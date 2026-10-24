#include "Main/Unknown/code_02125da0.h"

#pragma thumb on

// non-matching: 0x38 bytes, original 0x40; 16 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_02125da0(void) {
    if (*(int *) *((int *) ((u32) (&data_0217d3ec))) != 0) {
        func_021274e0();
    }
    if (*(int *) (*((int *) ((u32) (&data_0217d3ec))) + 4) != 0) {
        func_0212804c();
    }
    if (*(int *) (*((int *) ((u32) (&data_0217d3ec))) + 8) != 0) {
        func_021287c0();
    }
    *((int *) ((u32) (&data_0217d3ec))) = 0;
    return;
}

#pragma thumb off
