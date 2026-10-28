#include "03/code_021d022c.h"
#include "code_02142eac.h"
#include "03/code_021d0200.h"
#include "03/code_021d079c.h"
#include "03/code_021d07b0.h"

s32 func_ov003_021d022c(void) {
    s32 result;
    func_ov003_021d07b0(3);
    result = func_02143fbc(func_ov003_021d0200);
    if (result != 2) {
        func_ov003_021d079c(result);
        return 0;
    }
    return 1;
}
