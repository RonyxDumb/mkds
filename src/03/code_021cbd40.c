#include "03/code_021cbd40.h"
#include "03/code_021cbd20.h"
#include "03/code_021cef6c.h"

void func_ov003_021cbe44(void) {
    int iVar1;
    func_ov003_021cbe40();
    func_ov003_021cbe3c();
    iVar1 = func_ov003_021cef80();
    if (iVar1 == 0) {
        func_ov003_021cdc10((u32) (6));
        func_ov003_021cef90();
        func_ov003_021cdc10((u32) (6));
        func_ov003_021c212c(func_ov003_021cbe14);
    }
    return;
}

void func_ov003_021cbe40(void) {
    return;
}

void func_ov003_021cbe3c(void) {
    return;
}

void func_ov003_021cbe14(void) {
    int iVar1;
    iVar1 = func_ov003_021cef6c();
    if (iVar1 == 0) {
        func_ov003_021d1ee0((int) (3), (int) (0), (u32) (0x14), (u16) (8));
        func_ov003_021c212c(func_ov003_021cbde4);
    }
    return;
}

void func_ov003_021cbde4(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (0));
    if (iVar1 == 0) {
        func_ov003_021d272c((int) (0), (u32) (0x14));
        func_ov003_021c2120((u32) (0), (u32) (1));
        func_ov003_021c212c(func_ov003_021cbb98);
    }
    return;
}

void func_ov003_021cbdbc(void) {
    *(u8 *) &data_ov003_021da24c = 0;
    func_ov003_021cbd68();
    func_ov003_021bf578((u32) (0x77));
    func_ov003_021c212c(func_ov003_021cbd40);
    return;
}

void func_ov003_021cbd68(void) {
    unsigned int v2 = ((u32) (&data_ov003_021d76f4));
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
    *(unsigned short *) ((v5) + (0)) = (unsigned short) (v9);
    v11 = 0x400100au;
    v12 = ((unsigned int) *(unsigned short *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(unsigned short *) ((v11) + (0)) = (unsigned short) (v14);
    v16 = 0x400000au;
    v17 = ((unsigned int) *(unsigned short *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(unsigned short *) ((v16) + (0)) = (unsigned short) (v19);
    v21 = 0x400000cu;
    v22 = ((unsigned int) *(unsigned short *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(unsigned short *) ((v21) + (0)) = (unsigned short) (v24);
}

void func_ov003_021cbd40(void) {
    func_ov003_021d1ee0((int) (2), (int) (0), (u32) (0x15), (u16) (8));
    func_ov003_021d2784((int) (0), (u32) (0x15));
    func_ov003_021c212c(func_ov003_021cbd20);
    return;
}
