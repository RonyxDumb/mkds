#include "code_0214a54c.h"

// non-matching: the original is 32 identical four-word stores, with no pointer update between them
void func_0214a54c(void *a) {
    volatile u32 *p;
    s32 i;

    p = (volatile u32 *) a;
    for (i = 0; i < 32; i++) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
    }
}
