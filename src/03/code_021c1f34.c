#include "03/code_021c1f34.h"
#include "03/code_021b94b8.h"
#include "03/unk_021da000.h"

u32 func_ov003_021c1f34(void) {
    u8 a;
    if (func_ov003_021ba05c(*(Unk021b94c4 **) data_ov003_021da168) == 0) {
        data_ov003_021da164[0] = 1;
        return 1;
    }
    a = (*(Unk021b94c4 **) data_ov003_021da168)->mUnk_116;
    if (a == 1 || (u8) (a + 253) <= 2) {
        return 0;
    }
    return 2;
}
