#include "Main/Unknown/code_020529b8.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f59c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0204a52c.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"
#include "code_021445e0.h"
#include "wm_etc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203c25c.h"

void sub_2053D00(void) {
    Unk02143a78 *scanParams;
    Unk021438f0 *scanExParams;
    Unk0217aa00_16a0_view *blocks;
    BlockEntry *blockEntry;
    s32 i;

    if (gStruct217AA00 == NULL) {
        return;
    }
    gStruct217AA00->field0 = 0;
    gStruct217AA00->field4 = 0;
    gStruct217AA00->field8 = 9;
    gStruct217AA00->fieldC = 0;
    gStruct217AA00->mRequestPending = 0;
    gStruct217AA00->field454 = 0;
    scanParams = gStruct217AA00->field1C;
    scanParams->field0 = gStruct217AA00->field28;
    scanParams->field4 = 0;
    scanParams->field6 = 0;
    for (i = 0; i < 6; i++) {
        scanParams->field8[i] = 0xff;
    }
    scanExParams = gStruct217AA00->field20;
    scanExParams->field0 = gStruct217AA00->field2C;
    scanExParams->field4 = 0x400;
    scanExParams->field6 = 0;
    scanExParams->field8 = 0;
    scanExParams->field10 = 1;
    scanExParams->field12 = 0;
    for (i = 0; i < 6; i++) {
        scanExParams->fieldA[i] = 0xff;
    }
    ResetConnectionData();
    blocks = &gStruct217AA00->mUnk_16a0_view;
    blockEntry = &blocks->mBlockEntries[0];
    for (i = 0; i < 0xc; i++) {
        blockEntry->mPath = 0;
        blockEntry->mBuffer = NULL;
        blockEntry++;
    }
    blocks->field6B4 = 0;
    blocks->field660 = 0;
    blocks->field798 = FALSE;
    blocks->field79C = FALSE;
    func_0204e65c(&gStruct217AA00->mUnk_1658_view);
    func_02059878();
    FillParentParameter(1);
}

// Fills the record handed to WM_StepDataSharing, steps the data sharing with it and keeps the result.
void StepDataSharing(void) {
    Unk0217aa00_15c4 *sendData;
    u32 role;
    s32 result;

    scene_getSceneFrameCounter();
    sendData = gStruct217AA00->field15C4;
    if (gStruct217AA00->field4 == 8) {
        sendData->field5 = gStruct217AA00->field15F7;
    } else {
        sendData->field5 = 0;
    }
    sendData->field4 = (gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0) == 1 ? gStruct217AA00->field1EAC[0] : 0;
    sendData->field0 = input_getPressedKeys();
    sendData->field6_0 = 0;
    sendData->field7 = 0;
    role = 0;
    if (gStruct217AA00->field4 == 9) {
        if (gStruct217AA00 != NULL) {
            role = gStruct217AA00->field0;
        }
        if (role == 1) {
            if (dce_2055AFC() != FALSE) {
                sendData->field6_0 |= 4;
            } else {
                sendData->field6_0 &= ~4;
            }
        }
    }
    role = gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0;
    if (role != 1 || (gStruct217AA00->field8B & 1) != 0) {
        if (gStruct217AA00->field15EC == 0) {
            sendData->field6_0 |= 1;
            sendData->field6_0 &= ~2;
        } else {
            sendData->field6_0 |= 2;
            sendData->field6_0 &= ~1;
        }
    }
    sendData->field6_7 = gSpiData->mMicOverThreshold;
    sendData->field2 = spi_getTouchPos();
    result = WM_StepDataSharing(gStruct217AA00->field15BC, sendData, gStruct217AA00->field15C0);
    if (result == 0) {
        if (gStruct217AA00->field4 == 8) {
            gStruct217AA00->field15F7 = 0;
        }
    }
    gStruct217AA00->field15F0 = result;
}

