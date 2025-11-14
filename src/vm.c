#include "vm.h"
#include "instr.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void vm_init(VM *vm, int *code, int code_size){
	vm->code = code;
	vm->code_size = code_size;
	vm->ip = 0;
	vm->running = 1;
	stack_init(&vm->stack);
	memset(vm->memory, 0, sizeof(vm->memory));
	
}

/*
void vm_run2(VM *vm){
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
			case OP_LOAD:{
				op_load(vm);
				break;
			}
			case OP_STORE:{
				op_store(vm);
				break;
			}
			case OP_EQ: {
				op_eq(vm);
				break;
			}
			
		}
		// print_stack(&vm->stack);
	}
}

*/


void vm_run(VM *vm) {
	int i = 0;
    while (vm->running) {
    	//printf("BEFORE %d\n",i);
    	//print_stack(&vm->stack);
    	
        int op = vm->code[(vm->ip)++];
        dispatch_table[op](vm);
        
        //printf("AFTER %d\n",i);
    	//print_stack(&vm->stack);
    	i++;
    }
}
