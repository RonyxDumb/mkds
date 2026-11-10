#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void ReleaseResultsBattle(void);
void AdvanceResultsBattle(SceneNumbers *sceneNumbers);
void InitResultsBattle(void *heap, s32 b, s32 c);
