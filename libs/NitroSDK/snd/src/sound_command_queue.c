#include "sound_command_queue.h"
#include "arena_cache_init.h"
#include "reset_interrupts_halt.h"
#include "thread_scheduler.h"
#include "thread_mutex_types.h"
#include "arm_fifo_messaging.h"
#include "sound_shared_work_access.h"
#include "registers.h"

u32 sFinishedTag;
u32 sCurrentTag;
SNDCommand *sCommandFreeListEnd;
SNDCommand *g_WaitingCommandListCount;
SNDCommand *g_Command;
SNDCommand *sReserveListEnd;
s32 sWaitingCommandListQueueRead;
s32 sWaitingCommandListQueueWrite;
s32 g_Sound_WaitingCommandCount;
SNDCommand *sWaitingCommandListQueue[13];
SNDSharedWork sSharedWork;
SNDCommand g_SoundCommandArray[256];

// Stores handler and arg in the alarm table entry for alarmNo and returns the id byte of that entry after raising it.
u8 SetMDValue(int alarmNo, SNDAlarmHandler handler, void *arg) {
    AlarmCallbackInfo *info;

    info = &g_SoundAlarms[alarmNo];
    info->mFunc = handler;
    info->mArg = arg;
    info->mId++;
    return info->mId;
}

