#include "Main/Unknown/code_020cb4c0.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cb600.h"
#include "Main/Unknown/code_020cb618.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02054000.h"

#pragma thumb on
#pragma optimize_for_size on
// non-matching: at both indirect calls the original loads `ldr r1, [r2, #12]` before `adds r0, r4, #0`; the compiled code
// emits `adds r0, r4, #0` first (3 words, offsets 0x82/0x84 and 0x90/0x92).
void func_020cb51c(u32 a) {
    Unk0217b43c *p;

    if (func_02049b6c() == 0) {
        if (func_020cae54() == 1 || func_020cae54() == 2) {
            if (data_0217b43c->mUnk_958 == 0) {
                if (func_020546d8() != 1) {
                    return;
                }
                data_0217b43c->mUnk_958 = 1;
            }
            if (data_0217b43c->mUnk_95c == 0) {
                if (func_02054754() != 1) {
                    return;
                }
                data_0217b43c->mUnk_95c = 1;
            }
        }
        func_020ae6ac(data_0217b43c->mUnk_108, data_0217b43c->mUnk_50c);
        if (data_0217b43c->mUnk_104 != 0) {
            data_0217b43c->mUnk_104 = 0;
            func_020cb6c0();
            p = data_0217b43c;
            p->mUnk_014[p->mUnk_00c].mUnk_04(a);
        } else {
            p = data_0217b43c;
            p->mUnk_014[p->mUnk_00c].mUnk_04(a);
            if (data_0217b43c->mUnk_004 != 0) {
                func_020cb618();
                func_020cb6c0();
            }
        }
        func_02125928();
        func_0212a920();
        if (func_02036c5c() != 0) {
            func_020cb600(&data_0217b43c->mUnk_000);
        }
    }
}

void func_020cb4c0(void) {
    if (func_02049b6c() == 0) {
        if (func_020cae54() == 1 || func_020cae54() == 2) {
            if (data_0217b43c->mUnk_958 == 0 || data_0217b43c->mUnk_95c == 0) {
                return;
            }
        }
        func_020ae630(data_0217b43c->mUnk_108, data_0217b43c->mUnk_50c);
    }
}
