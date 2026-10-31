#include "03/code_021c6acc.h"
#include "03/code_021c0ca8.h"
#include "03/code_021c20dc.h"
#include "03/code_021c2120.h"
#include "03/code_021c6708.h"
#include "03/code_021c6764.h"
#include "03/code_021c6a18.h"
#include "03/code_021ce000.h"
#include "03/unk_021da000.h"

void func_ov003_021c6acc(void) {
    s32 a[2] = {0x9b, 0x9c};
    s32 b;
    if (func_ov003_021c0ca8() == 0) {
        if (data_ov003_021da1f8->mUnk_2a == 0) {
            func_ov003_021c212c(func_ov003_021c6a18);
        } else if (data_ov003_021da1f8->mUnk_2a == 2) {
            func_ov003_021cefc0(0x2f, 3, 1, -1, 0);
            func_ov003_021c212c(func_ov003_021c673c);
        } else {
            func_ov003_021c20dc(0, &b);
            func_ov003_021cefc0(a[b], 2, 1, -1, 0);
            func_ov003_021c212c(func_ov003_021c68c8);
        }
    }
}
