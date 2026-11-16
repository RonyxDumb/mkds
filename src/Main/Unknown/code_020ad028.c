#include "Main/Unknown/code_020ad028.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void title_updateUI(void) {
    LayoutTableEntry *p;
    u32 w;
    s32 i;

    p = sTitleSceneState->mTitleTable;
    w = title_jn_ui_getBnclElementCount(sTitleSceneState->mTitleSBncl);
    for (i = 0; i <= 9; i++) {
        p[i].mVisible = 1;
    }
    for (i = 10; i <= 14; i++) {
        p[i].mVisible = 0;
    }
    for (i = 0; i <= 1; i++) {
        p[w + i].mVisible = 1;
    }
    jn_ui_setLabelColorParam(0, 15, sTitleSceneState->mTitleSBnll, p, sTitleSceneState->mTitleSBncl);
    jn_ui_setLabelColorParam(1, 15, sTitleSceneState->mTitleSBnll, p, sTitleSceneState->mTitleSBncl);
    switch (sTitleSceneState->mSelectedIndex) {
        case 0:
            if (sTitleSceneState->mState == 4) {
                p[0].mOffsetX = sTitleSceneState->mSelectedOffset;
                p[5].mOffsetX = sTitleSceneState->mSelectedOffset;
                p[10].mOffsetX = sTitleSceneState->mSelectedOffset;
            }
            if (sTitleSceneState->mState != 4 || sTitleSceneState->mSelectedPressed == FALSE || title_getFrameCounter() >= 5) {
                p[5].mVisible = 0;
                p[10].mVisible = 1;
            }
            break;
        case 1:
            if (sTitleSceneState->mState == 4) {
                p[1].mOffsetX = sTitleSceneState->mSelectedOffset;
                p[6].mOffsetX = sTitleSceneState->mSelectedOffset;
                p[11].mOffsetX = sTitleSceneState->mSelectedOffset;
            }
            if (sTitleSceneState->mState != 4 || sTitleSceneState->mSelectedPressed == FALSE || title_getFrameCounter() >= 5) {
                p[6].mVisible = 0;
                p[11].mVisible = 1;
            }
            break;
        case 2:
            if (sTitleSceneState->mState == 4) {
                p[2].mOffsetX = sTitleSceneState->mSelectedOffset;
                p[7].mOffsetX = sTitleSceneState->mSelectedOffset;
                p[12].mOffsetX = sTitleSceneState->mSelectedOffset;
            }
            if (sTitleSceneState->mState != 4 || sTitleSceneState->mSelectedPressed == FALSE || title_getFrameCounter() >= 5) {
                p[7].mVisible = 0;
                p[12].mVisible = 1;
            }
            break;
        case 3:
            if (sTitleSceneState->mState != 4 || sTitleSceneState->mSelectedPressed == FALSE || title_getFrameCounter() >= 5) {
                p[8].mVisible = 0;
                p[13].mVisible = 1;
                jn_ui_setLabelColorParam(0, 14, sTitleSceneState->mTitleSBnll, p, sTitleSceneState->mTitleSBncl);
            }
            break;
        case 4:
            if (sTitleSceneState->mState != 4 || sTitleSceneState->mSelectedPressed == FALSE || title_getFrameCounter() >= 5) {
                p[9].mVisible = 0;
                p[14].mVisible = 1;
                jn_ui_setLabelColorParam(1, 14, sTitleSceneState->mTitleSBnll, p, sTitleSceneState->mTitleSBncl);
            }
            break;
    }
}

#pragma thumb off
