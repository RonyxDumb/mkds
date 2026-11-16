#include "00/Menu/wi_fi_states.h"
#include "00/Menu/wi_fi_state_machine.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Menu/wi_fi_states_release.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/Menu/wi_fi_login_menu.h"
#include "00/Menu/wi_fi_top_menu.h"
#include "00/Menu/wi_fi_select_character.h"
#include "00/Menu/wi_fi_select_kart.h"
#include "00/Menu/wi_fi_vs_course_select.h"
#include "00/Menu/wi_fi_connection_lost.h"
#include "00/Menu/wi_fi_aikotoba.h"
#include "00/Menu/wi_fi_aikotoba_check.h"
#include "00/Scene/wi_fi_menu_scene.h"
#include "Main/Menu/select_kart_data.h"
#include "Main/Race/race_setup.h"
#include "Main/Menu/wifi_vs_course_select_files.h"
#include "Main/Menu/player_entry_list.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/wi_fi_session_step.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Menu/message_screen.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/menu_shared_clear.h"

WiFiStates *gWiFiStates;

void ClearWiFiStateCallbacks(void) {
    gWiFiStates->mCallbacks.mInit = NULL;
    gWiFiStates->mCallbacks.mRelease = NULL;
    gWiFiStates->mCallbacks.mAdvance = NULL;
    gWiFiStates->mCallbacks.mWriteRegisters = NULL;
}

