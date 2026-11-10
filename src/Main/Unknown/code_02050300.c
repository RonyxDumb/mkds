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
#include "Main/Unknown/code_0211d4a8.h"

static inline u32 func_02050650_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mUnk_0000;
}

void DisconnectChildren(u32 aidBitmap) {
    gConnectionWork->mUnk_000c = 0x10;
    gConnectionWork->mRequestPending = 1;
    if (WM_DisconnectChildren(DisconnectChildrenCallback, aidBitmap) != 7) {
        return;
    }
    if (gConnectionWork->mState == 9) {
        if (func_02050650_inline() == 1) {
            gConnectionWork->mRemovedChildMask = 0;
        }
    }
    gConnectionWork->mRequestPending = 0;
}

void DisconnectChildrenCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0 && event->mResultCode != 7) {
        return;
    }
    if (func_02050650_inline() == 1) {
        switch (gConnectionWork->mState) {
            case 8:
            case 9:
                gConnectionWork->mUnk_1eac[0] = gConnectionWork->mUnk_1eac[0] | gConnectionWork->mRemovedChildMask;
                break;
        }
    }
    gConnectionWork->mRemovedChildMask = 0;
}

void EndDataSharing(void) {
    s32 result;

    gConnectionWork->mUnk_000c = 0x11;
    gConnectionWork->mRequestPending = 1;
    result = WM_EndDataSharing(gConnectionWork->mUnk_15bc);
    gConnectionWork->mRequestPending = 0;
    if (result == 0) {
        return;
    }
    func_020533a0();
}

void EndMP(void) {
    gConnectionWork->mUnk_000c = 0x12;
    gConnectionWork->mRequestPending = 1;
    if (WM_EndMP(EndMPCallback) == 2) {
        return;
    }
    func_020533a0();
}

void EndMPCallback(Unk021425e8 *event) {
    ConnectionWork *connection;

    gConnectionWork->mRequestPending = 0;
    gConnectionWork->mUnk_0454 &= ~1;
    if (event->mResultCode != 0) {
        func_020533a0();
        return;
    }
    connection = gConnectionWork;
    if (connection->mState == 0xb) {
        connection->mState = 0xc;
    }
}

void EndParent(void) {
    gConnectionWork->mUnk_000c = 0x13;
    gConnectionWork->mRequestPending = 1;
    if (WM_EndParent(EndParentCallback) == 2) {
        return;
    }
    func_020533a0();
}

void EndParentCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
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
    children = &gConnectionWork->mUnk_0044;
    switch (func_02050650_inline()) {
        case 1:
            for (i = 0, child = children->mEntries; i < children->mChildCount; i++, child++) {
                if (child->mAid != 0xffff) {
                    gConnectionWork->mUnk_0044.mDisconnectingIndex = i;
                    gConnectionWork->mUnk_000c = 0x14;
                    gConnectionWork->mRequestPending = 1;
                    result = WM_Disconnect(DisconnectCallback, child->mAid);
                    break;
                }
            }
            break;
        case 2:
            gConnectionWork->mUnk_000c = 0x14;
            gConnectionWork->mRequestPending = 1;
            result = WM_Disconnect(DisconnectCallback, 0);
            break;
    }
    switch (result) {
        case 0:
        case 7:
            gConnectionWork->mRequestPending = 0;
            break;
        case 2:
            if (func_02050650_inline() == 2) {
                gConnectionWork->mUnk_0436 |= 2;
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
            gConnectionWork->mRequestPending = 0;
            switch (gConnectionWork->mUnk_0000) {
                case 1:
                    aid = gConnectionWork->mUnk_0044.mEntries[gConnectionWork->mUnk_0044.mDisconnectingIndex].mAid;
                    RemoveChild(aid);
                    if (func_02050650_inline() == 1) {
                        if (gConnectionWork->mState == 9) {
                            gConnectionWork->mUnk_1eac[0] |= 1 << aid;
                        }
                    }
                    gConnectionWork->mUnk_0044.mDisconnectingIndex = -1;
                    break;
                case 2:
                    gConnectionWork->mUnk_0436 &= ~2;
                    ResetConnectionData();
                    break;
            }
            break;
        case 1:
            if ((gConnectionWork->mUnk_0436 & 2) != 0) {
                gConnectionWork->mUnk_0436 &= ~2;
                ResetConnectionData();
                gConnectionWork->mRequestPending = 0;
            } else {
                func_020533a0();
            }
            break;
        default:
            func_020533a0();
            break;
    }
}

BOOL IsWMInitializeStarted(void) {
    return (gConnectionWork->mUnk_0454 & 0x40) != 0;
}

s32 func_020510c8(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mUnk_0000;
}

static inline u32 func_02050ec0_inline(void) {
    return IsWMInitializeStarted() != FALSE && (func_020510c8() == 1 || func_020510ac() != FALSE);
}

BOOL func_020510ac(void) {
    return gBootInfo->mUnk_00 == 2;
}

