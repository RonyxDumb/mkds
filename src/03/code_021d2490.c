#include "03/code_021d2490.h"
#include "03/code_021bf620.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1d60.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_02022aa8.h"

void func_ov003_021d2490(void) {
    Unk021d2490 *a = func_ov003_021d285c(0x798, 4);
    u32 *b;
    s32 i;

    *(Unk021d2490 **) data_ov003_021da2c4 = a;
    (*(Unk021d2490 **) data_ov003_021da2c4)->mUnk_788 = func_ov003_021d1d60(0x20, a->mUnk_018, 0x38);
    b = 0;
    for (i = 0; i < 2; i++) {
        (*(Unk021d2490 **) data_ov003_021da2c4)->mUnk_78c[i] = func_ov003_021d14b8(data_ov003_021d7c0c[i], b, 4);
        func_02022d44(&(*(Unk021d2490 **) data_ov003_021da2c4)->mUnk_000[i],
                      (*(Unk021d2490 **) data_ov003_021da2c4)->mUnk_78c[i]);
    }
}
