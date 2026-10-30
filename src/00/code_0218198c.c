#include "00/code_0218198c.h"
#include "00/code_02181e8c.h"
#include "00/code_021806a0.h"
#include "00/code_021806e0.h"
#include "00/code_02181df0.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02175000.h"

extern const u8 data_ov000_021b05d8[3][5];
extern const s32 data_ov000_021b05cc[3];

void func_ov000_0218198c(void) {
    s32 i;
    s32 j;
    s32 v;
    if (func_ov000_021806c4() == -1) {
        if (data_ov000_021b4c6c->mUnk_10 == 10 && func_0211fd68() != 1) {
            func_ov000_021806b8(0);
        } else if (data_ov000_021b4c6c->mUnk_10 == 13) {
            data_021759d0->mUnk_20 = 4;
            func_ov000_021806b8(12);
        }
    }
    data_ov000_021b4c6c->mUnk_0c++;
    v = data_ov000_021b4c6c->mUnk_0c;
    if (v <= 10) {
        v = func_020ae4c0(1, 0xdc, 0, 10 - v, 10);
    } else {
        v = 0xdc;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b05cc[i]; j++) {
            data_ov000_021b4c6c->mUnk_1c[data_ov000_021b05d8[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov000_021b4c6c->mUnk_0c >= 10) {
        if ((data_ov000_021b4c6c->mUnk_10 == 10 || data_ov000_021b4c6c->mUnk_10 == 13) && func_02128274() == 0) {
            return;
        }
        if (func_ov000_021806c4() == -1) {
            if (data_ov000_021b4c6c->mUnk_10 == 8 && func_ov000_02181df0() == 0) {
                data_ov000_021b4c6c->mUnk_04 = 8;
                data_ov000_021b4c6c->mUnk_10 = -1;
                func_021266e4(func_020b3f7c(data_ov000_021b4c6c->mUnk_38, 0x12));
                data_ov000_021b4c6c->mUnk_0c = 0;
                func_021281c8(0xe);
                return;
            }
            func_ov000_021806e0(data_ov000_021b4c6c->mUnk_10);
        }
    }
}
