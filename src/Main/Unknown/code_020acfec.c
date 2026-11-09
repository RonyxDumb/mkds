#include "Main/Unknown/code_020acfec.h"

#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020ad028.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void SetupAndDrawTitleTable(void) {
    TitleScene *titleScene;
    SetupTitleTable();
    titleScene = gTitleScene;
    DrawLayoutTable(titleScene->mTitleSBncl, titleScene->mTitleSNceNcer, titleScene->mTitleSBnll, &titleScene->mSubOam,
                    titleScene->mTitleTable);
}

#pragma thumb off

#pragma thumb on
u32 func_020acfec(u32 value) {
    return func_020ad230(value);
}
#pragma thumb off
