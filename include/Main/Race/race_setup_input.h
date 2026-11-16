#pragma once

#include "types.h"

#define ITEM_BITS 0x600
// Item input bit held while the item is used: the held item is thrown in front of the kart.
#define ITEM_THROW_FORWARD_BIT 0x40

typedef struct MissionFileRow MissionFileRow;

u32 GetVolatileHalfwordIndex39(void);
void Struct5624_SetXflag1(u32 openDuringRace);
void RequestBits(s32 slotIndex, u32 bits);
void UpdateInputSlots(void);
unsigned int GetPadKeys(void);
void UpdatePadKeysAndTouchMic(void);
void SetLeftRightKeysSwapped(u32 mirrorMode);
void j_ResetGlobal59C4(void);
void SetNoKeysAndUpdateInputSlots(void);
void ClearInputSlots(void);
void StopTouchAutoSamplingWrapper(void);
void StartInputSlots(void);
void MaybeResetInput(void);
void Input_Initialize(void *heap);
void MaybeReloadRacersSfx(u32 useCurrentEntries);
void SelectGhostReadCourseRecordAndWait(u32 courseId);
void LoadStaffGhost(u32 courseId);
void ReadCourseAndSlotGhostRecords(u32 courseId, u8 slotIndex);
void ReadCourseGhostRecordAndWait(u32 courseId);
void SetNextRaceFromMissionRow(MissionFileRow *missionFileRow, u32 tableRow, u32 tableColumn);
void ReplaceEntryWithCpu(u32 entryIndex);

void RequestMPWaitRaceArchivesForNextRace(void);

u16 GetCurrentLapCount(void);
void ResetRacersForTimeTrial(void);
void Scene_Menu2_FinalizeImpl(void);
void PrepareRace(void);
BOOL MaybeLoadStaffGhost(s32 courseId, s32 entryIndex);
BOOL MaybeLoadDownloadGhost(s32 courseId, s32 entryIndex);
BOOL MaybeLoadPersonalGhost(s32 courseId, s32 entryIndex);
void RefreshListedCpuEntryIndices(void);
void PrepareCurrentRaceRacer(s32 entryIndex);
void PopulateGlobalCO(void);

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
BOOL HasSomeSecretFlag(s32 cupIndex);

extern const u32 gCupIndicesTwoCups[2];
extern const u32 gThreeCourseIds[3];
extern const u32 gSixCourseIds[6];
extern const u16 g_CharacterMaskTable[13];
extern const u32 gCupIndicesEightCups[8];

extern const u32 g_InternalCourseIdOrderedTable[8][4];
