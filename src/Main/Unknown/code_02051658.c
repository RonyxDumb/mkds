#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_020204c0.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_02051640.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_021445e0.h"
#include "wm_etc.h"
#include "code_02142eac.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0211d4a8.h"

static inline u32 func_02051658_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

void StartScan(s32 a, s32 (*b)(), s32 (*c)()) {
    ConnectionWork *connection;
    Unk0217aa00_ac *s;
    Unk02143a78 *scanParams;
    u16 channel;
    s32 i;
    u16 allowedChannels;

    connection = gConnectionWork;
    s = &connection->mUnk_00ac_view;
    channel = s->mUnk_38d;
    scanParams = connection->mUnk_001c;
    connection->mConnectionMode = 2;
    gConnectionWork->mStep = 7;
    gConnectionWork->mRequestPending = 1;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mErrorCode = 3;
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if (allowedChannels == 0x8000) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mErrorCode = 8;
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if (s->mUnk_38c == 0) {
        if (((1 << (channel - 1)) & allowedChannels) == 0) {
            do {
                channel = channel + 1;
                if (channel > 0xe) {
                    channel = 1;
                }
            } while (((1 << (channel - 1)) & allowedChannels) == 0);
        }
        scanParams->mUnk_04 = channel;
        s->mUnk_38d = channel;
        for (i = 0; i < 6; i++) {
            scanParams->mUnk_08[i] = 0xff;
        }
    } else {
        scanParams->mUnk_08[0] = s->mUnk_380[0];
        scanParams->mUnk_08[1] = s->mUnk_380[1];
        scanParams->mUnk_08[2] = s->mUnk_380[2];
        scanParams->mUnk_08[3] = s->mUnk_380[3];
        scanParams->mUnk_08[4] = s->mUnk_380[4];
        scanParams->mUnk_08[5] = s->mUnk_380[5];
        s->mUnk_38c = s->mUnk_38c - 1;
    }
    scanParams->mUnk_06 = WM_GetDispersionScanPeriod();
    if (WM_StartScan(StartScanCallback, scanParams) != 2) {
        gConnectionWork->mUnk_0436 &= ~1;
        StopConnection();
        return;
    }
    gConnectionWork->mUnk_0436 |= 1;
    gConnectionWork->mUnk_0440 = b;
    gConnectionWork->mUnk_0444 = c;
    if (a != 0) {
        s->mUnk_38f = 1;
    } else {
        s->mUnk_38f = 0;
    }
}

void FillScanSlot(ScanSlot *slot, WMBssDesc *scanBuffer, ScanMacAddress *key, UserGameInfo *gameInfo, u8 entryIndex) {
    s32 childCount;
    u8 languageIndex;
    s32 isGhost;

    if (entryIndex >= 4) {
        return;
    }
    isGhost = gameInfo->mUnk_0e.mHasGhost;
    if (isGhost != 0) {
        if (gConnectionWork->mUnk_1d00 != 2) {
            return;
        }
        languageIndex = gameInfo->mUnk_0e.mLanguageIndex;
        childCount = gameInfo->mUnk_0e.mChildCount;
        MI_CpuCopy8(scanBuffer, slot, 0xc0);
        slot->mKey = *key;
        slot->mInUse = 1;
        slot->mAge = 0;
        if (childCount >= 0) {
            slot->mChildCount = childCount;
        }
        slot->mLanguageIndex = languageIndex;
        slot->mMultiBoot = 0;
        slot->mHasGhost = isGhost;
        MI_CpuCopy8(gameInfo, slot->mName, 0x14);
        SetScanGhostInfo(entryIndex, gameInfo);
    } else {
        s32 m0;
        u8 m1;

        if (gConnectionWork->mUnk_1d00 == 2) {
            return;
        }
        m1 = gameInfo->mUnk_0e.mLanguageIndex;
        m0 = gameInfo->mUnk_0e.mChildCount;
        MI_CpuCopy8(scanBuffer, slot, 0xc0);
        slot->mKey = *key;
        slot->mInUse = 1;
        slot->mAge = 0;
        if (m0 >= 0) {
            slot->mChildCount = m0;
        }
        slot->mLanguageIndex = m1;
        slot->mMultiBoot = 0;
        slot->mHasGhost = isGhost;
        MI_CpuCopy8(gameInfo, slot->mName, 0x14);
    }
}

