#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h"

typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// OAM entries (mOams) and how many are used (mOamCount); AdvanceLld appends the cells it draws.
typedef struct OamBuffer {
    /* 000 */ u8 mOams[0x400];
    /* 400 */ u16 mOamCount;
    /* 402 */ u16 mUnk_402;
} OamBuffer;

// A list of cell entries with the cells and cell animations they draw and the offset they are drawn at.
typedef struct Lld {
    /* 00 */ u16 mEntryCount;
    /* 02 */ u8 mUnk_02[0x2];
    /* 04 */ struct LldEntry *mEntries;
    /* 08 */ void *mCells;
    /* 0c */ void *mCellAnims;
    /* 10 */ s32 mOffsetX;
    /* 14 */ s32 mOffsetY;
} Lld;

// Values of Emblem.mState.
enum {
    EMBLEM_STATE_GRID,
    EMBLEM_STATE_TEMPLATE,
    EMBLEM_STATE_TEMPLATE_SLIDE_IN,
    EMBLEM_STATE_TEMPLATE_SLIDE_OUT,
    EMBLEM_STATE_CAMERA,
    EMBLEM_STATE_FADE_OUT_TO_CAMERA,
    EMBLEM_STATE_FADE_IN_AT_CAMERA,
    EMBLEM_STATE_FADE_OUT_TO_GRID,
    EMBLEM_STATE_FADE_IN_AT_GRID,
    EMBLEM_STATE_CHOISES = 10,
    EMBLEM_STATE_WAIT_BACKUP,
    EMBLEM_STATE_DONE,
};

// Values of Emblem.mCursorTargetState: which part of the sub screen the cursor is on (GRID, BUTTONS, COLORS), or HELD
// while a press is still held.
enum {
    EMBLEM_CURSOR_TARGET_GRID,
    EMBLEM_CURSOR_TARGET_BUTTONS,
    EMBLEM_CURSOR_TARGET_COLORS,
    EMBLEM_CURSOR_TARGET_HELD,
};

// Values of Emblem.mDisplayState: which graphics work AdvanceEmblemDisplay does while the state is set; IDLE and CAMERA
// do none.
enum {
    EMBLEM_DISPLAY_UPLOAD_SCREENS,
    EMBLEM_DISPLAY_IDLE,
    EMBLEM_DISPLAY_TEMPLATE_SLIDE_IN_SETUP,
    EMBLEM_DISPLAY_TEMPLATE_SETUP,
    EMBLEM_DISPLAY_TEMPLATE_SLIDING,
    EMBLEM_DISPLAY_TEMPLATE_SHOWN,
    EMBLEM_DISPLAY_TEMPLATE_SLIDE_OUT_SETUP,
    EMBLEM_DISPLAY_GRID_RESTORE,
    EMBLEM_DISPLAY_GRID,
    EMBLEM_DISPLAY_CAMERA_UPLOAD,
    EMBLEM_DISPLAY_CAMERA_FADE,
    EMBLEM_DISPLAY_CAMERA,
    EMBLEM_DISPLAY_GRID_UPLOAD,
    EMBLEM_DISPLAY_GRID_FADE,
    EMBLEM_DISPLAY_CHOISES_SETUP,
    EMBLEM_DISPLAY_CHOISES_CLOSE,
};

// Distance the template screen slides, in pixels (Emblem.mTemplateSlideOffset runs 0 to this).
#define EMBLEM_TEMPLATE_SLIDE_DISTANCE 0xc0
// Speed (mTemplateSlideSpeed) the template slide in starts with and the slide out starts with negated; it changes by
// two every call.
#define EMBLEM_TEMPLATE_SLIDE_SPEED 32
// Highest value of mFadeLevel (the fade runs in steps of two).
#define EMBLEM_FADE_LEVEL_MAX 16
// Calls of the screen upload state (mUploadFrames) before the grid is shown.
#define EMBLEM_UPLOAD_FRAMES 2

typedef void (*EmblemTransitionFunc)(void);

// The emblem editor: its screen graphics, record and grid bytes, cursors, state and fade values.
typedef struct Emblem {
    /* 0000 */ OamBuffer mMainOam;
    /* 0404 */ OamBuffer mSubOam;
    /* 0808 */ Nclr *mEmblemMONclr;
    /* 080c */ Nclr *mEmblemMBNclr;
    /* 0810 */ Ncgr *mEmblemMONcgr;
    /* 0814 */ Ncgr *mEmblemMBNcgr;
    /* 0818 */ Nscr *mEmblemMNscr;
    /* 081c */ Nscr *mEmblemMBgNscr;
    /* 0820 */ struct NNSG2dCellDataBank *mEmblemMNcer;
    /* 0824 */ struct AnimBank *mEmblemMNanr;
    /* 0828 */ struct Lld *mEmblemMLld;
    /* 082c */ Nclr *mEmblemSONclr;
    /* 0830 */ Nclr *mEmblemSBNclr;
    /* 0834 */ Ncgr *mEmblemSONcgr;
    /* 0838 */ Ncgr *mEmblemSBNcgr;
    /* 083c */ Ncgr *mEmblemTemplateBNcgr;
    /* 0840 */ Nscr *mEmblemSToolNscr;
    /* 0844 */ Nscr *mEmblemSBgNscr;
    /* 0848 */ Nscr *mEmblemSTemplateFrameNscr;
    /* 084c */ Nscr *mEmblemSTemplateDarkNscr;
    /* 0850 */ struct NNSG2dCellDataBank *mEmblemSNcer;
    /* 0854 */ struct AnimBank *mEmblemSNanr;
    /* 0858 */ struct Lld *mEmblemSLld;
    /* 085c */ Lld *mEmblemTemplateSLld;
    /* 0860 */ Ncgr *mEmblemCameraSONcgr;
    /* 0864 */ Ncgr *mEmblemCameraSBNcgr;
    /* 0868 */ Nscr *mEmblemCameraSDSNscr;
    /* 086c */ Nscr *mEmblemCameraSBgNscr;
    /* 0870 */ struct NNSG2dCellDataBank *mEmblemCameraSNcer;
    /* 0874 */ struct AnimBank *mEmblemCameraSNanr;
    /* 0878 */ struct Lld *mEmblemCameraSLld;
    /* 087c */ u8 mRecordBytes[EMBLEM_PIXEL_BYTES];
    /* 0a7c */ u8 mGridCharBytes[EMBLEM_PIXEL_BYTES];
    /* 0c7c */ u8 mCellNibbles[0x400];
    /* 107c */ s32 mButtonCursorIndex;
    /* 1080 */ s32 mColorCursorIndex;
    /* 1084 */ s32 mTemplateCursorIndex;
    /* 1088 */ s32 mCursorSizeIndex;
    /* 108c */ EmblemTransitionFunc mPendingTransitionFunc;
    /* 1090 */ s32 mState;
    /* 1094 */ s32 mCursorTargetState;
    /* 1098 */ s32 mDisplayState;
    /* 109c */ s32 mFadeLevel;
    /* 10a0 */ s32 mTemplateSlideOffset;
    /* 10a4 */ s32 mTemplateSlideSpeed;
    /* 10a8 */ s32 mBgScrollPosition;
    /* 10ac */ BOOL mKartListSkipped;
    /* 10b0 */ BOOL mTransitionRunning;
    /* 10b4 */ s32 mUploadFrames;
    /* 10b8 */ BOOL mSoundPending;
    /* 10bc */ s32 mUnk_10bc;
} Emblem;

extern Emblem *gEmblem;

void InitEmblem(void);
