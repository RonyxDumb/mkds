#include "Main/Sound/sound_system.h"

#include "Main/Sound/scene_players_start_stop_and_release.h"
#include "Main/Sound/sound_mode_setup_and_restore.h"
#include "sound_player_control.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "sound_archive_load_result.h"
#include "capture_output_effect.h"
#include "sound_system_main.h"
#include "Main/Sound/sound_set_load.h"

s32 gSoundOutputEffectType = -1;
s32 gSceneSeqVolume = 0x50;
u32 gSoundFadeSteps = 0xa;
u16 gSeqTrackMask = 0xf;
NNSSndSeqPlayer *gSharedSeqHandle;
u32 gFileSndArcOpen;
void *gSoundOutputEffectBuffer;
SoundSetPlayer *gCurrentSoundSetPlayer;
ScenePlayers gScenePlayers;
SoundModeHolder gSoundModeHolder;
NNSSndArc gFileSndArc;

void SetFileSndArcOpen(u32 flag) {
    gFileSndArcOpen = flag;
}

BOOL IsFileSndArcOpen(void) {
    return gFileSndArcOpen;
}

void SetSoundFadeSteps(u32 fadeSteps) {
    gSoundFadeSteps = fadeSteps;
}

u32 GetSoundFadeSteps(void) {
    return gSoundFadeSteps;
}

void InitSoundSystem(void *heapMemory, u32 heapSize, const u8 *filePath) {
    NNS_SndInit();
    gCurrentSndHeap = NNS_SndHeapCreate(heapMemory, heapSize);
    gSoundOutputEffectBuffer = NNS_SndHeapAlloc(gCurrentSndHeap, 0x1020, SoundHeapAllocNop, NULL, 0);
    if (filePath != NULL) {
        NNS_SndArcInit(&gFileSndArc, filePath, gCurrentSndHeap, 0);
        gFileSndArcOpen = 1;
        NNS_SndArcPlayerSetup(gCurrentSndHeap);
    }
    NNS_SndHandleInit(&gSharedSeqHandle);
    SetupSoundMode(&gSoundModeHolder, &gScenePlayers, 0);
}

void SoundHeapAllocNop(void *memory, u32 size, void *data1, u32 data2) {}

void StartSoundOutputEffect(u32 type) {
    NNS_SndCaptureStartOutputEffect((void *) (((u32) gSoundOutputEffectBuffer + 0x1f) & ~0x1f), 0x1000, type);
    gSoundOutputEffectType = type;
}

void ChangeSoundOutputEffect(s32 type) {
    NNS_SndCaptureChangeOutputEffect(type);
    gSoundOutputEffectType = type;
}

void StartSeqAtVolume(u32 seqNo, u32 volume, NNSSndSeqPlayer **handle) {
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    NNS_SndArcGetFileAddress(NNS_SndArcGetSeqInfo(seqNo)->mFileId);
    NNS_SndArcPlayerStartSeq(handle, seqNo);
    NNS_SndPlayerSetVolume(handle, volume);
}

void UpdateSndMain(void) {
    if (gScenePlayers.mProgress != SCENE_PLAYERS_PROGRESS_RELEASED) {
        UpdateScenePlayersNop(&gScenePlayers);
    }
    NNS_SndMain();
}

void InitScenePlayers(ScenePlayers *scenePlayers, SceneSoundState *sceneSoundState, u32 sceneSoundRowIndex,
                      ScenePlayersSeqInfo seqInfo) {
    SetupSoundMode(&gSoundModeHolder, scenePlayers, 0);
    scenePlayers->mSeqInfo = seqInfo;
    scenePlayers->mSceneSoundState = sceneSoundState;
    scenePlayers->mSoundRowIndex = sceneSoundRowIndex;
    NNS_SndHandleInit(&scenePlayers->mSeqPlayer);
    NNS_SndHandleInit(&scenePlayers->mSecondSeqPlayer);
    scenePlayers->mProgress = SCENE_PLAYERS_PROGRESS_INITIALIZED;
}