void FindOrAddScanSlot(WMBssDesc *scanBuffer, ScanMacAddress *key, UserGameInfo *c) {
    Unk0217aa00_24_50_0e_36 *x;
    s32 i;
    s32 n;
    Unk0217aa00_ac *s;
    ScanSlot *chosenSlot;
    ScanSlot *g;
    ConnectionWork *connection;
    BOOL found;
    ScanSlot *slot;
    Unk0217aa00_24_50_0e *u;
    UserGameInfo *t;
    s8 v;

    connection = gConnectionWork;
    chosenSlot = NULL;
    g = connection->mUnk_00ac;
    n = 0;
    found = FALSE;
    for (i = 0, slot = g; i < 4; i++, slot++) {
        if (slot->mInUse != 0 && key->mUnk_00[0] == slot->mKey.mUnk_00[0] && key->mUnk_00[1] == slot->mKey.mUnk_00[1] &&
            key->mUnk_00[2] == slot->mKey.mUnk_00[2] && key->mUnk_00[3] == slot->mKey.mUnk_00[3] &&
            key->mUnk_00[4] == slot->mKey.mUnk_00[4] && key->mUnk_00[5] == slot->mKey.mUnk_00[5]) {
            chosenSlot = slot;
            found = TRUE;
            break;
        }
    }
    if (chosenSlot == NULL) {
        for (i = 0, slot = g; i < 4; i++, slot++) {
            if (slot->mInUse == 0) {
                chosenSlot = slot;
                break;
            }
        }
    }
    if (chosenSlot == NULL) {
        for (i = 0; i < 4; i++) {
            if (g->mAge < 5) {
                if (g->mAge > n) {
                    n = g->mAge;
                    chosenSlot = g;
                }
            }
            g++;
        }
    }
    if (chosenSlot == NULL) {
        return;
    }
    if ((scanBuffer->mGameInfo.mAttribute & 2) != 0) {
        if (connection->mUnk_1d00 != 2) {
            t = &scanBuffer->mGameInfo.mUserGameInfo;
            if (t->mUnk_07 == 5) {
                u = (void *) &t->mUnk_0e;
                x = &u->mUnk_36;
                v = -(found != FALSE);
                MI_CpuCopy8(scanBuffer, chosenSlot, 0xc0);
                chosenSlot->mKey = *key;
                chosenSlot->mInUse = 1;
                chosenSlot->mAge = 0;
                if (v >= 0) {
                    chosenSlot->mChildCount = v;
                }
                chosenSlot->mLanguageIndex = 0;
                chosenSlot->mMultiBoot = 1;
                chosenSlot->mHasGhost = 0;
                MI_CpuCopy8(x->mUnk_02, chosenSlot->mName, 0x14);
                gConnectionWork->mUnk_0438 = 0;
            } else if (t->mUnk_07 == 9) {
                if (chosenSlot->mInUse != 0) {
                    chosenSlot->mChildCount = t->mUnk_0a - 1;
                }
            } else if (chosenSlot->mInUse != 0) {
                chosenSlot->mAge = 0;
            } else {
                connection = gConnectionWork;
                connection->mUnk_042c = *key;
                connection->mUnk_0438 = 0xf;
            }
        }
    } else if (scanBuffer->mGameInfo.mUserGameInfoLength == 0x1c) {
        FillScanSlot(chosenSlot, scanBuffer, key, c, i);
    }
    s = &gConnectionWork->mUnk_00ac_view;
    s->mUnk_388 = 0;
    for (i = 0, slot = s->mUnk_000; i < 4; i++, slot++) {
        if (slot->mInUse != 0) {
            s->mUnk_388 += 1;
        }
    }
}

