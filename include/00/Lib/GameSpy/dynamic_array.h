#pragma once

#include "types.h"

typedef struct DArrayImplementation DArrayImplementation;

typedef s32 ArrayCompareFn(const void *first, const void *second);

// A growable array: count, capacity, element size, growth step, per-element callback and the element data.
typedef struct DArrayImplementation {
    /* 00 */ s32 mCount;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mElemsize;
    /* 0c */ s32 mGrowCount;
    /* 10 */ void (*mElemCallback)(void *);
    /* 14 */ u8 *mList;
} DArrayImplementation;

void *mybsearch(const void *key, u8 *base, s32 count, s32 elemSize, ArrayCompareFn *comparator,
                         s32 *found);
void *mylsearch(const void *key, u8 *base, s32 count, s32 elemSize, ArrayCompareFn *comparator);
void ArrayClear(DArrayImplementation *darray);
void *ArrayMapBackwards2(DArrayImplementation *array, ArrayCompareFn *fn, const void *userData);
void ArrayMapBackwards(DArrayImplementation *array, void (*fn)(void *, void *), void *userData);
s32 ArraySearch(DArrayImplementation *darray, const void *key, ArrayCompareFn *comparator, s32 startIndex, s32 sortedFlag);
void ArraySort(DArrayImplementation *darray, unsigned int compareFunc);
void ArrayReplaceAt(DArrayImplementation *array, const void *elem, s32 index);
void ArrayDeleteAt(DArrayImplementation *array, s32 index);
void ArrayRemoveAt(DArrayImplementation *array, int index);
void ArrayInsertSorted(DArrayImplementation *array, void *elem, ArrayCompareFn *comparator);
void ArrayInsertAt(void *darrayArg, void *element, s32 index);
void ArrayAppend(void *darrayArg, void *element);
void *ArrayNth(void *darrayArg, s32 index);
s32 ArrayLength(void *arrayArg);
void ArrayFree(void *arrayArg);
void *ArrayNew(s32 elemSize, s32 initialCount, void (*freeElement)(void *));
void SetElement(DArrayImplementation *darray, const void *elem, s32 index);
void ArrayGrow(DArrayImplementation *dynArray);
void FreeElement(void *arrayArg, s32 index);
