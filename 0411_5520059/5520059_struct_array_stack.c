#define _CRT_SECURE_NO_WARNINGS // scanf ���� ó�� �ذ��ϱ����� �����°�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 5

typedef int element;
typedef struct Stacktype {
    element* data;
    int capacity; // ���� ũ��
    int top;
} StackType;


// ���� ���� �Լ�
void init(StackType* sptr, int ofs) {
    sptr->data = (element*)malloc(sizeof(element) * ofs);
    sptr->top = -1;
    sptr->capacity = ofs;
}


// ����� ǥ��
int isEmpty(StackType* sptr) {
    return (sptr->top == -1);
}


// ���� �� ���� ǥ��
int is_full(StackType* sptr) {
    if (sptr->top == sptr->capacity - 1) {
        sptr->capacity = sptr->capacity * 2;
        sptr->data = (element*)realloc(sptr->data, sptr->capacity * sizeof(element));

    }
    return (sptr->top == sptr->capacity - 1);
}


// push
void push(StackType* sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack Overflow\n");
        return;
    }
    else {
        sptr->top = sptr->top + 1;
        sptr->data[sptr->top] = item;
    }
}


// pop
element pop(StackType* sptr) {
    if (isEmpty(sptr)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    else {
        return (sptr->data[(sptr->top)--]);
    }
}


// ���� ��� ���
void print_stack(StackType* sptr) {
    printf("Stack elements: ");
    for (int i = 0; i <= sptr->top; i++) {
        printf("%d ", sptr->data[i]);
    }
    printf("\n");
}



int main(void) {
    StackType s;
    int rand_num;
    int numOfStack;
    srand(time(NULL));

    printf("How many elements does the stack have? ");
    scanf("%d", &numOfStack);

    init(&s, numOfStack);

    for (int i = 0; i < 30; i++) {
        rand_num = rand() % 100 + 1;

        if (rand_num % 2 == 0) {
            push(&s, rand_num);
            printf("Current rand_num: %d | Even\n", rand_num);
            printf("Push: %d\n", rand_num);
        }
        else {
            printf("Current rand_num: %d | Odd\n", rand_num);
            printf("Pop: %d\n", pop(&s));
        }

        print_stack(&s);
        printf("\n");
    }

    return 0;
}