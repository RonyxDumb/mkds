#include "wireless_system_commands.h"

#include "arena_cache_init.h"
#include "thread_scheduler.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_clear_16.h"
#include "cpu_copy_fill.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "sound_stream_control.h"
#include "sound_archive_load.h"
#include "wireless_link_control.h"
#include "thread_mutex_types.h"
#include "dma_copy_fill_wait.h"
#include "arm_fifo_messaging.h"

struct WMPortRecvCallback gPortCallbackEvent;
u8 g_WMQueueMessagesData[10][0x100];

u16 g_WmInitialized;
struct WMArm9Buf *g_GlobalWM;
OSMessageQueue g_WMQueue;
void *g_WMQueueBuffer[10];

// Sets up the system buffer for the DMA channel dmaNo and clears WMArm9Buf.mScanOnlyFlag.
s32 Wm_Initialize(void *wmSysBuf, u16 dmaNo) {
    s32 result;

    result = Wm_InitializeImpl(wmSysBuf, dmaNo, 0xf00);
    if (result == 0) {
        g_GlobalWM->mScanOnlyFlag = 0;
    }
    return result;
}

// Takes the 32-byte aligned system buffer of bufSize bytes, lays out its areas, resets the port callbacks and the
// message ring and hooks Wm_FifoHandler onto the WM PXI tag. Returns 3 when already set up, 6 for a bad buffer or DMA
// channel, 4 when the other processor is not ready.
s32 Wm_InitializeImpl(void *wmSysBuf, u16 dmaNo, u32 bufSize) {
    s32 port;
    s32 index;

    if (g_WmInitialized != 0) {
        return 3;
    }
    g_WmInitialized = 1;
    if (wmSysBuf == 0) {
        g_WmInitialized = 0;
        return 6;
    }
    if (dmaNo > 3) {
        g_WmInitialized = 0;
        return 6;
    }
    if (((u32) wmSysBuf & 0x1f) != 0) {
        g_WmInitialized = 0;
        return 6;
    }
    j_Fifo_Initialize();
    if (Fifo_IsHandlerReady(0xa, 1) == 0) {
        g_WmInitialized = 0;
        return 4;
    }
    DC_InvalidateRangeNoClean(wmSysBuf, bufSize);
    Mem_DmaFill32(dmaNo, wmSysBuf, 0, bufSize);
    g_GlobalWM = wmSysBuf;
    g_GlobalWM->mWM7 = OFFSET_PTR(void, wmSysBuf, WIRELESS_ARM9_BUF_SIZE);
    g_GlobalWM->mStatusArea = OFFSET_PTR(WMStatus, g_GlobalWM->mWM7, 0x300);
    g_GlobalWM->mRequestArea = OFFSET_PTR(u16, g_GlobalWM->mStatusArea, 0x800);
    g_GlobalWM->mMessageArea = OFFSET_PTR(WirelessMessage, g_GlobalWM->mRequestArea, 0x100);
    Wm_DisableCallbackControl();
    g_GlobalWM->mDmaNo = dmaNo;
    for (port = 0; port < 16; port++) {
        WM_SetPortCallback(port, 0, 0);
    }
    Os_MessageQueue_Initialize(&g_WMQueue, g_WMQueueBuffer, 10);
    for (index = 0; index < 10; index++) {
        *(u16 *) g_WMQueueMessagesData[index] = 0x8000;
        DC_SomeClean(g_WMQueueMessagesData[index], 2);
        Os_MessageQueue_Send(&g_WMQueue, g_WMQueueMessagesData[index], 1);
    }
    Fifo_RegisterHandler(0xa, Wm_FifoHandler);
    return 0;
}

// Releases the system buffer and unhooks Wm_FifoHandler; only allowed in state 0.
s32 WM_Finish(void) {
    s32 result;

    if (Wm_CheckInitialized() != 0) {
        return 3;
    }
    result = WMi_CheckStateEx(1, 0);
    if (result != 0) {
        return result;
    }
    Wm_DisableCallbackControl();
    Fifo_RegisterHandler(0xa, 0);
    g_GlobalWM = 0;
    g_WmInitialized = 0;
    return 0;
}

