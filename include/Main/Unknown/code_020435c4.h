#pragma once

#include "types.h"

// The pair of input bits the item code tests to use the held item.
#define ITEM_BITS 0x600
// Item input bit held while the item is used: the held item is thrown in front of the kart.
#define ITEM_THROW_FORWARD_BIT 0x40

typedef struct MissionFileRow MissionFileRow;

u32 GetVolatileHalfwordIndex39(void);
void SetInputOpenDuringRace(u32 openDuringRace);
void RequestBits(s32 slotIndex, u32 bits);
void UpdateInputSlots(void);
unsigned int GetPadKeys(void);
void UpdatePadKeysAndTouchMic(void);
void SetLeftRightKeysSwapped(u32 mirrorMode);
void ReleaseTouchMicInputWrapper(void);
void SetNoKeysAndUpdateInputSlots(void);
void ClearInputSlots(void);
void StopTouchAutoSamplingWrapper(void);
void StartInputSlots(void);
void ResetInputSlots(void);
void InitInputSlotsAndTouchMic(void *heap);
void LoadSndBanksForCharacters(u32 useCurrentEntries);
void SelectGhostReadCourseRecordAndWait(u32 courseId);
void ReadCourseGhostRecordAndLoadFile(u32 courseId);
void ReadCourseAndSlotGhostRecords(u32 courseId, u32 slotIndex);
void ReadCourseGhostRecordAndWait(u32 courseId);
void SetNextRaceFromMissionRow(MissionFileRow *missionFileRow, u32 tableRow, u32 tableColumn);
void ReplaceEntryWithCpu(u32 entryIndex);
