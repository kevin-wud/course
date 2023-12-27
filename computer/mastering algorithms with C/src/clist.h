#ifndef __H_CLIST__
#define __H_CLIST__

#include <stdlib.h>
/*
    单向链表
*/
typedef struct CListElmt__
{
    void *data;
    struct CListElmt__ *next;
} CListElmt;

typedef struct CList__
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    CListElmt *head;
    CListElmt *tail;
} CList;

void clist_init(CList * list, void (*destroy)(void * data));

void clist_destroy(CList *list);

int clist_ins_next(CList *list, CListElmt *element, const void *data);

int clist_rem_next(CList *list, CListElmt *element, void **data);

int clist_size(const CList *list);

CListElmt *clist_head(const CList *list);

CListElmt *clist_tail(const CList *list);

int clist_is_head(const CList * list, const CListElmt *element);

void *clist_data(const CListElmt *element);

CListElmt *clist_next(const CListElmt *element);

#endif