void SetStepAndRequestPending(s32 a) {
    gConnectionWork->mUnk_000c = a;
    gConnectionWork->mRequestPending = 1;
}

// WM_End first; when it does not return 2, the 0x100 and 0x200 flag paths or WM_Reset run instead.
void End(void) {
    ConnectionWork *connection;
    u32 flags;

    gConnectionWork->mUnk_000c = 0x15;
    gConnectionWork->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    connection = gConnectionWork;
    flags = connection->mUnk_0454;
    if ((flags & 0x100) != 0) {
        connection->mUnk_000c = 0x26;
        gConnectionWork->mRequestPending = 1;
        if (func_02050ec0_inline() != 0) {
            StopRomArchive();
            gConnectionWork->mUnk_0454 &= ~0x100;
        }
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if ((flags & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    connection->mUnk_000c = 2;
    gConnectionWork->mRequestPending = 1;
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    gConnectionWork->mUnk_000c = 0x15;
    gConnectionWork->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    if ((gConnectionWork->mUnk_0454 & 0x100) != 0) {
        StopRomArchiveTransfer();
        return;
    }
    if ((gConnectionWork->mUnk_0454 & 0x200) != 0) {
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
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0) {
        gConnectionWork->mUnk_0008 = 8;
        gConnectionWork->mRequestPending = 0;
    } else {
        gConnectionWork->mUnk_0000 = 0;
    }
}

void func_02050e60(s32 a) {
    gConnectionWork->mUnk_0008 = a;
    gConnectionWork->mRequestPending = 0;
}

void AddChild(u32 aid, u8 *b, PlayerRecord *playerEntry) {
    ChildList *children;

    children = &gConnectionWork->mUnk_0044;
    if (children->mChildCount >= 7) {
        return;
    }
    children->mEntries[aid - 1].mAid = aid;
    children->mChildCount += 1;
    children->mChildMask |= 1 << aid;
    children->mEntries[0].mUnk_00[0] = b[0];
    children->mEntries[0].mUnk_00[1] = b[1];
    children->mEntries[0].mUnk_00[2] = b[2];
    children->mEntries[0].mUnk_00[3] = b[3];
    children->mEntries[0].mUnk_00[4] = b[4];
    children->mEntries[0].mUnk_00[5] = b[5];
    MI_CpuCopy8(playerEntry, &gConnectionWork->mUnk_045c[aid], 0x14);
    gConnectionWork->mUnk_008b |= 8;
    if ((playerEntry->mEmblem[0] & 1) != 0) {
        gConnectionWork->mUnk_0457 |= 1 << aid;
    }
}

static inline void func_0205081c_inline2(u16 v) {
    MPStateMachine *p = &gConnectionWork->mUnk_1608;
    p->mStateMachine.mNextState = v;
    p->mStateMachine.mNextStateRequested = 1;
}

static inline void func_0205081c_inline(u8 v) {
    u32 r = 0;
    u32 b;

    if ((gConnectionWork->mUnk_0454 & 0x40) != 0) {
        b = 1;
        if (func_02050650_inline() != 1) {
            if (gBootInfo->mUnk_00 != 2) {
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
    func_0204bcb4(v);
}

static inline void func_02050b88_inline(u16 v1) {
    u16 i;
    u32 f;

    for (i = 0; i < 8; i++) {
        if ((v1 & (1 << i)) != 0) {
            f = gConnectionWork->mState == 9 ? 1 : 0;
            if (func_02050650_inline() == 1) {
                gConnectionWork->mUnk_0044.mChildMask &= ~(1 << i);
                if (f != 0) {
                    gConnectionWork->mRemovedChildMask |= 1 << i;
                }
            }
            gConnectionWork->mUnk_0457 &= ~(1 << i);
        }
    }
    if (func_02050650_inline() != 1) {
        return;
    }
    if ((gConnectionWork->mUnk_0454 & 0x100) == 0) {
        return;
    }
    func_0205081c_inline(gConnectionWork->mUnk_0457);
}

void RemoveChild(u32 aid) {
    ChildList *children;

    children = &gConnectionWork->mUnk_0044;
    if (children->mEntries[aid - 1].mAid == 0xffff) {
        return;
    }
    children->mEntries[aid - 1].mAid = 0xffff;
    children->mChildCount -= 1;
    func_02050b88_inline(1 << aid);
    gConnectionWork->mUnk_008b |= 8;
    switch (gConnectionWork->mState) {
        case 9:
            if (children->mChildCount < 1) {
                gConnectionWork->mUnk_0008 = 0;
                gConnectionWork->mRequestPending = 0;
            }
            break;
        case 7:
        case 8:
            gConnectionWork->mUnk_0008 = 0;
            gConnectionWork->mRequestPending = 0;
            break;
    }
}

void ProcessMPData(u32 aid, MPMessage *message) {
    switch (message->mKind) {
        case 3:
            gConnectionWork->mUnk_1d54 &= ~(1 << aid);
            break;
        case 4:
            gConnectionWork->mUnk_1d54 |= 1 << aid;
            if (gConnectionWork->mUnk_1d54 == gConnectionWork->mUnk_0044.mChildMask) {
                gConnectionWork->mRequestPending = 0;
            }
            break;
        case 5:
            gConnectionWork->mUnk_1e44 |= 2;
            gConnectionWork->mRequestPending = 0;
            break;
        case 1:
            gConnectionWork->mParticipantMask = message->mUnk_04;
            func_02050080();
            func_02058b10();
            break;
        case 2:
            if (func_02050650_inline() == 2) {
                gConnectionWork->mUnk_0457 = message->mUnk_04;
            }
            func_0205081c_inline2(1);
            break;
        case 6:
            switch (gConnectionWork->mState) {
                case 6:
                    func_020559ec(message->mUnk_02, message->mUnk_16, message->mUnk_17);
                    break;
                case 0xa:
                    func_020597d0(message->mUnk_02, (u8) aid, message->mUnk_16, message->mUnk_17);
                    break;
            }
            break;
        case 9:
            if ((gConnectionWork->mUnk_164d & (1 << message->mUnk_0a)) != 0) {
                return;
            }
            MI_CpuCopy8(message->mUnk_02, gConnectionWork->mUnk_045c[message->mUnk_0a].mBits, 4);
            gConnectionWork->mUnk_164d |= 1 << message->mUnk_0a;
            break;
        case 7:
            func_02050b88_inline(message->mUnk_04);
            break;
        case 8:
            gConnectionWork->mUnk_1eb0 = message->mUnk_04;
            break;
    }
}

void MPDataPortCallback(Unk021425e8 *event) {
    MPMessage message;

    if (event->mResultCode != 0) {
        return;
    }
    if (event->mUnk_0c == 0) {
        return;
    }
    if (event->mUnk_10 < 2) {
        return;
    }
    if (event->mUnk_10 > 0x18) {
        return;
    }
    DC_InvalidateRange(event->mUnk_0c, event->mUnk_10);
    MI_CpuCopy8(event->mUnk_0c, &message, event->mUnk_10);
    if (event->mUnk_04 == 7) {
        return;
    }
    if (event->mUnk_04 == 9) {
        return;
    }
    if (event->mUnk_04 != 0x15) {
        return;
    }
    ProcessMPData(event->mUnk_12, &message);
}

BOOL QueueMPDataToPort(void *data, s32 dataSize, u16 destBitmap, void *sendBuffer, QueueMPDataToPortParams *params) {
    u16 sendSize;

    sendSize = dataSize;
    switch (func_02050650_inline()) {
        case 1:
            if (gConnectionWork->mUnk_0044.mChildMask == 0) {
                return FALSE;
            }
            break;
        case 2:
            if (gConnectionWork->mOwnIndex == 0xffff) {
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
    if ((gConnectionWork->mUnk_0454 & 1) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gConnectionWork->mUnk_0454 &= ~1;
    if (QueueMPDataToPort(&halfword, 2, destBitmap, gConnectionWork->mUnk_0040, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mUnk_0454 |= 1;
    return FALSE;
}

BOOL func_020504a4(s32 playerIndex, u16 destBitmap) {
    Unk020504a4 message;

    message.mUnk_00 = 6;
    MI_CpuCopy8(&gConnectionWork->mUnk_045c[playerIndex], message.mUnk_02, 0x14);
    message.mUnk_16 = playerIndex;
    if (func_02050650_inline() == 1) {
        message.mUnk_17 = gConnectionWork->mUnk_0044.mChildMask | 1;
    } else {
        message.mUnk_17 = 0;
    }
    if ((gConnectionWork->mUnk_0454 & 1) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gConnectionWork->mUnk_0454 &= ~1;
    if (QueueMPDataToPort(&message, 0x18, destBitmap, gConnectionWork->mUnk_0040, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mUnk_0454 |= 1;
    return FALSE;
}

BOOL func_020503cc(s32 playerIndex, u16 destBitmap) {
    Unk020503cc message;

    message.mUnk_00 = 9;
    MI_CpuCopy8(gConnectionWork->mUnk_045c[playerIndex].mBits, message.mUnk_02, 4);
    message.mUnk_0a = playerIndex;
    if ((gConnectionWork->mUnk_0454 & 1) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gConnectionWork->mUnk_0454 &= ~1;
    if (QueueMPDataToPort(&message, 0x12, destBitmap, gConnectionWork->mUnk_0040, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mUnk_0454 |= 1;
    return FALSE;
}

BOOL QueueMPDataHalfwordAndWord(s32 kind, u16 destBitmap, s32 word) {
    Unk02050320 message;

    message.mUnk_00 = kind;
    message.mUnk_04 = word;
    if ((gConnectionWork->mUnk_0454 & 1) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gConnectionWork->mUnk_0454 &= ~1;
    if (QueueMPDataToPort(&message, 8, destBitmap, gConnectionWork->mUnk_0040, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mUnk_0454 |= 1;
    return FALSE;
}

void QueueMPDataToPortCallback(void) {
    gConnectionWork->mUnk_0454 |= 1;
}
