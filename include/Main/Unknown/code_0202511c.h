#pragma once

#include "types.h"

typedef struct SoundRow SoundRow;

u32 GetSceneSoundRowIndex(s32 sceneNumber, SoundRow *output);
u32 GetCourseSoundRowIndex(u32 courseId, SoundRow *output);
SoundRow GetSoundRow(u32 rowIndex);
