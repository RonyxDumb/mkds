#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"

void SetMapObjectScale(MapObject *mapObject, Vec3 *scale);
void SetMapObjectExtentX(MapObject *mapObject, s32 baseSize);
// Allocates the sound source object of the map object (mUnk_94, 0x44 bytes) with volume curve 2
// (SoundSource.mFalloffIndex) and copies the curve's mUnk_20 into mUnk_70. Then it calls SetSoundSourceEnabled and,
// when bit 0 of the source's mUnk_34 is set, SetSoundSourceFlagBit.
void CreateMapObjectSoundSourceFalloff2(MapObject *mapObject);
SoundDistanceSquaredChange *CreateVehicleSoundSource(MapObject *mapObject);
// Allocates the sound source object of the map object (mUnk_94, 0x44 bytes) with volume curve 3
// (SoundSource.mFalloffIndex) and copies the curve's mUnk_20 into mUnk_70. Then it calls SetSoundSourceEnabled and,
// when bit 0 of the source's mUnk_34 is set, SetSoundSourceFlagBit.
void CreateMapObjectSoundSourceFalloff3(MapObject *mapObject);
// Allocates the sound source object of the map object (mUnk_94, 0x44 bytes) with volume curve 4
// (SoundSource.mFalloffIndex) and copies the curve's mUnk_20 into mUnk_70. Then it calls SetSoundSourceEnabled and,
// when bit 0 of the source's mUnk_34 is set, SetSoundSourceFlagBit.
void CreateMapObjectSoundSourceFalloff4(MapObject *mapObject);
