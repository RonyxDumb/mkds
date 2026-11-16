#include "00/code_02185344.h"
#include "00/unk_021b0000.h"
#include "code_0214b824.h"

#include "00/code_02180608.h"
#include "00/code_02184ba8.h"
#include "00/unk_021b4000.h"
#include "00/code_ov000_021804e0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02047104.h"

void SetWiFiAikotobaCheckDigits(void) {
    u8 a[20];
    s32 i;

    FormatUserDataFriendKey((u32) a);
    for (i = 0; i < 12; i++) {
        gWiFiAikotobaCheck->mDigits[i] = a[i];
    }
}

void menu_ta_GX_SetVisiblePlane(void) {
    s32 n = 0x4000;
    u8 a[12] = {0, 0, 1, 2, 3, 4, 1, 6, 7, 8, 9, 10};
    u8 b[12] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    u16 c;
    s32 i;
    s16 z[2];

    c = gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl->field6;
    SetWiFiAikotobaCheckDigits();
    for (i = 0; i < 12; i++) {
        if (b[i] == 0) {
            a[i] = a[i] + c;
        }
    }
    for (i = 0; i < 12; i++) {
        n -= jn_ui_initLabel(gWiFiAikotobaCheck->mHeap, data_ov000_021b06dc[i],
                             gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll, 8, 0x10, a[i],
                             gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcer, gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl,
                             gWiFiAikotobaCheck->mWiFiAikotobaCheckTable, n);
        z[0] = 0;
        z[1] = 0;
        z[0] = gWiFiAikotobaCheck->mDigits[i];
        jn_ui_212426C(0, data_ov000_021b06dc[i], gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll, z,
                      gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl, gWiFiAikotobaCheck->mWiFiAikotobaCheckTable);
    }
}

void InitWiFiAikotobaCheck(void *a) {
    void *b;

    gWiFiAikotobaCheck = heap_alloc(a, 0x54);
    gWiFiAikotobaCheck->mHeap = a;
    gWiFiAikotobaCheck->mState = 0;
    gWiFiAikotobaCheck->mNextState = 0;
    gWiFiAikotobaCheck->mPendingWiFiState = -1;
    gWiFiAikotobaCheck->mStateFrames = 0;
    gWiFiAikotobaCheck->mWiFiMessages = arc_getSceneArcFile(data_ov000_021b0fc0);
    gWiFiAikotobaCheck->mCommonMessages = arc_get2dArcFile(data_ov000_021b0fcc);
    LocateAndUploadWiFiAikotobaCheck();
    b = func_ov000_021804f4();
    oam_clearResetBuffers(b, test_run());
    jn_ui_initLayout(a, gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl, gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll,
                    &gWiFiAikotobaCheck->mWiFiAikotobaCheckTable);
    gWiFiAikotobaCheck->mOffset = 0x50;
    func_ov000_021854f8();
    menu_ta_GX_SetVisiblePlane();
    CreateMainMessageBoxBig(jn_msg_getMessage(gWiFiAikotobaCheck->mWiFiMessages, 0x11), 0, 1, 0, 0, 0, 0);
}

void menu_state4Vblank(void) {
    gWiFiAikotobaCheck = NULL;
}

void LocateAndUploadWiFiAikotobaCheck(void) {
    void *v1;
    v1 = arc_getSceneArcFile(gWiFiAikotobaCheckBnclName);
    gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl = v1;
    v1 = arc_getSceneArcFile(gWiFiAikotobaCheckBnllName);
    gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll = v1;
    v1 = arc_getSceneArcFile(gWiFiAikotobaCheckMNcgrName);
    g2du_getCharacterData(&gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcgr, v1);
    v1 = arc_getSceneArcFile(gWiFiAikotobaCheckMNcerName);
    g2du_getCellBankData(&gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcer, v1);
    v1 = arc_getSceneArcFile(gWiFiAikotobaCheckMONclrName);
    g2du_getPaletteData(&gWiFiAikotobaCheck->mWiFiAikotobaCheckMONclr, v1);
    GX_LoadOBJ(gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcgr->mData, 0,
               gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcgr->mDataSize);
    GX_LoadOBJPltt(gWiFiAikotobaCheck->mWiFiAikotobaCheckMONclr->mData, 0, 0x1a0);
    GX_LoadOBJPltt(gWiFiAikotobaCheck->mWiFiAikotobaCheckMONclr->mData + 0xe0, 0x1c0, 0x40);
}

