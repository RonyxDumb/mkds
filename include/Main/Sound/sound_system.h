#pragma once

#include "types.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/menu_screens_work.h"
#include "player.h"
#include "sound_player_type.h"
#include "stream.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"

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

extern u16 gSeqTrackMask;
extern s32 gSoundOutputEffectType;
extern s32 gSceneSeqVolume;
extern u32 gSoundFadeSteps;

extern void *gSoundOutputEffectBuffer;
// Passed by address to NNS_SndArcPlayerStartSeqArc, SetSndHandleTrackVolume and NNS_SndHandleInit; UpdateSeqQueue tests
// it for null.
extern NNSSndSeqPlayer *gSharedSeqHandle;
extern u32 gFileSndArcOpen;

extern ScenePlayers gScenePlayers;
extern SoundModeHolder gSoundModeHolder;
extern struct NNSSndArc gFileSndArc;
