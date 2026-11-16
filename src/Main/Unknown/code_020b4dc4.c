#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/code_0207a68c.h"
#include "Main/Unknown/unk_021759c0.h"

u32 m2d_race_getCurrentRaceMode(void) {
    return (gRaceMultiConfig->mMode);
}

u32 sub_20B4DC4(int kartIndex) {
    int currentMode;
    u32 v2;
    currentMode = m2d_race_getCurrentRaceMode();
    if ((currentMode == MODE_TIME_ATTACK) && (kartIndex != 0)) {
        return 1;
    }
    v2 = sub_207A68C(kartIndex);
    return v2;
}
