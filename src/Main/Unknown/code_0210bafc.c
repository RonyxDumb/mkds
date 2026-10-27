#include "Main/Unknown/code_0210bafc.h"

#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"

u32 func_0210bb74(s32 a, s32 b, s32 c) {
    s32 p;
    s32 v;

    p = ((Unk0217cd30 *) data_0217cd30)[b].mUnk_00[c];
    v = p != 0 ? ((u32 *) p)[a] : 0xffff;
    if (v != 0xffff) {
        return (u16) v;
    }
    v = data_0215a6fc[b][c];
    if (v == 0x14) {
        v = 0xffff;
    }
    if (v == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (data_0216ca84 + a * 0x26 + v * 2);
}

u32 func_0210bafc(s32 a, s32 b, s32 c) {
    s32 p;
    s32 v;

    p = ((Unk0217cd30 *) data_0217cd30)[b].mUnk_00[c];
    v = p != 0 ? ((u32 *) p)[a] : 0xffff;
    if (v != 0xffff) {
        return (u16) v;
    }
    v = data_0215a6fc[b][c];
    if (v == 0xe) {
        v = 0xffff;
    }
    if (v == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (data_0216ca68 + a * 0x1a + v * 2);
}
