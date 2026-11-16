#pragma once

#include "types.h"
#include "03/System/tasks.h"
#include "03/Sound/sound_seq.h"

void UpdateSound(TaskEntry *task, void *arg);

extern u8 gSoundDataSdatName[23];
extern struct SoundData *gSoundData;
