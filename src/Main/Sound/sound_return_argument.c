#include "Main/Sound/sound_return_argument.h"
#include "Main/Sound/sound_sources.h"

u32 SoundReturnArgumentWrapper(u32 address) {
    return SoundReturnArgument(address);
}
