#include "03/code_021ccbbc.h"
#include "03/code_021cca74.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"

void func_ov003_021ccbbc(void) {
    u16 a[2];
    u32 b;
    s32 c;
    s32 d;
    func_ov003_021d2940(a);
    b = data_ov003_021d6630[(*(Unk021cca74 **) data_ov003_021da268)->mUnk_1b];
    c = a[1] - (*(Unk021cca74 **) data_ov003_021da268)->mY - (b >> 1);
    if (c < 0) {
        c = 0;
    } else {
        d = (*(Unk021cca74 **) data_ov003_021da268)->mUnk_19 - b;
        if (c >= d) {
            c = d;
        }
    }
    func_ov003_021cca74(c);
    (*(Unk021cca74 **) data_ov003_021da268)->mUnk_1d = 3;
}
