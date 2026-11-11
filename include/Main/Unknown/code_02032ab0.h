#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void ReleaseResultsBattle(void);
void AdvanceResultsBattle(SceneNumbers *sceneNumbers);
void InitResultsBattle(void *heap, void *mainOam, void *subOam);
