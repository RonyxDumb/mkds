#pragma once

#include "types.h"

typedef struct Kart Kart;

// Collision response 12 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns
// for the kart and the map object): stores 0xc through the second parameter and returns 5.
int CollideKartWithMapObjectResponse12(Kart *kart, s32 *output);
// Collision response 10 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns
// for the kart and the map object): stores 0xa through the second parameter and returns 2.
int CollideKartWithMapObjectResponse10(Kart *kart, s32 *output);
// Collision response 9 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): stores 9 through the second parameter and returns 2.
int CollideKartWithMapObjectResponse9(Kart *kart, s32 *output);
// Collision response 8 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): stores 8 through the second parameter and returns 2.
int CollideKartWithMapObjectResponse8(Kart *kart, s32 *output);
