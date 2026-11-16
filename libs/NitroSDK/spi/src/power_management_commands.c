#include "power_management_commands.h"
#include "reset_interrupts_halt.h"
#include "cartridge_slot_access.h"
#include "interrupt_control.h"
#include "mutex_init_decl.h"
#include "arm_fifo_messaging.h"
#include "registers.h"

u16 gPowerInitialized;
vu32 PMi_SleepEndFlag;
PMSleepCallbackInfo *gPowerPostSleepCallbacks;
u32 PMi_LCDCount;
PMSleepCallbackInfo *gPowerPreSleepCallbacks;
vu32 gPowerSleepHandshakeReplyReceived;
PMiWork gPowerCommand;
OSMutex PMi_Mutex;
PMData16 gPowerRegisterSlots[4];

// Marks a command as in flight and returns 1; returns 0 when one already is.
BOOL PMi_Lock(void) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (gPowerCommand.mLock != 0) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    gPowerCommand.mLock = 1;
    OS_RestoreInterrupts(enabled);
    return 1;
}

// Spins until no command is in flight.
void PMi_WaitBusy(void) {
    vu32 *lock;

    lock = &gPowerCommand.mLock;
    while (*lock != 0) {
    }
}

// Callback of the blocking commands: stores the result through arg.
void PMi_DummyCallback(u32 result, void *arg) {
    *(u32 *) arg = result;
}

// Clears the in-flight mark, then calls the stored callback once with the result and PMiWork.mCallbackArg.
void PMi_CallCallbackAndUnlock(u32 result) {
    u32 locked;
    PMCallback callback;
    void *arg;

    locked = gPowerCommand.mLock;
    callback = gPowerCommand.mCallback;
    arg = gPowerCommand.mCallbackArg;
    if (locked != 0) {
        gPowerCommand.mLock = 0;
    }
    if (callback == 0) {
        return;
    }
    gPowerCommand.mCallback = 0;
    callback(result, arg);
}

// Runs once: opens the power-management channel (PXI tag 8), waits for the other processor, installs
// PMi_CommonCallback as its handler and clears the register buffers.
void PM_Init(void) {
    int slotIndex;

    if (gPowerInitialized != 0) {
        return;
    }
    gPowerInitialized = 1;
    gPowerCommand.mLock = 0;
    gPowerCommand.mCallback = 0;
    PXI_Init();
    while (PXI_IsCallbackReady(8, 1) == 0) {
    }
    PXI_SetFifoRecvCallback(8, PMi_CommonCallback);
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gPowerRegisterSlots[slotIndex].mFlag = 0;
    }
    OS_InitMutex(&PMi_Mutex);
    PMi_LCDCount = SYSTEM_WORK->mVblankCount;
}

// Receive handler of the tag-8 channel. An error finishes the command with 2. Replies 0x70-0x73 store their byte
// through PMData16.mBuffer (result 0); 0x60 sets gPowerSleepHandshakeReplyReceived; 0x62 sets PMi_SleepEndFlag; 0x67
// stores through PMiWork.mWork (result 0). Then finishes the command with the result.
void PMi_CommonCallback(u32 tag, u32 data, u32 err) {
    u16 reply;
    u16 pxiCommand;
    u32 *work;

    if (err != 0) {
        PMi_CallCallbackAndUnlock(2);
        return;
    }
    pxiCommand = (data & 0x7f00) >> 8;
    reply = data & 0xff;
    if (pxiCommand >= 0x70 && pxiCommand <= 0x73) {
        u16 *buffer;
        u16 value;

        value = reply & 0xff;
        buffer = gPowerRegisterSlots[pxiCommand - 0x70].mBuffer;
        if (buffer != 0) {
            *buffer = value;
        }
        gPowerRegisterSlots[pxiCommand - 0x70].mFlag = 1;
        reply = 0;
    } else if (pxiCommand == 0x60) {
        gPowerSleepHandshakeReplyReceived = 1;
    } else if (pxiCommand == 0x62) {
        PMi_SleepEndFlag = 1;
    } else if (pxiCommand == 0x67) {
        work = gPowerCommand.mWork;
        if (work != 0) {
            *work = reply;
        }
        reply = 0;
    }
    PMi_CallCallbackAndUnlock(reply);
}