void func_ov000_021854f8(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        gWiFiAikotobaCheck->mWiFiAikotobaCheckTable[data_ov000_021b06d8[i]].mOffsetY = gWiFiAikotobaCheck->mOffset;
    }
    for (i = 0; i < 12; i++) {
        gWiFiAikotobaCheck
            ->mWiFiAikotobaCheckTable[data_ov000_021b06dc[i] + gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl->field6]
            .mOffsetY = gWiFiAikotobaCheck->mOffset;
    }
}

void AdvanceWiFiAikotobaCheckState0(void) {
    gWiFiAikotobaCheck->mStateFrames = gWiFiAikotobaCheck->mStateFrames + 1;
    gWiFiAikotobaCheck->mOffset = mutil_interpolate(1, 0x50, 0, gWiFiAikotobaCheck->mStateFrames, 15);
    if (gWiFiAikotobaCheck->mStateFrames >= 15 && IsTxtSystemState2NoCloseRequest() != 0) {
        gWiFiAikotobaCheck->mNextState = 1;
        gWiFiAikotobaCheck->mStateFrames = 0;
    }
}

void AdvanceWiFiAikotobaCheckState1(void) {
    InputSlotIndex i = UNK_02175628_INDEX_8;
    BOOL a;
    BOOL b;
    u16 c;

    if ((u16) (gInputUnits[i].mPressedBits & PAD_KEY_B) == 0) {
        a = FALSE;
        b = FALSE;
        c = gInputUnits[i].mHasPair;
        if (c == 0 && gInputUnits[i].mNoPairCount < 5) {
            b = TRUE;
        }
        if (b == FALSE && gInputUnits[i].mPrevHasPair == 0 && c != 0) {
            a = TRUE;
        }
        if (a == FALSE || gmenu_checkSelectReturnTouch(gInputUnits[i].mPairX,
                                                                          gInputUnits[i].mPairY) == FALSE) {
            return;
        }
    }
    gWiFiAikotobaCheck->mNextState = 2;
    gWiFiAikotobaCheck->mPendingWiFiState = 8;
    RequestSelectReturnState3WithSound(0);
    RequestTxtSystemClose();
}

void AdvanceWiFiAikotobaCheckState2(void) {
    gWiFiAikotobaCheck->mStateFrames = gWiFiAikotobaCheck->mStateFrames + 1;
    gWiFiAikotobaCheck->mOffset = mutil_interpolate(1, 0, 0x50, gWiFiAikotobaCheck->mStateFrames, 15);
    if (gWiFiAikotobaCheck->mStateFrames >= 15 && IsTxtSystemState0NoOpenRequest() != 0 &&
        IsSelectReturnState2NoState3Or4Request() != 0) {
        RequestWiFiState(gWiFiAikotobaCheck->mPendingWiFiState);
    }
}

void AdvanceWiFiAikotobaCheck(void) {
    WiFiAikotobaCheck *p;

    gWiFiAikotobaCheck->mState = gWiFiAikotobaCheck->mNextState;
    switch (gWiFiAikotobaCheck->mState) {
        case 0:
            AdvanceWiFiAikotobaCheckState0();
            break;
        case 1:
            AdvanceWiFiAikotobaCheckState1();
            break;
        case 2:
            AdvanceWiFiAikotobaCheckState2();
            break;
    }
    func_ov000_021854f8();
    p = gWiFiAikotobaCheck;
    jn_ui_renderElements(p->mWiFiAikotobaCheckBncl, p->mWiFiAikotobaCheckMNcer, p->mWiFiAikotobaCheckBnll,
                    func_ov000_021804f4(), p->mWiFiAikotobaCheckTable);
}

void func_ov000_02185368(void) {}

void RegisterWiFiAikotobaCheckCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiAikotobaCheckCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
