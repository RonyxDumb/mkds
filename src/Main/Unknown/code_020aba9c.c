#include "Main/Unknown/code_020aba9c.h"

#pragma thumb on

// non-matching: 0x3c bytes, original 0x44; 16 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_020aba9c(void) {
    func_0200ee74((u32) (*(u32 *) (*((int *) ((u32) (&data_0217b334))) + 4)),
                  (int) (*(u32 *) (*((int *) ((u32) (&data_0217b334))) + 0xc)));
    func_0214bc34((const void *) (*(u32 *) (*((int *) ((u32) (&data_0217b334))) + 4)), (int) (0),
                  (u32) (*(u32 *) (*((int *) ((u32) (&data_0217b334))) + 0xc)));
    func_0200ee74((u32) (*(u32 *) *((int *) ((u32) (&data_0217b334)))),
                  (int) (((u32 *) *((int *) ((u32) (&data_0217b334))))[2]));
    func_0214b8f4((const void *) (*(u32 *) *((int *) ((u32) (&data_0217b334)))), (int) (0),
                  (u32) (((u32 *) *((int *) ((u32) (&data_0217b334))))[2]));
    return;
}

#pragma thumb off
