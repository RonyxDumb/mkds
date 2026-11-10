#pragma once

#include "types.h"

// Pair of callbacks at an element of the table behind the first word of StateMachine.
typedef struct StateCallbacks {
    /* 00 */ UnkFunc *mEnter;
    /* 04 */ UnkFunc *mUpdate;
} StateCallbacks;

// Object AdvanceStateMachine and SetStateMachineState take.
typedef struct StateMachine {
    /* 00 */ const StateCallbacks *mStateTable;
    /* 04 */ u32 mStateFrames;
    /* 08 */ void *mObject;
    /* 0c */ u16 mStateCount;
    /* 0e */ u16 mState;
    /* 10 */ u16 mNextState;
    /* 12 */ u16 mNextStateRequested;
} StateMachine;

s32 FindCupIndexOfCourse(s32 courseId);
u32 GetCupCourseIdAtIndex(s32 courseIndex);
s32 FindCupCourseIndex();
void SetNextRaceEntry(int entryIndex, u32 characterIndex, u32 kartIndex, int playerKind, u32 teamIndex, int f);
void RefreshRaceSetupKartCounts(s32 entryCount);
void CreateRaceSetupObjects(void *heap);
s32 RunSecondMenuScene(void *sceneNumbers);
unsigned int SecondMenuUpdateReturnArgument(unsigned int value);
unsigned int SecondMenuAfterUpdateReturnArgument(unsigned int value);
void SetNextRaceByModeWrapper(void);
void InitSecondMenuScene(void);
void AdvanceStateMachine(StateMachine *stateMachine);
void SetStateMachineState(StateMachine *stateMachine, u16 state);
