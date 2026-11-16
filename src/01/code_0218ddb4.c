#include "01/code_0218ddb4.h"
#include "01/code_02187d14.h"
#include "01/code_02188de0.h"

#include "01/code_02185ef4.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218155c.h"
#include "01/code_02187cd4.h"
#include "01/code_02188158.h"
#include "01/code_02188484.h"
#include "01/code_0218f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_02110100.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_02188000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02181bd0.h"
#include "01/code_02187e78.h"
#include "01/code_02187eb0.h"
#include "01/code_0218f900.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_02181000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_020a128c.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b000.h"
#include "01/code_02187000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "01/code_02182000.h"
#include "01/code_02188950.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0217a000.h"

void func_ov001_0218f850(Unk02188950 *a) {
    StartAnimationNoEndCallback(a, a->mPrm->field198, a->mPrm->field19C);
    SetAlphaLimitTargetAndPerCall(a, a->mPrm->field1A0, a->mPrm->field1A4);
    SetSpeedAndClearTarget(a, 0);
    func_ov001_02188c90(a);
    StartEffectAtOffset(a, 0, 0, 0, 0x41e, 0);
    StartEffectAtOffset(a, 0, 0, 0, 0x41f, 0);
    StartEffectAtOffset(a, 0, 0, 0, 0x420, 0);
    mobj_emitSfxFromEmitter2(&a->field0, 0x22d);
    a->field0.mFlags = a->field0.mFlags | data_ov001_021a65bc;
}

void func_ov001_0218f724(Unk02188950 *b) {
    Vec3 v1;
    Vec3 v2;
    u32 a;
    s32 i;
    s32 s;
    s32 c;
    s64 z;
    s64 x;
    VEC_Subtract(gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mrcnt_getPlayerPosition() : 0,
                 gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mrcnt_getPrevPlayerPosition() : 0, &v1);
    v1.y = 0;
    a = 0;
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        a = mrcnt_getPrevPlayerYRot();
    }
    a = (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mrcnt_getPlayerYRot() : 0) - a;
    VEC_Subtract(&b->field0.mPos, gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mrcnt_getPlayerPosition() : 0, &v2);
    for (i = 0; i < 1; i++) {
        c = FX_SinCosTable_[((u16) a >> 4) * 2 + 1];
        x = v2.x;
        s = FX_SinCosTable_[((u16) a >> 4) * 2];
        z = v2.z;
    }
    v1.x += (s32) (z * s >> 12) + (s32) (x * c >> 12) - v2.x;
    v1.z += (s32) (z * c >> 12) - (s32) (x * s >> 12) - v2.z;
    SetVelocity(b, &v1);
}

void func_ov001_0218f6d8(Unk02188950 *a) {
    Vec3 local;
    VEC_Subtract(gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mrcnt_getPlayerPosition() : 0,
                 gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mrcnt_getPrevPlayerPosition() : 0, &local);
    local.y = 0;
    SetVelocity(a, &local);
}

s32 func_ov001_0218f688(Unk02188950 *a) {
    Kart *obj = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    if ((obj->field48 & 0x200) == 0) {
        SetAnglePointAndMoveAnglePoint(a, &obj->mPos);
        func_ov001_02188d8c(a, &obj->mPos);
    }
    func_ov001_0218f6d8(a);
    return 0;
}

s32 func_ov001_0218f634(Unk02188950 *a) {
    Kart *obj = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    if ((obj->field48 & 0x200) == 0) {
        SetAnglePointAndMoveAnglePoint(a, &obj->mPos);
        func_ov001_02188d8c(a, &obj->mPos);
    }
    func_ov001_0218f6d8(a);
    race_resetDarkeningFadeWaitCounter();
    return 0;
}

void func_ov001_0218f57c(Unk02188950 *a) {
    Kart *p;

    p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(a, 5, func_ov001_0218f634);
    StartAnimationNoEndCallback(a, a->mPrm->field1FC, a->mPrm->field200);
    SetSpeedTargetAndPerCall(a, a->mPrm->field204, a->mPrm->field208);
    func_ov001_02188bc4(a, a->mPrm->field20C, a->mPrm->field210);
    SetAnglePointAndMoveAnglePoint(a, &p->mPos);
    func_ov001_021889c8(a);
    StartStateFrameCountCallback(a, a->mPrm->field214, NULL);
    SetKartCollisionCallback(a, func_ov001_0218f9a8);
}

