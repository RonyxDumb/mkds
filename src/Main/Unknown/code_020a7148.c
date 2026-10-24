#include "Main/Unknown/code_020a7148.h"

// non-matching: 0x9c bytes, original 0x80; 11 instructions differ; first at +0x28: original `ldr r0, [pc, #0x40]
// (->0x70)`, ours `ldr r1, [pc, #0x5c] (->0x8c)`
void func_020a7148(u32 param_1) {
    int iVar1;
    iVar1 = func_020d3bf8((u32) (0x6a));
    if (iVar1 == 0) {
        func_020ac588((u32) (0x6a), (int) (0x14), (u32) (param_1));
        func_020ac588(
            (u32) (0x70),
            (int) (*(u8 *) ((*(u32 *) (((u32) (&data_021759c0)) & 0xfffffffc) >> (((u32) (&data_021759c0)) & 3) * 8 |
                             *(u32 *) (((u32) (&data_021759c0)) & 0xfffffffc)
                                 << (((u32) (&data_021759c0)) & 3) * -8 + 0x20) +
                            0x3d0)),
            (u32) (param_1));
        func_020a233c((unsigned int) (((u32) (&func_020a72c8))));
        func_020a2328((unsigned int) (((u32) (&func_020a7270))));
        func_020a2314((unsigned int) (((u32) (&func_020a71c8))));
        return;
    }
    func_020d2398((unsigned int) (param_1));
    return;
}
