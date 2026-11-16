#include "Main/Unknown/code_020acfec.h"

#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020ad028.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void title_renderUI(void) {
    TitleScene *titleScene;
    title_updateUI();
    titleScene = sTitleSceneState;
    jn_ui_renderElements(titleScene->mTitleSBncl, titleScene->mTitleSNceNcer, titleScene->mTitleSBnll, &titleScene->mSubOam,
                    titleScene->mTitleTable);
}

#pragma thumb off

#pragma thumb on
u32 title_buttonsInStateVblank(u32 value) {
    u32 value0 = value;
    u32 functionAddress;
    functionAddress = (u32) &func_020ad230;
    value0 = func_020ad230(value0);
    return value0;
}
#pragma thumb off
