#include "00/Lib/GameSpy/dynamic_array.h"

#include "signed_int_divide.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "quick_sort.h"

void DarrayCallElemCallback(void *arrayArg, s32 index) {
    Darray *darray = arrayArg;
    if (darray->mElemCallback != NULL) {
        darray->mElemCallback(DarrayGetElement(darray, index));
    }
}

void DarrayGrow(Darray *dynArray) {
    dynArray->mCapacity = dynArray->mCapacity + dynArray->mGrowCount;
    dynArray->mList = DWCi_GsRealloc(dynArray->mList, dynArray->mCapacity * dynArray->mElemsize);
    if (dynArray->mList == NULL) {
        AssertionFailed("array->list", "darray.c", NULL, 0x41);
    }
}

void DarraySetElement(Darray *darray, const void *elem, s32 index) {
    memcpy(DarrayGetElement(darray, index), elem, darray->mElemsize);
}

void *DarrayCreate(s32 elemSize, s32 initialCapacity, void (*freeElement)(void *)) {
    Darray *array = DWCi_GsMalloc(sizeof(Darray));
    if (array == NULL) {
        AssertionFailed("array", "darray.c", NULL, 0x52);
    }
    if (elemSize == 0) {
        AssertionFailed("elemSize", "darray.c", NULL, 0x53);
    }
    if (initialCapacity == 0) {
        initialCapacity = 8;
    }
    array->mCount = 0;
    array->mCapacity = initialCapacity;
    array->mElemsize = elemSize;
    array->mGrowCount = initialCapacity;
    array->mElemCallback = freeElement;
    if (array->mCapacity != 0) {
        array->mList = DWCi_GsMalloc(array->mCapacity * array->mElemsize);
        if (array->mList == NULL) {
            AssertionFailed("array->list", "darray.c", NULL, 0x5e);
        }
    } else {
        array->mList = NULL;
    }
    return array;
}

void DarrayDelete(void *arrayArg) {
    Darray *array = arrayArg;
    s32 index;
    if (array == NULL) {
        AssertionFailed("array", "darray.c", NULL, 0x69);
    }
    index = 0;
    if (0 < array->mCount) {
        do {
            DarrayCallElemCallback(array, index);
            index = index + 1;
        } while (index < array->mCount);
    }
    DWCi_GsFree(array->mList);
    DWCi_GsFree(array);
}

s32 DarrayGetCount(void *arrayArg) {
    Darray *darray = arrayArg;
    return darray->mCount;
}

void *DarrayGetElement(void *darrayArg, s32 index) {
    Darray *array = darrayArg;
    if (index < 0 || index >= array->mCount) {
        AssertionFailed("(n >= 0) && (n < array->count)", "darray.c", NULL, 0x94);
    }
    if (index < 0 || index >= array->mCount) {
        return NULL;
    }
    return array->mList + array->mElemsize * index;
}

void DarrayAppend(void *darrayArg, void *element) {
    Darray *array = darrayArg;
    if (array == NULL) {
        AssertionFailed("array", "darray.c", NULL, 0xa0);
    }
    if (array != NULL) {
        DarrayInsert(array, element, array->mCount);
    }
}

void DarrayInsert(void *darrayArg, void *element, s32 index) {
    Darray *array = darrayArg;
    s32 lastIndex;
    if (index < 0 || index > array->mCount) {
        AssertionFailed("(n >= 0) && (n <= array->count)", "darray.c", NULL, 0xa7);
    }
    if (array->mCount == array->mCapacity) {
        DarrayGrow(array);
    }
    array->mCount = array->mCount + 1;
    lastIndex = array->mCount - 1;
    if (index < lastIndex) {
        memmove(DarrayGetElement(array, index + 1), DarrayGetElement(array, index),
                array->mElemsize * (lastIndex - index));
    }
    DarraySetElement(array, element, index);
}

void DarrayInsertSorted(Darray *array, void *elem, ElementCompareFunc *comparator) {
    u8 *insertPosition;
    u32 insertIndex;
    s32 searchFound[2];
    if (comparator == NULL) {
        AssertionFailed("comparator", "darray.c", NULL, 0xb7);
    }
    insertPosition = DarraySearchSorted(elem, array->mList, array->mCount, array->mElemsize, comparator, searchFound);
    insertIndex = _s32_div_f(insertPosition - array->mList, array->mElemsize);
    DarrayInsert(array, elem, insertIndex);
}

