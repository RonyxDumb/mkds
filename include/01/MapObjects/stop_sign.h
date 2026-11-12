#pragma once

#include "types.h"
#include "ITCM/code_01ff9000.h"

typedef struct StopSignObject {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mPosX;
    /* 08 */ s32 mPosY;
    /* 0c */ s32 mPosZ;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ u8 mScale[0xc];
    /* 28 */ u8 mMatrixAxes[0x24];
    /* 4c */ s32 mMatrixPosX;
    /* 50 */ s32 mMatrixPosY;
    /* 54 */ s32 mMatrixPosZ;
} StopSignObject;

#include "01/Menu/emblem_input.h"
#include "01/MapObjects/iwante.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02188950.h"
#include "01/code_0219b250.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/MapObjects/map_object_matrix.h"
#include "Main/Unknown/code_02146000.h"
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

void *CreateStopSignDrawList(void);
void CreateStopSignKindData(void);
void DrawStopSign(void *mapObjectList, StopSignObject *mapObject);
void LoadStopSign(MapObjectList *mapObjectList);
void InitStopSign(
    MissionRunMapObject *mapObject); /* object is MapObject-sized; MissionRunMapObject is only the prefix view */

#include "01/Menu/select_ghost.h"
