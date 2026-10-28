#include "00/code_02180608.h"
#include "00/code_021806ec.h"
#include "00/code_02182fdc.h"

s32 func_ov000_02180608(void) {
    s32 valid = 1;
    if (data_ov000_021b4c64 != 0 && data_ov000_021b4c64->mUnk_08 == 0) {
        valid = 0;
    }
    if (data_0217d384->mUnk_0008.mUnk_0e == 0 && valid != 0) {
        return 1;
    }
    return 0;
}
