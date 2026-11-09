#include "Main/Unknown/code_02073904.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"

static inline s32 func_02073904_inline(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(v, n);
}

void UpdateCameraShake(Unk02073904 *p) {
    RandomState64 *r;
    Vec3 a;
    Vec3 b;
    Vec3 d;
    Vec3 g;
    Vec3 e;
    Vec3 f;
    s32 l;
    s32 k;
    s32 h;
    s32 m;
    s32 s;
    s32 i;

    if (GetRaceUpdateFramesMod2() == 0) {
        VEC_Subtract(&p->mPos, &p->mLookAt, &d);
        l = func_02073904_inline(&d, &d);
        if (l != 0) {
            k = data_usa_021656a8;
            r = &gRaceProgress->mLocalRandom;
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            s = MUL_FIXED12_NO_ROUND(data_usa_021656ac, l);
            h = (s16) (u16) (r->mValue >> 52);
            s = MUL_FIXED12_NO_ROUND(s + 0x1000, data_usa_021656c8);
            m = MUL_FIXED12_NO_ROUND(s, (h - 0x800) * 2);
            a.x = MUL_FIXED12_NO_ROUND(p->mSide.x, m);
            a.y = MUL_FIXED12_NO_ROUND(p->mSide.y, m);
            a.z = MUL_FIXED12_NO_ROUND(p->mSide.z, m);
            r = &gRaceProgress->mLocalRandom;
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            h = (s16) (u16) (r->mValue >> 52);
            m = MUL_FIXED12_NO_ROUND(s, (h - 0x800) * 2);
            b.x = MUL_FIXED12_NO_ROUND(p->mUp.x, m);
            b.y = MUL_FIXED12_NO_ROUND(p->mUp.y, m);
            b.z = MUL_FIXED12_NO_ROUND(p->mUp.z, m);
            VEC_Add(&a, &b, &p->mShakeLookAtOffsetGoal);
            r = &gRaceProgress->mLocalRandom;
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            h = (s16) (u16) (r->mValue >> 52);
            m = MUL_FIXED12_NO_ROUND(k, (h - 0x800) * 2);
            a.x = MUL_FIXED12_NO_ROUND(p->mSide.x, m);
            a.y = MUL_FIXED12_NO_ROUND(p->mSide.y, m);
            a.z = MUL_FIXED12_NO_ROUND(p->mSide.z, m);
            r = &gRaceProgress->mLocalRandom;
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            h = (s16) (u16) (r->mValue >> 52);
            m = MUL_FIXED12_NO_ROUND(k, (h - 0x800) * 2);
            b.x = MUL_FIXED12_NO_ROUND(p->mUp.x, m);
            b.y = MUL_FIXED12_NO_ROUND(p->mUp.y, m);
            b.z = MUL_FIXED12_NO_ROUND(p->mUp.z, m);
            VEC_Add(&a, &b, &p->mShakePosOffsetGoal);
        }
    }
    s = data_usa_021656b0;
    VEC_Subtract(&p->mShakePosOffsetGoal, &p->mShakePosOffset, &e);
    e.x = MUL_FIXED12_NO_ROUND(e.x, s);
    e.y = MUL_FIXED12_NO_ROUND(e.y, s);
    e.z = MUL_FIXED12_NO_ROUND(e.z, s);
    VEC_Add(&p->mShakePosOffset, &e, &p->mShakePosOffset);
    s = data_usa_021656a4;
    VEC_Subtract(&p->mShakeLookAtOffsetGoal, &p->mShakeLookAtOffset, &f);
    f.x = MUL_FIXED12_NO_ROUND(f.x, s);
    f.y = MUL_FIXED12_NO_ROUND(f.y, s);
    f.z = MUL_FIXED12_NO_ROUND(f.z, s);
    VEC_Add(&p->mShakeLookAtOffset, &f, &p->mShakeLookAtOffset);
    i = -data_usa_021656cc[p->mShakeKind - 1];
    g.x = MUL_FIXED12_NO_ROUND(p->mShakeLookAtOffset.x, i);
    g.y = MUL_FIXED12_NO_ROUND(p->mShakeLookAtOffset.y, i);
    g.z = MUL_FIXED12_NO_ROUND(p->mShakeLookAtOffset.z, i);
    VEC_Add(&g, &p->mShakeLookAtCounterOffset, &p->mShakeLookAtCounterOffset);
    s = data_usa_021656bc;
    p->mShakeLookAtCounterOffset.x = MUL_FIXED12_NO_ROUND(p->mShakeLookAtCounterOffset.x, s);
    p->mShakeLookAtCounterOffset.y = MUL_FIXED12_NO_ROUND(p->mShakeLookAtCounterOffset.y, s);
    p->mShakeLookAtCounterOffset.z = MUL_FIXED12_NO_ROUND(p->mShakeLookAtCounterOffset.z, s);
}
