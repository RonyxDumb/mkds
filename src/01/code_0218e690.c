#include "01/code_0218e690.h"

// non-matching: 6 instructions differ; first at +0x60: original `ldr r0, [pc, #0x48] (->0x4ec)`, ours `ldr r2, [pc,
// #0x48] (->0xac)`
void func_ov001_0218ead0(int param_1) {
    int iVar1;
    u32 *puVar2;
    u32 *puVar3;
    u32 uVar4;
    func_ov001_02187218(param_1, 5, ((u32) ((u32) (&func_ov001_0218edb8))));
    func_ov001_0218f850((int) (param_1));
    func_ov001_02188e24((int) (param_1), (u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x000001a8u))),
                        (int) (((u32) ((u32) (&func_ov001_0218eb94)))));
    func_ov001_02182a3c(0);
    func_ov001_02187e48((int) (param_1), (int) (*(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x00000140u))));
    iVar1 = *(int *) (param_1 + 0xa8);
    if (iVar1 == 1) {
        uVar4 = 2;
    } else if (iVar1 == 2) {
        uVar4 = 3;
    } else if (iVar1 == 3) {
        uVar4 = 3;
    } else {
        uVar4 = 1;
    }
    *(u32 *) (param_1 + 0xa8) = uVar4;
    if (*((int *) ((u32) (&data_0217d20c))) != 3) {
        *((int *) ((u32) (&data_0217d21c))) = *((int *) ((u32) (&data_0217d20c)));
    }
    *((int *) ((u32) (&data_0217d20c))) = 3;
    puVar2 = (u32 *) (param_1 + ((int) 0x00000270u));
    *puVar2 = *(u32 *) (*(int *) (param_1 + 0xa0) + 0xc);
    puVar3 = (u32 *) (param_1 + ((int) 0x00000264u));
    *puVar3 = *puVar2;
    puVar2 = (u32 *) (param_1 + ((int) 0x00000268u));
    *puVar2 = *puVar3;
    *(u32 *) (param_1 + ((int) 0x0000025cu)) = *puVar2;
    return;
}

u32 func_ov001_0218ea98(int param_1) {
    int iVar1;
    int iVar2;
    iVar2 = *(int *) (*(int *) (param_1 + 0x9c) + 4) + *(int *) (*(int *) (param_1 + 0xa0) + 0x84);
    iVar1 = *(int *) (param_1 + 8) - *(int *) (*(int *) (param_1 + 0xa0) + 0x88);
    if (iVar1 <= iVar2) {
        iVar1 = iVar2;
    }
    *(int *) (param_1 + 8) = iVar1;
    func_02061860();
    return 0;
}

// non-matching: 50 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push {r4, r5, lr}`
void func_ov001_0218e92c(int param_1) {
    int iVar1;
    u32 uVar2;
    u32 *puVar3;
    int iVar4;
    u32 *puVar5;
    func_ov001_02187218(param_1, 5, ((u32) ((u32) (&func_ov001_0218ea98))));
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x00000170u)),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x00000174u)));
    func_ov001_02188d1c(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x00000178u)),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x0000017cu)));
    func_ov001_02188c90((Unk02188950 *) (param_1));
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188e24((int) (param_1), (u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x00000194u))),
                        (int) (((u32) ((u32) (&func_ov001_0218ead0)))));
    func_ov001_021875c0((int) (param_1), (u32) (0), (u32) (0), (u32) (0), (u32) (((u32) 0x00000431u)), (u32) (0));
    func_ov001_021875c0((int) (param_1), (u32) (0), (u32) (0), (u32) (0), (u32) (((u32) 0x00000430u)), (u32) (0));
    func_ov001_021875c0((int) (param_1), (u32) (0), (u32) (0), (u32) (0), (u32) (((u32) 0x00000432u)), (u32) (0));
    if (*((int *) ((u32) (&data_0217d20c))) != 4) {
        *((int *) ((u32) (&data_0217d21c))) = *((int *) ((u32) (&data_0217d20c)));
    }
    *((int *) ((u32) (&data_0217d20c))) = 4;
    func_ov001_02188200((int) (param_1), (u32) (((u32) ((u32) (&func_ov001_0218e38c)))));
    *(u16 *) (param_1 + 2) = *(u16 *) (param_1 + 2) | *((u16 *) ((u32) (&data_ov001_021a65b0)));
    if (*(int *) (*((int *) ((u32) (&data_021759c0))) + 8) == 4) {
        iVar1 = ((u16) func_ov001_02181800());
    } else {
        iVar1 = 0;
    }
    iVar4 = *(int *) (*(int *) (param_1 + 0xa0) + ((int) 0x0000018cu));
    if (iVar4 >= iVar1) {
        if (*(int *) (*((int *) ((u32) (&data_021759c0))) + 8) == 4) {
            iVar4 = ((u16) func_ov001_02181800());
        } else {
            iVar4 = 0;
        }
    }
    func_ov001_02182a3c(iVar4);
    uVar2 = _s32_div_f(*(u32 *) (*(int *) (param_1 + 0xa0) + 0xc), 2);
    puVar5 = (u32 *) (param_1 + ((int) 0x00000270u));
    *puVar5 = uVar2;
    puVar3 = (u32 *) (param_1 + ((int) 0x00000264u));
    *puVar3 = *puVar5;
    puVar5 = (u32 *) (param_1 + ((int) 0x00000268u));
    *puVar5 = *puVar3;
    *(u32 *) (param_1 + ((int) 0x0000025cu)) = *puVar5;
    return;
}

