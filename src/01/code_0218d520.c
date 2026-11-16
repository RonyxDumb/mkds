#include "01/code_0218d520.h"
#include "01/code_02187d14.h"
#include "01/code_02187eb0.h"
#include "01/code_02188230.h"
#include "01/code_02188cd8.h"
#include "01/code_02187000.h"
#include "01/code_02187e78.h"
#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_021000d0.h"

void func_ov001_0218dc20(Unk02188950 *a) {
    Unk0218dabc *r7 = a->fieldA4;
    int r5;
    u16 ang = (r7->field184 + 0x8000);
    int idx;

    switch (a->fieldA8) {
        case 1:
            r5 = a->mPrm->fieldC0;
            break;
        case 2:
            r5 = a->mPrm->fieldC4;
            break;
        case 3:
            r5 = a->mPrm->fieldC8;
            break;
        case 4:
            r5 = a->mPrm->fieldCC;
            break;
    }
    idx = (ang >> 4) * 2;
    a->field0.mPos.x = r7->field4 + (s32) (((s64) r5 * FX_SinCosTable_[idx]) >> 12);
    a->field0.mPos.z = a->fieldA4->fieldC + (s32) (((s64) r5 * FX_SinCosTable_[idx + 1]) >> 12);
}

void func_ov001_0218dba8(Unk02188950 *a) {
    int diff;
    int step;
    int limit;
    s32 cur;

    a->field13C = a->field13C - 1;
    if (a->field13C <= 0) {
        a->field13C = 0;
        cur = a->mAngle;
        diff = (u16) (a->fieldA4->field184 - cur);
        if (diff > 0x8000) {
            diff -= 0x10000;
        }
        limit = a->mAnglePerCall;
        step = diff < -limit ? -limit : (diff > limit ? limit : diff);
        a->mAngle = (u16) (cur + step);
        a->mMoveAngle = a->mAngle;
    }
}

void func_ov001_0218dadc(Unk02188950 *a) {
    Unk0218dabc *r7 = a->fieldA4;
    int r5;
    u16 ang = (r7->field184 + 0x8000);
    int idx;

    switch (a->fieldA8) {
        case 1:
            r5 = a->mPrm->fieldC0;
            break;
        case 2:
            r5 = a->mPrm->fieldC4;
            break;
        case 3:
            r5 = a->mPrm->fieldC8;
            break;
        case 4:
            r5 = a->mPrm->fieldCC;
            break;
    }
    idx = (ang >> 4) * 2;
    a->field0.mPos.x = r7->field4 + (s32) (((s64) r5 * FX_SinCosTable_[idx]) >> 12);
    a->field0.mPos.y = a->fieldA4->field8;
    a->field0.mPos.z = a->fieldA4->fieldC + (s32) (((s64) r5 * FX_SinCosTable_[idx + 1]) >> 12);
}

void func_ov001_0218dabc(Unk02188950 *a) {
    a->mAngle = a->fieldA4->field184;
    a->mMoveAngle = a->mAngle;
}

void func_ov001_0218da1c(Unk02188950 *a) {
    ReleaseEffects(a);
    StartEffectAtOffset(a, 0, a->mOffset.y >> 4, 0, 0x427, 0xf);
    StartEffectAtOffset(a, 0, a->mOffset.y >> 4, 0, 0x426, 0xf);
    mobj_emitSfxFromEmitter2(&a->field0, 0x24d);
    func_ov001_02188230(a);
    if (func_ov001_02188220(a) == 2) {
        mobj_emitSfxFromEmitter2(&a->field0, 0x24c);
    } else if (func_ov001_02188220(a) >= 3) {
        a->fieldAC = 0;
    }
    mobj_setModelNsbtpFrame(a->mNsbmd, func_ov001_02188220(a));
}

void func_ov001_0218d9cc(Unk02188950 *a) {
    Unk0218d87c *list;
    int i;
    Unk02188950 *q;

    list = mobj_getLogicPartForObjectId(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->field4 && (q = list->field0[i]) != NULL; i++) {
            StartStateFrameCountCallback(q, (q->fieldA8 * 15), (UnkFunc *) func_ov001_0218da1c);
        }
    }
    func_ov001_0218da1c(a);
}

void func_ov001_0218d950(Unk02188950 *a) {
    s32 prod;
    float f;
    ModelAnimationView *s;

    func_ov001_02187218(a, 1, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->field88, a->mPrm->field8C);
    prod = a->mPrm->fieldD0 * a->fieldA8;
    if (prod > 0) {
        f = 0.5f + (prod << 12);
    } else {
        f = (prod << 12) - 0.5f;
    }
    s = a->mNsbmd->mNsbcaAnimation;
    s->fieldC = f;
    *s->field1C[s->field1A] = s->fieldC;
}

