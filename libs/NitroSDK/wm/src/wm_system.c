#include "wm_system.h"

#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200fc8c.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0217e000.h"
#include "code_02142eac.h"
#include "code_0200e77c.h"
#include "code_0214c778.h"
#include "code_0214d5b8.h"

u16 wmInitialized;
struct WMArm9Buf *wm9buf;
OSMessageQueue data_0217eed8;
void *data_0217eef8[10];

// Sets up the system buffer for the DMA channel dmaNo and clears WMArm9Buf.mScanOnlyFlag.
s32 WM_Init(void *wmSysBuf, u16 dmaNo) {
    s32 result;

    result = WmInitCore(wmSysBuf, dmaNo, 0xf00);
    if (result == 0) {
        wm9buf->mScanOnlyFlag = 0;
    }
    return result;
}

// Takes the 32-byte aligned system buffer of bufSize bytes, lays out its areas, resets the port callbacks and the
// message ring and hooks WmReceiveFifo onto the WM PXI tag. Returns 3 when already set up, 6 for a bad buffer or DMA
// channel, 4 when the other processor is not ready.
s32 WmInitCore(void *wmSysBuf, u16 dmaNo, u32 bufSize) {
    s32 port;
    s32 index;

    if (wmInitialized != 0) {
        return 3;
    }
    wmInitialized = 1;
    if (wmSysBuf == 0) {
        wmInitialized = 0;
        return 6;
    }
    if (dmaNo > 3) {
        wmInitialized = 0;
        return 6;
    }
    if (((u32) wmSysBuf & 0x1f) != 0) {
        wmInitialized = 0;
        return 6;
    }
    PXI_Init();
    if (PXI_IsCallbackReady(0xa, 1) == 0) {
        wmInitialized = 0;
        return 4;
    }
    DC_InvalidateRange(wmSysBuf, bufSize);
    MI_DmaFill32(dmaNo, wmSysBuf, 0, bufSize);
    wm9buf = wmSysBuf;
    wm9buf->mWM7 = (u8 *) wmSysBuf + 0x200;
    wm9buf->mStatusArea = OFFSET_PTR(Unk02142988, wm9buf->mWM7, 0x300);
    wm9buf->mRequestArea = OFFSET_PTR(u16, wm9buf->mStatusArea, 0x800);
    wm9buf->mMessageArea = OFFSET_PTR(Unk021425e8, wm9buf->mRequestArea, 0x100);
    WmClearFifoRecvFlag();
    wm9buf->mDmaNo = dmaNo;
    for (port = 0; port < 16; port++) {
        WM_SetPortCallback(port, 0, 0);
    }
    OS_InitMessageQueue(&data_0217eed8, data_0217eef8, 10);
    for (index = 0; index < 10; index++) {
        *(u16 *) data_0217ef60[index] = 0x8000;
        DC_StoreRange(data_0217ef60[index], 2);
        OS_SendMessage(&data_0217eed8, data_0217ef60[index], 1);
    }
    PXI_SetFifoRecvCallback(0xa, WmReceiveFifo);
    return 0;
}

// Releases the system buffer and unhooks WmReceiveFifo; only allowed in state 0.
s32 WM_Finish(void) {
    s32 result;

    if (WMi_CheckInitialized() != 0) {
        return 3;
    }
    result = WMi_CheckStateEx(1, 0);
    if (result != 0) {
        return result;
    }
    WmClearFifoRecvFlag();
    PXI_SetFifoRecvCallback(0xa, 0);
    wm9buf = 0;
    wmInitialized = 0;
    return 0;
}

// Stores callback as the handler of the command id.
void WMi_SetCallbackTable(u32 id, Unk021425e8Func callback) {
    wm9buf->mCommandCallbacks[id] = callback;
}

