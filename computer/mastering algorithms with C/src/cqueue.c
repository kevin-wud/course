#include "cqueue.h"

int cqueue_enqueue(CQueue *queue, const void *data){
    return clist_ins_next(queue, clist_tail(queue), data);
}

int cqueue_dequeue(CQueue *queue, void **data){
    return clist_rem_next(queue, NULL, data);
}