#include "Main/Item/entry_kart_sound.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
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
