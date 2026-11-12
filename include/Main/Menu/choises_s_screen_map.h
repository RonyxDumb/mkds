#pragma once

#include "types.h"

unsigned int ChoisesSGetCurrentMode(void);

void *ChoisesSGetCurrentHeap(void);

void UpdateChoisesSScreenMap(void);

void UpdateChoisesS(void);

unsigned int ChoisesSGetConnectionKind(void);

BOOL IsChoisesSOpenAllowedDuringRace(void);

unsigned int GetRaceDone(void);
void ChoisesSSetLVselIndex6Requested(unsigned int value);

typedef struct InputSlotPair InputSlotPair;

u32 ChoisesSIsSlotPairNew(s32 slotIndex);
u32 ChoisesSIsPairNewUnlessRecentlyLost(InputSlotPair *inputSlotPair);
u32 ChoisesSIsPairNew(InputSlotPair *inputSlotPair);
u32 ChoisesSIsPairRecentlyLost(InputSlotPair *inputSlotPair);

unsigned int ChoisesSGetPairHasPair(const void *inputSlotPair);

typedef struct InputSlot InputSlot;

u16 ChoisesSGetInputSlotNewBits(InputSlot *slot, u32 mask);
u16 ChoisesSGetNewBits(s32 slotIndex, u32 mask);

unsigned int GetChoisesSInputSlot(void);
unsigned int ChoisesSGetUnfilledNotEliminated(void);

s32 ChoisesSIsBackupCommandRunning(void);
s32 ChoisesSIsBackupBusy(void);
u32 IsRaceDoneOrReplayPastStartFrames(void);
u32 IsChoisesSOpenAllowedAfterRace(void);

unsigned int ChoisesSIsBackupEnabled(void);

void WriteChoisesSListScreenMap(void);

s32 GetEntryEndKind(void);
u32 GetChoisesSListIndex(void);
void WriteChoisesSSelectedValueTiles(s32 selectedIndex);
