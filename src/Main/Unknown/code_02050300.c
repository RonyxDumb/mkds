#include "Main/Unknown/code_02050300.h"

#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_02142eac.h"
#include "code_021445e0.h"
#include "code_0214d018.h"

static inline u32 func_02050650_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

void DisconnectChildren(u32 aidBitmap) {
    gStruct217AA00->fieldC = 0x10;
    gStruct217AA00->mRequestPending = 1;
    if (WM_DisconnectChildren(DisconnectChildrenCallback, aidBitmap) != 7) {
        return;
    }
    if (gStruct217AA00->field4 == 9) {
        if (func_02050650_inline() == 1) {
            gStruct217AA00->field8A = 0;
        }
    }
    gStruct217AA00->mRequestPending = 0;
}

void DisconnectChildrenCallback(Unk021425e8 *event) {
    gStruct217AA00->mRequestPending = 0;
    if (event->mResultCode != 0 && event->mResultCode != 7) {
        return;
    }
    if (func_02050650_inline() == 1) {
        switch (gStruct217AA00->field4) {
            case 8:
            case 9:
                gStruct217AA00->field1EAC[0] = gStruct217AA00->field1EAC[0] | gStruct217AA00->field8A;
                break;
        }
    }
    gStruct217AA00->field8A = 0;
}

void EndDataSharing(void) {
    s32 result;

    gStruct217AA00->fieldC = 0x11;
    gStruct217AA00->mRequestPending = 1;
    result = WM_EndDataSharing(gStruct217AA00->field15BC);
    gStruct217AA00->mRequestPending = 0;
    if (result == 0) {
        return;
    }
    func_020533a0();
}

void EndMP(void) {
    gStruct217AA00->fieldC = 0x12;
    gStruct217AA00->mRequestPending = 1;
    if (WM_EndMP(EndMPCallback) == 2) {
        return;
    }
    func_020533a0();
}

void EndMPCallback(Unk021425e8 *event) {
    ConnectionWork *connection;

    gStruct217AA00->mRequestPending = 0;
    gStruct217AA00->field454 &= ~1;
    if (event->mResultCode != 0) {
        func_020533a0();
        return;
    }
    connection = gStruct217AA00;
    if (connection->field4 == 0xb) {
        connection->field4 = 0xc;
    }
}

void EndParent(void) {
    gStruct217AA00->fieldC = 0x13;
    gStruct217AA00->mRequestPending = 1;
    if (WM_EndParent(EndParentCallback) == 2) {
        return;
    }
    func_020533a0();
}

void EndParentCallback(Unk021425e8 *event) {
    gStruct217AA00->mRequestPending = 0;
    if (event->mResultCode != 0) {
        func_020533a0();
    } else {
        ResetConnectionData();
    }
}

void Disconnect(void) {
    s32 result;
    s32 i;
    ChildList *children;
    ChildEntry *child;

    result = 7;
    children = &gStruct217AA00->field44;
    switch (func_02050650_inline()) {
        case 1:
            for (i = 0, child = children->mEntries; i < children->mChildCount; i++, child++) {
                if (child->mAid != 0xffff) {
                    gStruct217AA00->field44.mDisconnectingIndex = i;
                    gStruct217AA00->fieldC = 0x14;
                    gStruct217AA00->mRequestPending = 1;
                    result = WM_Disconnect(DisconnectCallback, child->mAid);
                    break;
                }
            }
            break;
        case 2:
            gStruct217AA00->fieldC = 0x14;
            gStruct217AA00->mRequestPending = 1;
            result = WM_Disconnect(DisconnectCallback, 0);
            break;
    }
    switch (result) {
        case 0:
        case 7:
            gStruct217AA00->mRequestPending = 0;
            break;
        case 2:
            if (func_02050650_inline() == 2) {
                gStruct217AA00->field436 |= 2;
            }
            break;
        default:
            func_020533a0();
            break;
    }
}

