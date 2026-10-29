#include "Main/Unknown/code_0205905c.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02050320.h"
#include "Main/Unknown/code_0205955c.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline u32 func_0205905c_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_0205905c_inline2(void) {
    s32 r = 0;
    if (func_0205905c_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = 1;
    }
    return r;
}

static inline s32 func_0205905c_inline3(void) {
    s32 r = 0;
    if (func_0205905c_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = 1;
    }
    return r;
}

static inline s32 func_0205905c_inline4(void) {
    s32 r = 0;
    if (func_0205905c_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = 1;
    }
    return r;
}

u32 func_0205905c(void) {
    if (func_0205905c_inline4()) {
        return 3;
    }
    if (!func_0205905c_inline2()) {
        return 1;
    }
    switch (func_0205905c_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(2, 0, 0);
        default:
            return 3;
    }
}

u32 func_0205910c(void) {
    if (func_0205905c_inline4()) {
        return 3;
    }
    if (!func_0205905c_inline2()) {
        return 1;
    }
    switch (func_0205905c_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(3, 0, 0);
        default:
            return 3;
    }
}

s32 func_020591bc(void) {
    return func_020591cc();
}

s32 func_020591c4(void) {
    return func_020591cc();
}

// non-matching: in the second chain of conditions the original keeps the three flags in r1, r2 and r3 and the loaded
// value in r5; here the flags are in r5, r1 and r2 and the loaded value in r3. The rest is the same.
s32 func_020591cc(void) {
    s32 r;

    r = 0;
    if (!func_0205905c_inline2()) {
        return 1;
    }
    func_02046b40(&data_0217aa00->mUnk_1608);
    if (!func_0205905c_inline4()) {
        if (func_0205905c_inline() == 1 && data_0217aa00->mUnk_0044.mUnk_40 == 0) {
            func_02050e60(7);
        }
    }
    if (data_0217aa00->mUnk_1608.mUnk_0e == 0xf) {
        r = 1;
    }
    return r;
}

#pragma thumb off
