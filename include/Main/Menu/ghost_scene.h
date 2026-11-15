#pragma once

#include "types.h"
#include "Main/Race/data_021759c0.h" // MinuteSecondMillisecondTime
#include "tp.h"
#include "Main/Menu/data_02174000.h"

typedef struct GhostInfoFileSets GhostInfoFileSets;
typedef struct GhostRecord GhostRecord;
typedef struct SlotGhostRecord SlotGhostRecord;

unsigned int GetSlotGhostCount(void);
unsigned int GetCourseGhostCount(void);
unsigned int GetGhostCount(void);
SlotGhostRecord *GetSlotGhostBuffer(void);
GhostRecord *GetCourseGhostBuffer(void);
void PrintGhostRecordInfo(GhostInfoFileSets *fileSets, const s16 (*labelRows)[4], void *name, s32 characterIndex,
                          s32 kartIndex, s32 courseId, MinuteSecondMillisecondTime *time);
void WriteGhostSceneRegisters(void);
void ReleaseGhostScene(void);
void AdvanceGhostScene(s32 sceneNumbers);
void InitGhostScene(void *heap);

void LoadGhostSceneFiles(void);

u32 GhostSceneGetCupCourseIdAtIndex(s32 cupCourseIndex);

// Indexes of gGhostSceneCallbacks.
#define GHOST_SCENE_CALLBACKS_SEND 0
#define GHOST_SCENE_CALLBACKS_GET_SCAN 1
#define GHOST_SCENE_CALLBACKS_GET_SLOT 2

extern struct GhostSceneCallbacks *gGhostSceneCallbacks[3];
extern struct GhostScene *gGhostScene;