// Locks the command, sends the handshake word and waits for its reply, switches the screens off with the LED set to 2,
// then sends the sleep word (trigger) and the key word (keyIntrData). Returns 1 when busy.
u32 PMi_SendSleepStart(u16 trigger, u16 keyIntrData) {
    if (PMi_Lock() == 0) {
        return 1;
    }
    gPowerSleepHandshakeReplyReceived = 0;
    PMi_SendPxiData(0x3006000);
    while (gPowerSleepHandshakeReplyReceived == 0) {
    }
    gPowerSleepHandshakeReplyReceived = 0;
    PMi_SleepEndFlag = 0;
    PMi_SetLCDPower(0, POWER_LED_STATUS_SECOND, 0, 0);
    PMi_SendPxiData((trigger & 0xff) | 0x2006100);
    PMi_SendPxiData((keyIntrData & 0xffff) | 0x1010000);
    return 0;
}

// Sends utility command number and calls callback with the reply; returns 1 when another command is in flight.
u32 PM_SendUtilityCommandAsync(u32 number, PMCallback callback, void *arg) {
    if (PMi_Lock() == 0) {
        return 1;
    }
    gPowerCommand.mCallback = callback;
    gPowerCommand.mCallbackArg = arg;
    PMi_SendPxiData(((number >> 16) & 0xff) | 0x2006300);
    PMi_SendPxiData((number & 0xffff) | 0x1010000);
    return 0;
}

// Requests register registerAddr (0 to 3, not range-checked) into *buffer; callback is called with the result.
u32 PMi_ReadRegisterAsync(u16 registerAddr, u16 *buffer, PMCallback callback, void *arg) {
    if (PMi_Lock() == 0) {
        return 1;
    }
    gPowerRegisterSlots[registerAddr].mFlag = 0;
    gPowerCommand.mCallback = callback;
    gPowerCommand.mCallbackArg = arg;
    gPowerRegisterSlots[registerAddr].mBuffer = buffer;
    PMi_SendPxiData((registerAddr & 0xff) | 0x3006500);
    return 0;
}

// PMi_ReadRegisterAsync, then waits; returns the result.
u32 PMi_ReadRegister(u16 registerAddr, u16 *buffer) {
    u32 replyCode;
    u32 sendStatus;

    sendStatus = PMi_ReadRegisterAsync(registerAddr, buffer, PMi_DummyCallback, &replyCode);
    if (sendStatus != 0) {
        return sendStatus;
    }
    PMi_WaitBusy();
    return replyCode;
}

// Writes data to register registerAddr; callback is called with the result.
u32 PMi_WriteRegisterAsync(u16 registerAddr, u16 data, PMCallback callback, void *arg) {
    if (PMi_Lock() == 0) {
        return 1;
    }
    gPowerCommand.mCallback = callback;
    gPowerCommand.mCallbackArg = arg;
    PMi_SendPxiData((registerAddr & 0xff) | 0x2006400);
    PMi_SendPxiData((data & 0xffff) | 0x1010000);
    return 0;
}

// PMi_WriteRegisterAsync, then waits; returns the result.
u32 PMi_WriteRegister(u16 registerAddr, u16 data) {
    u32 replyCode;
    u32 sendStatus;

    sendStatus = PMi_WriteRegisterAsync(registerAddr, data, PMi_DummyCallback, &replyCode);
    if (sendStatus != 0) {
        return sendStatus;
    }
    PMi_WaitBusy();
    return replyCode;
}

// status 1, 2, 3 sends utility command 1, 3, 2; any other value returns 0xffff.
u32 PMi_SetLEDAsync(u32 status, PMCallback callback, void *arg) {
    u32 utilityCommand;

    switch (status) {
        case POWER_LED_STATUS_ON:
            utilityCommand = POWER_UTILITY_LED_ON;
            break;
        case POWER_LED_STATUS_THIRD:
            utilityCommand = POWER_UTILITY_LED_FOR_THIRD_STATUS;
            break;
        case POWER_LED_STATUS_SECOND:
            utilityCommand = POWER_UTILITY_LED_FOR_SECOND_STATUS;
            break;
        default:
            utilityCommand = 0;
            break;
    }
    if (utilityCommand == 0) {
        return 0xffff;
    }
    return PM_SendUtilityCommandAsync(utilityCommand, callback, arg);
}

// PMi_SetLEDAsync, then waits; returns the result.
u32 PMi_SetLED(u32 status) {
    u32 replyCode;
    u32 sendStatus;

    sendStatus = PMi_SetLEDAsync(status, PMi_DummyCallback, &replyCode);
    if (sendStatus != 0) {
        return sendStatus;
    }
    PMi_WaitBusy();
    return replyCode;
}

