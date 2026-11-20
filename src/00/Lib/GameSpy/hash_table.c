#include "00/Lib/GameSpy/hash_table.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"

#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "quick_sort.h"

HashImplementation *HashtableCreate(s32 elemSize, s32 nBuckets, s32 initialCount, s32 (*hashFn)(void *, s32),
                           ArrayCompareFn *compFn, void (*freeElement)(void *)) {
    HashImplementation *table;
    s32 bucketIndex;
    if (hashFn == NULL) {
        AssertionFailed("hashFn", "hashtable.c", NULL, 0x38);
    }
    if (compFn == NULL) {
        AssertionFailed("compFn", "hashtable.c", NULL, 0x39);
    }
    if (elemSize == 0) {
        AssertionFailed("elemSize", "hashtable.c", NULL, 0x3a);
    }
    if (nBuckets == 0) {
        AssertionFailed("nBuckets", "hashtable.c", NULL, 0x3b);
    }
    table = DWCi_GsMalloc(0x14);
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x3e);
    }
    table->mBuckets = DWCi_GsMalloc(nBuckets * 4);
    if (table->mBuckets == NULL) {
        AssertionFailed("table->buckets", "hashtable.c", NULL, 0x41);
    }
    for (bucketIndex = 0; bucketIndex < nBuckets; bucketIndex++) {
        table->mBuckets[bucketIndex] = ArrayNew(elemSize, initialCount, freeElement);
    }
    table->mBucketCount = nBuckets;
    table->mElemCallback = freeElement;
    table->mCompfn = compFn;
    table->mHashFn = hashFn;
    return table;
}

void TableFree(void *tableArg) {
    HashImplementation *table = tableArg;
    s32 bucketIndex;
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x51);
    }
    if (table != NULL) {
        for (bucketIndex = 0; bucketIndex < table->mBucketCount; bucketIndex++) {
            ArrayFree(table->mBuckets[bucketIndex]);
        }
        DWCi_GsFree(table->mBuckets);
        DWCi_GsFree(table);
    }
}

s32 TableCount(HashImplementation *table) {
    s32 total = 0;
    s32 bucketIndex;
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x61);
    }
    if (table == NULL) {
        return 0;
    }
    for (bucketIndex = 0; bucketIndex < table->mBucketCount; bucketIndex++) {
        total += ArrayLength(table->mBuckets[bucketIndex]);
    }
    return total;
}

void TableEnter(HashImplementation *table, void *elem) {
    s32 bucketNo;
    s32 elemIndex;
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x71);
    }
    if (table != NULL) {
        bucketNo = table->mHashFn(elem, table->mBucketCount);
        elemIndex = ArraySearch(table->mBuckets[bucketNo], elem, table->mCompfn, 0, 0);
        if (elemIndex == -1) {
            ArrayAppend(table->mBuckets[bucketNo], elem);
            return;
        }
        ArrayReplaceAt(table->mBuckets[bucketNo], elem, elemIndex);
    }
}

BOOL TableRemove(HashImplementation *table, void *elem) {
    s32 bucketNo;
    s32 elemIndex;
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x82);
    }
    if (table == NULL) {
        return FALSE;
    }
    bucketNo = table->mHashFn(elem, table->mBucketCount);
    elemIndex = ArraySearch(table->mBuckets[bucketNo], elem, table->mCompfn, 0, 0);
    if (elemIndex != -1) {
        ArrayDeleteAt(table->mBuckets[bucketNo], elemIndex);
        return TRUE;
    }
    return FALSE;
}

void *TableLookup(HashImplementation *table, void *elem) {
    s32 bucketNo;
    s32 elemIndex;
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x94);
    }
    if (table == NULL) {
        return NULL;
    }
    bucketNo = table->mHashFn(elem, table->mBucketCount);
    elemIndex = ArraySearch(table->mBuckets[bucketNo], elem, table->mCompfn, 0, 0);
    if (elemIndex != -1) {
        return ArrayNth(table->mBuckets[bucketNo], elemIndex);
    }
    return NULL;
}

void TableMapSafe(HashImplementation *table, void (*fn)(void *, void *), void *userData) {
    s32 bucketIndex;
    if (fn == NULL) {
        AssertionFailed("fn", "hashtable.c", NULL, 0xb6);
    }
    for (bucketIndex = 0; bucketIndex < table->mBucketCount; bucketIndex++) {
        ArrayMapBackwards(table->mBuckets[bucketIndex], fn, userData);
    }
}

void *TableMapSafe2(HashImplementation *table, int fn, const void *userData) {
    void *foundElement;
    int bucketIndex;
    if (fn == 0) {
        AssertionFailed("fn", "hashtable.c", NULL, 0xd3);
    }
    bucketIndex = 0;
    if (0 < table->mBucketCount) {
        do {
            foundElement = ArrayMapBackwards2(table->mBuckets[bucketIndex], (ArrayCompareFn *) fn, userData);
            if (foundElement != NULL) {
                return foundElement;
            }
            bucketIndex = bucketIndex + 1;
        } while (bucketIndex < table->mBucketCount);
    }
    return NULL;
}
