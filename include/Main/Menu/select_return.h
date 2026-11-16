#pragma once

#include "types.h"
#include "Main/Menu/back_screen_keyboard_tables.h"
#include "Main/Menu/menu_screens_work.h"

void SetSelectReturnDisplayBitOn(void);

void SetSelectChoisesSoundId(int choiceIndex, u32 soundId);
unsigned int GetSelectChoisesDone(void);
s32 GetSelectChoisesIndex(void);
void ClearSelectChoisesUseCharBuffers(void);
void SetSelectReturnSoundId(u32 soundId);

BOOL IsSelectChoisesHiddenNoRequest(void);
BOOL IsSelectChoisesChooseNoRequest(void);
void RequestSelectChoisesHidden(void);
void StartSelectChoises(void *firstText, void *secondText, s32 startOnSecond);
void RequestSelectChoisesChoose(void);
void SelectChoisesContext_OnSceneVblank_from_thumb(void);
void SelectChoisesContext_OnSceneUpdate_from_thumb(void);

void SelectChoisesContext_UpdateFn_State2_from_thumb(void);

s32 SelectChoisesContext_LoadGraphics_from_thumb(s32 subCharOffset);
void RefreshSelectChoisesNscrCopy(void);
void RefreshSelectChoisesPaletteBits(void);
void SelectChoisesContext_UpdateGraphics_from_thumb(void);
void RefreshSelectChoisesPaletteNoIndex(void);
void SelectChoisesContext_UpdateFn_State0_from_thumb(void);
void SelectChoisesContext_UpdateFn_State1_from_thumb(void);

u32 SelectChoisesContext_InitializeBg_from_thumb(void);
void SelectChoisesContext_Dispose_from_thumb(void);

s32 SelectChoisesContext_Initialize_from_thumb(void *heap, void *font, s32 subCharOffset);

void ClearSelectReturnDisplayBitOn(void);

BOOL IsSelectReturnShownNoRequestAndInRect(s32 pointX, s32 pointY);

int LookupSelectReturnSlideOutBg2Offset(int frame);
int LookupSelectReturnSlideInBg2Offset(int frame);

BOOL IsSelectReturnHiddenNoRequest(void);
BOOL IsSelectReturnShownNoRequest(void);
void RequestSelectReturnSlideOut(void);
void RequestSelectReturnPressWithSound(s32 requestSlideOut);
void RequestSelectReturnSlideIn(void);
void SelectReturnContext_OnSceneVblank_from_thumb(void);
void SelectReturnContext_OnSceneUpdate_from_thumb(void);
void AdvanceSelectReturnSlideOut(void);
void AdvanceSelectReturnPress(void);

void AdvanceSelectReturnShown(void);

void AdvanceSelectReturnSlideIn(void);
void AdvanceSelectReturnHidden(void);
void SetSelectReturnPaletteBits(s32 paletteKind);
s32 LoadSelectReturnGraphics_from_thumb(s32 subCharOffset);
void InitSelectReturnDisplay(void);

void SelectReturnContext_Dispose_from_thumb(void);

s32 InitializeSelectReturn_from_thumb(void *heap, s32 subCharOffset);

extern const u8 gSelectChoisesNscrOrigins[2][2];
extern const ByteRect gSelectChoisesTileRect;
extern const ByteRect gSelectChoisesPaletteRects[2];
extern const s8 gSelectReturnPressBg2Offsets[12];
extern const s8 gSelectReturnSlideInBg2Offsets[12];
extern const s8 gSelectReturnSlideOutBg2Offsets[12];
extern const ByteRect gSelectChoisesHitRects[2];
extern struct SelectReturn *g_SelectReturn;
extern struct SelectChoises *g_SelectChoisesContext;
