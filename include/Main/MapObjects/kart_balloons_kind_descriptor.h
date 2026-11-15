#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

#define KART_BALLOONS_NEVER_START_FRAMES 0xffff
#define KART_BALLOONS_START_FRAMES 0x3c
#define KART_BALLOONS_RESPAWN_WAIT_FRAMES 30

#define KART_BALLOONS_HIT_SOUND_ID 0x14f

extern const MapObjectKindDescriptor gKartBalloonsKindDescriptor;
