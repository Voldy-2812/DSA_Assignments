#include "stack.c"

void sortedInsert(struct Stack *s, int x) {
    if (s->top == -1 || x > peek(s)) {
        push(s, x);
        return;
    }
    int temp = pop(s);
    sortedInsert(s, x);
    push(s, temp);
}

void sortStack(struct Stack *s) {
    if (s->top != -1) {
        int x = pop(s);
        sortStack(s);
        sortedInsert(s, x);
    }
}

void removeDuplicate(struct Stack *s) {
    struct Stack *s1 = createStack(s->capacity);
    push(s1, pop(s));
    int temp;
    while (!isEmpty(s)) {
        if (peek(s) != peek(s1)) {
            push(s1, pop(s));
        }
        else {
            temp = pop(s);
        }
    }
    struct Stack *s2 = createStack(s1->top + 1);
    while (!isEmpty(s1)) {
        push(s2, pop(s1));
    }

    printf("\nStack with Duplicates removed:");
    disp(s2);
}

struct Stack *duplicateStack(struct Stack *s) {
    int temp = s->top;
    struct Stack *s1 = createStack(s->capacity);
    struct Stack *s2 = createStack(s->capacity);
    for (int i = 0; i < s->capacity; i++) {
        push(s1, pop(s));
    }

    for (int i = 0; i < s->capacity; i++) {
        push(s2, pop(s1));
    }
    s->top = temp;
    return s2;
}

void main() {
    int sz;
    printf("Enter size of stack: ");
    scanf("%d", &sz);

    struct Stack *stack1 = createStack(sz);
    printf("Enter elements for stack: ");
    for (int i = 0; i < sz; i++) {
        push_user(stack1);
    }
    struct Stack *stack2 = duplicateStack(stack1);
    sortStack(stack1);
    removeDuplicate(stack1);
    printf("\n\nOriginal Stack:");
    disp(stack2);
}