void func_ov001_0218e8d8(int param_1) {
    func_ov001_02187218(param_1, 5, 0);
    func_ov001_02188d30(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x00000168u)),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x0000016cu)),
                        ((u32) ((u32) (&func_ov001_0218e92c))));
    func_ov001_02188c90((Unk02188950 *) (param_1));
    func_ov001_02188cec(param_1, 0);
    func_ov001_02182a3c(0);
    func_020d2774((int) (param_1), (u32) (((u32) 0x00000230u)));
    return;
}

void func_ov001_0218e8b0(u32 param_1) {
    func_ov001_02187218(param_1, 1, 0);
    func_ov001_021888a4((int) (param_1), (int) (0), (u32) (((u32) 0x00019000u)));
    func_0206184c();
    func_ov001_021827f0();
    return;
}

// non-matching: 0x4c bytes, original 0x50; 10 instructions differ; first at +0x6: original `ldr r2, [pc, #0x34]
// (->0x20c)`, ours `ldr r2, [pc, #0x30] (->0x38)`
void func_ov001_0218e860(int param_1) {
    func_ov001_02187218(param_1, 5, ((u32) ((u32) (&func_ov001_0218f688))));
    func_ov001_0218f850((int) (param_1));
    func_ov001_02188e24((int) (param_1), (u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x000001a8u))),
                        (int) (((u32) ((u32) (&func_ov001_0218e8b0)))));
    if (*((int *) ((u32) (&data_0217d20c))) != 3) {
        *((int *) ((u32) (&data_0217d21c))) = *((int *) ((u32) (&data_0217d20c)));
    }
    *((int *) ((u32) (&data_0217d20c))) = 3;
    return;
}

// non-matching: 0x8c bytes, original 0x90; 12 instructions differ; first at +0x10: original `ldr r2, [pc, #0x5c]
// (->0x1b0)`, ours `ldr r2, [pc, #0x58] (->0x6c)`
void func_ov001_0218e7d0(int param_1) {
    func_ov001_02187218(param_1, 1, 0);
    func_ov001_021888a4((int) (param_1), (int) (0), (u32) (((u32) 0x00019000u)));
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x00000198u)),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x0000019cu)));
    func_ov001_02188d1c(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x000001a0u)),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x000001a4u)));
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188c90((Unk02188950 *) (param_1));
    if (*((int *) ((u32) (&data_0217d20c))) != 3) {
        *((int *) ((u32) (&data_0217d21c))) = *((int *) ((u32) (&data_0217d20c)));
    }
    *((int *) ((u32) (&data_0217d20c))) = 3;
    *(u16 *) (param_1 + 2) = *(u16 *) (param_1 + 2) | *((u16 *) ((u32) (&data_ov001_021a65bc)));
    return;
}

void func_ov001_0218e7b0(u32 param_1) {
    func_ov001_02187218(param_1, 1, 0);
    func_ov001_021888a4((int) (param_1), (int) (0), (u32) (((u32) 0x00019000u)));
    return;
}

// non-matching: 0x4c bytes, original 0x50; 10 instructions differ; first at +0x6: original `ldr r2, [pc, #0x34]
// (->0x10c)`, ours `ldr r2, [pc, #0x30] (->0x38)`
void func_ov001_0218e760(int param_1) {
    func_ov001_02187218(param_1, 5, ((u32) ((u32) (&func_ov001_0218f688))));
    func_ov001_0218f850((int) (param_1));
    func_ov001_02188e24((int) (param_1), (u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x000001a8u))),
                        (int) (((u32) ((u32) (&func_ov001_0218e7b0)))));
    if (*((int *) ((u32) (&data_0217d20c))) != 3) {
        *((int *) ((u32) (&data_0217d21c))) = *((int *) ((u32) (&data_0217d20c)));
    }
    *((int *) ((u32) (&data_0217d20c))) = 3;
    return;
}

// non-matching: 0x4c bytes, original 0x50; 7 instructions differ; first at +0x2a: original `ldr r0, [pc, #0x1c]
// (->0xc8)`, ours `ldr r2, [pc, #0x18] (->0x44)`
void func_ov001_0218e710(int param_1) {
    func_ov001_02187218(param_1, 8, 0);
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 0x78),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x7c));
    func_ov001_02188c90((Unk02188950 *) (param_1));
    func_ov001_02188cec(param_1, 0);
    if (*((int *) ((u32) (&data_0217d20c))) != 6) {
        *((int *) ((u32) (&data_0217d21c))) = *((int *) ((u32) (&data_0217d20c)));
    }
    *((int *) ((u32) (&data_0217d20c))) = 6;
    func_0206184c();
    return;
}

// non-matching: 0x7c bytes, original 0x80; 10 instructions differ; first at +0x1c: original `ldr r0, [pc, #0x44]
// (->0x64)`, ours `ldr r0, [pc, #0x40] (->0x60)`
void func_ov001_0218e690(u32 param_1) {
    func_ov001_02187218(param_1, 8, 0);
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 0x70),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x74));
    func_0208b7bc(((u32) 0x000003feu), param_1 + 4);
    func_0208b7bc(((u32) 0x000003fdu), param_1 + 4);
    if (*((int *) ((u32) (&data_0217d20c))) != 7) {
        *((int *) ((u32) (&data_0217d21c))) = *((int *) ((u32) (&data_0217d20c)));
    }
    *((int *) ((u32) (&data_0217d20c))) = 7;
    *(u16 *) (param_1 + 2) = *(u16 *) (param_1 + 2) | *((u16 *) ((u32) (&data_ov001_021a65b4)));
    *(u16 *) (param_1 + 2) = *(u16 *) (param_1 + 2) | *((u16 *) ((u32) (&data_ov001_021a65b8)));
    *(u16 *) (param_1 + 2) = *(u16 *) (param_1 + 2) | *((u16 *) ((u32) (&data_ov001_021a65bc)));
    return;
}
