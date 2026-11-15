#pragma once

#include "types.h"

typedef struct Darray Darray;

typedef s32 UnkCompare(const void *a, const void *b);

// 0x18 bytes. Growable array: count, capacity, element size, growth step, per-element callback, element data.
typedef struct Darray {
    /* 00 */ s32 mCount;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mElemSize;
    /* 0c */ s32 mGrowCount;
    /* 10 */ void (*mElemCallback)(void *);
    /* 14 */ u8 *mList;
} Darray;

void *DarraySearchSorted(const void *key, u8 *base, s32 count, s32 elemSize, UnkCompare *comparator, s32 *found);
void *DarraySearchLinear(const void *key, u8 *base, s32 count, s32 elemSize, UnkCompare *comparator);
void DarrayRemoveAll(Darray *darray);
void *DarrayFindByFnReverse(Darray *array, UnkCompare *fn, const void *userData);
void DarrayForEachReverse(Darray *array, UnkCompare *fn, const void *userData);
s32 DarrayFindIndex(Darray *darray, const void *key, UnkCompare *comparator, s32 startIndex, s32 sortedFlag);
void DarraySort(Darray *darray, unsigned int compareFunc);
void DarrayReplace(Darray *array, const void *elem, s32 index);
void DarrayRemove(Darray *array, s32 index);
void DarrayRemoveWithoutCallback(Darray *array, int index);
void DarrayInsertSorted(Darray *array, void *elem, UnkCompare *comparator);
void DarrayInsert(void *darrayArg, void *element, s32 index);
void DarrayAppend(void *darrayArg, void *element);
void *DarrayGetElement(void *darrayArg, s32 index);
s32 DarrayGetCount(void *arrayArg);
void DarrayDelete(void *arrayArg);
void *DarrayCreate(s32 elemSize, s32 initialCount, void (*freeElement)(void *));
void DarraySetElement(Darray *darray, const void *elem, s32 index);
void DarrayGrow(Darray *dynArray);
void DarrayCallElemCallback(void *arrayArg, s32 index);