void func_ov001_0218f51c(Unk02188950 *a) {
    driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(a, 5, func_ov001_0218f634);
    StartAnimationWithEndCallback(a, a->mPrm->field1F4, a->mPrm->field1F8, func_ov001_0218f57c);
    SetKartCollisionCallback(a, func_ov001_0218f9a8);
    func_ov001_021828f0();
}

void func_ov001_0218f454(Unk02188950 *a) {
    Kart *p;

    p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(a, 5, func_ov001_0218f634);
    StartAnimationNoEndCallback(a, a->mPrm->field1D8, a->mPrm->field1DC);
    SetSpeedTargetAndPerCall(a, a->mPrm->field1E0, a->mPrm->field1E4);
    func_ov001_02188c48(a, a->mPrm->field1E8, a->mPrm->field1EC);
    SetAnglePointAndMoveAnglePoint(a, &p->mPos);
    func_ov001_021889c8(a);
    StartStateFrameCountCallback(a, a->mPrm->field1F0, func_ov001_0218f51c);
    SetKartCollisionCallback(a, func_ov001_0218f9a8);
    mobj_emitSfxFromEmitter2(&a->field0, 0x229);
}

s32 func_ov001_0218f3ec(Unk02188950 *a) {
    Kart *p;
    Vec3 v;

    p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    if ((p->field48 & 0x200) == 0) {
        VEC_MultAdd(a->mPrm->field21C, &p->mEasedTurnedForward, &p->mPos, &v);
        SetAnglePointAndMoveAnglePoint(a, &v);
        func_ov001_02188d8c(a, &v);
    }
    func_ov001_0218f6d8(a);
    race_resetDarkeningFadeWaitCounter();
    return 0;
}

s32 func_ov001_0218f3ac(Unk02188950 *a) {
    Kart *p;

    p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    if ((p->field48 & 0x200) == 0) {
        SetAnglePointAndMoveAnglePoint(a, &p->mPos);
    }
    func_ov001_0218f6d8(a);
    return 0;
}

void func_ov001_0218f2a8(Unk02188950 *a) {
    Kart *p;
    Vec3 v;

    p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    VEC_MultAdd(a->mPrm->field21C, &p->mEasedTurnedForward, &p->mPos, &v);
    func_ov001_02187218(a, 5, func_ov001_0218f3ac);
    StartAnimationNoEndCallback(a, a->mPrm->fieldEC, a->mPrm->fieldF0);
    SetAlphaLimitTargetAndPerCall(a, a->mPrm->fieldF4, a->mPrm->fieldF8);
    SetSpeedTargetAndPerCall(a, a->mPrm->fieldFC, a->mPrm->field100);
    func_ov001_02188c48(a, a->mPrm->field104, a->mPrm->field108);
    SetPointInRangeCallback(a, a->mPrm->field218, 0, &v, (UnkFunc *) func_ov001_0218f454);
    if (data_0217d20c != 2) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 2;
    SetKartCollisionCallback(a, func_ov001_0218e298);
    a->field0.mFlags |= data_ov001_021a65b0;
}

s32 func_ov001_0218f244(Unk02188950 *a) {
    Kart *p;
    Vec3 v;

    p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    if ((p->field48 & 0x200) == 0) {
        VEC_MultAdd(-a->mPrm->fieldE8, &p->mEasedTurnedForward, &p->mPos, &v);
        SetAnglePointAndMoveAnglePoint(a, &v);
        func_ov001_02188d8c(a, &v);
    }
    func_ov001_0218f6d8(a);
    return 0;
}

void func_ov001_0218f16c(Unk02188950 *a) {
    Kart *p;
    Vec3 v;

    p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    VEC_MultAdd(-a->mPrm->fieldE8, &p->mEasedTurnedForward, &p->mPos, &v);
    func_ov001_02187218(a, 3, func_ov001_0218f244);
    StartAnimationNoEndCallback(a, a->mPrm->fieldC4, a->mPrm->fieldC8);
    SetAlphaLimitTargetAndPerCall(a, a->mPrm->fieldCC, a->mPrm->fieldD0);
    SetSpeedTargetAndPerCall(a, a->mPrm->fieldD4, a->mPrm->fieldD8);
    func_ov001_02188c48(a, a->mPrm->fieldDC, a->mPrm->fieldE0);
    SetPointInRangeCallback(a, a->mPrm->fieldE4, 0, &v, (UnkFunc *) func_ov001_0218f2a8);
    if (data_0217d20c != 1) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 1;
}

