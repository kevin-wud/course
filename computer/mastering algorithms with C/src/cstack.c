#include "cstack.h"

int cstack_push(CStack *stack, const void *data){
    return clist_ins_next(stack, NULL, data);
}

int cstack_pop(CStack *stack, void **data){
    return clist_rem_next(stack, NULL, data);
}

void *cstack_peek(const CStack *stack){
    return stack->head == NULL ? NULL : stack->head->data;
}