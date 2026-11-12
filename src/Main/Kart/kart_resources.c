#include "Main/Kart/kart_resources.h"
#include "Main/System/heap.h"
#include "Main/Kart/code_02066ac0.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/data_02067000.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/first_base_speed_limit.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/collision_hit_link_create.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "code_02147cd8.h"
#include "ITCM/kart_ground_contact.h"

void InitKartMapObjectResponses(void) {
    RaceSetup *raceSetup;
    u16 responseIndex;
    void **responseSlot;
    void **secondResponseSlot;

    data_0217ac14 = IsLowestOffsetFarOnHitBit;
    raceSetup = gRaceSetup;
    responseIndex = 0;
    responseSlot = gCollideKartWithMapObjectResponses;
    secondResponseSlot = gKartMapObjectSecondResponses;
    if (raceSetup->mCourseId == COURSE_ID_RAINBOW || raceSetup->mCourseId == COURSE_ID_OLD_SKY_AGB) {
        data_0217ac14 = IsLowestOffsetFarOnHitBitOrYAbove;
    }
    data_0217ac10 = 0;
    if (raceSetup->mMode == MODE_BATTLE) {
        switch (raceSetup->mCourseId) {
            case COURSE_ID_MINI_BLOCK_64:
            case COURSE_ID_MINI_DOKAN_GC:
                data_0217ac10 = 1;
                data_0217ac14 = IsLowestOffsetFarOnHitBitOrKartBit;
                break;
        }
    }
    for (; responseIndex < 15; responseIndex++, responseSlot++, secondResponseSlot++) {
        switch (responseIndex) {
            case 0:
                *responseSlot = CollideKartWithMapObjectResponse0;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 2:
                *responseSlot = CollideKartWithMapObjectResponse2;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 3:
                *responseSlot = CollideKartWithMapObjectResponse3;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 4:
                *responseSlot = CollideKartWithMapObjectResponse4;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 5:
                *responseSlot = CollideKartWithMapObjectResponse5;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 6:
                *responseSlot = CollideKartWithMapObjectResponse6;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 7:
                *responseSlot = CollideKartWithMapObjectResponse7;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 9:
                *responseSlot = CollideKartWithMapObjectResponse9;
                *secondResponseSlot = StartKartPushFlipOnHitByMapObject;
                break;
            case 8:
                *responseSlot = CollideKartWithMapObjectResponse8;
                *secondResponseSlot = StartKartPushFlipOnHit;
                break;
            case 10:
                *responseSlot = CollideKartWithMapObjectResponse10;
                *secondResponseSlot = StartKartPushDoubleFlipOnHit;
                break;
            case 11:
                *responseSlot = CollideKartWithMapObjectResponse11;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 12:
                *responseSlot = CollideKartWithMapObjectResponse12;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 13:
                *responseSlot = CollideKartWithMapObjectResponse13;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 14:
                *responseSlot = CollideKartWithMapObjectResponse14;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            default:
                *responseSlot = CollideKartWithMapObjectNoResponse;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
        }
    }
    data_usa_021654ec = FX_Div(0x1000, MUL_FIXED12_NO_ROUND(GetFirstBaseSpeedLimit(), 0xd9aLL));
}

void InitKartResources(Kart *kart) {
    void *heap;
    Vec3 *collisionPos;
    u16 entryIndex;

    heap = GetHeap(GetCurrentHeapCall());
    kart->mAdvanceOffsetCycle = AdvanceKartOffsetCycle;
    InitKartPhysicalParams(kart);
    InitKartFlags(kart);
    if (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) {
        SetKartSpeedLimitReciprocal(FX_Div(0x1000, kart->mPhysicalParam->mBaseSpeedLimit));
    }
    InitKartSound(kart);
    CreateCollisionHitLink(&kart->mCollisionHitLink);
    kart->mAi = HeapAlloc(heap, 0x158);
    if (gCourseMap->mRaceRouteCount != 0 || gCourseMap->mBattleRouteCount != 0) {
        if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_CPU) {
            kart->mEntryFlags |= KART_ENTRY_CPU;
            if (kart->mEntryFlags & KART_ENTRY_CPU) {
                for (entryIndex = 0; entryIndex < 12; entryIndex++) {
                    if (entryIndex != 0) {
                        kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[entryIndex] =
                            kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[entryIndex] << 2;
                        if (kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[entryIndex] >
                            kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[0]) {
                            kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[entryIndex] =
                                kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[0];
                        }
                    }
                }
            }
        }
    }
    kart->mSecondCollisionSlot = -1;
    kart->mCollisionSlot = kart->mSecondCollisionSlot;
    if (gRaceSetup->mMode == MODE_WIFI) {
        collisionPos = &kart->mPointAlongUp;
    } else {
        collisionPos = &kart->mCollisionCenter;
    }
    if (kart->mCollisionSlot == -1) {
        kart->mCollisionSlot = CreateCollisionSlot(collisionPos, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
    }
    if (kart->mSecondCollisionSlot == -1) {
        kart->mSecondCollisionSlot = CreateCollisionSlot(
            &kart->mSecondCollisionCenter, ((s64) kart->mPhysicalParam->mRadius << 15) >> 12, 0x800, kart);
    }
    kart->mMotionFlags |= KART_MOTION_ON_GROUND;
    kart->mCollisionStepFrames = 0x64;
    kart->mRadius = kart->mPhysicalParam->mRadius;
    InitKartSoundParams(kart);
    if (gRaceSetup->mMode == MODE_WIFI) {
        kart->mParticipantRecordData = HeapAlloc(heap, 0xb8);
        InitParticipantKartRecordState(kart, heap);
    }
    if (IsRaceAwardOrStaffRoll() != 0) {
        kart->mMotionFlags |= KART_MOTION_START_DONE;
    }
}