void StartScanCallback(Unk021425e8 *event) {
    WMBssDesc scanBuffer;
    ScanMacAddress key;
    s32 i;
    ConnectionWork *connection;
    s32 j;
    ScanSlot *q;
    Unk0217aa00_ac *s;
    u16 v;
    BOOL accepted;
    ScanSlot *e;

    if (gConnectionWork->mStep != 7) {
        return;
    }
    if (event->mResultCode == 0) {
        switch (event->mUnk_08_0) {
            case 5:
                DC_InvalidateRange(gConnectionWork->mUnk_0028, 0xc0);
                MI_CpuCopy8(gConnectionWork->mUnk_0028, &scanBuffer, 0xc0);
                DC_StoreRange(&scanBuffer, 0xc0);
                if (gConnectionWork->mState == 0xd) {
                    v = event->mUnk_12;
                    if (IsScanBlockGameInfoMatch(&scanBuffer) != 0) {
                        gConnectionWork->mUnk_1ed0 = 1;
                        gConnectionWork->mUnk_1ed4 = v;
                        gConnectionWork->mUnk_1ed6 = 0;
                    } else if (scanBuffer.mGameInfoLength >= 8 && scanBuffer.mGameInfo.mGgid == 0x25 &&
                               (scanBuffer.mGameInfo.mAttribute & 1) != 0) {
                        if ((scanBuffer.mGameInfo.mAttribute & 2) != 0) {
                            gConnectionWork->mUnk_1ed8 = 2;
                        } else {
                            gConnectionWork->mUnk_1ed8 = 3;
                        }
                        gConnectionWork->mUnk_1edc = v;
                        gConnectionWork->mUnk_1ede = 0;
                    }
                } else {
                    accepted = TRUE;
                    if (scanBuffer.mGameInfoLength < 8 || scanBuffer.mGameInfo.mGgid != 0x25 ||
                        (scanBuffer.mGameInfo.mAttribute & 1) == 0) {
                        accepted = FALSE;
                    } else if (gConnectionWork->mUnk_0444 != 0) {
                        if (gConnectionWork->mUnk_0444(&scanBuffer) == 0) {
                            accepted = FALSE;
                        }
                    }
                    if (accepted != FALSE) {
                        if (gConnectionWork->mUnk_0440 != 0) {
                            gConnectionWork->mUnk_0440(event, &scanBuffer);
                        } else if ((gConnectionWork->mUnk_0436 & 1) != 0) {
                            if ((scanBuffer.mGameInfo.mTgid & 0x8000) != 0) {
                                key.mUnk_00[0] = event->mUnk_0a[0];
                                key.mUnk_00[1] = event->mUnk_0a[1];
                                key.mUnk_00[2] = event->mUnk_0a[2];
                                key.mUnk_00[3] = event->mUnk_0a[3];
                                key.mUnk_00[4] = event->mUnk_0a[4];
                                key.mUnk_00[5] = event->mUnk_0a[5];
                                FindOrAddScanSlot(&scanBuffer, &key, &scanBuffer.mGameInfo.mUserGameInfo);
                                *gConnectionWork->mParentBssDesc = scanBuffer;
                            }
                        }
                    } else if (gConnectionWork->mUnk_0438 == 0) {
                        gConnectionWork->mUnk_0439 += 1;
                    }
                }
                break;
            case 4:
                if (gConnectionWork->mUnk_0438 == 0) {
                    gConnectionWork->mUnk_0439 += 1;
                }
                break;
        }
        connection = gConnectionWork;
        if ((connection->mUnk_0436 & 1) != 0 && connection->mState != 0xd) {
            for (i = 0, e = connection->mUnk_00ac; i < 4; i++, e++) {
                if (e->mInUse != 0) {
                    e->mAge += 1;
                    if (e->mAge > 0xc8) {
                        e->mInUse = 0;
                        s = &gConnectionWork->mUnk_00ac_view;
                        s->mUnk_388 = 0;
                        for (j = 0, q = s->mUnk_000; j < 4; j++, q++) {
                            if (q->mInUse != 0) {
                                s->mUnk_388 += 1;
                            }
                        }
                    }
                }
            }
        }
        if (gConnectionWork->mUnk_043b == 0) {
            gConnectionWork->mRequestPending = 0;
            return;
        }
        StartScan(1, gConnectionWork->mUnk_0440, gConnectionWork->mUnk_0444);
    } else {
        StopConnection();
    }
}

