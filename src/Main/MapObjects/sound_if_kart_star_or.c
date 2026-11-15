#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/Sound/sound_start.h"

u32 StartSoundIfKartStarOrKiller(MapObject *mapObject, Kart *kart) {
    if (kart->mItemEffect != KART_ITEM_EFFECT_STAR && kart->mItemEffect != KART_ITEM_EFFECT_KILLER) {
        return 0;
    }
    if (mapObject->mSound != NULL) {
        StartSound(&mapObject->mSound->mSoundSource, 0xe8, 0x7f, 0);
    } else {
        StartSoundFullVolume(&kart->mSoundSource, 0xe8);
    }
    return 1;
}
