#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

void ReleaseSceneText(void);

// What InitSceneText sets up: a use flag for the text system, select choises, select return and back screen, with the
// font, canvas flags and back screen kind they need.
typedef struct SceneTextInitParams {
    /* 00 */ BOOL mUseTxtSystem;
    /* 04 */ void *mTxtSystemFont;
    /* 08 */ s32 mUseCanvas1;
    /* 0c */ s32 mUseCanvas2;
    /* 10 */ s32 mUseCanvas3;
    /* 14 */ BOOL mUseSelectChoises;
    /* 18 */ void *mSelectChoisesFont;
    /* 1c */ BOOL mUseSelectReturn;
    /* 20 */ BOOL mUseBackScreen;
    /* 24 */ s32 mBackScreenKind;
} SceneTextInitParams;

// Start value of SceneText.mSubCharOffset; each loader that runs takes the current value and returns the lower one
// after its char data.
#define SCENE_TEXT_SUB_CHAR_OFFSET 0x5800

void InitSceneText(void *heap, SceneTextInitParams *config);

extern struct SceneText *gSceneText;
