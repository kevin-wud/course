#ifndef __H_CLIST__
#define __H_CLIST__

#include <stdlib.h>
/*
    单向链表
*/
typedef struct ListElmt__
{
    void *data;
    struct ListElmt__ *next;
} ListElmt;

typedef struct List__
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    ListElmt *head;
    ListElmt *tail;
} List;

void list_init(List * list, void (*destroy)(void * data));

void list_destroy(List *list);

int list_ins_next(List *list, ListElmt *element, const void *data);

int list_rem_next(List *list, ListElmt *element, void **data);

int list_size(const List *list);

ListElmt *list_head(const List *list);

ListElmt *list_tail(const List *list);

int list_is_head(const List * list, const ListElmt *element);

void *list_data(const ListElmt *element);

ListElmt *list_next(const ListElmt *element);

#endif