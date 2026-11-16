#pragma once

#include "types.h"

typedef struct SceneNumbersView SceneNumbersView;

void bres_finalize(void);
void bres_update(SceneNumbersView *sceneNumbers);
void bres_init(void *heap, s32 b, s32 c);