void EndScan(void) {
    gConnectionWork->mUnk_0436 &= ~1;
    gConnectionWork->mStep = 9;
    gConnectionWork->mRequestPending = 1;
    if (WM_EndScan(EndScanCallback) == 2) {
        return;
    }
    StopConnection();
}

void EndScanCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode == 0) {
        return;
    }
    StopConnection();
}

void StartConnect(WMBssDesc *a, void *b, void (*c)(), void (*d)(), void (*e)()) {
    u8 v1[0x18];

    MI_CpuFill8(v1, 0, 0x18);
    MI_CpuCopy8(&data_0217aa08->mFirstBlock->mPlayerName, v1, 0x14);
    if (a != NULL) {
        *gConnectionWork->mParentBssDesc = *a;
    }
    if (b == NULL) {
        v1[0x14] = 0;
        if (gBootInfo->mUnk_00 == 2) {
            v1[0x14] = v1[0x14] | 1;
        }
    } else {
        MI_CpuCopy8(b, v1, 0x18);
    }
    gConnectionWork->mStep = 10;
    gConnectionWork->mRequestPending = 1;
    if (WM_StartConnectEx(StartConnectCallback, (u16 *) gConnectionWork->mParentBssDesc, v1, 1, 0) != 2) {
        StopConnection();
        return;
    }
    gConnectionWork->mUnk_0448 = c;
    gConnectionWork->mUnk_044c = d;
    gConnectionWork->mUnk_0450 = e;
}

void StartConnectCallback(Unk021425e8 *event) {
    BOOL shouldReset;
    u16 v;
    RandomState64 *randomState;

    shouldReset = FALSE;
    switch (event->mResultCode) {
        case 0:
            switch (event->mUnk_08_0) {
                case 7:
                    gConnectionWork->mOwnIndex = event->mUnk_08_2;
                    gConnectionWork->mUnk_043a = shouldReset;
                    v = shouldReset;
                    switch (func_02051658_inline()) {
                        case 1:
                            v = gConnectionWork->mParentParameter->mUnk_0c;
                            break;
                        case 2:
                            v = gConnectionWork->mParentBssDesc->mGameInfo.mTgid;
                            break;
                    }
                    randomState = &gConnectionWork->mRandomState;
                    randomState->mValue = (u32) (v * 3 | v << 16);
                    randomState->mMultiplier = 0x5d588b656c078965;
                    randomState->mIncrement = 0x269ec3;
                    if (gConnectionWork->mUnk_0448 != 0) {
                        gConnectionWork->mUnk_0448();
                    }
                    gConnectionWork->mRequestPending = 0;
                    break;
                case 9:
                    if (gBootInfo->mUnk_00 == 2) {
                        shouldReset = TRUE;
                    } else if (gConnectionWork->mUnk_0450 != 0) {
                        gConnectionWork->mUnk_0450();
                    } else {
                        switch (gConnectionWork->mState) {
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                                StopConnection();
                                break;
                            case 0xa:
                                shouldReset = TRUE;
                                break;
                            case 0xb:
                            case 0xc:
                                break;
                            default:
                                shouldReset = TRUE;
                                break;
                        }
                    }
                    break;
                case 6:
                case 8:
                    break;
                default:
                    shouldReset = TRUE;
                    break;
            }
            break;
        case 1:
        case 0xb:
        case 0xc:
            if (gConnectionWork->mUnk_044c == 0) {
                shouldReset = TRUE;
            } else {
                gConnectionWork->mUnk_044c();
                gConnectionWork->mRequestPending = 0;
            }
            break;
        default:
            shouldReset = TRUE;
            break;
    }
    if (shouldReset == FALSE) {
        return;
    }
    ResetConnectionData();
    gConnectionWork->mErrorCode = 0;
    gConnectionWork->mRequestPending = 0;
}

