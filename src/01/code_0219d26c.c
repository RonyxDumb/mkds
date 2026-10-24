#include "01/code_0219d26c.h"

// non-matching: 0x50 bytes, original 0x54; 13 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov001_0219d26c(void) {
    *((u16 *) 0x0400000cu) = *((u16 *) 0x0400000cu) & 0x43 | (u16) ((u32) 0x00001e10u);
    *((u32 *) 0x04000000u) = *((u32 *) 0x04000000u) & ((u32) 0xffffe0ffu) | ((u32) 0x00001800u);
    func_02036ab0((u32) (*(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf8))) + ((int) 0x00001030u))));
    *((int *) ((u32) (&data_ov001_021a9bf8))) = 0;
    return;
}
