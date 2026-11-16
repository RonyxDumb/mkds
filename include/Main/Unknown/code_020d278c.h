#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

void mobj_setScale(MapObject *mapObject, Vec3 *scale);
void mobj_setSizeX(MapObject *mapObject, s32 baseSize);
// Allocates the sound source object of the map object (field94, 0x44 bytes) with volume curve 2
// (SoundSource.mFalloffIndex) and copies the curve's field20 into field70. Then it calls sfx_210CF9C and,
// when bit 0 of the source's field34 is set, SetSoundSourceFlagBit.
void mobj_initSoundEmitterForObjectSfxParam2(MapObject *mapObject);
SoundDistanceSquaredChange *mobj_initSoundEmitterExForObjectSfxParam2(MapObject *mapObject);
// Allocates the sound source object of the map object (field94, 0x44 bytes) with volume curve 3
// (SoundSource.mFalloffIndex) and copies the curve's field20 into field70. Then it calls sfx_210CF9C and,
// when bit 0 of the source's field34 is set, SetSoundSourceFlagBit.
void mobj_initSoundEmitterForObjectSfxParam3(MapObject *mapObject);
// Allocates the sound source object of the map object (field94, 0x44 bytes) with volume curve 4
// (SoundSource.mFalloffIndex) and copies the curve's field20 into field70. Then it calls sfx_210CF9C and,
// when bit 0 of the source's field34 is set, SetSoundSourceFlagBit.
void mobj_initSoundEmitterForObjectSfxParam4(MapObject *mapObject);
