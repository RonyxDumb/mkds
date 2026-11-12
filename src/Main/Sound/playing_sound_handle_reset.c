#include "Main/Sound/playing_sound_handle_reset.h"
#include "code_0212bcac.h"
#include "Main/Sound/sound_source_list.h"

void ResetPlayingSoundHandle(PlayingSound *sound) {
    sound->mUnk_04 = 0;
    NNS_SndHandleInit(&sound->mSeqPlayer);
}
