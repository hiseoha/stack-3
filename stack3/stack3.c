#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 10
typedef int ele;
typedef struct {
	ele* data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType *s) {
	s->top = -1;
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, ele item) {

	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (ele*)realloc(s->data, s->capacity * sizeof(ele));
		fprintf(stderr, "stack full\n");
	}
		return;
		s->data[++(s->top)] = item;
}

ele pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "stack empty\n");
	}
	else return s->data[(s->top)--];
}

int main(void) {

	srand(time(NULL));

	int i;
	StackType *s;
	s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);

	for (i = 1; i < 31; i++) {
		int rand_num = rand() % 100 + 1;

		if (rand_num % 2 == 0) {
			push(s, rand_num);
			printf("[%d] push %d\n", i, rand_num);
		}
		else {
			pop(s);
			printf("[%d] pop %d\n", i, rand_num);
		}
	}
	free(s);
	return 0;
}