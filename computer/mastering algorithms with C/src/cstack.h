#ifndef __H_CSTACK__
#define __H_CSTACK__

#include <stdlib.h>

#include "clist.h"

typedef CList CStack;

#define cstack_init clist_init

#define cstack_destroy clist_destroy

int cstack_push(CStack *stack, const void *data);

int cstack_pop(CStack *stack, void **data);

void *cstack_peek(const CStack *stack);

#define cstack_size clist_size

#endif