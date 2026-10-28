#include "Main/Unknown/code_020fcac0.h"

void func_020fcb30(unsigned int p0) {
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 368) = (unsigned int) (0x1u);
}

// non-matching: 0x8c bytes, original 0x70; 14 instructions differ; first at +0x8: original `ldr r1, [pc, #0x58]
// (->0x68)`, ours `ldr r1, [pc, #0x74] (->0x84)`
void func_020fcac0(int param_1) {
    u32 uVar1;
    u32 uVar2;
    func_02046be8((void *) (param_1 + 0x2e8), (UnkFunc *const *) &data_0216c6b4, 8, (void *) param_1);
    func_021471bc((Unk02012f58 *) (param_1 + 0x2b4));
    uVar2 = ((u32) (&data_0217561c));
    *(u16 *) (param_1 + 0x274) = 1;
    uVar1 = uVar2 & 3;
    uVar2 = *(u32 *) (uVar2 & 0xfffffffc);
    *(short *) (param_1 + 0x276) = (short) *(s8 *) ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x474);
    *(u32 *) (param_1 + 0x278) = 0;
    *(u32 *) (param_1 + 0x26c) = 0;
    *(u32 *) (param_1 + 0x270) = 0xdc;
    *(u16 *) (param_1 + 0x280) = 0;
    *(u32 *) (param_1 + 0x2e4) = 0;
    return;
}
