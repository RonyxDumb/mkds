#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0204a904.h"
#include "Main/Unknown/code_0204a978.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"

void StartRaceInput(void) {
    u32 entryIndex;
    SetReadRaceKeys(1);
    for (entryIndex = 0; entryIndex < gRaceSetup->mKartCount; entryIndex = (u16) (entryIndex + 1)) {
        InputSlot *inputSlot = &data_02175628[gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex];
        if (inputSlot->mSourceKind != 1) {
            if (inputSlot->mSourceKind == 2) {
                StartKeyRecording(&inputSlot->mUnk_28);
            }
        } else {
            StartReadingKeyRecording(&inputSlot->mUnk_28);
        }
    }
}

void GetRaceClockTime(u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    MinuteSecondMillisecondTime *clockTime;

    clockTime = &gRaceProgress->mUnk_000[0].mUnk_08_view;
    *outMinute = clockTime->mMinute;
    *outSecond = clockTime->mSecond;
    *outMillisecond = clockTime->mMillisecond;
}

u32 GetKartRank(u32 kartIndex) {
    if (gRaceSetup->mMode == 5) {
        return gWiFiRaceSync->mEntries[gParticipantKartMap->mParticipantOfKart[kartIndex & 0xff]].mRank;
    }
    return gRaceProgress->mKarts[kartIndex].mRank;
}
