#include "03/code_021cb580.h"
#include "03/code_021bf31c.h"
#include "03/code_021bf698.h"
#include "03/code_021c209c.h"
#include "03/code_021cb11c.h"
#include "03/code_021d2a34.h"
#include "03/code_021d2acc.h"

void func_ov003_021cb580(void) {
    u32 i;
    for (i = 0; i < 4; i++) {
        if (func_ov003_021d2a34(&data_ov003_021d65a0[func_ov003_021c20a8(1)][i]) != 0) {
            func_ov003_021bf31c(1);
            data_ov003_021da23c = i;
            func_ov003_021bf6c8(data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_00,
                                data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_04,
                                data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_02,
                                data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_06);
            return;
        }
    }
    if (func_ov003_021d2b04(1) != 0) {
        func_ov003_021bf31c(1);
    } else if (func_ov003_021d2b04(2) != 0) {
        func_ov003_021bf31c(0);
    } else if (func_ov003_021d2ae8(0x40) != 0) {
        func_ov003_021cb320(1);
    } else if (func_ov003_021d2ae8(0x80) != 0) {
        func_ov003_021cb320(3);
    } else if (func_ov003_021d2ae8(0x20) != 0) {
        func_ov003_021cb320(0);
    } else if (func_ov003_021d2ae8(0x10) != 0) {
        func_ov003_021cb320(2);
    }
}
