#include <stdlib.h>
#include <string.h>

#include "clist.h"

void clist_init(CList * list, void (*destroy)(void * data)){
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return ;
}

void clist_destroy(CList *list){
    void *data;

    while(clist_size(list) > 0){
        if(clist_rem_next(list,NULL,(void **)&data) ==0 && list->destroy != NULL){
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(CList));
    return ;
}

int clist_ins_next(CList *list, CListElmt *element, const void *data){
    CListElmt *new_element;

    if((new_element = (CListElmt *)malloc(sizeof(CListElmt))) == NULL){
        return -1;
    }

    new_element->data = (void *)data;
    if(element == NULL){
        if(clist_size(list) == 0){
            list->tail = new_element;
        }
        new_element->next = list->head;
        list->head = new_element;
    }else{
        if (element->next == NULL){
            list->tail = new_element;
        }
        new_element->next = element->next;
        element->next = new_element;
    }
    list->size++;

    return 0;
}

int clist_rem_next(CList *list, CListElmt *element, void **data){
    CListElmt *old_element;

    if (clist_size(list) == 0){
        return -1;
    }
    
    if(element == NULL){
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;

        if (clist_size(list) == 1){
            list->tail = NULL;
        }   
    }else{
        if(element->next == NULL){
            return -1;
        }

        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;

        if(element->next == NULL){
            list->tail = element;
        }
    }
    free(old_element); //destroy??

    list->size--;
    return 0;
}

int clist_size(const CList *list){
    return list->size;
}

CListElmt *clist_head(const CList *list){
    return list->head;
}

CListElmt *clist_tail(const CList *list){
    return list->tail;
}

int clist_is_head(const CList *list, const CListElmt *element){
    return list->head == element ? 1 : 0;
}

void *clist_data(const CListElmt *element){
    return element->data;
}

CListElmt *clist_next(const CListElmt *element){
    return element->next;
}