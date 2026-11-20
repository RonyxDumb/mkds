#include "Main/Graphics/scene_text_init.h"
#include "Main/System/heap.h"

#include "Main/Graphics/back_screen.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "01/Menu/option_select_menu.h"

SceneText *gSceneText;

#pragma thumb on

void InitSceneText(void *heap, SceneTextInitParams *config) {
    TxtSystemArgs txtConfig;

    gSceneText = HeapAlloc(heap, sizeof(*gSceneText));
    gSceneText->mSubCharOffset = SCENE_TEXT_SUB_CHAR_OFFSET;
    gSceneText->mUseTxtSystem = FALSE;
    gSceneText->mUseSelectChoises = FALSE;
    gSceneText->mUseSelectReturn = FALSE;
    if (config->mUseTxtSystem != FALSE) {
        txtConfig.mFont = config->mTxtSystemFont;
        txtConfig.mUseCanvas1 = config->mUseCanvas1;
        txtConfig.mUseCanvas2 = config->mUseCanvas2;
        txtConfig.mUseCanvas3 = config->mUseCanvas3;
        txtConfig.mSubCharOffset = gSceneText->mSubCharOffset;
        gSceneText->mUseTxtSystem = TRUE;
        gSceneText->mSubCharOffset = InitTxtSystem(heap, &txtConfig);
    }
    if (config->mUseSelectChoises != FALSE) {
        gSceneText->mUseSelectChoises = TRUE;
        gSceneText->mSubCharOffset = InitSelectChoises(heap, config->mSelectChoisesFont, gSceneText->mSubCharOffset);
    }
    if (config->mUseSelectReturn != FALSE) {
        gSceneText->mUseSelectReturn = TRUE;
        gSceneText->mSubCharOffset = InitSelectReturn(heap, gSceneText->mSubCharOffset);
    }
    if (config->mUseBackScreen != FALSE) {
        gSceneText->mBackScreenKind = config->mBackScreenKind;
        InitBackScreenDisplay();
        gSceneText->mSubCharOffset = LoadBackScreen(gSceneText->mSubCharOffset);
    }
}

void ReleaseSceneText(void) {
    if (gSceneText->mUseTxtSystem != FALSE) {
        ClearTxtSystemPointer();
    }
    if (gSceneText->mUseSelectChoises != FALSE) {
        ClearSelectChoisesPointer();
    }
    if (gSceneText->mUseSelectReturn != FALSE) {
        ClearSelectReturnPointer();
    }
    *&gSceneText = NULL;
}

#pragma thumb off
