#include "Main/Sound/distance_sound_volume.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/bound.h"

u32 GetDistanceSoundInverseVolume(void) {
    u32 volumeValue;
    volumeValue = 0xau;
    volumeValue = (u32) FindMapObjectKindUpdateList(volumeValue);
    volumeValue = *(const u32 *) ((volumeValue) + (0));
    volumeValue = *(const u32 *) ((volumeValue) + (0));
    volumeValue = *(const u32 *) ((volumeValue) + (164));
    volumeValue = (0x7f000u) - (volumeValue);
    volumeValue = ((s32) volumeValue >> 12);
    return volumeValue;
}
