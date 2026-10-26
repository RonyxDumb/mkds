#include "00/code_02187fb8.h"

// non-matching: 0x4c bytes, original 0x50; 13 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov000_02187fb8(void) {
    if (*((int *) ((u32) (&data_ov000_021b4cb0))) != 0) {
        if (*((int *) ((u32) (&data_ov000_021b4cac))) != 0) {
            func_ov000_02187274();
        }
        func_ov000_02186474();
        if (*(int *) (*((int *) ((u32) (&data_ov000_021b4cb0))) + ((int) 0x00000188u)) != 0) {
            func_0200e084((Unk0200db5c *) (*((int *) ((u32) (&data_ov000_021b4cb0))) + ((int) 0x0000011cu)));
        }
        *(u32 *) (*((int *) ((u32) (&data_ov000_021b4cb0))) + 4) = 0xfffffff9;
    }
    return;
}
