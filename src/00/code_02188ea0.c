#include "00/code_02188ea0.h"
#include "00/code_02188ec0.h"

u32 GetAuthMode(ACWORK *work) {
    if (work->mUnk_d0b_2 == 1) {
        return 0xc0000;
    }
    return 0x80000;
}
