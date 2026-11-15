#include "00/Lib/DWC/access_point_power_mode.h"

u32 GetPowerMode(ACWORK *work) {
    if (work->mPowerMode == 1) {
        return 0x30000;
    }
    return 0x20000;
}
