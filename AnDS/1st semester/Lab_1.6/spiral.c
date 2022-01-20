#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int p = 0; p < 13; p++) {
        int i = 79 - p;
        int j = 0, moveD = 0;
        for (; i > p; i--) {
            COORD Pos = {i, 24 - p};
            SetConsoleCursorPosition(hout, Pos);
            printf("*");
            Sleep(5);
        }
        for(; j < 24; j++){
            COORD Pos = {i,24 - p - j};
            SetConsoleCursorPosition(hout, Pos);
            printf("*");
            Sleep(5);
        }
        for (; i < 80 - p; i++) {
            COORD Pos = {i, p};
            SetConsoleCursorPosition(hout, Pos);
            printf("*");
            Sleep(5);
        }
        i--;
        for(; moveD < 24; moveD++) {
            COORD Pos = {i, moveD};
            SetConsoleCursorPosition(hout, Pos);
            printf("*");
            Sleep(5);
        }
    }
}
