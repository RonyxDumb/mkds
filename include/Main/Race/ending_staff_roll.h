#pragma once

#include "types.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Graphics/font_and_player_character.h"

// EndingStaffRollObject.mStaffRollFrames values at which something happens: the screen fades, the picture is no
// longer drawn, the staff text starts and the screen fades back. The frame count stops at the cap.
#define ENDING_STAFF_ROLL_FRAME_FADE_START 0x1a4
#define ENDING_STAFF_ROLL_FRAME_PICTURE_END 0x21c
#define ENDING_STAFF_ROLL_FRAME_TEXT_START 0x30c
#define ENDING_STAFF_ROLL_FRAME_FADE_TO_CLEAR_START 0x77a
#define ENDING_STAFF_ROLL_FRAME_CAP 0x7fffffff
#define ENDING_STAFF_ROLL_FADE_FRAMES 0x78

// The ending staff roll screen: its frame count, palette, chars and cell data and its OAM buffer.
typedef struct EndingStaffRollObject {
    /* 000 */ s32 mStaffRollFrames;
    /* 004 */ Nclr *mEndingStaffRollMO00Nclr;
    /* 008 */ Ncgr *mEndingStaffRollM00Ncgr;
    /* 00c */ NNSG2dCellDataWithBR *mCell;
    /* 010 */ RaceHudOamBuffer mOamBuffer;
} EndingStaffRollObject;

u16 UpdateEndingStaffRoll(void);
void DrawEndingStaffRoll(void);

void ClearEndingStaffRollPointer(void);

void UploadEndingStaffRollOam(void);
void InitEndingStaffRoll(void);

extern struct EndingStaffRollObject *gEndingStaffRoll;
