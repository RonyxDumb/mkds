#include "Main/Unknown/code_020646c0.h"
#include "Main/Unknown/code_0203be88.h"
#include "ITCM/code_01ffba68.h"

void func_020646c0(Kart *kart) {
    if (driver_getCheckMissionEndArea() != 0) {
        rstat_handleMissionEndAreas(&kart->mPos, kart->mIndex);
    }
    driver_1FFCC50(kart);
}
