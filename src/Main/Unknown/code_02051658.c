#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "code_020204c0.h"
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

static inline u32 func_02051658_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

void StartScan(s32 a, s32 (*b)(), s32 (*c)()) {
    ConnectionWork *connection;
    Unk0217aa00_ac *s;
    Unk02143a78 *scanParams;
    u16 channel;
    s32 i;
    u16 allowedChannels;

    connection = gStruct217AA00;
    s = &connection->mUnk_00ac_view;
    channel = s->field38D;
    scanParams = connection->field1C;
    connection->field0 = 2;
    gStruct217AA00->fieldC = 7;
    gStruct217AA00->mRequestPending = 1;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0) {
        gStruct217AA00->mRequestPending = 0;
        gStruct217AA00->field8 = 3;
        gStruct217AA00->mRequestPending = 0;
        return;
    }
    if (allowedChannels == 0x8000) {
        gStruct217AA00->mRequestPending = 0;
        gStruct217AA00->field8 = 8;
        gStruct217AA00->mRequestPending = 0;
        return;
    }
    if (s->field38C == 0) {
        if (((1 << (channel - 1)) & allowedChannels) == 0) {
            do {
                channel = channel + 1;
                if (channel > 0xe) {
                    channel = 1;
                }
            } while (((1 << (channel - 1)) & allowedChannels) == 0);
        }
        scanParams->field4 = channel;
        s->field38D = channel;
        for (i = 0; i < 6; i++) {
            scanParams->field8[i] = 0xff;
        }
    } else {
        scanParams->field8[0] = s->field380[0];
        scanParams->field8[1] = s->field380[1];
        scanParams->field8[2] = s->field380[2];
        scanParams->field8[3] = s->field380[3];
        scanParams->field8[4] = s->field380[4];
        scanParams->field8[5] = s->field380[5];
        s->field38C = s->field38C - 1;
    }
    scanParams->field6 = WM_GetDispersionScanPeriod();
    if (WM_StartScan(StartScanCallback, scanParams) != 2) {
        gStruct217AA00->field436 &= ~1;
        sub_20533A0();
        return;
    }
    gStruct217AA00->field436 |= 1;
    gStruct217AA00->field440 = b;
    gStruct217AA00->field444 = c;
    if (a != 0) {
        s->field38F = 1;
    } else {
        s->field38F = 0;
    }
}

void sub_20525A8(ScanSlot *slot, ScanBlockView *scanBuffer, Unk0217aa00_42c *key, Unk0217aa00_24_50 *d, u8 e) {
    s32 n0;
    u8 n1;
    s32 k;

    if (e >= 4) {
        return;
    }
    k = d->fieldE.field7_0;
    if (k != 0) {
        if (gStruct217AA00->field1D00 != 2) {
            return;
        }
        n1 = d->fieldE.field6_4;
        n0 = d->fieldE.field6_0;
        MI_CpuCopy8(scanBuffer, slot, 0xc0);
        slot->mUnk_c0_42c = *key;
        slot->fieldDC_0 = 1;
        slot->fieldDB = 0;
        if (n0 >= 0) {
            slot->fieldDA = n0;
        }
        slot->fieldDC_1 = n1;
        slot->fieldDC_5 = 0;
        slot->fieldDC_6 = k;
        MI_CpuCopy8(d, slot->fieldC6, 0x14);
        SetScanGhostInfo(e, d);
    } else {
        s32 m0;
        u8 m1;

        if (gStruct217AA00->field1D00 == 2) {
            return;
        }
        m1 = d->fieldE.field6_4;
        m0 = d->fieldE.field6_0;
        MI_CpuCopy8(scanBuffer, slot, 0xc0);
        slot->mUnk_c0_42c = *key;
        slot->fieldDC_0 = 1;
        slot->fieldDB = 0;
        if (m0 >= 0) {
            slot->fieldDA = m0;
        }
        slot->fieldDC_1 = m1;
        slot->fieldDC_5 = 0;
        slot->fieldDC_6 = k;
        MI_CpuCopy8(d, slot->fieldC6, 0x14);
    }
}

