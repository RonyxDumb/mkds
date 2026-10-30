#include "00/code_02193eac.h"
#include "00/code_02193818.h"
#include "00/code_02193f18.h"
#include "00/code_0218d000.h"
#include "00/code_021a3690.h"
#include "code_02134d30.h"

Unk02193f2cNode *func_ov000_02193eac(Unk0218f960 *param_1, u32 param_2, u32 param_3) {
    Unk0218f960_00 *a = param_1->mUnk_00;
    Unk02193f2cNode *b = func_ov000_021a3690(0x40);

    if (b == 0) {
        return 0;
    }
    func_02134de0(b, 0, 0x40);
    b->mUnk_00 = 0x64;
    b->mUnk_04 = param_3;
    b->mUnk_08 = -1;
    b->mUnk_0c = param_2;
    b->mUnk_10 = func_ov000_0218e320(0) + 0x12c;
    b->mNext = a->mUnk_434;
    b->mUnk_38 = (void *) func_ov000_0218dc94(0x18, 0, (unsigned int) func_ov000_02193f18);
    a->mUnk_434 = b;
    return b;
}
