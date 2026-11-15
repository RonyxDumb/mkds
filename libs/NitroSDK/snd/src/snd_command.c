#include "snd_command.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "os_thread.h"
#include "code_0200e77c.h"
#include "code_0214d5b8.h"
#include "snd_work.h"
#include "registers.h"

u32 sFinishedTag;
u32 sCurrentTag;
SNDCommand *sCommandFreeListEnd;
SNDCommand *sReserveList;
SNDCommand *sCommandFreeList;
SNDCommand *sReserveListEnd;
s32 sWaitingCommandListQueueRead;
s32 sWaitingCommandListQueueWrite;
s32 sWaitingCommandListCount;
SNDCommand *sWaitingCommandListQueue[13];
SNDSharedWork sSharedWork;
SNDCommand sCommandArray[256];

// Stores handler and arg in the alarm table entry for alarmNo and returns the id byte of that entry after raising it.
u8 SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg) {
    AlarmCallbackInfo *info;

    info = &gSndAlarmCallbackInfos[alarmNo];
    info->mFunc = handler;
    info->mArg = arg;
    info->mId++;
    return info->mId;
}

// Calls the handler of the alarm in the low byte of alarmNo when the id byte in the next byte is still the entry's id.
void SNDi_CallAlarmHandler(int alarmNo) {
    AlarmCallbackInfo *info;

    info = &gSndAlarmCallbackInfos[alarmNo & 0xff];
    if (((alarmNo >> 8) & 0xff) != info->mId) {
        return;
    }
    if (info->mFunc == 0) {
        return;
    }
    info->mFunc(info->mArg);
}

// Waits for the other processor's side of the command channel, links all records into the free list, clears the
// counters and queues the command that hands over the shared work area.
void SND_CommandInit(void) {
    s32 commandIndex;
    SNDCommand *sharedCommand;

    InitPXI();
    sCommandFreeList = sCommandArray;
    for (commandIndex = 0; commandIndex < 255; commandIndex++) {
        sCommandArray[commandIndex].mNext = &sCommandArray[commandIndex + 1];
    }
    sCommandArray[255].mNext = 0;
    sCommandFreeListEnd = &sCommandArray[255];
    sReserveList = 0;
    sReserveListEnd = 0;
    sWaitingCommandListCount = 0;
    sWaitingCommandListQueueRead = 0;
    sWaitingCommandListQueueWrite = 0;
    sCurrentTag = 1;
    sFinishedTag = 0;
    SNDi_SharedWork = &sSharedWork;
    SNDi_InitSharedWork(&sSharedWork);
    sharedCommand = SND_AllocCommand(1);
    if (sharedCommand == 0) {
        return;
    }
    sharedCommand->mId = SND_COMMAND_SET_SHARED_WORK;
    sharedCommand->mArg[0] = (u32) SNDi_SharedWork;
    SND_PushCommand(sharedCommand);
    SND_FlushCommand(1);
}

// Takes the oldest sent command list back into the free list and returns it. With flags bit 0 it waits for the reply,
// otherwise it returns 0 when none has come.
const SNDCommand *SND_RecvCommandReply(u32 flags) {
    u32 enabled;
    SNDCommand *chain;
    SNDCommand *chainEnd;
    s32 listIndex;

    enabled = OS_DisableInterrupts();
    if ((flags & 1) != 0) {
        while (sFinishedTag == SNDi_GetFinishedCommandTag()) {
            OS_RestoreInterrupts(enabled);
            OS_SpinWait(0x64);
            enabled = OS_DisableInterrupts();
        }
    } else if (sFinishedTag == SNDi_GetFinishedCommandTag()) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    listIndex = sWaitingCommandListQueueRead;
    chain = sWaitingCommandListQueue[listIndex];
    sWaitingCommandListQueueRead = listIndex + 1;
    if (sWaitingCommandListQueueRead > 8) {
        sWaitingCommandListQueueRead = 0;
    }
    chainEnd = chain;
    while (chainEnd->mNext != 0) {
        chainEnd = chainEnd->mNext;
    }
    if (sCommandFreeListEnd != 0) {
        sCommandFreeListEnd->mNext = chain;
    } else {
        sCommandFreeList = chain;
    }
    sCommandFreeListEnd = chainEnd;
    sWaitingCommandListCount--;
    sFinishedTag++;
    OS_RestoreInterrupts(enabled);
    return chain;
}

// Returns a record from the free list. When there is none and flags bit 0 is set, it flushes or collects replies until
// one is free; without the bit it returns 0.
SNDCommand *SND_AllocCommand(u32 flags) {
    SNDCommand *allocated;

    if (IsCommandAvailable() == 0) {
        return 0;
    }
    allocated = AllocCommand();
    if (allocated != 0) {
        return allocated;
    }
    if ((flags & 1) == 0) {
        return 0;
    }
    if (SND_CountWaitingCommand() > 0) {
        while (SND_RecvCommandReply(0) != 0) {
        }
        allocated = AllocCommand();
        if (allocated != 0) {
            return allocated;
        }
    } else {
        SND_FlushCommand(1);
    }
    RequestCommandProc();
    do {
        SND_RecvCommandReply(1);
        allocated = AllocCommand();
    } while (allocated == 0);
    return allocated;
}

// Appends the record to the list of commands that wait to be sent.
void SND_PushCommand(SNDCommand *command) {
    u32 enabled;
    SNDCommand *end;

    enabled = OS_DisableInterrupts();
    end = sReserveListEnd;
    if (end == 0) {
        sReserveListEnd = command;
        sReserveList = command;
    } else {
        end->mNext = command;
        sReserveListEnd = command;
    }
    command->mNext = 0;
    OS_RestoreInterrupts(enabled);
}

