#include "sound_capture_effect.h"

#include "arena_cache_init.h"
#include "sound_command_requests.h"
#include "sound_command_queue.h"
#include "thread_mutex_types.h"
#include "thread_scheduler.h"
#include "sound_archive_load.h"
#include "sound_channel_alarm_lock.h"
#include "sound_fader.h"
#include "sound_fader_init.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "00/Lib/DWC/access_point_manager.h"

CaptureParam sCapParam;
OSMessageQueue sMesgQ;
s32 sCurEffectInfo;
EffectInfo sEffectInfoBuffer[8];
u32 sIsThreadCreated;

// Stops any running effect capture, clears the buffer and starts a mixer capture of type 1 with callback called on
// every interval part of the buffer.
s32 NNS_SndCaptureStartEffect(void *buffer, u32 bufSize, u32 format, u32 rate, u32 interval,
                              NNSSndCaptureCallback callback, void *arg) {
    volatile u32 zero;
    u8 *bufferBytes = buffer;

    NNS_SndCaptureStopEffect();
    if (sCapParam.mActiveFlag != 0) {
        return 0;
    }
    zero = 0;
    MIi_CpuClear32(zero, bufferBytes, bufSize);
    DC_FlushRange(bufferBytes, bufSize);
    return NNSi_SndCaptureStart(1, bufferBytes, bufferBytes + (bufSize >> 1), bufSize >> 1, format, 0, 0, 1, rate, 0x7f,
                                0, 0x7f, interval, callback, arg);
}

// Stops the capture when it is a running effect capture.
void NNS_SndCaptureStopEffect(void) {
    if (sCapParam.mActiveFlag == 0) {
        return;
    }
    if (sCapParam.mType != 1) {
        return;
    }
    NNSi_SndCaptureStop();
}

// Clears the thread flag and CaptureParam.mActiveFlag.
void NNSi_SndCaptureInit(void) {
    sIsThreadCreated = 0;
    sCapParam.mActiveFlag = 0;
}

// For a reverb capture steps the fader, stops the capture when the fade out has finished and otherwise sets the
// volume of the playback channels from the fader.
void NNSi_SndCaptureMain(void) {
    CaptureParam *capture = &sCapParam;
    NNSSndFader *levelFader;
    s32 scaledLevel;

    if (capture->mActiveFlag == 0) {
        return;
    }
    if (capture->mType != 0) {
        return;
    }
    levelFader = &capture->mFader;
    NNSi_SndFaderUpdate(levelFader);
    if (capture->mFadeOutFlag != 0 && NNSi_SndFaderIsFinished(levelFader) != 0) {
        NNSi_SndCaptureStop();
        return;
    }
    scaledLevel = NNSi_SndFaderGet(levelFader) >> 8;
    if (scaledLevel == capture->mVolume) {
        return;
    }
    SND_SetChannelVolume(capture->mPlayChBitMask, scaledLevel, 0);
    capture->mVolume = scaledLevel;
}

// Locks two capture units, two channels and, with a callback, an alarm, sets them up on the two buffers and starts
// the timers. Returns 0 when something could not be locked.
s32 NNSi_SndCaptureStart(u32 type, u8 *left, u8 *right, u32 length, u32 format, u32 input, u32 output, u32 loop,
                         s32 rate, u32 volume, u32 panLeft, u32 panRight, u32 parts, NNSSndCaptureCallback callback,
                         void *callbackArg) {
    s32 timerPeriod;
    u32 captureFormat;
    u32 waveFormat;
    u32 playChannels;
    u32 alarmPeriod;
    s32 timerUnits;
    s32 isByteFormat;
    s32 alarm;
    u32 alarmDelay;
    u32 sampleTotal;
    CaptureParam *capture;

    timerUnits = 0;
    playChannels = 0;
    alarm = -1;
    capture = &sCapParam;
    DC_FlushRange(left, length);
    DC_FlushRange(right, length);
    isByteFormat = format == 1;
    timerPeriod = 0xffb0ff / rate;
    if (callback != 0) {
        sampleTotal = length;
        if (isByteFormat == 0) {
            sampleTotal = length >> 1;
        }
        timerPeriod = (timerPeriod + 0x10) & ~0x1f;
        timerUnits = timerPeriod >> 5;
        alarmPeriod = timerUnits * (sampleTotal / parts);
        alarmDelay = 0x20;
        if (isByteFormat == 0) {
            alarmDelay = alarmDelay >> 1;
        }
        alarmDelay = alarmDelay * timerUnits;
    }
    switch (isByteFormat) {
        default:
            waveFormat = 0;
            break;
        case 0:
            waveFormat = 1;
            break;
    }
    if (isByteFormat != 0) {
        captureFormat = 1;
    } else {
        captureFormat = 0;
    }
    if (type != 2) {
        playChannels = SOUND_CAPTURE_CHANNEL_BITS;
    }
    if (callback != 0) {
        alarm = NNS_SndAllocAlarm();
        if (alarm < 0) {
            return 0;
        }
    }
    if (NNS_SndLockCapture(SOUND_CAPTURE_UNIT_BITS) == 0) {
        if (alarm >= 0) {
            NNS_SndFreeAlarm(alarm);
        }
        return 0;
    }
    if (NNS_SndLockChannel(SOUND_CAPTURE_CHANNEL_BITS) == 0) {
        if (alarm >= 0) {
            NNS_SndFreeAlarm(alarm);
        }
        NNS_SndUnlockCapture(SOUND_CAPTURE_UNIT_BITS);
        return 0;
    }
    SND_SetupChannelPcm(1, waveFormat, left, loop != 0 ? 1 : 2, 0, length >> 2, volume, 0, timerPeriod, panLeft);
    SND_SetupCapture(0, captureFormat, left, length >> 2, loop, input, output);
    SND_SetupChannelPcm(3, waveFormat, right, loop != 0 ? 1 : 2, 0, length >> 2, volume, 0, timerPeriod, panRight);
    SND_SetupCapture(1, captureFormat, right, length >> 2, loop, input, output);
    if (alarm >= 0) {
        SND_SetupAlarm(alarm, alarmPeriod + alarmDelay, alarmPeriod, AlarmCallback, capture);
    }
    if (type == 1) {
        SND_SetOutputSelector(1, 2, 1, 1);
    }
    SND_StartTimer(playChannels, SOUND_CAPTURE_UNIT_BITS, alarm >= 0 ? 1 << alarm : 0, 0);
    capture->mActiveFlag = 1;
    capture->mType = type;
    capture->mChBitMask = SOUND_CAPTURE_CHANNEL_BITS;
    capture->mPlayChBitMask = playChannels;
    capture->mCapBitMask = SOUND_CAPTURE_UNIT_BITS;
    capture->mAlarmNo = alarm;
    capture->mFormat = format;
    capture->mBufferL = left;
    capture->mBufferR = right;
    capture->mBufLen = length;
    capture->mBlockSize = length / parts;
    capture->mCurBuffer = 0;
    capture->mInterval = parts;
    capture->mCallback = callback;
    capture->mCallbackArg = callbackArg;
    capture->mVolume = volume;
    NNSi_SndFaderInit(&capture->mFader);
    NNSi_SndFaderSet(&capture->mFader, volume << 8, 1);
    capture->mFadeOutFlag = 0;
    return 1;
}

