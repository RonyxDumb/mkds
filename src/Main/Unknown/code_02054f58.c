#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02055710.h"
#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"

static inline u32 func_02055030_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 func_02055030_inline2(void) {
    BOOL r = FALSE;
    if (func_02055030_inline() != 0 && gConnectionWork->mState != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055030_inline3(void) {
    BOOL r = FALSE;
    if (func_02055030_inline2() && !(gConnectionWork->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055030_inline4(void) {
    BOOL r = FALSE;
    if (func_02055030_inline3() && gConnectionWork->mErrorCode != 9) {
        r = TRUE;
    }
    return r;
}

s32 func_02055564(s32 a) {
    s32 status;

    status = 0;
    if (gConnectionWork->mRequestPending != 0) {
        if (gConnectionWork->mStep == 7 && gConnectionWork->mUnk_043b == 1) {
            if (TrySelectScanSlot(a) == 0) {
                SetRequestErrorCode(5);
            }
        }
        return 0;
    }
    if (func_02055030_inline4()) {
        return 3;
    }
    switch (gConnectionWork->mStep) {
        case 7:
            EndScan();
            break;
        case 9:
            StartConnect(NULL, NULL, NULL, func_02055710, NULL);
            break;
        case 2:
        case 10:
            if (gConnectionWork->mOwnIndex == 0xffff) {
                if (gBootInfo->mUnk_00 == 2) {
                    SetRequestErrorCode(5);
                    return 3;
                }
                status = 2;
            } else {
                StartMP();
            }
            break;
        case 11:
            gConnectionWork->mState = 6;
            func_02059878();
            status = 1;
            break;
    }
    return status;
}

s32 func_020554e4(void) {
    if (gConnectionWork->mRequestPending != 0) {
        return 0;
    }
    switch (gConnectionWork->mStep) {
        case 11:
            if (gConnectionWork->mUnk_008b & 8) {
                SetGameInfo();
            }
            break;
        case 15:
            gConnectionWork->mUnk_008b &= ~8;
            gConnectionWork->mStep = 11;
            break;
    }
    return 0;
}

void func_02055340(void) {
    u8 participantMask;
    u8 childMask;
    u8 participantIndex;

    if (!func_02055030_inline2()) {
        return;
    }
    switch (gConnectionWork->mState) {
        case 7:
        case 8:
        case 9:
            if (UpdateDataSharing() == FALSE) {
                gConnectionWork->mUnk_0454 |= 0x10;
            }
            if (gConnectionWork->mState != 9) {
                return;
            }
            if (func_02055030_inline() != 1) {
                return;
            }
            DisconnectRemovedChildren();
            break;
        case 2:
            childMask = gConnectionWork->mUnk_0044.mChildMask;
            participantMask = childMask | 1;
            if (gConnectionWork->mUnk_0044.mUnk_3e >= 8) {
                gConnectionWork->mUnk_0044.mUnk_3e++;
                if ((s32) gConnectionWork->mUnk_0044.mUnk_3e > 0x2c) {
                    gConnectionWork->mUnk_0044.mUnk_3e = 0;
                }
                return;
            }
            participantIndex = gConnectionWork->mUnk_0044.mUnk_3e % 8;
            if (participantMask & (1 << participantIndex)) {
                if (QueueMPDataPlayerName(participantIndex, childMask) == FALSE) {
                    return;
                }
                gConnectionWork->mUnk_0044.mUnk_3e++;
            } else {
                gConnectionWork->mUnk_0044.mUnk_3e++;
            }
            break;
    }
}

s32 AdvanceConnectionEnd(void) {
    BOOL finished;

    finished = FALSE;
    if (gConnectionWork->mState == 0) {
        gConnectionWork->mUnk_0454 &= ~0x80;
        return 1;
    }
    switch (gConnectionWork->mStep) {
        case 0x1d:
        case 0x1e:
            StartRequestEndScan();
            break;
        case 0x22:
            StartCloseScanConnect();
            break;
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2b:
        case 0x2c:
        case 0x2e:
            gConnectionWork->mRequestPending = 0;
            break;
    }
    if (gConnectionWork->mRequestPending != 0 && gConnectionWork->mStep == 7 && gConnectionWork->mUnk_043b == 1) {
        gConnectionWork->mUnk_043b = 0;
    }
    if (gConnectionWork->mRequestPending != 0) {
        return 0;
    }
    if (func_02055030_inline4()) {
        return 3;
    }
    switch (gConnectionWork->mStep) {
        case 38:
            End();
            break;
        case 21:
            gConnectionWork->mStep = 0;
            break;
        case 0:
            ClearParticipantBits();
            gConnectionWork->mState = 0;
            finished = TRUE;
            gConnectionWork->mUnk_0454 &= ~0x80;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 9:
        case 19:
        case 20:
        case 27:
        case 31:
        case 32:
        case 36:
            StopRomArchiveTransfer();
            break;
        case 7:
        case 8:
            EndScan();
            break;
        case 11:
        case 12:
        case 13:
        case 17:
            EndMP();
            break;
        case 6:
        case 10:
        case 16:
        case 18:
            switch (func_02055030_inline()) {
                case 1:
                    EndParent();
                    break;
                case 2:
                    Disconnect();
                    break;
            }
            break;
        case 14:
        case 15:
        case 37:
            EndDataSharing();
            break;
        case 22:
        case 23:
        case 24:
        case 25:
            StartEndToIdle();
            break;
        case 28:
        case 29:
        case 30:
        case 33:
        case 34:
        case 35:
            StartCloseScanConnect();
            break;
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 46:
            StopBlockTransferStep();
            break;
        case 45:
            EndMP();
            break;
        default:
            StopConnection();
            break;
    }
    return finished;
}

s32 func_02054f58(void) {
    s32 status;
    s32 result;

    status = 0;
    result = AdvanceConnectionEnd();
    if (result == 3) {
        switch (gConnectionWork->mStep) {
            case 0x16:
            case 0x17:
            case 0x18:
            case 0x19:
                StartEndToIdle();
                break;
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2a:
            case 0x2b:
            case 0x2c:
            case 0x2e:
                StopBlockTransferStep();
                break;
            case 0x1c:
            case 0x1d:
            case 0x1e:
            case 0x21:
            case 0x22:
            case 0x23:
                StartCloseScanConnect();
                break;
            default:
                StopConnection();
                break;
        }
        gConnectionWork->mErrorCode = 9;
    } else {
        status = result;
    }
    return status;
}
