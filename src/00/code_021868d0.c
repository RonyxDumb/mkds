#include "00/code_021868d0.h"
#include "code_02139f70.h"

s32 func_ov000_021868d0(Unk021868d0 *a, const u8 *b) {
    u8 *p;
    if (func_0213a434(b) >= 0x80) {
        return 0;
    }
    func_0213a228(a->mUnk_028, b, 0x80);
    if (func_0213a434(b) != func_0213a434(a->mUnk_028)) {
        return 0;
    }
    p = (u8 *) func_02139f70(a->mUnk_028, data_ov000_021b1268);
    if (p != 0) {
        a->mUnk_0a8 = a->mUnk_028 + 7;
        a->mUnk_0b0 = 0;
    } else {
        p = (u8 *) func_02139f70(a->mUnk_028, data_ov000_021b1270);
        if (p == 0) {
            return 0;
        }
        a->mUnk_0a8 = p + 8;
        a->mUnk_0b0 = 1;
    }
    p = (u8 *) func_02139f70(a->mUnk_0a8, data_ov000_021b127c);
    if (p == 0) {
        a->mUnk_0ac = 0;
    } else {
        *p = 0;
        a->mUnk_0ac = p + 1;
    }
    return 1;
}
