#include "01/code_0219baf4.h"

// non-matching: 0x4c bytes, original 0x54; 17 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov001_0219baf4(void) {
    if (*(int *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x6c) == 1) {
        *((u32 *) 0x04000000u) = *((u32 *) 0x04000000u) & ((u32) 0xffffe0ffu) | ((u32) 0x00001800u);
    }
    func_0212b91c();
    func_0211de34();
    func_0211df38();
    func_02117218();
    func_02036ab0((void *) (*(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x44)));
    *((int *) ((u32) (&data_ov001_021a9bf4))) = 0;
    return;
}
