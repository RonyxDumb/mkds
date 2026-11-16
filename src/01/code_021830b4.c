#include "01/code_021830b4.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_02184274.h"
#include "01/code_02184cc8.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_021000d0.h"

void func_ov001_021841e0(Unk02188950 *donketu) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = donketu->mPrm->field238;
    func_ov001_02187218(donketu, 8, func_ov001_02184274);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field224, donketu->mPrm->field228);
    SetVelocity(donketu, &velocity);
    func_ov001_02188c90(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->field230, donketu->mPrm->field234);
    SetCourseCollisionCallback(donketu, func_ov001_021842ec);
    donketu->field0.mFlags |= data_ov001_021a6578;
}

void func_ov001_02184160(Unk02188950 *donketu) {
    u32 v1;
    func_ov001_02187218(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field210, donketu->mPrm->field214);
    v1 = donketu->mPrm->field21C;
    func_ov001_02188c48(donketu, v1, v1);
    SetAnglePointAndMoveAnglePoint(donketu, (Vec3 *) donketu->field0.mCourseMapRow);
    v1 = donketu->mPrm->field218;
    SetSpeedTargetAndPerCall(donketu, v1, v1);
    StartStateFrameCountCallback(donketu, donketu->mPrm->field220, &func_ov001_021841e0);
}

void func_ov001_02183ff4(Unk02188950 *donketu) {
    Vec3 velocity;
    s32 scale;

    velocity.x = donketu->field0.mPos.x;
    velocity.y = 0;
    velocity.z = donketu->field0.mPos.z;
    if ((s64) velocity.z * velocity.z + ((s64) velocity.x * velocity.x + (s64) velocity.y * velocity.y) >= 16) {
        vec_normalize(&velocity, &velocity);
    }
    scale = donketu->mPrm->field204;
    velocity.x = (s64) velocity.x * scale >> 12;
    velocity.y = (s64) velocity.y * scale >> 12;
    velocity.z = (s64) velocity.z * scale >> 12;
    velocity.y = -donketu->mPrm->field208;
    func_ov001_02187218(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field1FC, donketu->mPrm->field200);
    func_ov001_02188c90(donketu);
    SetSpeedAndClearTarget(donketu, 0);
    SetVelocity(donketu, &velocity);
    DisableMissionRunMapObjectGravity(donketu);
    StartStateFrameCountCallback(donketu, donketu->mPrm->field20C, func_ov001_02184160);
    StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x423, 0);
    StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x425, 0);
    StartModelEffectAtWaterHeight(donketu, 4, 0);
    mobj_emitSfxFromEmitter2(&donketu->field0, 0x244);
    donketu->field0.mFlags |= data_ov001_021a6578;
}

void func_ov001_02183f0c(Unk02188950 *donketu) {
    Vec3 velocity = {0, 0, 0};

    func_ov001_02187218(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field70, donketu->mPrm->field74);
    SetVelocity(donketu, &velocity);
    DisableMissionRunMapObjectGravity(donketu);
    func_ov001_02188c90(donketu);
    SetSpeedAndClearTarget(donketu, 0);
    if (donketu->field0.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x423, 0);
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x425, 0);
    } else if (donketu->field0.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x423, 0);
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x425, 0);
    }
    {
        Unk0210b7a8 soundRequest = {0x212, 0, 0xc, 0};

        soundRequest.mPositionSource = &donketu->field0.mPos;
        soundRequest.mDistanceSquared = mobj_calcXZCamDist(&donketu->field0.mPos);
        sub_210B734(&soundRequest, func_02108e7c());
    }
    donketu->field0.mFlags |= data_ov001_021a6578;
}

void func_ov001_02183ed4(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 5, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->field160, donketu->mPrm->field164, NULL);
    SetSpeedAndClearTarget(donketu, 0);
}

u32 func_ov001_02183ebc(Unk02188950 *donketu) {
    mobj_emitSfxFromEmitter(&donketu->field0, 0x00000243u);
    return 0;
}

