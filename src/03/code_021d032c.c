#include "03/code_021d032c.h"
#include "code_02142eac.h"
#include "03/code_021d02e8.h"
#include "03/code_021d079c.h"
#include "03/code_021d07b0.h"

s32 func_ov003_021d032c(void) {
    s32 result;
    func_ov003_021d07b0(3);
    result = func_02143fbc(func_ov003_021d02e8);
    if (result != 2) {
        func_ov003_021d079c(result);
        return 0;
    }
    return 1;
}
