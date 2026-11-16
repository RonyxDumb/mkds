#pragma once

#include "types.h"
#include "00/Lib/GameSpy/dynamic_array.h"

typedef struct Darray Darray;

// A hash table: an array of Darray buckets, the bucket count, the per-element callback, the hash function and the
// compare function.
typedef struct Hashtable {
    /* 00 */ Darray **mBuckets;
    /* 04 */ s32 mBucketCount;
    /* 08 */ void (*mElemCallback)(void *);
    /* 0c */ s32 (*mHashFn)(void *, s32);
    /* 10 */ ArrayCompareFn *mCompfn;
} Hashtable;

Hashtable *HashtableCreate(s32 elemSize, s32 nBuckets, s32 initialCount, s32 (*hashFn)(void *, s32),
                           ArrayCompareFn *compFn, void (*freeElement)(void *));

void *TableMapSafe2(Hashtable *table, int fn, const void *userData);
void TableMapSafe(Hashtable *table, void (*fn)(void *, void *), void *userData);
void *TableLookup(Hashtable *table, void *elem);
BOOL TableRemove(Hashtable *table, void *elem);
void TableEnter(Hashtable *table, void *elem);
s32 TableCount(Hashtable *table);
void TableFree(void *tableArg);
