#include "03/code_021d0180.h"
#include "code_02142eac.h"
#include "03/code_021d0158.h"
#include "03/code_021d079c.h"
#include "03/code_021d07b0.h"

s32 func_ov003_021d0180(void) {
    s32 result;
    func_ov003_021d07b0(3);
    result = func_02143dd0(func_ov003_021d0158);
    if (result != 2) {
        func_ov003_021d079c(result);
        return 0;
    }
    return 1;
}
