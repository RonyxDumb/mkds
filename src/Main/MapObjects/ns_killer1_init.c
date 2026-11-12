#include "Main/MapObjects/ns_killer1_init.h"
#include "Main/MapObjects/ns_killer.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/straight_segment_lengths.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

void InitNsKiller1(NsKiller1 *nsKiller1) {
    InitGroupFollower(&nsKiller1->mFollower, nsKiller1->mMapObject.mCourseMapRow, 0);
    SetStraightSegmentLengths(&nsKiller1->mFollower);
    CreateParkedMapObjects(MAP_OBJECT_KIND_NS_KILLER2, 0x14, nsKiller1);
    nsKiller1->mMapObject.mFarDistanceSquared = gSoundFalloffs[9].mFarDistanceSquared;
}
