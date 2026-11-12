#include "Main/Sound/sound_system.h"

#include "Main/Sound/scene_players_release.h"
#include "Main/Sound/sound_mode_restore.h"
#include "player.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "code_0212df7c.h"
#include "output_effect.h"
#include "code_0212ba34.h"
#include "Main/Menu/data_0217d068.h"

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
    data_0217d06c = NNS_SndHeapAlloc(gCurrentSndHeap, 0x1020, SoundHeapAllocNop, NULL, 0);
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
    NNS_SndCaptureStartOutputEffect((void *) (((u32) data_0217d06c + 0x1f) & ~0x1f), 0x1000, type);
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
    if (gScenePlayers.mProgress != 0) {
        UpdateScenePlayersNop(&gScenePlayers);
    }
    NNS_SndMain();
}

void InitScenePlayers(ScenePlayers *scenePlayers, SceneSoundState *sceneSoundState, u32 sceneSoundRowIndex,
                      ScenePlayersSeqInfo seqInfo) {
    SetupSoundMode(&gSoundModeHolder, scenePlayers, 0);
    *(ScenePlayersSeqInfo *) &scenePlayers->mUnk_09 = seqInfo;
    scenePlayers->mSceneSoundState = sceneSoundState;
    scenePlayers->mSoundRowIndex = sceneSoundRowIndex;
    NNS_SndHandleInit(&scenePlayers->mSeqPlayer);
    NNS_SndHandleInit(&scenePlayers->mSecondSeqPlayer);
    scenePlayers->mProgress = 1;
}
