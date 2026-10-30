#include "00/code_0218d430.h"

s32 func_ov000_0218d430(u32 *param_1, u32 *param_2) {
    u8 *a;
    u8 *b;
    s32 result;
    a = func_ov000_0218b30c((Unk0218af28 *) *param_1, (const u8 *) data_ov000_021b4d24->mUnk_498, data_ov000_021b2260);
    b = func_ov000_0218b30c((Unk0218af28 *) *param_2, (const u8 *) data_ov000_021b4d24->mUnk_498, data_ov000_021b2260);
    result = func_0213a074(a, b);
    if (data_ov000_021b4d24->mUnk_49c == 0) {
        result = -result;
    }
    return result;
}