void StartMP(void) {
    gConnectionWork->mStep = 0xb;
    gConnectionWork->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, gConnectionWork->mUnk_003c, gConnectionWork->mUnk_0038,
                     gConnectionWork->mUnk_0034, gConnectionWork->mUnk_0030, 1, 0, 0, 0, 0, 0) == 2) {
        return;
    }
    gConnectionWork->mErrorCode = 2;
    gConnectionWork->mRequestPending = 0;
}

void StartMPCallback(Unk021425e8 *event) {
    switch (event->mResultCode) {
        case 0:
            switch (event->mUnk_04) {
                case 0xa:
                    gConnectionWork->mUnk_0454 |= 1;
                    gConnectionWork->mSyncDoneChildMask = 0;
                    gConnectionWork->mRequestPending = 0;
                    break;
                case 0xb:
                case 0xc:
                    break;
            }
            break;
        case 9:
        case 0xd:
        case 0xf:
            break;
        default:
            gConnectionWork->mUnk_0454 |= 1;
            gConnectionWork->mErrorCode = 2;
            gConnectionWork->mRequestPending = 0;
            break;
    }
}

void SetMPFrequency(u32 mpFreq) {
    s32 result;

    gConnectionWork->mStep = 0xc;
    gConnectionWork->mRequestPending = 1;
    result = WM_SetMPFrequency(SetMPFrequencyCallback, mpFreq);
    if (result == 0) {
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if (result == 2) {
        return;
    }
    gConnectionWork->mErrorCode = 2;
    gConnectionWork->mRequestPending = 0;
}

void SetMPFrequencyCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0) {
        gConnectionWork->mErrorCode = 2;
        gConnectionWork->mRequestPending = 0;
    }
}

void SetEntry(s32 enabled) {
    s32 result;

    if ((gConnectionWork->mParentParameter->mUnk_0e != 0) == enabled) {
        return;
    }
    gConnectionWork->mStep = 0xd;
    gConnectionWork->mRequestPending = 1;
    result = WM_SetEntry(SetEntryCallback, enabled);
    if (result == 2) {
        return;
    }
    StopConnection();
}

void SetEntryCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode == 0) {
        return;
    }
    StopConnection();
}

void StartDataSharing(void) {
    s32 result;

    gConnectionWork->mStep = 0xe;
    gConnectionWork->mRequestPending = 1;
    result = WM_StartDataSharing(gConnectionWork->mUnk_15bc, 0xc, 0xff, 8, 1);
    gConnectionWork->mRequestPending = 0;
    if (result != 0) {
        gConnectionWork->mErrorCode = 2;
        gConnectionWork->mRequestPending = 0;
        return;
    }
    ResetDataSharing(&gConnectionWork->mUnk_15bc_view);
}

void SetGameInfo(void) {
    ChildList *children;
    BOOL r;
    u8 f;

    if (func_02051658_inline() != 1) {
        return;
    }
    gConnectionWork->mStep = 0xf;
    gConnectionWork->mRequestPending = 1;
    children = &gConnectionWork->mUnk_0044;
    children->mUnk_38->mUnk_0e.mChildCount = children->mChildCount;
    r = TRUE;
    if (gConnectionWork->mState != 8 && gConnectionWork->mState != 9) {
        r = FALSE;
    }
    if (WM_SetGameInfo(ClearRequestPending, children->mUnk_38, 0x1c, 0x25, gConnectionWork->mParentParameter->mUnk_0c,
                       r == FALSE) != 2) {
        gConnectionWork->mRequestPending = 0;
    }
}
