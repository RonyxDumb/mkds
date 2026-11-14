#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"

void SetMapObjectScale(MapObject *mapObject, const Vec3 *scale);
void SetMapObjectExtentX(MapObject *mapObject, s32 baseSize);
// Allocates mSound (0x44 bytes) with volume curve 2 and copies the curve's mFarDistanceSquared into the map object.
// Then it calls SetSoundSourceEnabled and, when bit 0 of mSourceFlags is set, SetSoundSourceFlagBit.
void CreateMapObjectSoundSourceFalloff2(MapObject *mapObject);
SoundDistanceSquaredChange *CreateVehicleSoundSource(MapObject *mapObject);
// Allocates mSound (0x44 bytes) with volume curve 3 and copies the curve's mFarDistanceSquared into the map object.
// Then it calls SetSoundSourceEnabled and, when bit 0 of mSourceFlags is set, SetSoundSourceFlagBit.
void CreateMapObjectSoundSourceFalloff3(MapObject *mapObject);
// Allocates mSound (0x44 bytes) with volume curve 4 and copies the curve's mFarDistanceSquared into the map object.
// Then it calls SetSoundSourceEnabled and, when bit 0 of mSourceFlags is set, SetSoundSourceFlagBit.
void CreateMapObjectSoundSourceFalloff4(MapObject *mapObject);
