#include "00/Lib/GameSpy/hash_table.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"

#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "quick_sort.h"

Hashtable *HashtableCreate(s32 elemSize, s32 nBuckets, s32 initialCount, s32 (*hashFn)(void *, s32),
                           ElementCompareFunc *compFn, void (*freeElement)(void *)) {
    Hashtable *table;
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
        table->mBuckets[bucketIndex] = DarrayCreate(elemSize, initialCount, freeElement);
    }
    table->mBucketCount = nBuckets;
    table->mElemCallback = freeElement;
    table->mCompFn = compFn;
    table->mHashFn = hashFn;
    return table;
}

void HashtableDelete(void *tableArg) {
    Hashtable *table = tableArg;
    s32 bucketIndex;
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x51);
    }
    if (table != NULL) {
        for (bucketIndex = 0; bucketIndex < table->mBucketCount; bucketIndex++) {
            DarrayDelete(table->mBuckets[bucketIndex]);
        }
        DWCi_GsFree(table->mBuckets);
        DWCi_GsFree(table);
    }
}

s32 HashtableGetCount(Hashtable *table) {
    s32 total = 0;
    s32 bucketIndex;
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x61);
    }
    if (table == NULL) {
        return 0;
    }
    for (bucketIndex = 0; bucketIndex < table->mBucketCount; bucketIndex++) {
        total += DarrayGetCount(table->mBuckets[bucketIndex]);
    }
    return total;
}

void HashtableSet(Hashtable *table, void *elem) {
    s32 bucketNo;
    s32 elemIndex;
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x71);
    }
    if (table != NULL) {
        bucketNo = table->mHashFn(elem, table->mBucketCount);
        elemIndex = DarrayFindIndex(table->mBuckets[bucketNo], elem, table->mCompFn, 0, 0);
        if (elemIndex == -1) {
            DarrayAppend(table->mBuckets[bucketNo], elem);
            return;
        }
        DarrayReplace(table->mBuckets[bucketNo], elem, elemIndex);
    }
}

BOOL HashtableRemove(Hashtable *table, void *elem) {
    s32 bucketNo;
    s32 elemIndex;
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x82);
    }
    if (table == NULL) {
        return FALSE;
    }
    bucketNo = table->mHashFn(elem, table->mBucketCount);
    elemIndex = DarrayFindIndex(table->mBuckets[bucketNo], elem, table->mCompFn, 0, 0);
    if (elemIndex != -1) {
        DarrayRemove(table->mBuckets[bucketNo], elemIndex);
        return TRUE;
    }
    return FALSE;
}

void *HashtableFind(Hashtable *table, void *elem) {
    s32 bucketNo;
    s32 elemIndex;
    if (table == NULL) {
        AssertionFailed("table", "hashtable.c", NULL, 0x94);
    }
    if (table == NULL) {
        return NULL;
    }
    bucketNo = table->mHashFn(elem, table->mBucketCount);
    elemIndex = DarrayFindIndex(table->mBuckets[bucketNo], elem, table->mCompFn, 0, 0);
    if (elemIndex != -1) {
        return DarrayGetElement(table->mBuckets[bucketNo], elemIndex);
    }
    return NULL;
}

void HashtableForEach(Hashtable *table, void (*fn)(void *, void *), void *userData) {
    s32 bucketIndex;
    if (fn == NULL) {
        AssertionFailed("fn", "hashtable.c", NULL, 0xb6);
    }
    for (bucketIndex = 0; bucketIndex < table->mBucketCount; bucketIndex++) {
        DarrayForEachReverse(table->mBuckets[bucketIndex], fn, userData);
    }
}

void *HashtableFindByFn(Hashtable *table, int fn, const void *userData) {
    void *foundElement;
    int bucketIndex;
    if (fn == 0) {
        AssertionFailed("fn", "hashtable.c", NULL, 0xd3);
    }
    bucketIndex = 0;
    if (0 < table->mBucketCount) {
        do {
            foundElement = DarrayFindByFnReverse(table->mBuckets[bucketIndex], (ElementCompareFunc *) fn, userData);
            if (foundElement != NULL) {
                return foundElement;
            }
            bucketIndex = bucketIndex + 1;
        } while (bucketIndex < table->mBucketCount);
    }
    return NULL;
}