// Sends command id with paramNum words to the other processor through a free message of the ring; with no words the
// request area is copied into the message. Returns 8 when no message is free or the send fails, otherwise 2.
s32 WMi_SendCommand(u32 id, u16 paramNum, ...) {
    void *buffer;
    u32 *args;
    s32 argIndex;
    s32 result;

    if (OS_ReceiveMessage(&data_0217eed8, &buffer, 0) == 0) {
        return 8;
    }
    DC_InvalidateRange(buffer, 2);
    if ((*(u16 *) buffer & 0x8000) == 0) {
        OS_JamMessage(&data_0217eed8, buffer, 1);
        return 8;
    }
    if (paramNum == 0) {
        DC_StoreRange(wm9buf->mRequestArea, 0x100);
        DC_InvalidateRange(buffer, 0x100);
        MI_DmaCopy32(wm9buf->mDmaNo, wm9buf->mRequestArea, buffer, 0x100);
    }
    *(u16 *) buffer = id;
    args = (u32 *) (((u32) &paramNum & ~3) + 4);
    for (argIndex = 0; argIndex < paramNum; argIndex++) {
        args++;
        (OFFSET_PTR(u32, buffer, 4))[argIndex] = args[-1];
    }
    DC_StoreRange(buffer, 0x100);
    result = PXI_SendWordByFifo(0xa, (u32) buffer, 0);
    OS_SendMessage(&data_0217eed8, buffer, 1);
    if (result < 0) {
        return 8;
    }
    return 2;
}

// Returns the system buffer.
WMArm9Buf *WMi_GetSystemWork(void) {
    return wm9buf;
}

// Returns 0 once the library is set up, otherwise 3.
s32 WMi_CheckInitialized(void) {
    if (wmInitialized != 0) {
        return 0;
    }
    return 3;
}

// Returns 3 when the library is not set up or the state is 0 or 1, otherwise 0.
s32 WMi_CheckIdle(void) {
    s32 result;

    result = WMi_CheckInitialized();
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(wm9buf->mStatusArea, 2);
    if (wm9buf->mStatusArea->mState <= 1) {
        return 3;
    }
    return 0;
}

// Returns 0 when Unk02142988.mState equals one of the paramNum state numbers that follow, otherwise 3.
s32 WMi_CheckStateEx(s32 paramNum, ...) {
    u32 *args;
    u16 current;
    s32 result;

    result = WMi_CheckInitialized();
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(wm9buf->mStatusArea, 2);
    current = wm9buf->mStatusArea->mState;
    args = (u32 *) (((u32) &paramNum & ~3) + 4);
    result = 3;
    while (paramNum != 0) {
        args++;
        if (args[-1] == current) {
            result = 0;
        }
        paramNum--;
    }
    return result;
}

