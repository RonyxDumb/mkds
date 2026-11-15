#include "00/Lib/DWC/access_point_auth_mode.h"
#include "00/Lib/DWC/access_point_power_mode.h"

u32 GetAuthMode(ACWORK *work) {
    if (work->mAuthMode == 1) {
        return 0xc0000;
    }
    return 0x80000;
}
