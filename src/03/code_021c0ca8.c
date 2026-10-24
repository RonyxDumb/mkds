#include "03/code_021c0ca8.h"

// non-matching: 0x30 bytes, original 0x34; 9 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c0cf8(void) {
    func_ov003_021d197c(*(u32 *) (*((int *) ((u32) (&data_ov003_021da15c))) + ((int) 0x00000114u)));
    func_ov003_021d34e0((int) (*(u32 *) (*((int *) ((u32) (&data_ov003_021da15c))) + ((int) 0x00000118u))),
                        (u32) (((u32) ((u32) (&func_ov003_021bfc80)))));
    return;
}

u8 func_ov003_021c0ce4(void) {
    return *(u8 *) (*((int *) ((u32) (&data_ov003_021da15c))) + ((int) 0x0000011cu));
}

void func_ov003_021c0cd0(u8 param_1) {
    *(u8 *) (*((int *) ((u32) (&data_ov003_021da15c))) + ((int) 0x00000123u)) = param_1;
    return;
}

void func_ov003_021c0cbc(u8 param_1) {
    *(u8 *) (*((int *) ((u32) (&data_ov003_021da15c))) + ((int) 0x00000124u)) = param_1;
    return;
}

u32 func_ov003_021c0ca8(void) {
    if (*((int *) ((u32) (&data_ov003_021da15c))) != 0) {
        return 1;
    }
    return 0;
}
