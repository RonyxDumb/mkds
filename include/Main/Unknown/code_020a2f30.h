#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

void blln_deflate(Balloon *balloon, u16 kartIndex, s32 scaleStep);
void blln_inflate(Balloon *balloon, u16 kartIndex, s32 scaleStep);
// Leaves mKartIndex unset.
Balloon *blln_spawn(u16 nsbtpFrameIndex, Vec3 *targetPos);
void func_020a305c(void);
void *blln_setupLogicPart(void);
void *blln_setupRenderPart(void);
void blln_update(void *mapObjectList,
                   Balloon *balloon); /* skipped for objects with mFlags & 4 (parked pool objects) */
void UpdateBalloonAngle(Balloon *balloon);
