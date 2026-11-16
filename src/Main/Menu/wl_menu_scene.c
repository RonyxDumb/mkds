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

struct WLMenuCallbacks *g_SomeFnTable[WL_MENU_CALLBACKS_COUNT] = {
    &gMultiSelectMemberGroupCallbacks, &gMultiSelectNSCallbacks,        &gMemberKeyStartCallbacks,
    &gMemberNoKeyStartCallbacks,       &gWLMenuMBChildMessageCallbacks, &gWLMenuMessageToRaceCallbacks,
    &gWLMenuMessageToResultCallbacks,  &gWLMenuMessageToMenuCallbacks};
struct WLMenuScene *gWLMenuScene;

void SetSomeDispcntTopMask(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

void SetSomeDispcntSubMask(u32 bits) {
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_EXOBJ_CH_MASK | REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

#pragma thumb on

void InitWLMenuScene(void *heap) {
    DisplaySettings *displaySettings;
    SceneTextInitParams sceneTextInitParams;

    gWLMenuScene = Mem_AllocateHeapAligned(heap, 0x874, HEAP_ALIGN_CACHE_LINE);
    WLMenuMI_CpuClearFast(gWLMenuScene, 0x874);
    displaySettings = CreateDisplayConfig(heap, gWLMenuSceneDisplaySettingsDesc);
    DisplayConfig_SetTopEngineBg1Config_0(displaySettings, 0, 0, 0, 0, 0xc, 0, 0);
    DisplayConfig_SetBottomEngineBg3Config_0(displaySettings, 2, 0, 0, 0, 0xf, 6);
    SetGlobalDisplayConfig(displaySettings);
    if (j_IsDwc_2() == 0) {
        sceneTextInitParams.mUseTxtSystem = 1;
        sceneTextInitParams.mTxtSystemFont = GetLoadedFont_from_thumb(1);
        sceneTextInitParams.mUseCanvas1 = 0;
        sceneTextInitParams.mUseCanvas2 = 1;
        sceneTextInitParams.mUseCanvas3 = 0;
        sceneTextInitParams.mUseSelectChoises = 0;
        sceneTextInitParams.mSelectChoisesFont = NULL;
        sceneTextInitParams.mUseSelectReturn = 1;
        sceneTextInitParams.mUseBackScreen = GetB488SomeMode() == 0;
        sceneTextInitParams.mBackScreenKind = 0;
        PrepareNavigationContextFiles_from_thumb();
        InitializeNavigationContext_from_thumb(heap, &sceneTextInitParams);
    }
    CreateGlobalNN_from_thumb(heap, gWLMenuScene);
    switch (GetB488SomeMode()) {
        case WL_MENU_KIND_JOIN_GROUP:
            gWLMenuScene->mRequestedCallbacksIndex = j_IsDwc_2() != 0
                                                         ? WL_MENU_CALLBACKS_MB_CHILD_MESSAGE
                                                         : WL_MENU_CALLBACKS_MEMBER_GROUP;
            InitWLMenuResetRaceSetup(heap);
            ResetConnection();
            break;
        case WL_MENU_KIND_TO_RACE:
            gWLMenuScene->mRequestedCallbacksIndex = WL_MENU_CALLBACKS_MESSAGE_TO_RACE;
            InitWLMenuRequestMPWaitRaceArchives(heap);
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
    gWLMenuScene->mCurrentCallbacks = g_SomeFnTable[gWLMenuScene->mRequestedCallbacksIndex];
    gWLMenuScene->mHeap = Mem_CreateChildExpHeap(heap);
    if (j_IsDwc_2() == 0) {
        MaybeVerifyMultiSelectFiles_from_thumb();
    }
    OamBuffer_SomeFn_from_thumb(gWLMenuScene, gWLMenuScene->mSubOam);
    SetSomeDispcntTopMask(0x10);
    SetSomeDispcntSubMask(0x10);
    gWLMenuScene->mCurrentCallbacks->mInit(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
}

void Scene_WLMenu_UpdateImpl_from_thumb(void *sceneNumbers) {
    s32 callbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
    WLMenuCallbacks *previousCallbacks;

    if (gWLMenuScene->mCurrentCallbacksIndex != callbacksIndex) {
        previousCallbacks = gWLMenuScene->mCurrentCallbacks;
        gWLMenuScene->mCurrentCallbacks = g_SomeFnTable[callbacksIndex];
        gWLMenuScene->mCurrentCallbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
        previousCallbacks->mRelease();
        gWLMenuScene->mCurrentCallbacks->mInit(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
    } else {
        OamBuffer_ResetValues16_from_thumb(gWLMenuScene, gWLMenuScene->mSubOam);
        callbacksIndex = gWLMenuScene->mCurrentCallbacks->mAdvance(sceneNumbers);
        if (callbacksIndex != -1) {
            gWLMenuScene->mRequestedCallbacksIndex = callbacksIndex;
        }
        AdvanceLinkLevelIcons();
        OamBuffer_SomeFn2_from_thumb(gWLMenuScene, gWLMenuScene->mSubOam);
    }
    if (j_IsDwc_2() == 0) {
        NavigationContext_OnSceneUpdate_from_thumb();
    }
}

#pragma thumb off

#pragma thumb on

void Scene_WLMenu_FinalizeImpl_from_thumb(void) {
    int isMultiBootChild;
    gWLMenuScene->mCurrentCallbacks->mRelease();
    isMultiBootChild = j_IsDwc_2();
    if (isMultiBootChild == 0) {
        DisposeNavigationContext_from_thumb();
    }
    ResetGlobalNN_from_thumb();
}

#pragma thumb off

u16 *GetBiosBootIndicatorRef(void) {
    return &gBootInfo->mBootType;
}

u32 IsDwc_2(void) {
    return *GetBiosBootIndicatorRef() == 2;
}

u32 j_IsDwc_2(void) {
    return IsDwc_2();
}

#pragma thumb on

void Scene_WLMenu_VblankImpl_from_thumb(void) {
    int isMultiBootChild;
    isMultiBootChild = j_IsDwc_2();
    if (isMultiBootChild == 0) {
        NavigationContext_OnSceneVblank_from_thumb();
    }
    gWLMenuScene->mCurrentCallbacks->mWriteRegisters();
    CopyOamBuffersToMemory_from_thumb(gWLMenuScene, gWLMenuScene->mSubOam);
}

WLMenuScanSlotPick *GetWLMenuSceneScanSlotPick(void) {
    return &gWLMenuScene->mScanSlotPick;
}

#pragma thumb off
