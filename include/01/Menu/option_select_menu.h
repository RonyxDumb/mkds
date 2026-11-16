#pragma once

#include "types.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/System/backup_net_camera_work.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/scene_text_init.h"

// The x and y offset of one group of cells of OptionSelectMenu (mGroupOffsets).
typedef struct OptionSelectMenuGroupOffset {
    /* 00 */ s16 mOffsetX;
    /* 02 */ s16 mOffsetY;
} OptionSelectMenuGroupOffset;

// Values of OptionSelectMenu.mIndex and of the touch rectangle ids 0 to 2: the two setting rows, then the OK entry;
// mRowValues and mOffsetTimers have one entry per setting row only.
enum {
    OPTION_SELECT_ROW_SOUND,
    OPTION_SELECT_ROW_LOCATE_FRIEND,
    OPTION_SELECT_ROW_OK,
};

// Values of OptionSelectMenu.mState and mNextState, in the order of AdvanceOptionSelectMenu's cases: the entries slide
// in, the screen waits for input, the entries slide out; OK_PRESSED_DELAY runs after the OK entry is chosen;
// WAIT_BACKUP waits for the message to finish and the backup write to end.
enum {
    OPTION_SELECT_STATE_SLIDE_IN,
    OPTION_SELECT_STATE_SLIDE_IN_OK_GROUP,
    OPTION_SELECT_STATE_WAIT_INPUT,
    OPTION_SELECT_STATE_OK_PRESSED_DELAY,
    OPTION_SELECT_STATE_SLIDE_OUT,
    OPTION_SELECT_STATE_WAIT_BACKUP,
};

// Frames of the slide in and the slide out; the groups of cells travel OPTION_SELECT_SLIDE_DISTANCE sideways, the
// background layers OPTION_SELECT_BG_SLIDE_DISTANCE and the OK group OPTION_SELECT_BG2_SLIDE_DISTANCE up and down.
#define OPTION_SELECT_SLIDE_FRAMES 10
#define OPTION_SELECT_SLIDE_DISTANCE 250
#define OPTION_SELECT_BG_SLIDE_DISTANCE 140
#define OPTION_SELECT_BG2_SLIDE_DISTANCE 40

// Frames AdvanceOptionSelectMenuOkPressedDelay runs before the slide out; mHighlightVisible is set again from the
// fifth.
#define OPTION_SELECT_PRESS_FRAMES 10
#define OPTION_SELECT_HIGHLIGHT_FRAME 5

// The option select menu with two setting rows and an OK entry: their values, saved values, offsets and layout tables.
typedef struct OptionSelectMenu {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ s32 mIndex;
    /* 0c */ s32 mRowValues[2];
    /* 14 */ s32 mSavedRowValues[2];
    /* 1c */ BOOL mOkChosen;
    /* counted only while the groups slide in, while the OK group slides in, in OK_PRESSED_DELAY and while sliding out;
       zeroed when the first three hand over and when the slide out hands over to WAIT_BACKUP (OK path); on the Back
       path the slide out keeps counting while it requests the next option state */
    /* 20 */ s32 mStateFrames;
    /* 24 */ s16 mBg0Bg1Offset;
    /* 26 */ OptionSelectMenuGroupOffset mGroupOffsets[3];
    /* 32 */ u8 mUnk_32[2];
    /* 34 */ s32 mNextOptionState; /* only ever 0 (the top menu state), passed to RequestOptionState */
    /* 38 */ BOOL mHighlightVisible;
    /* 3c */ BOOL mBg1Visible;
    /* 40 */ s32 mOffsetTimers[2][2];
    /* 50 */ void *mHeap;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable; indexed with an offset
    // added
    /* 54 */ LayoutTableEntry *mOptionSelectMenuMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable; indexed with an offset
    // added
    /* 58 */ LayoutTableEntry *mOptionSelectMenuSTable;
    /* 5c */ struct NNSG2dCellDataBank *mOptionSelectMenuMNcer;
    /* 60 */ struct NNSG2dCellDataBank *mOptionSelectMenuSNcer;
    /* 64 */ Ncgr *mOptionSelectMenuMNcgr;
    /* 68 */ Ncgr *mOptionSelectMenuSNcgr;
    /* 6c */ Nclr *mOptionSelectMenuMONclr;
    /* 70 */ Nclr *mOptionSelectMenuSONclr;
    /* 74 */ LayoutEntryTable *mOptionSelectMenuMBncl;
    /* 78 */ LayoutEntryTable *mOptionSelectMenuSBncl;
    /* 7c */ void *mOptionSelectMenuSBnbl;
    /* 80 */ struct LayoutEntryTable *mOptionSelectMenuMBnll;
    /* 84 */ struct LayoutEntryTable *mOptionSelectMenuSBnll;
    /* 88 */ struct Bmg *mOptionMessages;
    /* 8c */ void *mCommonMessages;
} OptionSelectMenu;

void RegisterOptionSelectMenuCallbacks(void);
void WriteOptionSelectMenuRegisters(void);
void AdvanceOptionSelectMenu(void);
void AdvanceOptionSelectMenuOffsetTimers(void);
void SetOptionSelectMenuRowsOnOff(void);
void SetOptionSelectMenuValuesOnOff(void);
void WriteOptionSelectMenuTableOffsets(void);
void AdvanceOptionSelectMenuWaitBackup(void);
void AdvanceOptionSelectMenuSlideOut(void);
void AdvanceOptionSelectMenuOkPressedDelay(void);
void AdvanceOptionSelectMenuWaitInput(void);
void AdvanceOptionSelectMenuSlideInBg2(void);
void AdvanceOptionSelectMenuSlideIn(void);
void SetOptionSoundRowFromSave(void);
void SetSoundModeFromOptionRow(void);
void ApplyOptionSelectMenuSound(void);
void LocateAndQueueOptionSelectMenu(void);
/* slot mRelease of OptionStateCallbacks; sets the sound row back from the save and applies it, hides BG1 (bit 1 of the
   display plane field), clears the palette blend pointer and the global. On a state change AdvanceOptionStates destroys
   the state heap after it returns */
void ReleaseOptionSelectMenu(void);
void InitOptionSelectMenu(void *heap);
void InitOptionSelectMenuTexts(void);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u8 gOptionSelectMenuMLabelIndices[2];
extern const u8 gOptionSelectMenuXluCellIndices[2];
extern const u8 gOptionSelectMenuValueCounts[3];
extern const u8 gOptionSelectMenuOffsetMIndices[1];
extern const u8 gOptionSelectMenuRowSTableIndices[3];
extern const u8 gOptionSelectMenuSLabelIndices[3];
extern const u8 gOptionSelectMenuValueSTableIndices[3][3];
extern const s32 gOptionSelectMenuGroupSTableCounts[3];
extern const u8 gOptionSelectMenuTimerSTableIndices[2][3][2];
extern const u8 gOptionSelectMenuGroupSTableIndices[3][12];
