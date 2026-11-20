#include "Main/Race/race_item_slot_sound.h"
#include "Main/Sound/sound_handle_accessors_and_mission_count_seq.h"
#include "sound_player_control.h"

void StopRaceItemSlotSound(void) {
    NNSSndSeqPlayer **seqPlayer;
    seqPlayer = GetSndHandles();
    NNS_SndPlayerStopSeq(seqPlayer, 0);
}
