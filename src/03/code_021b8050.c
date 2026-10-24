#include "03/code_021b8050.h"

unsigned char func_ov003_021b8050(unsigned int p0, unsigned int p1) {
    unsigned int v2 = ((p0) + (0x0u));
    unsigned int v3 = ((p1) + (0x0u));
    unsigned int v4 = ((u32) (&data_ov003_021d7f6c));
    unsigned int v7 = ~(0x0u);
    unsigned int v8 = ((v2) + (0x0u));
    unsigned int v9 = func_ov003_021b8010((unsigned int) (v7), (unsigned int) (v8), (unsigned int) (v3),
                                          (unsigned int) (0x0u), (unsigned int) (v4));
    unsigned int v11 = ~(0x0u);
    unsigned int v12 = ((v9) ^ (v11));
    unsigned int v13 = ((v12) << 24);
    unsigned int v14 = ((v13) >> 24);
    return v14;
}
