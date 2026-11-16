#pragma once

#include "types.h"
#include "Main/Menu/back_screen_keyboard_tables.h"
#include "Main/Menu/menu_screens_work.h"

void TextSystem_SetFadeInSseqId_from_thumb(unsigned int soundId);

void SetTxtSystemSoundId(int soundIndex, u32 soundId);

void SetTxtSystemBgOffsetRequested(int mainOffset, int subOffset);

void SetTxtSystemMode(unsigned int mode);
unsigned int GetTxtSystemInputAccepted(void);

s32 TextSystem_WasAnyDialogButtonPressed_from_thumb(void);
s32 TextSystem_IsButton2Focused_from_thumb(void);

void TextSystem_DisplaySingleButtonDialog_from_thumb(void *text, void *buttonText, u32 mainBlendPlanes, u32 subBlendPlanes,
                                   u32 openFromIndex, u32 closeToIndex);
void TextSystem_DisplayDoubleButtonDialog_Simple_from_thumb(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex);
void TextSystem_DisplayDoubleButtonDialog_from_thumb(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                       u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex);
void TextSystem_CloseDialog_from_thumb(void);
BOOL TextSystem_IsDialogIdle_from_thumb(void);
BOOL TextSystem_IsDialogFinished_from_thumb(void);
BOOL TextSystem_JustFadedIn_from_thumb(void);

void TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(void *text, void *buttonText);

void TextSystem_DisplayProgressDialog_from_thumb(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                             u32 subAnim);

void TextSystem_DisplayProgressDialog_Simple_from_thumb(void *text);

void SetupTxtSystemMainTextButtonEx(void *text, void *buttonText, u32 mainBlendPlanes, u32 subBlendPlanes,
                                    u32 openFromIndex, u32 closeToIndex, u32 mainAnim);
void SetupTxtSystemMainTextTwoButtons(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex);
void SetupTxtSystemMainTextTwoButtonsEx(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                        u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                                        u32 mainAnim);

void SetupTxtSystemMainTextButton(void *text, void *buttonText);

void TextSystem_DisplayProgressDialog_TopScreen_from_thumb(void *text, s32 mainBlendPlanes, s32 subBlendPlanes, s32 openFromIndex, s32 closeToIndex,
                              s32 mainAnim, s32 subAnim);
void SetupTxtSystemMainTextShort(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex,
                                 u32 closeToIndex, u32 mainAnim, u32 subAnim);

void SetupTxtSystemMainText(void *text);

void TextSystemContext_UpdateFn_State0_from_thumb(void);
void TextSystemContext_UpdateFn_State1_from_thumb(void);
void TextSystemContext_UpdateFn_State2_from_thumb(void);
void TextSystemContext_UpdateFn_State3_from_thumb(void);
void TextSystemContext_UpdateFn_State4_from_thumb(void);
void TextSystemContext_OnSceneUpdate_from_thumb(void);
void TextSystemContext_OnSceneVblank_from_thumb(void);
void TextSystemContext_StartDialog_from_thumb(void);

void TextSystemContext_ReloadButtonGraphics2_from_thumb(void);
void TextSystemContext_ReloadButtonGraphics_from_thumb(void);

void TextSystemContext_LoadEnabledSpritesAndAnimations_from_thumb(u32 *drawFlags);
void TextSystemContext_UpdateAnimationGraphics_from_thumb(void);
s32 TextSystemContext_LoadGraphics_from_thumb(s32 subCharOffset);
void TextSystemContext_InitializeBg_from_thumb(void);

void TextSystemContext_Dispose_from_thumb(void);

// The arguments of TextSystemContext_Initialize_from_thumb: the font, the canvas switches and the sub character offset.
typedef struct TxtSystemArgs {
    /* 00 */ void *mFont;
    /* 04 */ u32 mUseCanvas1;
    /* 08 */ u32 mUseCanvas2;
    /* 0c */ u32 mUseCanvas3;
    /* 10 */ s32 mSubCharOffset;
} TxtSystemArgs;

void TextSystemContext_DisableAllSprites_from_thumb(void);
s32 TextSystemContext_Initialize_from_thumb(void *heap, TxtSystemArgs *args);

extern const u8 g_TextSystemContextTileDimensionTable[8][2];
extern const s16 g_TextSystemContext_FadeYValues[2];
extern const u16 gTxtSystemCanvasCharOffsets[8];
extern const ByteRect gTxtSystemHitRects[7];
extern const ByteRect gTxtSystemNscrRects[7];
extern struct TxtSystem *g_TextSystemContext;
