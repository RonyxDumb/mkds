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
#include "Main/Sound/sound_handle_accessors_and_mission_count_seq.h"
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
#include "capture_output_effect.h"

void LoadBg1FromSceneFiles(Bg1Files *files, s32 mainScreen, const char *paletteFileName, const char *charsFileName,
                           const char *screenMapFileName) {
    LoadNclrData(&files->mPalette, FindSceneFile(paletteFileName));
    DC_StoreRange(files->mPalette->mData, files->mPalette->mDataSize);
    if (mainScreen != 0) {
        GX_LoadBGPltt(files->mPalette->mData, 0, files->mPalette->mDataSize);
    } else {
        GXS_LoadBGPltt(files->mPalette->mData, 0, files->mPalette->mDataSize);
    }
    LoadNcgrData2(&files->mChars, FindSceneFile(charsFileName));
    DC_StoreRange(files->mChars->mData, files->mChars->mDataSize);
    if (mainScreen != 0) {
        GX_LoadBG1Char(files->mChars->mData, 0, files->mChars->mDataSize);
    } else {
        GXS_LoadBG1Char(files->mChars->mData, 0, files->mChars->mDataSize);
    }
    LoadNscrData(&files->mScreenMap, FindSceneFile(screenMapFileName));
    DC_StoreRange(files->mScreenMap->mData, files->mScreenMap->mDataSize);
    if (mainScreen != 0) {
        GX_LoadBG1Scr(files->mScreenMap->mData, 0, files->mScreenMap->mDataSize);
    } else {
        GXS_LoadBG1Scr(files->mScreenMap->mData, 0, files->mScreenMap->mDataSize);
    }
}

void InitLogoScene(void *heap) {
    SceneTextInitParams arg;
    DisplaySettings *displaySettings;
    gLogoScene = HeapAlloc(heap, 60);
    displaySettings = CreateDisplaySettings(heap, gLogoSceneDisplaySettingsDesc);
    SetBg1Record(&displaySettings->mMainBgRecords, 1, 0, 0, 0, 0, 1, 0);
    SetBg1Record(&displaySettings->mSubBgRecords, 1, 0, 0, 0, 0, 2, 0);
    InitDisplayFromSettings(displaySettings);
    LoadBg1FromSceneFiles(&gLogoScene->mMainBg, 1, gLogoMainBgPaletteFileName, gLogoMainBgCharsFileName,
                          gLogoMainBgScreenMapFileName);
    LoadBg1FromSceneFiles(&gLogoScene->mSubBg, 0, gLogoSubBgPaletteFileName, gLogoSubBgCharsFileName,
                          gLogoSubBgScreenMapFileName);
    InitStateMachine(&gLogoScene->mStateMachine, gLogoStateTable, 12, NULL);
    gLogoScene->mResetBackupRequested = 0;
    gLogoScene->mReadBackupFrames = 0;
    gLogoScene->mCommonMessages = FindFileInLoadedArchives(gLogoSceneCommonBmgFileName);
    arg.mUseTxtSystem = TRUE;
    arg.mTxtSystemFont = GetFontByIndex(1);
    arg.mUseCanvas1 = 0;
    arg.mUseCanvas3 = 0;
    arg.mUseSelectChoises = FALSE;
    arg.mSelectChoisesFont = NULL;
    arg.mUseSelectReturn = FALSE;
    arg.mUseBackScreen = FALSE;
    arg.mBackScreenKind = 0;
    arg.mUseCanvas2 = 1;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &arg);
}

void ApplySavedSoundMode(void) {
    s32 outputEffect;
    s32 soundMode;
    outputEffect = SOUND_OUTPUT_EFFECT_NONE;
    gLogoScene = NULL;
    soundMode = gBackupBuffers->mFirstBlock->mSoundMode;
    switch (soundMode) {
        case SOUND_MODE_STEREO:
            break;
        case SOUND_MODE_HEADPHONES:
            outputEffect = SOUND_OUTPUT_EFFECT_HEADPHONE;
            break;
        case SOUND_MODE_SURROUND:
        default:
            outputEffect = SOUND_OUTPUT_EFFECT_SURROUND;
            break;
    }
    SetSoundOutputEffect(outputEffect);
    ReleaseSceneText();
}

void WriteLogoSceneRegisters(void) {
    s32 brightness;
    s32 frames;
    brightness = 0;
    WriteSceneTextRegisters();
    frames = gLogoScene->mReadBackupFrames;
    if (frames > 90) {
        brightness = (-(frames - 90) * 16) / 30;
    }
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 2, brightness);
    G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 2, brightness);
}

void UpdateLogoScene(SceneNumbers *sceneNumbers) {
    AdvanceStateMachine(&gLogoScene->mStateMachine);
    if (sceneNumbers != NULL && gLogoScene->mStateMachine.mState == LOGO_STATE_END) {
        sceneNumbers->mNextScene = SCENE_TITLE;
    }
    AdvanceSceneText();
}

void EnterLogoReadBackup(void *stateObject) {
    StartReadBackupFirstBlockAndRecords();
    gLogoScene->mUnk_2c_1 = 0;
}

void UpdateLogoReadBackup(void *stateObject) {
    s32 slotIndex;
    StateMachine *stateMachine;
    gLogoScene->mReadBackupFrames = gLogoScene->mReadBackupFrames + 1;
    if (gLogoScene->mReadBackupFrames > LOGO_READ_BACKUP_FRAMES) {
        stateMachine = &gLogoScene->mStateMachine;
        stateMachine->mNextState = LOGO_STATE_WAIT_BACKUP_READ;
        stateMachine->mNextStateRequested = 1;
    }
    slotIndex = GetPadInputSlot();
    if ((gInputSlots[slotIndex].mBits & PAD_KEYS_A_B_X_Y_L_R) != PAD_KEYS_A_B_X_Y_L_R) {
        return;
    }
    gLogoScene->mResetBackupRequested = 1;
}
