#pragma once
#include "types.h"
#include "Main/MapObjects/bakubaku.h" // MoveTree
#include "01/MapObjects/data_0209bc74.h"

void InitMoveTree(MoveTree *moveTree); /* starts the path follower (InitGroupFollower) */

extern struct MapObjectModel *gMoveTree;