void DisconnectCallback(Unk021425e8 *event) {
    u16 aid;

    switch (event->mResultCode) {
        case 0:
        case 7:
            gStruct217AA00->mRequestPending = 0;
            switch (gStruct217AA00->field0) {
                case 1:
                    aid = gStruct217AA00->field44.mEntries[gStruct217AA00->field44.mDisconnectingIndex].mAid;
                    RemoveChild(aid);
                    if (func_02050650_inline() == 1) {
                        if (gStruct217AA00->field4 == 9) {
                            gStruct217AA00->field1EAC[0] |= 1 << aid;
                        }
                    }
                    gStruct217AA00->field44.mDisconnectingIndex = -1;
                    break;
                case 2:
                    gStruct217AA00->field436 &= ~2;
                    ResetConnectionData();
                    break;
            }
            break;
        case 1:
            if ((gStruct217AA00->field436 & 2) != 0) {
                gStruct217AA00->field436 &= ~2;
                ResetConnectionData();
                gStruct217AA00->mRequestPending = 0;
            } else {
                func_020533a0();
            }
            break;
        default:
            func_020533a0();
            break;
    }
}

BOOL func_020510e4(void) {
    return (gStruct217AA00->field454 & 0x40) != 0;
}

s32 func_020510c8(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

static inline u32 func_02050ec0_inline(void) {
    return func_020510e4() != FALSE && (func_020510c8() == 1 || func_020510ac() != FALSE);
}

BOOL func_020510ac(void) {
    return *(u16 *) 0x027ffc40 == 2;
}

void SetStepAndRequestPending(s32 a) {
    gStruct217AA00->fieldC = a;
    gStruct217AA00->mRequestPending = 1;
}

// WM_End first; when it does not return 2, the 0x100 and 0x200 flag paths or WM_Reset run instead.
void End(void) {
    ConnectionWork *connection;
    u32 flags;

    gStruct217AA00->fieldC = 0x15;
    gStruct217AA00->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    connection = gStruct217AA00;
    flags = connection->field454;
    if ((flags & 0x100) != 0) {
        connection->fieldC = 0x26;
        gStruct217AA00->mRequestPending = 1;
        if (func_02050ec0_inline() != 0) {
            WFS_End();
            gStruct217AA00->field454 &= ~0x100;
        }
        gStruct217AA00->mRequestPending = 0;
        return;
    }
    if ((flags & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    connection->fieldC = 2;
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

void EndCallback(Unk021425e8 *event) {
    gStruct217AA00->mRequestPending = 0;
    if (event->mResultCode != 0) {
        gStruct217AA00->field8 = 8;
        gStruct217AA00->mRequestPending = 0;
    } else {
        gStruct217AA00->field0 = 0;
    }
}

void func_02050e60(s32 a) {
    gStruct217AA00->field8 = a;
    gStruct217AA00->mRequestPending = 0;
}

void AddChild(u32 aid, u8 *b, Unk0217aa00_45c *playerEntry) {
    ChildList *children;

    children = &gStruct217AA00->field44;
    if (children->mChildCount >= 7) {
        return;
    }
    children->mEntries[aid - 1].mAid = aid;
    children->mChildCount += 1;
    children->mChildMask |= 1 << aid;
    children->mEntries[0].field0[0] = b[0];
    children->mEntries[0].field0[1] = b[1];
    children->mEntries[0].field0[2] = b[2];
    children->mEntries[0].field0[3] = b[3];
    children->mEntries[0].field0[4] = b[4];
    children->mEntries[0].field0[5] = b[5];
    MI_CpuCopy8(playerEntry, &gStruct217AA00->field45C[aid], 0x14);
    gStruct217AA00->field8B |= 8;
    if ((playerEntry->field14 & 1) != 0) {
        gStruct217AA00->field457 |= 1 << aid;
    }
}

static inline void func_0205081c_inline2(u16 v) {
    MPStateMachine *p = &gStruct217AA00->field1608;
    p->mNextState = v;
    p->mNextStateRequested = 1;
}

static inline void func_0205081c_inline(u8 v) {
    u32 r = 0;
    u32 b;

    if ((gStruct217AA00->field454 & 0x40) != 0) {
        b = 1;
        if (func_02050650_inline() != 1) {
            if (*(u16 *) 0x027ffc40 != 2) {
                b = 0;
            }
        }
        if (b != 0) {
            r = 1;
        }
    }
    if (r == 0) {
        return;
    }
    if (func_02050650_inline() != 1) {
        return;
    }
    WFS_EnableSync(v);
}

static inline void func_02050b88_inline(u16 v1) {
    u16 i;
    u32 f;

    for (i = 0; i < 8; i++) {
        if ((v1 & (1 << i)) != 0) {
            f = gStruct217AA00->field4 == 9 ? 1 : 0;
            if (func_02050650_inline() == 1) {
                gStruct217AA00->field44.mChildMask &= ~(1 << i);
                if (f != 0) {
                    gStruct217AA00->field8A |= 1 << i;
                }
            }
            gStruct217AA00->field457 &= ~(1 << i);
        }
    }
    if (func_02050650_inline() != 1) {
        return;
    }
    if ((gStruct217AA00->field454 & 0x100) == 0) {
        return;
    }
    func_0205081c_inline(gStruct217AA00->field457);
}

void RemoveChild(u32 aid) {
    ChildList *children;

    children = &gStruct217AA00->field44;
    if (children->mEntries[aid - 1].mAid == 0xffff) {
        return;
    }
    children->mEntries[aid - 1].mAid = 0xffff;
    children->mChildCount -= 1;
    func_02050b88_inline(1 << aid);
    gStruct217AA00->field8B |= 8;
    switch (gStruct217AA00->field4) {
        case 9:
            if (children->mChildCount < 1) {
                gStruct217AA00->field8 = 0;
                gStruct217AA00->mRequestPending = 0;
            }
            break;
        case 7:
        case 8:
            gStruct217AA00->field8 = 0;
            gStruct217AA00->mRequestPending = 0;
            break;
    }
}

void ProcessMPData(u32 aid, MPMessage *message) {
    switch (message->mKind) {
        case 3:
            gStruct217AA00->field1D54 &= ~(1 << aid);
            break;
        case 4:
            gStruct217AA00->field1D54 |= 1 << aid;
            if (gStruct217AA00->field1D54 == gStruct217AA00->field44.mChildMask) {
                gStruct217AA00->mRequestPending = 0;
            }
            break;
        case 5:
            gStruct217AA00->field1E44 |= 2;
            gStruct217AA00->mRequestPending = 0;
            break;
        case 1:
            gStruct217AA00->mParticipantMask = message->field4;
            func_02050080();
            func_02058b10();
            break;
        case 2:
            if (func_02050650_inline() == 2) {
                gStruct217AA00->field457 = message->field4;
            }
            func_0205081c_inline2(1);
            break;
        case 6:
            switch (gStruct217AA00->field4) {
                case 6:
                    func_020559ec(message->field2, message->field16, message->field17);
                    break;
                case 0xa:
                    func_020597d0(message->field2, (u8) aid, message->field16, message->field17);
                    break;
            }
            break;
        case 9:
            if ((gStruct217AA00->field164D & (1 << message->fieldA)) != 0) {
                return;
            }
            MI_CpuCopy8(message->field2, gStruct217AA00->field45C[message->fieldA].mBits, 4);
            gStruct217AA00->field164D |= 1 << message->fieldA;
            break;
        case 7:
            func_02050b88_inline(message->field4);
            break;
        case 8:
            gStruct217AA00->field1EB0 = message->field4;
            break;
    }
}

void MPDataPortCallback(Unk021425e8 *event) {
    MPMessage message;

    if (event->mResultCode != 0) {
        return;
    }
    if (event->fieldC == 0) {
        return;
    }
    if (event->field10 < 2) {
        return;
    }
    if (event->field10 > 0x18) {
        return;
    }
    DC_InvalidateRange(event->fieldC, event->field10);
    MI_CpuCopy8(event->fieldC, &message, event->field10);
    if (event->field4 == 7) {
        return;
    }
    if (event->field4 == 9) {
        return;
    }
    if (event->field4 != 0x15) {
        return;
    }
    ProcessMPData(event->field12, &message);
}

BOOL QueueMPDataToPort(void *data, s32 dataSize, u16 destBitmap, void *sendBuffer, QueueMPDataToPortParams *params) {
    u16 sendSize;

    sendSize = dataSize;
    switch (func_02050650_inline()) {
        case 1:
            if (gStruct217AA00->field44.mChildMask == 0) {
                return FALSE;
            }
            break;
        case 2:
            if (gStruct217AA00->mOwnIndex == 0xffff) {
                return FALSE;
            }
            break;
    }
    if (sendSize > params->mMaxDataSize) {
        sendSize = params->mMaxDataSize;
    }
    DC_FlushRange(data, sendSize);
    if (sendBuffer == NULL) {
        sendBuffer = data;
    } else {
        MI_CpuCopy8(data, sendBuffer, sendSize);
        DC_FlushRange(sendBuffer, sendSize);
    }
    if (WM_SetMPDataToPortEx(params->mCallback, NULL, sendBuffer, sendSize, destBitmap, params->mPort,
                             params->mPriority) != 2) {
        return FALSE;
    }
    return TRUE;
}

BOOL QueueMPDataHalfword(s32 kind, u16 destBitmap) {
    u16 halfword;

    halfword = kind;
    if ((gStruct217AA00->field454 & 1) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gStruct217AA00->field454 &= ~1;
    if (QueueMPDataToPort(&halfword, 2, destBitmap, gStruct217AA00->field40, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gStruct217AA00->field454 |= 1;
    return FALSE;
}

BOOL func_020504a4(s32 playerIndex, u16 destBitmap) {
    Unk020504a4 message;

    message.field0 = 6;
    MI_CpuCopy8(&gStruct217AA00->field45C[playerIndex], message.field2, 0x14);
    message.field16 = playerIndex;
    if (func_02050650_inline() == 1) {
        message.field17 = gStruct217AA00->field44.mChildMask | 1;
    } else {
        message.field17 = 0;
    }
    if ((gStruct217AA00->field454 & 1) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gStruct217AA00->field454 &= ~1;
    if (QueueMPDataToPort(&message, 0x18, destBitmap, gStruct217AA00->field40, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gStruct217AA00->field454 |= 1;
    return FALSE;
}

BOOL func_020503cc(s32 playerIndex, u16 destBitmap) {
    Unk020503cc message;

    message.field0 = 9;
    MI_CpuCopy8(gStruct217AA00->field45C[playerIndex].mBits, message.field2, 4);
    message.fieldA = playerIndex;
    if ((gStruct217AA00->field454 & 1) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gStruct217AA00->field454 &= ~1;
    if (QueueMPDataToPort(&message, 0x12, destBitmap, gStruct217AA00->field40, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gStruct217AA00->field454 |= 1;
    return FALSE;
}

BOOL QueueMPDataHalfwordAndWord(s32 kind, u16 destBitmap, s32 word) {
    Unk02050320 message;

    message.field0 = kind;
    message.field4 = word;
    if ((gStruct217AA00->field454 & 1) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gStruct217AA00->field454 &= ~1;
    if (QueueMPDataToPort(&message, 8, destBitmap, gStruct217AA00->field40, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gStruct217AA00->field454 |= 1;
    return FALSE;
}

u32 QueueMPDataToPortCallback(void) {
    u32 value0;
    u32 flags;
    value0 = (u32) &gStruct217AA00;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = (value0) + (0x400u);
    flags = *(const u16 *) ((value0) + (84));
    flags = (flags) | (1u);
    *(u16 *) ((value0) + (84)) = flags;
    return value0;
}