// Handler of the WM PXI tag: takes the message the other processor sent and calls the handler stored for it (the
// command callback, the indication callback or a port callback). Replies to commands 8 and 12 (start
// parent, start connect) with a connect or disconnect state are also passed to every port callback.
void WmReceiveFifo(u32 tag, Unk021425e8 *callback, s32 err) {
    Unk021425e8Func handler;
    u16 command;
    u16 stateCode;
    u16 memberIndex;
    u16 ownIndex;
    u8 *peerAddress;
    u8 *peerName;
    u16 port;
    volatile u16 zero;

    if (err != 0) {
        return;
    }
    DC_InvalidateRange(wm9buf->mMessageArea, 0x100);
    if (wm9buf->mScanOnlyFlag == 0) {
        DC_InvalidateRange(wm9buf->mStatusArea, 0x800);
    }
    if (callback != wm9buf->mMessageArea) {
        DC_InvalidateRange(callback, 0x100);
    }
    if (callback->mCommand >= 0x2a) {
        if (callback->mCommand == 0x80) {
            if (callback->mResultCode == 0x13) {
                OS_Terminate();
            }
            handler = wm9buf->mIndicationCallback;
            if (handler != 0) {
                handler(callback);
            }
        } else if (callback->mCommand == 0x82) {
            if (wm9buf->mPortCallbacks[callback->mUnk_06] != 0) {
                callback->mUnk_1c = wm9buf->mPortCallbackArgs[callback->mUnk_06];
                DC_InvalidateRange(callback->mUnk_08, wm9buf->mStatusArea->mMpRecvBufSize);
                wm9buf->mPortCallbacks[callback->mUnk_06](callback);
            }
        } else if (callback->mCommand == 0x81) {
            callback->mCommand = 0xf;
            handler = callback->mUnk_1c;
            if (handler != 0) {
                handler(callback);
            }
        }
    } else {
        if (callback->mCommand == 0xe) {
            if ((u16) (callback->mUnk_04 + 0xfff5) <= 1) {
                if (callback->mResultCode == 0) {
                    DC_InvalidateRange(callback->mUnk_08, wm9buf->mStatusArea->mMpRecvBufSize);
                }
            }
        }
        if (callback->mCommand == 2 && callback->mResultCode == 0) {
            handler = wm9buf->mCommandCallbacks[callback->mCommand];
            WM_Finish();
            if (handler == 0) {
                return;
            }
            handler(callback);
            return;
        }
        handler = wm9buf->mCommandCallbacks[callback->mCommand];
        if (handler != 0) {
            handler(callback);
            if (wmInitialized == 0) {
                return;
            }
        }
        command = callback->mCommand;
        if (command == 8 || command == 0xc) {
            if (command == 8) {
                peerAddress = (u8 *) callback + 0xa;
                peerName = (u8 *) callback + 0x14;
                stateCode = *(u16 *) &callback->mUnk_08;
                memberIndex = callback->mUnk_10;
                ownIndex = 0;
            } else if (command == 0xc) {
                memberIndex = 0;
                stateCode = *(u16 *) &callback->mUnk_08;
                ownIndex = callback->mUnk_10;
                peerName = 0;
                peerAddress = (u8 *) callback + 0xa;
            }
            if (stateCode == 7 || stateCode == 9) {
                gPortCallbackEvent.mCommand = 0x82;
                gPortCallbackEvent.mResultCode = 0;
                gPortCallbackEvent.mUnk_04 = stateCode;
                gPortCallbackEvent.mUnk_08 = 0;
                gPortCallbackEvent.mUnk_0c = 0;
                gPortCallbackEvent.mUnk_10 = 0;
                gPortCallbackEvent.mUnk_12 = memberIndex;
                gPortCallbackEvent.mUnk_20 = ownIndex;
                gPortCallbackEvent.mUnk_1a = 0xffff;
                MI_CpuCopy8(peerAddress, gPortCallbackEvent.mUnk_14, 6);
                if (peerName != 0) {
                    MIi_CpuCopy16(peerName, gPortCallbackEvent.mUnk_24, 0x18);
                } else {
                    zero = 0;
                    MIi_CpuClear16(zero, gPortCallbackEvent.mUnk_24, 0x18);
                }
                for (port = 0; port < 16; port++) {
                    gPortCallbackEvent.mUnk_06 = port;
                    if (wm9buf->mPortCallbacks[port] != 0) {
                        gPortCallbackEvent.mUnk_1c = wm9buf->mPortCallbackArgs[port];
                        wm9buf->mPortCallbacks[port](&gPortCallbackEvent);
                    }
                }
            }
        }
    }
    DC_InvalidateRange(wm9buf->mMessageArea, 0x100);
    WmClearFifoRecvFlag();
    if (callback == wm9buf->mMessageArea) {
        return;
    }
    callback->mCommand |= 0x8000;
    DC_StoreRange(callback, 0x100);
}

// Clears the pending-callback flag (bit 0) of the system work halfword at 0x027fff96.
void WmClearFifoRecvFlag(void) {
    if ((SYSTEM_WORK->mWmCallbackControl & 1) != 0) {
        SYSTEM_WORK->mWmCallbackControl &= ~1;
    }
}

// Returns the status area, or NULL when the library is not set up.
Unk02142988 *WMi_GetStatusAddress(void) {
    if (WMi_CheckInitialized() != 0) {
        return 0;
    }
    return wm9buf->mStatusArea;
}
