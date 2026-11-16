#pragma once

#include "types.h"
#include "Main/Menu/menu_label_cell_rows.h"

// Sound ids GetSceneSoundRowIndex writes into the row of a mission run: the sequence of the garden mission and of a
// mission that counts pending objects, the first bank by mission, and the second bank every mission with a first bank
// or Hanachan gets.
#define SOUND_SEQ_ID_MISSION_GARDEN 0x2a
#define SOUND_SEQ_ID_MISSION_COUNT_PENDING_WITH_SEQ 0x2c
#define SOUND_BANK_MISSION_DONKETU 0x25
#define SOUND_BANK_MISSION_IWANTE 0x26
#define SOUND_BANK_MISSION_KURIKING 0x27
#define SOUND_BANK_MISSION_KING_TERESA 0x28
#define SOUND_BANK_MISSION_BOMB_KING 0x29
#define SOUND_BANK_MISSION_SECOND 0x22

typedef struct SoundRow SoundRow;

u32 GetSceneSoundRowIndex(s32 sceneNumber, SoundRow *output);
u32 GetCourseSoundRowIndex(u32 courseId, SoundRow *output);
SoundRow GetSoundRow(u32 rowIndex);

extern const SoundRow gSoundRowTable[53];
