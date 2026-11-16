#pragma once

#include "types.h"

// A stop sign map object: its position, scale and the matrix axes and position it is drawn with.
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
#include "Main/MapObjects/map_object_model_frame.h"
#include "01/MapObjects/mission_run_map_object.h"
#include "01/MapObjects/map_object_model_animation_load.h"
#include "Main/MapObjects/map_object_matrix.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"

#include "01/MapObjects/kuriking_state_shared.h"

MapObjectList *CreateStopSignDrawList(void);
MapObjectKindData *CreateStopSignKindData(void);
void DrawStopSign(void *mapObjectList, StopSignObject *mapObject);
void LoadStopSign(MapObjectList *mapObjectList);
void InitStopSign(
    MissionRunMapObject *mapObject); /* object is only MapObject-sized; InitStopSign uses just its mMapObject part */

#include "01/Menu/select_ghost.h"

extern MapObjectKindDescriptor gStopSignKindDescriptor;
