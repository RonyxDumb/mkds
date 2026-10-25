#include "Main/Unknown/code_0202808c.h"

#pragma thumb on

// non-matching: 0x48 bytes, original 0x50; 14 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_0202808c(void) {
    int iVar1;
    if ((*(int *) (*((int *) ((u32) (&data_02174e18))) + ((int) 0x00000100u)) == 1) &&
        (iVar1 = ((u32) func_0202811c()), iVar1 == 2)) {
        func_021281fc();
    }
    iVar1 = func_020280dc();
    if (iVar1 == 0) {
        func_0212b91c();
    } else {
        func_0211f498();
    }
    func_02036ab0((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e18))) + 0x8c)));
    *((int *) ((u32) (&data_02174e18))) = 0;
    return;
}

#pragma thumb off
