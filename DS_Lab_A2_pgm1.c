#include <stdio.h>

void push(int Stack[], int element, int *top) {
    Stack[*top] = element;
    *top += 1;
}

void pop(int Stack[], int *top) {
    if (*top == 0){
        printf("\nStack is Empty.");
    }
    else {
        *top -= 1;
        printf("\nPopped Element : %d", Stack[*top]);
    }
}

void displayStack(int Stack[], int top) {
    for (int i = 0; i < top; i++) {
        printf("%d  ", Stack[i]);
    }
}

void sort(int Stack[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (Stack[j] > Stack[j + 1]) {
                int temp = Stack[j];
                Stack[j] = Stack[j + 1];
                Stack[j + 1] = temp;
            }
        }
    }
}

void merge(int Stack1[], int Stack2[], int Stack3[], int MergedStack[], int top1, int top2, int top3) {
    sort(Stack1, top1);
    sort(Stack2, top2);
    sort(Stack3, top3);
    int i = 0, j = 0, k = 0, len=0;
    while (i < top1 && j < top2 && k < top3) {
        if (Stack1[i] < Stack2[j] && Stack1[i] < Stack3[k]) {
            MergedStack[len++] = Stack1[i++];
        }
        else if (Stack2[j] < Stack3[k]) {
            MergedStack[len++] = Stack2[j++];
        }
        else {
            MergedStack[len++] = Stack3[k++];
        }
    }
    while (i < top1 && j < top2) {
        if (Stack1[i] < Stack2[j]) {
            MergedStack[len++] = Stack1[i++];
        }
        else {
            MergedStack[len++] = Stack2[j++];
        }
    }
    while (k < top3 && j < top2) {
        if (Stack2[j] < Stack3[k]) {
            MergedStack[len++] = Stack2[j++];
        }
        else {
            MergedStack[len++] = Stack3[k++];
        }
    }
    while (i < top1 && k < top3) {
        if (Stack1[i] < Stack3[k]) {
            MergedStack[len++] = Stack1[i++];
        }
        else {
            MergedStack[len++] = Stack3[k++];
        }
    }
    for (; i < top1; i++) {
        MergedStack[len++] = Stack1[i];
    }
    for (; j < top2; j++) {
        MergedStack[len++] = Stack2[j];
    }
    for (; k < top3; k++) {
        MergedStack[len++] = Stack3[k];
    }
}

int main() {
    int Stack[4][100], top[4] = {0}, ch, ele, n;
    fflush(stdin);
    while (1) {
        printf("\n1. First Stack");
        printf("\n2. Second Stack");
        printf("\n3. Third Stack");
        printf("\n4. Merged Stack");
        printf("\n5. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &n);
        if (n > 4 || n < 1) {
            break;
        }
        if (n == 4) {
            merge(Stack[0], Stack[1], Stack[2], Stack[3], top[0], top[1], top[2]);
            top[3] = top[0] + top[1] + top[2];
        }
        do {
            printf("\nChoose anyone :");
            printf("\n1. Push");
            printf("\n2. Pop");
            printf("\n3. Display");
            printf("\n4. Go Back");
            printf("\nEnter your choice : ");
            scanf("%d", &ch);
            switch (ch) {
            case 1:
                printf("Enter a element : ");
                scanf("%d", &ele);
                push(Stack[n - 1], ele, &top[n - 1]);
                break;
            case 2:
                pop(Stack[n - 1], &top[n - 1]);
                break;
            case 3:
                printf("\nStack : ");
                displayStack(Stack[n - 1], top[n - 1]);
                break;
            }
        } while (ch != 4);
    }
    return 0;
}
