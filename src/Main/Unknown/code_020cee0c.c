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
    if (gStruct217B488->mIndicesShuffled == 0) {
        if (func_020cef08() == 1 || func_020cef08() == 2) {
            random = func_020ceeec();
            for (i = 0; i < 8; i++) {
                remaining[i] = i;
            }
            for (i = 0; i < 8; i++) {
                pickIndex = (func_020951b4(random) >> 8) % remainingCount;
                gStruct217B488->mShuffledIndices[i] = remaining[pickIndex];
                remainingCount--;
                for (k = pickIndex; k < remainingCount; k++) {
                    remaining[k] = remaining[k + 1];
                }
            }
            gStruct217B488->mIndicesShuffled = 1;
        }
    }
}

void ClearShuffledIndices(void) {
    s32 i;
    BOOL v;

    v = FALSE;
    for (i = 0; i < 8; i++) {
        gStruct217B488->mShuffledIndices[i] = v;
    }
    gStruct217B488->mIndicesShuffled = v;
}
#pragma thumb off

BOOL mpicn_createPakkunFireIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sPakkunFireIcon, 0x1ab);
}
