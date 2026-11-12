#include "03/Menu/jb5_info.h"
#include "03/code_021c38f0.h"
#include "03/Graphics/hl_scr.h"
#include "03/code_021bf000.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/text_canvas.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/Menu/sub_screen_message.h"
#include "03/System/application.h"
#include "03/code_021c36ec.h"
#include "03/code_021c3758.h"
#include "03/code_021c388c.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"
#include "code_0200fc8c.h"
#include "code_0213c9f8.h"
#include "dwc_backup.h"
#include "03/code_021c36c8.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Menu/slide_buttons.h"
#include "03/Menu/yb5_multi_next_setup.h"

void SetupJb5Info(void) {
    LoadJb5InfoFileAndSetBgCnt();
    LoadHlScr(0x11);
    ShowSubScreenMessage(0x89, -1, 0);
    PrintJb5Info();
    SetUpdateFunction(StartJb5InfoFadeIn);
}

void LoadJb5InfoFileAndSetBgCnt(void) {
    void *v2 = &gJb5InfoNscName;
    void *v3 = &GX_LoadBG2Scr;
    u32 v4 = LoadFileToVram(v2, v3);
    u32 v5 = 0x4001008u;
    u32 v6 = (*(u16 *) ((v5) + (0)));
    u32 v8 = ((v6) & ~(0x3u));
    u32 v9 = ((v8) | (0x3u));
    u32 v11;
    u32 v12;
    u32 v13;
    u32 v14;
    u32 v16;
    u32 v17;
    u32 v18;
    u32 v19;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v24;
    u32 v26;
    u32 v27;
    u32 v28;
    u32 v29;
    *(u16 *) ((v5) + (0)) = v9;
    v11 = 0x400100au;
    v12 = (*(u16 *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(u16 *) ((v11) + (0)) = v14;
    v16 = 0x4000008u;
    v17 = (*(u16 *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(u16 *) ((v16) + (0)) = v19;
    v21 = 0x400000au;
    v22 = (*(u16 *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(u16 *) ((v21) + (0)) = v24;
    v26 = 0x400000cu;
    v27 = (*(u16 *) ((v26) + (0)));
    v28 = ((v27) & ~(0x3u));
    v29 = ((v28) | (0x3u));
    *(u16 *) ((v26) + (0)) = v29;
}

void PrintJb5Info(void) {
    void *a;
    u8 b[8];
    DWCWiFiInfo c;
    u32 d[4];
    u16 f[20];
    u64 g;
    s32 i;
    a = InitBgTextCanvas(0, 0);
    OS_GetMacAddress(b);
    swprintf(f, 0x14, gMacAddressFormat, b[0], b[1], b[2], b[3], b[4], b[5]);
    DrawCanvasTextRect(a, gJb5InfoMacAddressRect.mX, gJb5InfoMacAddressRect.mY, gJb5InfoMacAddressRect.mUnk_04,
                       gJb5InfoMacAddressRect.mUnk_06, 2, 0x480, f);
    DWCi_BM_GetWiFiInfo(&c);
    g = c.mAttestedUserId;
    if (g != 0) {
        d[3] = (g % 10) * 1000;
        g = g / 10;
        for (i = 0; i < 3; i++) {
            d[2 - i] = g % 10000;
            g = g / 10000;
        }
        swprintf(f, 0x14, gDashSeparatedNumbersFormat, d[0], d[1], d[2], d[3]);
    } else {
        swprintf(f, 0x14, gDashesFormat);
    }
    DrawCanvasTextRect(a, gJb5InfoUserIdRect.mX, gJb5InfoUserIdRect.mY, gJb5InfoUserIdRect.mUnk_04,
                       gJb5InfoUserIdRect.mUnk_06, 2, 0x480, f);
    RequestBgTextCanvasUpload(a);
}

void StartJb5InfoFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateJb5InfoFadeIn);
}

void UpdateJb5InfoFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(2);
        SetUpdateFunction(UpdateJb5InfoButtonsIn);
    }
}

void UpdateJb5InfoButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateJb5Info);
    }
}

void UpdateJb5Info(void) {
    UpdateJb5InfoInput();
    UpdateJb5InfoNop();
    UpdateJb5InfoResult();
}
