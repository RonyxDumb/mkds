#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/Sound/sound_start.h"

u32 StartSoundIfKartStarOrKiller(MapObject *mapObject, Kart *kart) {
    if (kart->mItemEffect != KART_ITEM_EFFECT_STAR && kart->mItemEffect != KART_ITEM_EFFECT_KILLER) {
        return 0;
    }
    if (mapObject->mSound != NULL) {
        StructMQRacerEntry_SomeFn_8(&mapObject->mSound->mSoundSource, 0xe8, 0x7f, 0);
    } else {
        StartSoundFullVolume(&kart->mSoundSource, 0xe8);
    }
    return 1;
}
