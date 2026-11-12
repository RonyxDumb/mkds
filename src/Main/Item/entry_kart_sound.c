#include "Main/Item/entry_kart_sound.h"
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

void StartEntryKartSound(Kart *kart, u32 soundId) {
    if (kart == NULL) {
        return;
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) == 0) {
        return;
    }
    StartSoundFullVolume(&kart->mSoundSource, soundId);
}
