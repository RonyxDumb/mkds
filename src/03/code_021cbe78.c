#include "03/code_021cbe78.h"
#include "03/code_021c20dc.h"
#include "03/code_021c2120.h"
#include "03/code_021cbd40.h"
#include "03/code_021ce000.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"

void func_ov003_021cbe78(void) {
    Unk021d7708 a = data_ov003_021d7708;
    s32 b;
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        func_ov003_021c20dc(0, &b);
        func_ov003_021cefc0(a.mUnk_00[b], 1, 1, -1, 0);
        func_ov003_021c212c(func_ov003_021cbe44);
    }
}