void LoadWiFiMenuSceneData(void) {
    LoadedPartPointer loadedPartPointer;
    Gfx_ReadCharGraphicsV2(&loadedPartPointer.mNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting_s_b.ncgr"));
    Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting_s_b.nclr"));
    MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_s_setting.nscr"));
    Gfx_ReadCharGraphicsV2(&loadedPartPointer.mNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_matching_s_b.ncgr"));
    Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_matching_s_b.nclr"));
    MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_matching_s.nscr"));
    Gfx_ReadCharGraphics(&loadedPartPointer.mNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_top_menu_s.nce.ncgr"));
    LoadCellBankFrom(&loadedPartPointer.mNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_top_menu_s.nce.ncer"));
    Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_top_menu_s_o.nclr"));
    Gfx_ReadCharGraphics(&loadedPartPointer.mNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting_s.nce.ncgr"));
    LoadCellBankFrom(&loadedPartPointer.mNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting_s.nce.ncer"));
    Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting_s_o.nclr"));
    Gfx_ReadCharGraphics(&loadedPartPointer.mNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_matching_s.nce.ncgr"));
    LoadCellBankFrom(&loadedPartPointer.mNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_matching_s.nce.ncer"));
    Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_matching_s_o.nclr"));
    Gfx_ReadCharGraphics(&loadedPartPointer.mNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba_s.nce.ncgr"));
    LoadCellBankFrom(&loadedPartPointer.mNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba_s.nce.ncer"));
    Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba_s_o.nclr"));
    Gfx_ReadCharGraphics(&loadedPartPointer.mNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba_check_m.nce.ncgr"));
    LoadCellBankFrom(&loadedPartPointer.mNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba_check_m.nce.ncer"));
    Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba_check_m_o.nclr"));
    VerifySelectCharacterFiles_from_thumb();
    VerifySelectKartFiles_from_thumb();
    LoadWiFiVSCourseSelectFiles();
    VerifySelectMenuFiles_from_thumb();
}

void InitWiFiStates(void *heap, s32 sceneNumber) {
    SceneTextInitParams sceneTextInitParams;
    StateMachine *sessionStateMachine;
    gWiFiStates = Mem_AllocateHeap(heap, sizeof(WiFiStates));
    gWiFiStates->mHeap = heap;
    gWiFiStates->mCounter = 0;
    InitializeGlobalCA_from_thumb(heap);
    gWiFiStates->mDisplaySettings = CreateWiFiStatesDisplaySettings(heap);
    CreateGlobalNN_from_thumb(heap, GetWiFiMenuMainOamList());
    sceneTextInitParams.mUseTxtSystem = TRUE;
    sceneTextInitParams.mTxtSystemFont = GetLoadedFont_from_thumb(1);
    sceneTextInitParams.mUseCanvas1 = 0;
    sceneTextInitParams.mUseCanvas2 = 0;
    sceneTextInitParams.mUseCanvas3 = 0;
    sceneTextInitParams.mUseSelectChoises = FALSE;
    sceneTextInitParams.mSelectChoisesFont = NULL;
    sceneTextInitParams.mUseSelectReturn = TRUE;
    sceneTextInitParams.mUseBackScreen = TRUE;
    sceneTextInitParams.mBackScreenKind = 1;
    PrepareNavigationContextFiles_from_thumb();
    InitializeNavigationContext_from_thumb(heap, &sceneTextInitParams);
    LoadWiFiMenuSceneData();
    AndAnotherAlloc_0_from_thumb(heap, GetWiFiMenuMainOamList());
    CreateGlobalCE_from_thumb(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
    RequestKartModelMenuCharacter(-1);
    RequestKartModelMenuKart(-1);
    ReleaseKartModelLoadSlotsForScene();
    gWiFiStates->mStateHeap = Mem_CreateChildExpHeap(heap);
    ClearWiFiStateCallbacks();
    gWiFiStates->mNextScene = -1;
    if (g_GlobalB488->mWiFiTopMenuRequested != FALSE) {
        sceneNumber = 0;
        g_GlobalB488->mWiFiTopMenuRequested = FALSE;
    }
    switch (sceneNumber) {
        case SCENE_TITLE:
            gWiFiStates->mPrevState = WIFI_STATE_SCENE_TITLE;
            gWiFiStates->mState = WIFI_STATE_TOP_MENU;
            RegisterWiFiTopMenuCallbacks();
            ResetWiFiSessionToOff();
            g_GlobalB488->mWiFiMenuStartKind = WIFI_MENU_START_TOP_MENU;
            break;
        case SCENE_WIFI_MENU:
            gWiFiStates->mPrevState = WIFI_STATE_SCENE_WIFI_MENU;
            gWiFiStates->mState = WIFI_STATE_TOP_MENU;
            RegisterWiFiTopMenuCallbacks();
            break;
        case SCENE_RACE:
        case SCENE_RESULT:
            switch (g_GlobalB488->mWiFiMenuStartKind) {
                case WIFI_MENU_START_TOP_MENU:
                    gWiFiStates->mState = WIFI_STATE_TOP_MENU;
                    RegisterWiFiTopMenuCallbacks();
                    break;
                case WIFI_MENU_START_VS_SETTING:
                    sessionStateMachine = &g_GlobalB->mStateMachine;
                    sessionStateMachine->mNextState = WIFI_SESSION_STATE_IDLE;
                    sessionStateMachine->mNextStateRequested = 1;
                    gWiFiStates->mState = WIFI_STATE_VS_SETTING;
                    RegisterWiFiVSSettingCallbacks();
                    break;
                case WIFI_MENU_START_SELECT_CHARACTER:
                    SetupWiFiSession(1);
                    gWiFiStates->mState = WIFI_STATE_SELECT_CHARACTER;
                    RegisterSelectCharacterCallbacks();
                    break;
                case WIFI_MENU_START_VS_COURSE_SELECT:
                    SetupWiFiSession(2);
                    CopyEntriesToRaceSetupCopy();
                    gWiFiStates->mState = WIFI_STATE_VS_COURSE_SELECT;
                    RegisterWiFiVSCourseSelectCallbacks();
                    break;
            }
            break;
        case SCENE_KEYBOARD:
            gWiFiStates->mPrevState = WIFI_STATE_SCENE_KEYBOARD;
            gWiFiStates->mState = WIFI_STATE_AIKOTOBA;
            RegisterWiFiAikotobaCallbacks();
            break;
        case SCENE_RECORD:
            switch (g_GlobalB488->mWiFiScene8StartKind) {
                case 0:
                    gWiFiStates->mPrevState = WIFI_STATE_SCENE_RECORD;
                    gWiFiStates->mState = WIFI_STATE_VS_SETTING;
                    RegisterWiFiVSSettingCallbacks();
                    break;
                case 1:
                    gWiFiStates->mPrevState = WIFI_STATE_SCENE_RECORD;
                    gWiFiStates->mState = WIFI_STATE_AIKOTOBA;
                    RegisterWiFiAikotobaCallbacks();
                    break;
            }
            break;
    }
    gWiFiStates->mNextState = WIFI_STATE_NONE;
    gWiFiStates->mCallbacks.mInit(gWiFiStates->mStateHeap);
    g_GlobalB488->mResultArchiveDl = 1;
}

void ReleaseWiFiStates(void) {
    if (gWiFiStates->mCallbacks.mRelease != NULL) {
        gWiFiStates->mCallbacks.mRelease();
    }
    ClearWiFiStateCallbacks();
    ReleasePlayerEntryList();
    ResetGlobalNN_from_thumb();
    DisposeNavigationContext_from_thumb();
    gWiFiStates = NULL;
}

void AdvanceWiFiStates(void) {
    if (gWiFiStates->mCallbacks.mAdvance != NULL) {
        gWiFiStates->mCallbacks.mAdvance();
    }
    if (gWiFiStates->mNextState != WIFI_STATE_NONE) {
        gWiFiStates->mCallbacks.mRelease();
        ClearWiFiStateCallbacks();
        Mem_DestroyHeap(gWiFiStates->mStateHeap);
        gWiFiStates->mStateHeap = Mem_CreateChildExpHeap(gWiFiStates->mHeap);
        switch (gWiFiStates->mNextState) {
            case WIFI_STATE_LOGIN_MENU:
                RegisterWiFiLoginMenuCallbacks();
                break;
            case WIFI_STATE_TOP_MENU:
                RegisterWiFiTopMenuCallbacks();
                break;
            case WIFI_STATE_VS_SETTING:
                RegisterWiFiVSSettingCallbacks();
                break;
            case WIFI_STATE_VS_MATCHING:
                RegisterWiFiVSMatchingCallbacks();
                break;
            case WIFI_STATE_SELECT_CHARACTER:
                RegisterSelectCharacterCallbacks();
                break;
            case WIFI_STATE_SELECT_KART:
                RegisterSelectKartCallbacks();
                break;
            case WIFI_STATE_VS_COURSE_SELECT:
                RegisterWiFiVSCourseSelectCallbacks();
                break;
            case WIFI_STATE_CONNECTION_LOST:
                RegisterWiFiConnectionLostCallbacks();
                break;
            case WIFI_STATE_AIKOTOBA:
                RegisterWiFiAikotobaCallbacks();
                break;
            case WIFI_STATE_AIKOTOBA_CHECK:
                RegisterWiFiAikotobaCheckCallbacks();
                break;
        }
        gWiFiStates->mPrevState = gWiFiStates->mState;
        gWiFiStates->mState = gWiFiStates->mNextState;
        gWiFiStates->mNextState = WIFI_STATE_NONE;
        if (gWiFiStates->mCallbacks.mInit != NULL) {
            gWiFiStates->mCallbacks.mInit(gWiFiStates->mStateHeap);
        }
    }
    NavigationContext_OnSceneUpdate_from_thumb();
    AdvanceLinkLevelIcons();
    gWiFiStates->mCounter++;
    if (gWiFiStates->mCounter > 0) {
        gWiFiStates->mCounter = 0;
    }
}

void WriteWiFiStatesRegisters(void) {
    if (gWiFiStates->mCallbacks.mWriteRegisters != NULL) {
        gWiFiStates->mCallbacks.mWriteRegisters();
    }
    NavigationContext_OnSceneVblank_from_thumb();
}

void SetWiFiStateCallbacks(const WiFiStateCallbacks *callbacks) {
    gWiFiStates->mCallbacks = *callbacks;
}

void RequestWiFiState(s32 nextState) {
    u32 requestedState = nextState;
    u32 wiFiStatesAddress;
    wiFiStatesAddress = (u32) &gWiFiStates;
    gWiFiStates->mNextState = requestedState;
}

s32 GetWiFiPrevState(void) {
    return gWiFiStates->mPrevState;
}

u32 GetWiFiNextScene(void) {
    return (gWiFiStates->mNextScene);
}

void SetWiFiNextScene(u32 nextScene) {
    gWiFiStates->mNextScene = (u16) nextScene;
}

u32 IsWiFiStatesCounterNotNegative(void) {
    if (0 <= gWiFiStates->mCounter) {
        return TRUE;
    }
    return FALSE;
}

#ifdef version_EUR
// In language 0 or 1 setting 2 has its own message.
u32 LookupWiFiVSSettingMessageIndex(u32 settingIndex) {
    u32 messageIndices[4] = {2, 3, 4, 5};
    u32 r = messageIndices[settingIndex];
    // placeholder: the offset from a null byte pointer keeps the copy of the language index (adds r1, r1, #0) that
    // the original makes before its compare.
    if (settingIndex == 2 && (u32) ((u8 *) 0 + g_GlobalP->mLanguageIndex) <= 1) {
        r = 6;
    }
    return r;
}
#else
u32 LookupWiFiVSSettingMessageIndex(u32 settingIndex) {
    u32 messageIndices[4] = {2, 3, 4, 5};
    return messageIndices[settingIndex];
}
#endif

u32 GetWiFiVSSettingIndex(void) {
    return gWiFiStates->mWiFiVSSettingIndex;
}

void SetWiFiVSSettingIndex(u32 settingIndex) {
    gWiFiStates->mWiFiVSSettingIndex = settingIndex;
}

s32 GetWiFiVSSettingFlag(void) {
    u32 vsSettingFlag;
    vsSettingFlag = gWiFiStates->mTimeLimitDisabled;
    return vsSettingFlag;
}

void SetWiFiVSSettingFlag(s32 flag) {
    u32 flagValue = flag;
    u32 statesPointerAddress;
    statesPointerAddress = (u32) &gWiFiStates;
    gWiFiStates->mTimeLimitDisabled = flagValue;
}

BOOL IsWiFiSessionOffOutsideLogin(void) {
    BOOL valid = TRUE;
    if (gWiFiStates != NULL && gWiFiStates->mState == WIFI_STATE_LOGIN_MENU) {
        valid = FALSE;
    }
    if (g_GlobalB->mStateMachine.mState == WIFI_SESSION_STATE_OFF && valid != FALSE) {
        return TRUE;
    }
    return FALSE;
}

BOOL IsWiFiSessionOffOutsideLoginWrapper(void) {
    return IsWiFiSessionOffOutsideLogin();
}
