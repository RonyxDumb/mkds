#include "Main/Unknown/code_0200ba84.h"

#pragma thumb on

void func_0200bab0(void) {
    *(u16 *) &data_0216fde4 = 0;
    *(u32 *) ((*(int *) &data_0216fde8) + 0x5f04) = 0;
    func_0200bc0c();
    func_0200ba44((u32) 0x14, (u32) 0);
}

unsigned int func_0200baa8(void) {
    return 0x5f20u;
}

void func_0200ba84(UnkFunc *p0) {
    unsigned int v1 = (unsigned int) p0;
    unsigned int v2 = ((unsigned int) func_0200fca0());
    unsigned int v3 = ((u32) (&data_0216fde8));
    unsigned int v4 = ((unsigned int) *(unsigned int *) ((v3) + (0)));
    unsigned int v5 = 0x5e0u;
    unsigned int v7;
    *(unsigned int *) ((v4) + (0 + (v5))) = (unsigned int) v1;
    v7 = ((unsigned int) func_0200fcb4((u32) v2));
}

#pragma thumb off
