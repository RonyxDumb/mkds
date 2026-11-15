#pragma once

#include "types.h"
#include "03/System/tasks.h"
#include "03/code_021cdbd0.h"

void UpdateSound(TaskEntry *task, void *arg);

extern u8 gSoundDataSdatName[23];
extern struct SoundData *gSoundData;
