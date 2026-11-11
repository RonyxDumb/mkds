#pragma avoid_byte all

#include "code_021382a8.h"

// Swaps size bytes between first and second.
static inline void SwapElements(u8 *first, u8 *second, u32 size) {
    u8 *firstPtr;
    u8 *secondPtr;
    u8 tempByte;
    u32 remaining;

    remaining = size;
    firstPtr = first;
    secondPtr = second;
    for (; remaining != 0; remaining--) {
        tempByte = *secondPtr;
        *secondPtr++ = *firstPtr;
        *firstPtr++ = tempByte;
    }
}

void qsort(u8 *base, u32 count, u32 size, int (*cmp)(void *, void *)) {
    u32 heapIndex;
    u8 *lo;
    u8 *hi;
    u32 childIndex;
    u8 *parentPtr;
    u8 *childPtr;
    u8 *siblingPtr;

    if (count < 2) {
        return;
    }
    heapIndex = (count >> 1) + 1;
    lo = base + size * (heapIndex - 1);
    hi = base + size * (count - 1);
    for (;;) {
        if (heapIndex > 1) {
            heapIndex--;
            lo -= size;
        } else {
            SwapElements(hi, lo, size);
            count--;
            if (count == 1) {
                return;
            }
            hi -= size;
        }
        childIndex = heapIndex;
        childPtr = base + size * (childIndex - 1);
        while (childIndex * 2 <= count) {
            childIndex = childIndex * 2;
            parentPtr = childPtr;
            childPtr = base + size * (childIndex - 1);
            if (childIndex < count) {
                siblingPtr = childPtr + size;
                if (cmp(childPtr, siblingPtr) < 0) {
                    childPtr = siblingPtr;
                    childIndex++;
                }
            }
            if (cmp(parentPtr, childPtr) >= 0) {
                break;
            }
            SwapElements(childPtr, parentPtr, size);
        }
    }
}
