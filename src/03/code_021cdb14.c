#include "03/code_021cdb14.h"

int func_ov003_021cdb6c(void) {
    return *((int *) ((u32) (&data_ov003_021da270))) + ((int) 0x00000400u);
}

void func_ov003_021cdb58(u8 param_1) {
    *(u8 *) (*((int *) ((u32) (&data_ov003_021da270))) + ((int) 0x000004f5u)) = param_1;
    return;
}

void func_ov003_021cdb44(u8 param_1) {
    *(u8 *) (*((int *) ((u32) (&data_ov003_021da270))) + ((int) 0x000004f6u)) = param_1;
    return;
}

// non-matching: 0x2c bytes, original 0x30; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021cdb14(u32 param_1) {
    func_0214d1fc((const void *) ((u16 *) (u32) (param_1)),
                  (void *) ((u32 *) (u32) (*((int *) ((u32) (&data_ov003_021da270))) + ((int) 0x00000440u))),
                  (u32) (0x20));
    *(u8 *) (*((int *) ((u32) (&data_ov003_021da270))) + ((int) 0x000004e7u)) = 0;
    return;
}
