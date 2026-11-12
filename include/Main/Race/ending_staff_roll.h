#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Graphics/font_and_player_character.h"

// Object behind gEndingStaffRoll.
typedef struct EndingStaffRollObject {
    /* 000 */ s32 mStaffRollFrames;
    /* 004 */ Nclr *mEndingStaffRollMO00Nclr;
    /* 008 */ Ncgr *mEndingStaffRollM00Ncgr;
    /* 00c */ NNSG2dCellDataWithBR *mCell;
    /* 010 */ RaceHudOamBuffer mOamBuffer;
} EndingStaffRollObject;

u16 UpdateEndingStaffRoll(void);
void DrawEndingStaffRoll(void);
