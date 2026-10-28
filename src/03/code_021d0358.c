#include "03/code_021d0358.h"
#include "code_021445e0.h"
#include "03/code_021d079c.h"

s32 func_ov003_021d0358(void) {
    s32 result = func_021453b4((Unk021450ec *) ((u8 *) data_ov003_021da2a8 + 0x1e00));
    if (result != 2) {
        func_ov003_021d079c(result);
        return 0;
    }
    return 1;
}
