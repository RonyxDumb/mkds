#include "Main/Item/item_koura_w_far.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"

u32 GetItemKouraWFarDistanceSquared(void) {
    return gSoundFalloffs[7].mFarDistanceSquared;
}
