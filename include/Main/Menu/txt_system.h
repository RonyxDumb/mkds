#pragma once

#include "types.h"
#include "Main/Menu/back_screen_keyboard_tables.h"
#include "Main/Menu/menu_screens_work.h"

void SetTxtSystemOpenSoundId(unsigned int soundId);

void SetTxtSystemSoundId(int soundIndex, u32 soundId);

void SetTxtSystemBgOffsetRequested(int mainOffset, int subOffset);

void SetTxtSystemMode(unsigned int mode);
unsigned int GetTxtSystemInputAccepted(void);

s32 GetTxtSystemDone(void);
s32 GetTxtSystemSelectedIndex(void);

void SetupTxtSystemSubTextButtonEx(void *text, void *buttonText, u32 mainBlendPlanes, u32 subBlendPlanes,
                                   u32 openFromIndex, u32 closeToIndex);
void SetupTxtSystemSubTextTwoButtons(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex);
void SetupTxtSystemSubTextTwoButtonsEx(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                       u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex);
void RequestTxtSystemClose(void);
BOOL IsTxtSystemOpenNoCloseRequest(void);
BOOL IsTxtSystemClosedNoOpenRequest(void);
BOOL IsTxtSystemOpenAfterOpening(void);

void SetupTxtSystemSubTextButton(void *text, void *buttonText);

void SetupTxtSystemSubTextEx(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                             u32 subAnim);

void SetupTxtSystemSubText(void *text);

void SetupTxtSystemMainTextButtonEx(void *text, void *buttonText, u32 mainBlendPlanes, u32 subBlendPlanes,
                                    u32 openFromIndex, u32 closeToIndex, u32 mainAnim);
void SetupTxtSystemMainTextTwoButtons(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex);
void SetupTxtSystemMainTextTwoButtonsEx(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                        u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                                        u32 mainAnim);

void SetupTxtSystemMainTextButton(void *text, void *buttonText);

void SetupTxtSystemMainTextEx(void *text, s32 mainBlendPlanes, s32 subBlendPlanes, s32 openFromIndex, s32 closeToIndex,
                              s32 mainAnim, s32 subAnim);
void SetupTxtSystemMainTextShort(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex,
                                 u32 closeToIndex, u32 mainAnim, u32 subAnim);

void SetupTxtSystemMainText(void *text);

void AdvanceTxtSystemClosed(void);
void AdvanceTxtSystemOpening(void);
void AdvanceTxtSystemOpen(void);
void AdvanceTxtSystemButtonPressed(void);
void AdvanceTxtSystemClosing(void);
void AdvanceTxtSystem(void);
void WriteTxtSystemRegisters(void);
void RequestTxtSystemOpen(void);

void ResetTxtSystemButtonColors(void);
void QueueTxtSystemButtonColors(void);

void RefreshTxtSystemScreenBuffers(u32 *drawFlags);
void RefreshTxtSystemAnim(void);
s32 LoadTxtSystem(s32 subCharOffset);
void InitTxtSystemDisplay(void);

void ClearTxtSystemPointer(void);

typedef struct TxtSystemArgs {
    /* 00 */ void *mFont;
    /* 04 */ u32 mUseCanvas1;
    /* 08 */ u32 mUseCanvas2;
    /* 0c */ u32 mUseCanvas3;
    /* 10 */ s32 mSubCharOffset;
} TxtSystemArgs;

void ClearTxtSystemCanvasInUse(void);
s32 InitTxtSystem(void *heap, TxtSystemArgs *args);

extern const u8 gTxtSystemCanvasSizes[8][2];
extern const s16 gTxtSystemBgOffsets[2];
extern const u16 gTxtSystemCanvasCharOffsets[8];
extern const ByteRect gTxtSystemHitRects[7];
extern const ByteRect gTxtSystemNscrRects[7];
extern struct TxtSystem *gTxtSystem;
