#pragma once
#include "types.h"
#include "Main/MapObjects/bakubaku.h" // MoveTree
#include "01/MapObjects/map_object_model.h"

#define MOVE_TREE_KART_HIT_FRAMES 30
#define MOVE_TREE_HIT_FRAME_STEP 2
#define MOVE_TREE_SOUND_FRAME 0x1e

#define MOVE_TREE_SOUND_ID 0x11f

void InitMoveTree(MoveTree *moveTree); /* starts the path follower (InitGroupFollower) */

extern struct MapObjectModel *gMoveTree;
