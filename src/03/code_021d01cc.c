#include "03/code_021d01cc.h"
#include "03/code_021cfb80.h"
#include "03/code_021d01ac.h"
#include "03/code_021d079c.h"
#include "03/code_021d07b0.h"
#include "code_02142eac.h"

s32 func_ov003_021d01cc(void) {
    s32 r;

    func_ov003_021d07b0(3);
    r = func_021436d0(func_ov003_021d01ac, 0);
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021cfb80();
        return 0;
    }
    return 1;
}
