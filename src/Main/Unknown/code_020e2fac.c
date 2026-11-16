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

void choro_applyShadowMaterial(void) {
    u32 value12;
    oshd_applyMaterial();
}

void choro_renderShadow(void *a, Unk020e1e98 *choropu, u32 c, u32 alpha) {
    oshd_render(&choropu->fieldB4.field8, NULL, 0, alpha);
}

void choro_update(u32 arg0, u32 object) {
    u32 value0;
    u32 value1 = object;
    u32 value12;
    value0 = (value1) + (0x80u);
    sm_execute((void *) value0);
}

void choro_state0Init(Unk020e35a0 *choropu) {
    choropu->field8 = choropu->fieldAC;
    choropu->field14 = 0x0u;
    choropu->field2 |= data_02158bb8;
    choropu->field2 |= data_02158bb4;
}

void choro_state0Update(Unk020e1e98 *choropu) {
    if (choropu->field0.mStateMachine.mStateFrames >= choropu->fieldA0) {
        choropu->field0.mStateMachine.mNextState = 1;
        choropu->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void choro_state1Init(Unk020e3538 *choropu) {
    choropu->field8 = choropu->fieldAC;
    choropu->field14 = 0x1000u;
    choropu->fieldB8 = 0x0u;
    choropu->field2 |= data_02158bb8;
    choropu->field2 |= data_02158bb4;
}

void choro_state1Update(Unk020e1e98 *choropu) {
    choropu->field0.mPos.y = choropu->field0.mPos.y + choropu->field0.field10.y;
    if (choropu->field0.mPos.y > choropu->fieldAC + 0x11199) {
        choropu->field0.mPos.y = choropu->fieldAC + 0x11199;
        choropu->field0.mStateMachine.mNextState = 2;
        choropu->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void choro_state2Init(Unk020e34ec *choropu) {
    choropu->field14 = 0x0u;
}

void choro_state2Update(Unk020e1e98 *choropu) {
    if (choropu->field0.mStateMachine.mStateFrames >= 0x14) {
        choropu->field0.mStateMachine.mNextState = 3;
        choropu->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void choro_state3Init(Unk020e34c0 *choropu) {
    choropu->field14 = ((0x0u) - (0x1000u));
}

void choro_state3Update(Unk020e1e98 *choropu) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;

    choropu->field0.mPos.y = choropu->field0.mPos.y + choropu->field0.field10.y;
    if (choropu->field0.mPos.y >= choropu->fieldAC) {
        return;
    }
    if ((choropu->field0.mDistanceSquaredAndFlags & 0x4) == 0) {
        falloffIndex = choropu->field0.mFarDistanceSquared == gSfxParams[2].field20
                           ? 2
                           : (choropu->field0.mFarDistanceSquared == gSfxParams[3].field20 ? 3 : 4);
        soundRequest.mSoundId = 0x128;
        soundRequest.mPositionSource = &choropu->field0.mPos;
        soundRequest.field8 = falloffIndex;
        soundRequest.mDistanceSquared = mobj_calcXZCamDist(&choropu->field0.mPos);
        func_0210b7a8(&soundRequest);
    }
    choropu->field0.mStateMachine.mNextState = 4;
    choropu->field0.mStateMachine.mNextStateRequested = 1;
}

void choro_state4Init(Unk020e1e98 *choropu) {
    choropu->field0.mPos.y = choropu->fieldAC;
    choropu->field0.field10.y = 0x4800;
    choropu->field0.mFlags &= ~0x1;
    if ((choropu->field0.mDistanceSquaredAndFlags & 0x3) != 0) {
        if (rstat_getUncontrollable() == 0) {
            return;
        }
    }
    ptcm_createEmitter(0x30, &choropu->field0.mCourseMapRow->field0);
}

void choro_state4Update(Unk020e1e98 *choropu) {
    choropu->field0.field10.y -= 0x266;
    choropu->field0.mPos.y = choropu->field0.mPos.y + choropu->field0.field10.y;
    if (choropu->field0.mPos.y < choropu->fieldB0) {
        choropu->field0.mStateMachine.mNextState = 5;
        choropu->field0.mStateMachine.mNextStateRequested = 1;
    }
}

// Same body as choro_state0Init; this is the enter slot of state 5.
void choro_state5Init(Unk020e3338 *choropu) {
    choropu->field8 = choropu->fieldAC;
    choropu->field14 = 0x0u;
    choropu->field2 |= data_02158bb8;
    choropu->field2 |= data_02158bb4;
}

void choro_state5Update(Unk020e1e98 *choropu) {
    if (choropu->field0.mStateMachine.mStateFrames >= choropu->fieldA4) {
        choropu->field0.mStateMachine.mNextState = 1;
        choropu->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void choro_state6Init(Unk020e1e98 *choropu) {
    choropu->field0.mFlags = (((choropu->field0.mFlags)) | ((data_02158bb4)));
}

void choro_state6Update(Unk020e1e98 *choropu) {
    if (choropu->fieldB4.field0 != 0) {
        choropu->fieldB4.field4 += 0x400;
    } else {
        choropu->fieldB4.field4 -= 0x400;
    }
    choropu->field0.field10.y -= 0x400;
    choropu->field0.mPos.y = choropu->field0.mPos.y + choropu->field0.field10.y;
    if (choropu->field0.mPos.y < choropu->fieldB0) {
        choropu->field0.mStateMachine.mNextState = 5;
        choropu->field0.mStateMachine.mNextStateRequested = 1;
    }
}

u32 choro_state7Init(u32 value) {
    return value;
}

void choro_state7Update(Unk020e1e98 *choropu) {
    choropu->field0.field10.y -= 0x266;
    choropu->field0.mPos.y = choropu->field0.mPos.y + choropu->field0.field10.y;
    if (choropu->field0.mPos.y < choropu->fieldB0) {
        Unk020e005c_080 *stateMachine = &choropu->field0.mStateMachine;

        stateMachine->mNextState = 5;
        stateMachine->mNextStateRequested = 1;
    }
    if (choropu->fieldB4.field0 != 0) {
        choropu->fieldB4.field4 += 0x400;
    } else {
        choropu->fieldB4.field4 -= 0x400;
    }
}

// Case 1 starts state 6 with an upward speed; case 2 starts state 7 unless player kind 2 or already there.
u8 choro_onDriverCollide(Unk020e1e98 *choropu, Kart *kart, u8 *c, u8 *d) {
    Vec3 offsetFromKart;

    switch (c[0]) {
        case 2:
            if (gRaceMultiConfig->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
                return d[0];
            }
            if (choropu->field0.mStateMachine.mState == 7) {
                return d[0];
            }
            choropu->field0.mStateMachine.mNextState = 7;
            choropu->field0.mStateMachine.mNextStateRequested = 1;
            mobj_tryDestroyByDriver(&choropu->field0, kart);
            break;
        case 1:
            VEC_Subtract(&choropu->field0.mPos, &kart->mPos, &offsetFromKart);
            if ((s64) offsetFromKart.z * kart->mVelocity.x - (s64) offsetFromKart.x * kart->mVelocity.z < 0) {
                choropu->fieldB4.field0 = 1;
            } else {
                choropu->fieldB4.field0 = 0;
            }
            choropu->field0.field10.y = 0x4000;
            choropu->field0.mStateMachine.mNextState = 6;
            choropu->field0.mStateMachine.mNextStateRequested = 1;
            choropu->field0.mFlags |= data_02158bb4;
            mobj_tryDestroyByDriver(&choropu->field0, kart);
            break;
    }
    return d[0];
}

// Case 1 starts state 6 with an upward speed, as choro_onDriverCollide does for a kart.
u8 choro_onItemCollide(Unk020e1e98 *choropu, Unk020e246c *itemObject, u8 *c, u8 *d) {
    Vec3 offsetFromItem;
    Vec3 offset;

    if (c[0] == 1) {
        if (itemObject != NULL) {
            VEC_Subtract(&choropu->field0.mPos, &itemObject->field50, &offsetFromItem);
            if ((s64) offsetFromItem.z * itemObject->field5C - (s64) offsetFromItem.x * itemObject->field64 < 0) {
                choropu->fieldB4.field0 = 1;
            } else {
                choropu->fieldB4.field0 = 0;
            }
            choropu->field0.field10.y = 0x4000;
            choropu->field0.mStateMachine.mNextState = 6;
            choropu->field0.mStateMachine.mNextStateRequested = 1;
            choropu->field0.mFlags |= data_02158bb4;
            it_emitMissionParticles(itemObject);
        } else {
            VEC_Subtract(&choropu->field0.mPos, &choropu->field0.mPos, &offset);
            if ((s64) offset.z * data_02158c7c.x - (s64) offset.x * data_02158c7c.z < 0) {
                choropu->fieldB4.field0 = 1;
            } else {
                choropu->fieldB4.field0 = 0;
            }
            choropu->field0.field10.y = 0x4000;
            choropu->field0.mStateMachine.mNextState = 6;
            choropu->field0.mStateMachine.mNextStateRequested = 1;
            choropu->field0.mFlags |= data_02158bb4;
        }
    }
    return d[0];
}

#pragma thumb on

void choro_loadModel(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = mobj_getMapObjFile(aChoropu_nsbmd);
    nsbtpFile = mobj_getMapObjFile(aChoropu_nsbtp);
    bbm_createFromNsbmd((NsbmdModel **) (((u32 *) &gChoropu)), nsbmdFile, nsbtpFile, 0);
    bbm_setDefaultMatParams(gChoropu);
}

#pragma thumb off
