#include "ITCM/code_01ffcf7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Kart/KartAiCallbacks.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "registers.h"

void col_update(void) {
    s32 i = 0;
    s32 k = 0;
    s32 n;
    s32 t;
    CollisionSlot *e;
    Vec3 *v;
    s32 r;
    u16 f;
    CollisionSlotEnd *x;
    CollisionSlotEnd *y;
    u32 w;
    CollisionSlotEnd *v1;
    CollisionSlotEnd *pa;
    CollisionSlotEnd *pb;
    if (col_sEntryCount > 0) {
        do {
            e = &col_sColEntries[i];
            v = e->mCenterPos;
            r = e->mRadius;
            if (v != NULL) {
                f = e->mFlags;
                if (f & 0x600) {
                    if (f & 0x100) {
                        e->mFlags = f & ~0x100;
                    } else {
                        k++;
                        goto next;
                    }
                }
                k++;
                e->mHighZ = v->z + r;
                e->mLowZ = v->z - r;
                col_sSegRightEndpoints[e->mHighEndIndex].mEndX = (v->x + r) >> 11;
                col_sSegLeftEndpoints[e->mLowEndIndex].mEndX = (v->x - r) >> 11;
            }
        next:
            i++;
        } while (k < col_sEntryCount);
    }
    for (i = 1; i < col_sEntryCount; i++) {
        k = i;
        while ((x = &col_sSegRightEndpoints[k], y = &col_sSegRightEndpoints[k - 1], y->mEndX > x->mEndX) && k >= 1) {
            w = *(u32 *) x;
            *(u32 *) x = *(u32 *) y;
            *(u32 *) y = w;
            v1 = col_sSegLeftEndpoints;
            pa = &v1[x->mOtherEndIndex];
            pb = &v1[y->mOtherEndIndex];
            pa->mOtherEndIndex++;
            pb->mOtherEndIndex--;
            col_sColEntries[pa->field1].mHighEndIndex++;
            col_sColEntries[pb->field1].mHighEndIndex--;
            if (x->field1 == y->mOtherEndIndex) {
                t = x->field1;
                do {
                    t++;
                } while (col_sSegLeftEndpoints[t].mOtherEndIndex < k);
                x->field1 = t;
            }
            if (y->field1 > x->mOtherEndIndex) {
                y->field1 = x->mOtherEndIndex;
            }
            k--;
        }
    }
    for (i = 1; i < col_sEntryCount; i++) {
        k = i;
        while ((x = &col_sSegLeftEndpoints[k], y = &col_sSegLeftEndpoints[k - 1], y->mEndX > x->mEndX) && k >= 1) {
            w = *(u32 *) x;
            *(u32 *) x = *(u32 *) y;
            *(u32 *) y = w;
            col_sSegRightEndpoints[x->mOtherEndIndex].mOtherEndIndex++;
            col_sSegRightEndpoints[y->mOtherEndIndex].mOtherEndIndex--;
            col_sColEntries[x->field1].mLowEndIndex++;
            col_sColEntries[y->field1].mLowEndIndex--;
            if (x->mOtherEndIndex > y->mOtherEndIndex) {
                for (n = x->mOtherEndIndex; n > y->mOtherEndIndex && col_sSegRightEndpoints[n].field1 == k - 1; n--) {
                    col_sSegRightEndpoints[n].field1++;
                }
            } else {
                n = y->mOtherEndIndex;
                while (n > x->mOtherEndIndex && col_sSegRightEndpoints[n].field1 == k) {
                    col_sSegRightEndpoints[n--].field1--;
                }
            }
            k--;
        }
    }
}

void col_queryByColEntry(s32 a, s32 b) {
    CollisionSlot *e;
    s32 c;
    s32 t;
    s32 q;
    s32 u;
    s32 s;
    s32 d;
    s32 f;
    CollisionSlotEnd *y;
    s32 p;
    CollisionSlotEnd *x;
    s32 m;
    s32 h;
    s16 l;
    u32 i;
    CollisionSlot *o;
    u16 g;
    if (a < 0 || a >= 0x100) {
        return;
    }
    e = &col_sColEntries[(s16) a];
    p = e->mHighEndIndex;
    u = e->mLowEndIndex;
    q = u;
    x = col_sSegRightEndpoints;
    y = col_sSegLeftEndpoints;
    s = col_sEntryCount - 1;
    c = x[p].mEndX;
    t = y[u].mEndX;
    d = e->mHighZ;
    f = e->mLowZ;
    if (e->mCenterPos == NULL) {
        gColQueryResultCount = 0;
        return;
    }
    gColQueryResultCount = 0;
    while (p > 7 && x[p - 8].mEndX >= t) {
        p -= 8;
    }
    while (p > 0 && x[p - 1].mEndX >= t) {
        p--;
    }
    m = s - 7;
    while (q < m && y[q + 8].mEndX <= c) {
        q += 8;
    }
    while (q < s && y[q + 1].mEndX <= c) {
        q++;
    }
    h = (s16) q;
    i = x[p].field1;
    l = i;
    if (h < l) {
        return;
    }
    for (;;) {
        if (col_sSegLeftEndpoints[h].mOtherEndIndex >= p && h != u) {
            o = &col_sColEntries[col_sSegLeftEndpoints[h].field1];
            g = o->mFlags;
            if (o->mHighZ < f || o->mLowZ > d || !(g & b) || (g & 0x200)) {
                goto next;
            }
            gColQueryResultEntryIds[gColQueryResultCount] = col_sSegLeftEndpoints[h].field1;
            gColQueryResultFlags[gColQueryResultCount] = g;
            gColQueryResultObjects[gColQueryResultCount] = o->mObject;
            gColQueryResultCount++;
            if (gColQueryResultCount == 0x80) {
                return;
            }
        }
        if (h == 0) {
            return;
        }
    next:
        h--;
        if (h < l) {
            break;
        }
    }
}

