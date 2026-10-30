#include "Main/Unknown/code_02060c68.h"

s32 func_02060c68(Unk0217aa00_45c *p0, u32 p1) {
    unsigned int v2 = ((unsigned int) *(unsigned char *) (((u32) p0) + (532)));
    unsigned int v3 = ((u32) (&data_0217aa08));
    unsigned int v4 = 0x874u;
    unsigned int v7 = ((unsigned int) *(unsigned int *) ((v3) + (0)));
    unsigned int v9 = ((unsigned int) *(unsigned int *) ((v7) + (32)));
    unsigned int v10 = (((u32) p0) + (0x218u));
    unsigned int v11 = ((v9) + (v4));
    unsigned int v13 = func_02060d1c((u8 *) v11, (void *) p0, (u8 *) v10,
                                     (unsigned int) 0x0u, (unsigned int) v2, (unsigned int) p1);
    return v13;
}
