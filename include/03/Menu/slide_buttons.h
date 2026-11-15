#pragma once

#include "types.h"
#include "03/Graphics/nce_oam.h"
#include "03/System/tasks.h"
#include "03/code_021be610.h"

// Frames the slide buttons wait before they take touch input, and frames the button reset waits.
#define SLIDE_BUTTONS_WAIT_FRAMES 4
#define SLIDE_BUTTONS_RESET_WAIT_FRAMES 0x10

typedef struct SlideButtons {
    /* 00 */ OamRange *mButtons[2];
    /* 08 */ OamRange *mSlideRange;
    /* 0c */ TaskEntry *mStepTask;
    /* 10 */ TaskEntry *mResetTask;
    /* 14 */ u16 mStepFrames;
    /* 16 */ s8 mButtonResult;
    /* 17 */ u8 mKind;
    /* 18 */ u8 mTouchDisabled;
    /* 19 */ u8 mSlidingOut;
} SlideButtons;

extern const u16 gSlideButtonOrigins[4];

void AdvanceSlideButtonsOut(TaskEntry *task, void *arg);
void AdvanceButtonTouch(TaskEntry *task, void *arg);
void AdvanceSlideButtonsWait(TaskEntry *task, void *arg);
void AdvanceSlideButtonsIn(TaskEntry *task, void *arg);
void SetSlideButtonsY(s32 yPosition);
void DisableButtonTouch(void);
void EnableButtonTouch(void);
BOOL IsSlideButtonsNotSlidingOut(void);
void SetButtonResult(s8 result);
void SetButtonResultIfNone(s32 result);
int GetButtonResult(void);
void StartSlideButtonsOut(void);
void CreateSlideButtons(u32 kind);

extern const u8 gAnimatedIconPalettes[3];
extern const u16 gAnimatedIconPosition[2];
extern const u16 gSlideButtonsPosition[2];
extern const u16 gSlideButtonSize[2];
extern const u8 gSlideButtonImages[14];
extern const u8 gSlideButtonPositionIndices[14];
extern const u8 gSlideButtonCounts[7];
extern struct AnimatedIcon *gAnimatedIcon;
extern SlideButtons *gSlideButtons;
