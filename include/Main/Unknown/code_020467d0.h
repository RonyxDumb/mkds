#pragma once

#include "types.h"

// Pair of callbacks at an element of the table behind the first word of StateMachine.
typedef struct StateCallbacks {
    /* 00 */ void (*mEnter)(void *);
    /* 04 */ void (*mUpdate)(void *);
} StateCallbacks;

// Object sm_execute and sm_gotoState take (the code reaches it through a void pointer).
typedef struct StateMachine {
    /* 00 */ StateCallbacks *mStateTable;
    /* 04 */ s32 mStateFrames;
    /* 08 */ void *mObject;
    /* 0c */ u8 mUnk_0c[0x2];
    /* 0e */ u16 mState;
    /* 10 */ u16 mNextState;
    /* 12 */ u16 mNextStateRequested;
} StateMachine;

s32 FindCupIndexOfCourse(s32 courseId);
u32 GetCupCourseIdAtIndex(s32 courseIndex);
s32 rconf_getCourseNumber();
void rconf_setDriverConfigNext(int entryIndex, u32 characterIndex, u32 kartIndex, int playerKind, u32 teamIndex, int f);
void RefreshRaceSetupKartCounts(s32 entryCount);
void rconf_init(void *heap);
s32 menu2_run(void *a);
unsigned int menu2_draw(unsigned int value);
unsigned int menu2_vblank(unsigned int value);
void menu2_finish(void);
void menu2_create(void);
void sm_execute(void *rawStateMachine);
void sm_gotoState(void *rawStateMachine, u16 state);
