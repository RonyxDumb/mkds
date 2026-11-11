#include "00/code_02188ec0.h"

u32 GetPowerMode(ACWORK *work) {
    if (work->mPowerMode == 1) {
        return 0x30000;
    }
    return 0x20000;
}
