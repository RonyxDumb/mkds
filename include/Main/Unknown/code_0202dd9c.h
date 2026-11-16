#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h" // MinuteSecondMillisecondTime

typedef struct SelectCharacter SelectCharacter;

unsigned int ghost_getDlGhostCount(void);
unsigned int ghost_getMyGhostCount(void);
unsigned int ghost_getTotalGhostCount(void);
unsigned int GetSlotGhostBuffer(void);
void *GetCourseGhostBuffer(void);
void PrintGhostRecordInfo(SelectCharacter *fileSets, s16 (*labelRows)[4], void *name, s32 characterIndex, s32 kartIndex,
                          s32 courseId, MinuteSecondMillisecondTime *time);
void ghost_vblank(void);
void ghost_finish(void);
void ghost_render(s32 sceneNumbers);
void ghost_create(void *heap);