// target picks the screen (0, 1, or 2 for both), sw is 1 for on and 0 for off; sends utility command 6/7, 4/5 or 8/9.
// Returns 0xffff for any other pair.
u32 PM_SetBackLightAsync(u32 target, u32 sw, PMCallback callback, void *arg) {
    u32 utilityCommand;

    utilityCommand = 0;
    if (target == 0) {
        if (sw == POWER_SWITCH_ON) {
            utilityCommand = 6;
        }
        if (sw == POWER_SWITCH_OFF) {
            utilityCommand = 7;
        }
    } else if (target == 1) {
        if (sw == POWER_SWITCH_ON) {
            utilityCommand = 4;
        }
        if (sw == POWER_SWITCH_OFF) {
            utilityCommand = 5;
        }
    } else if (target == 2) {
        if (sw == POWER_SWITCH_ON) {
            utilityCommand = 8;
        }
        if (sw == POWER_SWITCH_OFF) {
            utilityCommand = 9;
        }
    }
    if (utilityCommand == 0) {
        return 0xffff;
    }
    return PM_SendUtilityCommandAsync(utilityCommand, callback, arg);
}

// PM_SetBackLightAsync, then waits for the reply and returns it.
u32 PM_SetBackLight(u32 target, u32 sw) {
    u32 replyCode;
    u32 sendStatus;

    sendStatus = PM_SetBackLightAsync(target, sw, PMi_DummyCallback, &replyCode);
    if (sendStatus != 0) {
        return sendStatus;
    }
    PMi_WaitBusy();
    return replyCode;
}

// Sends the power-off utility command (14) and returns.
u32 PM_ForceToPowerOffAsync(PMCallback callback, void *arg) {
    return PM_SendUtilityCommandAsync(0xe, callback, arg);
}

// Sends the power-off utility command (14) and waits for the reply.
u32 PM_ForceToPowerOff(void) {
    u32 replyCode;
    u32 sendStatus;

    sendStatus = PM_ForceToPowerOffAsync(PMi_DummyCallback, &replyCode);
    if (sendStatus != 0) {
        return sendStatus;
    }
    PMi_WaitBusy();
    return replyCode;
}

// Writes register 2 and waits for the reply; start-up code passes 1 after initialising the microphone.
u32 PM_SetAmp(u32 status) {
    return PMi_WriteRegister(2, status);
}

// Writes register 3 and waits for the reply; the microphone set-up passes 3.
u32 PM_SetAmpGain(u32 gain) {
    return PMi_WriteRegister(3, gain);
}

// Reads register 0 and stores bit 0x8 through top and bit 0x4 through bottom as 0 or 1. Returns the read result.
u32 PM_GetBackLight(u32 *top, u32 *bottom) {
    u16 registerValue;
    u32 result;

    result = PMi_ReadRegister(0, &registerValue);
    if (result != 0) {
        return result;
    }
    if (top != 0) {
        *top = (registerValue & 8) != 0 ? 1 : 0;
    }
    if (bottom != 0) {
        *bottom = (registerValue & 4) != 0 ? 1 : 0;
    }
    return result;
}

// Sends one word on tag 8, retrying until the FIFO accepts it.
void PMi_SendPxiData(u32 data) {
    while (PXI_SendWordByFifo(8, data, 0) != 0) {
    }
}

static inline u32 OS_GetVBlankCount(void) {
    return SYSTEM_WORK->mVblankCount;
}

