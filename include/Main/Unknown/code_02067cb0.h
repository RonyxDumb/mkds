#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct MapObject MapObject;

// Collision response 7 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): runs driver_tryStartForwardFlip and, when it starts, for the selected kart increments the counter of the
// record driver_getPlayerStatistics returns and sets bit 0x20000 of field48. Stores 7 through the second parameter and
// returns 2.
int driver_initForwardFlipReaction(Kart *p, s32 *a);
// Collision response 5 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): runs driver_tryStartSpinOut with 2 and, when that succeeds, passes the result of ptcm_createEmitter with 0x4f at
// mPos to rptc_2081E3C with the kart index and 0x46 if bit 0x10 of field7C is set and, for the
// selected kart, increments the counter of the record driver_getPlayerStatistics returns. Stores 5 through the second
// parameter and returns 0.
int driver_initDoubleSpinOutFireReaction(Kart *p, s32 *a);
// Collision response 6 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object is set it
// runs driver_tryStartSpinOut with 2 and, when that succeeds, for the selected kart increments the counter of the record
// driver_getPlayerStatistics returns and runs rptc_startWaterEffect with the kart index; it then stores 4 through the second
// parameter. Otherwise it stores 0. Returns 0.
int driver_initDoubleSpinOutWaterReaction(Kart *p, s32 *a, MapObject *c);
// Collision response 4 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object is set it
// runs driver_tryStartSpinOut with 2 and, when that succeeds, calls ptcm_createEmitter with 0xc, 0xd and 0xe at mPos unless the field58
// member of mKartModelsEntry is non-zero and, for the selected kart, increments the counter of the record
// driver_getPlayerStatistics returns; it then stores 4 through the second parameter. Otherwise it stores 2. Returns 0xb.
int driver_initDoubleSpinOutReaction(Kart *p, s32 *a, MapObject *c);
// Collision response 3 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object is set it
// runs driver_tryStartSpinOut with 1 and, when that succeeds, calls ptcm_createEmitter with 0xc, 0xd and 0xe at mPos unless the field58
// member of mKartModelsEntry is non-zero and, for the selected kart, increments the counter of the record
// driver_getPlayerStatistics returns; it then stores 3 through the second parameter. Otherwise it stores 2. Returns 0xb.
int driver_initSingleSpinOutReaction(Kart *p, s32 *a, MapObject *c);
