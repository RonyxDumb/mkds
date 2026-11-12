#pragma once

#include "types.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02181f98.h"
#include "01/unk_021a9000.h"
#include "Main/Graphics/scene_text_init.h"
#include "01/code_02198854.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Scene/display_settings.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/unk_02175000.h"
#include "03/code_021b94b8.h"

// Object behind gNicknameScene.
typedef struct NicknameScene {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ void *mHeap;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mNextScene;
    /* 10 */ void *mSceneDisplaySettings;
    /* 14 */ struct Bmg *mCommonMessages;
} NicknameScene;

int GetNicknameSceneNextScene(void);
void NicknameWriteSceneTextRegistersWrapper(void);
void AdvanceNicknameScene(void);
void AdvanceNicknameSceneState3(void);
void AdvanceNicknameSceneState2(void);
void AdvanceNicknameSceneState1(void);
void AdvanceNicknameSceneState0(void);
void ReleaseNicknameSceneObject(void);
void InitNicknameSceneObject(void *heap, s16 a);

#include "00/code_021832d8.h"
