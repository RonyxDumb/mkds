#include "Main/Graphics/scene_text_init.h"
#include "Main/System/heap.h"

#include "Main/Unknown/code_02125de0.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_021274e0.h"
#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/code_0212802c.h"
#include "Main/Unknown/code_02128058.h"
#include "Main/Unknown/code_021287c0.h"
#include "Main/Unknown/code_021287cc.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/Menu/option_select_menu.h"

#pragma thumb on

void InitSceneText(void *heap, SceneTextInitParams *config) {
    TxtSystemArgs txtConfig;

    gSceneText = HeapAlloc(heap, 0x814);
    gSceneText->mSubCharOffset = 0x5800;
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
