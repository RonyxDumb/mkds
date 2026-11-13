#include "Main/MapObjects/cow.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/basabasa.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/data_02166000.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/kanoke64_init.h"
#include "Main/MapObjects/bound.h"

MapObjectModel *gKanoke64;

MapObjectKindDescriptor gKanoke64KindDescriptor = {0,
                                                   {0, 0},
                                                   0xb0,
                                                   InitKanoke64,
                                                   CreateEmptyMapObjectKindData,
                                                   CreateKanoke64DrawList,
                                                   0,
                                                   0,
                                                   CreateKanoke64UpdateList};

static inline u32 MapObjectRandomBelow(u32 limit) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return ((mapObjectRandom->mValue >> 32) * limit) >> 32;
}

static inline u16 MapObjectRandomBelowU16(u32 limit) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return (u32) (((mapObjectRandom->mValue >> 32) * limit) >> 32);
}

static inline void StartKanoke64Sound(Kanoke64 *kanoke64, s32 soundId) {
    SoundStartParams soundRequest;
    s32 falloffIndex;

    if (kanoke64->mMapObject.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (kanoke64->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
        falloffIndex = 2;
    } else if (kanoke64->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
        falloffIndex = 3;
    } else {
        falloffIndex = 4;
    }
    soundRequest.mSoundId = soundId;
    soundRequest.mPositionSource = &kanoke64->mMapObject.mPos;
    soundRequest.mFalloffIndex = falloffIndex;
    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&kanoke64->mMapObject.mPos);
    StartSoundFromParams(&soundRequest);
}

void CreateKanoke64(void *mapObjectList) {
    gKanoke64 = CreateMapObjectModelAnimated(mapObjectList, "kanoke_64.nsbmd");
    CreateMapObjectModelNsbcaAnimation(gKanoke64, "kanoke_64.nsbca");
}

void DrawKanoke64(void *mapObjectList, Kanoke64 *kanoke64) {
    s32 commandArg;

    SetMapObjectModelNsbcaFrameIndex(gKanoke64, kanoke64->mNsbcaFrameIndex);
    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    kanoke64->mMapObject.mMatrix.mRows[3].x = kanoke64->mMapObject.mPos.x >> 4;
    kanoke64->mMapObject.mMatrix.mRows[3].y = kanoke64->mMapObject.mPos.y >> 4;
    kanoke64->mMapObject.mMatrix.mRows[3].z = kanoke64->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &kanoke64->mMapObject.mMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &kanoke64->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gKanoke64, kanoke64);
}

void InitKanoke64Objects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    Kanoke64 *kanoke64;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (kanoke64 = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        if (kanoke64->mMapObject.mFlags & 0x800) {
            kanoke64->mTimer = (u16) (MapObjectRandomBelowU16(25) + 200);
        }
    }
}

// Returns a random value below b (0 when b is 0), advancing the generator a.
u32 NextRandomBelow(RandomState64 *randomState64, u32 limit) {
    if (limit == 0) {
        return 0;
    }
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    if (limit == 0) {
        return randomState64->mValue >> 32;
    }
    return ((randomState64->mValue >> 32) * limit) >> 32;
}

s16 Kanoke64FX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 Kanoke64MulFixed12NoRound(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_NO_ROUND(multiplicand, multiplier);
}

