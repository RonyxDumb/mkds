#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

void UpdateBalloonShrinking(Balloon *balloon, u16 kartIndex, s32 scaleStep);
void UpdateBalloonInflating(Balloon *balloon, u16 kartIndex, s32 scaleStep);
// Leaves mKartIndex unset.
Balloon *StartBalloon(u16 nsbtpFrameIndex, Vec3 *targetPos);
void ResetBalloons(void);
void *CreateBalloonUpdateList(void);
void *CreateBalloonDrawList(void);
void UpdateBalloon(void *mapObjectList,
                   Balloon *balloon); /* skipped for objects with mFlags & 4 (parked pool objects) */
void UpdateBalloonAngle(Balloon *balloon);
