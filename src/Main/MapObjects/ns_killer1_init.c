#include "Main/MapObjects/ns_killer1_init.h"
#include "Main/MapObjects/ns_killer2.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/straight_segment_lengths.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

void InitNsKiller1(NsKiller1 *nsKiller1) {
    InitGroupFollower(&nsKiller1->mFollower, nsKiller1->mMapObject.mCourseMapRow, 0);
    SetStraightSegmentLengths(&nsKiller1->mFollower);
    CreateParkedMapObjects(MAP_OBJECT_KIND_NS_KILLER2, 0x14, nsKiller1);
    nsKiller1->mMapObject.mFarDistanceSquared = gSoundFalloffs[9].mFarDistanceSquared;
}