// Calls the handler of the alarm in the low byte of alarmNo when the id byte in the next byte is still the entry's id.
void Sound_CallAlarmHandler(int alarmNo) {
    AlarmCallbackInfo *info;

    info = &g_SoundAlarms[alarmNo & 0xff];
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
void Sound_InitializeCommands(void) {
    s32 commandIndex;
    SNDCommand *sharedCommand;

    Sound_RegisterFifoHandler();
    g_Command = g_SoundCommandArray;
    for (commandIndex = 0; commandIndex < 255; commandIndex++) {
        g_SoundCommandArray[commandIndex].mNext = &g_SoundCommandArray[commandIndex + 1];
    }
    g_SoundCommandArray[255].mNext = 0;
    sCommandFreeListEnd = &g_SoundCommandArray[255];
    g_WaitingCommandListCount = 0;
    sReserveListEnd = 0;
    g_Sound_WaitingCommandCount = 0;
    sWaitingCommandListQueueRead = 0;
    sWaitingCommandListQueueWrite = 0;
    sCurrentTag = 1;
    sFinishedTag = 0;
    SNDi_SharedWork = &sSharedWork;
    SNDi_InitSharedWork(&sSharedWork);
    sharedCommand = Sound_AllocateCommand(1);
    if (sharedCommand == 0) {
        return;
    }
    sharedCommand->mId = SOUND_COMMAND_SET_SHARED_WORK;
    sharedCommand->mArg[0] = (u32) SNDi_SharedWork;
    SND_PushCommand(sharedCommand);
    Sound_FlushCommand(1);
}

// Takes the oldest sent command list back into the free list and returns it. With flags bit 0 it waits for the reply,
// otherwise it returns 0 when none has come.
const SNDCommand *Sound_CommandReceiveAndReply(u32 flags) {
    u32 enabled;
    SNDCommand *chain;
    SNDCommand *chainEnd;
    s32 listIndex;

    enabled = Os_DisableIrq();
    if ((flags & 1) != 0) {
        while (sFinishedTag == SNDi_GetFinishedCommandTag()) {
            Os_RestoreIrq(enabled);
            Os_SpinWait(0x64);
            enabled = Os_DisableIrq();
        }
    } else if (sFinishedTag == SNDi_GetFinishedCommandTag()) {
        Os_RestoreIrq(enabled);
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
        g_Command = chain;
    }
    sCommandFreeListEnd = chainEnd;
    g_Sound_WaitingCommandCount--;
    sFinishedTag++;
    Os_RestoreIrq(enabled);
    return chain;
}

// Returns a record from the free list. When there is none and flags bit 0 is set, it flushes or collects replies until
// one is free; without the bit it returns 0.
SNDCommand *Sound_AllocateCommand(u32 flags) {
    SNDCommand *allocated;

    if (Sound_IsCommandAvailable() == 0) {
        return 0;
    }
    allocated = Sound_AllocateCommandImpl();
    if (allocated != 0) {
        return allocated;
    }
    if ((flags & 1) == 0) {
        return 0;
    }
    if (SND_CountWaitingCommand() > 0) {
        while (Sound_CommandReceiveAndReply(0) != 0) {
        }
        allocated = Sound_AllocateCommandImpl();
        if (allocated != 0) {
            return allocated;
        }
    } else {
        Sound_FlushCommand(1);
    }
    SoundInternal_RequestCommandProc();
    do {
        Sound_CommandReceiveAndReply(1);
        allocated = Sound_AllocateCommandImpl();
    } while (allocated == 0);
    return allocated;
}

// Appends the record to the list of commands that wait to be sent.
void SND_PushCommand(SNDCommand *command) {
    u32 enabled;
    SNDCommand *end;

    enabled = Os_DisableIrq();
    end = sReserveListEnd;
    if (end == 0) {
        sReserveListEnd = command;
        g_WaitingCommandListCount = command;
    } else {
        end->mNext = command;
        sReserveListEnd = command;
    }
    command->mNext = 0;
    Os_RestoreIrq(enabled);
}

// Sends the list of waiting commands to the other processor; returns 1 when sent or when none wait. With flags bit 0 it
// waits until it can send, otherwise it returns 0. Flags bit 1 also requests command processing.
u32 Sound_FlushCommand(u32 flags) {
    u32 enabled;

    enabled = Os_DisableIrq();
    if (g_WaitingCommandListCount == 0) {
        Os_RestoreIrq(enabled);
        return 1;
    }
    if (g_Sound_WaitingCommandCount >= 8) {
        if ((flags & 1) == 0) {
            Os_RestoreIrq(enabled);
            return 0;
        }
        do {
            Sound_CommandReceiveAndReply(1);
        } while (g_Sound_WaitingCommandCount >= 8);
    }
    Arm_FlushRange(g_SoundCommandArray, 0x1800);
    if (Fifo_SendWord(7, (u32) g_WaitingCommandListCount, 0) < 0) {
        if ((flags & 1) == 0) {
            Os_RestoreIrq(enabled);
            return 0;
        }
        if (Fifo_SendWord(7, (u32) g_WaitingCommandListCount, 0) < 0) {
            do {
                Os_RestoreIrq(enabled);
                Os_SpinWait(0x64);
                enabled = Os_DisableIrq();
            } while (Fifo_SendWord(7, (u32) g_WaitingCommandListCount, 0) < 0);
        }
    }
    if ((flags & 2) != 0) {
        SoundInternal_RequestCommandProc();
    }
    sWaitingCommandListQueue[sWaitingCommandListQueueWrite] = g_WaitingCommandListCount;
    sWaitingCommandListQueueWrite++;
    if (sWaitingCommandListQueueWrite > 8) {
        sWaitingCommandListQueueWrite = 0;
    }
    g_WaitingCommandListCount = 0;
    sReserveListEnd = 0;
    g_Sound_WaitingCommandCount++;
    sCurrentTag++;
    Os_RestoreIrq(enabled);
    return 1;
}

// Returns once the other processor has finished the commands up to tag.
void SND_WaitForCommandProc(u32 tag) {
    if (SND_IsFinishedCommandTag(tag) != 0) {
        return;
    }
    while (Sound_CommandReceiveAndReply(0) != 0) {
    }
    if (SND_IsFinishedCommandTag(tag) != 0) {
        return;
    }
    SoundInternal_RequestCommandProc();
    if (SND_IsFinishedCommandTag(tag) != 0) {
        return;
    }
    do {
        Sound_CommandReceiveAndReply(1);
    } while (SND_IsFinishedCommandTag(tag) == 0);
}

// Returns the tag that the next sent command list will get: the finished tag when no command waits, else the current
// one.
u32 SND_GetCurrentCommandTag(void) {
    u32 enabled;
    u32 tag;

    enabled = Os_DisableIrq();
    if (g_WaitingCommandListCount == 0) {
        tag = sFinishedTag;
    } else {
        tag = sCurrentTag;
    }
    Os_RestoreIrq(enabled);
    return tag;
}

// Returns 1 when tag is not after the finished tag (compared as a wrapping counter).
u32 SND_IsFinishedCommandTag(u32 tag) {
    u32 enabled;
    u32 finished;
    u32 result;

    enabled = Os_DisableIrq();
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
    Os_RestoreIrq(enabled);
    return result;
}

// Counts the records in the free list.
s32 SND_CountFreeCommand(void) {
    u32 enabled;
    SNDCommand *entry;
    s32 count;

    enabled = Os_DisableIrq();
    count = 0;
    for (entry = g_Command; entry != 0; entry = entry->mNext) {
        count++;
    }
    Os_RestoreIrq(enabled);
    return count;
}

// Counts the records in the list of commands that wait to be sent.
s32 SND_CountReservedCommand(void) {
    u32 enabled;
    SNDCommand *entry;
    s32 count;

    enabled = Os_DisableIrq();
    count = 0;
    for (entry = g_WaitingCommandListCount; entry != 0; entry = entry->mNext) {
        count++;
    }
    Os_RestoreIrq(enabled);
    return count;
}

// Counts the records that were sent and not yet taken back.
s32 SND_CountWaitingCommand(void) {
    s32 free;

    free = SND_CountFreeCommand();
    return 0x100 - free - SND_CountReservedCommand();
}

// Runs the alarm handler for data with interrupts off.
void Sound_FifoHandler(u32 tag, u32 data) {
    u32 enabled;

    enabled = Os_DisableIrq();
    Sound_CallAlarmHandler(data);
    Os_RestoreIrq(enabled);
}

// Sets the sound FIFO callback and, when the command channel is available, waits until the other side is ready.
void Sound_RegisterFifoHandler(void) {
    Fifo_RegisterHandler(7, Sound_FifoHandler);
    if (Sound_IsCommandAvailable() == 0) {
        return;
    }
    if (Fifo_IsHandlerReady(7, 1) != 0) {
        return;
    }
    do {
        Os_SpinWait(0x64);
    } while (Fifo_IsHandlerReady(7, 1) == 0);
}

// Sends the request-command-processing message until the FIFO takes it.
void SoundInternal_RequestCommandProc(void) {
    while (Fifo_SendWord(7, 0, 0) < 0) {
    }
}

// Takes the first record off the free list, or returns 0 when it is empty.
SNDCommand *Sound_AllocateCommandImpl(void) {
    u32 enabled;
    SNDCommand *command;
    SNDCommand *next;

    enabled = Os_DisableIrq();
    command = g_Command;
    if (command == 0) {
        Os_RestoreIrq(enabled);
        return 0;
    }
    next = command->mNext;
    g_Command = next;
    if (next == 0) {
        sCommandFreeListEnd = 0;
    }
    Os_RestoreIrq(enabled);
    return command;
}

// Returns 1 unless the port at 0x04fff200 does not answer.
u32 Sound_IsCommandAvailable(void) {
    u32 enabled;
    u32 value;

    if (Os_IsEmulator() == 0) {
        return 1;
    }
    enabled = Os_DisableIrq();
    reg_EMU_PORT = 0x10;
    value = reg_EMU_PORT;
    Os_RestoreIrq(enabled);
    return value != 0;
}