static inline s64 XzDistanceSquared(const Vec3 *firstPos, const Vec3 *secondPos) {
    s32 deltaX;
    s32 deltaZ;

    deltaX = firstPos->x - secondPos->x;
    deltaZ = firstPos->z - secondPos->z;
    return (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
}

static inline BOOL Kanoke64IsKartNearInAngle(Kanoke64 *kanoke64, s32 objectAngle) {
    s32 kartIndex;
    BOOL isHumanGhostOrPeer;
    s32 angleDifference;
    Kart *kart;

    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        isHumanGhostOrPeer = FALSE;
        if (gRaceSetup->mCurrentEntries[(u16) kartIndex].mPlayer.mKind <= 3 &&
            ((1 << gRaceSetup->mCurrentEntries[(u16) kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            isHumanGhostOrPeer = TRUE;
        }
        if (isHumanGhostOrPeer == FALSE && kartIndex != gRaceSetup->mEntryIndex) {
            continue;
        }
        kart = GetKart((u16) kartIndex);
        if (XzDistanceSquared(&kart->mPos, &kanoke64->mMapObject.mPos) >= 0x225510000000LL) {
            continue;
        }
        angleDifference =
            FX_Atan2Idx(kart->mPos.x - kanoke64->mMapObject.mPos.x, kart->mPos.z - kanoke64->mMapObject.mPos.z) -
            objectAngle;
        if (angleDifference < -0x1f40) {
            continue;
        }
        if (angleDifference <= 0x1f40) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline void Kanoke64SetRandomPos(Vec3 *outPos, s32 baseX, s32 baseY, s32 baseZ) {
    outPos->x = baseX - 0x5000 + MapObjectRandomBelow(0xa000);
    GetMapObjectRandom();
    outPos->y = baseY;
    outPos->z = baseZ - 0x28000 + MapObjectRandomBelow(0x50000);
}

s16 Kanoke64FX_CosIdx(s32 angle) {
    return FX_CosIdx(angle);
}

void UpdateKanoke64(void *mapObjectList, Kanoke64 *kanoke64) {
    s32 burstIndex;
    s32 horizontalSpeed;
    u16 angle;
    s32 nextFrameIndex;
    Vec3 basabasaPos;
    Vec3 basabasaVelocity;

    switch (kanoke64->mState) {
        case 0:
            if (GetCurrentCameraKind() == 2) {
                kanoke64->mState = 1;
                return;
            }
            if (kanoke64->mMapObject.mFlags & 0x800) {
                if (kanoke64->mTimer-- <= 0) {
                    kanoke64->mTimer = 8;
                    kanoke64->mState = 1;
                }
                return;
            }
            if (Kanoke64IsKartNearInAngle(kanoke64, kanoke64->mMapObject.mAngle) != FALSE) {
                kanoke64->mTimer = 8;
                kanoke64->mState = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (kanoke64->mNsbcaFrameIndex == 10) {
        for (burstIndex = 0; burstIndex < 3; burstIndex++) {
            Kanoke64SetRandomPos(&basabasaPos, kanoke64->mMapObject.mPos.x, kanoke64->mMapObject.mPos.y + 0x19000,
                                 kanoke64->mMapObject.mPos.z);
            angle = kanoke64->mMapObject.mAngle;
            horizontalSpeed = NextRandomBelow(GetMapObjectRandom(), 0x1000) + 0x800;
            angle = angle - 0x3e8 + NextRandomBelowU16(GetMapObjectRandom(), 0x7d0);
            basabasaVelocity.x = Kanoke64MulFixed12NoRound(horizontalSpeed, Kanoke64FX_SinIdx(angle));
            basabasaVelocity.y = NextRandomBelow(GetMapObjectRandom(), 0x400) + 0x2200;
            basabasaVelocity.z = Kanoke64MulFixed12NoRound(horizontalSpeed, Kanoke64FX_CosIdx(angle));
            if (burstIndex == 0 && kanoke64->mBurstCount == 0) {
                StartBasabasa(0x50, &basabasaPos, &basabasaVelocity, 0x28, 1, burstIndex == 0 ? 3 : 0);
            } else {
                StartBasabasa(0x50, &basabasaPos, &basabasaVelocity, 0x28, 0, burstIndex == 0 ? 3 : 0);
            }
        }
        kanoke64->mBurstCount += 1;
        if (kanoke64->mBurstCount >= 3) {
            kanoke64->mBurstCount = 0;
        }
    }
    nextFrameIndex = kanoke64->mNsbcaFrameIndex + 1;
    if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gKanoke64)) {
        nextFrameIndex = 0;
    }
    kanoke64->mNsbcaFrameIndex = nextFrameIndex;
    if (kanoke64->mNsbcaFrameIndex == 0) {
        if (kanoke64->mTimer-- <= 0) {
            kanoke64->mBurstCount = 0;
            kanoke64->mState = 0;
            if (kanoke64->mMapObject.mFlags & 0x800) {
                kanoke64->mTimer = (u16) (MapObjectRandomBelowU16(25) + 200);
            }
        }
    }
    if (kanoke64->mNsbcaFrameIndex != 0) {
        return;
    }
    StartKanoke64Sound(kanoke64, 0x188);
}

MapObjectList *CreateKanoke64DrawList(void) {
    return CreateMapObjectDrawList1(CreateKanoke64, DrawKanoke64, NULL);
}

MapObjectList *CreateKanoke64UpdateList(void) {
    return CreateMapObjectUpdateList(InitKanoke64Objects, UpdateKanoke64, NULL);
}
