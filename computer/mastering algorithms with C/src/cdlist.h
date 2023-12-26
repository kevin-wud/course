#ifndef __H_CDLIST__
#define __H_CDLIST__

#include <stdlib.h>

/*
    双向链表
 */
typedef struct DListElmt__
{
    void *data;
    struct DListElmt__ *next;
    struct DListElmt__ *prev;
    
} DListElmt;

typedef struct DList__
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    DListElmt *head;
    DListElmt *tail;
} DList;



void dlist_init(DList * list, void (*destroy)(void * data));

void dlist_destroy(DList *list);

int dlist_ins_next(DList *list, DListElmt *element, const void *data);

int dlist_rem_next(DList *list, DListElmt *element, void **data);

int list_size(const DList *list);

DListElmt *list_head(const DList *list);

DListElmt *list_tail(const DList *list);

int list_is_head(const DList * list, const DListElmt *element);

void *list_data(const DListElmt *element);

DListElmt *list_next(const DListElmt *element);

#endif