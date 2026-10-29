#include "Main/Unknown/code_02057fe8.h"
#include "Main/Unknown/code_02050000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline u32 func_02057fe8_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_02057fe8_inline2(u16 v) {
    Unk0217aa00_1608 *p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = v;
    p->mUnk_12 = 1;
}

void func_02057fe8(void) {
    if (func_02057fe8_inline() == 1) {
        if ((data_0217aa00->mUnk_162a & (1 << data_0217aa00->mUnk_164e)) != 0) {
            if (func_020503cc(data_0217aa00->mUnk_164e, data_0217aa00->mUnk_0044.mUnk_43) != 0) {
                data_0217aa00->mUnk_164e += 1;
            }
        } else {
            data_0217aa00->mUnk_164e += 1;
        }
        if (data_0217aa00->mUnk_164e > 8) {
            func_02057fe8_inline2(0xb);
        }
    } else if (data_0217aa00->mUnk_162a == (data_0217aa00->mUnk_162a & data_0217aa00->mUnk_164d)) {
        func_02057fe8_inline2(0xb);
    }
}
#pragma thumb off
