#pragma once
#include "types.h"
#include "Main/MapObjects/bakubaku.h" // MoveTree
#include "01/MapObjects/data_0209bc74.h"

#define MOVE_TREE_SOUND_ID 0x11f

void InitMoveTree(MoveTree *moveTree); /* starts the path follower (InitGroupFollower) */

extern struct MapObjectModel *gMoveTree;
