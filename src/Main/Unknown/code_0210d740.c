#include "Main/Unknown/code_0210d740.h"

#include "Main/Unknown/code_0210d73c.h"
#include "Main/Unknown/code_0210dc60.h"
#include "code_0212bcac.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_0212df7c.h"
#include "code_0212d214.h"
#include "output_effect.h"
#include "code_0212ba68.h"
#include "Main/Unknown/code_0210d890.h"
#include "Main/Unknown/code_0210d894.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0210d960.h"

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
