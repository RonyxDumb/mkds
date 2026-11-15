#pragma once

#include "types.h"
#include "Main/Race/race_setup.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/kart_icon.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/cup_mark.h"
#include "player.h"
#include "Main/Graphics/layout_rect_table.h"
#include "code_0212df7c.h"

// Values of SelectGhost.mResult: how the screen is being left (the ghost records are read for CHOSEN).
enum {
    SELECT_GHOST_RESULT_NONE,
    SELECT_GHOST_RESULT_CHOSEN,
    SELECT_GHOST_RESULT_RETURN,
};

// Values of SelectGhost.mState and mNextState.
enum {
    SELECT_GHOST_STATE_SLIDE_IN,
    SELECT_GHOST_STATE_RETURN_SLIDE_IN,
    SELECT_GHOST_STATE_INPUT,
    SELECT_GHOST_STATE_PRESS,
    SELECT_GHOST_STATE_CHOISES_OPEN,
    SELECT_GHOST_STATE_CHOISES_INPUT,
    SELECT_GHOST_STATE_CHOISES_CLOSE,
    SELECT_GHOST_STATE_SLIDE_OUT,
};

// Object behind gSelectGhost.
typedef struct SelectGhost {
    /* 00 */ struct NNSG2dCellDataBank *mSelectCupCourseMNcer;
    /* 04 */ LayoutEntryTable *mSelectCupCourseTaMBncl;
    /* 08 */ struct LayoutEntryTable *mSelectCupCourseTaMBnll;
    /* 0c */ struct NNSG2dCellDataBank *mSelectGhostSONcer;
    /* 10 */ LayoutEntryTable *mSelectGhostSBncl;
    /* 14 */ void *mSelectGhostSBnbl;
    /* 18 */ struct LayoutEntryTable *mSelectGhostSBnll;
    /* 1c */ Nclr *mSelectGhostSONclr;
    /* 20 */ void *mPlayerCharacterMNcgr;
    /* 24 */ struct NNSG2dCellDataBank *mPlayerCharacterMNcer;
    /* 28 */ Nclr *mPlayerCharacterMONclr;
    /* 2c */ struct LayoutEntryTable *mPlayerCharacterMBncl;
    /* 30 */ LayoutTableEntry *mSelectCupCourseTaMTable;
    /* 34 */ LayoutTableEntry *mSelectGhostSTable;
    /* 38 */ struct Bmg *mCommonMessages;
    /* 3c */ struct Bmg *mMenuMessages;
    /* 40 */ void *mSecondScreenMapBuffer;
    /* 44 */ void *mHeap;
    /* 48 */ s32 mState;
    /* 4c */ s32 mNextState;
    /* 50 */ s32 mStateFrames;
    // Set to 6 by the index steps, counts down to 0; 6 - timer indexes gFrameOffsets through LookupFrameOffset.
    /* 54 */ s16 mOffsetTimers[2];
    // Negated and shifted into the upper half-word of the BG0 offset register.
    /* 58 */ s32 mBg0Offset;
    // Y half of reg_G2S_DB_BG3OFS (0x0400101c): the SUB engine's BG3, stored negated; mBg0Offset is the main engine's
    /* 5c */ s32 mBg3Offset;
    /* 60 */ s32 mIndex;
    /* 64 */ void *mMainOamList;
    /* 68 */ void *mSubOamList;
    /* 6c */ s32 mResult;
} SelectGhost;

#include "01/code_0219c000.h"
#include "Main/Menu/select_return.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "01/unk_021a9000.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/unk_021a8000.h"
#include "01/unk_021a6000.h"
#include "Main/Graphics/oam.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"

void WriteSelectGhostRegisters(void);
int AdvanceSelectGhost(void);
void AdvanceSelectGhostSlideOut(void);
void AdvanceSelectGhostChoisesClose(void);
void AdvanceSelectGhostChoisesInput(void);
void AdvanceSelectGhostChoisesOpen(void);
void AdvanceSelectGhostPress(void);
void AdvanceSelectGhostInput(void);
void AdvanceSelectGhostReturnSlideIn(void);
void AdvanceSelectGhostSlideIn(void);
void ReleaseSelectGhost(void);
void InitSelectGhost(void *parentHeap, void *mainOam, void *subOam);
void SetupSelectGhostCupCells(void);
void ReadSelectGhostRecords(void);
void DecrementSelectGhostIndex(void);
void IncrementSelectGhostIndex(void);
void RefreshSelectGhostForIndex(void);
void AdvanceSelectGhostOffsetTimers(void);
void UpdateSelectGhostCellVisibility(void);
void RequestSelectGhostSlideOut(void);
void RequestSelectGhostChoisesClose(void);
void RequestSelectGhostChoisesInput(void);
void RequestSelectGhostChoisesOpen(void);
void RequestSelectGhostPress(void);
void RequestSelectGhostInput(void);
void RequestSelectGhostReturnSlideIn(void);
void ResetSelectGhost(void);
void LocateAndQueueSelectGhost(void);
void LoadSelectGhostAndKartIconData(void);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u16 gSelectGhostSTableIndices[6];
extern char *gSelectGhostSONcerName;
extern char *gSelectGhostSBnllName;
extern const u16 gSelectGhostTimerZeroSTableIndices[2];
extern const u16 gSelectGhostCharacterCells[13];
extern const u16 gSelectGhostRunningSTableIndices[2];
extern const u32 gSelectGhostCupIndices[8];
extern char *gSelectGhostSBNclrName;
extern char *gSelectGhostSONcgrName;
extern char *gSelectGhostSONclrName;
extern const u16 gSelectGhostSBnllIndices[5];
extern char *gSelectGhostSBnblName;
extern const u16 gSelectGhostSLabelHeights[5];
extern char *gSelectGhostSBNcgrName;
extern const u32 gSelectGhostRecordKinds[4];
extern const u16 gSelectGhostSLabelWidths[5];
extern const u16 gSelectGhostMenuMessageIndices[4];
extern char *gSelectCupCourseTaMBnclName;
extern char *gSelectCupCourseTaMBnllName;
extern char *gSelectCupCourseMNcerName;
extern char *gSelectGhostSBnclName;
extern char *gSelectGhostSNscrName;
