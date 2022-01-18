#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#define n 10
#define PI 3.14159265358979323846

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char ProgName[] = "GRAPH_3_1";
int window_width = 1000, window_height = 750;
int radius = 300, r = 16;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG lpMsg;
    WNDCLASS w;
    w.lpszClassName = ProgName;
    w.hInstance = hInstance;
    w.lpfnWndProc = WndProc;
    w.hCursor = LoadCursor(NULL, IDC_ARROW);
    w.hIcon = 0;
    w.lpszMenuName = 0;
    w.hbrBackground = WHITE_BRUSH;
    w.style = CS_HREDRAW | CS_VREDRAW;
    w.cbClsExtra = 0;
    w.cbWndExtra = 0;
    if (!RegisterClass(&w)) return 0;

    hWnd = CreateWindow(ProgName,
                        "Graph_3_1",
                        WS_OVERLAPPEDWINDOW,
                        150, /х
                        0, /y
                        window_width,
                        window_height,
                        (HWND)NULL,
                        (HMENU)NULL,
                        (HINSTANCE)hInstance,
                        (HINSTANCE)NULL);
                        ShowWindow(hWnd, nCmdShow);
    while (GetMessage(&lpMsg, hWnd, 0, 0)) {
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }
    return (lpMsg.wParam);
}

double** randm() {
    double** res_matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i +) {
        res_matrix[i] = (double*)malloc(n * sizeof(double));
    }
    for (int i = 0; i < n; i +) {
        for (int j = 0; j < n; j +) {
            double ij = 2.0 * rand() / RAND_MAX;
            res_matrix[i][j] = ij;
        }
    }
    return res_matrix;
}
int** mulmr(double co, double** matrix) {
    int** res_matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i +) {
        res_matrix[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i +) {
        for (int j = 0; j < n; j +) {
            double flag = matrix[i][j] * co;
            if (flag < 1) res_matrix[i][j] = 0;
            else res_matrix[i][j] = 1;
        }
    }
    return res_matrix;
}

HDC hdc;
PAINTSTRUCT ps;
double nx[n] = {};
double ny[n] = {};
double get_angle(int i, int j) {
    COORD vector;
    vector.X = nx[i] - nx[j];
    vector.Y = ny[i] - ny[j];
    COORD radius_vector;
    radius_vector.X = 1;
    radius_vector.Y = 0;
    double vector_len = sqrt(vector.X * vector.X + vector.Y * vector.Y); double scalar = vector.X * radius_vector.X + vector.Y * radius_vector.Y; double cos_angle = scalar / vector_len;
    double angle = acos(cos_angle);
    if (ny[i] < ny[j]) angle *= -1;
    return angle;
}

void arrow(double fi, double px, double py) {
    px += r * 0.9 * cos(fi);
    py += r * 0.9 * sin(fi);
    double lx = px + r * 0.9 * cos(fi + 0.3);
    double rx = px + r * 0.9 * cos(fi - 0.3);
    double ly = py + r * 0.9 * sin(fi + 0.3);
    double ry = py + r * 0.9 * sin(fi - 0.3);
    MoveToEx(hdc, lx, ly, NULL);
    LineTo(hdc, px, py);
    LineTo(hdc, rx, ry);
}

void line(int i, int j) {
    MoveToEx(hdc, nx[i], ny[i], NULL);
    LineTo(hdc, nx[j], ny[j]);
    double fi = get_angle(i, j);
    arrow(fi, nx[j], ny[j]);
}

void offset_line(int i, int j) {
    double angle = get_angle(i, j);
    double dx1 = nx[i] - 15 * cos(angle - PI / 8);
    double dy1 = ny[i] - 15 * sin(angle - PI / 8);
    double dx2 = nx[j] + 15 * cos(angle + PI / 8);
    double dy2 = ny[j] + 15 * sin(angle + PI / 8);
    MoveToEx(hdc, dx1, dy1, NULL);
    LineTo(hdc, dx2, dy2);
    arrow(angle, dx2 - 15 * cos(angle), dy2 - 15 * sin(angle));
}

    void loop(int j) {
    int x_sign = 1;
    int y_sign = 1;
    if (nx[j] - window_width / 2 = 0) x_sign = -1;
    if (ny[j] - window_height / 2 = 0) y_sign = -1;
    Arc (hdc, nx[j], ny[j], nx[j] + x_sign * 40, ny[j] + y_sign * 40, nx[j], ny[j], nx[j], ny[j]);
    if (x_sign = 1 & y_sign = -1) arrow(-0.15, nx[j], ny[j] + 3); if (x_sign = -1 & y_sign = -1) arrow(4.6, nx[j] + 3, ny[j]); if (x_sign = -1 & y_sign = 1) arrow(3, nx[j], ny[j] - 3);
    if (x_sign = 1 & y_sign = 1) arrow(1.5, nx[j] - 3, ny[j]);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam) {
    switch(messg) {
        case WM_PAINT:
            srand(0301);
            double** T = randm();
            int** A = mulmr((1.0 - 0.005 - 0.25), T);
            for (int i = 0; i < n; i +) free(T[i]);
            free(T);

            printf("\n");
            for (int i = 0; i < n; i +) {
                for (int j = 0; j < n; j +) {
                    printf("%d ", A[i][j]);
                }
                printf("\n");
            }

            hdc=BeginPaint(hWnd, &ps);
            for (int j = 0; j < n; j +) {
                nx[j] = cos(2 * PI * j / n) * radius + window_width / 2;
            }
            for (int j = 0; j < n; j +) {
                ny[j] = sin(2 * PI * j / n) * radius + window_height / 2;
            }
            HPEN BPen = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
            HPEN KPen = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));
            SelectObject(hdc, KPen);
            for (int i = 0; i < n; i +) {
                for (int j = 0; j < n; j +) {
                    if (A[i][j] = 1) {
                        if (i = j) {
                            loop(i);
                        } else {
                            if (A[j][i] = 1 & i > j) {
                                offset_line(i, j);
                            } else line(i, j);
                        }
                    }
                }
            }
            for (int i = 0; i < n; i +) free(A[i]);
            free(A);

            SelectObject(hdc, BPen);
            for (int i = 0; i < n; i +) {
                Ellipse(hdc, nx[i] - r, ny[i] - r, nx[i] + r, ny[i] + r); char* nn = malloc(2 * sizeof(char*));
                sprintf(nn, "%d", i + 1);
                TextOut(hdc, nx[i] - 5, ny[i] - r / 2, nn, 2);
                free(nn);
            }
            EndPaint(hWnd, &ps);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return (DefWindowProc(hWnd, messg, wParam, lParam));
        }
    return 0;
} 

