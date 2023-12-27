#include "cdlist.h"


void dlist_init(DList * list, void (*destroy)(void * data)){
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return ;
}

void dlist_destroy(DList *list){
    
}

int dlist_ins_next(DList *list, DListElmt *element, const void *data);

int dlist_rem_next(DList *list, DListElmt *element, void **data);

int list_size(const DList *list);

DListElmt *list_head(const DList *list);

DListElmt *list_tail(const DList *list);

int list_is_head(const DList * list, const DListElmt *element);

void *list_data(const DListElmt *element);

DListElmt *list_next(const DListElmt *element);