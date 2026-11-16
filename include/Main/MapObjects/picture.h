#pragma once

#include "types.h"
#include "01/MapObjects/map_object_model.h"

// Sound ids UpdatePicture starts at fixed frames of the model animation: the first and second frame sets and the latest
// frame of picture 1, and frame 0 of picture 2 (only in its PLAY state).
#define PICTURE1_FIRST_FRAMES_SOUND_ID 0x116
#define PICTURE1_SECOND_FRAMES_SOUND_ID 0x117
#define PICTURE1_LATEST_FRAME_SOUND_ID 0x115
#define PICTURE2_SOUND_ID 0x118

extern struct MapObjectModel *gPicture2;
extern struct MapObjectModel *gPicture1;
