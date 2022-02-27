#include<stdio.h>
#include<stdlib.h>

void makeList(int *l, int d, int *t, int s) {
	if(*t >= s) {
		printf("Overflow\n");
    }
	else {
		*t = *t + 1;
		l[*t] = d;
	}
}

void showList(int *l, int s) {
	printf("\nStack:\n");
	for(int i = s-1; i>=0; --i)
		printf("%d\n", l[i]);
}

int * duplicateList(int *l, int s) {
	int *c = (int *)malloc(s*sizeof(int));
	for(int i = 0; i<s; ++i) {
		c[i] = l[i];
    }
	return c;
}

int main() {
	int top = -1, size, data;
	int *list;
	printf("Enter size of stack: ");
	scanf ("%d", &size);
	list = (int *)malloc(size*sizeof(int));
	for(int i = 0; i<size; ++i) {
		printf("Enter data %d: ", i+1);
		scanf ("%d", &data);
		makeList(list, data, &top, size);
	}
	showList(list, size);
	int *copy = duplicateList(list, size);
	showList(copy, size);
	return 0;
}
