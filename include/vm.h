#ifndef VM_H
#define VM_H

#define MEM_SIZE 1024

#include "stack.h"

typedef enum {
	OP_PUSH,
	OP_LOAD,
	OP_STORE,

	OP_ADD,
	OP_SUB,
	OP_MULT,
	OP_DIV,

	OP_EQ,
	OP_NEQ,
	OP_LT,
	OP_GT,
	OP_LE,
	OP_GE,
	
	OP_JMP,
	OP_JMP_IFZ,
	OP_JMP_IFNZ,

	OP_PRINT,
	OP_HALT,
	
	
	NUM_OPCODES
} OpCode;


typedef struct {
	int * code;
	int code_size;
	int ip;
	
	Stack stack;
	int memory[MEM_SIZE];
	int running;
}VM;


void vm_init(VM *vm, int *code,int code_size);
void vm_run(VM *vm);

#endif