void func_ov001_02183e40(Unk02188950 *donketu) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = donketu->mPrm->field154;
    func_ov001_02187218(donketu, 5, (s32(*)(Unk02188950 *)) func_ov001_02183ebc);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field14C, donketu->mPrm->field150);
    func_ov001_02188a8c(donketu, donketu->mPrm->field158, donketu->mPrm->field158);
    SetVelocity(donketu, &velocity);
    SetCourseCollisionCallback(donketu, func_ov001_02183ed4);
}

void func_ov001_02183dec(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 5, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->field12C, donketu->mPrm->field130, NULL);
    StartStateFrameCountCallback(donketu, donketu->mPrm->field134, &func_ov001_02183e40);
    SetSpeedAndClearTarget(donketu, 0);
}

s32 func_ov001_02183d94(Unk02188950 *donketu) {
    SetAnglePointAndMoveAnglePoint(donketu, &driver_getById((u16) gRaceMultiConfig->mEntryIndex)->mPos);
    if (donketu->mSpeed < donketu->mPrm->field108) {
        SetKartCollisionCallback(donketu, func_ov001_02184874);
        func_ov001_02184e6c(donketu);
    }
    return 0;
}

void func_ov001_02183cc8(Unk02188950 *donketu) {
    Kart *kart;

    kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(donketu, 2, func_ov001_02183d94);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field10C, donketu->mPrm->field110);
    func_ov001_02188c48(donketu, donketu->mPrm->field118, donketu->mPrm->field118);
    SetAnglePointAndMoveAnglePoint(donketu, &kart->mPos);
    func_ov001_021889c8(donketu);
    SetSpeedTargetAndPerCall(donketu, 0, donketu->mPrm->field114);
    SetStoppedCallback(donketu, func_ov001_02184cc8);
    SetKartCollisionCallback(donketu, func_ov001_021843b0);
    if (donketu->mSpeed < donketu->mPrm->field114) {
        SetKartCollisionCallback(donketu, func_ov001_02184874);
    }
    func_ov001_02184e18((u16 *) donketu);
}

void func_ov001_02183c54(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->fieldF4, donketu->mPrm->fieldF8);
    func_ov001_02188c90(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->fieldFC, donketu->mPrm->field100);
    StartStateFrameCountCallback(donketu, donketu->mPrm->field104, &func_ov001_02183cc8);
    SetKartCollisionCallback(donketu, func_ov001_021843b0);
    func_ov001_02184e18((u16 *) donketu);
}

void func_ov001_02183c08(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->fieldE8, donketu->mPrm->fieldEC);
    func_ov001_02188c90(donketu);
    StartStateFrameCountCallback(donketu, donketu->mPrm->fieldF0, &func_ov001_02183c54);
    func_ov001_02184e6c(donketu);
}

void func_ov001_02183b9c(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field80, donketu->mPrm->field84);
    func_ov001_02188c90(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->field88, donketu->mPrm->field8C);
    StartStateFrameCountCallback(donketu, donketu->mPrm->field90, &func_ov001_02183cc8);
    SetKartCollisionCallback(donketu, func_ov001_021843b0);
    func_ov001_02184e18((u16 *) donketu);
}

void func_ov001_02183ad8(Unk02188950 *donketu) {
    Kart *kart;

    kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(donketu, 3, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->fieldCC, donketu->mPrm->fieldD0);
    func_ov001_02188c48(donketu, donketu->mPrm->fieldD8, donketu->mPrm->fieldD8);
    SetAnglePointAndMoveAnglePoint(donketu, &kart->mPos);
    SetSpeedAndClearTarget(donketu, donketu->mPrm->fieldD4);
    SetPointInRangeCallback(donketu, 0, donketu->mPrm->fieldE4, &kart->mPos, func_ov001_02183c08);
    if (donketu->field0.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
        mobj_emitSfxFromEmitter2(&donketu->field0, 0x214);
    } else if (donketu->field0.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        mobj_emitSfxFromEmitter2(&donketu->field0, 0x245);
    }
    func_ov001_02184e6c(donketu);
}

