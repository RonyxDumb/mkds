#pragma once

#include "types.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Race/grand_prix_record.h"
#include "Main/Race/course_time_text.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/menu.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"

typedef struct SceneNumbers SceneNumbers;

// Object behind gResultsGp, allocated by InitResultsGp.
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



void AdvanceResultsGp(SceneNumbers *sceneNumbers);
void InitResultsGp(void *heap, void *firstOamList, void *secondOamList);

extern const u16 gEngineMessageIndexTable[4];
extern const u16 gCupNameLeftCharIndices[8];
extern const u16 gCupRankCellIndexTable[8];
extern const u16 gResultsGpGradeCellIndices[8];
extern const u32 gResultsGpCupCourseIds[8][4];
extern const LabelCanvasEntry gResultsGpSubLabelCanvasEntries[16];
extern ResultsGp *gResultsGp;
