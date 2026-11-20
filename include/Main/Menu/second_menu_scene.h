#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h"

// Called with StateMachine.mObject: some state functions read it as the type of the object that owns the machine,
// others ignore it (some machines pass NULL).
typedef void (*StateCallback)(void *stateObject);

// The enter and update callbacks of one state of a StateMachine's table.
typedef struct StateCallbacks {
    /* 00 */ StateCallback mEnter;
    /* 04 */ StateCallback mUpdate;
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
u32 GetCupCourseIdAtIndex(u8 courseIndex);
s32 FindCupCourseIndex();
void SetNextRaceEntry(int entryIndex, u32 characterIndex, u32 kartIndex, int playerKind, u32 teamIndex,
                      int listedCpuSlot);
void RefreshRaceSetupKartCounts(s32 entryCount);
void CreateRaceSetupObjects(void *heap);
s32 RunSecondMenuScene(void *sceneNumbers);
void SecondMenuUpdateNop(void);
void SecondMenuAfterUpdateNop(void);
void SetNextRaceByModeWrapper(void);
void InitSecondMenuScene(void);
void AdvanceStateMachine(StateMachine *stateMachine);
void SetStateMachineState(StateMachine *stateMachine, u16 state);

extern SceneCallbacks gSecondMenuSceneCallbacks;

