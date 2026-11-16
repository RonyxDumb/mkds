#pragma once

#include "types.h"

typedef struct MapObject MapObject;

// Starts sound arg1 at volume 0x7f on the sound source behind MapObject.mUnk_94 with StartSoundWhileRequested.
void mobj_emitSfxFromEmitter(MapObject *mapObject, u32 soundId);
// Starts sound arg1 at volume 0x7f on the sound source behind MapObject.mUnk_94 (sfx_21090C4).
void mobj_emitSfxFromEmitter2(MapObject *mapObject, u32 soundId);
