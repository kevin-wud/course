#include <string.h>
#include "cset.h"


void cset_init(CSet *set, int (*match)(const void *key1, const void *key2),
                void (*destroy)(void *data)){

    clist_init(set,destroy);
    set->match = match;

    return ;
}

int cset_insert(CSet *set, const void *data){
    if(cset_is_member(set,data)){
        return 1;
    }
    return clist_ins_next(set,clist_tail(set), data);
}

int cset_remove(CSet *set, void **data){
    CListElmt *mumber, *prev;

    prev = NULL;

    for(mumber = clist_head(set); mumber != NULL; mumber = clist_next(mumber)){
        if(set->match(*data,clist_data(mumber))){
            break;
        }
        prev = mumber;
    }

    if(mumber == NULL){
        return -1;
    }
    return clist_rem_next(set, prev, data);
}

int cset_union(CSet *setu, const CSet *set1, const CSet *set2){
    CListElmt *member;
    void *data;

    cset_init(setu, set1->match, NULL);

    for (member = clist_head(set1); member != NULL; member = clist_next(member)){
        data = clist_data(member);

        if(clist_ins_next(setu, clist_tail(setu), data) != 0){
            cset_destroy(setu);
            return -1;
        }    
    }

    for (member = clist_head(set2); member != NULL; member = clist_next(member)){
        if(cset_is_member(set1, clist_data(member))){
            continue;
        }else{
            data = clist_data(member);

            if(clist_ins_next(setu, clist_tail(setu), data) != 0){
                cset_destroy(setu);
                return -1;
            }   
        }
    }

    return 0;
}

int cset_intersection(CSet *seti, const CSet *set1, const CSet *set2){
    CListElmt *member;
    void *data;

    cset_init(seti, set1->match, NULL);

    for (member = clist_head(set1); member != NULL; member = clist_next(member)){
         if (cset_is_member(set2, clist_data(member))){
            data = clist_data(member);

            if(clist_ins_next(seti, clist_tail(seti), data) != 0){
                cset_destroy(seti);
                return -1;
            }
         }
    }

    return 0;
}

int cset_defference(CSet *setd, const CSet *set1, const CSet *set2){
    CListElmt *member;
    void *data;

    cset_init(setd, set1->match, NULL);

    for (member = clist_head(set1); member != NULL; member = clist_next(member)){
         if (!cset_is_member(set2, clist_data(member))){
            data = clist_data(member);

            if(clist_ins_next(setd, clist_tail(setd), data) != 0){
                cset_destroy(setd);
                return -1;
            }
         }
    }
   
    return 0;
}

int cset_is_member(const CSet *set, const void *data){
    CListElmt *member;

    for(member = clist_head(set); member != NULL; member = clist_next(member)){
        if(set->match(data,clist_data(member))){
            return 1;
        }
    }
    return 0;
}

int cset_is_subset(const CSet *set1, const CSet *set2){
    CListElmt * member;

    if(cset_size(set1) > cset_size(set2)){
        return 0;
    }

    for(member = clist_head(set1); member != NULL; member = clist_next(member)){
        if(!cset_is_member(set2, clist_data(member))){
            return 0;
        }
    }
    return 1;
}

int cset_is_equal(const CSet *set1, const CSet *set2){
    if(cset_size(set1) != cset_size(set2)){
        return 0;
    }
    return cset_is_subset(set1, set2);
}