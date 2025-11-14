#include "vm.h"

int main() {
    int program[] = {
	OP_PUSH, 5,
	OP_STORE, 0,
	OP_LOAD, 0,
	OP_PRINT,
	OP_LOAD, 0,
	OP_PUSH, 1,
	OP_SUB,
	OP_STORE, 0,
	OP_LOAD, 0,
	OP_JMP_IFNZ, 4,
	OP_HALT
    };
    
    int p_size = sizeof(program) / sizeof(program[0]);
    // printf("size of program = %d, element = %d , %d\n",sizeof(program),sizeof(program[0]),p_size);

    VM vm;
    vm_init(&vm, program,p_size);
    vm_run(&vm);
}
