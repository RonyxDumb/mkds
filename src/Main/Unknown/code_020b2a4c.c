#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "00/code_02181f98.h"

void ChoisesSSetLVselIndex6Requested(u32 value) {
    gMenuShared->mLVselIndex6Requested = value;
}

u32 GetRaceDone(void) {
    return (gRaceProgress->mRaceDone);
}
