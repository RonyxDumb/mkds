#include "00/code_0218dd8c.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"

#include "00/dwc_memfunc.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "code_021382a8.h"

Hashtable *HashtableCreate(s32 elemSize, s32 nBuckets, s32 e, s32 (*hashFn)(void *, s32), s32 (*compFn)(void *, void *),
                           void (*h)(void *)) {
    Hashtable *table;
    s32 b;
    if (hashFn == NULL) {
        AssertionFailed(gHashFnAssertText, gHashtableFileName, NULL, 0x38);
    }
    if (compFn == NULL) {
        AssertionFailed(gCompFnAssertText, gHashtableFileName, NULL, 0x39);
    }
    if (elemSize == 0) {
        AssertionFailed(gHashtableElemSizeAssertText, gHashtableFileName, NULL, 0x3a);
    }
    if (nBuckets == 0) {
        AssertionFailed(gNBucketsAssertText, gHashtableFileName, NULL, 0x3b);
    }
    table = DWCi_GsMalloc(0x14);
    if (table == NULL) {
        AssertionFailed(gTableAssertText, gHashtableFileName, NULL, 0x3e);
    }
    table->mBuckets = DWCi_GsMalloc(nBuckets * 4);
    if (table->mBuckets == NULL) {
        AssertionFailed(gTableBucketsAssertText, gHashtableFileName, NULL, 0x41);
    }
    for (b = 0; b < nBuckets; b++) {
        table->mBuckets[b] = DarrayCreate(elemSize, e, h);
    }
    table->mBucketCount = nBuckets;
    table->mElemCallback = h;
    table->mCompFn = compFn;
    table->mHashFn = hashFn;
    return table;
}

void HashtableDelete(void *c) {
    Hashtable *table = c;
    s32 b;
    if (table == NULL) {
        AssertionFailed(gTableAssertText, gHashtableFileName, NULL, 0x51);
    }
    if (table != NULL) {
        for (b = 0; b < table->mBucketCount; b++) {
            DarrayDelete(table->mBuckets[b]);
        }
        DWCi_GsFree(table->mBuckets);
        DWCi_GsFree(table);
    }
}

s32 HashtableGetCount(Hashtable *table) {
    s32 a = 0;
    s32 b;
    if (table == NULL) {
        AssertionFailed(gTableAssertText, gHashtableFileName, NULL, 0x61);
    }
    if (table == NULL) {
        return 0;
    }
    for (b = 0; b < table->mBucketCount; b++) {
        a += DarrayGetCount(table->mBuckets[b]);
    }
    return a;
}

void HashtableSet(Hashtable *table, void *d) {
    s32 a;
    s32 b;
    if (table == NULL) {
        AssertionFailed(gTableAssertText, gHashtableFileName, NULL, 0x71);
    }
    if (table != NULL) {
        a = table->mHashFn(d, table->mBucketCount);
        b = DarrayFindIndex(table->mBuckets[a], d, (UnkCompare *) table->mCompFn, 0, 0);
        if (b == -1) {
            DarrayAppend(table->mBuckets[a], d);
            return;
        }
        DarrayReplace(table->mBuckets[a], d, b);
    }
}

BOOL HashtableRemove(Hashtable *table, void *d) {
    s32 a;
    s32 b;
    if (table == NULL) {
        AssertionFailed(gTableAssertText, gHashtableFileName, NULL, 0x82);
    }
    if (table == NULL) {
        return FALSE;
    }
    a = table->mHashFn(d, table->mBucketCount);
    b = DarrayFindIndex(table->mBuckets[a], d, (UnkCompare *) table->mCompFn, 0, 0);
    if (b != -1) {
        DarrayRemove(table->mBuckets[a], b);
        return TRUE;
    }
    return FALSE;
}

void *HashtableFind(Hashtable *table, void *d) {
    s32 a;
    s32 b;
    if (table == NULL) {
        AssertionFailed(gTableAssertText, gHashtableFileName, NULL, 0x94);
    }
    if (table == NULL) {
        return NULL;
    }
    a = table->mHashFn(d, table->mBucketCount);
    b = DarrayFindIndex(table->mBuckets[a], d, (UnkCompare *) table->mCompFn, 0, 0);
    if (b != -1) {
        return DarrayGetElement(table->mBuckets[a], b);
    }
    return NULL;
}

void HashtableForEach(Hashtable *table, void (*fn)(void *, void *), void *d) {
    s32 a;
    if (fn == NULL) {
        AssertionFailed(gHashtableFnAssertText, gHashtableFileName, NULL, 0xb6);
    }
    for (a = 0; a < table->mBucketCount; a++) {
        DarrayForEachReverse(table->mBuckets[a], (UnkCompare *) fn, d);
    }
}

void *HashtableFindByFn(Hashtable *table, int fn, const void *c) {
    void *v1;
    int v3;
    if (fn == 0) {
        AssertionFailed(gHashtableFnAssertText, gHashtableFileName, NULL, 0xd3);
    }
    v3 = 0;
    if (0 < table->mBucketCount) {
        do {
            v1 = DarrayFindByFnReverse(table->mBuckets[v3], (UnkCompare *) fn, c);
            if (v1 != NULL) {
                return v1;
            }
            v3 = v3 + 1;
        } while (v3 < table->mBucketCount);
    }
    return NULL;
}
