#include "Main/Unknown/code_02100b84.h"

#include "Main/Unknown/code_02100de4.h"
#include "Main/Unknown/code_021001ac.h"
#include "Main/Unknown/code_020f8e3c.h"

void func_02100bf0(Unk020f41c4_A *p) {
    if (p->mUnk_164 < 0x1f) {
        p->mUnk_164 += 5;
    }
    p->mUnk_178 = (s32) (((s64) p->mUnk_178 * 0xf85) >> 12);
    p->mUnk_180 = (s32) (((s64) p->mUnk_180 * 0xf85) >> 12);
    if (p->mUnk_130 == 0x12) {
        if (p->mUnk_19c == 0) {
            p->mUnk_19c = -0x1ae;
            p->mUnk_1a0 = p->mUnk_17c;
        }
        p->mUnk_17c += p->mUnk_19c;
        p->mUnk_170 += p->mUnk_17c;
        func_02101964(p, 1);
        if (p->mUnk_19c >= 0 && p->mUnk_17c >= p->mUnk_1a0) {
            return;
        }
        p->mUnk_130--;
        if (p->mUnk_19c >= 0) {
            return;
        }
        if (p->mUnk_17c < -0xc00) {
            p->mUnk_19c = 0x133;
            return;
        }
        if (p->mUnk_17c <= 0) {
            return;
        }
        if (p->mUnk_17c >= -p->mUnk_19c) {
            return;
        }
        func_020f8e3c((unsigned int) p->mUnk_168, 0xf5);
    } else {
        p->mUnk_16c += p->mUnk_178;
        p->mUnk_174 += p->mUnk_180;
        func_02101618(p, 1, (p->mUnk_74 & 0x8000000) ? 4 : 5);
        if (!(p->mUnk_74 & 0x8000000)) {
            return;
        }
        if (p->mUnk_24c != 0) {
            return;
        }
        if (p->mUnk_144 != 0) {
            return;
        }
        if (p->mUnk_264 == 0xffffffff) {
            return;
        }
        if (p->mUnk_264 - 2 <= 1) {
            p->mUnk_144 = 1;
            p->mUnk_264 = -1;
        }
    }
}

void func_02100bc8(Unk020f41c4_A *p) {
    p->mUnk_268 = ((p->mUnk_74 & 0x10000000) ? 0xf : 0) - p->mUnk_268;
    p->mUnk_24c = 0;
}

void func_02100b84(Unk020f41c4_A *p) {
    p->mUnk_268--;
    if (p->mUnk_268 >= 0) {
        return;
    }
    p->mUnk_24c = (p->mUnk_74 & 0x10000000) == 0;
    p->mUnk_13c = 5;
    p->mUnk_13e = 1;
}
