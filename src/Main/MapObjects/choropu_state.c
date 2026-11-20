#include "Main/MapObjects/choropu_state.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/view_frustum.h"

#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "fixed_vector_math.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Item/mission_run_koura_effects.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/entry_race_ended.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/bridge.h"

const MapObjectList gChoropuUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateChoropu, NULL, 0, NULL, 0, NULL};
const MapObjectDrawList gChoropuShadowDrawListData = {{NULL,
                                                       0,
                                                       {0, 0},
                                                       NULL,
                                                       (void (*)(MapObjectList *)) SetupDrawChoropuShadow,
                                                       (MapObjectForEachCallback) DrawChoropuShadow,
                                                       NULL,
                                                       1,
                                                       NULL,
                                                       1,
                                                       NULL},
                                                      0};
const MapObjectDrawList gChoropuDrawListData = {{NULL,
                                                 0,
                                                 {0, 0},
                                                 (void (*)(MapObjectList *)) CreateChoropu,
                                                 (void (*)(MapObjectList *)) SetupDrawChoropu,
                                                 (MapObjectForEachCallback) DrawChoropu,
                                                 NULL,
                                                 2,
                                                 NULL,
                                                 0,
                                                 NULL},
                                                0};
const MapObjectKindData gChoropuKindData = {(s32 (*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithChoropu,
                                         (s32 (*)(MapObject *, void *, void *, void *)) CollideItemObjectWithChoropu,
                                         1,
                                         0x9000,
                                         0,
                                         0,
                                         NULL,
                                         1,
                                         0,
                                         0x129,
                                         0x12a,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0};
StateCallbacks gChoropuStateTable[8] = {{EnterChoropuWaitStart, UpdateChoropuWaitStart},
                                        {EnterChoropuRise, UpdateChoropuRise},
                                        {EnterChoropuHoldTop, UpdateChoropuHoldTop},
                                        {EnterChoropuSink, UpdateChoropuSink},
                                        {EnterChoropuLeap, UpdateChoropuLeap},
                                        {EnterChoropuWaitRepeat, UpdateChoropuWaitRepeat},
                                        {EnterChoropuLaunchedSpin, UpdateChoropuLaunchedSpin},
                                        {ChoropuFallSpinNop, UpdateChoropuFallSpin}};

void SetupDrawChoropuShadow(void) {
    u32 unused;
    SendObjShadowMaterial();
}

void DrawChoropuShadow(void *unused0, Choropu *choropu, u32 unused1, u32 alpha) {
    DrawObjShadowAfterMaterial(&choropu->mShadowMatrix, NULL, 0, alpha);
}

void UpdateChoropu(u32 unused, Choropu *choropu) {
    AdvanceStateMachine(&choropu->mMapObject.mStateMachine);
}

void EnterChoropuWaitStart(void *stateObject) {
    Choropu *choropu = stateObject;
    choropu->mMapObject.mPos.y = choropu->mBottomY;
    choropu->mMapObject.mPosStep.y = 0;
    choropu->mMapObject.mFlags |= gChoropuSecondFlag;
    choropu->mMapObject.mFlags |= gChoropuFlag;
}

void UpdateChoropuWaitStart(void *stateObject) {
    Choropu *choropu = stateObject;
    if (choropu->mMapObject.mStateMachine.mStateFrames >= choropu->mStartDelayFrameCount) {
        choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_RISE;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuRise(void *stateObject) {
    Choropu *choropu = stateObject;
    choropu->mMapObject.mPos.y = choropu->mBottomY;
    choropu->mMapObject.mPosStep.y = 0x1000;
    choropu->mSpinAngle = 0;
    choropu->mMapObject.mFlags |= gChoropuSecondFlag;
    choropu->mMapObject.mFlags |= gChoropuFlag;
}

void UpdateChoropuRise(void *stateObject) {
    Choropu *choropu = stateObject;
    choropu->mMapObject.mPos.y = choropu->mMapObject.mPos.y + choropu->mMapObject.mPosStep.y;
    if (choropu->mMapObject.mPos.y > choropu->mBottomY + 0x11199) {
        choropu->mMapObject.mPos.y = choropu->mBottomY + 0x11199;
        choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_HOLD_TOP;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuHoldTop(void *stateObject) {
    Choropu *choropu = stateObject;
    choropu->mMapObject.mPosStep.y = 0;
}

void UpdateChoropuHoldTop(void *stateObject) {
    Choropu *choropu = stateObject;
    if (choropu->mMapObject.mStateMachine.mStateFrames >= CHOROPU_HOLD_TOP_FRAMES) {
        choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_SINK;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuSink(void *stateObject) {
    Choropu *choropu = stateObject;
    choropu->mMapObject.mPosStep.y = -0x1000;
}

void UpdateChoropuSink(void *stateObject) {
    Choropu *choropu = stateObject;
    SoundStartParams soundRequest;
    s32 falloffIndex;

    choropu->mMapObject.mPos.y = choropu->mMapObject.mPos.y + choropu->mMapObject.mPosStep.y;
    if (choropu->mMapObject.mPos.y >= choropu->mBottomY) {
        return;
    }
    if ((choropu->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
        falloffIndex =
            choropu->mMapObject.mFarDistanceSquared == gSoundFalloffs[SOUND_FALLOFF_SHORT_RANGE].mFarDistanceSquared
                ? SOUND_FALLOFF_SHORT_RANGE
                : (choropu->mMapObject.mFarDistanceSquared ==
                           gSoundFalloffs[SOUND_FALLOFF_MEDIUM_RANGE].mFarDistanceSquared
                       ? SOUND_FALLOFF_MEDIUM_RANGE
                       : SOUND_FALLOFF_LONG_RANGE);
        soundRequest.mSoundId = CHOROPU_SINK_SOUND_ID;
        soundRequest.mPositionSource = &choropu->mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&choropu->mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
    }
    choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_LEAP;
    choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
}

void EnterChoropuLeap(void *stateObject) {
    Choropu *choropu = stateObject;
    choropu->mMapObject.mPos.y = choropu->mBottomY;
    choropu->mMapObject.mPosStep.y = 0x4800;
    choropu->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_DISABLED;
    if ((choropu->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_OUT_OF_SIGHT) != 0) {
        if (GetEntryRaceEnded() == 0) {
            return;
        }
    }
    StartEffect(0x30, &choropu->mMapObject.mCourseMapRow->mPosition);
}

void UpdateChoropuLeap(void *stateObject) {
    Choropu *choropu = stateObject;
    choropu->mMapObject.mPosStep.y -= 0x266;
    choropu->mMapObject.mPos.y = choropu->mMapObject.mPos.y + choropu->mMapObject.mPosStep.y;
    if (choropu->mMapObject.mPos.y < choropu->mLowestY) {
        choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_WAIT_REPEAT;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

// Same body as EnterChoropuWaitStart; this is the enter slot of the repeat wait.
void EnterChoropuWaitRepeat(void *stateObject) {
    Choropu *choropu = stateObject;
    choropu->mMapObject.mPos.y = choropu->mBottomY;
    choropu->mMapObject.mPosStep.y = 0;
    choropu->mMapObject.mFlags |= gChoropuSecondFlag;
    choropu->mMapObject.mFlags |= gChoropuFlag;
}

void UpdateChoropuWaitRepeat(void *stateObject) {
    Choropu *choropu = stateObject;
    if (choropu->mMapObject.mStateMachine.mStateFrames >= choropu->mRepeatDelayFrameCount) {
        choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_RISE;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuLaunchedSpin(void *stateObject) {
    Choropu *choropu = stateObject;
    choropu->mMapObject.mFlags = (((choropu->mMapObject.mFlags)) | ((gChoropuFlag)));
}

void UpdateChoropuLaunchedSpin(void *stateObject) {
    Choropu *choropu = stateObject;
    if (choropu->mSpinDirection != 0) {
        choropu->mSpinAngle += 0x400;
    } else {
        choropu->mSpinAngle -= 0x400;
    }
    choropu->mMapObject.mPosStep.y -= 0x400;
    choropu->mMapObject.mPos.y = choropu->mMapObject.mPos.y + choropu->mMapObject.mPosStep.y;
    if (choropu->mMapObject.mPos.y < choropu->mLowestY) {
        choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_WAIT_REPEAT;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void ChoropuFallSpinNop(void *stateObject) {}

void UpdateChoropuFallSpin(void *stateObject) {
    Choropu *choropu = stateObject;
    choropu->mMapObject.mPosStep.y -= 0x266;
    choropu->mMapObject.mPos.y = choropu->mMapObject.mPos.y + choropu->mMapObject.mPosStep.y;
    if (choropu->mMapObject.mPos.y < choropu->mLowestY) {
        StateMachine *stateMachine = &choropu->mMapObject.mStateMachine;

        stateMachine->mNextState = CHOROPU_STATE_WAIT_REPEAT;
        stateMachine->mNextStateRequested = 1;
    }
    if (choropu->mSpinDirection != 0) {
        choropu->mSpinAngle += 0x400;
    } else {
        choropu->mSpinAngle -= 0x400;
    }
}

// Case 1 starts the launched spin with an upward speed; case 2 starts the fall spin unless the kart is a ghost or the
// Choropu is already in it.
u8 CollideKartWithChoropu(Choropu *choropu, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    Vec3 offsetFromKart;

    switch (firstResponsePtr[0]) {
        case CHOROPU_KART_RESPONSE_FALL_SPIN:
            if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
                return secondResponsePtr[0];
            }
            if (choropu->mMapObject.mStateMachine.mState == CHOROPU_STATE_FALL_SPIN) {
                return secondResponsePtr[0];
            }
            choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_FALL_SPIN;
            choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
            StartSoundIfKartStarOrKiller(&choropu->mMapObject, kart);
            break;
        case 1:
            VEC_Subtract(&choropu->mMapObject.mPos, &kart->mPos, &offsetFromKart);
            if ((s64) offsetFromKart.z * kart->mVelocity.x - (s64) offsetFromKart.x * kart->mVelocity.z < 0) {
                choropu->mSpinDirection = 1;
            } else {
                choropu->mSpinDirection = 0;
            }
            choropu->mMapObject.mPosStep.y = 0x4000;
            choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_LAUNCHED_SPIN;
            choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
            choropu->mMapObject.mFlags |= gChoropuFlag;
            StartSoundIfKartStarOrKiller(&choropu->mMapObject, kart);
            break;
    }
    return secondResponsePtr[0];
}

// Case 1 starts the launched spin with an upward speed, as CollideKartWithChoropu does for a kart.
u8 CollideItemObjectWithChoropu(Choropu *choropu, ItemObject *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    Vec3 offsetFromItem;
    Vec3 offset;

    if (firstResponsePtr[0] == 1) {
        if (itemObject != NULL) {
            VEC_Subtract(&choropu->mMapObject.mPos, &itemObject->mPos, &offsetFromItem);
            if ((s64) offsetFromItem.z * itemObject->mVelocity.x - (s64) offsetFromItem.x * itemObject->mVelocity.z <
                0) {
                choropu->mSpinDirection = 1;
            } else {
                choropu->mSpinDirection = 0;
            }
            choropu->mMapObject.mPosStep.y = 0x4000;
            choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_LAUNCHED_SPIN;
            choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
            choropu->mMapObject.mFlags |= gChoropuFlag;
            StartMissionRunKouraEffects(itemObject);
        } else {
            VEC_Subtract(&choropu->mMapObject.mPos, &choropu->mMapObject.mPos, &offset);
            if ((s64) offset.z * gChoropuZeroVector.x - (s64) offset.x * gChoropuZeroVector.z < 0) {
                choropu->mSpinDirection = 1;
            } else {
                choropu->mSpinDirection = 0;
            }
            choropu->mMapObject.mPosStep.y = 0x4000;
            choropu->mMapObject.mStateMachine.mNextState = CHOROPU_STATE_LAUNCHED_SPIN;
            choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
            choropu->mMapObject.mFlags |= gChoropuFlag;
        }
    }
    return secondResponsePtr[0];
}

#pragma thumb on

void CreateChoropu(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = FindCourseMapObjFile("choropu.nsbmd");
    nsbtpFile = FindCourseMapObjFile("choropu.nsbtp");
    CreateNsbmdModel(&gChoropu, nsbmdFile, nsbtpFile, 0);
    SetNsbmdModelFixedAttributes(gChoropu);
}

#pragma thumb off

const u16 gChoropuFlag = 1;
const u16 gChoropuSecondFlag = 8;
