#pragma once

#include "types.h"

typedef struct TaskEntry TaskEntry;

// The position of one menu object.
typedef struct MenuPairObjectPosition {
    /* 00 */ u16 mX;
    /* 02 */ u16 mY;
} MenuPairObjectPosition;

typedef struct OamRange OamRange;

// The five menu objects of a menu pair, the task that slides them in and out, and whether they are sliding out.
typedef struct MenuPairObjects {
    /* 00 */ OamRange *mObjects[5];
    /* 14 */ TaskEntry *mTask;
    /* 18 */ u8 mSlidingOut;
} MenuPairObjects;

BOOL IsMenuPairObjectsNotSlidingOut(void);
void AdvanceMenuPairObjectSlideOut0(TaskEntry *taskEntry, void *arg);
void AdvanceMenuPairObjectSlideOut1(TaskEntry *taskEntry, void *arg);
void AdvanceMenuPairObjectSlideOut2(TaskEntry *taskEntry, void *arg);
void AdvanceMenuPairObjectSlideOut3(TaskEntry *taskEntry, void *arg);
void AdvanceMenuPairObjectSlideOut4(TaskEntry *taskEntry, void *arg);
BOOL IsMenuPairObjectsSliding(void);
void ChangeMenuPairObjectImages(u32 row);
void StartMenuPairObjectsSlideOut(void);
void AdvanceMenuPairObjectsSlideInEnd(TaskEntry *task, void *arg);
