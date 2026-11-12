#include "stream.h"
#include "snd_interface.h"
#include "snd_command.h"
#include "pm.h"
#include "code_0212d214.h"
#include "code_020172d0.h"
#include "resource_mgr.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "code_020218f4.h"

NNSFndList sStrmList;
NNSSndStrmChannel sStrmChannel[16];

// Unlocks the channels of the stream.
void NNS_SndStrmFreeChannel(NNSSndStrm *stream) {
    if (stream->mChBitMask == 0) {
        return;
    }
    NNS_SndUnlockChannel(stream->mChBitMask);
    stream->mChBitMask = 0;
    stream->mNumChannels = 0;
}

// Starts the timers of the stream and, on the first start, adds its sleep callbacks.
void NNS_SndStrmStart(NNSSndStrm *stream) {
    SND_StartTimer(stream->mChBitMask, 0, 1 << stream->mAlarmNo, 0);
    if (stream->mStartFlag) {
        return;
    }
    PM_PrependPreSleepCallback(&stream->mPreSleepInfo);
    PM_AppendPostSleepCallback(&stream->mPostSleepInfo);
    stream->mStartFlag = 1;
}

// Stops the stream when it is set up.
void NNS_SndStrmStop(NNSSndStrm *stream) {
    if (stream->mActiveFlag) {
        ForceStopStrm(stream);
    }
}

// Sets NNSSndStrm.mVolume and the volume of every channel of the stream, added to the volume of the channel.
void NNS_SndStrmSetVolume(NNSSndStrm *stream, s32 volume) {
    u32 channel;
    s32 channelIndex;
    s32 level;

    stream->mVolume = volume;
    for (channelIndex = 0; channelIndex < stream->mNumChannels; channelIndex++) {
        channel = stream->mChannelNo[channelIndex];
        level = SND_CalcChannelVolume(stream->mVolume + sStrmChannel[channel].mVolume);
        SND_SetChannelVolume(1 << channel, level & 0xff, level >> 8);
    }
}

// Stops the timers and the sleep callbacks of a started stream, waits for the sound commands, and shuts it down.
void ForceStopStrm(NNSSndStrm *stream) {
    u32 tag;

    if (stream->mStartFlag) {
        SND_StopTimer(stream->mChBitMask, 0, 1 << stream->mAlarmNo, 0);
        PM_DeletePreSleepCallback(&stream->mPreSleepInfo);
        PM_DeletePostSleepCallback(&stream->mPostSleepInfo);
        stream->mStartFlag = 0;
        tag = SND_GetCurrentCommandTag();
        SND_FlushCommand(1);
        SND_WaitForCommandProc(tag);
    }
    ShutdownStrm(stream);
}

// Frees the alarm of the stream, removes it from the stream list and marks it not set up.
void ShutdownStrm(NNSSndStrm *stream) {
    NNS_SndFreeAlarm(stream->mAlarmNo);
    NNS_FndRemoveListObject(&sStrmList, stream);
    stream->mActiveFlag = 0;
}
