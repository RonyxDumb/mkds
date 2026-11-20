#pragma once

#include "types.h"
#include "00/Lib/GameSpy/dynamic_array.h"

typedef struct DArrayImplementation DArrayImplementation;

// A hash table: an array of DArrayImplementation buckets, the bucket count, the per-element callback, the hash
// function and the compare function.
typedef struct HashImplementation {
    /* 00 */ DArrayImplementation **mBuckets;
    /* 04 */ s32 mBucketCount;
    /* 08 */ void (*mElemCallback)(void *);
    /* 0c */ s32 (*mHashFn)(void *, s32);
    /* 10 */ ArrayCompareFn *mCompfn;
} HashImplementation;

HashImplementation *HashtableCreate(s32 elemSize, s32 nBuckets, s32 initialCount, s32 (*hashFn)(void *, s32),
                           ArrayCompareFn *compFn, void (*freeElement)(void *));

void *TableMapSafe2(HashImplementation *table, int fn, const void *userData);
void TableMapSafe(HashImplementation *table, void (*fn)(void *, void *), void *userData);
void *TableLookup(HashImplementation *table, void *elem);
BOOL TableRemove(HashImplementation *table, void *elem);
void TableEnter(HashImplementation *table, void *elem);
s32 TableCount(HashImplementation *table);
void TableFree(void *tableArg);
