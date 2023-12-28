#ifndef __H_COHTBL__
#define __H_COHTBL__

#include <stdlib.h>

typedef struct COHTbl__
{
    int positions;
    void *vacated;

    int (*h1)(const void *key);
    int (*h2)(const void *key);
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    int size;
    void **table;

} COHTbl;


int cohtbl_init(COHTbl *htbl, int positions, int (*h1)(const void *key),
                int (*h2)(const void *key), int(*match)(const void *key1, const void *key2),
                void (destroy)(void *data));

void cohtbl_destroy(COHTbl *htbl);

int cohtbl_insert(COHTbl *htbl, const void *data);

int cohtbl_remove(COHTbl *htbl, void **data);

int cohtbl_lookup(const COHTbl *htbl, void **data);

#define cohtbl_size(htbl) (htbl->size)

#endif