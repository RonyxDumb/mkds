#include "Main/Sound/sound_falloffs_and_playing_sounds_init.h"
#include "Main/Sound/sound_falloffs.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"

PlayingSound gPlayingSoundEntries[12];
SoundFalloff gSoundFalloffs[16];

void InitSoundFalloffsAndPlayingSounds(void) {
    InitSoundFalloffs();
    InitPlayingSoundPool(gPlayingSoundEntries, 0xc);
    SetSoundPanFunction(ComputeSoundPan);
    SetSoundDistanceFunction(ComputeSoundDistanceAndOffsets);
    SetSoundVolumeFunction(ComputeSoundVolume);
}
