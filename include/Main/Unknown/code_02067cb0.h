#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct MapObject MapObject;

// Collision response 7 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): runs TryStartKartState3 and, when it starts, for the selected kart increments the
// counter of the record GetEntryKartCounters returns and sets KART_DRIVE_HIT_STATE in mDriveFlags. Stores 7 through the
// second parameter and returns 2.
int CollideKartWithMapObjectResponse7(Kart *kart, s32 *result);
// Collision response 5 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): runs TrySpinKart with 2 and, when that succeeds, passes the result of StartEffect with
// 0x4f at mPos to SetupKartFollowEffectWithVelocity with the kart index and 0x46 if KART_ENTRY_HAS_CHARACTER_ANIMATION
// is set in mEntryFlags and, for the selected kart, increments the counter of the record GetEntryKartCounters returns.
// Stores 5 through the second parameter and returns 0.
int CollideKartWithMapObjectResponse5(Kart *kart, s32 *result);
// Collision response 6 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object
// is set it runs TrySpinKart with 2 and, when that succeeds, for the selected kart increments the counter of the record
// GetEntryKartCounters returns and runs StartKartSpinSideEffects with the kart index; it then stores 4 through the
// second parameter. Otherwise it stores 0. Returns 0.
int CollideKartWithMapObjectResponse6(Kart *kart, s32 *result, MapObject *mapObject);
// Collision response 4 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object
// is set it runs TrySpinKart with 2 and, when that succeeds, calls StartEffect with 0xc, 0xd and 0xe at mPos unless the
// mUnk_058 member of mKartModelsEntry is non-zero and, for the selected kart, increments the counter of the record
// GetEntryKartCounters returns; it then stores 4 through the second parameter. Otherwise it stores 2. Returns 0xb.
int CollideKartWithMapObjectResponse4(Kart *kart, s32 *result, MapObject *mapObject);
// Collision response 3 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object
// is set it runs TrySpinKart with 1 and, when that succeeds, calls StartEffect with 0xc, 0xd and 0xe at mPos unless the
// mUnk_058 member of mKartModelsEntry is non-zero and, for the selected kart, increments the counter of the record
// GetEntryKartCounters returns; it then stores 3 through the second parameter. Otherwise it stores 2. Returns 0xb.
int CollideKartWithMapObjectResponse3(Kart *kart, s32 *result, MapObject *mapObject);
