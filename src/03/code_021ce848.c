#include "03/code_021ce848.h"
#include "03/code_021d27d8.h"
#include "03/code_021d34c0.h"
#include "code_02142eac.h"

// non-matching: the pointer to the byte in the wait loop is built in r1 (adds r1, r1, r0) instead of r0, one register swap,
// same size
u32 func_ov003_021ce848(void) {
    Unk021da280 *d;
    vu8 *q;

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
    q = &d->mUnk_1b80;
    while (*q != 2) {
    }
    func_ov003_021d2808(&data_ov003_021da280);
    return 1;
}
