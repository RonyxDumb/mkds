#include "Main/Unknown/code_020580a4.h"
#include "Main/Unknown/code_02050320.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline u32 func_020580a4_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_020580a4_inline2(u16 v) {
    Unk0217aa00_1608 *p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = v;
    p->mUnk_12 = 1;
}

void func_02058198(void) {
    if (data_0217aa00->mUnk_0010 != 0) {
        return;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0xc:
        case 0x25:
        case 0x27:
            func_02051734();
            break;
        case 0xe:
            data_0217aa00->mUnk_0004 = 7;
            func_020580a4_inline2(5);
            break;
    }
}

void func_02058130(void) {
    s32 i;

    data_0217aa00->mUnk_164d = 0;
    i = 0;
    if (data_0217aa00->mUnk_0000 == 2) {
        i = data_0217aa00->mUnk_0432;
    }
    func_0214d1fc(data_0217aa08->mUnk_00->mUnk_20, data_0217aa00->mUnk_045c[(u16) i].mUnk_224, 4);
    data_0217aa00->mUnk_162a |= 1;
}

void func_020580a4(void) {
    s32 v;

    if (func_020580a4_inline() == 1) {
        if (data_0217aa00->mUnk_0044.mUnk_43 == (data_0217aa00->mUnk_0044.mUnk_43 & data_0217aa00->mUnk_164d)) {
            func_020580a4_inline2(0xe);
        }
    } else if (data_0217aa00->mUnk_164d != 0) {
        func_020580a4_inline2(0xe);
    } else {
        if (data_0217aa00->mUnk_0000 == 2) {
            v = data_0217aa00->mUnk_0432;
        } else {
            v = 0;
        }
        func_020503cc((u8) (u16) v, 1);
    }
}
#pragma thumb off
