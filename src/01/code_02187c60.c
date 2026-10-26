#include "01/code_02187c60.h"
#include "01/code_02187d14.h"
#include "01/code_0218d520.h"
#include "code_020109c4.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_02147000.h"

void func_ov001_02187c88(Unk02188950 *param_1, s32 param_2, const Vec3 *param_3) {
    param_1->mUnk_2e4 = param_2;
    param_1->mUnk_2f4 = *param_3;
    param_1->mUnk_304->mUnk_10->mUnk_2c = param_1;
    func_020109c4((void *) param_1->mUnk_304->mUnk_10, (void (*)(void *)) func_ov001_02187d14, (u32) (0), (u8) (6),
                  (u8) (3));
}

void func_ov001_02187c60(Unk02188950 *param_1, void *param_2) {
    if (param_1->mUnk_300 != 0) {
        func_020fd494(&param_1->mUnk_300);
    }
    param_1->mUnk_300 = param_2;
}
