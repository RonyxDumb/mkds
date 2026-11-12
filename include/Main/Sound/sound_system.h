#pragma once

#include "types.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"

void StartSoundOutputEffect(u32 type);
void ChangeSoundOutputEffect(s32 type);
void StartSeqAtVolume(u32 seqNo, u32 volume, NNSSndSeqPlayer **handle);
void UpdateSndMain(void);
void InitScenePlayers(ScenePlayers *scenePlayers, SceneSoundState *sceneSoundState, u32 sceneSoundRowIndex,
                      ScenePlayersSeqInfo seqInfo);

void SoundHeapAllocNop(void *memory, u32 size, void *data1, u32 data2);

void InitSoundSystem(void *heapMemory, u32 heapSize, const u8 *filePath);

unsigned int GetSoundFadeSteps(void);
void SetSoundFadeSteps(unsigned int fadeSteps);
BOOL IsFileSndArcOpen(void);
void SetFileSndArcOpen(unsigned int flag);
