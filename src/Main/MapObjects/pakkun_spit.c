#include "Main/MapObjects/pakkun_spit.h"

#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/pakkun.h"
#include "Main/MapObjects/empty_kind_data.h"
#include "Main/MapObjects/crab.h"

const u16 gFlipperInitMapObjectFlag = 0x200;

MapObjectKindDescriptor gPakkunSpitKindDescriptor = {0,
                                                     {0, 0},
                                                     0xd4,
                                                     InitPakkunSpit,
                                                     CreatePakkunSpitKindData,
                                                     0,
                                                     0,
                                                     0,
                                                     CreatePakkunSpitUpdateList};

void InitPakkunSpit(MapObject *mapObject) {
    u32 flags = mapObject->mFlags;
    u32 addedFlags = gPakkunSpitInitMapObjectFlag;
    u32 newFlags = ((flags) | (addedFlags));
    mapObject->mFlags = newFlags;
    ParkMapObject(mapObject);
    CreateMapObjectSoundSourceFalloff2(mapObject);
}

u32 CollideKartWithPakkunSpit(PakkunSpit *pakkunSpit, Kart *kart, u8 *firstResponse, u8 *response) {
    u32 firstResponseValue = *firstResponse;
    u8 result = *response;
    if (firstResponseValue == 1) {
        pakkunSpit->mMapObject.mFlags = pakkunSpit->mMapObject.mFlags | gPakkunSpitDisabledFlag;
        pakkunSpit->mState = 1;
        if (kart->mItemEffect == KART_ITEM_EFFECT_STAR || kart->mItemEffect == KART_ITEM_EFFECT_KILLER) {
            pakkunSpit->mMapObject.mDistanceSquaredAndFlags =
                pakkunSpit->mMapObject.mDistanceSquaredAndFlags | gPakkunSpitSkipSoundFlag;
        }
        StartSoundIfKartStarOrKiller(&pakkunSpit->mMapObject, kart);
    }
    return result;
}

void UpdatePakkunSpit(void *mapObjectList, PakkunSpit *pakkunSpit) {
    s32 falloffIndex;
    SoundStartParams soundRequest;
    ParticleInstance *entry;
    switch (pakkunSpit->mState) {
        case 0:
            pakkunSpit->mHeightOffset = pakkunSpit->mHeightOffset + pakkunSpit->mHeightSpeed;
            pakkunSpit->mHeightSpeed = pakkunSpit->mHeightSpeed - 0x1000;
            if (pakkunSpit->mHeightOffset <= 0) {
                pakkunSpit->mHeightOffset = 0;
                pakkunSpit->mHeightSpeed = PAKKUN_SPIT_HEIGHT_SPEED;
                if ((pakkunSpit->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
                    if (pakkunSpit->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                        falloffIndex = 2;
                    } else if (pakkunSpit->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                        falloffIndex = 3;
                    } else {
                        falloffIndex = 4;
                    }
                    soundRequest.mSoundId = PAKKUN_SPIT_OBJECT_SOUND_ID;
                    soundRequest.mPositionSource = &pakkunSpit->mMapObject.mPos;
                    soundRequest.mFalloffIndex = falloffIndex;
                    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&pakkunSpit->mMapObject.mPos);
                    StartSoundFromParams(&soundRequest);
                }
            }
            if (AdvanceGroupFollower(&pakkunSpit->mFollower) != FALSE && pakkunSpit->mFollower.mForward == 0) {
                pakkunSpit->mState = 1;
            } else {
                GetGroupFollowerLinearPosStep(&pakkunSpit->mFollower, &pakkunSpit->mMapObject.mPos,
                                              &pakkunSpit->mMapObject.mPosStep);
                pakkunSpit->mMapObject.mPos.y = pakkunSpit->mMapObject.mPos.y + (pakkunSpit->mHeightOffset + 0xf000);
            }
            if (pakkunSpit->mEmitter == NULL) {
                return;
            }
            if ((pakkunSpit->mMapObject.mFlags & MAP_OBJECT_FLAGS_NOT_DRAWN) != 0) {
                pakkunSpit->mEmitter->mFlags.mEmissionStopped = 1;
                return;
            }
            PlaceEffect(pakkunSpit->mEmitter, &pakkunSpit->mMapObject.mPos);
            pakkunSpit->mEmitter->mFlags.mEmissionStopped = 0;
            return;
        case 1:
            if (pakkunSpit->mEmitter != NULL) {
                for (entry = pakkunSpit->mEmitter->mParticles.mFront; entry != NULL; entry = entry->mNext) {
                    entry->mAge = entry->mLife;
                }
                StopEffectAndClearPointer((void **) &pakkunSpit->mEmitter);
            }
            ParkMapObject(&pakkunSpit->mMapObject);
            return;
    }
}

MapObjectKindData *CreatePakkunSpitKindData(void) {
    return CreateMapObjectKindDataWithSound(&CollideKartWithPakkunSpit, NULL, NULL, 1, 1, (0x0000018du));
}