// Stores callback as the handler of the command id.
void SetSomeFunctionPtr(u32 id, WirelessMessageCallback callback) {
    g_GlobalWM->mCommandCallbacks[id] = callback;
}

// Sends command id with paramNum words to the other processor through a free message of the ring; with no words the
// request area is copied into the message. Returns 8 when no message is free or the send fails, otherwise 2.
s32 WM_SomeFn(u32 id, u16 paramNum, ...) {
    void *buffer;
    u32 *args;
    s32 argIndex;
    s32 result;

    if (Os_ReceiveMessage(&g_WMQueue, &buffer, 0) == 0) {
        return 8;
    }
    DC_InvalidateRangeNoClean(buffer, 2);
    if ((*(u16 *) buffer & 0x8000) == 0) {
        OS_JamMessage(&g_WMQueue, buffer, 1);
        return 8;
    }
    if (paramNum == 0) {
        DC_SomeClean(g_GlobalWM->mRequestArea, 0x100);
        DC_InvalidateRangeNoClean(buffer, 0x100);
        MI_DmaCopy32(g_GlobalWM->mDmaNo, g_GlobalWM->mRequestArea, buffer, 0x100);
    }
    *(u16 *) buffer = id;
    args = (u32 *) (((u32) &paramNum & ~3) + 4);
    for (argIndex = 0; argIndex < paramNum; argIndex++) {
        args++;
        (OFFSET_PTR(u32, buffer, 4))[argIndex] = args[-1];
    }
    DC_SomeClean(buffer, 0x100);
    result = Fifo_SendWord(0xa, (u32) buffer, 0);
    Os_MessageQueue_Send(&g_WMQueue, buffer, 1);
    if (result < 0) {
        return 8;
    }
    return 2;
}

// Returns the system buffer.
WMArm9Buf *Wm_GetGlobal(void) {
    return g_GlobalWM;
}

// Returns 0 once the library is set up, otherwise 3.
s32 Wm_CheckInitialized(void) {
    if (g_WmInitialized != 0) {
        return 0;
    }
    return 3;
}

// Returns 3 when the library is not set up or the state is 0 or 1, otherwise 0.
s32 WMi_CheckIdle(void) {
    s32 result;

    result = Wm_CheckInitialized();
    if (result != 0) {
        return result;
    }
    DC_InvalidateRangeNoClean(g_GlobalWM->mStatusArea, 2);
    if (g_GlobalWM->mStatusArea->mState <= 1) {
        return 3;
    }
    return 0;
}

