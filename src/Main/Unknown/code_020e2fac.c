#include "Main/Unknown/code_020e2fac.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d4c28.h"

#include "Main/Unknown/code_020e2fe4.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020f8000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/code_020f36d8.h" // ItemObject
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020e32a0.h"
#include "Main/Unknown/code_020e32a4.h"
#include "Main/Unknown/code_020e3300.h"
#include "Main/Unknown/code_020e331c.h"
#include "Main/Unknown/code_020e3338.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020e34c0.h"
#include "Main/Unknown/code_020e34d0.h"
#include "Main/Unknown/code_020e34ec.h"
#include "Main/Unknown/code_020e34f8.h"
#include "Main/Unknown/code_020e3538.h"
#include "Main/Unknown/code_020e3584.h"
#include "Main/Unknown/code_020e35a0.h"
#include "Main/Unknown/code_020e35e4.h"
#include "Main/Unknown/code_020e35f4.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020e360c.h"

void SetupDrawChoropuShadow(void) {
    u32 unused;
    SendObjShadowMaterial();
}

void DrawChoropuShadow(void *unused0, Choropu *choropu, u32 unused1, u32 alpha) {
    DrawObjShadowAfterMaterial(&choropu->mShadowMatrix, NULL, 0, alpha);
}

void UpdateChoropu(u32 unused, Choropu *choropu) {
    AdvanceStateMachine(&choropu->mUnk_000.mStateMachine);
}

void EnterChoropuState0(Choropu *choropu) {
    choropu->mUnk_000.mPos.y = choropu->mBottomY;
    choropu->mUnk_000.mUnk_10.y = 0;
    choropu->mUnk_000.mFlags |= data_02158bb8;
    choropu->mUnk_000.mFlags |= data_02158bb4;
}

