#include "Main/Unknown/code_02116084.h"
#include "Main/Unknown/code_02114158.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/code_02116870.h"

#pragma thumb on

const u16 data_0215c4ac[2] = {0x1e, 0x1f};

void AdvanceRecordVSEraseOffsetTimers(void) {
    s32 firstRecordIndex;
    BOOL hiddenA;
    BOOL hiddenB;
    s32 timerIndex;

    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    gRecordVSErase->mRecordVSSEraseTable[data_0215c4a8[0]].mOffsetX =
        -LookupFrameOffset(6 - gRecordVSErase->mOffsetTimers[0]);
    gRecordVSErase->mRecordVSSEraseTable[data_0215c4a8[1]].mOffsetX =
        LookupFrameOffset(6 - gRecordVSErase->mOffsetTimers[1]);
    hiddenA = FALSE;
    hiddenB = FALSE;
    for (timerIndex = 0; timerIndex < 2; timerIndex++) {
        if (gRecordVSErase->mOffsetTimers[timerIndex] > 0) {
            gRecordVSErase->mOffsetTimers[timerIndex]--;
            gRecordVSErase->mRecordVSSEraseTable[data_0215c4ac[timerIndex]].mVisible = hiddenA;
            gRecordVSErase->mRecordVSSEraseTable[data_0215c4a8[timerIndex]].mVisible = 1;
        } else {
            gRecordVSErase->mRecordVSSEraseTable[data_0215c4ac[timerIndex]].mVisible = 1;
            gRecordVSErase->mRecordVSSEraseTable[data_0215c4a8[timerIndex]].mVisible = hiddenB;
        }
    }
    if (firstRecordIndex == 0) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4ac[0]].mVisible = 0;
    }
    if (firstRecordIndex + 5 >= GetRecordCount()) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4ac[1]].mVisible = 0;
    }
}

#pragma thumb off
