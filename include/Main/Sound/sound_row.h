#pragma once

#include "types.h"
#include "Main/Menu/data_02153000.h"

typedef struct SoundRow SoundRow;

u32 GetSceneSoundRowIndex(s32 sceneNumber, SoundRow *output);
u32 GetCourseSoundRowIndex(u32 courseId, SoundRow *output);
SoundRow GetSoundRow(u32 rowIndex);

extern const SoundRow gSoundRowTable[53];
