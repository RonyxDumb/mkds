#include "Main/Sound/sound_nop_wrapper.h"
#include "Main/Sound/sound_sources.h"

void SoundNopWrapper(void *address) {
    SoundNop(address);
}
