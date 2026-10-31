#include "03/code_021ce848.h"
#include "03/code_021d27d8.h"
#include "03/code_021d34c0.h"
#include "code_02142eac.h"

u32 func_ov003_021ce848(void) {
    Unk021da280 *d;

    data_ov003_021da280->mUnk_1b80 = 1;
    func_02143520(&data_ov003_021da280->mUnk_13b8);
    if (data_ov003_021da280->mUnk_13b8.mUnk_000 != 2) {
        if (func_02143dd0(func_ov003_021ce7c0) != 2) {
            return 0;
        }
        do {
            func_02143520(&data_ov003_021da280->mUnk_13b8);
        } while (data_ov003_021da280->mUnk_13b8.mUnk_000 != 2);
    }
    if (func_02143d88(func_ov003_021ce7c0) != 2) {
        return 0;
    }
    d = data_ov003_021da280;
    if (d->mUnk_1b7c != 0) {
        func_ov003_021d34c0(0, d->mUnk_1b7c);
    }
    d = data_ov003_021da280;
    while (*(vu8 *) &d->mUnk_1b80 != 2) {
    }
    func_ov003_021d2808(&data_ov003_021da280);
    return 1;
}
