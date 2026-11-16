#pragma once

#include "types.h"
#include "00/Lib/GameSpy/dynamic_array.h"

typedef struct Darray Darray;

// A hash table: an array of Darray buckets, its length, the per-element callback and the bucket and compare functions.
typedef struct Hashtable {
    /* 00 */ Darray **mBuckets;
    /* 04 */ s32 mBucketCount;
    /* 08 */ void (*mElemCallback)(void *);
    /* 0c */ s32 (*mHashFn)(void *, s32);
    /* 10 */ ElementCompareFunc *mCompFn;
} Hashtable;

Hashtable *HashtableCreate(s32 elemSize, s32 nBuckets, s32 initialCount, s32 (*hashFn)(void *, s32),
                           ElementCompareFunc *compFn, void (*freeElement)(void *));

void *HashtableFindByFn(Hashtable *table, int fn, const void *userData);
void HashtableForEach(Hashtable *table, void (*fn)(void *, void *), void *userData);
void *HashtableFind(Hashtable *table, void *elem);
BOOL HashtableRemove(Hashtable *table, void *elem);
void HashtableSet(Hashtable *table, void *elem);
s32 HashtableGetCount(Hashtable *table);
void HashtableDelete(void *tableArg);