// Stops the timers, waits for the commands, drops the alarm messages, unlocks what the capture locked and restores
// the output selector of an effect capture.
void NNSi_SndCaptureStop(void) {
    CaptureParam *capture = &sCapParam;
    s32 hasAlarm;
    u32 tag;

    if (capture->mActiveFlag == 0) {
        return;
    }
    hasAlarm = capture->mAlarmNo >= 0;
    SND_StopTimer(capture->mPlayChBitMask, capture->mCapBitMask, hasAlarm != 0 ? 1 << capture->mAlarmNo : 0, 0);
    if (hasAlarm != 0) {
        tag = SND_GetCurrentCommandTag();
        SND_FlushCommand(1);
        SND_WaitForCommandProc(tag);
        while (OS_ReceiveMessage(&sMesgQ, 0, 0) != 0) {
        }
    }
    if (capture->mCapBitMask != 0) {
        NNS_SndUnlockCapture(capture->mCapBitMask);
    }
    if (capture->mChBitMask != 0) {
        NNS_SndUnlockChannel(capture->mChBitMask);
    }
    if (hasAlarm != 0) {
        NNS_SndFreeAlarm(capture->mAlarmNo);
    }
    if (capture->mType == 1) {
        SND_SetOutputSelector(0, 0, 0, 0);
    }
    capture->mActiveFlag = 0;
}

// Stops the capture timers and waits for the commands, for the sleep mode.
void NNSi_SndCaptureBeginSleep(void) {
    CaptureParam *capture = &sCapParam;
    u32 tag;

    if (capture->mActiveFlag == 0) {
        return;
    }
    SND_StopTimer(capture->mPlayChBitMask, capture->mCapBitMask, capture->mAlarmNo >= 0 ? 1 << capture->mAlarmNo : 0,
                  0);
    tag = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(tag);
}

// Clears and flushes both buffers and restarts the capture timers after sleep mode.
void NNSi_SndCaptureEndSleep(void) {
    CaptureParam *capture = &sCapParam;
    volatile u32 zeroL;
    volatile u32 zeroR;

    if (capture->mActiveFlag == 0) {
        return;
    }
    capture->mCurBuffer = 0;
    zeroL = 0;
    MIi_CpuClear32(zeroL, capture->mBufferL, capture->mBufLen);
    zeroR = 0;
    MIi_CpuClear32(zeroR, capture->mBufferR, capture->mBufLen);
    DC_FlushRange(capture->mBufferL, capture->mBufLen);
    DC_FlushRange(capture->mBufferR, capture->mBufLen);
    SND_StartTimer(capture->mPlayChBitMask, capture->mCapBitMask, capture->mAlarmNo >= 0 ? 1 << capture->mAlarmNo : 0,
                   0);
}

// Alarm handler: hands the current block of both buffers to the callback, directly or through the message queue
// when the thread exists, then moves to the next block.
void AlarmCallback(void *arg) {
    CaptureParam *capture = arg;
    u8 *left;
    u8 *right;
    u32 chunkSize;
    u32 offset;
    EffectInfo *info;

    chunkSize = capture->mBlockSize;
    offset = chunkSize * capture->mCurBuffer;
    left = capture->mBufferL + offset;
    right = capture->mBufferR + offset;
    if (sIsThreadCreated != 0) {
        info = &sEffectInfoBuffer[sCurEffectInfo];
        info->mCap = capture;
        info->mBlockSize = chunkSize;
        info->mOffset = offset;
        info->mBufferL = left;
        info->mBufferR = right;
        OS_SendMessage(&sMesgQ, info, 0);
        sCurEffectInfo++;
        if (sCurEffectInfo >= 8) {
            sCurEffectInfo = 0;
        }
    } else {
        DC_InvalidateRange(left, chunkSize);
        DC_InvalidateRange(right, chunkSize);
        capture->mCallback(left, right, chunkSize, capture->mFormat, capture->mCallbackArg);
    }
    capture->mCurBuffer++;
    if (capture->mCurBuffer >= capture->mInterval) {
        capture->mCurBuffer = 0;
    }
}
