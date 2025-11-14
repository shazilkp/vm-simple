#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void stack_init(Stack * s){
	s->top = -1;
}

void push(Stack *s, int val) {
    if (s->top >= STACK_SIZE) {
        fprintf(stderr, "Stack Overflow\n");
        exit(1);
    }

    s->data[++s->top] = val;   // store then increment
    // printf("%d was pushed to stack\n", val);
}


int pop(Stack * s){
	if(s->top < 0){
		fprintf(stderr,"Stack Underflow\n");
		exit(1);
	}
	
	int val = s->data[s->top];
	(s->top)--;
	return val;
}

int peek(Stack * s){
	if(s->top < 0){
		fprintf(stderr,"Stack empty\n");
		return -1;
	}
	
	int val = s->data[s->top];
	//printf("peek called");
	return val;
}

void print_stack(Stack *stack) {
    printf("[STACK] (size=%d): ", stack->top+1);
    if (stack->top < 0) {
        printf("<empty>\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

