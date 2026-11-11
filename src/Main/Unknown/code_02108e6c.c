#include "Main/Unknown/code_02108e6c.h"

#include "Main/Unknown/code_02108e94.h"
#include "Main/Unknown/code_0210d000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_02108eb4.h"
#include "Main/Unknown/code_02108ec4.h"
#include "Main/Unknown/code_02108ed8.h"
#include "Main/Unknown/code_02108edc.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"

void StartMissionRunCountSeq(s32 count, s32 countLimit) {
    u32 c;
    PlayingSound *playingSound;

    if (count == countLimit) {
        if (gMissionRunLimitSeqNo[0] != 0xff) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, gMissionRunLimitSeqNo[0]);
        }
        if (gMissionRunLimitSeqNo[0] == 0x1d7) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1de);
            return;
        }
        c = gRaceSetup->mMissionMapObjectKind0;
        if (c == 0x65 || c == 0xc9) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xd4);
        }
    } else {
        c = gMissionRunCountSeqNo[0];
        if (c == 0xff) {
            return;
        }
        if (!(gRaceSoundKind & 1)) {
            return;
        }
        playingSound = TakeSoundHandleEntry(&gSoundHandlePool);
        if (gSoundModeHolder.mSeqStartEnabled == 0) {
            return;
        }
        if (playingSound->mSeqPlayer != NULL) {
            NNS_SndPlayerStopSeq(&playingSound->mSeqPlayer, 0);
        }
        if (playingSound->mSeqPlayer != NULL) {
            NNS_SndPlayerStopSeq(&playingSound->mSeqPlayer, 0);
        }
        NNS_SndArcPlayerStartSeqArc(&playingSound->mSeqPlayer, 0, c);
    }
}

void RunScenesSoundNop(void) {}

NNSSndArc *SetCurrentSndArc(void) {
    return NNS_SndArcSetCurrent(&gFileSndArc);
}

void SetPlayerVolumeTarget(u32 index, u32 value) {
    gPlayerVolumeTargets[index] = value;
}

SoundHandlePool *GetSoundHandlePool(u32 index) {
    return &(&gSoundHandlePool)[index];
}

void SetSoundOutputEffect(s32 type) {
    ChangeSoundOutputEffect(type);
}

NNSSndSeqPlayer **GetSndHandles(void) {
    return gSndHandleSlots;
}

NNSSndSeqPlayer **GetSecondSndHandleSlot(void) {
    return &data_0217c83c;
}

NNSSndSeqPlayer **GetSndHandleSlot(u32 index) {
    return gSndHandleSlots + index;
}
