#pragma once

#include "types.h"
#include "Main/Unknown/code_020467d0.h" // StateCallbacks
#include "Main/Unknown/code_020e0680.h" // CollisionHitRecord
#include "Main/Unknown/code_0210b000.h" // SoundStartParams

extern CollisionHitRecord data_0216b8c4;
extern CollisionHitRecord data_0216b8ec;
extern const StateCallbacks gKuriboStateTable[];
extern const StateCallbacks gMkdEfBubbleStateTable[];
extern const StateCallbacks gKoopaBlockStateTable[];

// Objects whose layout isn't known yet.
extern const char gKuriboNsbmdName[];
extern const char gKuriboNsbtpName[];
extern const char gEarthenPipe1NsbmdName[];
extern const char gEarthenPipe2NsbmdName[];

extern u8 *gKartResponsesByKind[][4];
extern u8 *gKartFirstResponsesByKind[][4];
extern u8 *gItemObjectResponsesByKind[][14];
extern u8 *gItemObjectFirstResponsesByKind[][14];
