#ifndef __H_CCLIST__
#define __H_CCLIST__

#include <stdlib.h>

/*
    循环链表
 */
typedef struct CCListElmt__
{
    void *data;
    struct CCListElmt__ *next;
} CCListElmt;

typedef struct CCList__
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    CCListElmt *head;
} CCList;

void cclist_init(CCList * list, void (*destroy)(void * data));

void cclist_destroy(CCList *list);

int cclist_ins_next(CCList *list, CCListElmt *element, const void *data);

int cclist_rem_next(CCList *list, CCListElmt *element, void **data);

int cclist_size(const CCList *list);

CCListElmt *cclist_head(const CCList *list);

CCListElmt *cclist_tail(const CCList *list);

int cclist_is_head(const CCList * list, const CCListElmt *element);

void *cclist_data(const CCListElmt *element);

CCListElmt *cclist_next(const CCListElmt *element);

#endif