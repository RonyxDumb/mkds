#include "03/Sound/sound_data.h"
#include "03/Sound/sound_seq.h"
#include "player.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/System/exp_heap.h"
#include "03/System/dwc_archive.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/System/tasks.h"
#include "code_0212ba34.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"

u8 gSoundDataSdatName[23] = {0x73, 0x6f, 0x75, 0x6e, 0x64, 0x2f, 0x73, 0x6f, 0x75, 0x6e, 0x64, 0x5f,
                             0x64, 0x61, 0x74, 0x61, 0x2e, 0x73, 0x64, 0x61, 0x74, 0x2e, 0x6c};
struct SoundData *gSoundData;

void CreateSoundData(void) {
    u32 fileSize;
    gSoundData = AllocExpHeapBlock(0x9c, 4);
    gSoundData->mFileData = LoadFile(gSoundDataSdatName, &fileSize, 0x20);
    NNS_SndInit();
    NNS_SndArcInitOnMemory(&gSoundData->mArc, gSoundData->mFileData);
    NNS_SndArcPlayerSetup(NULL);
    NNS_SndHandleInit(&gSoundData->mSeqPlayer);
    gSoundData->mTask = AddTask(0, UpdateSound, NULL, 0xc8);
}

void ReleaseSoundData(void) {
    RequestTaskRemoval(0, gSoundData->mTask);
    FreeExpHeapBlockAndClearPointer(&gSoundData);
}

void StartSoundSeq(u32 index) {
    u32 playResult = index;
    u32 playerNumber;
    u32 sequenceIndex;
    u32 unusedValue;
    sequenceIndex = (playResult) + (0u);
    playResult = (u32) &gSoundData;
    playResult = *(const u32 *) ((playResult) + 0u);
    playResult = (playResult) + 144u;
    playerNumber = 0u;
    playResult = NNS_SndArcPlayerStartSeqArc((const void *) playResult, playerNumber, sequenceIndex);
}

u32 SetSoundSeqVolume(u32 volume) {
    u32 setVolumeResult = volume;
    u32 volumeValue;
    u32 setVolumeFunction;
    volumeValue = (setVolumeResult) + (0u);
    setVolumeResult = (u32) &gSoundData;
    setVolumeResult = *(const u32 *) ((setVolumeResult) + 0u);
    setVolumeResult = (setVolumeResult) + 144u;
    setVolumeFunction = (u32) &NNS_SndPlayerSetVolume;
    setVolumeResult = (u32) NNS_SndPlayerSetVolume((NNSSndSeqPlayer **) setVolumeResult, volumeValue);
    return setVolumeResult;
}

void SetSoundSeqTrackPitch(u32 tracks, u32 pitch) {
    NNS_SndPlayerSetTrackPitch(&gSoundData->mSeqPlayer, tracks, pitch);
}

void StopSoundSeq(void) {
    NNS_SndPlayerStopSeq(&gSoundData->mSeqPlayer, 0);
}

void UpdateSound(TaskEntry *task, void *arg) {
    NNS_SndMain();
}