// Returns 0 when WMStatus.mState equals one of the paramNum state numbers that follow, otherwise 3.
s32 WMi_CheckStateEx(s32 paramNum, ...) {
    u32 *args;
    u16 current;
    s32 result;

    result = Wm_CheckInitialized();
    if (result != 0) {
        return result;
    }
    DC_InvalidateRangeNoClean(g_GlobalWM->mStatusArea, 2);
    current = g_GlobalWM->mStatusArea->mState;
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
void Wm_FifoHandler(u32 tag, WirelessMessage *callback, s32 err) {
    WirelessMessageCallback handler;
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
    DC_InvalidateRangeNoClean(g_GlobalWM->mMessageArea, 0x100);
    if (g_GlobalWM->mScanOnlyFlag == 0) {
        DC_InvalidateRangeNoClean(g_GlobalWM->mStatusArea, 0x800);
    }
    if (callback != g_GlobalWM->mMessageArea) {
        DC_InvalidateRangeNoClean(callback, 0x100);
    }
    if (callback->mCommand >= WIRELESS_REQUEST_KIND_COUNT) {
        if (callback->mCommand == WIRELESS_REQUEST_EVENT_REPORT) {
            if (callback->mResultCode == WIRELESS_RESULT_STORAGE_ERROR) {
                Os_Terminate();
            }
            handler = g_GlobalWM->mIndicationCallback;
            if (handler != 0) {
                handler(callback);
            }
        } else if (callback->mCommand == WIRELESS_REQUEST_PORT_DATA) {
            if (g_GlobalWM->mPortCallbacks[callback->mPort] != 0) {
                callback->mArg = g_GlobalWM->mPortCallbackArgs[callback->mPort];
                DC_InvalidateRangeNoClean(callback->mRecvBuf, g_GlobalWM->mStatusArea->mMpRecvBufSize);
                g_GlobalWM->mPortCallbacks[callback->mPort](callback);
            }
        } else if (callback->mCommand == WIRELESS_REQUEST_PORT_SENT) {
            callback->mCommand = WIRELESS_REQUEST_QUEUE_EXCHANGE_DATA;
            handler = callback->mArg;
            if (handler != 0) {
                handler(callback);
            }
        }
    } else {
        if (callback->mCommand == WIRELESS_REQUEST_BEGIN_EXCHANGE) {
            if ((u16) (callback->mState + 0xfff5) <= 1) {
                if (callback->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
                    DC_InvalidateRangeNoClean(callback->mRecvBuf, g_GlobalWM->mStatusArea->mMpRecvBufSize);
                }
            }
        }
        if (callback->mCommand == WIRELESS_REQUEST_CLOSE_STACK && callback->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
            handler = g_GlobalWM->mCommandCallbacks[callback->mCommand];
            WM_Finish();
            if (handler == 0) {
                return;
            }
            handler(callback);
            return;
        }
        handler = g_GlobalWM->mCommandCallbacks[callback->mCommand];
        if (handler != 0) {
            handler(callback);
            if (g_WmInitialized == 0) {
                return;
            }
        }
        command = callback->mCommand;
        if (command == WIRELESS_REQUEST_OPEN_HOST || command == WIRELESS_REQUEST_ENTER_HOST) {
            if (command == WIRELESS_REQUEST_OPEN_HOST) {
                peerAddress = callback->mMacAddress;
                peerName = callback->mPeerBytes;
                stateCode = callback->mReplyState;
                memberIndex = callback->mLength;
                ownIndex = 0;
            } else if (command == 0xc) {
                memberIndex = 0;
                stateCode = callback->mReplyState;
                ownIndex = callback->mLength;
                peerName = 0;
                peerAddress = callback->mMacAddress;
            }
            if (stateCode == 7 || stateCode == 9) {
                gPortCallbackEvent.mCommand = WIRELESS_REQUEST_PORT_DATA;
                gPortCallbackEvent.mResultCode = WIRELESS_RESULT_SUCCEEDED;
                gPortCallbackEvent.mState = stateCode;
                gPortCallbackEvent.mRecvBuf = 0;
                gPortCallbackEvent.mData = 0;
                gPortCallbackEvent.mLength = 0;
                gPortCallbackEvent.mAid = memberIndex;
                gPortCallbackEvent.mOwnIndex = ownIndex;
                gPortCallbackEvent.mSeqNo = WIRELESS_SEQ_NO_NONE;
                Mem_CpuCopy8(peerAddress, gPortCallbackEvent.mPeerBytes, 6);
                if (peerName != 0) {
                    CopyMemory16(peerName, gPortCallbackEvent.mSsid, 0x18);
                } else {
                    zero = 0;
                    Mem_CpuFill16(zero, gPortCallbackEvent.mSsid, 0x18);
                }
                for (port = 0; port < 16; port++) {
                    gPortCallbackEvent.mPort = port;
                    if (g_GlobalWM->mPortCallbacks[port] != 0) {
                        gPortCallbackEvent.mArg = g_GlobalWM->mPortCallbackArgs[port];
                        g_GlobalWM->mPortCallbacks[port](&gPortCallbackEvent);
                    }
                }
            }
        }
    }
    DC_InvalidateRangeNoClean(g_GlobalWM->mMessageArea, 0x100);
    Wm_DisableCallbackControl();
    if (callback == g_GlobalWM->mMessageArea) {
        return;
    }
    callback->mCommand |= WIRELESS_FREE_FLAG;
    DC_SomeClean(callback, 0x100);
}

// Clears the pending-callback flag (bit 0) of the system work halfword at 0x027fff96.
void Wm_DisableCallbackControl(void) {
    if ((SYSTEM_WORK->mWmCallbackControl & 1) != 0) {
        SYSTEM_WORK->mWmCallbackControl &= ~1;
    }
}

// Returns the status area, or NULL when the library is not set up.
WMStatus *WMi_GetStatusAddress(void) {
    if (Wm_CheckInitialized() != 0) {
        return 0;
    }
    return g_GlobalWM->mStatusArea;
}