void DarrayRemoveWithoutCallback(Darray *array, int index) {
    s32 lastIndex;
    if (index < 0 || index >= array->mCount) {
        AssertionFailed("(n >= 0) && (n < array->count)", "darray.c", NULL, 0xc0);
    }
    lastIndex = array->mCount - 1;
    if (index < lastIndex) {
        memmove(DarrayGetElement(array, index), DarrayGetElement(array, index + 1),
                array->mElemsize * (lastIndex - index));
    }
    array->mCount = array->mCount - 1;
}

void DarrayRemove(Darray *array, s32 index) {
    if ((index < 0) || (index >= array->mCount)) {
        AssertionFailed("(n >= 0) && (n < array->count)", "darray.c", NULL, 0xca);
    }
    DarrayCallElemCallback(array, index);
    DarrayRemoveWithoutCallback(array, index);
}

void DarrayReplace(Darray *array, const void *elem, s32 index) {
    if ((index < 0) || (index >= array->mCount)) {
        AssertionFailed("(n >= 0) && (n < array->count)", "darray.c", NULL, 0xd3);
    }
    DarrayCallElemCallback(array, index);
    DarraySetElement(array, elem, index);
}

void DarraySort(Darray *darray, u32 compareFunc) {
    qsort(darray->mList, darray->mCount, darray->mElemsize, (int (*)(void *, void *)) compareFunc);
}

s32 DarrayFindIndex(Darray *darray, const void *key, ElementCompareFunc *comparator, s32 startIndex, s32 sortedFlag) {
    s32 matchFlag = 1;
    s32 count;
    u8 *position;
    if (darray == NULL || (count = darray->mCount) == 0) {
        return -1;
    }
    if (sortedFlag != 0) {
        position = DarraySearchSorted(key, DarrayGetElement(darray, startIndex), count - startIndex, darray->mElemsize,
                                   comparator, &matchFlag);
    } else {
        position = DarraySearchLinear(key, DarrayGetElement(darray, startIndex), count - startIndex, darray->mElemsize,
                                   comparator);
    }
    if (position != NULL && matchFlag != 0) {
        return (position - darray->mList) / darray->mElemsize;
    }
    return -1;
}

void DarrayForEachReverse(Darray *array, void (*fn)(void *, void *), void *userData) {
    s32 index;
    if (fn == NULL) {
        AssertionFailed("fn", "darray.c", NULL, 0x104);
    }
    for (index = array->mCount - 1; index >= 0; index--) {
        fn(DarrayGetElement(array, index), userData);
    }
}

void *DarrayFindByFnReverse(Darray *array, ElementCompareFunc *fn, const void *userData) {
    s32 index;
    void *elem;
    if (fn == NULL) {
        AssertionFailed("fn", "darray.c", NULL, 0x121);
    }
    for (index = array->mCount - 1; index >= 0; index--) {
        elem = DarrayGetElement(array, index);
        if (fn(elem, userData) == 0) {
            return elem;
        }
    }
    return NULL;
}

void DarrayRemoveAll(Darray *darray) {
    s32 index;
    for (index = DarrayGetCount(darray) - 1; index >= 0; index--) {
        DarrayRemove(darray, index);
    }
}

void *DarraySearchLinear(const void *key, u8 *base, s32 count, s32 elemSize, ElementCompareFunc *comparator) {
    s32 index;
    s32 byteOffset;
    index = 0;
    if (count > 0) {
        byteOffset = 0;
        do {
            if (comparator(key, base + byteOffset) == 0) {
                return base + elemSize * index;
            }
            byteOffset += elemSize;
            index++;
        } while (index < count);
    }
    return NULL;
}

void *DarraySearchSorted(const void *key, u8 *base, s32 count, s32 elemSize, ElementCompareFunc *comparator,
                         s32 *found) {
    s32 lowIndex = 0;
    s32 highIndex = count - 1;
    s32 midIndex;
    s32 compareResult;
    *found = 0;
    if (highIndex >= 0) {
        do {
            midIndex = (lowIndex + highIndex) >> 1;
            compareResult = comparator(base + midIndex * elemSize, key);
            if (compareResult == 0) {
                *found = 1;
            }
            if (compareResult < 0) {
                lowIndex = midIndex + 1;
            } else {
                highIndex = midIndex - 1;
            }
        } while (lowIndex <= highIndex);
    }
    return base + lowIndex * elemSize;
}
