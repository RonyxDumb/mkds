#include "Main/Kart/kart_resources.h"
#include "Main/System/heap.h"
#include "Main/Kart/kart_ai_battle.h"
#include "Main/Kart/kart_surface_effects.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/System/heap_call.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/first_base_speed_limit.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/collision_hit_link_create.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "fixed_vector_math.h"
#include "ITCM/kart_ground_contact.h"
#include "Main/Kart/kart_drift.h"
#include "Main/System/init_after_startup.h"

u32 gCoursePushStrongEnabled;
void *gLowestOffsetFarCheck;
void *gCollideKartWithMapObjectResponses[15];
void *gKartMapObjectSecondResponses[15];

void InitKartMapObjectResponses(void) {
    RaceSetup *raceSetup;
    u16 responseIndex;
    void **responseSlot;
    void **secondResponseSlot;

    gLowestOffsetFarCheck = IsLowestOffsetFarOnHitBit;
    raceSetup = g_GlobalCO;
    responseIndex = 0;
    responseSlot = gCollideKartWithMapObjectResponses;
    secondResponseSlot = gKartMapObjectSecondResponses;
    if (raceSetup->mCourseId == COURSE_ID_RAINBOW || raceSetup->mCourseId == COURSE_ID_OLD_SKY_AGB) {
        gLowestOffsetFarCheck = IsLowestOffsetFarOnHitBitOrYAbove;
    }
    gCoursePushStrongEnabled = 0;
    if (raceSetup->mMode == MODE_BATTLE) {
        switch (raceSetup->mCourseId) {
            case COURSE_ID_MINI_BLOCK_64:
            case COURSE_ID_MINI_DOKAN_GC:
                gCoursePushStrongEnabled = 1;
                gLowestOffsetFarCheck = IsLowestOffsetFarOnHitBitOrKartBit;
                break;
        }
    }
    for (; responseIndex < 15; responseIndex++, responseSlot++, secondResponseSlot++) {
        switch (responseIndex) {
            case 0:
                *responseSlot = CollideKartWithMapObjectResponse0;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            case 2:
                *responseSlot = CollideKartWithMapObjectResponse2;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            case 3:
                *responseSlot = CollideKartWithMapObjectResponse3;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            case 4:
                *responseSlot = CollideKartWithMapObjectResponse4;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            case 5:
                *responseSlot = CollideKartWithMapObjectResponse5;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            case 6:
                *responseSlot = CollideKartWithMapObjectResponse6;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            case 7:
                *responseSlot = CollideKartWithMapObjectResponse7;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            case 9:
                *responseSlot = CollideKartWithMapObjectResponse9;
                *secondResponseSlot = StartKartPushFlipOnHitByMapObject;
                break;
            case 8:
                *responseSlot = CollideKartWithMapObjectResponse8;
                *secondResponseSlot = StructMQRacerEntry_SomeFn_72;
                break;
            case 10:
                *responseSlot = CollideKartWithMapObjectResponse10;
                *secondResponseSlot = StartKartPushDoubleFlipOnHit;
                break;
            case 11:
                *responseSlot = CollideKartWithMapObjectResponse11;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            case 12:
                *responseSlot = CollideKartWithMapObjectResponse12;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            case 13:
                *responseSlot = CollideKartWithMapObjectResponse13;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            case 14:
                *responseSlot = CollideKartWithMapObjectResponse14;
                *secondResponseSlot = MapObjectResponseNop;
                break;
            default:
                *responseSlot = CollideKartWithMapObjectNoResponse;
                *secondResponseSlot = MapObjectResponseNop;
                break;
        }
    }
    gFirstBaseSpeedLimitReciprocal = FX_Div(0x1000, MUL_FIXED12_NO_ROUND(GetFATGigi(), 0xd9aLL));
}

void StructMQRacerEntry_Fn0(Kart *kart) {
    void *heap;
    Vec3 *collisionPos;
    u16 entryIndex;

    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    kart->mAdvanceOffsetCycle = AdvanceKartOffsetCycle;
    StructMQRacerEntry_SomeFn_43(kart);
    StructMQRacerEntry_SomeFn_44(kart);
    if (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) {
        SetKartSpeedLimitReciprocal(FX_Div(0x1000, kart->mPhysicalParam->mBaseSpeedLimit));
    }
    StructMQRacerEntry_SomeFn_49(kart);
    CreateCollisionHitLink(&kart->mCollisionHitLink);
    kart->mAi = Mem_AllocateHeap(heap, sizeof(*kart->mAi));
    if (g_GlobalPE->mRaceRouteCount != 0 || g_GlobalPE->mBattleRouteCount != 0) {
        if (g_GlobalCO->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_CPU) {
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
    if (g_GlobalCO->mMode == MODE_WIFI) {
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
    kart->mCollisionStepFrames = KART_COLLISION_STEP_FRAMES_FULL;
    kart->mRadius = kart->mPhysicalParam->mRadius;
    StructMQRacerEntry_SomeFn_24(kart);
    if (g_GlobalCO->mMode == MODE_WIFI) {
        kart->mParticipantRecordData = Mem_AllocateHeap(heap, sizeof(*kart->mParticipantRecordData));
        StructMQRacerEntry_InitializeSub(kart, heap);
    }
    if (IsAwardOrStaffRoll_0() != 0) {
        kart->mMotionFlags |= KART_MOTION_START_DONE;
    }
}
