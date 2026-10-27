#include "03/code_021cc084.h"
#include "03/code_021cc064.h"

void func_ov003_021cc214(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021cc1cc);
    return;
}

void func_ov003_021cc1cc(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70(1);
    if (iVar1 == 0) {
        func_ov003_021bf344();
        if (data_ov003_021da254 == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021cc144);
    }
    return;
}

void func_ov003_021cc144(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70(0);
    if ((iVar1 == 0) && (((data_ov003_021da254 != 0 || (iVar1 = func_ov003_021d1f70(1), iVar1 == 0)) &&
                          (iVar1 = func_ov003_021bf2f0(), iVar1 != 0)))) {
        func_ov003_021d2168(0);
        if (data_ov003_021da254 == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da254 == 0) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cb294);
            return;
        }
        func_ov003_021c2120(2, 1);
        func_ov003_021c212c(func_ov003_021cc83c);
    }
    return;
}

void func_ov003_021cc110(void) {
    data_ov003_021da250 = 0;
    func_ov003_021cc0ac();
    func_ov003_021bf86c(8);
    func_ov003_021bf578(0x6f);
    func_ov003_021cdc10(0x10);
    func_ov003_021c212c(func_ov003_021cc084);
    return;
}

void func_ov003_021cc0ac(void) {
    unsigned int v2 = ((u32) (&data_ov003_021d7728));
    unsigned int v3 = ((u32) (&func_0214bc9c));
    unsigned int v4 = func_ov003_021bf620((unsigned int) (v2), (unsigned int) (v3));
    unsigned int v5 = 0x4001008u;
    unsigned int v6 = ((unsigned int) *(unsigned short *) ((v5) + (0)));
    unsigned int v8 = ((v6) & ~(0x3u));
    unsigned int v9 = ((v8) | (0x3u));
    unsigned int v11;
    unsigned int v12;
    unsigned int v13;
    unsigned int v14;
    unsigned int v16;
    unsigned int v17;
    unsigned int v18;
    unsigned int v19;
    unsigned int v21;
    unsigned int v22;
    unsigned int v23;
    unsigned int v24;
    unsigned int v26;
    unsigned int v27;
    unsigned int v28;
    unsigned int v29;
    *(unsigned short *) ((v5) + (0)) = (unsigned short) (v9);
    v11 = 0x400100au;
    v12 = ((unsigned int) *(unsigned short *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(unsigned short *) ((v11) + (0)) = (unsigned short) (v14);
    v16 = 0x4000008u;
    v17 = ((unsigned int) *(unsigned short *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(unsigned short *) ((v16) + (0)) = (unsigned short) (v19);
    v21 = 0x400000au;
    v22 = ((unsigned int) *(unsigned short *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(unsigned short *) ((v21) + (0)) = (unsigned short) (v24);
    v26 = 0x400000cu;
    v27 = ((unsigned int) *(unsigned short *) ((v26) + (0)));
    v28 = ((v27) & ~(0x3u));
    v29 = ((v28) | (0x3u));
    *(unsigned short *) ((v26) + (0)) = (unsigned short) (v29);
}

void func_ov003_021cc084(void) {
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c212c(func_ov003_021cc064);
    return;
}