void func_ov001_021839ac(Unk02188950 *donketu) {
    if (IsPointInRange(donketu, (Vec3 *) donketu->field0.mCourseMapRow, (donketu->mPrm->field180 + 0x28), 0)) {
        func_ov001_02187218(donketu, 3, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->field168, donketu->mPrm->field16C);
        func_ov001_02188c48(donketu, donketu->mPrm->field178, 0x270f000);
        SetAnglePointAndMoveAnglePoint(donketu, &donketu->field0.mCourseMapRow->field0);
        SetSpeedTargetAndPerCall(donketu, donketu->mPrm->field174, donketu->mPrm->field170);
        StartStateFrameCountCallback(donketu, donketu->mPrm->field17C, NULL);
        SetKartCollisionCallback(donketu, func_ov001_02184874);
    } else {
        func_ov001_02187218(donketu, 3, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->field168, donketu->mPrm->field16C << 2);
        func_ov001_02188c48(donketu, donketu->mPrm->field178, 0x270f000);
        SetAnglePointAndMoveAnglePoint(donketu, &donketu->field0.mCourseMapRow->field0);
        SetSpeedTargetAndPerCall(donketu, -donketu->mPrm->field174, donketu->mPrm->field170);
        StartStateFrameCountCallback(donketu, donketu->mPrm->field17C, NULL);
        SetKartCollisionCallback(donketu, func_ov001_02184874);
    }
    func_ov001_02184e6c(donketu);
}

void func_ov001_02183894(Unk02188950 *donketu) {
    MissionRunPrm *prm;

    prm = donketu->mPrm;
    if (IsPointInRange(donketu, &GetCurrentGroupEntry(donketu)->mPos, prm->fieldAC, prm->fieldB0)) {
        func_ov001_02187218(donketu, 1, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->fieldB8, donketu->mPrm->fieldBC);
        func_ov001_02188b2c(donketu, donketu->mPrm->fieldC4, donketu->mPrm->fieldC4, 0);
        SetAnglePointAndMoveAnglePoint(donketu, &GetCurrentGroupEntry(donketu)->mPos);
        SetSpeedTargetAndPerCall(donketu, donketu->mPrm->fieldC0, donketu->mPrm->fieldC0);
        StartStateFrameCountCallback(donketu, donketu->mPrm->fieldC8, NULL);
    } else {
        IncrementEntryIndex(donketu);
        func_ov001_02187218(donketu, 1, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->field9C, donketu->mPrm->fieldA0);
        func_ov001_02188c48(donketu, donketu->mPrm->fieldA8, donketu->mPrm->fieldA8);
        SetAnglePointAndMoveAnglePoint(donketu, &GetCurrentGroupEntry(donketu)->mPos);
        SetSpeedTargetAndPerCall(donketu, donketu->mPrm->fieldA4, donketu->mPrm->fieldA4);
        prm = donketu->mPrm;
        SetPointInRangeCallback(donketu, prm->fieldAC, prm->fieldB0, &GetCurrentGroupEntry(donketu)->mPos, NULL);
    }
    func_ov001_02184e6c(donketu);
}

void func_ov001_02183880(Unk02188950 *donketu) {
    func_ov001_02183ff4(donketu);
    func_ov001_02188260(donketu);
}

void func_ov001_02183850(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field78, donketu->mPrm->field7C);
    func_ov001_02188c90(donketu);
    SetSpeedAndClearTarget(donketu, 0);
}

void func_ov001_02183848(void) {
    func_ov001_021882b8();
}

int func_ov001_02183780(Unk02188950 *donketu) {
    if (donketu->field0.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        if (mobj_getModelCurNsbcaFrame(donketu->mNsbmd) == 2 ||
            mobj_getModelCurNsbcaFrame(donketu->mNsbmd) == 3) {
            ReleaseEffects(donketu);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            mobj_emitSfxFromEmitter2(&donketu->field0, 0x240);
        }
    }
    if (race_getState() == 1) {
        func_ov001_02183b9c(donketu);
    }
    return 0;
}

