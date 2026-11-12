#include "03/Menu/main_menu.h"
#include "03/code_021c2b28.h"
#include "03/unk_021da000.h"
#include "03/code_021d1c18.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/selection_objects.h"
#include "03/System/application.h"
#include "03/code_021c2530.h"
#include "03/code_021c2afc.h"
#include "03/code_021cb000.h"
#include "Main/Unknown/code_02151718.h"
#include "03/code_021cd2e0.h"
#include "03/code_021d1000.h"
#include "03/Graphics/dispcnt_window.h"
#include "gx_load2d.h"
#include "03/Menu/edit_keyboard.h"
#include "registers.h"
#include "03/code_021c2aa0.h"
#include "03/code_021d1dd0.h"
#include "03/Menu/jb2_menu.h"
#include "03/code_021c3000.h"
#include "03/code_021cb11c.h"
#include "03/code_021d1f70.h"
#include "03/code_021c2a74.h"
#include "03/code_021c2a28.h"
#include "03/unk_021d8000.h"
#include "03/Net/exchange_essid.h"
#include "03/Graphics/hl_scr.h"
#include "03/System/free_exp_heap_block.h"
#include "03/System/alloc_exp_heap_block.h"
#include "03/Graphics/text_canvas.h"
#include "03/unk_021d5000.h"
#include "03/System/exp_heap.h"
#include "os_thread.h"
#include "code_0200fc8c.h"

void LoadMainFilesAndSetBgCnt(void) {
    CreateApStore();
    InitMessagesPool();
    InitSelectionObjects();
    InitHlScr();
    ClearSubScreenMessageShown();
    if (GetLanguageIndex() == 1 && HasModeFlag(2) != 0) {
        gMessages = LoadMessages(gUsaBmgName);
    } else {
        gMessages = LoadMessages(gLanguageBmgNames[GetLanguageIndex()]);
    }
    LoadNceFile(1, BuildFilePathWithLanguage(gJtMainNceName));
    LoadNceFile(0, BuildFilePathWithLanguage(gJbMainNceName));
    LoadFileToVram(gJtBgMainNcgName, GXS_LoadBG1Char);
    LoadFileToVram(gJtBgMainNclName, GXS_LoadBGPltt);
    LoadFileToVram(gJtObjMainNcgName, GXS_LoadOBJ);
    LoadFileToVram(gXtObjMainNclName, GXS_LoadOBJPltt);
    LoadFileToVram(gJbBgStep1NcgName, GX_LoadBG2Char);
    LoadFileToVram(gJbBgStep1NclName, GX_LoadBGPltt);
    LoadFileToVram(gJbObjMainNcgName, GX_LoadOBJ);
    LoadFileToVram(gYbObjMainNclName, GX_LoadOBJPltt);
    switch (GetMode()) {
        case 0:
            LoadFileToVram(gJtTopNscName, GXS_LoadBG1Scr);
            break;
        case 1:
            LoadFileToVram(gJtStep1NscName, GXS_LoadBG1Scr);
            break;
    }
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    CombineDispcntBits(1, 2);
    CombineDispcntBits(0, 2);
    SetUpdateFunction(StartMainFadeIn);
}

void StartMainFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 2, 0x14);
    StartBlendBrightnessFade(2, 0, 2, 0x14);
    SetUpdateFunction(SelectFirstScreenByMode);
}

void SelectFirstScreenByMode(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        switch (GetMode()) {
            case 0:
                SetPrimaryMenuPair(0, 1);
                SetUpdateFunction(SetupJb2Menu);
                break;
            case 1:
                SetPrimaryMenuPair(1, 1);
                SetUpdateFunction(CreateAp);
                break;
        }
    }
}

void StartMainFadeOut(void) {
    StartBlendBrightnessFade(3, 1, 0x3f, 0x14);
    StartBlendBrightnessFade(3, 0, 0x3f, 0x14);
    SetUpdateFunction(ReleaseMainAndQuit);
}

void ReleaseMainAndQuit(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        FreeNceFile(1);
        FreeNceFile(0);
        ReleaseHlScr();
        ReleaseSelectionObjects();
        ReleaseMessages(gMessages);
        FreeMessagesPool();
        ReleaseApStore();
        SetQuitFlag();
    }
}

void StartExchangeWithStatusRecord(void) {
    gExchangeStatusRecord = AllocZeroedExpHeapBlock(0xc, -4);
    if (StartExchange(0xf, 0x40, StoreExchangeStatus, AllocExpHeapBlockWrapper, FreeExpHeapBlockWrapper, 0x800) != 1) {
        OS_Terminate();
    }
    OS_Sleep(0xa);
}

void StopExchangeWithStatusRecord(void) {
    if (StopExchange() != 1) {
        OS_Terminate();
    }
    FreeExpHeapBlockAndClearPointer(&gExchangeStatusRecord);
}

u32 GetExchangeOutcome(void) {
    ExchangeResult exchangeResult;
    switch (gExchangeStatusRecord->mStatus) {
        case 0:
        case 1:
        case 3:
        case 5:
            return 0;
        case 2:
            return 1;
        case 4:
            return 2;
        case 6:
            if (CopyExchangeResult(&exchangeResult) != 1) {
                OS_Terminate();
            }
            if (exchangeResult.mKind >= 0 && exchangeResult.mKind <= 3 && exchangeResult.mUnk_24 == 1) {
                return 3;
            }
            return 5;
        case 7:
            return 4;
    }
}

void StoreExchangeResultForAp(void) {
    ExchangeResult exchangeResult;
    if (CopyExchangeResult(&exchangeResult) != 1) {
        OS_Terminate();
    }
    WriteApWorkFromExchangeResult(&exchangeResult);
}

void StoreExchangeStatus(const ExchangeStatus *status) {
    *gExchangeStatusRecord = *status;
}
