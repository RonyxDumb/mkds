#pragma once

#include "types.h"
#include "Main/Menu/data_02175628.h"

void LoadSelectKartData(void);

void WriteSelectKartRegisters(void);
void SelectKartG2S_SetWnd0Position(u32 startX, u32 startY, u32 endX, u32 endY);
void SelectKartG2S_SetWndOutsidePlane(u32 lowBits, u32 extraBitFlag);
void SelectKartG2S_SetWnd0InsidePlane(u32 lowBits, u32 extraBitFlag);
u32 WriteSubWinEnableBits(u32 bits);
void WriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient);
void WriteSubBg3CntBits(u32 bits);
void SelectKartG2S_SetBG3Offset(u32 offsetX, u32 offsetY);
u32 SelectKartGXS_SetVisiblePlane(u32 bits);
u32 SelectKartGX_SetVisiblePlane(u32 bits);
void ReleaseSelectKart(void);
u32 SelectKartMB_IsMultiBootChildWrapper(void);
u32 SelectKartMB_IsMultiBootChild(void);
u16 *SelectKartMB_GetMultiBootParam(void);
unsigned int SelectKartGetConnectionKind(void);

typedef struct InputSlot InputSlot;

int AdvanceSelectKart(void);
u16 SelectKartGetNewBits(u32 slotIndex, u32 mask);
u16 SelectKartGetInputSlotNewBits(InputSlot *inputSlot, u32 mask);

u32 SelectKartGetSlotPairY(u32 slot);
unsigned int SelectKartGetPairY(InputSlotPair *inputSlotPair);
u32 SelectKartGetSlotPairX(u32 slot);
unsigned int SelectKartGetPairX(InputSlotPair *inputSlotPair);

typedef struct InputSlotPair InputSlotPair;

BOOL SelectKartIsSlotPairNew(u32 slot);
BOOL SelectKartIsPairNewUnlessLost(InputSlotPair *pair);
BOOL SelectKartIsPairNew(InputSlotPair *pair);
BOOL SelectKartIsPairRecentlyLost(InputSlotPair *pair);

unsigned int SelectKartGetPairHasPair(InputSlotPair *inputSlotPair);
void SetDataSharingSendByteInState8(u8 sendByte);
unsigned int GetConnectionState(void);

void InitSelectKart(void *parentHeap, s32 mode, void *mainOam, void *subOam);

typedef struct CellFileSet CellFileSet;
typedef struct LayoutEntryTable LayoutEntryTable;

u32 GetOwnEntryIndex(void);
unsigned int GetParticipantEntryIndex(unsigned int participantIndex);
u16 GetOwnIndexOrZero(void);
void SelectKartMI_CpuClearFast(void *destination, u32 size);
void SelectKartMI_CpuFillFast(void *destination, u32 value, u32 size);
void RefreshKartMenuParamElements(void);
void SetKartMenuParamElementOffset(s32 elementIndex, s32 endCellIndex, s32 paramValue, CellFileSet *parts);
void *GetCellLayoutEntrySwapped(s32 index, LayoutEntryTable *cellLayout);

void PrintSelectKartMessage(void);
u32 IsSelectKartModeAndTimerZero(void);
void SetSelectKartSPartsOffsetY(void);

unsigned int GetLabelLayoutCount(void *labelLayout);
unsigned int GetCellLayoutCount(void *cellLayout);

void SetSelectKartGpMPartsOffsets(void);
u32 IsSelectKartTouchRepeat(s32 rectIndex);
s32 UpdateSelectKartTouchHold(void);
