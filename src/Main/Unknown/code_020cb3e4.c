#include "Main/Unknown/code_020cb3e4.h"

#pragma thumb on

// non-matching: 0x9c bytes, original 0xa8; 30 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_020cb3e4(void) {
    int iVar1;
    iVar1 = ((u32) func_020cccc0());
    if (iVar1 != 0) {
        func_020cb4a8((int) (0x18));
        func_02148950((u16) (1), (u32) (0), (int) (0));
        func_0214c090(
            (const void *) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217b43c))) + ((int) 0x00000910u)) + 0xc)),
            (int) (0), (u32) (((u32) 0x000001a0u)));
        func_0214c090(
            (const void *) (*(int *) (*(int *) (*((int *) ((u32) (&data_0217b43c))) + ((int) 0x00000910u)) + 0xc) +
                            ((int) 0x000001c0u)),
            (int) (((int) 0x000001c0u)), (u32) (0x40));
        func_0214bf04(
            (const void *) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217b43c))) + ((int) 0x00000914u)) + 0x14)),
            (int) (0), (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217b43c))) + ((int) 0x00000914u)) + 0x10)));
        func_020cb48c((int) (0x16));
        func_02148934((u32) (0));
        func_0214c028(
            (const void *) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217b43c))) + ((int) 0x00000920u)) + 0xc)),
            (int) (0), (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217b43c))) + ((int) 0x00000920u)) + 8)));
        func_0214bea4(
            (const void *) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217b43c))) + ((int) 0x00000924u)) + 0x14)),
            (int) (0), (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217b43c))) + ((int) 0x00000924u)) + 0x10)));
    }
    return;
}

#pragma thumb off