s32 func_ov001_0218efc4(Unk02188950 *a) {
    Kart *p;
    float f;

    p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    if ((p->field48 & 0x200) == 0) {
        SetAnglePointAndMoveAnglePoint(a, &p->mPos);
        func_ov001_02188d8c(a, &p->mPos);
    }
    func_ov001_0218f724(a);
    if (GetEntryKartInRange(a, a->mPrm->fieldB8, 0) == NULL) {
        a->field1C4 = a->mPrm->fieldC0;
    } else {
        a->field1C4 = 0;
    }
    a->mAlphaLimitPerCall = a->mPrm->field9C;
    if (a->mPrm->field1CC - (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) > 0) {
        f = 0.5f + ((a->mPrm->field1CC - (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0)) << 12);
    } else {
        f = ((a->mPrm->field1CC - (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0)) << 12) - 0.5f;
    }
    a->mAlphaLimitTarget = (s32) f / a->mPrm->field1D4;
    if ((gRaceMultiConfig->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) <= a->mPrm->field1D0 &&
        GetEntryKartFacingObject(a, 0, a->mPrm->fieldBC) != NULL) {
        SetKartCollisionCallback(a, func_ov001_0218f9a8);
        a->field0.mFlags |= data_ov001_021a65b0;
        func_ov001_0218f16c(a);
    } else if ((gRaceMultiConfig->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) > a->mPrm->field1CC) {
        func_ov001_02188e88(a);
    }
    return 0;
}

void func_ov001_0218ef30(Unk02188950 *a) {
    driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(a, 3, func_ov001_0218efc4);
    StartAnimationNoEndCallback(a, a->mPrm->field90, a->mPrm->field94);
    SetSpeedAndClearTarget(a, a->mPrm->fieldA0);
    func_ov001_02188adc(a, a->mPrm->fieldB0, 0x270f000, a->mPrm->fieldA8, 0x270f000, 0);
    if (data_0217d20c != 0) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 0;
}

void func_ov001_0218ee88(Unk02188950 *a) {
    Kart *p;
    Vec3 v;

    p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    VEC_MultAdd(-a->mPrm->fieldE8, &p->mEasedTurnedForward, &p->mPos, &v);
    a->field0.mPos.x = v.x;
    a->field0.mPos.y = a->field0.mCourseMapRow->field0.y + a->mPrm->field80;
    a->field0.mPos.z = v.z;
    a->mMoveAngle = (u16) (FX_Atan2Idx(p->mPos.x - a->field0.mPos.x, p->mPos.z - a->field0.mPos.z) + 0x4000);
    a->mAngle = a->mMoveAngle;
    func_ov001_0218ef30(a);
    func_ov001_02182a3c(0);
    a->field0.mFlags &= ~1;
}

void func_ov001_0218edc8(Unk02188950 *a) {
    Kart *p;

    p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(a, 3, func_ov001_0218f634);
    StartAnimationNoEndCallback(a, a->mPrm->field144, a->mPrm->field148);
    SetAlphaLimitTargetAndPerCall(a, a->mPrm->field14C, a->mPrm->field150);
    SetSpeedTargetAndPerCall(a, a->mPrm->field154, a->mPrm->field158);
    func_ov001_02188c48(a, a->mPrm->field15C, a->mPrm->field160);
    SetAnglePointAndMoveAnglePoint(a, &p->mPos);
    StartStateFrameCountCallback(a, a->mPrm->field164, NULL);
}

u32 func_ov001_0218edb8(void) {
    race_resetDarkeningFadeWaitCounter();
    return 0;
}

