#pragma once

#include "types.h"

u32 GetNextSceneNumber(void);
int GetCurrentSceneNumber(void);
void InitRunScenesKind(void);
void CreateRunScenesState(void *heap);
s32 UpdateShapeMapObjectCounts(void);
void ClearShapeMapObjectCountListPointer(void);
