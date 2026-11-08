#include "Main/Unknown/code_0210e328.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_0210bcf4.h"

void ResetPlayingSoundHandle(PlayingSound *sound) {
    sound->mUnk_04 = 0;
    NNS_SndHandleInit(&sound->mSeqPlayer);
}
