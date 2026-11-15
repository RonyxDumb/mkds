#include "Main/Item/item_koura_w_far.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"

u32 GetItemKouraWFarDistanceSquared(void) {
    return gSoundFalloffs[7].mFarDistanceSquared;
}
