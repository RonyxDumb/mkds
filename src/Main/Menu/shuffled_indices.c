#include "Main/Menu/shuffled_indices.h"
#include "Main/Unknown/code_020ceeec.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/MapObjects/teresa_spawner.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_02095000.h"
#include "Main/Unknown/code_02133000.h"

u32 ShuffledIndicesGetConnectionKind(void) {
    return (gStartupWork->mConnectionKind);
}

RandomState64 *ShuffledIndicesGetConnectionWorkRandomState(void) {
    return &gConnectionWork->mRandomState;
}

#pragma optimize_for_size on

#pragma thumb on
void FillShuffledIndices(void) {
    s32 remaining[8];
    s32 remainingCount;
    s32 index;
    s32 pickIndex;
    s32 shiftIndex;
    RandomState64 *random;

    remainingCount = 8;
    if (gMenuShared->mIndicesShuffled == 0) {
        if (ShuffledIndicesGetConnectionKind() == 1 || ShuffledIndicesGetConnectionKind() == 2) {
            random = ShuffledIndicesGetConnectionWorkRandomState();
            for (index = 0; index < 8; index++) {
                remaining[index] = index;
            }
            for (index = 0; index < 8; index++) {
                pickIndex = (NextRandomU16(random) >> 8) % remainingCount;
                gMenuShared->mShuffledIndices[index] = remaining[pickIndex];
                remainingCount--;
                for (shiftIndex = pickIndex; shiftIndex < remainingCount; shiftIndex++) {
                    remaining[shiftIndex] = remaining[shiftIndex + 1];
                }
            }
            gMenuShared->mIndicesShuffled = 1;
        }
    }
}

void ClearShuffledIndices(void) {
    s32 index;
    BOOL clearValue;

    clearValue = FALSE;
    for (index = 0; index < 8; index++) {
        gMenuShared->mShuffledIndices[index] = clearValue;
    }
    gMenuShared->mIndicesShuffled = clearValue;
}
#pragma thumb off

BOOL CreateRaceHudSubScreenPakkunSpitCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenPakkunSpitCells, 0x1ab);
}
