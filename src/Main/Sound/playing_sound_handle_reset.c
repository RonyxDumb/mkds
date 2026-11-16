#include "Main/Sound/playing_sound_handle_reset.h"
#include "sound_player_control.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"

void ResetPlayingSoundHandle(PlayingSound *sound) {
    sound->mUnk_04 = 0;
    NNS_SndHandleInit(&sound->mSeqPlayer);
}