void UpdateChoropuState0(Choropu *choropu) {
    if (choropu->mUnk_000.mStateMachine.mStateFrames >= choropu->mStartDelayFrameCount) {
        choropu->mUnk_000.mStateMachine.mNextState = 1;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState1(Choropu *choropu) {
    choropu->mUnk_000.mPos.y = choropu->mBottomY;
    choropu->mUnk_000.mUnk_10.y = 0x1000;
    choropu->mSpinAngle = 0;
    choropu->mUnk_000.mFlags |= data_02158bb8;
    choropu->mUnk_000.mFlags |= data_02158bb4;
}

void UpdateChoropuState1(Choropu *choropu) {
    choropu->mUnk_000.mPos.y = choropu->mUnk_000.mPos.y + choropu->mUnk_000.mUnk_10.y;
    if (choropu->mUnk_000.mPos.y > choropu->mBottomY + 0x11199) {
        choropu->mUnk_000.mPos.y = choropu->mBottomY + 0x11199;
        choropu->mUnk_000.mStateMachine.mNextState = 2;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState2(Choropu *choropu) {
    choropu->mUnk_000.mUnk_10.y = 0;
}

void UpdateChoropuState2(Choropu *choropu) {
    if (choropu->mUnk_000.mStateMachine.mStateFrames >= 0x14) {
        choropu->mUnk_000.mStateMachine.mNextState = 3;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState3(Choropu *choropu) {
    choropu->mUnk_000.mUnk_10.y = -0x1000;
}

void UpdateChoropuState3(Choropu *choropu) {
    SoundStartParams soundRequest;
    s32 falloffIndex;

    choropu->mUnk_000.mPos.y = choropu->mUnk_000.mPos.y + choropu->mUnk_000.mUnk_10.y;
    if (choropu->mUnk_000.mPos.y >= choropu->mBottomY) {
        return;
    }
    if ((choropu->mUnk_000.mDistanceSquaredAndFlags & 0x4) == 0) {
        falloffIndex = choropu->mUnk_000.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20
                           ? 2
                           : (choropu->mUnk_000.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20 ? 3 : 4);
        soundRequest.mSoundId = 0x128;
        soundRequest.mPositionSource = &choropu->mUnk_000.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&choropu->mUnk_000.mPos);
        StartSoundFromParams(&soundRequest);
    }
    choropu->mUnk_000.mStateMachine.mNextState = 4;
    choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
}

void EnterChoropuState4(Choropu *choropu) {
    choropu->mUnk_000.mPos.y = choropu->mBottomY;
    choropu->mUnk_000.mUnk_10.y = 0x4800;
    choropu->mUnk_000.mFlags &= ~0x1;
    if ((choropu->mUnk_000.mDistanceSquaredAndFlags & 0x3) != 0) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    StartEffect(0x30, &choropu->mUnk_000.mCourseMapRow->mUnk_00);
}

void UpdateChoropuState4(Choropu *choropu) {
    choropu->mUnk_000.mUnk_10.y -= 0x266;
    choropu->mUnk_000.mPos.y = choropu->mUnk_000.mPos.y + choropu->mUnk_000.mUnk_10.y;
    if (choropu->mUnk_000.mPos.y < choropu->mLowestY) {
        choropu->mUnk_000.mStateMachine.mNextState = 5;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

// Same body as EnterChoropuState0; this is the enter slot of state 5.
void EnterChoropuState5(Choropu *choropu) {
    choropu->mUnk_000.mPos.y = choropu->mBottomY;
    choropu->mUnk_000.mUnk_10.y = 0;
    choropu->mUnk_000.mFlags |= data_02158bb8;
    choropu->mUnk_000.mFlags |= data_02158bb4;
}

void UpdateChoropuState5(Choropu *choropu) {
    if (choropu->mUnk_000.mStateMachine.mStateFrames >= choropu->mRepeatDelayFrameCount) {
        choropu->mUnk_000.mStateMachine.mNextState = 1;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState6(Choropu *choropu) {
    choropu->mUnk_000.mFlags = (((choropu->mUnk_000.mFlags)) | ((data_02158bb4)));
}

void UpdateChoropuState6(Choropu *choropu) {
    if (choropu->mSpinDirection != 0) {
        choropu->mSpinAngle += 0x400;
    } else {
        choropu->mSpinAngle -= 0x400;
    }
    choropu->mUnk_000.mUnk_10.y -= 0x400;
    choropu->mUnk_000.mPos.y = choropu->mUnk_000.mPos.y + choropu->mUnk_000.mUnk_10.y;
    if (choropu->mUnk_000.mPos.y < choropu->mLowestY) {
        choropu->mUnk_000.mStateMachine.mNextState = 5;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

u32 ChoropuState7ReturnArgument(u32 value) {
    return value;
}

void UpdateChoropuState7(Choropu *choropu) {
    choropu->mUnk_000.mUnk_10.y -= 0x266;
    choropu->mUnk_000.mPos.y = choropu->mUnk_000.mPos.y + choropu->mUnk_000.mUnk_10.y;
    if (choropu->mUnk_000.mPos.y < choropu->mLowestY) {
        StateMachine *stateMachine = &choropu->mUnk_000.mStateMachine;

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
            if (choropu->mUnk_000.mStateMachine.mState == 7) {
                return secondResponsePtr[0];
            }
            choropu->mUnk_000.mStateMachine.mNextState = 7;
            choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
            StartSoundIfKartStarOrKiller(&choropu->mUnk_000, kart);
            break;
        case 1:
            VEC_Subtract(&choropu->mUnk_000.mPos, &kart->mPos, &offsetFromKart);
            if ((s64) offsetFromKart.z * kart->mVelocity.x - (s64) offsetFromKart.x * kart->mVelocity.z < 0) {
                choropu->mSpinDirection = 1;
            } else {
                choropu->mSpinDirection = 0;
            }
            choropu->mUnk_000.mUnk_10.y = 0x4000;
            choropu->mUnk_000.mStateMachine.mNextState = 6;
            choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
            choropu->mUnk_000.mFlags |= data_02158bb4;
            StartSoundIfKartStarOrKiller(&choropu->mUnk_000, kart);
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
            VEC_Subtract(&choropu->mUnk_000.mPos, &itemObject->mPos, &offsetFromItem);
            if ((s64) offsetFromItem.z * itemObject->mVelocity.x - (s64) offsetFromItem.x * itemObject->mVelocity.z <
                0) {
                choropu->mSpinDirection = 1;
            } else {
                choropu->mSpinDirection = 0;
            }
            choropu->mUnk_000.mUnk_10.y = 0x4000;
            choropu->mUnk_000.mStateMachine.mNextState = 6;
            choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
            choropu->mUnk_000.mFlags |= data_02158bb4;
            func_020f8ddc(itemObject);
        } else {
            VEC_Subtract(&choropu->mUnk_000.mPos, &choropu->mUnk_000.mPos, &offset);
            if ((s64) offset.z * data_02158c7c.x - (s64) offset.x * data_02158c7c.z < 0) {
                choropu->mSpinDirection = 1;
            } else {
                choropu->mSpinDirection = 0;
            }
            choropu->mUnk_000.mUnk_10.y = 0x4000;
            choropu->mUnk_000.mStateMachine.mNextState = 6;
            choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
            choropu->mUnk_000.mFlags |= data_02158bb4;
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
