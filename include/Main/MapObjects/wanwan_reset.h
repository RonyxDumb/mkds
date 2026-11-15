#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateCallbacks
#include "Main/MapObjects/code_020d6dc0.h" // Quaternion
#include "Main/Sound/data_0210b000.h" // SoundStartParams
#include "Main/MapObjects/wanwan.h" // Wanwan
#include "Main/Kart/shadow_model.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

#define WANWAN_PROBE_OFFSET_Y 0xf000

typedef struct CourseMapRow CourseMapRow;

extern SoundStartParams gWanwanTouchGroundSoundParams;
extern Quaternion gWanwanResetSurfaceOrientation;
extern StateCallbacks gWanwanStateTable[];

void UpdateWanwanFollowPath(void *stateObject);
void InitWanwanOnChain(Wanwan *wanwan, CourseMapRow *row);
void InitWanwanOnPath(Wanwan *wanwan, CourseMapRow *row);
void ResetWanwan(Wanwan *wanwan);
void CreateWanwanAndRockShadow(void);

extern struct ShadowModel *gWanwanRockShadow;
extern struct Nsbmd *gWanwan;

extern const MapObjectKindDescriptor gWanwanOnChainKindDescriptor;
extern const MapObjectKindDescriptor gWanwanOnPathKindDescriptor;
