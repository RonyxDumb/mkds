#include "03/code_021c6d0c.h"

void func_ov003_021c6da4(void) {
    unsigned int v2 = ((u32) (&data_ov003_021d72a4));
    unsigned int v3 = ((u32) (&func_0214c090));
    unsigned int v4 = func_ov003_021bf620((unsigned int) (v2), (unsigned int) (v3));
    unsigned int v5 = ((u32) (&data_ov003_021d72b8));
    unsigned int v6 = ((u32) (&func_0214b95c));
    unsigned int v7 = func_ov003_021bf620((unsigned int) (v5), (unsigned int) (v6));
    unsigned int v8 = ((u32) (&data_ov003_021d72d0));
    unsigned int v9 = ((u32) (&func_0214c160));
    unsigned int v10 = func_ov003_021bf620((unsigned int) (v8), (unsigned int) (v9));
    unsigned int v11 = ((u32) (&data_ov003_021d72e8));
    unsigned int v12 = ((u32) (&func_0214bc9c));
    unsigned int v13 = func_ov003_021bf620((unsigned int) (v11), (unsigned int) (v12));
    unsigned int v14 = 0x4001008u;
    unsigned int v15 = ((unsigned int) *(unsigned short *) ((v14) + (0)));
    unsigned int v17 = ((v15) & ~(0x3u));
    unsigned int v18 = ((v17) | (0x3u));
    unsigned int v20;
    unsigned int v21;
    unsigned int v22;
    unsigned int v23;
    unsigned int v25;
    unsigned int v26;
    unsigned int v27;
    unsigned int v29;
    unsigned int v31;
    unsigned int v32;
    unsigned int v33;
    unsigned int v34;
    unsigned int v36;
    unsigned int v37;
    unsigned int v38;
    unsigned int v39;
    *(unsigned short *) ((v14) + (0)) = (unsigned short) (v18);
    v20 = 0x400100au;
    v21 = ((unsigned int) *(unsigned short *) ((v20) + (0)));
    v22 = ((v21) & ~(0x3u));
    v23 = ((v22) | (0x3u));
    *(unsigned short *) ((v20) + (0)) = (unsigned short) (v23);
    v25 = 0x4000008u;
    v26 = ((unsigned int) *(unsigned short *) ((v25) + (0)));
    v27 = ((v26) & ~(0x3u));
    v29 = ((v27) | (0x2u));
    *(unsigned short *) ((v25) + (0)) = (unsigned short) (v29);
    v31 = 0x400000au;
    v32 = ((unsigned int) *(unsigned short *) ((v31) + (0)));
    v33 = ((v32) & ~(0x3u));
    v34 = ((v33) | (0x3u));
    *(unsigned short *) ((v31) + (0)) = (unsigned short) (v34);
    v36 = 0x400000cu;
    v37 = ((unsigned int) *(unsigned short *) ((v36) + (0)));
    v38 = ((v37) & ~(0x3u));
    v39 = ((v38) | (0x3u));
    *(unsigned short *) ((v36) + (0)) = (unsigned short) (v39);
}

void func_ov003_021c6d68(void) {
    func_ov003_021d1ee0((int) (2), (int) (1), (u32) (1), (u16) (8));
    func_ov003_021d1ee0((int) (2), (int) (0), (u32) (0x15), (u16) (8));
    func_ov003_021d2784((int) (1), (u32) (1));
    func_ov003_021d2784((int) (0), (u32) (0x15));
    func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c6d0c)))));
    return;
}

// non-matching: 0x58 bytes, original 0x5c; 11 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c6d0c(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if ((iVar1 == 0) && (iVar1 = func_ov003_021d1f70((int) (0)), iVar1 == 0)) {
        func_ov003_021c0d2c();
        func_ov003_021cdc10((u32) (0x14));
        if (*(unsigned char *) (*((int *) ((u32) (&data_ov003_021da1f8))) + 0x29) == '\0') {
            func_ov003_021c0cd0((u8) (0));
        }
        if (*(unsigned char *) (*((int *) ((u32) (&data_ov003_021da1f8))) + 0x29) == ' ') {
            func_ov003_021c0cbc((u8) (0));
        }
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c6cf0)))));
    }
    return;
}
