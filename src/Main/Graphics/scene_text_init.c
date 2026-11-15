#include "Main/Graphics/scene_text_init.h"
#include "Main/System/heap.h"

#include "Main/Graphics/back_screen.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/menu_screens_work.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
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

#pragma thumb off

#pragma thumb on

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
