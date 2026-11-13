#pragma once

#include "types.h"

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

void RequestMPState16ForNextRace(void);

typedef struct RaceSetupBlock {
    /* 000 */ u32 mUnk_000[0x7a];
} RaceSetupBlock;

u16 GetLapCount(void);
void ResetTimeAttackNextEntries(void);
void SetNextRaceByMode(void);
void SetCurrentRaceFromNext(void);
BOOL SetNextEntryFromSecondSlotGhost(s32 courseId, s32 entryIndex);
BOOL SetNextEntryFromFirstSlotGhost(s32 courseId, s32 entryIndex);
BOOL SetNextEntryFromCourseGhost(s32 courseId, s32 entryIndex);
void RefreshListedCpuEntryIndices(void);
void SetCurrentEntryPlayer(s32 entryIndex);
void ResetRaceSetup(void);

typedef struct RandomState64 RandomState64;

BOOL CopyCourseIdAndAdvanceCourseNumber(void);
s32 AdvanceToNextBattleCourse(void);
s32 AdvanceToNextCourseWrapper(void);
s32 AdvanceToNextCourse(void);
void SetupStaffRollRace(s32 useTrueStaffRoll);
BOOL CopyEntryResultAndSetupAwardRace(void);
void AssignCpuNumbersAndSetupFirstCourse(void);
void BuildCourseList(s32 isVersus);
u32 NextRandomBelowU16(RandomState64 *randomState64, u32 limit);
void AssignCpuNumbers(void);
BOOL IsCupEnabled(s32 cupIndex);

extern const u32 gCupIndicesTwoCups[2];
extern const u32 gThreeCourseIds[3];
extern const u32 gSixCourseIds[6];
extern const u16 gCharacterSndBankMasks[13];
extern const u32 gCupIndicesEightCups[8];

extern const u32 gCupCourseIdTable[8][4];
