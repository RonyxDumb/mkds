#pragma once

#include "types.h"

// Argument block of func_02125de0 (ten words read from it).
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

void func_02125de0(void *heap, SceneTextInitParams *config);
