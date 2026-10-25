#include "Main/Unknown/code_02030ae8.h"

#pragma thumb on

// non-matching: 0x2c bytes, original 0x30; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_02030ae8(void) {
    func_02125ee8((int) (0), (int) (0));
    func_0212b91c();
    func_02036ab0((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e58))) + ((int) 0x00000150u))));
    *((int *) ((u32) (&data_02174e58))) = 0;
    return;
}

#pragma thumb off
