#include "instr.h"
#include <stdio.h>
#include <stdlib.h>


void op_add(Stack * s){
	int t1 = pop(s);
	int t2 = pop(s);
	push(s,t1+t2);
}


void op_sub(Stack * s){
	int t1 = pop(s);
	int t2 = pop(s);
	push(s,t1-t2);
}

void op_mult(Stack * s){
	int t1 = pop(s);
	int t2 = pop(s);
	push(s,t1*t2);
}

void op_div(Stack * s){
	int t1 = pop(s);
	int t2 = pop(s);
	push(s,t1/t2);
}

void op_print(Stack * s){
	printf("%d\n", peek(s));
}
