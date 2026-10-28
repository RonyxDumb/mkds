#include "03/code_021d02c0.h"
#include "code_02142eac.h"
#include "03/code_021d02a0.h"
#include "03/code_021d079c.h"
#include "03/code_021d07b0.h"

s32 func_ov003_021d02c0(void) {
    s32 result = func_02143b7c(func_ov003_021d02a0);
    if (result != 2) {
        func_ov003_021d079c(result);
        return 0;
    }
    return 1;
}
