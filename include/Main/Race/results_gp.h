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
#include "font_glyph_layout.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Menu/multi_select_member_group.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"

typedef struct SceneNumbers SceneNumbers;

// The three best values of ResultsGp.mGrade (0 to 7, higher is better), the ones that start a sequence.
typedef enum ResultsGpGrade {
    RESULTS_GP_GRADE_THIRD_BEST = 5,
    RESULTS_GP_GRADE_SECOND_BEST = 6,
    RESULTS_GP_GRADE_BEST = 7,
} ResultsGpGrade;

// Values GetLowestGrandPrixRecordValue returns once every Grand Prix record has a grade of at least the third best: the
// lowest grade over all records is the third best, the second best or the best (0 when a record is lower or missing).
#define GP_LOWEST_RECORD_THIRD_BEST 1
#define GP_LOWEST_RECORD_SECOND_BEST 2
#define GP_LOWEST_RECORD_BEST 3

// Number of cup ranks that get a trophy: a cup rank index below it is a trophy rank.
#define CUP_RANK_TROPHY_COUNT 3
// TimeRecord.mCupRank of a rank without a trophy.
#define CUP_RANK_NO_TROPHY 3
// Values of ResultsGp.mState: mStateFrames counts up to the frame limit and the scene waits for A or a new pair, a text
// is open and waits to close, the scene is left.
#define RESULTS_GP_STATE_COUNTING_FRAMES 0
#define RESULTS_GP_STATE_TEXT_OPEN 1
#define RESULTS_GP_STATE_LEFT 2

// The Grand Prix results screen: its cell file sets and oam lists, cup, grade and cup rank index, the common and secret
// messages, the state with its frames, and the secret message mask.
typedef struct ResultsGp {
    /* 00 */ CellFileSet mCellFileSets[2];
    /* 38 */ void *mOamLists[2];
    /* 40 */ s32 mCupIndex;
    /* 44 */ s32 mGrade;
    /* 48 */ s32 mCupRankIndex;
    /* 4c */ Bmg *mCommonMessages;
    /* 50 */ Bmg *mSecretMessages;
    /* 54 */ s32 mState;
    /* 58 */ u32 mSecretMessageMask;
    /* 5c */ s32 mStateFrames; /* counted only in state 0 */
} ResultsGp;



void AdvanceResultsGp(SceneNumbers *sceneNumbers);
void InitResultsGp(void *heap, void *firstOamList, void *secondOamList);

extern const u16 gEngineMessageIndexTable[4];
extern const u16 gCupNameLeftCellIndices[8];
extern const u16 gCupRankCellIndexTable[8];
extern const u16 gResultsGpGradeCellIndices[8];
extern const u32 gResultsGpCupCourseIds[8][4];
extern const LabelCanvasEntry gResultsGpSubLabelCanvasEntries[16];
extern ResultsGp *gResultsGp;
