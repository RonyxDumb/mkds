#include "Main/Race/race_item_slot_sound.h"
#include "Main/Sound/sound_handle_pool.h"
#include "player.h"

void StopRaceItemSlotSound(void) {
    NNSSndSeqPlayer **seqPlayer;
    seqPlayer = GetSndHandles();
    NNS_SndPlayerStopSeq(seqPlayer, 0);
}
