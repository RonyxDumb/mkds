#include "Main/Menu/wl_menu_scene.h"

#include "Main/Graphics/oam_upload.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Menu/message_screen.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/Menu/multi_select_ns.h"
#include "Main/Menu/multi_select_ns_layout_count.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Menu/wl_menu_kind.h"
#include "Main/Menu/wl_menu_bg.h"
#include "Main/Menu/multi_select_files.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Race/grand_prix_record.h"
#include "Main/Net/connection.h"
#include "Main/Menu/menu.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Menu/label_palette_indices.h"
#include "Main/Menu/wl_menu_message.h"
#include "registers.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Scene/display_settings_descs.h"

struct WLMenuCallbacks *gWLMenuCallbacks[WL_MENU_CALLBACKS_COUNT] = {
    &gMultiSelectMemberGroupCallbacks, &gMultiSelectNSCallbacks,        &gMemberKeyStartCallbacks,
    &gMemberNoKeyStartCallbacks,       &gWLMenuMBChildMessageCallbacks, &gWLMenuMessageToRaceCallbacks,
    &gWLMenuMessageToResultCallbacks,  &gWLMenuMessageToMenuCallbacks};
struct WLMenuScene *gWLMenuScene;

void WLMenuGX_SetOBJVRamModeChar(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

void WLMenuGXS_SetOBJVRamModeChar(u32 bits) {
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_EXOBJ_CH_MASK | REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

#pragma thumb on

void InitWLMenuScene(void *heap) {
    DisplaySettings *displaySettings;
    SceneTextInitParams sceneTextInitParams;

    gWLMenuScene = HeapAllocAligned(heap, 0x874, HEAP_ALIGN_CACHE_LINE);
    WLMenuMI_CpuClearFast(gWLMenuScene, 0x874);
    displaySettings = CreateDisplaySettings(heap, gWLMenuSceneDisplaySettingsDesc);
    WLMenuSetMainBg1Record(displaySettings, 0, 0, 0, 0, 0xc, 0, 0);
    WLMenuSetSubBg3RecordParams(displaySettings, 2, 0, 0, 0, 0xf, 6);
    InitDisplayFromSettings(displaySettings);
    if (WLMenuMB_IsMultiBootChildWrapper() == 0) {
        sceneTextInitParams.mUseTxtSystem = 1;
        sceneTextInitParams.mTxtSystemFont = GetFontByIndex(1);
        sceneTextInitParams.mUseCanvas1 = 0;
        sceneTextInitParams.mUseCanvas2 = 1;
        sceneTextInitParams.mUseCanvas3 = 0;
        sceneTextInitParams.mUseSelectChoises = 0;
        sceneTextInitParams.mSelectChoisesFont = NULL;
        sceneTextInitParams.mUseSelectReturn = 1;
        sceneTextInitParams.mUseBackScreen = GetWLMenuKind() == WL_MENU_KIND_MEMBER_GROUP;
        sceneTextInitParams.mBackScreenKind = 0;
        LoadTxtSystemAndSelectChoisesAndSelectReturnData();
        InitSceneText(heap, &sceneTextInitParams);
    }
    InitLinkLevelIcons(heap, gWLMenuScene);
    switch (GetWLMenuKind()) {
        case WL_MENU_KIND_MEMBER_GROUP:
            gWLMenuScene->mRequestedCallbacksIndex = WLMenuMB_IsMultiBootChildWrapper() != 0
                                                         ? WL_MENU_CALLBACKS_MB_CHILD_MESSAGE
                                                         : WL_MENU_CALLBACKS_MEMBER_GROUP;
            InitWLMenuResetRaceSetup(heap);
            ResetConnection();
            break;
        case WL_MENU_KIND_TO_RACE:
            gWLMenuScene->mRequestedCallbacksIndex = WL_MENU_CALLBACKS_MESSAGE_TO_RACE;
            InitWLMenuRequestMPWaitRaceArchivesForNextRace(heap);
            break;
        case WL_MENU_KIND_TO_RESULT:
            gWLMenuScene->mRequestedCallbacksIndex = WL_MENU_CALLBACKS_MESSAGE_TO_RESULT;
            InitWLMenuRequestMPWaitResultArchives(heap);
            break;
        case WL_MENU_KIND_TO_MENU:
            gWLMenuScene->mRequestedCallbacksIndex = WL_MENU_CALLBACKS_MESSAGE_TO_MENU;
            InitWLMenuRequestMPWaitMenuArchives(heap);
            break;
    }
    gWLMenuScene->mCurrentCallbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
    gWLMenuScene->mCurrentCallbacks = gWLMenuCallbacks[gWLMenuScene->mRequestedCallbacksIndex];
    gWLMenuScene->mHeap = CreateExpHeapFromMaxFree(heap);
    if (WLMenuMB_IsMultiBootChildWrapper() == 0) {
        LoadMultiSelectFiles();
    }
    ResetOamLists(gWLMenuScene, gWLMenuScene->mSubOam);
    WLMenuGX_SetOBJVRamModeChar(0x10);
    WLMenuGXS_SetOBJVRamModeChar(0x10);
    gWLMenuScene->mCurrentCallbacks->mInit(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
}

void AdvanceWLMenuScene(void *sceneNumbers) {
    s32 callbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
    WLMenuCallbacks *previousCallbacks;

    if (gWLMenuScene->mCurrentCallbacksIndex != callbacksIndex) {
        previousCallbacks = gWLMenuScene->mCurrentCallbacks;
        gWLMenuScene->mCurrentCallbacks = gWLMenuCallbacks[callbacksIndex];
        gWLMenuScene->mCurrentCallbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
        previousCallbacks->mRelease();
        gWLMenuScene->mCurrentCallbacks->mInit(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
    } else {
        ClearOamListCounts(gWLMenuScene, gWLMenuScene->mSubOam);
        callbacksIndex = gWLMenuScene->mCurrentCallbacks->mAdvance(sceneNumbers);
        if (callbacksIndex != -1) {
            gWLMenuScene->mRequestedCallbacksIndex = callbacksIndex;
        }
        AdvanceLinkLevelIcons();
        HideUnusedOams(gWLMenuScene, gWLMenuScene->mSubOam);
    }
    if (WLMenuMB_IsMultiBootChildWrapper() == 0) {
        AdvanceSceneText();
    }
}

#pragma thumb off

#pragma thumb on

void ReleaseWLMenuScene(void) {
    int isMultiBootChild;
    gWLMenuScene->mCurrentCallbacks->mRelease();
    isMultiBootChild = WLMenuMB_IsMultiBootChildWrapper();
    if (isMultiBootChild == 0) {
        ReleaseSceneText();
    }
    ClearLinkLevelIconsPointer();
}

#pragma thumb off

u16 *WLMenuMB_GetMultiBootParam(void) {
    return &gBootInfo->mBootType;
}

u32 WLMenuMB_IsMultiBootChild(void) {
    return *WLMenuMB_GetMultiBootParam() == 2;
}

u32 WLMenuMB_IsMultiBootChildWrapper(void) {
    return WLMenuMB_IsMultiBootChild();
}

#pragma thumb on

void WriteWLMenuSceneRegisters(void) {
    int isMultiBootChild;
    isMultiBootChild = WLMenuMB_IsMultiBootChildWrapper();
    if (isMultiBootChild == 0) {
        WriteSceneTextRegisters();
    }
    gWLMenuScene->mCurrentCallbacks->mWriteRegisters();
    UploadOamLists(gWLMenuScene, gWLMenuScene->mSubOam);
}

WLMenuScanSlotPick *GetWLMenuSceneScanSlotPick(void) {
    return &gWLMenuScene->mScanSlotPick;
}

#pragma thumb off
