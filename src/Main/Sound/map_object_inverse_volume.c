#include "Main/Sound/map_object_inverse_volume.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/bound.h"

u32 GetDistanceSoundInverseVolume(void) {
    u32 value;
    value = 0xau;
    value = (u32) FindMapObjectKindUpdateList(value);
    value = *(const u32 *) ((value) + (0));
    value = *(const u32 *) ((value) + (0));
    value = *(const u32 *) ((value) + (164));
    value = (0x7f000u) - (value);
    value = ((s32) value >> 12);
    return value;
}
