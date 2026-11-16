#include "Main/Item/item_koura_w_far.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"

u32 GetItemKouraWFarDistanceSquared(void) {
    return gSoundFalloffs[7].mFarDistanceSquared;
}
