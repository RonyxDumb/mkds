#include "Main/Unknown/code_020b1cdc.h"
#include "Main/Unknown/unk_0217b000.h"

void SetRaceHudKartRemoved(u32 kartIndex, u32 removed) {
    gRaceHud->mKartRemoved[kartIndex] = removed;
}
