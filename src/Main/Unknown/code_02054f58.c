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
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

static inline s32 func_02055030_inline2(void) {
    BOOL r = FALSE;
    if (func_02055030_inline() != 0 && gStruct217AA00->field4 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055030_inline3(void) {
    BOOL r = FALSE;
    if (func_02055030_inline2() && !(gStruct217AA00->field454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055030_inline4(void) {
    BOOL r = FALSE;
    if (func_02055030_inline3() && gStruct217AA00->field8 != 9) {
        r = TRUE;
    }
    return r;
}

s32 func_02055564(s32 a) {
    s32 status;

    status = 0;
    if (gStruct217AA00->mRequestPending != 0) {
        if (gStruct217AA00->fieldC == 7 && gStruct217AA00->field43B == 1) {
            if (func_020501b0(a) == 0) {
                func_02050e60(5);
            }
        }
        return 0;
    }
    if (func_02055030_inline4()) {
        return 3;
    }
    switch (gStruct217AA00->fieldC) {
        case 7:
            EndScan();
            break;
        case 9:
            StartConnect(NULL, NULL, NULL, func_02055710, NULL);
            break;
        case 2:
        case 10:
            if (gStruct217AA00->mOwnIndex == 0xffff) {
                if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
                    func_02050e60(5);
                    return 3;
                }
                status = 2;
            } else {
                StartMP();
            }
            break;
        case 11:
            gStruct217AA00->field4 = 6;
            func_02059878();
            status = 1;
            break;
    }
    return status;
}

s32 func_020554e4(void) {
    if (gStruct217AA00->mRequestPending != 0) {
        return 0;
    }
    switch (gStruct217AA00->fieldC) {
        case 11:
            if (gStruct217AA00->field8B & 8) {
                SetGameInfo();
            }
            break;
        case 15:
            gStruct217AA00->field8B &= ~8;
            gStruct217AA00->fieldC = 11;
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
    switch (gStruct217AA00->field4) {
        case 7:
        case 8:
        case 9:
            if (UpdateDataSharing() == FALSE) {
                gStruct217AA00->field454 |= 0x10;
            }
            if (gStruct217AA00->field4 != 9) {
                return;
            }
            if (func_02055030_inline() != 1) {
                return;
            }
            func_02001000();
            break;
        case 2:
            childMask = gStruct217AA00->field44.mChildMask;
            participantMask = childMask | 1;
            if (gStruct217AA00->field44.field3E >= 8) {
                gStruct217AA00->field44.field3E++;
                if ((s32) gStruct217AA00->field44.field3E > 0x2c) {
                    gStruct217AA00->field44.field3E = 0;
                }
                return;
            }
            participantIndex = gStruct217AA00->field44.field3E % 8;
            if (participantMask & (1 << participantIndex)) {
                if (func_020504a4(participantIndex, childMask) == FALSE) {
                    return;
                }
                gStruct217AA00->field44.field3E++;
            } else {
                gStruct217AA00->field44.field3E++;
            }
            break;
    }
}

s32 AdvanceConnectionEnd(void) {
    BOOL finished;

    finished = FALSE;
    if (gStruct217AA00->field4 == 0) {
        gStruct217AA00->field454 &= ~0x80;
        return 1;
    }
    switch (gStruct217AA00->fieldC) {
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
            gStruct217AA00->mRequestPending = 0;
            break;
    }
    if (gStruct217AA00->mRequestPending != 0 && gStruct217AA00->fieldC == 7 && gStruct217AA00->field43B == 1) {
        gStruct217AA00->field43B = 0;
    }
    if (gStruct217AA00->mRequestPending != 0) {
        return 0;
    }
    if (func_02055030_inline4()) {
        return 3;
    }
    switch (gStruct217AA00->fieldC) {
        case 38:
            End();
            break;
        case 21:
            gStruct217AA00->fieldC = 0;
            break;
        case 0:
            ClearParticipantBits();
            gStruct217AA00->field4 = 0;
            finished = TRUE;
            gStruct217AA00->field454 &= ~0x80;
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
            func_0204e090();
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
            func_0204eca0();
            break;
        case 45:
            EndMP();
            break;
        default:
            func_020533a0();
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
        switch (gStruct217AA00->fieldC) {
            case 0x16:
            case 0x17:
            case 0x18:
            case 0x19:
                func_0204e090();
                break;
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2a:
            case 0x2b:
            case 0x2c:
            case 0x2e:
                func_0204eca0();
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
                func_020533a0();
                break;
        }
        gStruct217AA00->field8 = 9;
    } else {
        status = result;
    }
    return status;
}
