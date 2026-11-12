#include "03/Menu/connect_message.h"
#include "03/code_021cbf60.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/text_canvas.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/Menu/sub_screen_message.h"
#include "03/code_021bf000.h"
#include "03/Net/essid_packet_steps.h"
#include "03/code_021cd2e0.h"
#include "03/Graphics/hl_scr.h"
#include "03/System/application.h"
#include "03/code_021cbed0.h"
#include "03/code_021cd000.h"
#include "03/Net/ap_scan.h"
#include "03/code_021d1dd0.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"
#include "03/code_021cb000.h"
#include "03/code_021ce000.h"
#include "03/Menu/message_box_create.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/Menu/connect_done.h"

ConnectMessageIds gConnectMessageIds = {{0x75, 0x75, 0x9d}};
u8 gXb4NoneNscName2[18] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x78, 0x62, 0x34, 0x4e, 0x6f, 0x6e, 0x65, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};

void SetupConnectMessage(void) {
    s32 secondaryPairSecond;
    ReleaseApScan();
    GetSecondaryMenuPair(NULL, &secondaryPairSecond);
    LoadConnectMessageFileAndSetBgCnt();
    ShowSubScreenMessage(0x7d, -1, 0);
    if (secondaryPairSecond != 2) {
        LoadHlSetScr();
    }
    if (secondaryPairSecond == 1) {
        WriteApWorkCopy();
    }
    SetUpdateFunction(StartConnectMessageFadeIn);
}

void LoadConnectMessageFileAndSetBgCnt(void) {
    void *nscName = &gXb4NoneNscName2;
    void *loadBg2ScrFunc = &GX_LoadBG2Scr;
    u32 bg2ScrLoadResult = LoadFileToVram(nscName, loadBg2ScrFunc);
    u32 g2sDbBg0CntAddr = 0x4001008u;
    u32 g2sDbBg0CntOld = (*(u16 *) ((g2sDbBg0CntAddr) + (0)));
    u32 g2sDbBg0CntCleared = ((g2sDbBg0CntOld) & ~(0x3u));
    u32 g2sDbBg0CntNew = ((g2sDbBg0CntCleared) | (0x3u));
    u32 g2sDbBg1CntAddr;
    u32 g2sDbBg1CntOld;
    u32 g2sDbBg1CntCleared;
    u32 g2sDbBg1CntNew;
    u32 g2Bg1CntAddr;
    u32 g2Bg1CntOld;
    u32 g2Bg1CntCleared;
    u32 g2Bg1CntNew;
    u32 g2Bg2CntAddr;
    u32 g2Bg2CntOld;
    u32 g2Bg2CntCleared;
    u32 g2Bg2CntNew;
    *(u16 *) ((g2sDbBg0CntAddr) + (0)) = g2sDbBg0CntNew;
    g2sDbBg1CntAddr = 0x400100au;
    g2sDbBg1CntOld = (*(u16 *) ((g2sDbBg1CntAddr) + (0)));
    g2sDbBg1CntCleared = ((g2sDbBg1CntOld) & ~(0x3u));
    g2sDbBg1CntNew = ((g2sDbBg1CntCleared) | (0x3u));
    *(u16 *) ((g2sDbBg1CntAddr) + (0)) = g2sDbBg1CntNew;
    g2Bg1CntAddr = 0x400000au;
    g2Bg1CntOld = (*(u16 *) ((g2Bg1CntAddr) + (0)));
    g2Bg1CntCleared = ((g2Bg1CntOld) & ~(0x3u));
    g2Bg1CntNew = ((g2Bg1CntCleared) | (0x3u));
    *(u16 *) ((g2Bg1CntAddr) + (0)) = g2Bg1CntNew;
    g2Bg2CntAddr = 0x400000cu;
    g2Bg2CntOld = (*(u16 *) ((g2Bg2CntAddr) + (0)));
    g2Bg2CntCleared = ((g2Bg2CntOld) & ~(0x3u));
    g2Bg2CntNew = ((g2Bg2CntCleared) | (0x3u));
    *(u16 *) ((g2Bg2CntAddr) + (0)) = g2Bg2CntNew;
}

void StartConnectMessageFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x14, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x14);
    SetUpdateFunction(UpdateConnectMessageFadeIn);
}

void UpdateConnectMessageFadeIn(void) {
    ConnectMessageIds messageIds = gConnectMessageIds;
    s32 secondaryPairSecond;
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        GetSecondaryMenuPair(NULL, &secondaryPairSecond);
        CreateMessageBox(messageIds.mMessageIndices[secondaryPairSecond], 1, 1, -1, 0);
        SetUpdateFunction(UpdateConnectMessage);
    }
}
