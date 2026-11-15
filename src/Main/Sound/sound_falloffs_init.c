#include "Main/Sound/sound_falloffs_init.h"
#include "Main/Sound/sound_falloffs.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"

PlayingSound gPlayingSoundEntries[12];
SoundFalloff gSoundFalloffs[16];

void InitSoundFalloffsAndPlayingSounds(void) {
    InitSoundFalloffs();
    InitPlayingSoundPool(gPlayingSoundEntries, 0xc);
    SetSoundPanFunction(ComputeSoundPan);
    SetSoundDistanceFunction(ComputeSoundDistanceAndOffsets);
    SetSoundVolumeFunction(ComputeSoundVolume);
}
