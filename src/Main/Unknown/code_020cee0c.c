#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/code_02094e1c.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020ceeec.h"
#include "Main/Unknown/code_02095000.h"
#include "Main/Unknown/code_02133000.h"

#pragma optimize_for_size on

#pragma thumb on
void FillShuffledIndices(void) {
    s32 remaining[8];
    s32 remainingCount;
    s32 i;
    s32 pickIndex;
    s32 k;
    RandomState64 *random;

    remainingCount = 8;
    if (gMenuShared->mIndicesShuffled == 0) {
        if (ShuffledIndicesGetConnectionKind() == 1 || ShuffledIndicesGetConnectionKind() == 2) {
            random = ShuffledIndicesGetConnectionWorkRandomState();
            for (i = 0; i < 8; i++) {
                remaining[i] = i;
            }
            for (i = 0; i < 8; i++) {
                pickIndex = (NextRandomU16(random) >> 8) % remainingCount;
                gMenuShared->mShuffledIndices[i] = remaining[pickIndex];
                remainingCount--;
                for (k = pickIndex; k < remainingCount; k++) {
                    remaining[k] = remaining[k + 1];
                }
            }
            gMenuShared->mIndicesShuffled = 1;
        }
    }
}

void ClearShuffledIndices(void) {
    s32 i;
    BOOL clearValue;

    clearValue = FALSE;
    for (i = 0; i < 8; i++) {
        gMenuShared->mShuffledIndices[i] = clearValue;
    }
    gMenuShared->mIndicesShuffled = clearValue;
}
#pragma thumb off

BOOL CreateRaceHudSubScreenPakkunSpitCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenPakkunSpitCells, 0x1ab);
}
