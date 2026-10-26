#include "01/code_02193944.h"
#include "01/code_02195000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"

void func_ov001_02193944(void) {
    s32 amount;
    s32 i;
    s32 j;

    data_ov001_021a9bd4->mUnk_0c++;
    amount = func_020ae4c0(1, 250, 0, data_ov001_021a9bd4->mUnk_0c, 10);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a65e4[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bd4->mUnk_20[data_ov001_021a65f0[i][j]].mUnk_04 = amount;
            } else {
                data_ov001_021a9bd4->mUnk_20[data_ov001_021a65f0[i][j]].mUnk_04 = -amount;
            }
        }
    }
    if (func_ov001_02192e94() == 1 && data_ov001_021a9bd4->mUnk_08 != 2) {
        data_ov001_021a9bd4->mUnk_18 = func_020ae4c0(1, 50, 0, data_ov001_021a9bd4->mUnk_0c, 10);
    }
    if (data_ov001_021a9bd4->mUnk_0c >= 10) {
        data_ov001_021a9bd4->mUnk_04 = 2;
        data_ov001_021a9bd4->mUnk_0c = 0;
        func_02128374();
    }
}