// Runs the pre-sleep callbacks, switches both backlights and the screens off, asks the other processor to sleep (wake
// triggers trigger, key data logic | keyPattern), halts, then restores the screens and runs the post-sleep callbacks.
// When bit 0x8 of trigger is set and IRQ request bit 0x100000 is pending after the wake, it powers off instead of
// restoring.
void PM_GoSleepMode(u32 trigger, u32 logic, u32 keyPattern) {
    u32 intrMode;
    u32 intrMask;
    u32 lcdPower;
    u32 topBacklightOn;
    u32 bottomBacklightOn;
    vu32 vblankCount;
    u32 shutdownRequested;
    u32 savedMainDispCnt;
    u32 savedSubDispCnt;
    u16 param;
    u16 savedIme;
    u16 ime;

    shutdownRequested = 0;
    PMi_ExecuteList(gPowerPreSleepCallbacks);
    savedIme = reg_OS_IME;
    reg_OS_IME = 0;
    intrMode = OS_DisableInterrupts();
    intrMask = OS_DisableIrqMask(0x3fffff);
    OS_SetIrqMask(0x40000);
    OS_RestoreInterrupts(intrMode);
    ime = reg_OS_IME;
    reg_OS_IME = 1;
    if ((trigger & 8) != 0) {
        if (SYSTEM_WORK->mWmBootBuf.mBootType == BOOT_TYPE_MULTIBOOT) {
            trigger &= ~8;
        }
    }
    if ((trigger & 0x10) != 0) {
        if (CTRDG_IsExisting() == 0) {
            trigger &= ~0x10;
        }
    }
    savedMainDispCnt = reg_GX_DISPCNT;
    savedSubDispCnt = reg_GXS_DB_DISPCNT;
    lcdPower = PM_GetLCDPower();
    PM_GetBackLight(&topBacklightOn, &bottomBacklightOn);
    PM_SetBackLight(2, 0);
    vblankCount = OS_GetVBlankCount();
    while (vblankCount == OS_GetVBlankCount()) {
    }
    vblankCount = OS_GetVBlankCount();
    reg_GX_DISPCNT &= ~0x30000;
    reg_GXS_DB_DISPCNT &= ~0x10000;
    while (vblankCount == OS_GetVBlankCount()) {
    }
    vblankCount = OS_GetVBlankCount();
    while (vblankCount == OS_GetVBlankCount()) {
    }
    param = trigger | (topBacklightOn << 5) | (bottomBacklightOn << 6);
    while (PMi_SendSleepStart(param, logic | keyPattern) != 0) {
    }
    OS_Halt();
    OS_SpinWait(0x332340);
    if ((trigger & 8) != 0) {
        if ((reg_OS_IF & 0x100000) != 0) {
            shutdownRequested = 1;
        }
    }
    if (shutdownRequested == 0) {
        if (lcdPower == 1) {
            PMi_SetLCDPower(1, POWER_LED_STATUS_ON, 1, 0);
        } else {
            PMi_SetLED(POWER_LED_STATUS_ON);
        }
        reg_GX_DISPCNT = savedMainDispCnt;
        reg_GXS_DB_DISPCNT = savedSubDispCnt;
    }
    OS_DisableInterrupts();
    OS_SetIrqMask(intrMask);
    OS_RestoreInterrupts(intrMode);
    ime = reg_OS_IME;
    reg_OS_IME = savedIme;
    if (shutdownRequested != 0) {
        PM_ForceToPowerOff();
    }
    PMi_ExecuteList(gPowerPostSleepCallbacks);
}

// sw = 1 turns the screens on, sw = 0 off. On: returns 0 and changes nothing when fewer than 8 counts of the shared
// counter at 0x27ffc3c have passed since the last turn-off, unless skip is nonzero. led != 0 also sets that LED
// (waiting for it when isSync is nonzero). Off: stores the counter for that guard. Returns 1 when done.
BOOL PMi_SetLCDPower(u32 sw, u32 led, u32 skip, u32 isSync) {
    switch (sw) {
        case POWER_SWITCH_ON:
            if (skip == 0) {
                if (SYSTEM_WORK->mVblankCount - PMi_LCDCount <= 7) {
                    return 0;
                }
            }
            if (led != 0) {
                if (isSync != 0) {
                    PMi_SetLED(led);
                } else {
                    PMi_SetLEDAsync(led, 0, 0);
                }
            }
            reg_GX_POWCNT |= 1;
            break;
        case POWER_SWITCH_OFF:
            reg_GX_POWCNT &= ~1;
            PMi_LCDCount = SYSTEM_WORK->mVblankCount;
            if (led != 0) {
                if (isSync != 0) {
                    PMi_SetLED(led);
                } else {
                    PMi_SetLEDAsync(led, 0, 0);
                }
            }
            break;
    }
    return 1;
}

// Anything but 1 counts as 0. Switches the screens on or off with no LED change; returns 0 when the turn-on guard of
// PMi_SetLCDPower refuses.
BOOL PM_SetLCDPower(u32 sw) {
    if (sw != POWER_SWITCH_ON) {
        sw = POWER_SWITCH_OFF;
    }
    return PMi_SetLCDPower(sw, 0, 0, 1);
}

// Returns bit 0 of reg_GX_POWCNT: 1 while the screens are powered.
int PM_GetLCDPower(void) {
    return (reg_GX_POWCNT & 1) != 0 ? 1 : 0;
}

