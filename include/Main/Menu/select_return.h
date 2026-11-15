#pragma once

#include "types.h"
#include "Main/Menu/data_0215d000.h"
#include "Main/Menu/data_0217d000.h"

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
void WriteSelectChoisesRegisters(void);
void AdvanceSelectChoises(void);

void AdvanceSelectChoisesChosen(void);

s32 LoadSelectChoises(s32 subCharOffset);
void RefreshSelectChoisesNscrCopy(void);
void RefreshSelectChoisesPaletteBits(void);
void RefreshAndQueueSelectChoises(void);
void RefreshSelectChoisesPaletteNoIndex(void);
void AdvanceSelectChoisesHidden(void);
void AdvanceSelectChoisesChoose(void);

u32 InitSelectChoisesDisplay(void);
void ClearSelectChoisesPointer(void);

s32 InitSelectChoises(void *heap, void *font, s32 subCharOffset);

void ClearSelectReturnDisplayBitOn(void);

BOOL IsSelectReturnShownNoRequestAndInRect(s32 pointX, s32 pointY);

int LookupSelectReturnSlideOutBg2Offset(int frame);
int LookupSelectReturnSlideInBg2Offset(int frame);

BOOL IsSelectReturnHiddenNoRequest(void);
BOOL IsSelectReturnShownNoRequest(void);
void RequestSelectReturnSlideOut(void);
void RequestSelectReturnPressWithSound(s32 requestState4);
void RequestSelectReturnSlideIn(void);
void WriteSelectReturnRegisters(void);
void AdvanceSelectReturn(void);
void AdvanceSelectReturnSlideOut(void);
void AdvanceSelectReturnPress(void);

void AdvanceSelectReturnShown(void);

void AdvanceSelectReturnSlideIn(void);
void AdvanceSelectReturnHidden(void);
void SetSelectReturnPaletteBits(s32 paletteKind);
s32 LoadSelectReturn(s32 subCharOffset);
void InitSelectReturnDisplay(void);

void ClearSelectReturnPointer(void);

s32 InitSelectReturn(void *heap, s32 subCharOffset);

extern const u8 gSelectChoisesNscrOrigins[2][2];
extern const ByteRect gSelectChoisesTileRect;
extern const ByteRect gSelectChoisesPaletteRects[2];
extern const s8 gSelectReturnPressBg2Offsets[12];
extern const s8 gSelectReturnSlideInBg2Offsets[12];
extern const s8 gSelectReturnSlideOutBg2Offsets[12];
extern const ByteRect gSelectChoisesHitRects[2];
extern struct SelectReturn *gSelectReturn;
extern struct SelectChoises *gSelectChoises;
