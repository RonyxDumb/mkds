#include "Main/Race/race_clock.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Race/race_keys.h"
#include "Main/System/key_recording_read.h"
#include "Main/System/key_recording_start.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

void StartRaceClock(void) {
    gRaceProgress->mHeader.mClockEnabled = 1;
}

void StartRaceInput(void) {
    u32 entryIndex;
    SetReadRaceKeys(1);
    for (entryIndex = 0; entryIndex < gRaceSetup->mKartCount; entryIndex = (u16) (entryIndex + 1)) {
        InputSlot *inputSlot = &gInputSlots[gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex];
        if (inputSlot->mSourceKind != INPUT_SOURCE_KEY_RECORDING_PLAYBACK) {
            if (inputSlot->mSourceKind == INPUT_SOURCE_PAD_RECORDED) {
                StartKeyRecording(&inputSlot->mKeyRecording);
            }
        } else {
            StartReadingKeyRecording(&inputSlot->mKeyRecording);
        }
    }
}

void GetRaceClockTime(u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    MinuteSecondMillisecondTime *clockTime;

    clockTime = &gRaceProgress->mHeader.mClockTime;
    *outMinute = clockTime->mMinute;
    *outSecond = clockTime->mSecond;
    *outMillisecond = clockTime->mMillisecond;
}

u32 GetKartRank(u32 kartIndex) {
    if (gRaceSetup->mMode == MODE_WIFI) {
        return gWiFiRaceSync->mEntries[gParticipantKartMap->mParticipantOfKart[kartIndex & 0xff]].mRank;
    }
    return gRaceProgress->mKarts[kartIndex].mRank;
}
