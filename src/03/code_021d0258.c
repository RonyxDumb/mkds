#include "03/code_021d0258.h"
#include "03/code_021d079c.h"
#include "03/code_021d07b0.h"
#include "03/unk_021da000.h"
#include "code_021445e0.h"

s32 func_ov003_021d0258(void) {
    s32 r;

    if (data_ov003_021da2a8->mUnk_40 != 6) {
        return 0;
    }
    func_ov003_021d07b0(3);
    r = func_021453b4(&data_ov003_021da2a8->mUnk_1e00);
    if (r != 2) {
        func_ov003_021d079c(r);
        return 0;
    }
    return 1;
}
