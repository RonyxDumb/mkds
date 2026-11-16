#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine

typedef struct Bmg Bmg;
typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// Three pointers filled in by Gfx_ReadPalette, Gfx_ReadCharGraphics and MaybeReadScreenBlock_0.
typedef struct Bg1Files {
    /* 00 */ Nclr *mPalette;
    /* 04 */ Ncgr *mChars;
    /* 08 */ Nscr *mScreenMap;
} Bg1Files;

// Frames the logo scene waits for the backup read and shows its sub text before it goes on.
#define LOGO_READ_BACKUP_FRAMES 120
#define LOGO_SUB_TEXT_FRAMES 90

// The logo scene: its NtrMain and sub backgrounds, state machine, backup read counters and common messages.
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

extern LogoScene *g_LogoContext;
extern s32 g_DwcStatus;

void DisconnectRemovedChildren(void);
void FinishMultiBootParentSetup(void);
