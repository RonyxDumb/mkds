#pragma avoid_byte all

#include "code_021382a8.h"

// Swaps size bytes between a and b.
static inline void SwapElements(u8 *first, u8 *second, u32 size) {
    u8 *p;
    u8 *q;
    u8 temp;
    u32 i;

    i = size;
    p = first;
    q = second;
    for (; i != 0; i--) {
        temp = *q;
        *q++ = *p;
        *p++ = temp;
    }
}

void qsort(u8 *base, u32 n, u32 size, int (*cmp)(void *, void *)) {
    u32 l;
    u8 *lo;
    u8 *hi;
    u32 j;
    u8 *c;
    u8 *b;
    u8 *a;

    if (n < 2) {
        return;
    }
    l = (n >> 1) + 1;
    lo = base + size * (l - 1);
    hi = base + size * (n - 1);
    for (;;) {
        if (l > 1) {
            l--;
            lo -= size;
        } else {
            SwapElements(hi, lo, size);
            n--;
            if (n == 1) {
                return;
            }
            hi -= size;
        }
        j = l;
        b = base + size * (j - 1);
        while (j * 2 <= n) {
            j = j * 2;
            c = b;
            b = base + size * (j - 1);
            if (j < n) {
                a = b + size;
                if (cmp(b, a) < 0) {
                    b = a;
                    j++;
                }
            }
            if (cmp(c, b) >= 0) {
                break;
            }
            SwapElements(b, c, size);
        }
    }
}
