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

BOOL IsSelectChoisesState0NoState1Request(void);
BOOL IsSelectChoisesState1NoState0Request(void);
void RequestSelectChoisesState0(void);
void StartSelectChoises(void *firstText, void *secondText, s32 startOnSecond);
void RequestSelectChoisesState1(void);
void WriteSelectChoisesRegisters(void);
void AdvanceSelectChoises(void);

void AdvanceSelectChoisesState2(void);

s32 LoadSelectChoises(s32 subCharOffset);
void RefreshSelectChoisesNscrCopy(void);
void RefreshSelectChoisesPaletteBits(void);
void RefreshAndQueueSelectChoises(void);
void RefreshSelectChoisesPaletteNoIndex(void);
void AdvanceSelectChoisesState0(void);
void AdvanceSelectChoisesState1(void);

u32 InitSelectChoisesDisplay(void);
void ClearSelectChoisesPointer(void);

s32 InitSelectChoises(void *heap, void *font, s32 subCharOffset);

void ClearSelectReturnDisplayBitOn(void);

BOOL IsSelectReturnState2NoState3Or4RequestAndInRect(s32 pointX, s32 pointY);

int LookupSelectReturnState4Bg2Offset(int frame);
int LookupSelectReturnState1Bg2Offset(int frame);

BOOL IsSelectReturnState0NoState1Request(void);
BOOL IsSelectReturnState2NoState3Or4Request(void);
void RequestSelectReturnState4(void);
void RequestSelectReturnState3WithSound(s32 requestState4);
void RequestSelectReturnState1(void);
void WriteSelectReturnRegisters(void);
void AdvanceSelectReturn(void);
void AdvanceSelectReturnState4(void);
void AdvanceSelectReturnState3(void);

void AdvanceSelectReturnState2(void);

void AdvanceSelectReturnState1(void);
void AdvanceSelectReturnState0(void);
void SetSelectReturnPaletteBits(s32 paletteKind);
s32 LoadSelectReturn(s32 subCharOffset);
void InitSelectReturnDisplay(void);

void ClearSelectReturnPointer(void);

s32 InitSelectReturn(void *heap, s32 subCharOffset);

extern const u8 gSelectChoisesNscrOrigins[2][2];
extern const ByteRect gSelectChoisesTileRect;
extern const ByteRect gSelectChoisesPaletteRects[2];
extern const s8 gSelectReturnState3Bg2Offsets[12];
extern const s8 gSelectReturnState1Bg2Offsets[12];
extern const s8 gSelectReturnState4Bg2Offsets[12];
extern const ByteRect gSelectChoisesHitRects[2];
extern struct SelectReturn *gSelectReturn;
extern struct SelectChoises *gSelectChoises;