void FindOrAddScanSlot(ScanBlockView *scanBuffer, Unk0217aa00_42c *key, Unk0217aa00_24_50 *c) {
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
    Unk0217aa00_24_50 *t;
    s8 v;

    connection = gStruct217AA00;
    chosenSlot = NULL;
    g = connection->fieldAC;
    n = 0;
    found = FALSE;
    for (i = 0, slot = g; i < 4; i++, slot++) {
        if (slot->fieldDC_0 != 0 && key->field0[0] == slot->fieldC0[0] && key->field0[1] == slot->fieldC0[1] &&
            key->field0[2] == slot->fieldC0[2] && key->field0[3] == slot->fieldC0[3] &&
            key->field0[4] == slot->fieldC0[4] && key->field0[5] == slot->fieldC0[5]) {
            chosenSlot = slot;
            found = TRUE;
            break;
        }
    }
    if (chosenSlot == NULL) {
        for (i = 0, slot = g; i < 4; i++, slot++) {
            if (slot->fieldDC_0 == 0) {
                chosenSlot = slot;
                break;
            }
        }
    }
    if (chosenSlot == NULL) {
        for (i = 0; i < 4; i++) {
            if (g->fieldDB < 5) {
                if (g->fieldDB > n) {
                    n = g->fieldDB;
                    chosenSlot = g;
                }
            }
            g++;
        }
    }
    if (chosenSlot == NULL) {
        return;
    }
    if ((scanBuffer->field4B & 2) != 0) {
        if (connection->field1D00 != 2) {
            t = &scanBuffer->field50;
            if (t->field7 == 5) {
                u = (void *) &t->fieldE;
                x = &u->field36;
                v = -(found != FALSE);
                MI_CpuCopy8(scanBuffer, chosenSlot, 0xc0);
                chosenSlot->mUnk_c0_42c = *key;
                chosenSlot->fieldDC_0 = 1;
                chosenSlot->fieldDB = 0;
                if (v >= 0) {
                    chosenSlot->fieldDA = v;
                }
                chosenSlot->fieldDC_1 = 0;
                chosenSlot->fieldDC_5 = 1;
                chosenSlot->fieldDC_6 = 0;
                MI_CpuCopy8(x->field2, chosenSlot->fieldC6, 0x14);
                gStruct217AA00->field438 = 0;
            } else if (t->field7 == 9) {
                if (chosenSlot->fieldDC_0 != 0) {
                    chosenSlot->fieldDA = t->fieldA - 1;
                }
            } else if (chosenSlot->fieldDC_0 != 0) {
                chosenSlot->fieldDB = 0;
            } else {
                connection = gStruct217AA00;
                *(Unk0217aa00_42c *) &connection->field42C = *key;
                connection->field438 = 0xf;
            }
        }
    } else if (scanBuffer->field4A == 0x1c) {
        sub_20525A8(chosenSlot, scanBuffer, key, c, i);
    }
    s = &gStruct217AA00->mUnk_00ac_view;
    s->field388 = 0;
    for (i = 0, slot = s->field0; i < 4; i++, slot++) {
        if (slot->fieldDC_0 != 0) {
            s->field388 += 1;
        }
    }
}