void func_ov001_0218ec40(Unk02188950 *a) {
    driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(a, 1, (s32(*)(Unk02188950 *)) func_ov001_0218edb8);
    StartAnimationNoEndCallback(a, a->mPrm->field118, a->mPrm->field11C);
    SetAlphaLimitTargetAndPerCall(a, a->mPrm->field120, a->mPrm->field124);
    if (a->fieldA8 == 1) {
        SetSpeedTargetAndPerCall(a, a->mPrm->field128, a->mPrm->field12C);
        func_ov001_02188c48(a, a->mPrm->field130, a->mPrm->field134);
    } else if (a->fieldA8 == 2) {
        SetSpeedTargetAndPerCall(a, a->mPrm->field220, a->mPrm->field224);
        func_ov001_02188c48(a, a->mPrm->field228, a->mPrm->field22C);
    } else if (a->fieldA8 == 3) {
        SetSpeedTargetAndPerCall(a, a->mPrm->field230, a->mPrm->field234);
        func_ov001_02188c48(a, a->mPrm->field238, a->mPrm->field23C);
    }
    SetAnglePointAndMoveAnglePoint(a, &GetCurrentGroupEntry(a)->mPos);
    SetPointInRangeCallback(a, a->mPrm->field138, a->mPrm->field13C, &GetCurrentGroupEntry(a)->mPos, NULL);
    if (data_0217d20c != 5) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 5;
}

void func_ov001_0218eb94(Unk02188950 *a) {
    RandomState64 *rng;
    driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    rng = mobj_getRng1();
    rng->mValue = (s64) rng->mMultiplier * (s64) rng->mValue + rng->mIncrement;
    a->field0.mPos.x = (&GetCurrentGroupEntry(a)->mPos)->x;
    a->field0.mPos.y = a->mPrm->field80 + (&GetCurrentGroupEntry(a)->mPos)->y;
    a->field0.mPos.z = (&GetCurrentGroupEntry(a)->mPos)->z;
    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_0218f900(a);
    StartStateFrameCountCallback(a, a->mPrm->field1B4, NULL);
    if (data_0217d20c != 5) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 5;
}

void func_ov001_0218ead0(Unk02188950 *a) {
    int v1;
    u32 v2;

    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_0218f850(a);
    StartStateFrameCountCallback(a, a->mPrm->field1A8, func_ov001_0218eb94);
    func_ov001_02182a3c(0);
    IncrementEntryGroupIndex(a, a->mPrm->field140);
    v1 = a->fieldA8;
    if (v1 == 1) {
        v2 = 2;
    } else if (v1 == 2) {
        v2 = 3;
    } else if (v1 == 3) {
        v2 = 3;
    } else {
        v2 = 1;
    }
    a->fieldA8 = v2;
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
    a->mCollisionExtentTargetZ = a->mPrm->fieldC;
    a->mCollisionExtent.z = a->mCollisionExtentTargetZ;
    a->mCollisionExtentTargetX = a->mCollisionExtent.z;
    a->mCollisionExtent.x = a->mCollisionExtentTargetX;
}

u32 func_ov001_0218ea98(Unk02188950 *a) {
    int v1;
    int v2;
    v2 = a->field0.mCourseMapRow->field0.y + a->mPrm->field84;
    v1 = a->field0.mPos.y - a->mPrm->field88;
    if (v1 <= v2) {
        v1 = v2;
    }
    a->field0.mPos.y = v1;
    race_resetDarkeningFadeWaitCounter();
    return 0;
}

void func_ov001_0218e92c(Unk02188950 *p) {
    func_ov001_02187218(p, 5, (s32(*)(Unk02188950 *)) func_ov001_0218ea98);
    StartAnimationNoEndCallback(p, p->mPrm->field170, p->mPrm->field174);
    SetAlphaLimitTargetAndPerCall(p, p->mPrm->field178, p->mPrm->field17C);
    func_ov001_02188c90(p);
    SetSpeedAndClearTarget(p, 0);
    StartStateFrameCountCallback(p, p->mPrm->field194, func_ov001_0218ead0);
    StartEffectAtOffset(p, 0, 0, 0, 0x431, 0);
    StartEffectAtOffset(p, 0, 0, 0, 0x430, 0);
    StartEffectAtOffset(p, 0, 0, 0, 0x432, 0);
    if (data_0217d20c != 4) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 4;
    SetKartCollisionCallback(p, func_ov001_0218e38c);
    p->field0.mFlags |= data_ov001_021a65b0;
    func_ov001_02182a3c(p->mPrm->field18C < (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mrcnt_getStolenCoinCount() : 0)
                            ? p->mPrm->field18C
                            : (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mrcnt_getStolenCoinCount() : 0));
    p->mCollisionExtent.x = p->mCollisionExtentTargetX = p->mCollisionExtent.z = p->mCollisionExtentTargetZ =
        p->mPrm->fieldC / 2;
}

