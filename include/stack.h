#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 256

typedef struct stack {
	int data[STACK_SIZE];
	int top;
} Stack;


void stack_init(Stack * s);
void push(Stack * s, int val);
int peek(Stack * s);
int pop(Stack * s);
void print_stack(Stack *s);
#endif