// Sends the list of waiting commands to the other processor; returns 1 when sent or when none wait. With flags bit 0 it
// waits until it can send, otherwise it returns 0. Flags bit 1 also requests command processing.
u32 SND_FlushCommand(u32 flags) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (sReserveList == 0) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (sWaitingCommandListCount >= 8) {
        if ((flags & 1) == 0) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        do {
            SND_RecvCommandReply(1);
        } while (sWaitingCommandListCount >= 8);
    }
    DC_FlushRange(sCommandArray, 0x1800);
    if (PXI_SendWordByFifo(7, (u32) sReserveList, 0) < 0) {
        if ((flags & 1) == 0) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        if (PXI_SendWordByFifo(7, (u32) sReserveList, 0) < 0) {
            do {
                OS_RestoreInterrupts(enabled);
                OS_SpinWait(0x64);
                enabled = OS_DisableInterrupts();
            } while (PXI_SendWordByFifo(7, (u32) sReserveList, 0) < 0);
        }
    }
    if ((flags & 2) != 0) {
        RequestCommandProc();
    }
    sWaitingCommandListQueue[sWaitingCommandListQueueWrite] = sReserveList;
    sWaitingCommandListQueueWrite++;
    if (sWaitingCommandListQueueWrite > 8) {
        sWaitingCommandListQueueWrite = 0;
    }
    sReserveList = 0;
    sReserveListEnd = 0;
    sWaitingCommandListCount++;
    sCurrentTag++;
    OS_RestoreInterrupts(enabled);
    return 1;
}

// Returns once the other processor has finished the commands up to tag.
void SND_WaitForCommandProc(u32 tag) {
    if (SND_IsFinishedCommandTag(tag) != 0) {
        return;
    }
    while (SND_RecvCommandReply(0) != 0) {
    }
    if (SND_IsFinishedCommandTag(tag) != 0) {
        return;
    }
    RequestCommandProc();
    if (SND_IsFinishedCommandTag(tag) != 0) {
        return;
    }
    do {
        SND_RecvCommandReply(1);
    } while (SND_IsFinishedCommandTag(tag) == 0);
}

// Returns the tag that the next sent command list will get: the finished tag when no command waits, else the current
// one.
u32 SND_GetCurrentCommandTag(void) {
    u32 enabled;
    u32 tag;

    enabled = OS_DisableInterrupts();
    if (sReserveList == 0) {
        tag = sFinishedTag;
    } else {
        tag = sCurrentTag;
    }
    OS_RestoreInterrupts(enabled);
    return tag;
}

// Returns 1 when tag is not after the finished tag (compared as a wrapping counter).
u32 SND_IsFinishedCommandTag(u32 tag) {
    u32 enabled;
    u32 finished;
    u32 result;

    enabled = OS_DisableInterrupts();
    finished = sFinishedTag;
    if (tag > finished) {
        if ((tag - finished) < 0x80000000u) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        if ((finished - tag) < 0x80000000u) {
            result = 1;
        } else {
            result = 0;
        }
    }
    OS_RestoreInterrupts(enabled);
    return result;
}

// Counts the records in the free list.
s32 SND_CountFreeCommand(void) {
    u32 enabled;
    SNDCommand *entry;
    s32 count;

    enabled = OS_DisableInterrupts();
    count = 0;
    for (entry = sCommandFreeList; entry != 0; entry = entry->mNext) {
        count++;
    }
    OS_RestoreInterrupts(enabled);
    return count;
}

// Counts the records in the list of commands that wait to be sent.
s32 SND_CountReservedCommand(void) {
    u32 enabled;
    SNDCommand *entry;
    s32 count;

    enabled = OS_DisableInterrupts();
    count = 0;
    for (entry = sReserveList; entry != 0; entry = entry->mNext) {
        count++;
    }
    OS_RestoreInterrupts(enabled);
    return count;
}

// Counts the records that were sent and not yet taken back.
s32 SND_CountWaitingCommand(void) {
    s32 free;

    free = SND_CountFreeCommand();
    return 0x100 - free - SND_CountReservedCommand();
}

// Runs the alarm handler for data with interrupts off.
void PxiFifoCallback(u32 tag, u32 data) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    SNDi_CallAlarmHandler(data);
    OS_RestoreInterrupts(enabled);
}

// Sets the sound FIFO callback and, when the command channel is available, waits until the other side is ready.
void InitPXI(void) {
    PXI_SetFifoRecvCallback(7, PxiFifoCallback);
    if (IsCommandAvailable() == 0) {
        return;
    }
    if (PXI_IsCallbackReady(7, 1) != 0) {
        return;
    }
    do {
        OS_SpinWait(0x64);
    } while (PXI_IsCallbackReady(7, 1) == 0);
}

// Sends the request-command-processing message until the FIFO takes it.
void RequestCommandProc(void) {
    while (PXI_SendWordByFifo(7, 0, 0) < 0) {
    }
}

// Takes the first record off the free list, or returns 0 when it is empty.
SNDCommand *AllocCommand(void) {
    u32 enabled;
    SNDCommand *command;
    SNDCommand *next;

    enabled = OS_DisableInterrupts();
    command = sCommandFreeList;
    if (command == 0) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    next = command->mNext;
    sCommandFreeList = next;
    if (next == 0) {
        sCommandFreeListEnd = 0;
    }
    OS_RestoreInterrupts(enabled);
    return command;
}

// Returns 1 unless the port at 0x04fff200 does not answer.
u32 IsCommandAvailable(void) {
    u32 enabled;
    u32 value;

    if (OS_IsRunOnEmulator() == 0) {
        return 1;
    }
    enabled = OS_DisableInterrupts();
    reg_EMU_PORT = 0x10;
    value = reg_EMU_PORT;
    OS_RestoreInterrupts(enabled);
    return value != 0;
}