void func_ov001_0218e8d8(Unk02188950 *a) {
    func_ov001_02187218(a, 5, NULL);
    StartAnimationWithEndCallback(a, a->mPrm->field168, a->mPrm->field16C, func_ov001_0218e92c);
    func_ov001_02188c90(a);
    SetSpeedAndClearTarget(a, 0);
    func_ov001_02182a3c(0);
    mobj_emitSfxFromEmitter2(&a->field0, 0x00000230u);
}

void func_ov001_0218e8b0(Unk02188950 *a) {
    func_ov001_02187218(a, 1, NULL);
    SetShadowOffsetYAndScale(a, 0, 0x19000);
    race_forceDarkeningFade();
    func_ov001_021827f0();
}

void func_ov001_0218e860(Unk02188950 *a) {
    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *)) func_ov001_0218f688);
    func_ov001_0218f850(a);
    StartStateFrameCountCallback(a, a->mPrm->field1A8, func_ov001_0218e8b0);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
}

void func_ov001_0218e7d0(Unk02188950 *p) {
    func_ov001_02187218(p, 1, NULL);
    SetShadowOffsetYAndScale(p, 0, 0x19000);
    StartAnimationNoEndCallback(p, p->mPrm->field198, p->mPrm->field19C);
    SetAlphaLimitTargetAndPerCall(p, p->mPrm->field1A0, p->mPrm->field1A4);
    SetSpeedAndClearTarget(p, 0);
    func_ov001_02188c90(p);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
    p->field0.mFlags |= data_ov001_021a65bc;
}

void func_ov001_0218e7b0(Unk02188950 *a) {
    func_ov001_02187218(a, 1, NULL);
    SetShadowOffsetYAndScale(a, 0, 0x19000);
}

void func_ov001_0218e760(Unk02188950 *p) {
    func_ov001_02187218(p, 5, func_ov001_0218f688);
    func_ov001_0218f850(p);
    StartStateFrameCountCallback(p, p->mPrm->field1A8, func_ov001_0218e7b0);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
}

void ktesa_218E710(Unk02188950 *p) {
    func_ov001_02187218(p, 8, NULL);
    StartAnimationNoEndCallback(p, p->mPrm->field78, p->mPrm->field7C);
    func_ov001_02188c90(p);
    SetSpeedAndClearTarget(p, 0);
    if (data_0217d20c != 6) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 6;
    race_forceDarkeningFade();
}

void func_ov001_0218e690(Unk02188950 *p) {
    func_ov001_02187218(p, 8, NULL);
    StartAnimationNoEndCallback(p, p->mPrm->field70, p->mPrm->field74);
    ptcm_createEmitter(0x3fe, &p->field0.mPos);
    ptcm_createEmitter(0x3fd, &p->field0.mPos);
    if (data_0217d20c != 7) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 7;
    p->field0.mFlags |= data_ov001_021a65b4;
    p->field0.mFlags |= data_ov001_021a65b8;
    p->field0.mFlags |= data_ov001_021a65bc;
}

s32 func_ov001_0218e650(Unk02188950 *a) {
    if (a->mStateFrames == 50) {
        Unk0210b7a8 local = {0x22f, 0, 0xe, 0};
        local.mPositionSource = &a->field0.mPos;
        local.mDistanceSquared = mobj_calcXZCamDist(&a->field0.mPos);
        func_0210b734(&local, func_02108e7c());
    }
    return 0;
}

void func_ov001_0218e5c4(Unk02188950 *a) {
    a->field0.mPos.y += a->mPrm->field80;
    a->mAlphaLimit = a->mAlphaLimitTarget = 0x1f000;
    a->mAlphaLimitPerCall = 0;
    func_ov001_02187218(a, 8, func_ov001_0218e650);
    StartAnimationNoEndCallback(a, a->mPrm->field70, a->mPrm->field74);
    StartStateFrameCountCallback(a, 0x3c, func_ov001_0218e690);
    if (data_0217d20c != 7) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 7;
    a->field0.mFlags &= ~1;
}

void func_ov001_0218e594(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->field70, a->mPrm->field74);
    func_ov001_02188c90(a);
    SetSpeedAndClearTarget(a, 0);
}

void func_ov001_0218e58c(void) {
    func_ov001_021882b8();
}

void ktesa_218E564(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationWithEndCallback(a, a->mPrm->field58, a->mPrm->field5C, func_ov001_0218e760);
}

void ktesa_218E520(Unk02188950 *a) {
    a->field0.mPos.y += a->mPrm->field80;
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->field4C, a->mPrm->field50);
    StartStateFrameCountCallback(a, a->mPrm->field54, ktesa_218E564);
}

