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

void func_02108edc(s32 count, s32 countLimit) {
    u32 c;
    PlayingSound *playingSound;

    if (count == countLimit) {
        if (data_0217c76c[0] != 0xff) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, data_0217c76c[0]);
        }
        if (data_0217c76c[0] == 0x1d7) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1de);
            return;
        }
        c = gRaceSetup->mUnk_3c;
        if (c == 0x65 || c == 0xc9) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xd4);
        }
    } else {
        c = data_0217c770[0];
        if (c == 0xff) {
            return;
        }
        if (!(data_0217c780 & 1)) {
            return;
        }
        playingSound = TakeSoundHandleEntry(&data_0217c7c4);
        if (data_0217d084.mUnk_0c == 0) {
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

void func_02108ed8(void) {}

NNSSndArc *SetCurrentSndArc(void) {
    return NNS_SndArcSetCurrent(&gFileSndArc);
}

void SetPlayerVolumeTarget(u32 index, u32 value) {
    gPlayerVolumeTargets[index] = value;
}

SoundHandlePool *GetSoundHandlePool(u32 index) {
    return &(&data_0217c7c4)[index];
}

void SetSoundOutputEffect(s32 type) {
    ChangeSoundOutputEffect(type);
}

NNSSndSeqPlayer **GetSndHandles(void) {
    return data_0217c838;
}

NNSSndSeqPlayer **func_02108e7c(void) {
    return &data_0217c83c;
}

NNSSndSeqPlayer **GetSndHandleSlot(u32 index) {
    return data_0217c838 + index;
}