void func_ov001_0218d8f4(Unk02188950 *a, int b) {
    Unk0218d87c *list;
    int i;

    list = mobj_getLogicPartForObjectId(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->field4 && list->field0[i] != NULL; i++) {
            StartAnimationNoEndCallback(a, a->mPrm->field88, (a->mPrm->field8C * b / 100));
        }
    }
}

void func_ov001_0218d87c(Unk02188950 *a, int b) {
    Unk0218d87c *list;
    int i;
    Unk02188950 *q;

    list = mobj_getLogicPartForObjectId(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->field4 && (q = list->field0[i]) != NULL; i++) {
            q->field13C = q->mPrm->fieldD8 * q->fieldA8 * 100 / b;
            q->mAnglePerCall = a->mPrm->fieldD4 * b / 100;
        }
    }
}

void func_ov001_0218d824(Unk02188950 *b, int c) {
    MissionRunPrm *a;

    a = b->mPrm;
    SetSpeedTargetAndPerCall(b, (a->field90 * c / 100), a->field94);
    a = b->mPrm;
    func_ov001_02188c48(b, a->field98 * c / 100, a->field9C);
    SetAnglePointAndMoveAnglePoint(b, &GetNextGroupEntry(b)->mPos);
}

void func_ov001_0218d800(Unk02188950 *a) {
    a->field150 = 1;
    StartAnimationNoEndCallback(a, a->mPrm->field88, a->mPrm->field8C);
}

int func_ov001_0218d520(Unk02188950 *a) {
    int r4;
    s32 t;
    s32 *v;

    if (IsPointInRange(a, &GetCurrentGroupEntry(a)->mPos, a->mPrm->fieldA0, 0)) {
        if (mgcnt_getDriverBalloonShineCount(gRaceMultiConfig->mEntryIndex) <= 1) {
            r4 = 0x1000 - a->mPrm->fieldAC;
            t = func_ov001_02187f38(a);
            r4 = (((s64) t * r4) >> 12);
        } else if (mgcnt_getDriverBalloonShineCount(gRaceMultiConfig->mEntryIndex) <= 2) {
            r4 = 0x1000 - a->mPrm->fieldA8;
            t = func_ov001_02187f38(a);
            r4 = (((s64) t * r4) >> 12);
        } else {
            r4 = func_ov001_02187f38(a);
        }
        if (func_ov001_02187f7c(a) >= 1) {
            func_ov001_0218d9cc(a);
        }
        if ((gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_hasWinnerBeenDecided() : 0) == FALSE && a->fieldA8 == 0 &&
            func_ov001_021871f8(a, 3) != 0) {
            if (GetEntryKartInAngleRange(a, a->mPrm->field120, a->mPrm->field124, a->mPrm->field128)) {
                a->fieldA8 = a->mPrm->field12C;
                a->field150 = 3;
                StartAnimationWithEndCallback(a, a->mPrm->field118, a->mPrm->field11C, (UnkFunc *) func_ov001_0218d800);
                r4 -= a->mPrm->field130;
                mobj_emitSfxFromEmitter2(&a->field0, 0x24b);
            } else if (GetEntryKartInAngleRange(a, a->mPrm->field10C, a->mPrm->field110, a->mPrm->field114)) {
                a->fieldA8 = a->mPrm->field12C;
                a->field150 = 3;
                StartAnimationWithEndCallback(a, a->mPrm->field104, a->mPrm->field108, (UnkFunc *) func_ov001_0218d800);
                r4 -= a->mPrm->field130;
                mobj_emitSfxFromEmitter2(&a->field0, 0x24b);
            }
        }
        func_ov001_0218d824(a, r4);
        func_ov001_0218d87c(a, r4);
        IncrementEntryIndex(a);
        if (a->mEntryIndex == 0) {
            IncrementEntryGroupIndex(a, 4);
        }
    }
    if (a->fieldA8 > 0) {
        a->fieldA8 = a->fieldA8 - 1;
    }
    if (func_ov001_021871f8(a, 5)) {
        if (func_ov001_02188220(a) == 2) {
            a->field140 = a->field140 + 1 >= 6 ? 0 : a->field140 + 1;
            if (a->field140 == 0) {
                StartEffectAtOffset(a, 0, 0, 0, 0x3f9, 0x1c);
            }
            a->field144 = a->field144 + 1 >= 0x12 ? 0 : a->field144 + 1;
            if (a->field144 == 0) {
                mobj_emitSfxFromEmitter2(&a->field0, 0x24f);
            }
        } else if (func_ov001_02188220(a) == 1) {
            a->field140 = a->field140 + 1 >= 0x12 ? 0 : a->field140 + 1;
            if (a->field140 == 0) {
                StartEffectAtOffset(a, 0, 0, 0, 0x3f8, 0x1c);
                mobj_emitSfxFromEmitter2(&a->field0, 0x24e);
            }
        }
    }
    return 0;
}