s32 mobj_calcVisibilityFlags2d(Vec3 *a, s32 b, s32 c, s32 d, u16 e) {
    s32 r;
    s32 x;
    s32 y;
    s32 z;
    s32 q;
    s32 f;
    s32 g;
    c = (c + b) >> 12;
    z = (a->z - gViewFrustum.mCameraPos.z) >> 12;
    x = (a->x - gViewFrustum.mCameraPos.x) >> 12;
    f = x * x;
    q = z * z + f;
    r = q & ~0xc000001f;
    if (q > d) {
        r |= data_021568f4;
    }
    if (q > c * c) {
        if (e <= 1) {
            return r | 3;
        }
        r |= data_021568f8;
    }
    y = (a->y - gViewFrustum.mCameraPos.y) >> 12;
    if (x * gViewFrustum.mViewDirection.x + y * gViewFrustum.mViewDirection.y + z * gViewFrustum.mViewDirection.z <
        gViewFrustum.mNear - b) {
        return r | 2;
    }
    if (x * gViewFrustum.field20.x + y * gViewFrustum.field20.y + z * gViewFrustum.field20.z > b) {
        return r | 2;
    }
    if (x * gViewFrustum.field2C.x + y * gViewFrustum.field2C.y + z * gViewFrustum.field2C.z > b) {
        return r | 2;
    }
    if (x * gViewFrustum.field38.x + y * gViewFrustum.field38.y + z * gViewFrustum.field38.z > b) {
        return r | 2;
    }
    g = x * gViewFrustum.field44.x;
    if (z * gViewFrustum.field44.z + (y * gViewFrustum.field44.y + g) > b) {
        r |= 2;
    }
    return r;
}

static inline s32 func_01ffd648_inline(ViewFrustum *g) {
    return g->field20.y;
}

s32 mobj_calcVisibilityFlags3d(Vec3 *a, s32 b, s32 c, s32 d, u16 e) {
    Vec3 v;
    s32 r;
    s32 q;
    s32 h;
    c = (c + b) >> 12;
    VEC_Subtract(a, &gViewFrustum.mCameraPos, &v);
    v.x = (a->x - gViewFrustum.mCameraPos.x) >> 12;
    v.z = (a->z - gViewFrustum.mCameraPos.z) >> 12;
    q = v.x * v.x + v.z * v.z;
    r = q & ~0xc000001f;
    if (q > d) {
        r |= data_021568f4;
    }
    if (q > c * c) {
        if (e <= 1) {
            return r | 3;
        }
        r |= data_021568f8;
    }
    v.y = (a->y - gViewFrustum.mCameraPos.y) >> 12;
    h = ((const Vec3 *) &v)->x;
    if (v.y * func_01ffd648_inline(&gViewFrustum) + v.x * gViewFrustum.field20.x + v.z * gViewFrustum.field20.z > b) {
        return r | 2;
    }
    if (h * gViewFrustum.field2C.x + v.y * gViewFrustum.field2C.y + v.z * gViewFrustum.field2C.z > b) {
        r |= 2;
    }
    return r;
}

