#include "Main/Unknown/code_02111b40.h"

#pragma thumb on

void func_02111b40(void) {
    unsigned int v1 = ((u32) (&data_0217d348));
    unsigned int v2 = ((unsigned int) *(unsigned int *) ((v1) + (0)));
    unsigned int v3 = ((unsigned int) *(unsigned int *) ((v2) + (88)));
    unsigned int v4 = ((0x0u) - (v3));
    unsigned int v5 = 0x1ffu;
    unsigned int v6 = ((v4) & (v5));
    unsigned int v7 = ((unsigned int) *(unsigned int *) ((v2) + (92)));
    unsigned int v8 = ((0x0u) - (v7));
    unsigned int v9 = ((v8) << 16);
    unsigned int v10 = 0x1ff0000u;
    unsigned int v11 = ((v9) & (v10));
    unsigned int v12 = ((v6) | (v11));
    unsigned int v13 = 0x4000010u;
    unsigned int v15;
    unsigned int v16;
    unsigned int v17;
    unsigned int v18;
    unsigned int v19;
    unsigned int v20;
    unsigned int v21;
    unsigned int v22;
    unsigned int v23;
    unsigned int v24;
    *(unsigned int *) ((v13) + (0)) = (unsigned int) (v12);
    v15 = ((unsigned int) *(unsigned int *) ((v1) + (0)));
    v16 = ((unsigned int) *(unsigned int *) ((v15) + (96)));
    v17 = ((0x0u) - (v16));
    v18 = ((v17) & (v5));
    v19 = ((unsigned int) *(unsigned int *) ((v15) + (100)));
    v20 = ((0x0u) - (v19));
    v21 = ((v20) << 16);
    v22 = ((v21) & (v10));
    v23 = ((v18) | (v22));
    v24 = 0x4000014u;
    *(unsigned int *) ((v24) + (0)) = (unsigned int) (v23);
    func_02111428((unsigned int) (v24), (unsigned int) (v5), (unsigned int) (v10));
}

#pragma thumb off
