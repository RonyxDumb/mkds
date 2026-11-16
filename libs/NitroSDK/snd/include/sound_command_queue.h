#pragma once

#include "types.h"

typedef struct SNDSharedWork SNDSharedWork;

// Command id whose first argument is the address of the shared work area.
#define SOUND_COMMAND_SET_SHARED_WORK 0x1d

// A sound command: mNext, its id mId and four arguments mArg; the free list, the list waiting to be sent and the sent
// lists are chained through mNext.
typedef struct SNDCommand {
    /* 00 */ struct SNDCommand *mNext;
    /* 04 */ u32 mId;
    /* 08 */ u32 mArg[4];
} SNDCommand;

typedef void (*SNDAlarmHandler)(void *);

// The callback of a sound alarm: mFunc and mArg, and mId, which SNDi_SetAlarmHandler and SNDi_IncAlarmId raise and
// SNDi_CallAlarmHandler compares.
typedef struct AlarmCallbackInfo {
    /* 00 */ SNDAlarmHandler mFunc;
    /* 04 */ void *mArg;
    /* 08 */ u8 mId;
} AlarmCallbackInfo;

extern SNDCommand *sCommandFreeList;
extern u32 sFinishedTag;
extern SNDCommand *sReserveList;
extern SNDCommand *sReserveListEnd;
extern SNDCommand *sCommandFreeListEnd;
extern s32 sWaitingCommandListQueueRead;
extern s32 sWaitingCommandListQueueWrite;
extern s32 sWaitingCommandListCount;
extern u32 sCurrentTag;
extern SNDCommand *sWaitingCommandListQueue[13];
extern SNDSharedWork sSharedWork;
extern SNDCommand sCommandArray[256];
extern AlarmCallbackInfo gSndAlarmCallbackInfos[8];

u32 IsCommandAvailable(void);
SNDCommand *AllocCommand(void);
void RequestCommandProc(void);
void InitPXI(void);
void PxiFifoCallback(u32 tag, u32 data);
s32 SND_CountWaitingCommand(void);
s32 SND_CountReservedCommand(void);
s32 SND_CountFreeCommand(void);
u32 SND_IsFinishedCommandTag(u32 tag);
u32 SND_GetCurrentCommandTag(void);
void SND_WaitForCommandProc(u32 tag);
u32 SND_FlushCommand(u32 flags);
void SND_PushCommand(SNDCommand *command);
SNDCommand *SND_AllocCommand(u32 flags);
const SNDCommand *SND_RecvCommandReply(u32 flags);
void SND_CommandInit(void);
void SNDi_CallAlarmHandler(int alarmNo);
u8 SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg);