int func_ov001_02183690(Unk02188950 *donketu) {
    if (donketu->field0.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        if (mobj_getModelCurNsbcaFrame(donketu->mNsbmd) == 2) {
            ReleaseEffects(donketu);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            mobj_emitSfxFromEmitter2(&donketu->field0, 0x240);
        }
    } else if (donketu->field0.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
        if (mobj_getModelCurNsbcaFrame(donketu->mNsbmd) == 0x2b ||
            mobj_getModelCurNsbcaFrame(donketu->mNsbmd) == 0x48) {
            ReleaseEffects(donketu);
            StartEffectAtRowHeight(donketu, 0, 0, 0, 0x410, 0);
        }
    }
    return 0;
}

s32 func_ov001_021835e0(Unk02188950 *donketu) {
    int nsbcaFrameIndex;
    if ((donketu->field0.mKind == 0x000001f6u) &&
        (nsbcaFrameIndex = mobj_getModelCurNsbcaFrame(donketu->mNsbmd), nsbcaFrameIndex == 2)) {
        ReleaseEffects(donketu);
        func_ov001_021872e0(donketu, 0x00001000u, 0, 0, 0, 0x00000666u, 0xfffff000u, 0x00000428u, 0);
        func_ov001_021872e0(donketu, 0x00001000u, 0, 0, 0, 0x00000666u, 0xfffff000u, 0x00000429u, 0);
        func_ov001_021872e0(donketu, 0x00001000u, 0, 0, 0, 0x00000800u, 0xfffff000u, 0x0000042au, 0);
        mobj_emitSfxFromEmitter2(&donketu->field0, 0x00000240u);
    }
    return 0;
}

void func_ov001_021835b8(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, &func_ov001_02183780);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field64, donketu->mPrm->field68);
}

void func_ov001_0218355c(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, &func_ov001_02183690);
    if (donketu->field0.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        StartAnimationNoEndCallback(donketu, donketu->mPrm->field58, donketu->mPrm->field5C);
        StartStateFrameCountCallback(donketu, donketu->mPrm->field60, &func_ov001_021835b8);
        return;
    }
    StartAnimationWithEndCallback(donketu, donketu->mPrm->field58, donketu->mPrm->field5C, &func_ov001_021835b8);
}

void func_ov001_02183524(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, func_ov001_021835e0);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field4C, donketu->mPrm->field50);
    StartStateFrameCountCallback(donketu, donketu->mPrm->field54, &func_ov001_0218355c);
}

void func_ov001_021834fc(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, func_ov001_021835e0);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field40, donketu->mPrm->field44);
}

void func_ov001_021834c4(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, func_ov001_021835e0);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->field34, donketu->mPrm->field38);
    StartStateFrameCountCallback(donketu, donketu->mPrm->field3C, &func_ov001_021834fc);
}

void InitDonketuObjects(Unk0218fa78 *list) {
    s32 i;
    Unk02188950 *donketu;

    if (list != NULL) {
        for (i = 0; i < list->field4 && (donketu = list->field0[i]) != NULL; i++) {
            func_ov001_02187eb0(donketu);
            donketu->field0.mCourseMapRow->field0.x = 0;
            donketu->field0.mCourseMapRow->field0.z = 0;
            if (race_isCamAnimMode() != 0) {
                func_ov001_021834c4(donketu);
            } else {
                func_ov001_02183524(donketu);
            }
            func_ov001_02188da4(donketu, func_ov001_02183b9c);
        }
    }
    mgcnt_setOnEndFunc((void (*)(void)) func_ov001_02183848);
}