void func_ov001_0218e508(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    func_ov001_0218f900(a);
}

void ktesa_218E4AC(Unk02188950 *a) {
    a->field0.mPos.y += a->mPrm->field80;
    a->mAlphaLimitTarget = 0;
    a->mAlphaLimit = a->mAlphaLimitTarget;
    a->mAlphaLimit = 0;
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->field34, a->mPrm->field38);
    StartStateFrameCountCallback(a, a->mPrm->field3C, func_ov001_0218e508);
}

void ktesa_init(Unk02188950 *a) {
    a->field0.mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource(&a->field0.mSound->mSoundSource, 0xe, &a->field0.mPos);
    a->field0.mFarDistanceSquared = data_0217cc6c[6];
}

void func_ov001_0218e38c(Unk02188950 *a, Kart *b) {
    a->field0.field10.x = ((s64) -a->mPrm->field24 * FX_SinCosTable_[(b->mHeadingAngle >> 4) * 2]) >> 12;
    a->field0.field10.y = 0;
    a->field0.field10.z = ((s64) -a->mPrm->field24 * FX_SinCosTable_[(b->mHeadingAngle >> 4) * 2 + 1]) >> 12;
    func_ov001_021829ac(a->mPrm->field190);
    func_ov001_0218ead0(a);
    a->field2D8 = 0;
    SetKartCollisionCallback(a, func_ov001_0218f9a8);
    func_ov001_0218e860(a);
    a->fieldA8 = 0;
    mobj_emitSfxFromEmitter2(&a->field0, 0x22c);
    a->mCollisionExtent.x = a->mCollisionExtentTargetX = a->mCollisionExtent.z = a->mCollisionExtentTargetZ =
        a->mPrm->fieldC;
}

void func_ov001_0218e344(Unk02188950 *a) {
    int v1;
    v1 = func_ov001_021871f8(a, 5);
    if (v1 != 0) {
        func_ov001_0218edc8(a);
    }
    a->field2D8 = 0xd;
    SetKartCollisionCallback(a, func_ov001_0218e344);
    if (a->mTimer == 0) {
        mobj_emitSfxFromEmitter2(&a->field0, 0x00000234u);
    }
}

void func_ov001_0218e298(Unk02188950 *a, Kart *b) {
    coin_steal((u16) a->mPrm->field110);
    a->field0.field10.x = 0;
    a->field0.field10.y = a->mPrm->field114;
    a->field0.field10.z = 0;
    a->field2D8 = 0xc;
    a->field158 = func_ov001_0218f3ec;
    SetKartCollisionCallback(a, func_ov001_0218f9a8);
    cam_tryImpactShakePlayerCamera(a->field0.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    func_02068a10(b);
    SetShadowOffsetYAndScale(a, 0, 0x32000);
    a->fieldA8 = 1;
    if (!(gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_hasWinnerBeenDecided() : 0)) {
        race_startDarkening();
    }
}

void ktesa_globalInitLogic(Unk0218d87c *a) {
    s32 i;
    Unk02188950 *obj;
    MissionRunPrm *a0;

    if (a != NULL) {
        for (i = 0; i < a->field4 && (obj = a->field0[i]) != NULL; i++) {
            if (race_isCamAnimMode() != 0) {
                ktesa_218E4AC(obj);
            } else {
                ktesa_218E520(obj);
            }
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                a0 = obj->mPrm;
                func_ov001_02181844(a0->field1B8, a0->field1BC, a0->field1C0, a0->field1C4);
            }
        }
    }
    mgcnt_setOnEndFunc((void (*)(void)) func_ov001_0218e58c);
}

