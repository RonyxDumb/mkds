#include "Main/Unknown/code_02108c1c.h"

void func_02108ddc(void) {
    u32 uVar1;
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217c868)))));
    func_0212c6f0(((u32) ((u32) (&data_0217c788))), 1);
    func_0212c6f0(((u32) ((u32) (&data_0217c778))), 1);
    uVar1 = ((u32) ((u32) (&data_0217d0a0)));
    *((u32 *) ((u32) (&data_0217c7a4))) = 1;
    func_0212d5e0((Unk0212d5f8 *) (uVar1));
    return;
}

void func_02108d80(void) {
    u32 uVar1;
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217c868)))));
    func_0212c6f0(((u32) ((u32) (&data_0217c788))), 0xd);
    uVar1 = ((u32) ((u32) (&data_0217c778)));
    *((u32 *) ((u32) (&data_0217c7a4))) = 0;
    func_0212c6f0(uVar1, 1);
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217d0a0)))));
    return;
}

// non-matching: 13 instructions differ; first at +0x0: original `stmdb sp!, {lr}`, ours `stmdb sp!, {r4, lr}`
void func_02108d00(void) {
    u32 uVar1;
    func_0212c6f0(((u32) ((u32) (&data_0217c788))), 1);
    uVar1 = ((u32) ((u32) (&data_0217c778)));
    *((u32 *) ((u32) (&data_0217c7a4))) = 0;
    func_0212c6f0(uVar1, 1);
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217c868)))));
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217c868)))));
    func_0212ecc0((const void *) (((u32) ((u32) (&data_0217d068)))), (u32) (0), (u32) (1));
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217d0a0)))));
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217d0a0)))));
    return;
}

// non-matching: 13 instructions differ; first at +0x0: original `stmdb sp!, {lr}`, ours `stmdb sp!, {r4, lr}`
void func_02108c80(void) {
    u32 uVar1;
    func_0212c6f0(((u32) ((u32) (&data_0217c788))), 1);
    uVar1 = ((u32) ((u32) (&data_0217c778)));
    *((u32 *) ((u32) (&data_0217c7a4))) = 0;
    func_0212c6f0(uVar1, 1);
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217c868)))));
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217c868)))));
    func_0212ecc0((const void *) (((u32) ((u32) (&data_0217d068)))), (u32) (0), (u32) (1));
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217d0a0)))));
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217d0a0)))));
    return;
}

// non-matching: 0x78 bytes, original 0x64; 31 instructions differ; first at +0x0: original `stmdb sp!, {lr}`, ours
// `stmdb sp!, {r4, lr}`
void func_02108c1c(void) {
    func_0212c6f0(((u32) ((u32) (&data_0217c788))), 1);
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217c868)))));
    if (*(u32 *) (((u32) ((u32) (&data_0217c788)))) >> (((u32) ((u32) (&data_0217c788))) & 3) * 8 != 0 ||
        *(u32 *) (((u32) ((u32) (&data_0217c788)))) << (((u32) ((u32) (&data_0217c788))) & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(((u32) ((u32) (&data_0217c788))), 0);
    }
    func_0212ecc0((const void *) (((u32) ((u32) (&data_0217c788)))), (u32) (0), (u32) (8));
    func_0212d5e0((Unk0212d5f8 *) (((u32) ((u32) (&data_0217d0a0)))));
    return;
}
