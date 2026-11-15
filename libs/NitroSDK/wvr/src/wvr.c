#include "wvr.h"
#include "os_spinLock.h"
#include "code_0200fc8c.h"
#include "data_02173000.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "mic.h"
#include "gfd_LinkedListTexVramMan.h"
#include "code_0214d5b8.h"
#include "code_0200fe74.h"

void (*wvrCallback)(u32, s32) = 0;
u32 wvrArg = 0;
vu16 wvrVRam = 0;
vu16 wvrLockId = 0;

s32 WVR_StartUpAsync(u32 vram, void (*callback)(u32, s32), u32 arg) {
    u32 enabled;

    PXI_Init();
    if (PXI_IsCallbackReady(0xf, 1) == 0) {
        return 2;
    }
    if (wvrLockId == 0) {
        do {
            s32 id = OS_GetLockID();

            if (id == -3) {
                return 7;
            }
            wvrLockId = id;
        } while (wvrLockId == 0);
    }
    enabled = OS_DisableInterrupts();
    if (wvrCallback != 0) {
        OS_RestoreInterrupts(enabled);
        return 5;
    }
    if (wvrVRam != 0) {
        OS_RestoreInterrupts(enabled);
        return 5;
    }
    switch (vram) {
        case WVR_VRAM_BANK_C:
            if (OSi_TryLockVram(WVR_VRAM_BANK_C, wvrLockId) == 0) {
                OS_RestoreInterrupts(enabled);
                return 6;
            }
            wvrVRam = WVR_VRAM_BANK_C;
            *(vu8 *) 0x4000242 = 0x82;
            break;
        case WVR_VRAM_BANK_D:
            if (OSi_TryLockVram(WVR_VRAM_BANK_D, wvrLockId) == 0) {
                OS_RestoreInterrupts(enabled);
                return 6;
            }
            wvrVRam = WVR_VRAM_BANK_D;
            *(vu8 *) 0x4000243 = 0x82;
            break;
        case WVR_VRAM_BANK_C_AND_D:
            if (OSi_TryLockVram(WVR_VRAM_BANK_C_AND_D, wvrLockId) == 0) {
                OS_RestoreInterrupts(enabled);
                return 6;
            }
            wvrVRam = WVR_VRAM_BANK_C_AND_D;
            *(vu8 *) 0x4000242 = 0x82;
            *(vu8 *) 0x4000243 = 0x8a;
            break;
        default:
            OS_RestoreInterrupts(enabled);
            return 3;
    }
    if (PXI_IsCallbackReady(0xf, 0) == 0) {
        PXI_SetFifoRecvCallback(0xf, WvrReceiveCallback);
    }
    if (callback == 0) {
        wvrCallback = WvrDummyAsyncCallback;
    } else {
        wvrCallback = callback;
    }
    wvrArg = arg;
    if (PXI_SendWordByFifo(0xf, WVR_COMMAND_START_UP, 0) < 0) {
        OSi_UnlockVram(wvrVRam, wvrLockId);
        wvrVRam = 0;
        wvrCallback = 0;
        OS_RestoreInterrupts(enabled);
        return 4;
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

s32 WVR_TerminateAsync(void (*callback)(u32, s32), u32 arg) {
    u32 enabled;

    PXI_Init();
    if (PXI_IsCallbackReady(0xf, 1) == 0) {
        return 2;
    }
    enabled = OS_DisableInterrupts();
    if (wvrCallback != 0) {
        OS_RestoreInterrupts(enabled);
        return 5;
    }
    if (PXI_IsCallbackReady(0xf, 0) == 0) {
        PXI_SetFifoRecvCallback(0xf, WvrReceiveCallback);
    }
    if (callback == 0) {
        wvrCallback = WvrDummyAsyncCallback;
    } else {
        wvrCallback = callback;
    }
    wvrArg = arg;
    if (PXI_SendWordByFifo(0xf, WVR_COMMAND_TERMINATE, 0) < 0) {
        wvrCallback = 0;
        OS_RestoreInterrupts(enabled);
        return 4;
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

void WvrReceiveCallback(u32 tag, u32 data) {
    void (*callback)(u32, s32);
    u32 callbackArg;
    u32 command;
    u32 result;

    command = data & 0xffff0000;
    result = data & 0xff;
    callback = wvrCallback;
    callbackArg = wvrArg;
    switch (command) {
        case WVR_COMMAND_START_UP:
            if (result == 7 && wvrVRam != 0 && wvrLockId != 0) {
                OSi_UnlockVram(wvrVRam, wvrLockId);
                wvrVRam = 0;
            }
            break;
        case WVR_COMMAND_TERMINATE:
            if (result == 0 && wvrVRam != 0 && wvrLockId != 0) {
                OSi_UnlockVram(wvrVRam, wvrLockId);
                wvrVRam = 0;
            }
            PXI_SetFifoRecvCallback(0xf, 0);
            break;
    }
    if (callback != 0) {
        wvrCallback = 0;
        wvrArg = 0;
        callback(callbackArg, result);
    }
}

void WvrDummyAsyncCallback(u32 arg, s32 result) {}
