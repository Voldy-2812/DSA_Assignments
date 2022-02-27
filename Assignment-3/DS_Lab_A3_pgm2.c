#include "stack.c"

void sortedInsert(struct Stack* s, int x) {
    if (s->top==-1 || x > peek(s)) {
        push(s, x);
        return;
    }
    int temp = pop(s);
    sortedInsert(s, x);
    push(s, temp);
}

void sortStack(struct Stack* s) {
    if (s->top != -1) {
        int x = pop(s); 
        sortStack(s); 
        sortedInsert(s, x);
    }
}

void main() {
    int sz1, sz2, sz3;
    printf("\nEnter size of stack 1: ");
    scanf("%d", &sz1);
    struct Stack* stack1= createStack(sz1);
    for(int i= 0; i<sz1; i++) {
        push_user(stack1);
    }

    printf("\nEnter size of stack 2: ");
    scanf("%d", &sz2);
    struct Stack* stack2= createStack(sz2);
    for(int i= 0; i<sz2; i++) {
        push_user(stack2);
    }

    printf("\nEnter size of stack 3: ");
    scanf("%d", &sz3);
    struct Stack* stack3= createStack(sz3);
    for(int i= 0; i<sz3; i++) {
        push_user(stack3);
    }

    int t_sz= sz1+sz2+sz3;
    struct Stack* t_stack= createStack(t_sz);
    for(int i= 0; i<t_sz; i++) {
        if(!isEmpty(stack1)) {
            push(t_stack, pop(stack1));
        }
        else if(!isEmpty(stack2)) {
            push(t_stack, pop(stack2));
        }
        else if(!isEmpty(stack3)) {
            push(t_stack, pop(stack3));
        }
    }

    sortStack(t_stack);
    printf("\nSorted Stack is: \n");
    disp(t_stack);
}
