#pragma once

#include "types.h"

typedef struct Kart Kart;

// Collision response 2 of gCollideKartWithMapObjectResponses (indexed by the value func_020d6be0 returns for the kart
// and the map object): stores 2 through the second parameter and returns 0xb.
s32 CollideKartWithMapObjectResponse2(Kart *kart, s32 *output);
// Collision response 0 of gCollideKartWithMapObjectResponses (indexed by the value func_020d6be0 returns for the kart
// and the map object): stores 0 through the second parameter and returns 0. Same bytes as
// CollideKartWithMapObjectNoResponse, the table entry for index 1.
s32 CollideKartWithMapObjectResponse0(Kart *kart, s32 *output);
