#include "vm.h"
#include "instr.h"
#include  <stdio.h>
#include <stdlib.h>


void vm_init(VM *vm, int *code){
	vm->code = code;
	vm->ip = 0;
	stack_init(&vm->stack);
}


void vm_run(VM *vm){
	int vm_running = 1;
	while(vm_running){
		int op = vm->code[(vm->ip)++];
		switch(op){
			case OP_PUSH:{
				int val = vm->code[(vm->ip)++];
				push(&vm->stack,val);
				break;
			}
			case OP_ADD:{
				op_add(&vm->stack);
				break;
			}
			case OP_SUB:{
				op_sub(&vm->stack);
				break;
			}
			case OP_MULT:{
				op_mult(&vm->stack);
				break;
			}
			case OP_DIV:{
				op_div(&vm->stack);
				break;
			}
			case OP_PRINT:{
				op_print(&vm->stack);
				break;
			}
			case OP_HALT:{
				vm_running = 0;
				break;
			}
			
			
		}
		// print_stack(&vm->stack);
	}
}
