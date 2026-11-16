#include "sound_shared_work_access.h"

#include "sound_command_queue.h"
#include "arena_cache_init.h"
#include "thread_scheduler.h"

SNDSharedWork *SNDi_SharedWork;

// Reads the player status word of the shared work area after invalidating its cache line.
u32 SND_GetPlayerStatus(void) {
    DC_InvalidateRangeNoClean(&SNDi_SharedWork->mPlayerStatus, 4);
    return SNDi_SharedWork->mPlayerStatus;
}

// Reads variable varNo of player playerNo from the shared work area after invalidating its cache line.
s16 SND_GetPlayerLocalVariable(s32 playerNo, s32 varNo) {
    DC_InvalidateRangeNoClean(&SNDi_SharedWork->mPlayer[playerNo].mVariable[varNo], 2);
    return SNDi_SharedWork->mPlayer[playerNo].mVariable[varNo];
}

// Reads the finished command tag of the shared work area after invalidating its cache line.
u32 SNDi_GetFinishedCommandTag(void) {
    DC_InvalidateRangeNoClean(SNDi_SharedWork, 4);
    return SNDi_SharedWork->mFinishCommandTag;
}

// Clears the status words, the tick counters and sets every variable to -1, then writes the area back to memory.
void SNDi_InitSharedWork(SNDSharedWork *work) {
    s32 playerNo;
    s32 variableNo;

    work->mPlayerStatus = 0;
    work->mChannelStatus = 0;
    work->mCaptureStatus = 0;
    work->mFinishCommandTag = 0;
    for (playerNo = 0; playerNo < 16; playerNo++) {
        work->mPlayer[playerNo].mTickCounter = 0;
        for (variableNo = 0; variableNo < 16; variableNo++) {
            work->mPlayer[playerNo].mVariable[variableNo] = -1;
        }
    }
    for (variableNo = 0; variableNo < 16; variableNo++) {
        work->mGlobalVariable[variableNo] = -1;
    }
    Arm_FlushRange(work, 0x280);
}

// Clears the handler, argument and id of each of the 8 alarm table entries.
void Sound_InitializeAlarms(void) {
    s32 alarmNo;

    for (alarmNo = 0; alarmNo < 8; alarmNo++) {
        g_SoundAlarms[alarmNo].mFunc = 0;
        g_SoundAlarms[alarmNo].mArg = 0;
        g_SoundAlarms[alarmNo].mId = 0;
    }
}

// Raises the id byte of alarm table entry alarmNo and returns it.
u32 IncreaseMDCounter(u32 alarmNo) {
    AlarmCallbackInfo *info;
    u32 id;

    info = &g_SoundAlarms[alarmNo];
    id = info->mId + 1;
    info->mId = id;
    return id;
}
