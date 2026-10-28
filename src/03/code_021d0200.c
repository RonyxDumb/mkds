#include "03/code_021d0200.h"
#include "03/code_021d079c.h"
#include "03/code_021d07b0.h"
#include "03/code_021cfaa8.h"
#include "03/code_021d01cc.h"

void func_ov003_021d0200(Unk021425e8 *event) {
    if (event->mUnk_02 != 0) {
        func_ov003_021d079c(event->mUnk_02);
        func_ov003_021cfaa8();
    } else {
        if (func_ov003_021d01cc() == 0) {
            func_ov003_021d07b0(9);
        }
    }
}
