#include "Main/Sound/playing_sound_handle_reset.h"
#include "player.h"
#include "Main/Sound/sound_source_list.h"

void ResetPlayingSoundHandle(PlayingSound *sound) {
    sound->mUnk_04 = 0;
    NNS_SndHandleInit(&sound->mSeqPlayer);
}
