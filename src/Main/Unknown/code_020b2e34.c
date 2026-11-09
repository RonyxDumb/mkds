#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/code_020b2000.h"
#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b2ecc.h"

#pragma thumb on

void SetChoisesSOpenDuringRace(u32 openFlag) {
    int wasOpen;
    int v2;
    wasOpen = GetChoisesSOpenDuringRace();
    v2 = IsChoisesSOpenAllowedDuringRace();
    if (v2 != 0) {
        SetChoisesSOpen(openFlag);
    }
    v2 = GetChoisesSOpenDuringRace();
    if ((wasOpen == 0) && (v2 != 0)) {
        LowerSndHandleVolumes();
    }
}

u32 GetChoisesSPrevOpenDuringRace(void) {
    return (gChoisesS->mPrevOpenDuringRace);
}

int GetChoisesSPickedValue(void) {
    int courseCountReached;
    int pickedValue;
    pickedValue = gChoisesS->mPickedValue;
    if ((pickedValue == 2) && (courseCountReached = func_020c3db4(), courseCountReached != 0)) {
        pickedValue = 7;
    }
    return pickedValue;
}

#pragma thumb off
