#include "Main/Menu/menu_sound.h"

#include "Main/System/input_slots.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
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
