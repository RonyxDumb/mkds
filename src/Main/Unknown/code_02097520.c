#include "Main/Unknown/code_02097520.h"

u32 func_0209753c(u32 param_1) {
    void *iVar2;
    iVar2 = func_0209bc5c(func_02100138(0x1a9), param_1);
    *(u32 *) ((u8 *) iVar2 + 0xebc) = 0xaa;
    return 1;
}

void func_02097520(u32 p0) {
    *(u16 *) ((u8 *) p0 + 2) = (u16) ((
        (((u32) *(const u16 *) ((u8 *) p0 + 2))) |
        (((u32) *(const u16 *) ((u8 *) (u32) (((u32) (&data_021564c0))) +
                                                    0)))));
}
