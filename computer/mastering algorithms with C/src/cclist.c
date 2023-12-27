#include <string.h>

#include "cclist.h"

void cclist_init(CCList * list, void (*destroy)(void * data)){
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;

    return ;
}

void cclist_destroy(CCList *list){
    void *data;

    while(cclist_size(list) > 0){
        if(cclist_rem_next(list,list->head, (void**)&data) == 0 && list->destroy != NULL){
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(CCList));

    return ;
}

int cclist_ins_next(CCList *list, CCListElmt *element, const void *data){

    return 0;
}

int cclist_rem_next(CCList *list, CCListElmt *element, void **data){

    return 0;
}

int cclist_size(const CCList *list){
    return list->size;
}

CCListElmt *cclist_head(const CCList *list){

}

CCListElmt *cclist_tail(const CCList *list){

}

int cclist_is_head(const CCList * list, const CCListElmt *element){

}

void *cclist_data(const CCListElmt *element){

}

CCListElmt *cclist_next(const CCListElmt *element){

}