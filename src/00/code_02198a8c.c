#include "00/code_02198a8c.h"
#include "00/code_02198714.h"
#include "00/code_02198ba8.h"
#include "00/code_02198d04.h"
#include "00/code_0219a000.h"
#include "00/code_0219a01c.h"
#include "00/code_0219a09c.h"
#include "00/code_0219a3f4.h"
#include "00/code_021988e8.h"

void func_ov000_02198a8c(Unk021981d0 *a) {
    if (func_ov000_0219914c((Unk02197e8c *) a) != 0) {
        if (func_ov000_0219a09c((int) a) != 0) {
            func_ov000_0219a06c((Unk02197e8c *) a);
        }
    }
}

void func_ov000_02198ab0(Unk02198394 *a) {
    func_ov000_021988e8(a);
    func_ov000_0219a3f8((u32 *) a);
}

void func_ov000_02198ac4(Unk02197e8c **a, const u8 *b, u32 c, u32 d, u32 e) {
    func_ov000_0219a430(a, b, c, d, e);
}

int func_ov000_02198ad8(Unk021981d0 *a, u8 *b, int c, int d) {
    if (d != 0) {
        return func_ov000_02198f80((int) a, (u32) b, c);
    }
    return func_ov000_02198c58(a, b, c);
}

int func_ov000_02198af4(Unk021981d0 *a, Unk02198af4 *b) {
    func_ov000_0219a01c(a->mUnk_50.mUnk_00, b->mUnk_00 + 5, a->mUnk_66);
    if (func_ov000_02198714((u32 *) a, (u32) (a->mUnk_50.mUnk_00 + b->mUnk_00), b->mUnk_04) == 0) {
        return 0;
    }
    b->mUnk_0c = a->mUnk_88;
    if (a->mUnk_50.mUnk_00[b->mUnk_00 + 2] == 2) {
        a->mUnk_8c = a->mUnk_88;
    }
    return 1;
}

// non-matching: same size and instruction mix, but the original computes sp+4 into r3 first and keeps the data pointer
// in r5 and the loaded bytes in r4 (ours: pointer in r4, bytes in r5, sp+4 in r3 after the load)
int func_ov000_02198b50(Unk02198394 *a, u32 b, int c) {
    u8 d[3];
    d[0] = data_ov000_021b3fa4[0];
    d[1] = data_ov000_021b3fa4[1];
    d[2] = 0x68;
    if (func_ov000_0219a110((u32 *) a, b, c, (u32) d, 3) != 0) {
        return 1;
    }
    return 0;
}

int func_ov000_02198b8c(Unk021981d0 *a) {
    return func_ov000_02198b50(a->mUnk_08, a->mUnk_00, a->mUnk_04);
}
