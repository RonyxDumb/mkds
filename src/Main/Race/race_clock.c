#include "Main/Race/race_clock.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Race/race_keys.h"
#include "Main/System/key_recording_read.h"
#include "Main/System/key_recording_start.h"
#include "Main/System/input_slots.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

void StartRaceClock(void) {
    g_GlobalMV->mHeader.mClockEnabled = 1;
}

void StartRaceInput(void) {
    u32 entryIndex;
    Struct5624_SetXflag2(1);
    for (entryIndex = 0; entryIndex < g_GlobalCO->mKartCount; entryIndex = (u16) (entryIndex + 1)) {
        InputSlot *inputSlot = &g_GlobalCYT[g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mIndex];
        if (inputSlot->mSourceKind != INPUT_SOURCE_KEY_RECORDING_PLAYBACK) {
            if (inputSlot->mSourceKind == INPUT_SOURCE_PAD_RECORDED) {
                StartKeyRecording(&inputSlot->mKeyRecording);
            }
        } else {
            StartReadingKeyRecording(&inputSlot->mKeyRecording);
        }
    }
}

void GetSomeMVTime(u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    MinuteSecondMillisecondTime *clockTime;

    clockTime = &g_GlobalMV->mHeader.mClockTime;
    *outMinute = clockTime->mMinute;
    *outSecond = clockTime->mSecond;
    *outMillisecond = clockTime->mMillisecond;
}

u32 GetSomeRacerFlags(u32 kartIndex) {
    if (g_GlobalCO->mMode == MODE_WIFI) {
        return g_GlobalAA->mEntries[g_GlobalRE->mParticipantOfKart[kartIndex & 0xff]].mRank;
    }
    return g_GlobalMV->mKarts[kartIndex].mRank;
}
