#include "00/code_021a8e78.h"

unsigned int func_ov000_021a8ed4(void) {
    unsigned int v1 = ((unsigned int) func_ov000_021a8830());
    unsigned int v2 = ((v1) << 24);
    unsigned int v3 = 0xff000000u;
    unsigned int v4 = ((v2) & (v3));
    unsigned int v5 = ((v1) << 8);
    unsigned int v6 = 0xff0000u;
    unsigned int v7 = ((v5) & (v6));
    unsigned int v8 = ((v1) >> 24);
    unsigned int v10 = ((v8) & (0xffu));
    unsigned int v11 = ((v1) >> 8);
    unsigned int v12 = 0xff00u;
    unsigned int v13 = ((v11) & (v12));
    unsigned int v14 = ((v10) | (v13));
    unsigned int v15 = ((v7) | (v14));
    unsigned int v16 = ((v4) | (v15));
    unsigned int v17 = ((v16) + (0x0u));
    return v17;
}

void func_ov000_021a8e78(unsigned int *p0, unsigned int *p1) {
    unsigned int v2 = ((unsigned int) *(unsigned int *) ((p1) + (0)));
    unsigned int v3 = ((unsigned int) *(unsigned int *) ((p0) + (0)));
    unsigned int v4 = ((v3) << 24);
    unsigned int v5 = 0xff000000u;
    unsigned int v6 = ((v4) & (v5));
    unsigned int v7 = ((v3) << 8);
    unsigned int v8 = 0xff0000u;
    unsigned int v9 = ((v7) & (v8));
    unsigned int v10 = ((v3) >> 24);
    unsigned int v12 = ((v10) & (0xffu));
    unsigned int v13 = ((v3) >> 8);
    unsigned int v14 = 0xff00u;
    unsigned int v15 = ((v13) & (v14));
    unsigned int v16 = ((v12) | (v15));
    unsigned int v17 = ((v9) | (v16));
    unsigned int v18 = ((v6) | (v17));
    unsigned int v19 = ((v18) + (0x0u));
    unsigned int v20 = ((v2) << 24);
    unsigned int v21 = 0xff000000u;
    unsigned int v22 = ((v20) & (v21));
    unsigned int v23 = ((v2) << 8);
    unsigned int v24 = ((v23) & (v8));
    unsigned int v25 = ((v2) >> 24);
    unsigned int v26 = ((v25) & (0xffu));
    unsigned int v27 = ((v2) >> 8);
    unsigned int v28 = ((v27) & (v14));
    unsigned int v29 = ((v26) | (v28));
    unsigned int v30 = ((v24) | (v29));
    unsigned int v31 = ((v22) | (v30));
    unsigned int v32 = ((v31) + (0x0u));
    unsigned int v33 = ((unsigned int) func_ov000_021a8878((u32) (v19), (u32) (v32)));
}
