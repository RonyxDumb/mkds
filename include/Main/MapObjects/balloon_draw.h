#pragma once

#include "types.h"
#include "Main/MapObjects/balloon.h" // Balloon
#include "code_0201c528.h" // ParticleEmitter
#include "Main/Kart/kart_name_tags.h"
#include "01/MapObjects/data_0209bc74.h"

#define BALLOON_SCALE_SWING_PER_FRAME 50
#define BALLOON_SWING_ANGLE_PER_FRAME 0x640
#define BALLOON_SCALE_FACTOR_PER_FRAME 0x258

typedef struct MapObjectList MapObjectList;

void UpdateBalloonShrinking(Balloon *balloon, u16 kartIndex, s32 scaleStep);
void UpdateBalloonInflating(Balloon *balloon, u16 kartIndex, s32 scaleStep);
// Leaves mKartIndex unset.
Balloon *StartBalloon(u16 nsbtpFrameIndex, Vec3 *targetPos);
void ResetBalloons(void);
MapObjectList *CreateBalloonUpdateList(void);
MapObjectList *CreateBalloonDrawList(void);
void UpdateBalloon(void *mapObjectList,
                   Balloon *balloon); /* skipped for objects with mFlags & 4 (parked pool objects) */
void UpdateBalloonAngle(Balloon *balloon);

u32 GetBalloonDistanceSquared(Balloon *balloon);
u32 GetBalloonFlagBits(Balloon *balloon);

void FollowBalloonTarget(Balloon *balloon);

void SetBalloonEffectColor(ParticleEmitter *effect, Balloon *balloon);

void DrawBalloon(void *mapObjectList, Balloon *balloon);
void SetupDrawBalloon(void *mapObjectList);
void CreateBalloon(MapObjectList *mapObjectList); /* also sets word +0x1c of the group record to 1 */

void InitBalloon(
    Balloon *balloon); /* marks the balloon unowned (mKartIndex = -1) and parks the pooled object (ParkMapObject) */

extern const u16 gBalloonDrawRotateZAngles[4][4];
extern const s32 gBalloonDrawListIndices[4][4];
extern struct MapObjectModel *gBalloon;
extern Vec3 gBalloonCameraPosHalf;
extern Vec3 gBalloonCameraPosEighth;
