#include "03/Menu/main_menu.h"
#include "03/Menu/main_menu_load_files.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Graphics/nce_file.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/selection_objects.h"
#include "03/System/application.h"
#include "03/Graphics/message_pool.h"
#include "03/Menu/main_menu_fade_in.h"
#include "wifi_settings_nvram_backup.h"
#include "03/Net/ap_entries.h"
#include "03/Graphics/dispcnt_window.h"
#include "vram_load_2d_graphics.h"
#include "03/Menu/edit_keyboard.h"
#include "registers.h"
#include "03/Menu/main_menu_first_screen.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/jb2_menu.h"
#include "03/Menu/way_ap_setup.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Menu/main_menu_fade_out.h"
#include "03/Net/exchange_result_records.h"
#include "03/Net/exchange_essid.h"
#include "03/Graphics/hl_scr.h"
#include "03/System/free_exp_heap_block.h"
#include "03/System/alloc_exp_heap_block.h"
#include "03/Graphics/text_canvas.h"
#include "03/System/exp_heap.h"
#include "thread_scheduler.h"
#include "reset_interrupts_halt.h"

MessageFile *gMessages;

void *gLanguageBmgNames[6] = {"msg/jap.bmg.l", "msg/eng.bmg.l", "msg/fre.bmg.l",
                              "msg/ger.bmg.l", "msg/ita.bmg.l", "msg/spa.bmg.l"};

void LoadMainFilesAndSetBgCnt(void) {
    CreateApStore();
    InitMessagesPool();
    InitSelectionObjects();
    InitHlScr();
    ClearSubScreenMessageShown();
    if (GetLanguageIndex() == 1 && HasModeFlag(2) != 0) {
        gMessages = LoadMessages("msg/usa.bmg.l");
    } else {
        gMessages = LoadMessages(gLanguageBmgNames[GetLanguageIndex()]);
    }
    LoadNceFile(1, BuildFilePathWithLanguage((u8 *) "char/jtMain.nce.l"));
    LoadNceFile(0, BuildFilePathWithLanguage((u8 *) "char/jbMain.nce.l"));
    LoadFileToVram("char/jtBgMain.ncg.l", CopyBgData_Bg1_Bottom);
    LoadFileToVram("char/jtBgMain.ncl.l", CopyPaletteBottom);
    LoadFileToVram("char/jtObjMain.ncg.l", TEQSub_Fn35Impl);
    LoadFileToVram("char/xtObjMain.ncl.l", TEQSub_Fn30Impl);
    LoadFileToVram("char/jbBgStep1.ncg.l", CopyBgData_Bg2_Top);
    LoadFileToVram("char/jbBgStep1.ncl.l", CopyPaletteTop);
    LoadFileToVram("char/jbObjMain.ncg.l", CopyTileDataTop_0);
    LoadFileToVram("char/ybObjMain.ncl.l", CopySomePaletteData);
    switch (GetMode()) {
        case 0:
            LoadFileToVram("char/jtTop.nsc.l", TEQSub_Fn25Impl);
            break;
        case 1:
            LoadFileToVram("char/jtStep1.nsc.l", TEQSub_Fn25Impl);
            break;
    }
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 3;
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