// Sends command 0x66 with pattern byte pattern; callback is called with the result.
u32 PMi_SendLEDPatternCommandAsync(u32 pattern, PMCallback callback, void *arg) {
    if (PMi_Lock() == 0) {
        return 1;
    }
    gPowerCommand.mCallback = callback;
    gPowerCommand.mCallbackArg = arg;
    PMi_SendPxiData((pattern & 0xff) | 0x3006600);
    return 0;
}

// PMi_SendLEDPatternCommandAsync, then waits; returns the result.
u32 PMi_SendLEDPatternCommand(u32 pattern) {
    u32 replyCode;
    u32 sendStatus;

    sendStatus = PMi_SendLEDPatternCommandAsync(pattern, PMi_DummyCallback, &replyCode);
    if (sendStatus != 0) {
        return sendStatus;
    }
    PMi_WaitBusy();
    return replyCode;
}

// Sends command 0x67; the reply byte is stored through patternBuf and callback is called with the result.
u32 PM_GetLEDPatternAsync(u32 *patternBuf, PMCallback callback, void *arg) {
    if (PMi_Lock() == 0) {
        return 1;
    }
    gPowerCommand.mCallback = callback;
    gPowerCommand.mCallbackArg = arg;
    gPowerCommand.mWork = patternBuf;
    PMi_SendPxiData(0x3006700);
    return 0;
}

// PM_GetLEDPatternAsync, then waits for the reply; *patternBuf receives the pattern.
u32 PM_GetLEDPattern(u32 *patternBuf) {
    u32 replyCode;
    u32 sendStatus;

    sendStatus = PM_GetLEDPatternAsync(patternBuf, PMi_DummyCallback, &replyCode);
    if (sendStatus != 0) {
        return sendStatus;
    }
    PMi_WaitBusy();
    return replyCode;
}

// Puts info first in *listp.
void PMi_PrependList(PMSleepCallbackInfo **listp, PMSleepCallbackInfo *info) {
    if (listp != 0) {
        info->mNext = *listp;
        *listp = info;
    }
}

// Puts info last in *listp.
void PMi_AppendList(PMSleepCallbackInfo **listp, PMSleepCallbackInfo *info) {
    PMSleepCallbackInfo *last;
    PMSleepCallbackInfo *next;

    if (listp == 0) {
        return;
    }
    last = *listp;
    if (last == 0) {
        info->mNext = 0;
        *listp = info;
        return;
    }
    next = last->mNext;
    while (next != 0) {
        last = next;
        next = next->mNext;
    }
    info->mNext = next;
    last->mNext = info;
}

// Unlinks info from *listp.
void PMi_DeleteList(PMSleepCallbackInfo **listp, PMSleepCallbackInfo *info) {
    PMSleepCallbackInfo *current;
    PMSleepCallbackInfo *previous;

    if (listp == 0) {
        return;
    }
    current = *listp;
    previous = current;
    if (current == 0) {
        return;
    }
    do {
        if (current == info) {
            if (current == previous) {
                *listp = current->mNext;
            } else {
                previous->mNext = current->mNext;
            }
            return;
        }
        previous = current;
        current = current->mNext;
    } while (current != 0);
}

// Calls PMSleepCallbackInfo.mCallback with mArg for each entry of the list.
void PMi_ExecuteList(PMSleepCallbackInfo *list) {
    if (list == 0) {
        return;
    }
    do {
        list->mCallback(list->mArg);
        list = list->mNext;
    } while (list != 0);
}

// Appends info to the list PM_GoSleepMode runs before the sleep sequence.
void PM_AppendPreSleepCallback(PMSleepCallbackInfo *info) {
    PMi_AppendList(&gPowerPreSleepCallbacks, info);
}

// Puts info first in the list PM_GoSleepMode runs before the sleep sequence.
void PM_PrependPreSleepCallback(PMSleepCallbackInfo *info) {
    PMi_PrependList(&gPowerPreSleepCallbacks, info);
}

// Appends info to the list PM_GoSleepMode runs after the wake.
void PM_AppendPostSleepCallback(PMSleepCallbackInfo *info) {
    PMi_AppendList(&gPowerPostSleepCallbacks, info);
}

// Removes info from the pre-sleep list.
void PM_DeletePreSleepCallback(PMSleepCallbackInfo *info) {
    PMi_DeleteList(&gPowerPreSleepCallbacks, info);
}

// Removes info from the post-sleep list.
void PM_DeletePostSleepCallback(PMSleepCallbackInfo *info) {
    PMi_DeleteList(&gPowerPostSleepCallbacks, info);
}
