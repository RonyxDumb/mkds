#include "Main/MapObjects/group_follower_init.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/group_paths.h"

#pragma thumb on
void InitGroupFollower(GroupFollower *follower, CourseMapRow *row, s32 speed) {
    GroupFollower *followerCopy = follower;
    u32 value1 = (u32) row;
    u32 speedCopy = speed;
    u32 unused;
    value1 = *(const u16 *) ((value1) + 38u);
    InitGroupFollowerForGroup(followerCopy, value1, speedCopy);
}
#pragma thumb off
