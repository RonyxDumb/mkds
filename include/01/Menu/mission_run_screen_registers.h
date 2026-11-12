#pragma once

#include "types.h"

typedef struct MissionGateObject MissionGateObject;

u16 IsMissionGateFrameAdvanced(MissionGateObject *missionGateObject);
void WriteMissionRunLVselScreenRegisters(void);
void UpdateMissionRunLVsel(void);
void MissionRunGX_SetVisiblePlane(u32 bits);
void MissionRunGXS_SetVisiblePlane(u32 bits);
void WriteMissionRunMSselScreenRegisters(void);
void UpdateMissionRunMSsel(void);
void WriteTimeAttackTopMenuRegisters(void);
void SetGhostSceneInitialCallbacksIndex(s32 callbacksIndex);
void UpdateTimeAttackTopMenu(void);
void WriteTimeAttackCharacterRegisters(void);
void UpdateTimeAttackSelectCharacter(void);
void WriteTimeAttackKartRegisters(void);
void UpdateTimeAttackSelectKart(void);
void WriteTimeAttackCupGridRegisters(void);
void TimeAttackSetMenuEntryKind(s32 value);
void TimeAttackSetRaceSetupRequested(s32 value);
void UpdateTimeAttackSelectCupGrid(void);
void WriteTimeAttackCupCourseRegisters(void);
void UpdateTimeAttackSelectCupCourse(void);
void WriteMainBg1Offset(u32 offsetX, u32 offsetY);
void WriteMainBg1CntLowBits(u32 bits);
