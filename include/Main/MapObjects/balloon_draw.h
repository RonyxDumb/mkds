#pragma once

#include "types.h"
#include "Main/MapObjects/balloon.h" // Balloon
#include "code_0201c528.h" // ParticleEmitter
#include "Main/Kart/kart_name_tags.h"

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

u32 GetBalloonDistanceSquared(Balloon *balloon);
u32 GetBalloonFlagBits(Balloon *balloon);

void FollowBalloonTarget(Balloon *balloon);

void SetBalloonEffectColor(ParticleEmitter *effect, Balloon *balloon);

typedef struct MapObjectList MapObjectList;

void DrawBalloon(void *mapObjectList, Balloon *balloon);
void SetupDrawBalloon(void *mapObjectList);
void CreateBalloon(MapObjectList *mapObjectList); /* also sets word +0x1c of the group record to 1 */

void InitBalloon(
    Balloon *balloon); /* marks the balloon unowned (mUnk_a4 = -1) and parks the pooled object (ParkMapObject) */