void StartScanCallback(Unk021425e8 *event) {
    ScanBlockView scanBuffer;
    Unk0217aa00_42c key;
    s32 i;
    ConnectionWork *connection;
    s32 j;
    ScanSlot *q;
    Unk0217aa00_ac *s;
    u16 v;
    BOOL accepted;
    ScanSlot *e;

    if (gStruct217AA00->fieldC != 7) {
        return;
    }
    if (event->mResultCode == 0) {
        switch (event->field8_0) {
            case 5:
                DC_InvalidateRange(gStruct217AA00->field28, 0xc0);
                MI_CpuCopy8(gStruct217AA00->field28, &scanBuffer, 0xc0);
                DC_StoreRange(&scanBuffer, 0xc0);
                if (gStruct217AA00->field4 == 0xd) {
                    v = event->field12;
                    if (sub_20204C0(&scanBuffer) != 0) {
                        gStruct217AA00->field1ED0 = 1;
                        gStruct217AA00->field1ED4 = v;
                        gStruct217AA00->field1ED6 = 0;
                    } else if (scanBuffer.field3C >= 8 && scanBuffer.field44 == 0x25 && (scanBuffer.field4B & 1) != 0) {
                        if ((scanBuffer.field4B & 2) != 0) {
                            gStruct217AA00->field1ED8 = 2;
                        } else {
                            gStruct217AA00->field1ED8 = 3;
                        }
                        gStruct217AA00->field1EDC = v;
                        gStruct217AA00->field1EDE = 0;
                    }
                } else {
                    accepted = TRUE;
                    if (scanBuffer.field3C < 8 || scanBuffer.field44 != 0x25 || (scanBuffer.field4B & 1) == 0) {
                        accepted = FALSE;
                    } else if (gStruct217AA00->field444 != 0) {
                        if (gStruct217AA00->field444(&scanBuffer) == 0) {
                            accepted = FALSE;
                        }
                    }
                    if (accepted != FALSE) {
                        if (gStruct217AA00->field440 != 0) {
                            gStruct217AA00->field440(event, &scanBuffer);
                        } else if ((gStruct217AA00->field436 & 1) != 0) {
                            if ((scanBuffer.field48 & 0x8000) != 0) {
                                key.field0[0] = event->fieldA[0];
                                key.field0[1] = event->fieldA[1];
                                key.field0[2] = event->fieldA[2];
                                key.field0[3] = event->fieldA[3];
                                key.field0[4] = event->fieldA[4];
                                key.field0[5] = event->fieldA[5];
                                FindOrAddScanSlot(&scanBuffer, &key, &scanBuffer.field50);
                                *gStruct217AA00->field24 = scanBuffer;
                            }
                        }
                    } else if (gStruct217AA00->field438 == 0) {
                        gStruct217AA00->field439 += 1;
                    }
                }
                break;
            case 4:
                if (gStruct217AA00->field438 == 0) {
                    gStruct217AA00->field439 += 1;
                }
                break;
        }
        connection = gStruct217AA00;
        if ((connection->field436 & 1) != 0 && connection->field4 != 0xd) {
            for (i = 0, e = connection->fieldAC; i < 4; i++, e++) {
                if (e->fieldDC_0 != 0) {
                    e->fieldDB += 1;
                    if (e->fieldDB > 0xc8) {
                        e->fieldDC_0 = 0;
                        s = &gStruct217AA00->mUnk_00ac_view;
                        s->field388 = 0;
                        for (j = 0, q = s->field0; j < 4; j++, q++) {
                            if (q->fieldDC_0 != 0) {
                                s->field388 += 1;
                            }
                        }
                    }
                }
            }
        }
        if (gStruct217AA00->field43B == 0) {
            gStruct217AA00->mRequestPending = 0;
            return;
        }
        StartScan(1, gStruct217AA00->field440, gStruct217AA00->field444);
    } else {
        sub_20533A0();
    }
}

void EndScan(void) {
    gStruct217AA00->field436 &= ~1;
    gStruct217AA00->fieldC = 9;
    gStruct217AA00->mRequestPending = 1;
    if (WM_EndScan(EndScanCallback) == 2) {
        return;
    }
    sub_20533A0();
}

void EndScanCallback(Unk021425e8 *event) {
    gStruct217AA00->mRequestPending = 0;
    if (event->mResultCode == 0) {
        return;
    }
    sub_20533A0();
}

void StartConnect(ScanBlockView *a, void *b, s32 (*c)(), s32 (*d)(), s32 (*e)()) {
    u8 v1[0x18];

    MI_CpuFill8(v1, 0, 0x18);
    MI_CpuCopy8(&gSaveData->mFirstBlock->mPlayerName, v1, 0x14);
    if (a != NULL) {
        *gStruct217AA00->field24 = *a;
    }
    if (b == NULL) {
        v1[0x14] = 0;
        if (*(u16 *) 0x027ffc40 == 2) {
            v1[0x14] = v1[0x14] | 1;
        }
    } else {
        MI_CpuCopy8(b, v1, 0x18);
    }
    gStruct217AA00->fieldC = 10;
    gStruct217AA00->mRequestPending = 1;
    if (WM_StartConnectEx(StartConnectCallback, (u16 *) gStruct217AA00->field24, v1, 1, 0) != 2) {
        sub_20533A0();
        return;
    }
    gStruct217AA00->field448 = c;
    gStruct217AA00->field44C = d;
    gStruct217AA00->field450 = e;
}

