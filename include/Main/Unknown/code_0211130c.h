#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void UpdateRecordScene(SceneNumbers *sceneNumbers);
void *GetRecordMainOam(void);
void *GetRecordSubOam(void);
