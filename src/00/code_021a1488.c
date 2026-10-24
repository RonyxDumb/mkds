#include "00/code_021a1488.h"

// non-matching: 0x94 bytes, original 0x8c; 34 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// r5, r6, r7, lr}`
u32 func_ov000_021a1488(void) {
    u32 uVar1;
    u8 auStack_30[12];
    u8 auStack_24[32];
    if (*(unsigned char *) (*((int *) ((u32) (&data_ov000_021b566c))) + 0x15) != '\x02') {
        return 0;
    }
    func_0200d9e0((u32) (u32) (auStack_30), 0xc, ((u32) ((u32) (&data_ov000_021b40b8))),
                  *(u8 *) (*((int *) ((u32) (&data_ov000_021b566c))) + 0x16) + 1);
    func_ov000_021a363c((u32) (((u32) ((u32) (&data_ov000_021b41a8)))), (u32) ((u32) (u32) (auStack_30)),
                        (u32) ((u32) (u32) (auStack_24)), (u32) (0x2f));
    func_0200d9e0((u32) (u32) (auStack_30), 0xc, ((u32) ((u32) (&data_ov000_021b40b8))),
                  *(u8 *) (*((int *) ((u32) (&data_ov000_021b566c))) + 0xd) + 1);
    func_ov000_021a360c((u32) (((u32) ((u32) (&data_ov000_021b41ac)))), (u32) ((u32) (u32) (auStack_30)),
                        (u32) ((u32) (u32) (auStack_24)), (u32) (0x2f));
    func_0200d9e0((u32) (u32) (auStack_30), 0xc, ((u32) ((u32) (&data_ov000_021b40b8))), 3);
    func_ov000_021a360c((u32) (((u32) ((u32) (&data_ov000_021b4118)))), (u32) ((u32) (u32) (auStack_30)),
                        (u32) ((u32) (u32) (auStack_24)), (u32) (0x2f));
    uVar1 = func_ov000_0219d558((int) (6), (int) ((int) (u32) (auStack_24)), (int) (0));
    return uVar1;
}
