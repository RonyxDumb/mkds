#pragma once

#include "types.h"

typedef struct SNDSharedWork SNDSharedWork;

// Command id whose first argument is the address of the shared work area.
#define SOUND_COMMAND_SET_SHARED_WORK 0x1d

// A sound command: the link to the next command, its id and four arguments; free commands are chained in a list.
typedef struct SNDCommand {
    /* 00 */ struct SNDCommand *mNext;
    /* 04 */ u32 mId;
    /* 08 */ u32 mArg[4];
} SNDCommand;

typedef void (*SNDAlarmHandler)(void *);

// The callback of a sound alarm: its function and argument, and an id that counts how often they were set.
typedef struct AlarmCallbackInfo {
    /* 00 */ SNDAlarmHandler mFunc;
    /* 04 */ void *mArg;
    /* 08 */ u8 mId;
} AlarmCallbackInfo;

extern SNDCommand *g_Command;
extern u32 sFinishedTag;
extern SNDCommand *g_WaitingCommandListCount;
extern SNDCommand *sReserveListEnd;
extern SNDCommand *sCommandFreeListEnd;
extern s32 sWaitingCommandListQueueRead;
extern s32 sWaitingCommandListQueueWrite;
extern s32 g_Sound_WaitingCommandCount;
extern u32 sCurrentTag;
extern SNDCommand *sWaitingCommandListQueue[13];
extern SNDSharedWork sSharedWork;
extern SNDCommand g_SoundCommandArray[256];
extern AlarmCallbackInfo g_SoundAlarms[8];

u32 Sound_IsCommandAvailable(void);
SNDCommand *Sound_AllocateCommandImpl(void);
void SoundInternal_RequestCommandProc(void);
void Sound_RegisterFifoHandler(void);
void Sound_FifoHandler(u32 tag, u32 data);
s32 SND_CountWaitingCommand(void);
s32 SND_CountReservedCommand(void);
s32 SND_CountFreeCommand(void);
u32 SND_IsFinishedCommandTag(u32 tag);
u32 SND_GetCurrentCommandTag(void);
void SND_WaitForCommandProc(u32 tag);
u32 Sound_FlushCommand(u32 flags);
void SND_PushCommand(SNDCommand *command);
SNDCommand *Sound_AllocateCommand(u32 flags);
const SNDCommand *Sound_CommandReceiveAndReply(u32 flags);
void Sound_InitializeCommands(void);
void Sound_CallAlarmHandler(int alarmNo);
u8 SetMDValue(int alarmNo, SNDAlarmHandler handler, void *arg);
