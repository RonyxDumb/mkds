#include "00/Lib/DWC/code_02188ea0.h"
#include "00/Lib/DWC/code_02188ec0.h"

u32 GetAuthMode(ACWORK *work) {
    if (work->mAuthMode == 1) {
        return 0xc0000;
    }
    return 0x80000;
}
