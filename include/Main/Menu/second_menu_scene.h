#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h"

// Called with the object of the state machine; each state function reads it as the type of its machine.
typedef void (*StateCallback)(void *stateObject);

// The enter and update callbacks of one state of a StateMachine's table.
typedef struct StateCallbacks {
    /* 00 */ StateCallback mEnter;
    /* 04 */ StateCallback mUpdate;
} StateCallbacks;

// Object StateDualHandler_Execute and StateDualHandler_SetState take.
typedef struct StateMachine {
    /* 00 */ const StateCallbacks *mStateTable;
    /* 04 */ u32 mStateFrames;
    /* 08 */ void *mObject;
    /* 0c */ u16 mStateCount;
    /* 0e */ u16 mState;
    /* 10 */ u16 mNextState;
    /* 12 */ u16 mNextStateRequested;
} StateMachine;

s32 GetCupForCourse(s32 courseId);
u32 GetSomeInternalCourseId(u8 courseIndex);
s32 GetCourseIdFromInternalId();
void StructCO_ConfigureRacerDefault(int entryIndex, u32 characterIndex, u32 kartIndex, int playerKind, u32 teamIndex,
                      int listedCpuSlot);
void MaybeSetRacerCount(s32 entryCount);
void InitializeGlobalCO(void *heap);
s32 SceneFn_Menu2(void *sceneNumbers);
void Scene_Menu2_Update(void);
void Scene_Menu2_VBlank(void);
void Scene_Menu2_Finalize(void);
void Scene_Menu2_Initialize(void);
void StateDualHandler_Execute(StateMachine *stateMachine);
void StateDualHandler_SetState(StateMachine *stateMachine, u16 state);

extern SceneCallbacks g_Scene_Menu2;

