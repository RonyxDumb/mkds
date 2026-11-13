#include "Main/Sound/distance_sound_volume.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/bound.h"

u32 GetDistanceSoundInverseVolume(void) {
    u32 value0;
    value0 = 0xau;
    value0 = (u32) FindMapObjectKindUpdateList(value0);
    value0 = *(const u32 *) ((value0) + (0));
    value0 = *(const u32 *) ((value0) + (0));
    value0 = *(const u32 *) ((value0) + (164));
    value0 = (0x7f000u) - (value0);
    value0 = ((s32) value0 >> 12);
    return value0;
}
