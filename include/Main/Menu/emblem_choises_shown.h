#pragma once

#include "types.h"
#include "01/unk_021a9000.h"
#include "Main/Menu/data_02180728.h"
#include "Main/Graphics/oam.h"

void SetEmblemChoisesShownAndReset(u32 shown);
s32 CreateRaceHudSubScreenShine16Cells(void);

unsigned int GetEmblemChoisesResult(void);

void RequestEmblemChoisesGraphicsUpload(void);

void ClearEmblemChoisesPointer(void);

void EmblemChoisesInitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing,
                                 s32 lineSpacing);
u32 EmblemChoisesDrawTextOnCanvas(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text);
void InitEmblemChoises(void);

void *EmblemChoisesGetCurrentHeap(void);
void WriteEmblemChoisesScreenMapWrapper(void);

void UpdateEmblemChoises(void);

u32 StartEmblemChoisesSound(u32 seqIndex);

u32 EmblemChoisesStartSeqArc(u32 seqIndex, u32 seqArcNo);

typedef struct InputSlot InputSlot;

u16 EmblemChoisesGetInputSlotNewBits(InputSlot *slot, u32 mask);
u16 EmblemChoisesGetNewBits(u32 slotIndex, u32 mask);

unsigned int GetEmblemChoisesInputSlot(void);

void DrawEmblemChoises(void);

void EmblemChoisesWriteSubBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2);

void EmblemChoisesWriteSubBg0Offset(u32 offsetX, u32 offsetY);
void WriteSubBlendBrightness(u32 plane1, u32 plane2, u32 ev1, u32 ev2, s32 brightness);

u32 EmblemChoisesGXS_SetVisiblePlane(u32 bits);

u32 GetSubDispcntBits(void);

void WriteEmblemChoisesScreenMap(void);

s32 MoveEmblemChoisesIndex(s32 step);
s32 MoveEmblemChoisesIndexByTouch(void);
void ResetEmblemChoisesState(void);
void WriteEmblemChoisesChoiceTiles(u16 *mapData, s32 column, s32 row);
void WriteEmblemChoisesTiles(void);
void WriteEmblemChoisesSelectedTiles(s32 choiceIndex);
