#include "00/Lib/GameSpy/code_0218d818.h"

#include "code_02133048.h"
#include "string.h"
#include "code_02134398.h"
#include "00/unk_021b2000.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "code_021382a8.h"

void DarrayCallElemCallback(void *arrayArg, s32 index) {
    Darray *darray = arrayArg;
    if (darray->mElemCallback != NULL) {
        darray->mElemCallback(DarrayGetElement(darray, index));
    }
}

void DarrayGrow(Darray *dynArray) {
    dynArray->mCapacity = dynArray->mCapacity + dynArray->mGrowCount;
    dynArray->mList = DWCi_GsRealloc(dynArray->mList, dynArray->mCapacity * dynArray->mElemSize);
    if (dynArray->mList == NULL) {
        AssertionFailed("array->list", "darray.c", NULL, 0x41);
    }
}

void DarraySetElement(Darray *darray, const void *elem, s32 index) {
    memcpy(DarrayGetElement(darray, index), elem, darray->mElemSize);
}

void *DarrayCreate(s32 elemSize, s32 initialCount, void (*freeElement)(void *)) {
    Darray *array = DWCi_GsMalloc(0x18);
    if (array == NULL) {
        AssertionFailed("array", "darray.c", NULL, 0x52);
    }
    if (elemSize == 0) {
        AssertionFailed("elemSize", "darray.c", NULL, 0x53);
    }
    if (initialCount == 0) {
        initialCount = 8;
    }
    array->mCount = 0;
    array->mCapacity = initialCount;
    array->mElemSize = elemSize;
    array->mGrowCount = initialCount;
    array->mElemCallback = freeElement;
    if (array->mCapacity != 0) {
        array->mList = DWCi_GsMalloc(array->mCapacity * array->mElemSize);
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

void *DarrayGetElement(void *param_1, s32 index) {
    Darray *array = param_1;
    if (index < 0 || index >= array->mCount) {
        AssertionFailed("(n >= 0) && (n < array->count)", "darray.c", NULL, 0x94);
    }
    if (index < 0 || index >= array->mCount) {
        return NULL;
    }
    return array->mList + array->mElemSize * index;
}

void DarrayAppend(void *param_1, void *param_2) {
    Darray *array = param_1;
    if (array == NULL) {
        AssertionFailed("array", "darray.c", NULL, 0xa0);
    }
    if (array != NULL) {
        DarrayInsert(array, param_2, array->mCount);
    }
}

void DarrayInsert(void *param_1, void *param_2, s32 index) {
    Darray *array = param_1;
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
                array->mElemSize * (lastIndex - index));
    }
    DarraySetElement(array, param_2, index);
}

void DarrayInsertSorted(Darray *array, void *elem, UnkCompare *comparator) {
    u8 *v1;
    u32 v2;
    s32 v3[2];
    if (comparator == NULL) {
        AssertionFailed("comparator", "darray.c", NULL, 0xb7);
    }
    v1 = DarraySearchSorted(elem, array->mList, array->mCount, array->mElemSize, comparator, v3);
    v2 = _s32_div_f(v1 - array->mList, array->mElemSize);
    DarrayInsert(array, elem, v2);
}

void DarrayRemoveWithoutCallback(Darray *array, int index) {
    s32 v1;
    if (index < 0 || index >= array->mCount) {
        AssertionFailed("(n >= 0) && (n < array->count)", "darray.c", NULL, 0xc0);
    }
    v1 = array->mCount - 1;
    if (index < v1) {
        memmove(DarrayGetElement(array, index), DarrayGetElement(array, index + 1), array->mElemSize * (v1 - index));
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

void DarraySort(Darray *p0, u32 p1) {
    qsort(p0->mList, p0->mCount, p0->mElemSize, (int (*)(void *, void *)) p1);
}

s32 DarrayFindIndex(Darray *darray, const void *key, UnkCompare *comparator, s32 startIndex, s32 sortedFlag) {
    s32 v1 = 1;
    s32 count;
    u8 *found;
    if (darray == NULL || (count = darray->mCount) == 0) {
        return -1;
    }
    if (sortedFlag != 0) {
        found = DarraySearchSorted(key, DarrayGetElement(darray, startIndex), count - startIndex, darray->mElemSize,
                                   comparator, &v1);
    } else {
        found = DarraySearchLinear(key, DarrayGetElement(darray, startIndex), count - startIndex, darray->mElemSize,
                                   comparator);
    }
    if (found != NULL && v1 != 0) {
        return (found - darray->mList) / darray->mElemSize;
    }
    return -1;
}

void DarrayForEachReverse(Darray *array, UnkCompare *fn, const void *userData) {
    s32 index;
    if (fn == NULL) {
        AssertionFailed("fn", "darray.c", NULL, 0x104);
    }
    for (index = array->mCount - 1; index >= 0; index--) {
        fn(DarrayGetElement(array, index), userData);
    }
}

void *DarrayFindByFnReverse(Darray *array, UnkCompare *fn, const void *userData) {
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

void *DarraySearchLinear(const void *key, u8 *base, s32 count, s32 elemSize, UnkCompare *comparator) {
    s32 index;
    s32 v1;
    index = 0;
    if (count > 0) {
        v1 = 0;
        do {
            if (comparator(key, base + v1) == 0) {
                return base + elemSize * index;
            }
            v1 += elemSize;
            index++;
        } while (index < count);
    }
    return NULL;
}

void *DarraySearchSorted(const void *key, u8 *base, s32 count, s32 elemSize, UnkCompare *comparator, s32 *found) {
    s32 v1 = 0;
    s32 v2 = count - 1;
    s32 v3;
    s32 compareResult;
    *found = 0;
    if (v2 >= 0) {
        do {
            v3 = (v1 + v2) >> 1;
            compareResult = comparator(base + v3 * elemSize, key);
            if (compareResult == 0) {
                *found = 1;
            }
            if (compareResult < 0) {
                v1 = v3 + 1;
            } else {
                v2 = v3 - 1;
            }
        } while (v1 <= v2);
    }
    return base + v1 * elemSize;
}
