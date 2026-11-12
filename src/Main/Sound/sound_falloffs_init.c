#include "Main/Sound/sound_falloffs_init.h"
#include "Main/Sound/sound_falloffs.h"
#include "Main/Unknown/code_0210d020.h"
#include "Main/Unknown/code_0210d4a4.h"
#include "Main/Unknown/unk_0217c000.h"

void InitSoundFalloffsAndPlayingSounds(void) {
    InitSoundFalloffs();
    InitPlayingSoundPool(data_0217c91c, 0xc);
    SetSoundPanFunction(ComputeSoundPan);
    SetSoundDistanceFunction(ComputeSoundDistanceAndOffsets);
    SetSoundVolumeFunction(ComputeSoundVolume);
}
