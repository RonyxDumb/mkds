#include "Main/Menu/logo_scene.h"
#include "registers.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Menu/logo_state.h"
#include "Main/Menu/logo_backup_read_and_reset.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/state_machine_init.h"
#include "Main/System/result_archive_path.h"
#include "Main/Save/backup_reset.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "arena_cache_init.h"
#include "display_blend_affine_setup.h"
#include "vram_load_2d_graphics.h"
#include "Main/Scene/display_settings_descs.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

void LoadLogoScreenGraphics(Bg1Files *files, s32 mainScreen, const char *paletteFileName, const char *charsFileName,
                           const char *screenMapFileName) {
    Gfx_ReadPalette(&files->mPalette, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(paletteFileName));
    DC_SomeClean(files->mPalette->mData, files->mPalette->mDataSize);
    if (mainScreen != 0) {
        CopyPaletteTop(files->mPalette->mData, 0, files->mPalette->mDataSize);
    } else {
        CopyPaletteBottom(files->mPalette->mData, 0, files->mPalette->mDataSize);
    }
    Gfx_ReadCharGraphics(&files->mChars, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(charsFileName));
    DC_SomeClean(files->mChars->mData, files->mChars->mDataSize);
    if (mainScreen != 0) {
        CopyBgData_Bg1_Top(files->mChars->mData, 0, files->mChars->mDataSize);
    } else {
        CopyBgData_Bg1_Bottom(files->mChars->mData, 0, files->mChars->mDataSize);
    }
    MaybeReadScreenBlock_0(&files->mScreenMap, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(screenMapFileName));
    DC_SomeClean(files->mScreenMap->mData, files->mScreenMap->mDataSize);
    if (mainScreen != 0) {
        TEQSub_Fn9Impl(files->mScreenMap->mData, 0, files->mScreenMap->mDataSize);
    } else {
        TEQSub_Fn25Impl(files->mScreenMap->mData, 0, files->mScreenMap->mDataSize);
    }
}

void InitializeLogoContext(void *heap) {
    SceneTextInitParams arg;
    DisplaySettings *displaySettings;
    g_LogoContext = Mem_AllocateHeap(heap, 60);
    displaySettings = CreateDisplayConfig(heap, gLogoSceneDisplaySettingsDesc);
    DisplayEngineConfig_SetBg1Config(&displaySettings->mMainBgRecords, 1, 0, 0, 0, 0, 1, 0);
    DisplayEngineConfig_SetBg1Config(&displaySettings->mSubBgRecords, 1, 0, 0, 0, 0, 2, 0);
    SetGlobalDisplayConfig(displaySettings);
    LoadLogoScreenGraphics(&g_LogoContext->mMainBg, 1, gLogoMainBgPaletteFileName, gLogoMainBgCharsFileName,
                          gLogoMainBgScreenMapFileName);
    LoadLogoScreenGraphics(&g_LogoContext->mSubBg, 0, gLogoSubBgPaletteFileName, gLogoSubBgCharsFileName,
                          gLogoSubBgScreenMapFileName);
    StateDualHandler_Create(&g_LogoContext->mStateMachine, g_E7FnList0, 12, NULL);
    g_LogoContext->mResetBackupRequested = 0;
    g_LogoContext->mReadBackupFrames = 0;
    g_LogoContext->mCommonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(gLogoSceneCommonBmgFileName);
    arg.mUseTxtSystem = TRUE;
    arg.mTxtSystemFont = GetLoadedFont_from_thumb(1);
    arg.mUseCanvas1 = 0;
    arg.mUseCanvas3 = 0;
    arg.mUseSelectChoises = FALSE;
    arg.mSelectChoisesFont = NULL;
    arg.mUseSelectReturn = FALSE;
    arg.mUseBackScreen = FALSE;
    arg.mBackScreenKind = 0;
    arg.mUseCanvas2 = 1;
    PrepareNavigationContextFiles_from_thumb();
    InitializeNavigationContext_from_thumb(heap, &arg);
}

void Scene_Logo_FinalizeImpl(void) {
    s32 outputEffect;
    s32 soundMode;
    outputEffect = 0;
    g_LogoContext = NULL;
    soundMode = g_SaveDataHolder->mFirstBlock->mSoundMode;
    switch (soundMode) {
        case SOUND_MODE_STEREO:
            break;
        case SOUND_MODE_HEADPHONES:
            outputEffect = 2;
            break;
        case SOUND_MODE_SURROUND:
        default:
            outputEffect = 1;
            break;
    }
    SetSoundOutputEffect(outputEffect);
    DisposeNavigationContext_from_thumb();
}

void Scene_Logo_VBlankImpl(void) {
    s32 brightness;
    s32 frames;
    brightness = 0;
    NavigationContext_OnSceneVblank_from_thumb();
    frames = g_LogoContext->mReadBackupFrames;
    if (frames > 90) {
        brightness = (-(frames - 90) * 16) / 30;
    }
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 2, brightness);
    G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 2, brightness);
}

void Scene_Logo_UpdateImpl(SceneNumbers *sceneNumbers) {
    StateDualHandler_Execute(&g_LogoContext->mStateMachine);
    if (sceneNumbers != NULL && g_LogoContext->mStateMachine.mState == LOGO_STATE_END) {
        sceneNumbers->mNextScene = 0;
    }
    NavigationContext_OnSceneUpdate_from_thumb();
}

void Logo_StateHandler_ReadSaveData_First(void *stateObject) {
    ReadSaveData_NonGhost_from_thumb();
    g_LogoContext->mUnk_2c_1 = 0;
}

void Logo_StateHandler_ReadSaveData_Second(void *stateObject) {
    s32 slotIndex;
    StateMachine *stateMachine;
    g_LogoContext->mReadBackupFrames = g_LogoContext->mReadBackupFrames + 1;
    if (g_LogoContext->mReadBackupFrames > LOGO_READ_BACKUP_FRAMES) {
        stateMachine = &g_LogoContext->mStateMachine;
        stateMachine->mNextState = LOGO_STATE_WAIT_BACKUP_READ;
        stateMachine->mNextStateRequested = 1;
    }
    slotIndex = GetSomeCYId_9();
    if ((g_GlobalCYT[slotIndex].mBits & PAD_KEYS_FACE_AND_SHOULDER) != PAD_KEYS_FACE_AND_SHOULDER) {
        return;
    }
    g_LogoContext->mResetBackupRequested = 1;
}
