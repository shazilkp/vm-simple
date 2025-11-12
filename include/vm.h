#ifndef VM_H
#define VM_H

#include "stack.h"

typedef enum {
	OP_PUSH,
	OP_ADD,
	OP_SUB,
	OP_MULT,
	OP_DIV,
	OP_PRINT,
	OP_HALT
} OpCode;


typedef struct {
	int * code;
	int ip;
	Stack stack;
}VM;


void vm_init(VM *vm, int *code);
void vm_run(VM *vm);

#endif
