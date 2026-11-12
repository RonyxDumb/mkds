#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/Sound/sound_start.h"

u32 StartSoundIfKartStarOrKiller(MapObject *mapObject, Kart *kart) {
    if (kart->mItemEffect != 1 && kart->mItemEffect != 3) {
        return 0;
    }
    if (mapObject->mSound != NULL) {
        StartSound(&mapObject->mSound->mSoundSource, 0xe8, 0x7f, 0);
    } else {
        StartSoundFullVolume(&kart->mSoundSource, 0xe8);
    }
    return 1;
}
