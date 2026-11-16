#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

void mobj_emitDriverHitSfx(MapObject *mapObject, SoundSource *soundSource, s32 d, s32 e);
void mobj_20D2600(s32 soundId, Vec3 *position, s32 falloffKind);
void mobj_setSizeY(MapObject *mapObject, s32 baseSize);
s32 mobj_getBoundingSphereSize(MapObject *mapObject);
void mobj_setFarClip(MapObject *mapObject, s32 drawDistance);
