#pragma once

#include "types.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_0202a340.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02174000.h"

typedef struct SceneNumbersView SceneNumbersView;

// Object behind gpres_sState, allocated by gpres_init.
typedef struct ResultsGp {
    /* 00 */ CellFileSet mCellFileSets[2];
    /* 38 */ void *mOamLists[2];
    /* 40 */ s32 mCupIndex;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mCupRankIndex;
    /* 4c */ Bmg *mCommonMessages;
    /* 50 */ Bmg *mSecretMessages;
    /* 54 */ s32 mState;
    /* 58 */ u32 mSecretMessageMask;
    /* 5c */ s32 mState0Frames;
} ResultsGp;

extern ResultsGp *gpres_sState;

extern const char aCommon_bmg_13[];
extern const char aSecret_bmg[];
extern const char aResults_gp_m_b[];
extern const char aResults_gp_m_0[];
extern const char aResults_gp_m1_[];
extern const char aResults_gp_m2_[];
extern const char aResults_gp_m_n[];
extern const char aResults_gp_m_1[];
extern const char aResults_gp_m_o[];
extern const char aResults_gp_m_2[];
extern const char aResults_gp_m_4[];
extern const char aResults_gp_s_b[];
extern const char aResults_gp_s_0[];
extern const char aResults_gp_s_n[];
extern const char aResults_gp_s_5[];
extern const char aResults_gp_s_3[];
extern const char aResults_gp_s_o[];
extern const char aResults_gp_s_4[];
extern const char aResults_gp_s_1[];
extern const char aCup_name_lef_2[];
extern const char aCup_name_lef_0[];
extern const char aCup_name_left_[];
extern u16 gpres_sCCModeStringIds[];
extern u16 gpres_sCupCellIds[];
extern u16 gCupRankCellIndexTable[];
extern u16 data_02153888[];
extern u32 gpres_sCupCourses[][4];
extern Unk02153918 data_02153918[];

void gpres_update(SceneNumbersView *sceneNumbers);
void gpres_init(void *heap, void *firstOamList, void *secondOamList);
