#include "03/code_021cd118.h"
#include "03/code_021cce78.h"
#include "code_02142eac.h"

u32 func_ov003_021cd118(void) {
    data_ov003_021da26c->mUnk_1e48 = 1;
    func_02143520(&data_ov003_021da26c->mUnk_168c);
    if (data_ov003_021da26c->mUnk_168c.mUnk_00 != 2) {
        if (func_02143dd0(func_ov003_021cd080) != 2) {
            return 0;
        }
        do {
            func_02143520(&data_ov003_021da26c->mUnk_168c);
        } while (data_ov003_021da26c->mUnk_168c.mUnk_00 != 2);
    }
    if (func_02143d88(func_ov003_021cd080) != 2) {
        return 0;
    }
    return 1;
}