void UpdateDonketu(u32 b, Unk02188950 *donketu) {
    MissionRunPrm *prm;
    Kart *kart;

    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_hasWinnerBeenDecided() : 0) {
        if (func_ov001_021871f8(donketu, 1) != 0) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_isDriverDead((u16) gRaceMultiConfig->mEntryIndex) : 0) {
                func_ov001_02183850(donketu);
            } else {
                func_ov001_02183f0c(donketu);
            }
        }
    } else {
        if (func_ov001_021871f8(donketu, 8) != 0) {
            if (func_ov001_021871d0(donketu) != FALSE) {
                func_ov001_02183880(donketu);
            }
        }
        if (func_ov001_021871f8(donketu, 5) != 0) {
            prm = donketu->mPrm;
            if (func_ov001_02188220(donketu) >= prm->field148) {
                prm = donketu->mPrm;
                if (GetEntryKartInRange(donketu, prm->field138, prm->field13C) != NULL) {
                    prm = donketu->mPrm;
                    kart = GetEntryKartFacingObject(donketu, prm->field140, prm->field144);
                    if (kart != NULL) {
                        if ((driver_getById(kart->mIndex)->field48 & 0x100000) != 0 && kart->mBoostTimer > 0) {
                            func_ov001_02183dec(donketu);
                        }
                    }
                }
            }
        }
        if (func_ov001_021871f8(donketu, 3) != 0) {
            if (IsPointInRange(donketu, (Vec3 *) donketu->field0.mCourseMapRow, donketu->mPrm->field180, 0) ==
                FALSE) {
                func_ov001_021839ac(donketu);
            }
        }
        if (func_ov001_021871f8(donketu, 2) != 0) {
            prm = donketu->mPrm;
            if (GetEntryKartInRange(donketu, prm->fieldDC, prm->fieldE0) != NULL) {
                func_ov001_02183ad8(donketu);
            }
        }
        if (func_ov001_021871f8(donketu, 1) != 0) {
            func_ov001_02183894(donketu);
        }
    }
    boss_update(b, donketu);
}

void donk_init(Unk02188950 *donketu) {
    donketu->field0.mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource((SoundSource *) donketu->field0.mSound, 0xc, &donketu->field0.mPos);
    donketu->field0.mFarDistanceSquared = data_0217cbec[20];
}

void LoadBoss_donketu(Unk0218fa78 *list) {
    Unk02188950 *donketu;
    s32 i;

    if (list != NULL) {
        for (i = 0; i < list->field4 && (donketu = list->field0[i]) != NULL; i++) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(donketu);
            }
            boss_21870E4(list, donketu, aBoss_donketu_n, aBoss_donketu_0, aBoss_donketu_p);
            LoadMissionRunMapObjectShadow(list, donketu, aSh_circle_nsbmd);
            SetCollisionOffsetAndExtent(donketu, donketu->mPrm->field8, donketu->mPrm->fieldC, 0);
            SetShadowOffsetYAndScale(donketu, 0, 0x11000);
            SetKartCollisionCallback(donketu, func_ov001_02184874);
            donketu->field2B8 = 2;
        }
    }
}

void LoadKing_ice_donketu(Unk0218fa78 *list) {
    Unk02188950 *donketu;
    s32 i;

    if (list != NULL) {
        for (i = 0; i < list->field4 && (donketu = list->field0[i]) != NULL; i++) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(donketu);
            }
            boss_21870E4(list, donketu, aKing_ice_donke, aKing_ice_don_0,
                                    aKing_ice_don_1);
            LoadMissionRunMapObjectShadow(list, donketu, aSh_circle_nsbm);
            SetCollisionOffsetAndExtent(donketu, donketu->mPrm->field8, donketu->mPrm->fieldC, 0);
            SetShadowOffsetYAndScale(donketu, 0, 0x21000);
            SetKartCollisionCallback(donketu, func_ov001_02184874);
        }
    }
}

void func_ov001_02183138(void *a, Unk02188950 *donketu) {
    boss_render(a, donketu);
    boss_renderShadow(a, donketu, 0);
}

void donk_setupCollision(void) {
    u32 v4 = 0x23eu;
    void *v8 = &boss_onDriverCollide;
    void *v9 = &boss_onItemCollide;
    void *v10 = &boss_collide;
    void *v12 = func_ov001_0219b510(v8, v9, v10, 0x2u, 0x1u, v4, 0x0u);
}

void *donk_setupBossRenderPart(void) {
    return mobj_createRenderPart3d(LoadBoss_donketu, func_ov001_02183138, ktesa_globalPreRender);
}

void *donk_setupKingIceRenderPart(void) {
    return mobj_createRenderPart3d(LoadKing_ice_donketu, func_ov001_02183138, ktesa_globalPreRender);
}

void *donk_setupLogicPart(void) {
    return mobj_createLogicPart(InitDonketuObjects, UpdateDonketu, NULL);
}
