#include "Main/Sound/sound_return_argument.h"
#include "Main/Sound/sound_sources.h"

void SoundNopWrapper(u32 address) {
    SoundNop(address);
}
