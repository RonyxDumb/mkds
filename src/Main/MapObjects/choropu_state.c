#include "Main/MapObjects/choropu_state.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/view_frustum.h"

#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "code_02147cd8.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Item/mission_run_koura_effects.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/entry_race_ended.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Item/item_koura_w.h"

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

void EnterChoropuState0(Choropu *choropu) {
    choropu->mMapObject.mPos.y = choropu->mBottomY;
    choropu->mMapObject.mPosStep.y = 0;
    choropu->mMapObject.mFlags |= data_02158bb8;
    choropu->mMapObject.mFlags |= data_02158bb4;
}

void UpdateChoropuState0(Choropu *choropu) {
    if (choropu->mMapObject.mStateMachine.mStateFrames >= choropu->mStartDelayFrameCount) {
        choropu->mMapObject.mStateMachine.mNextState = 1;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState1(Choropu *choropu) {
    choropu->mMapObject.mPos.y = choropu->mBottomY;
    choropu->mMapObject.mPosStep.y = 0x1000;
    choropu->mSpinAngle = 0;
    choropu->mMapObject.mFlags |= data_02158bb8;
    choropu->mMapObject.mFlags |= data_02158bb4;
}

void UpdateChoropuState1(Choropu *choropu) {
    choropu->mMapObject.mPos.y = choropu->mMapObject.mPos.y + choropu->mMapObject.mPosStep.y;
    if (choropu->mMapObject.mPos.y > choropu->mBottomY + 0x11199) {
        choropu->mMapObject.mPos.y = choropu->mBottomY + 0x11199;
        choropu->mMapObject.mStateMachine.mNextState = 2;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState2(Choropu *choropu) {
    choropu->mMapObject.mPosStep.y = 0;
}

void UpdateChoropuState2(Choropu *choropu) {
    if (choropu->mMapObject.mStateMachine.mStateFrames >= 0x14) {
        choropu->mMapObject.mStateMachine.mNextState = 3;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState3(Choropu *choropu) {
    choropu->mMapObject.mPosStep.y = -0x1000;
}

void UpdateChoropuState3(Choropu *choropu) {
    SoundStartParams soundRequest;
    s32 falloffIndex;

    choropu->mMapObject.mPos.y = choropu->mMapObject.mPos.y + choropu->mMapObject.mPosStep.y;
    if (choropu->mMapObject.mPos.y >= choropu->mBottomY) {
        return;
    }
    if ((choropu->mMapObject.mDistanceSquaredAndFlags & 0x4) == 0) {
        falloffIndex = choropu->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared
                           ? 2
                           : (choropu->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared ? 3 : 4);
        soundRequest.mSoundId = 0x128;
        soundRequest.mPositionSource = &choropu->mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&choropu->mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
    }
    choropu->mMapObject.mStateMachine.mNextState = 4;
    choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
}

void EnterChoropuState4(Choropu *choropu) {
    choropu->mMapObject.mPos.y = choropu->mBottomY;
    choropu->mMapObject.mPosStep.y = 0x4800;
    choropu->mMapObject.mFlags &= ~0x1;
    if ((choropu->mMapObject.mDistanceSquaredAndFlags & 0x3) != 0) {
        if (GetEntryRaceEnded() == 0) {
            return;
        }
    }
    StartEffect(0x30, &choropu->mMapObject.mCourseMapRow->mPosition);
}

void UpdateChoropuState4(Choropu *choropu) {
    choropu->mMapObject.mPosStep.y -= 0x266;
    choropu->mMapObject.mPos.y = choropu->mMapObject.mPos.y + choropu->mMapObject.mPosStep.y;
    if (choropu->mMapObject.mPos.y < choropu->mLowestY) {
        choropu->mMapObject.mStateMachine.mNextState = 5;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

// Same body as EnterChoropuState0; this is the enter slot of state 5.
void EnterChoropuState5(Choropu *choropu) {
    choropu->mMapObject.mPos.y = choropu->mBottomY;
    choropu->mMapObject.mPosStep.y = 0;
    choropu->mMapObject.mFlags |= data_02158bb8;
    choropu->mMapObject.mFlags |= data_02158bb4;
}

void UpdateChoropuState5(Choropu *choropu) {
    if (choropu->mMapObject.mStateMachine.mStateFrames >= choropu->mRepeatDelayFrameCount) {
        choropu->mMapObject.mStateMachine.mNextState = 1;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState6(Choropu *choropu) {
    choropu->mMapObject.mFlags = (((choropu->mMapObject.mFlags)) | ((data_02158bb4)));
}

void UpdateChoropuState6(Choropu *choropu) {
    if (choropu->mSpinDirection != 0) {
        choropu->mSpinAngle += 0x400;
    } else {
        choropu->mSpinAngle -= 0x400;
    }
    choropu->mMapObject.mPosStep.y -= 0x400;
    choropu->mMapObject.mPos.y = choropu->mMapObject.mPos.y + choropu->mMapObject.mPosStep.y;
    if (choropu->mMapObject.mPos.y < choropu->mLowestY) {
        choropu->mMapObject.mStateMachine.mNextState = 5;
        choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 ChoropuState7ReturnArgument(u32 value) {
    return value;
}

void UpdateChoropuState7(Choropu *choropu) {
    choropu->mMapObject.mPosStep.y -= 0x266;
    choropu->mMapObject.mPos.y = choropu->mMapObject.mPos.y + choropu->mMapObject.mPosStep.y;
    if (choropu->mMapObject.mPos.y < choropu->mLowestY) {
        StateMachine *stateMachine = &choropu->mMapObject.mStateMachine;

        stateMachine->mNextState = 5;
        stateMachine->mNextStateRequested = 1;
    }
    if (choropu->mSpinDirection != 0) {
        choropu->mSpinAngle += 0x400;
    } else {
        choropu->mSpinAngle -= 0x400;
    }
}

// Case 1 starts state 6 with an upward speed; case 2 starts state 7 unless player kind 2 or already there.
u8 CollideKartWithChoropu(Choropu *choropu, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    Vec3 offsetFromKart;

    switch (firstResponsePtr[0]) {
        case 2:
            if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
                return secondResponsePtr[0];
            }
            if (choropu->mMapObject.mStateMachine.mState == 7) {
                return secondResponsePtr[0];
            }
            choropu->mMapObject.mStateMachine.mNextState = 7;
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
            choropu->mMapObject.mStateMachine.mNextState = 6;
            choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
            choropu->mMapObject.mFlags |= data_02158bb4;
            StartSoundIfKartStarOrKiller(&choropu->mMapObject, kart);
            break;
    }
    return secondResponsePtr[0];
}

// Case 1 starts state 6 with an upward speed, as CollideKartWithChoropu does for a kart.
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
            choropu->mMapObject.mStateMachine.mNextState = 6;
            choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
            choropu->mMapObject.mFlags |= data_02158bb4;
            StartMissionRunKouraEffects(itemObject);
        } else {
            VEC_Subtract(&choropu->mMapObject.mPos, &choropu->mMapObject.mPos, &offset);
            if ((s64) offset.z * data_02158c7c.x - (s64) offset.x * data_02158c7c.z < 0) {
                choropu->mSpinDirection = 1;
            } else {
                choropu->mSpinDirection = 0;
            }
            choropu->mMapObject.mPosStep.y = 0x4000;
            choropu->mMapObject.mStateMachine.mNextState = 6;
            choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
            choropu->mMapObject.mFlags |= data_02158bb4;
        }
    }
    return secondResponsePtr[0];
}

#pragma thumb on

void CreateChoropu(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = FindCourseMapObjFile(gChoropuNsbmdName);
    nsbtpFile = FindCourseMapObjFile(gChoropuNsbtpName);
    CreateNsbmdModel(&gChoropu, nsbmdFile, nsbtpFile, 0);
    SetNsbmdModelFixedAttributes(gChoropu);
}

#pragma thumb off