BOOL UpdateDataSharing(void) {
    DataSharing *dataSharing;
    BOOL allRead;
    u16 i;
    u16 j;
    u8 m;
    u8 *sharedData;
    u8 buf[8][8];
    u32 participantMask;
    u32 bit;
    u16 entryIndex;

    dataSharing = &gStruct217AA00->mUnk_15bc_view;
    gStruct217AA00->field1606 = gStruct217AA00->field15BC->mDs[gStruct217AA00->field15BC->mWriteIndex].mArrivedMembers;
    gStruct217AA00->field454 &= ~0x10;
    switch (gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0) {
        case 1:
            if (gStruct217AA00->field44.mChildCount != 0) {
                StepDataSharing();
            } else {
                return FALSE;
            }
            break;
        case 2:
            if (gStruct217AA00->mOwnIndex != 0xffff) {
                StepDataSharing();
            } else {
                return FALSE;
            }
            break;
    }
    switch (gStruct217AA00->field4) {
        case 8:
            if (dataSharing->field34 != 0 && dataSharing->field34 == 5) {
                return FALSE;
            }
            break;
        case 9:
            if (dataSharing->field34 != 0) {
                if (dataSharing->field34 == 5) {
                    return FALSE;
                }
            } else {
                if ((gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0) == 1) {
                    for (j = 1; j < 8; j++) {
                        if ((gStruct217AA00->mParticipantMask & (1 << j)) != 0) {
                            gStruct217AA00->field15F8[j - 1] = 0;
                        }
                    }
                }
            }
            break;
    }
    allRead = TRUE;
    sharedData = WM_GetSharedDataAddress(gStruct217AA00->field15BC, gStruct217AA00->field15C0, 0);
    if (sharedData != NULL) {
        m = sharedData[4];
        if (m != 0) {
            for (i = 0; i < 8; i++) {
                bit = 1 << i;
                participantMask = gStruct217AA00->mParticipantMask;
                entryIndex = gStruct217AA00->field1E52[i].mEntryIndex;
                if ((participantMask & bit) != 0 && (m & bit) != 0) {
                    gStruct217AA00->mParticipantMask = participantMask & ~bit;
                    if (gStruct217AA00->field4 == 9) {
                        rstat_203C2E4(entryIndex);
                    }
                    if ((gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0) == 1) {
                        gStruct217AA00->field1EAC[0] &= ~bit;
                    }
                }
            }
        }
        MI_CpuCopy8(sharedData, &buf[0], 8);
    } else {
        allRead = FALSE;
    }
    if (allRead != FALSE) {
        for (i = 1; i < 8; i++) {
            if ((gStruct217AA00->mParticipantMask & (1 << i)) != 0) {
                sharedData = WM_GetSharedDataAddress(gStruct217AA00->field15BC, gStruct217AA00->field15C0, i);
                if (sharedData != NULL) {
                    MI_CpuCopy8(sharedData, &buf[i], 8);
                } else {
                    allRead = FALSE;
                    break;
                }
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (allRead != FALSE && (gStruct217AA00->mParticipantMask & (1 << i)) != 0) {
            MI_CpuCopy8(&buf[i], &dataSharing->fieldC[i], 8);
            dataSharing->mSharedDataCopied[i] = 1;
        } else {
            dataSharing->mSharedDataCopied[i] = 0;
        }
    }
    return allRead != FALSE;
}

void Initialize(void) {
    gStruct217AA00->fieldC = 1;
    gStruct217AA00->mRequestPending = 1;
    if (WM_Initialize(gStruct217AA00->field14, InitializeCallback, 2) != 2) {
        gStruct217AA00->mRequestPending = 0;
    }
}

void InitializeCallback(Unk021425e8 *event) {
    s32 result;

    result = WM_SetIndCallback(0xf, MPDataPortCallback, NULL);
    gStruct217AA00->mRequestPending = 0;
    if (result != 0) {
        return;
    }
    if (event->mResultCode != 0) {
        return;
    }
    if (gStruct217AA00->field1D00 != 0) {
        WM_SetIndCallback(1, PacketPortCallback, NULL);
    }
    ResetConnectionData();
}

void sub_20533A0(void) {
    u32 role;
    BOOL shouldStop;
    BOOL c;

    if ((gStruct217AA00->field454 & 0x100) != 0) {
        gStruct217AA00->fieldC = 0x26;
        gStruct217AA00->mRequestPending = 1;
        shouldStop = FALSE;
        if ((gStruct217AA00->field454 & 0x40) != 0) {
            c = TRUE;
            role = gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0;
            if (role != 1 && ((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
                c = FALSE;
            }
            if (c != FALSE) {
                shouldStop = TRUE;
            }
        }
        if (shouldStop != FALSE) {
            WFS_End();
            gStruct217AA00->field454 &= ~0x100;
        }
        gStruct217AA00->mRequestPending = 0;
        return;
    }
    if ((gStruct217AA00->field454 & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    gStruct217AA00->fieldC = 2;
    gStruct217AA00->mRequestPending = 1;
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    gStruct217AA00->fieldC = 0x15;
    gStruct217AA00->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    if ((gStruct217AA00->field454 & 0x100) != 0) {
        gStruct217AA00->fieldC = 0x26;
        gStruct217AA00->mRequestPending = 1;
        if (sub_20510E4() != FALSE && (sub_20510C8() == 1 || sub_20510AC() != FALSE)) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        if (c != FALSE) {
            WFS_End();
            gStruct217AA00->field454 &= ~0x100;
        }
        gStruct217AA00->mRequestPending = 0;
        return;
    }
    if ((gStruct217AA00->field454 & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    gStruct217AA00->fieldC = 2;
    gStruct217AA00->mRequestPending = 1;
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    gStruct217AA00->fieldC = 0x15;
    gStruct217AA00->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    if ((gStruct217AA00->field454 & 0x100) != 0) {
        StopRomArchiveTransfer();
        return;
    }
    if ((gStruct217AA00->field454 & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    SetStepAndRequestPending(2);
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    End();
}

void ResetCallback(Unk021425e8 *event) {
    gStruct217AA00->mRequestPending = 0;
    if (event->mResultCode != 0) {
        gStruct217AA00->field8 = 1;
        gStruct217AA00->mRequestPending = 0;
    } else {
        ResetConnectionData();
    }
}

void SetLifeTime(s32 camLifeTime) {
    gStruct217AA00->fieldC = 3;
    gStruct217AA00->mRequestPending = 1;
    if (WM_SetLifeTime(func_0205329c, 0xffff, camLifeTime, 0xffff, 0xf) != 2) {
        sub_20533A0();
    }
}

void func_0205329c(Unk021425e8 *event) {
    gStruct217AA00->mRequestPending = 0;
    if (event->mResultCode != 0) {
        sub_20533A0();
    }
}

// Measures each allowed channel 7 times in a row, in two passes over channels 1 to 14; a is the one just measured.
void MeasureChannel(u16 measuredChannel) {
    u16 allowedChannels;
    u16 channel;
    s32 i;

    gStruct217AA00->fieldC = 4;
    gStruct217AA00->mRequestPending = 1;
    channel = measuredChannel;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0) {
        gStruct217AA00->mRequestPending = 0;
        gStruct217AA00->field8 = 3;
        gStruct217AA00->mRequestPending = 0;
    } else if (allowedChannels == 0x8000) {
        gStruct217AA00->mRequestPending = 0;
        gStruct217AA00->field8 = 8;
        gStruct217AA00->mRequestPending = 0;
    }
    if (channel == 0) {
        gStruct217AA00->field89_0 = 1;
        gStruct217AA00->field89_4 = 1;
        for (i = 1; i < 0xe; i++) {
            gStruct217AA00->field8C[i] = -1;
        }
        channel = 1;
    } else if (gStruct217AA00->field89_0 >= 7) {
        channel = channel + 1;
        gStruct217AA00->field89_0 = 1;
        if (((1 << (channel - 1)) & allowedChannels) == 0) {
            do {
                channel = channel + 1;
                if (channel > 0xe) {
                    if (gStruct217AA00->field89_4 >= 2) {
                        gStruct217AA00->mRequestPending = 0;
                        return;
                    }
                    gStruct217AA00->field89_4 += 1;
                    channel = 1;
                    gStruct217AA00->field89_0 = 1;
                }
            } while (((1 << (channel - 1)) & allowedChannels) == 0);
        }
    } else {
        gStruct217AA00->field89_0 += 1;
    }
    if (WM_MeasureChannel(MeasureChannelCallback, 3, 0x11, channel, 0x14) != 2) {
        sub_20533A0();
    }
}

void MeasureChannelCallback(Unk021425e8 *event) {
    s16 *channelSum;

    if (event->mResultCode != 0) {
        sub_20533A0();
        return;
    }
    channelSum = &gStruct217AA00->field8C[event->field8_0];
    if (*channelSum < 0) {
        *channelSum = 0;
    }
    *channelSum = *channelSum + event->field8_2;
    MeasureChannel(event->field8_0);
}

void *RomArchiveAllocFunc(s32 a, u32 size, void *block) {
    u32 savedInterrupts;
    void *allocated;

    allocated = NULL;
    savedInterrupts = OS_DisableInterrupts();
    if (block != NULL) {
        heap_free(gStruct217AA00->mHeap, block);
    } else {
        allocated = heap_allocEx(gStruct217AA00->mHeap, size, -0x20);
    }
    OS_RestoreInterrupts(savedInterrupts);
    return allocated;
}

void StartRomArchiveTransfer(void) {
    u32 role;
    BOOL c;
    BOOL shouldStart;

    gStruct217AA00->fieldC = 0x24;
    gStruct217AA00->mRequestPending = 1;
    shouldStart = FALSE;
    if ((gStruct217AA00->field454 & 0x40) != 0) {
        c = TRUE;
        role = gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0;
        if (role != 1 && ((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
            c = FALSE;
        }
        if (c != FALSE) {
            shouldStart = TRUE;
        }
    }
    if (shouldStart != FALSE) {
        role = gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0;
        WFS_Init(role == 1 ? 1 : 0, 4, 0x154, RomArchiveStateCallback, RomArchiveAllocFunc, 0);
    }
    gStruct217AA00->mRequestPending = 0;
    ResetPendingFiles();
}

void RomArchiveStateCallback(s32 a) {
    if (gStruct217AA00->fieldC == 0x24) {
        if (WFS_GetStatus() == 2) {
            gStruct217AA00->mRequestPending = 0;
            ResetPendingFiles();
        }
    } else {
        gStruct217AA00->mRequestPending = 0;
    }
}

void func_02052da4(void) {
    u32 role;
    BOOL c;
    BOOL shouldStart;

    gStruct217AA00->fieldC = 0x25;
    gStruct217AA00->mRequestPending = 1;
    shouldStart = FALSE;
    if ((gStruct217AA00->field454 & 0x40) != 0) {
        c = TRUE;
        role = gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0;
        if (role != 1 && ((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
            c = FALSE;
        }
        if (c != FALSE) {
            shouldStart = TRUE;
        }
    }
    if (shouldStart != FALSE) {
        WFS_Start();
        gStruct217AA00->field1E34 = 0;
        gStruct217AA00->field454 |= 0x100;
    }
    gStruct217AA00->mRequestPending = 0;
}

void StopRomArchiveTransfer(void) {
    u32 role;
    BOOL c;
    BOOL shouldStop;

    gStruct217AA00->fieldC = 0x26;
    gStruct217AA00->mRequestPending = 1;
    shouldStop = FALSE;
    if ((gStruct217AA00->field454 & 0x40) != 0) {
        c = TRUE;
        role = gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0;
        if (role != 1 && ((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
            c = FALSE;
        }
        if (c != FALSE) {
            shouldStop = TRUE;
        }
    }
    if (shouldStop != FALSE) {
        WFS_End();
        gStruct217AA00->field454 &= ~0x100;
    }
    gStruct217AA00->mRequestPending = 0;
}

u16 sub_2052C5C(u32 a) {
    RTCTime time;
    u32 h;
    u16 seconds;
    u64 x;
    u64 y;

    GetTime(&time);
    h = time.mHour;
    if (h >= 0x12) {
        h -= 0x12;
    }
    seconds = (h * 0x3c + time.mMinute) * 0x3c + time.mSecond;
    x = OS_GetTickLo() | seconds << 16;
    x = x * 0x5d588b656c078965ull + 0x269ec3;
    y = x >> 32;
    return (u16) (y * 0x10000 >> 32) | 0x8000;
}

// Calls WM_SetParentParameter; also stores 1 in the first session word.
void SetParentParameter(void) {
    gStruct217AA00->field0 = 1;
    gStruct217AA00->fieldC = 5;
    gStruct217AA00->mRequestPending = 1;
    if (WM_SetParentParameter(func_02052bb8, gStruct217AA00->mParentParameter) != 2) {
        sub_20533A0();
    }
}

void func_02052bb8(Unk021425e8 *event) {
    gStruct217AA00->mRequestPending = 0;
    if (event->mResultCode != 0) {
        sub_20533A0();
    }
}

void StartParent(Unk021425e8Func callback) {
    if (callback == NULL) {
        callback = StartParentCallback;
    }
    gStruct217AA00->fieldC = 6;
    gStruct217AA00->mRequestPending = 1;
    if (WM_StartParent(callback) != 2) {
        sub_20533A0();
    }
}

// Callback of WM_StartParent: code 7 adds a child, 9 removes one, 0 copies the own data into the first member record.
void StartParentCallback(Unk021425e8 *event) {
    RandomState64 *randomState;
    u32 role;
    u16 v;
    u32 aid;

    if (event->mResultCode == 0) {
        switch (event->field8_0) {
            case 7:
                AddChild(event->field10, &event->fieldA[0], (Unk0217aa00_45c *) event->field14);
                break;
            case 0:
                MI_CpuCopy8(&gSaveData->mFirstBlock->mPlayerName, &gStruct217AA00->field45C[0], 0x14);
                MI_CpuCopy8(&gSaveData->mFirstBlock->mFlags, &gStruct217AA00->field45C[0].mBits, 4);
                v = 0;
                role = gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0;
                switch (role) {
                    case 1:
                        v = gStruct217AA00->mParentParameter->fieldC;
                        break;
                    case 2:
                        v = gStruct217AA00->field24->field48;
                        break;
                }
                randomState = &gStruct217AA00->field1EE8;
                randomState->mValue = (u32) (v * 3 | v << 16);
                randomState->mMultiplier = 0x5d588b656c078965ull;
                randomState->mIncrement = 0x269ec3;
                gStruct217AA00->mRequestPending = 0;
                break;
            case 9:
                RemoveChild(event->field10);
                aid = event->field10;
                role = gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0;
                if (role == 1 && gStruct217AA00->field4 == 9) {
                    gStruct217AA00->field1EAC[0] |= 1 << aid;
                }
                break;
        }
    } else {
        sub_20533A0();
    }
}
