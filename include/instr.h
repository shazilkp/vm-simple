#ifndef INSTR_H
#define INSTR_H

#include "vm.h"

typedef void (*OpHandler)(VM *);
extern OpHandler dispatch_table[];

void op_push(VM * vm);
void op_load(VM * vm);
void op_store(VM * vm);

void op_add(VM * vm);
void op_sub(VM * vm);
void op_mult(VM * vm);
void op_div(VM * vm);

void op_eq(VM * vm);
void op_neq(VM * vm);
void op_lt(VM * vm);
void op_gt(VM * vm);
void op_le(VM * vm);
void op_ge(VM * vm);

void op_jmp(VM * vm);
void op_jmp_ifz(VM * vm);
void op_jmp_ifnz(VM * vm);

void op_print(VM * vm);
void op_halt(VM * vm);

#endif
