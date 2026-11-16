#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0204a904.h"
#include "Main/Unknown/code_0204a978.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"

void rstat_initInputRecorders(void) {
    u32 entryIndex;
    input_setFlagsBit1(1);
    for (entryIndex = 0; entryIndex < gRaceMultiConfig->mKartCount; entryIndex = (u16) (entryIndex + 1)) {
        InputSlot *inputSlot = &gInputUnits[gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mIndex];
        if (inputSlot->mSourceKind != 1) {
            if (inputSlot->mSourceKind == 2) {
                irec_startRecording((KeyRecording *) &inputSlot->mUnk_28);
            }
        } else {
            irec_startPlayback((KeyRecording *) &inputSlot->mUnk_28);
        }
    }
}

void rstat_getLapTime(u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    Unk0217aa1c_144_00 *clockTime;

    clockTime = &gRaceStatus->mUnk_000[0].mUnk_08_view;
    *outMinute = clockTime->mUnk_02;
    *outSecond = clockTime->mUnk_03;
    *outMillisecond = clockTime->mUnk_00;
}

u32 rstat_getPlace(u32 kartIndex) {
    if (gRaceMultiConfig->mMode == 5) {
        return gStruct217AA14->mUnk_104[gStruct217AA18->mParticipantOfKart[kartIndex & 0xff]].mRank;
    }
    return gRaceStatus->mKarts[kartIndex].mRank;
}
