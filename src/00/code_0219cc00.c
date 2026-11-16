#include "00/code_0219cc00.h"
#include "00/GameSpy/gstats.h"
#include "00/code_02197000.h"
#include "00/code_0219c000.h"
#include "00/code_0219cfc0.h"
#include "00/code_0219d000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219d128.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"

#include "00/code_0219c954.h"
#include "00/code_0219cb00.h"
#include "00/code_021947e4.h"
#include "00/code_02196000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/GameSpy/gpiBuddy.h"
#include "00/code_02194000.h"
#include "00/GameSpy/gp.h"
#include "00/unk_021b4000.h"
#include "os_printf.h"
#include "code_02139f70.h"
#include "Main/Unknown/code_02152000.h"
#include "code_02152500.h"
#include "code_02152934.h"
#include "code_021522a0.h"
#include "Main/Unknown/code_02152468.h"
#include "Main/Unknown/code_02152a1c.h"

void func_ov000_0219ce48(GpConnection *a, Unk0219c400 *b, u32 c) {
    s32 i;
    s32 k;
    s32 n;
    if (b->field0 == 0 && b->field4 != 0 && DWC_GetFriendDataType(&gWiFiBuddySync->mBuddies[c]) != 0) {
        if (gWiFiBuddySync->mState == 1) {
            gWiFiBuddySync->mBuddiesChanged = 1;
            for (i = 0; i < b->field4; i++) {
                if (func_ov000_0219d210(gWiFiBuddySync->mBuddies, c, b->fieldC[i].field0) != FALSE) {
                    gWiFiBuddySync->mSyncIndex++;
                    gWiFiBuddySync->field1E = 1;
                    b->field8 = 0x601;
                    return;
                }
            }
            k = 0;
            for (i = 0; i < b->field4; i++) {
                ReportBuddySyncGpResult(GpGetBuddyIndex(a, b->fieldC[i].field0, &n));
                if (n == ~k) {
                    AddBuddy(b->fieldC[i].field0);
                } else {
                    DWC_SetGsProfileId(&gWiFiBuddySync->mBuddies[c], b->fieldC[0].field0);
                    DWCi_SetBuddyFriendData(&gWiFiBuddySync->mBuddies[c]);
                    func_ov000_0219d504(c);
                    gWiFiBuddySync->mSyncIndex++;
                    gWiFiBuddySync->field1E = 1;
                    b->field8 = 0x601;
                    return;
                }
            }
            if (b->field8 != 0x600) {
                gWiFiBuddySync->mSyncIndex++;
                gWiFiBuddySync->field1E = 1;
            }
        }
    } else {
        if (b->field0 != 0) {
            if (ReportBuddySyncGpResult(b->field0) != 0) {
                return;
            }
        } else if (gWiFiBuddySync->mState == 1 || DWC_GetFriendDataType(&gWiFiBuddySync->mBuddies[c]) == 0) {
            gWiFiBuddySync->mSyncIndex++;
            gWiFiBuddySync->field1E = 1;
        }
    }
}

void func_ov000_0219cd74(GpConnection *a, Unk0219c400 *b, u32 c) {
    GpConnection *h = a;
    s32 i;
    BOOL f;
    char s[0x18];
    u32 t;
    f = FALSE;
    i = 0;
    for (; i < gWiFiBuddySync->mBuddyEntryCount; i++) {
        if (DWC_GetFriendDataType(&gWiFiBuddySync->mBuddies[i]) == 1) {
            DWC_LoginIdToUserName(func_ov000_0219c9c4(), &gWiFiBuddySync->mBuddies[i], s);
            if (strcmp(s, (const char *) b->field8E) == 0) {
                func_ov000_0218ee1c(h, b->field4);
                DWC_SetGsProfileId(&gWiFiBuddySync->mBuddies[i], b->field4);
                f = TRUE;
            }
        } else if (DWC_GetFriendDataType(&gWiFiBuddySync->mBuddies[i]) == 3 ||
                   DWC_GetFriendDataType(&gWiFiBuddySync->mBuddies[i]) == 2) {
            t = b->field4;
            if (t == DWC_GetGsProfileId(func_ov000_0219c9c4(), &gWiFiBuddySync->mBuddies[i])) {
                func_ov000_0218ee1c(h, t);
                f = TRUE;
            }
        }
    }
    if (f != FALSE) {
        AddBuddy(b->field4);
    } else {
        func_ov000_0218ed74(h, b->field4);
    }
}

void func_ov000_0219cc94(GpConnection *a, Unk0219c400 *b, u32 c) {
    s32 i;
    BOOL f;
    char s[0x1c];
    u32 t;
    f = FALSE;
    i = 0;
    for (; i < gWiFiBuddySync->mBuddyEntryCount; i++) {
        if (DWC_GetFriendDataType(&gWiFiBuddySync->mBuddies[i]) == 1) {
            DWC_LoginIdToUserName(func_ov000_0219c9c4(), &gWiFiBuddySync->mBuddies[i], s);
            if (strcmp(s, (const char *) b->field8E) == 0) {
                DWC_SetGsProfileId(&gWiFiBuddySync->mBuddies[i], b->field4);
                DWCi_SetBuddyFriendData(&gWiFiBuddySync->mBuddies[i]);
                f = TRUE;
            }
        } else if (DWC_GetFriendDataType(&gWiFiBuddySync->mBuddies[i]) == 3 ||
                   DWC_GetFriendDataType(&gWiFiBuddySync->mBuddies[i]) == 2) {
            t = b->field4;
            if (t == DWC_GetGsProfileId(func_ov000_0219c9c4(), &gWiFiBuddySync->mBuddies[i])) {
                DWC_SetGsProfileId(&gWiFiBuddySync->mBuddies[i], t);
                DWCi_SetBuddyFriendData(&gWiFiBuddySync->mBuddies[i]);
                f = TRUE;
            }
        }
    }
    if (f != FALSE) {
        func_ov000_0219d504(
            func_ov000_0219d14c(gWiFiBuddySync->mBuddies, gWiFiBuddySync->mBuddyEntryCount, b->field4));
        gWiFiBuddySync->mBuddiesChanged = 1;
    }
}

void func_ov000_0219cc30(u32 a, u32 b, u32 c) {
    char s[0x40];
    RemovePendingStatsRequest();
    if (c == 0 || a != 0) {
        ReportBuddySyncError(6, -72200);
        return;
    }
    gWiFiBuddySync->field24 = b;
    OS_SNPrintf(s, 0x40, "\\dwc_name\\%s", gWiFiBuddySync->field28);
    func_ov000_0219cc00(gWiFiBuddySync->field24, 3, (u32) s, 0x80000001);
}

void func_ov000_0219cc00(u32 a, u32 b, u32 c, u32 d) {
    AddPendingStatsRequest();
    func_ov000_02197558(0, a, b, 0, c, (u32) &func_ov000_0219cb64, d);
}
