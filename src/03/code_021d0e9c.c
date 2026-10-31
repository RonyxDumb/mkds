#include "03/code_021d0e9c.h"
#include "03/code_021d0850.h"
#include "03/unk_021da000.h"

void func_ov003_021d0e9c(u8 *param_1, u8 *param_2) {
    *param_1 = (*(Unk021da2ac **) &data_ov003_021da2ac)->mUnk_a90;
    if ((*(Unk021da2ac **) &data_ov003_021da2ac)->mUnk_a90 != (*(Unk021da2ac **) &data_ov003_021da2ac)->mUnk_a91) {
        *param_2 = 1;
    } else {
        *param_2 = 0;
    }
    (*(Unk021da2ac **) &data_ov003_021da2ac)->mUnk_a91 = (*(Unk021da2ac **) &data_ov003_021da2ac)->mUnk_a90;
}
