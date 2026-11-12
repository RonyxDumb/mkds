#pragma once
#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateCallbacks
#include "Main/MapObjects/choropu.h" // CollisionHitRecord
#include "Main/Sound/data_0210b000.h" // SoundStartParams

extern CollisionHitRecord data_0216b8c4;

extern CollisionHitRecord data_0216b8ec;

extern const StateCallbacks gKuriboStateTable[];



// Objects whose layout isn't known yet.
extern const char gKuriboNsbmdName[];

extern const char gKuriboNsbtpName[];






extern u8 *gKartResponsesByKind[][4];

extern u8 *gKartFirstResponsesByKind[][4];

extern u8 *gItemObjectResponsesByKind[][14];

extern u8 *gItemObjectFirstResponsesByKind[][14];