void ktesa_update(u32 a, Unk02188950 *b) {
    Kart *p;

    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_hasWinnerBeenDecided() : 0) {
        if (func_ov001_021871f8(b, 5) != 0) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_isDriverDead((u16) gRaceMultiConfig->mEntryIndex) : 0) {
                ktesa_218E710(b);
            } else if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_hasMgEnded() : 0) {
                func_ov001_0218e5c4(b);
            } else {
                func_ov001_0218e594(b);
            }
        }
    } else {
        if (b->fieldA8 != 0) {
            if (func_ov001_021871f8(b, 5) != 0) {
                p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
                if (p->mState == KART_STATE_NORMAL && (p->field48 & 0x200) == 0 &&
                    GetEntryKartInRange(b, 0, b->mPrm->field184) != NULL &&
                    GetEntryKartFacingObject(b, 0, b->mPrm->field180) != NULL &&
                    GetEntryKartInRange(b, b->mPrm->field188, 0) != NULL) {
                    func_ov001_0218e8d8(b);
                }
            }
            if (func_ov001_021871f8(b, 3) != 0) {
                if (IsPointInRange(b, &GetCurrentGroupEntry(b)->mPos, b->mPrm->field138, 0) != 0) {
                    IncrementEntryIndex(b);
                }
                SetKartCollisionCallback(b, func_ov001_0218e344);
                b->field0.mFlags &= ~0x40;
                func_ov001_02182a3c(0);
                func_ov001_0218ec40(b);
            }
        } else {
            p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
            if (p->field48 & 0x200) {
                if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mrcnt_getCurrentValue() : 0) {
                    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                        SetMissionRunTimer((u16) b->mPrm->field1BC);
                    }
                } else {
                    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                        SetMissionRunTimer(0);
                    }
                }
                if ((b->field0.mFlags & 1) == 0) {
                    SetKartCollisionCallback(b, func_ov001_0218f9a8);
                    b->field0.mFlags |= data_ov001_021a65b0;
                    func_ov001_0218e7d0(b);
                }
            }
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) {
                if (func_ov001_021871f8(b, 3) != 0) {
                    if ((gRaceMultiConfig->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) < b->mPrm->field1C8) {
                        if (b->field0.mFlags & 1) {
                            SetKartCollisionCallback(b, func_ov001_0218f9a8);
                            b->field0.mFlags |= data_ov001_021a65b0;
                            func_ov001_0218ee88(b);
                        } else {
                            SetKartCollisionCallback(b, func_ov001_0218f9a8);
                            b->field0.mFlags |= data_ov001_021a65b0;
                            func_ov001_0218ef30(b);
                        }
                    } else if ((b->field0.mFlags & 1) == 0) {
                        SetKartCollisionCallback(b, func_ov001_0218f9a8);
                        b->field0.mFlags |= data_ov001_021a65b0;
                        func_ov001_0218e7d0(b);
                    }
                }
            }
        }
        if (data_0217d20c == 0) {
            func_02110350(b->field0.mSound);
        } else if (func_02110324() != 0) {
            mobj_emitSfxFromEmitter(&b->field0, 0x22a);
        } else if (data_0217d20c == 4) {
            mobj_emitSfxFromEmitter(&b->field0, 0x22b);
        }
    }
    boss_update(a, b);
}

void ktesa_loadFiles(Unk0218d87c *a) {
    int i;
    Unk02188950 *p;
    MissionRunPrm *a0;

    if (a != NULL) {
        for (i = 0; i < a->field4 && (p = a->field0[i]) != NULL; i++) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(p);
            }
            boss_21870E4(a, p, aKing_teresa_ns, aKing_teresa__0, aKing_teresa_pr);
            LoadMissionRunMapObjectShadow(a, p, aSh_circle_ns_4);
            a0 = p->mPrm;
            SetCollisionOffsetAndExtent(p, a0->field8, a0->fieldC, a0->field240);
            SetShadowOffsetYAndScale(p, 0, 0x19000);
            SetKartCollisionCallback(p, func_ov001_0218f9a8);
            func_ov001_02187cd4(p, 0);
            p->field0.mFlags |= data_ov001_021a65b0;
            p->field2B8 = 3;
        }
    }
}

void ktesa_render(void *a, Unk02188950 *b) {
    boss_render(a, b);
    if (b->fieldA8 == 0) {
        boss_renderShadow(a, b, 0);
        return;
    }
    boss_renderShadow(a, b, 1);
}

void ktesa_setupCollision(void) {
    void *v6 = &boss_onDriverCollide;
    void *v7 = &boss_onItemCollide;
    void *v8 = &boss_collide;
    void *v10 = func_ov001_0219b510(v6, v7, v8, 0x2u, 0x0u, 0x0u, 0x0u);
}

void *ktesa_setupRenderPart(void) {
    return mobj_createRenderPart3d(ktesa_loadFiles, ktesa_render, ktesa_globalPreRender);
}

void *ktesa_setupLogicPart(void) {
    return mobj_createLogicPart(ktesa_globalInitLogic, ktesa_update, NULL);
}
