#include "Main/Unknown/code_021258f0.h"

#pragma thumb on

// non-matching: 0x34 bytes, original 0x38; 12 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_02125928(void) {
    if (*(int *) *((int *) ((u32) (&data_0217d3ec))) != 0) {
        func_02126834();
    }
    if (*(int *) (*((int *) ((u32) (&data_0217d3ec))) + 4) != 0) {
        func_021279a0();
    }
    if (*(int *) (*((int *) ((u32) (&data_0217d3ec))) + 8) != 0) {
        func_02128458();
    }
    return;
}

// non-matching: 0x34 bytes, original 0x38; 12 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_021258f0(void) {
    if (*(int *) *((int *) ((u32) (&data_0217d3ec))) != 0) {
        func_02126730();
    }
    if (*(int *) (*((int *) ((u32) (&data_0217d3ec))) + 4) != 0) {
        func_021278f4();
    }
    if (*(int *) (*((int *) ((u32) (&data_0217d3ec))) + 8) != 0) {
        func_021283bc();
    }
    return;
}

#pragma thumb off
