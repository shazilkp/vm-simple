#include "vm.h"

int main() {
    int program[] = {
        OP_PUSH, 10,
        OP_PUSH, 20,
        OP_ADD,
        OP_PRINT,
        OP_HALT
        
    };

    VM vm;
    vm_init(&vm, program);
    vm_run(&vm);
}
