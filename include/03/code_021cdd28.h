#pragma once

#include "types.h"

typedef struct TaskEntry TaskEntry;

typedef struct MenuPairObjectPosition {
    /* 00 */ u16 mX;
    /* 02 */ u16 mY;
} MenuPairObjectPosition;

typedef struct OamRange OamRange;

typedef struct MenuPairObjects {
    /* 00 */ OamRange *mObjects[5];
    /* 14 */ u32 mTask;
    /* 18 */ u8 mSlidingOut;
} MenuPairObjects;

extern MenuPairObjectPosition gMenuPairObjectPositions[];

BOOL IsMenuPairObjectsNotSlidingOut(void);
void AdvanceMenuPairObjectSlideOut0(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideOut1(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideOut2(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideOut3(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideOut4(TaskEntry *taskEntry);
BOOL IsMenuPairObjectsSliding(void);
void ChangeMenuPairObjectImages(u32 row);
void StartMenuPairObjectsSlideOut(void);
void AdvanceMenuPairObjectsSlideInEnd(u32 task);
