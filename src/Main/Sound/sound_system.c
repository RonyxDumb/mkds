#include "Main/Sound/sound_system.h"

#include "Main/Sound/scene_players_release.h"
#include "Main/Sound/sound_mode_restore.h"
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
#include "Main/Sound/sound_seq.h"
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
u32 g_GlobalSdatUsed;
void *g_SomeSdatPtr;
SoundSetPlayer *gCurrentSoundSetPlayer;
ScenePlayers gScenePlayers;
SoundModeHolder gSoundModeHolder;
NNSSndArc g_GlobalSdat;

void SetGlobalSdatUsed(u32 flag) {
    g_GlobalSdatUsed = flag;
}

BOOL Sound_IsGlobalSdatUsed(void) {
    return g_GlobalSdatUsed;
}

void SetSoundFadeSteps(u32 fadeSteps) {
    gSoundFadeSteps = fadeSteps;
}

u32 GetSoundFadeSteps(void) {
    return gSoundFadeSteps;
}

void Sound_InitializeWithData(void *heapMemory, u32 heapSize, const u8 *filePath) {
    Sound_EnsureInitialized();
    g_SoundContext = Sound_InitializeContext(heapMemory, heapSize);
    g_SomeSdatPtr = Sound_Context_Allocate(g_SoundContext, 0x1020, SoundHeapAllocNop, NULL, 0);
    if (filePath != NULL) {
        Sound_ReadSdatFromPathImpl(&g_GlobalSdat, filePath, g_SoundContext, 0);
        g_GlobalSdatUsed = 1;
        NNS_SndArcPlayerSetup(g_SoundContext);
    }
    NNS_SndHandleInit(&gSharedSeqHandle);
    SetupSoundMode(&gSoundModeHolder, &gScenePlayers, 0);
}

void SoundHeapAllocNop(void *memory, u32 size, void *data1, u32 data2) {}

void MaybeSendArm7SoundShit(u32 type) {
    NNS_SndCaptureStartOutputEffect((void *) (((u32) g_SomeSdatPtr + 0x1f) & ~0x1f), 0x1000, type);
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
    Sound_MaybeGetRawFilePointer(Sound_GetSseqInfoEntry(seqNo)->mFileId);
    NNS_SndArcPlayerStartSeq(handle, seqNo);
    NNS_SndPlayerSetVolume(handle, volume);
}

void UpdateSndMain(void) {
    if (gScenePlayers.mProgress != SCENE_PLAYERS_PROGRESS_RELEASED) {
        nullsub_15(&gScenePlayers);
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
