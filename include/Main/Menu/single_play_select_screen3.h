#pragma once

#include "types.h"
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry

typedef struct Ncgr Ncgr;
typedef struct Nclr Nclr;
typedef struct CharacterKartPicks CharacterKartPicks;
typedef struct NNSG2dCellDataBank NNSG2dCellDataBank;

// Elements of the table at member 0x14 of MenuScene.
typedef struct ScreenCallbacks {
    /* 0 */ void (*mWriteRegisters)(void);
    /* 4 */ void (*mUpdate)(u32 a);
} ScreenCallbacks;

// Object behind gMenuScene.
typedef struct MenuScene {
    /* 000 */ s32 mFramesSinceScreenSwitch;
    /* 004 */ s32 mScreenSwitched;
    /* 008 */ s32 mPreviousScreenNumber;
    /* 00c */ s32 mScreenNumber;
    /* 010 */ s32 mNextScreenNumber;
    /* 014 */ ScreenCallbacks mScreenCallbacks[0x1e];
    /* 104 */ BOOL mScreenInitPending;
    /* 108 */ u8 mMainOam[0x404];
    /* 50c */ u8 mSubOam[0x404];
    /* 910 */ Nclr *mSinglePlaySelectModeMONclr;
    /* 914 */ Ncgr *mSinglePlaySelectModeMNcgr;
    /* 918 */ NNSG2dCellDataBank *mSinglePlaySelectModeMNcer;
    /* 91c */ u8 mUnk_91c[4];
    /* 920 */ Nclr *mSinglePlaySelectModeSONclr;
    /* 924 */ Ncgr *mSinglePlaySelectModeSNcgr;
    /* 928 */ NNSG2dCellDataBank *mSinglePlaySelectModeSNcer;
    /* 92c */ u8 mUnk_92c[4];
    /* 930 */ s32 mSinglePlaySelectModeIndex;
    /* 934 */ BOOL mSinglePlaySelectStartedOnSelected;
    /* 938 */ s16 mSinglePlaySelectModePressOffset;
    /* 93a */ u8 mUnk_93a[2];
    /* 93c */ LayoutTableEntry *mSinglePlaySelectModeMLayoutTable;
    /* 940 */ struct LayoutEntryTable *mSinglePlaySelectModeMBncl;
    /* 944 */ s32 mUnk_944;
    /* 948 */ LayoutTableEntry *mSinglePlaySelectModeSLayoutTable;
    /* 94c */ struct LayoutEntryTable *mSinglePlaySelectModeSBncl;
    /* 950 */ void *mSinglePlaySelectModeSBnbl;
    /* 954 */ CharacterKartPicks *mCharacterKartPicks;
    /* 958 */ BOOL mDataSharingSyncStarted;
    /* 95c */ BOOL mDataSharingSyncFinished;
} MenuScene;

void UpdateSinglePlaySelectMenuScreen3(void);

void WriteSinglePlaySelect3Registers(void);

void UpdateSinglePlaySelectMenuScreen2(void);

void WriteSinglePlaySelect2Registers(void);

void UpdateSinglePlaySelectInput(s32 inputEnabled);
