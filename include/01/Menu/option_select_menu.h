#pragma once

#include "types.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/MapObjects/data_0217a000.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/scene_text_init.h"

// An s16 pair of OptionSelectMenu.
typedef struct OptionSelectMenuGroupOffset {
    /* 00 */ s16 mOffsetX;
    /* 02 */ s16 mOffsetY;
} OptionSelectMenuGroupOffset;

// Object behind gOptionSelectMenu.
typedef struct OptionSelectMenu {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ s32 mIndex; /* 0 and 1 are the two setting rows, 2 is the OK entry */
    /* 0c */ s32 mRowValues[2];
    /* 14 */ s32 mSavedRowValues[2];
    /* 1c */ BOOL mOkChosen;
    /* counted only in states 0, 1, 3, 4; zeroed when 0, 1, 3 hand over and when 4 hands over to 5 (OK path); on
       the Back path state 4 keeps counting while it requests the next option state */
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
    /* 5c */ struct Unk02021dc8 *mOptionSelectMenuMNcer;
    /* 60 */ struct Unk02021dc8 *mOptionSelectMenuSNcer;
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
void AdvanceOptionSelectMenuState5(void);
void AdvanceOptionSelectMenuState4(void);
void AdvanceOptionSelectMenuState3(void);
void AdvanceOptionSelectMenuState2(void);
void AdvanceOptionSelectMenuState1(void);
void AdvanceOptionSelectMenuState0(void);
void SetOptionSoundRowFromSave(void);
void SetSoundModeFromOptionRow(void);
void ApplyOptionSelectMenuSound(void);
void LocateAndQueueOptionSelectMenu(void);
/* slot mRelease of OptionStateCallbacks; clears the global and undoes the display setup (DISPCNT bit 1 cleared),
   the state heap is destroyed by AdvanceOptionStates after it returns */
void ReleaseOptionSelectMenu(void);
void InitOptionSelectMenu(void *heap);
void InitOptionSelectMenuTexts(void);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u8 gOptionSelectMenuMLabelIndices[2];
extern const u8 gOptionSelectMenuXluCellIndices[2];
extern const u8 gOptionSelectMenuValueCounts[3];
// Object behind gBackupBuffers; the byte at 0x31 of the object at its first member holds flags.
extern const u8 gOptionSelectMenuOffsetMIndices[1];
extern const u8 gOptionSelectMenuRowSTableIndices[3];
extern const u8 gOptionSelectMenuSLabelIndices[3];
extern const u8 gOptionSelectMenuValueSTableIndices[3][3];
extern const s32 gOptionSelectMenuGroupSTableCounts[3];
extern const u8 gOptionSelectMenuTimerSTableIndices[2][3][2];
extern const u8 gOptionSelectMenuGroupSTableIndices[3][12];
