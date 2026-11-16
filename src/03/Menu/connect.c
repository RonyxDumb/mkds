#include "03/Menu/connect.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/wifi_menu_tables.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"

#include "03/System/exp_heap.h"
#include "00/Lib/DWC/access_point_alloc.h"
#include "00/Lib/DWC/access_point_manager.h"
#include "03/Net/exchange_wcm_state.h"
#include "03/System/application.h"
#include "03/Menu/jb4_error.h"
#include "03/Menu/jb4_error_setup.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/connect_done.h"
#include "03/Net/ap_entries.h"
#include "03/Sound/sound_seq.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/tasks.h"
#include "Main/Save/packed_wifi_info.h"
#include "cpu_copy_fill.h"
#include "reset_interrupts_halt.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Graphics/hl_scr.h"
#include "03/Menu/link_level.h"
#include "00/Lib/DWC/access_point_power_mode.h"

const DWCACConfig gConnectParamsTemplate = {
    (void *(*) ()) ConnectAllocExpHeapBlockWrapper, ConnectFreeExpHeapBlockWrapper, 3, 1, 0, 0};
u8 gConnectSucceeded;

void SetupConnect(void) {
    s32 secondaryPairSecond;
    gConnectSucceeded = 0;
    LoadConnectFilesAndSetBgCnt();
    GetSecondaryMenuPair(NULL, &secondaryPairSecond);
    if (secondaryPairSecond == 0) {
        ShowSubScreenMessage(0x7d, -1, 0);
    }
    CreateObjectsForMenuPair(2);
    if (secondaryPairSecond == 0) {
        LoadHlSetScr();
    }
    PrintMessage(0x76);
    CreateAnimatedIcon(0);
    StartConnectRequest();
    CreateLinkLevel(0);
    StartSoundSeq(0xc);
    SetUpdateFunction(StartConnectFadeIn);
}

void LoadConnectFilesAndSetBgCnt(void) {
    void *ncgName = &"char/jbBgStep3.ncg.l";
    void *loadBg2CharFunc = &GX_LoadBG2Char;
    u32 bg2CharLoadResult = LoadFileToVram(ncgName, loadBg2CharFunc);
    void *nclName = &"char/ybBgStep3.ncl.l";
    void *loadBgPlttFunc = &GX_LoadBGPltt;
    u32 bgPlttLoadResult = LoadFileToVram(nclName, loadBgPlttFunc);
    void *nscName = &"char/xb4Multi.nsc.l";
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
    u32 g2Bg0CntAddr;
    u32 g2Bg0CntOld;
    u32 g2Bg0CntCleared;
    u32 g2Bg0CntNew;
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
    g2Bg0CntAddr = 0x4000008u;
    g2Bg0CntOld = (*(u16 *) ((g2Bg0CntAddr) + (0)));
    g2Bg0CntCleared = ((g2Bg0CntOld) & ~(0x3u));
    g2Bg0CntNew = ((g2Bg0CntCleared) | (0x3u));
    *(u16 *) ((g2Bg0CntAddr) + (0)) = g2Bg0CntNew;
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

void StartConnectRequest(void) {
    s32 secondaryPairSecond;
    DWCACConfig connectParams;
    ApWorkCopy *record = GetApWorkCopy();
    MIi_CpuCopy32(&gConnectParamsTemplate, &connectParams, 0xc);
    GetSecondaryMenuPair(NULL, &secondaryPairSecond);
    if (secondaryPairSecond == 2) {
        connectParams.mConnectType = AUTO_CONNECT_TYPE_NWCUSBAP_SSID;
    } else {
        connectParams.mConnectType = record->mEntryIndex + 1;
    }
    if (DWC_AC_Create(&connectParams) == 0) {
        OS_Terminate();
    }
    if (secondaryPairSecond == 0) {
        DWCi_AC_InsertApInfo(record->mEntryIndex, record);
    }
    AddTask(0, AdvanceConnectRequest, NULL, 0x78);
}

void StartConnectFadeIn(void) {
    int secondaryPairSecond[1];
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    GetSecondaryMenuPair(NULL, secondaryPairSecond);
    if (secondaryPairSecond[0] == 0) {
        StartBlendBrightnessFade(2, 1, 1, 8);
        CombineDispcntBits(1, 1);
    }
    SetUpdateFunction(UpdateConnectFadeIn);
}

void UpdateConnectFadeIn(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        SetUpdateFunction(UpdateConnect);
    }
}

void UpdateConnect(void) {
    UpdateConnectInputNop();
    UpdateConnectNop();
    UpdateConnectResultNop();
}

void UpdateConnectInputNop(void) {}

void UpdateConnectNop(void) {}

void UpdateConnectResultNop(void) {}

void StartConnectFadeOut(void) {
    StartBlendBrightnessFade(3, 0, 0x15, 8);
    SetUpdateFunction(UpdateConnectFadeOut);
}

void UpdateConnectFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        SetUpdateFunction(UpdateConnectRelease);
    }
}

void UpdateConnectRelease(void) {
    ApStore *recordStore = GetApStore();
    if (DWC_AC_Destroy() != 0) {
        MI_CpuCopy8(GetPackedWiFiInfo(), recordStore->mPages[0].mPackedWiFiInfo, 0xe);
        MI_CpuCopy8(GetPackedWiFiInfo(), recordStore->mPages[1].mPackedWiFiInfo, 0xe);
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        ClearDispcntBits(0, 0x15);
        if (gConnectSucceeded == 0) {
            SetPrimaryMenuPair(0, 1);
            SetUpdateFunction(SetupJb4Error);
        } else {
            SetPrimaryMenuPair(0, 1);
            SetUpdateFunction(SetupConnectDone);
        }
    }
}

void AdvanceConnectRequest(TaskEntry *entry, void *arg) {
    s32 connectResult = DWC_AC_Process();
    if (connectResult != 0) {
        ReleaseLinkLevel();
        StopSoundSeq();
        if (connectResult > 0) {
            gConnectSucceeded = 1;
            StartSoundSeq(0x11);
        } else {
            SetJb4ErrorCode(DWC_AC_GetStatus());
            StartSoundSeq(0x12);
        }
        SetUpdateFunction(StartConnectFadeOut);
        RequestTaskRemoval(0, entry);
    }
}

u32 ConnectAllocExpHeapBlockWrapper(u32 unused, u32 size) {
    u32 allocatedBlock;
    u32 sizeThenAlignment = size;
    u32 allocFunctionAddress;
    allocatedBlock = (sizeThenAlignment) + (0u);
    sizeThenAlignment = 32u;
    allocFunctionAddress = (u32) &AllocExpHeapBlock;
    allocatedBlock = (u32) AllocExpHeapBlock(allocatedBlock, sizeThenAlignment);
    return allocatedBlock;
}

void ConnectFreeExpHeapBlockWrapper(void *unused, void *block) {
    FreeExpHeapBlock(block);
}
