#ifndef __H_CSET__
#define __H_CSET__

#include <stdlib.h>

#include "clist.h"

typedef CList CSet;

void cset_init(CSet *set, int (*match)(const void *key1, const void *key2),
                void (*destroy)(void *data));

#define cset_destroy clist_destroy

int cset_insert(CSet *set, const void *data);

int cset_remove(CSet *set, void **data);

int cset_union(CSet *setu, const CSet *set1, const CSet *set2);

int cset_intersection(CSet *seti, const CSet *set1, const CSet *set2);

int cset_defference(CSet *setd, const CSet *set1, const CSet *set2);

int cset_is_member(const CSet *set, const void *data);

int cset_is_subset(const CSet *set1, const CSet *set2);

int cset_is_equal(const CSet *set1, const CSet *set2);

#define cset_size(set) (set->size)

#endif