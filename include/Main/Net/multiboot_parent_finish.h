#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine

typedef struct Bmg Bmg;
typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// The palette, chars and screen map of one background: mPalette, mChars and mScreenMap, loaded by
// LoadBg1FromSceneFiles.
typedef struct Bg1Files {
    /* 00 */ Nclr *mPalette;
    /* 04 */ Ncgr *mChars;
    /* 08 */ Nscr *mScreenMap;
} Bg1Files;

// LOGO_READ_BACKUP_FRAMES: calls of UpdateLogoReadBackup after which (more than this many) the scene goes to the wait
// for the backup read. LOGO_SUB_TEXT_FRAMES: calls of the reset states after which (more than this many), once the
// backup command is idle and the sub text is open, they go on.
#define LOGO_READ_BACKUP_FRAMES 120
#define LOGO_SUB_TEXT_FRAMES 90

// The logo scene: its main and sub backgrounds, state machine, the reset backup flag, the read backup and sub text
// frame counters and common messages.
typedef struct LogoScene {
    /* 00 */ Bg1Files mMainBg;
    /* 0c */ Bg1Files mSubBg;
    /* 18 */ StateMachine mStateMachine;
    /* 2c */ union {
        s32 mUnk_2c;
        struct {
// Set to 1 when A, B, X, Y, L and R are held together in ReadBackup, and stays set.
            s32 mResetBackupRequested : 1;
            u32 mUnk_2c_1 : 1;
        };
    };
    /* 30 */ s32 mReadBackupFrames;
    /* 34 */ s32 mSubTextFrames;
    /* 38 */ Bmg *mCommonMessages;
} LogoScene;

extern LogoScene *gLogoScene;
extern s32 gDwcInitResult;

void DisconnectRemovedChildren(void);
void FinishMultiBootParentSetup(void);
