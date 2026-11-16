#pragma once

#include "types.h"

typedef struct SoundRow SoundRow;

u32 scene_getMusicData(s32 sceneNumber, void *output);
u32 GetSequenceTableIndexAndData(u32 courseId, void *output);
SoundRow GetSoundRow(u32 rowIndex);
