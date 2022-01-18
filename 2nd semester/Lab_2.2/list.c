#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    char value;
    struct list *next;
} list;

list *initList(char value) {
    list *l_p;
    l_p = malloc(sizeof(list));
    l_p -> value = value;
    l_p -> next = NULL;
    return l_p;
}

list *getLast(list *l_p) {
    if (l_p == NULL) {
        return NULL;
    }
    while (l_p -> next) {
        l_p = l_p -> next;
    }
    return l_p;
}

void addList(list *l_p, char value) {
    list *last = getLast(l_p);
    list *temp = malloc(sizeof(list));
    temp -> value = value;
    temp -> next = NULL;
    last -> next = temp;
}

void printList(list *l_p) {
    struct list *p;
    do {
        printf("%c ", p -> value);
        p = p -> next;
    } while (p != NULL);
}

void deleteList(list *l_p) {
    list *prev = NULL;
    while (l_p->next) {
        prev = l_p;
        l_p = l_p -> next;
        free(prev);
    }
    free(l_p);
}

list *sortList(list *l_p) {
    list *new_root = NULL;
    while ( l_p != NULL ) {
        list *node = l_p;
        l_p = l_p->next;

        if (new_root == NULL || node -> value < new_root -> value) {
            node->next = new_root;
            new_root = node;
        }
        else {
            list *p = new_root;
            while (p->next != NULL && !(node->value < p->next->value)) {
                p = p->next;
            }
            node->next = p->next;
            p->next = node;
        }
    }
    return new_root;
}

int main() {
    int n;
    char a;
    struct list *l_p;

    printf("Enter N:");
    scanf("%d", &n);
    if (n > 10) {
        printf("N can`t be more than 10");
        return 0;
    }

    printf("Enter letters:\n");
    scanf("%c", &a);
    initList(a);

    for (int i = 2; i <= n; i++) {
        scanf("%c\n", &a);
        addList(l_p, a);
    }
    sortList(l_p);
    printList(l_p);
    deleteList(l_p);
}


