#pragma once

#include "types.h"
#include "Main/Menu/menu_label_cell_rows.h"

// Sound ids MaybeGetMusicForMenu writes into the row of a mission run: the sequence of the garden mission and of a
// mission that counts pending objects, the first bank by mission, and the second bank every one of them with a bank
// gets.
#define SOUND_SEQ_ID_MISSION_GARDEN 0x2a
#define SOUND_SEQ_ID_MISSION_COUNT_PENDING 0x2c
#define SOUND_BANK_MISSION_DONKETU 0x25
#define SOUND_BANK_MISSION_IWANTE 0x26
#define SOUND_BANK_MISSION_KURIKING 0x27
#define SOUND_BANK_MISSION_KING_TERESA 0x28
#define SOUND_BANK_MISSION_BOMB_KING 0x29
#define SOUND_BANK_MISSION_SECOND 0x22

typedef struct SoundRow SoundRow;

u32 MaybeGetMusicForMenu(s32 sceneNumber, SoundRow *output);
u32 GetCourseBgmInfo(u32 courseId, SoundRow *output);
SoundRow GetCourseBgmEntry(u32 rowIndex);

extern const SoundRow g_CourseBgmTable[53];