void StartConnectCallback(Unk021425e8 *event) {
    BOOL shouldReset;
    u16 v;
    RandomState64 *randomState;

    shouldReset = FALSE;
    switch (event->mResultCode) {
        case 0:
            switch (event->field8_0) {
                case 7:
                    gStruct217AA00->mOwnIndex = event->field8_2;
                    gStruct217AA00->field43A = shouldReset;
                    v = shouldReset;
                    switch (func_02051658_inline()) {
                        case 1:
                            v = gStruct217AA00->mParentParameter->fieldC;
                            break;
                        case 2:
                            v = gStruct217AA00->field24->field48;
                            break;
                    }
                    randomState = &gStruct217AA00->field1EE8;
                    randomState->mValue = (u32) (v * 3 | v << 16);
                    randomState->mMultiplier = 0x5d588b656c078965;
                    randomState->mIncrement = 0x269ec3;
                    if (gStruct217AA00->field448 != 0) {
                        gStruct217AA00->field448();
                    }
                    gStruct217AA00->mRequestPending = 0;
                    break;
                case 9:
                    if (*(u16 *) 0x027ffc40 == 2) {
                        shouldReset = TRUE;
                    } else if (gStruct217AA00->field450 != 0) {
                        gStruct217AA00->field450();
                    } else {
                        switch (gStruct217AA00->field4) {
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                                sub_20533A0();
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
            if (gStruct217AA00->field44C == 0) {
                shouldReset = TRUE;
            } else {
                gStruct217AA00->field44C();
                gStruct217AA00->mRequestPending = 0;
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
    gStruct217AA00->field8 = 0;
    gStruct217AA00->mRequestPending = 0;
}

void StartMP(void) {
    gStruct217AA00->fieldC = 0xb;
    gStruct217AA00->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, gStruct217AA00->field3C, gStruct217AA00->field38, gStruct217AA00->field34,
                     gStruct217AA00->field30, 1, 0, 0, 0, 0, 0) == 2) {
        return;
    }
    gStruct217AA00->field8 = 2;
    gStruct217AA00->mRequestPending = 0;
}

void StartMPCallback(Unk021425e8 *event) {
    switch (event->mResultCode) {
        case 0:
            switch (event->field4) {
                case 0xa:
                    gStruct217AA00->field454 |= 1;
                    gStruct217AA00->field1D54 = 0;
                    gStruct217AA00->mRequestPending = 0;
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
            gStruct217AA00->field454 |= 1;
            gStruct217AA00->field8 = 2;
            gStruct217AA00->mRequestPending = 0;
            break;
    }
}

void SetMPFrequency(u32 mpFreq) {
    s32 result;

    gStruct217AA00->fieldC = 0xc;
    gStruct217AA00->mRequestPending = 1;
    result = WM_SetMPFrequency(SetMPFrequencyCallback, mpFreq);
    if (result == 0) {
        gStruct217AA00->mRequestPending = 0;
        return;
    }
    if (result == 2) {
        return;
    }
    gStruct217AA00->field8 = 2;
    gStruct217AA00->mRequestPending = 0;
}

void SetMPFrequencyCallback(Unk021425e8 *event) {
    gStruct217AA00->mRequestPending = 0;
    if (event->mResultCode != 0) {
        gStruct217AA00->field8 = 2;
        gStruct217AA00->mRequestPending = 0;
    }
}

void SetEntry(s32 enabled) {
    s32 result;

    if ((gStruct217AA00->mParentParameter->fieldE != 0) == enabled) {
        return;
    }
    gStruct217AA00->fieldC = 0xd;
    gStruct217AA00->mRequestPending = 1;
    result = WM_SetEntry(SetEntryCallback, enabled);
    if (result == 2) {
        return;
    }
    sub_20533A0();
}

void SetEntryCallback(Unk021425e8 *event) {
    gStruct217AA00->mRequestPending = 0;
    if (event->mResultCode == 0) {
        return;
    }
    sub_20533A0();
}

void StartDataSharing(void) {
    s32 result;

    gStruct217AA00->fieldC = 0xe;
    gStruct217AA00->mRequestPending = 1;
    result = WM_StartDataSharing(gStruct217AA00->field15BC, 0xc, 0xff, 8, 1);
    gStruct217AA00->mRequestPending = 0;
    if (result != 0) {
        gStruct217AA00->field8 = 2;
        gStruct217AA00->mRequestPending = 0;
        return;
    }
    ResetDataSharing(&gStruct217AA00->mUnk_15bc_view);
}

void SetGameInfo(void) {
    ChildList *children;
    BOOL r;
    u8 f;

    if (func_02051658_inline() != 1) {
        return;
    }
    gStruct217AA00->fieldC = 0xf;
    gStruct217AA00->mRequestPending = 1;
    children = &gStruct217AA00->field44;
    children->field38->fieldE.field6_0 = children->mChildCount;
    r = TRUE;
    if (gStruct217AA00->field4 != 8 && gStruct217AA00->field4 != 9) {
        r = FALSE;
    }
    if (WM_SetGameInfo((Unk021425e8Func) ClearRequestPending, children->field38, 0x1c, 0x25,
                       gStruct217AA00->mParentParameter->fieldC, r == FALSE) != 2) {
        gStruct217AA00->mRequestPending = 0;
    }
}