void AdvanceKartAiHeading(struct KartAi *p, Vec3 *a, Vec3 *b) {
    Kart *q = p->mKart;
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 v6;
    Vec3 v4;
    Vec3 v7;
    Vec3 v5;
    Vec3 v8;
    Vec3 v11;
    Vec3 v10;
    Vec3 v9;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
    BOOL r;
    Vec3 *u;
    Kart *o;
    if (q->mState != KART_STATE_NORMAL) {
        return;
    }
    if (q->field44 & 2) {
        return;
    }
    if (q->field4C & 0x10000000) {
        return;
    }
    r = FALSE;
    enmy_getTargetPosDir(&v0, &v1, p);
    if (p->fieldA8 == 1) {
        u = &q->field12C;
        d = VEC_DotProduct(u, &v1);
        v5.x = v1.x - (s32) (((s64) u->x * d) >> 12);
        v5.y = v1.y - (s32) (((s64) u->y * d) >> 12);
        v5.z = v1.z - (s32) (((s64) u->z * d) >> 12);
        if (vec_dotProduct(&q->field138, &v5) > -0x333) {
            enmy_getTargetPosDir(&v2, &v3, p);
            o = p->mKart;
            r = TRUE;
            VEC_Subtract(&o->mPos, &v2, &v9);
            v9.y = 0;
            driver_getShadowYDirection(o, &v8);
            d = VEC_DotProduct(&v8, &v3);
            v10.x = v3.x - (s32) (((s64) v8.x * d) >> 12);
            v10.y = v3.y - (s32) (((s64) v8.y * d) >> 12);
            v10.z = v3.z - (s32) (((s64) v8.z * d) >> 12);
            vec_crossProduct(&v9, &v10, &v11);
            g = vec_dotProduct(&v8, &v11) > 0 ? 1 : -1;
            q->mHeadingAngle += g * 200;
            goto end;
        }
    }
    if (p->mTurnAngleDegrees > 0x2000) {
        e = ((s64) q->mVelocityLength * *data_0217ae60) >> 12;
        if (e > 0x1000) {
            e = 0x1000;
        }
        driver_getShadowYDirection(q, &v6);
        d = VEC_DotProduct(&v6, a);
        v7.x = a->x - (s32) (((s64) v6.x * d) >> 12);
        v7.y = a->y - (s32) (((s64) v6.y * d) >> 12);
        v7.z = a->z - (s32) (((s64) v6.z * d) >> 12);
        vec_crossProduct(b, &v7, &v4);
        q->mHeadingAngle +=
            (g = vec_dotProduct(&v6, &v4) > 0 ? 1 : -1) *
            ((s32) (((s64) ((s32) (((s64) p->mTurnAngleDegrees * 0xB60B60B60BLL + 0x80000000LL) >> 32)) *
                     (s32) (((s64) e * 0xa4) >> 12)) >>
                    12) >>
             12);
        r = TRUE;
    }
    if ((q->field4C & 0x8000000) && p->mTurnAngleDegrees < 0x46000 && (q->field44 & KART_44_ON_GROUND) &&
        !(q->field48 & 0x8020) && q->mVelocityLength > 0x3000 && p->field90 != 2 && p->fieldA8 == 0) {
        p->fieldC8 += 0x44c;
        p->fieldCA = ((s64) FX_SinCosTable_[(p->fieldC8 >> 4) * 2] * 0xfa + 0x800) >> 12;
        q->mHeadingAngle += (s16) p->fieldCA * p->fieldCC;
        r = TRUE;
    } else {
        p->fieldCA = 0;
        p->fieldC8 = 0;
    }
end:
    if (r == FALSE) {
        return;
    }
    if (g > 0) {
        q->field48 |= KART_48_TURN_LEFT;
    } else {
        q->field48 |= KART_48_TURN_RIGHT;
    }
}

void qrtn_fromAxisAngle(const Vec3 *a, s32 b, Vec4 *c) {
    s32 i = (s32) ((u32) (b << 15) >> 16) >> 4;
    s32 s = FX_SinCosTable_[i * 2];
    c->x = ((s64) a->x * s + 0x800) >> 12;
    c->y = ((s64) a->y * s + 0x800) >> 12;
    c->z = ((s64) a->z * s + 0x800) >> 12;
    c->w = FX_SinCosTable_[i * 2 + 1];
}

s32 qrtn_lookAt(Vec4 *a, const Vec3 *b, const Vec3 *c) {
    Vec3 v;
    s32 r;
    BOOL k = TRUE;
    VEC_CrossProduct(b, c, &v);
    r = FX_Sqrt((VEC_DotProduct(b, c) + 0x1000) << 1);
    *a = Quaternion_Identity;
    if (r <= 0) {
        k = FALSE;
    } else {
        a->x = FX_Div(v.x, r);
        a->y = FX_Div(v.y, r);
        a->z = FX_Div(v.z, r);
        a->w = r >> 1;
    }
    return k;
}

void qrtn_normalize(const Vec4 *a, Vec4 *b) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    w = (s64) a->x * a->x;
    w += (s64) a->y * a->y;
    w += (s64) a->z * a->z;
    w += (s64) a->w * a->w;
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = w;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = w << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    r = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    q = reg_CP_DIV_RESULT;
    t = q * r;
    b->x = (t * a->x + 0x100000000000LL) >> 45;
    b->y = (t * a->y + 0x100000000000LL) >> 45;
    b->z = (t * a->z + 0x100000000000LL) >> 45;
    b->w = (t * a->w + 0x100000000000LL) >> 45;
}
