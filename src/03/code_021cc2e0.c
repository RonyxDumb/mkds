#include "03/code_021cc2e0.h"
#include "03/code_021cc2bc.h"

void func_ov003_021cc34c(void) {
    unsigned int v2 = ((u32) (&data_ov003_021d773c));
    unsigned int v3 = ((u32) (&func_0214b95c));
    unsigned int v4 = func_ov003_021bf620((unsigned int) (v2), (unsigned int) (v3));
    unsigned int v5 = ((u32) (&data_ov003_021d7754));
    unsigned int v6 = ((u32) (&func_0214c160));
    unsigned int v7 = func_ov003_021bf620((unsigned int) (v5), (unsigned int) (v6));
    unsigned int v8 = ((u32) (&data_ov003_021d776c));
    unsigned int v9 = ((u32) (&func_0214bc9c));
    unsigned int v10 = func_ov003_021bf620((unsigned int) (v8), (unsigned int) (v9));
    unsigned int v11 = 0x4001008u;
    unsigned int v12 = ((unsigned int) *(unsigned short *) ((v11) + (0)));
    unsigned int v14 = ((v12) & ~(0x3u));
    unsigned int v15 = ((v14) | (0x3u));
    unsigned int v17;
    unsigned int v18;
    unsigned int v19;
    unsigned int v20;
    unsigned int v22;
    unsigned int v23;
    unsigned int v24;
    unsigned int v25;
    unsigned int v27;
    unsigned int v28;
    unsigned int v29;
    unsigned int v30;
    unsigned int v32;
    unsigned int v33;
    unsigned int v34;
    unsigned int v35;
    *(unsigned short *) ((v11) + (0)) = (unsigned short) (v15);
    v17 = 0x400100au;
    v18 = ((unsigned int) *(unsigned short *) ((v17) + (0)));
    v19 = ((v18) & ~(0x3u));
    v20 = ((v19) | (0x3u));
    *(unsigned short *) ((v17) + (0)) = (unsigned short) (v20);
    v22 = 0x4000008u;
    v23 = ((unsigned int) *(unsigned short *) ((v22) + (0)));
    v24 = ((v23) & ~(0x3u));
    v25 = ((v24) | (0x3u));
    *(unsigned short *) ((v22) + (0)) = (unsigned short) (v25);
    v27 = 0x400000au;
    v28 = ((unsigned int) *(unsigned short *) ((v27) + (0)));
    v29 = ((v28) & ~(0x3u));
    v30 = ((v29) | (0x3u));
    *(unsigned short *) ((v27) + (0)) = (unsigned short) (v30);
    v32 = 0x400000cu;
    v33 = ((unsigned int) *(unsigned short *) ((v32) + (0)));
    v34 = ((v33) & ~(0x3u));
    v35 = ((v34) | (0x3u));
    *(unsigned short *) ((v32) + (0)) = (unsigned short) (v35);
}

void func_ov003_021cc310(void) {
    func_ov003_021d1ee0((int) (2), (int) (1), (u32) (1), (u16) (8));
    func_ov003_021d1ee0((int) (2), (int) (0), (u32) (0x15), (u16) (8));
    func_ov003_021d2784((int) (1), (u32) (1));
    func_ov003_021d2784((int) (0), (u32) (0x15));
    func_ov003_021c212c(func_ov003_021cc2e0);
    return;
}

void func_ov003_021cc2e0(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if ((iVar1 == 0) && (iVar1 = func_ov003_021d1f70((int) (0)), iVar1 == 0)) {
        func_ov003_021bf5c8((u32) (6));
        func_ov003_021c212c(func_ov003_021cc2bc);
    }
    return;
}
