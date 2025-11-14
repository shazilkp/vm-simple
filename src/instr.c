#include "instr.h"
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>


typedef void (*OpHandler)(VM *);

OpHandler dispatch_table[NUM_OPCODES] = {
   	op_push,
	op_load,
	op_store,
	op_add,
	op_sub,
	op_mult,
	op_div,
	op_eq,
	op_neq,
	op_lt,
	op_gt,
	op_le,
	op_ge,
	op_jmp,
	op_jmp_ifz,
	op_jmp_ifnz,
	op_print,
	op_halt
};

void op_push(VM * vm){
	//printf("push called\n");
	int val = vm->code[(vm->ip)++];
	push(&vm->stack,val);
}

void op_halt(VM * vm){
	vm->running = 0;
}

void op_add(VM * vm){
	int b = pop(&vm->stack);
	int a = pop(&vm->stack);
	push(&vm->stack,a+b);
}


void op_sub(VM * vm){
	int b = pop(&vm->stack);
	int a = pop(&vm->stack);
	push(&vm->stack,a-b);
}

void op_mult(VM * vm){
	int b = pop(&vm->stack);
	int a = pop(&vm->stack);
	push(&vm->stack,a*b);
}

void op_div(VM * vm){
	int b = pop(&vm->stack);
	int a = pop(&vm->stack);
	push(&vm->stack,a/b);
}

void op_print(VM * vm){
	//printf("print called\n");
	printf("%d\n", peek(&vm->stack));
}

void op_load(VM * vm){
	int addr = vm->code[(vm->ip)++];
	if(addr >= 0 && addr < MEM_SIZE){	
		push(&vm->stack,vm->memory[addr]);
	}
	else{
		fprintf(stderr,"Out of bound memory access at %d\n",addr);
		exit(1);
	}
}

void op_store(VM * vm){
	int addr = vm->code[(vm->ip)++];
	int val = pop(&vm->stack);
	if(addr >= 0 && addr < MEM_SIZE){	
		vm->memory[addr] = val;
	}
	else{
		fprintf(stderr,"Out of bound memory access at %d\n",addr);
		exit(1);
	}
	
}


void op_eq(VM * vm){
	int b = pop(&vm->stack);
	int a = pop(&vm->stack);
	
	push(&vm->stack,(a == b) ? 1 : 0);
}

void op_neq(VM * vm){
	int b = pop(&vm->stack);
	int a = pop(&vm->stack);
	
	push(&vm->stack,(a != b) ? 1 : 0);
}

void op_lt(VM * vm){
	int b = pop(&vm->stack);
	int a = pop(&vm->stack);
	
	push(&vm->stack,(a < b) ? 1 : 0);
}

void op_gt(VM * vm){
	int b = pop(&vm->stack);
	int a = pop(&vm->stack);
	
	push(&vm->stack,(a > b) ? 1 : 0);
}

void op_le(VM * vm){
	int b = pop(&vm->stack);
	int a = pop(&vm->stack);
	
	push(&vm->stack,(a <= b) ? 1 : 0);
}

void op_ge(VM * vm){
	int b = pop(&vm->stack);
	int a = pop(&vm->stack);
	
	push(&vm->stack,(a >= b) ? 1 : 0);
}

void op_jmp(VM * vm){
	int target = vm->code[(vm->ip)++];
	if (target < 0 || target >= vm->code_size) {
		fprintf(stderr, "Invalid jump address %d\n", target);
	 	exit(1);
	}
	
	vm->ip = target;
}

void op_jmp_ifz(VM *vm) {
	int target = vm->code[(vm->ip)++];
	if (target < 0 || target >= vm->code_size) {
		fprintf(stderr, "Invalid jump address %d\n", target);
	 	exit(1);
	}
	int value = pop(&vm->stack);

	if (value == 0){
		vm->ip = target;
	}
}

void op_jmp_ifnz(VM *vm) {
	int target = vm->code[(vm->ip)++];
	if (target < 0 || target >= vm->code_size) {
		fprintf(stderr, "Invalid jump address %d\n", target);
	 	exit(1);
	}
	int value = pop(&vm->stack);

	if (value != 0){
		vm->ip = target;
	}
}
