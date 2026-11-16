#include "code_020204c0.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0214d000.h"

s32 func_020204c0(ScanBlockView *a) {
    // volatile only so that v1[0] is read again for the second compare, as in the original
    volatile u16 v1[4];

    if (a == 0) {
        return 0;
    }
    if (a->field3C == 0) {
        return 0;
    }
    MI_CpuCopy8(&a->field50, v1, 8);
    DC_StoreRange(v1, 8);
    if (a->field44 == 0) {
        if (v1[0] == 0x2348 || v1[0] == 0xbd8a) {
            if (v1[3] == 4) {
                return 1;
            }
        }
    }
    return 0;
}
