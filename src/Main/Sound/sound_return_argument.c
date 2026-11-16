#include "Main/Sound/sound_return_argument.h"
#include "Main/Sound/sound_sources.h"

void SoundNopWrapper(void *address) {
    SoundNop(address);
}
