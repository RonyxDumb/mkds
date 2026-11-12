#include "Main/Menu/menu_sound.h"

#include "Main/Menu/data_02175628.h"
#include "player.h"
#include "code_0212df7c.h"
#include "Main/Sound/sound_system.h"

u32 MenuStartSeqArc(u32 seqIndex, u32 seqArcNo) {
    return NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, seqArcNo, seqIndex);
}

u32 StartMenuSound(u32 seqIndex) {
    return MenuStartSeqArc(seqIndex, 0u);
}

u32 MenuGetPairHasPair(InputSlotPair *pair) {
    return pair->mHasPair;
}
