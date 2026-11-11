#include "Main/Unknown/code_0209df00.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0209eb54.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02108e38.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02077bc0.h"

void *CreatePuddleDrawList(void) {
    return CreateMapObjectDrawList2(CreatePuddle, DrawPuddle, SetupDrawPuddle);
}

void InitFireball2(Fireball2 *a) {
    a->mMapObject.mFlags |= data_usa_021565ec;
    a->mRowCount = a->mMapObject.mCourseMapRow->mUnk_28;
    a->mRowElementCount = a->mMapObject.mCourseMapRow->mUnk_2e + 1;
    CreateMapObjectSoundSourceFalloff2(&a->mMapObject);
    a->mMapObject.mFlags &= ~1;
    a->mMapObject.mFlags &= ~2;
    a->mMapObject.mFlags &= ~8;
    a->mMapObject.mAlpha = 0x1f;
}

u8 CollideKartWithFireball2(Fireball2 *a, Kart *b, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (a->mKartHitTimers[b->mIndex] == 0) {
        if (b->mItemEffect == 1 || b->mItemEffect == 3) {
            a->mMapObject.mDistanceSquaredAndFlags |= data_usa_021565e8;
        }
        StartSoundIfKartStarOrKiller(&a->mMapObject, b);
    }
    a->mKartHitTimers[b->mIndex] = 0xb;
    return v;
}

static inline BOOL func_0209df84_inline(Kart *p, Fireball2 *b, s32 t) {
    s32 y;
    s32 x;
    s32 z;
    s32 u;

    u = -t;
    z = p->mPos.z - b->mMapObject.mPos.z;
    if (z > t || z < u) {
        return FALSE;
    }
    x = p->mPos.x - b->mMapObject.mPos.x;
    if (x > t || x < u) {
        return FALSE;
    }
    y = p->mPos.y - b->mMapObject.mPos.y;
    if (y > t || y < u) {
        return FALSE;
    }
    return (s64) x * x + (s64) y * y + (s64) z * z < (s64) t * t;
}

BOOL IsPosNearFireball2(Fireball2 *a, Vec3 *b, s32 c) {
    s32 i;
    s32 d;
    s32 e;
    s32 f;

    for (i = 0; i < a->mRowCount; i++) {
        d = b->x - a->mElements[i][0].mUnk_00.x;
        e = b->y - a->mElements[i][0].mUnk_00.y;
        f = b->z - a->mElements[i][0].mUnk_00.z;
        if ((s64) d * d + (s64) e * e + (s64) f * f < (s64) (c + 0xf000) * (c + 0xf000)) {
            return TRUE;
        }
    }
    return FALSE;
}

void CreateFireball2(MapObjectList *a) {
    gFireball2 = CreateMapObjectModelNsbmd(a, gFireball2NsbmdName);
    SetMapObjectModelPolygonId(gFireball2, 0x3f);
    a->mSortByDistance = 1;
}

void SetupDrawFireball2(void *a) {
    QueueMapObjectModelMaterial(a, gFireball2);
}

void DrawFireball2(void *a, Fireball2 *b) {
    s32 s1;
    s32 s2;
    s32 s3;
    MtxFx33 m1;
    MtxFx33 m2;
    MtxFx33 m3;
    s32 i;
    s32 c;
    s32 j;
    s32 f;
    s32 g;
    Camera *q;

    q = GetCurrentCamera();
    c = Vec3DotUnrounded(&b->mMapObject.mMatrix.mRows[0], &q->mForward);
    for (i = 0; i < b->mRowCount; i++) {
        if (c >= 0) {
            f = 1;
        } else {
            f = 0;
        }
        if (b->mElements[i][0].mUnk_0c >= 0x4000 && b->mElements[i][0].mUnk_0c < 0xc000) {
            g = 1;
        } else {
            g = 0;
        }
        if (f ^ g) {
            for (j = 0; j < b->mRowElementCount; j++) {
                s1 = 0x1e;
                NNS_G3dGeBufferOP_N(0x14, &s1, 1);
                NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&b->mElements[i][j].mUnk_00), 0xc);
                if (b->mElements[i][j].mUnk_0e != 0) {
                    MTX_RotZ33_(&m1, FX_SinIdx(b->mElements[i][j].mUnk_0e), FX_CosIdx(b->mElements[i][j].mUnk_0e));
                    NNS_G3dGeBufferOP_N(0x1a, &m1, 9);
                }
                NNS_G3dGeBufferOP_N(0x1b, &b->mMapObject.mScale, 3);
                SetMapObjectModelPolygonId(gFireball2, AllocPolygonIdWrapping());
                DrawMapObjectModel(a, gFireball2, b);
            }
        }
    }
    if (b->mRowElementCount > 1) {
        s2 = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &s2, 1);
        NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&b->mCenterPos), 0xc);
        if (b->mCenterRotationAngle != 0) {
            MTX_RotZ33_(&m2, FX_SinIdx(b->mCenterRotationAngle), FX_CosIdx(b->mCenterRotationAngle));
            NNS_G3dGeBufferOP_N(0x1a, &m2, 9);
        }
        NNS_G3dGeBufferOP_N(0x1b, &b->mMapObject.mScale, 3);
        SetMapObjectModelPolygonId(gFireball2, AllocPolygonIdWrapping());
        DrawMapObjectModel(a, gFireball2, b);
    }
    for (i = 0; i < b->mRowCount; i++) {
        if (c >= 0) {
            f = 1;
        } else {
            f = 0;
        }
        if (b->mElements[i][0].mUnk_0c >= 0x4000 && b->mElements[i][0].mUnk_0c < 0xc000) {
            g = 1;
        } else {
            g = 0;
        }
        if ((f ^ g) == 0) {
            for (j = b->mRowElementCount - 1; j >= 0; j--) {
                s3 = 0x1e;
                NNS_G3dGeBufferOP_N(0x14, &s3, 1);
                NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&b->mElements[i][j].mUnk_00), 0xc);
                if (b->mElements[i][j].mUnk_0e != 0) {
                    MTX_RotZ33_(&m3, FX_SinIdx(b->mElements[i][j].mUnk_0e), FX_CosIdx(b->mElements[i][j].mUnk_0e));
                    NNS_G3dGeBufferOP_N(0x1a, &m3, 9);
                }
                NNS_G3dGeBufferOP_N(0x1b, &b->mMapObject.mScale, 3);
                SetMapObjectModelPolygonId(gFireball2, AllocPolygonIdWrapping());
                DrawMapObjectModel(a, gFireball2, b);
            }
        }
    }
}

void InitFireball2Objects(MapObjectList *p) {
    s32 i;
    s32 j;
    s32 k;
    s16 v;
    float f;
    u64 t;
    Fireball2 *e;
    RandomState64 *r;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mMapObjectCount && (e = p->mMapObjects[i]) != NULL; i++) {
        v = e->mMapObject.mCourseMapRow->mUnk_2a;
        if (v > 0) {
            f = 0.5f + (v << 12);
        } else {
            f = (v << 12) - 0.5f;
        }
        e->mRadius = f;
        e->mRowAnglePerFrame = (e->mMapObject.mCourseMapRow->mUnk_2c * 0x16c) / 100;
        e->mRowAngleSpacing = 0x10000 / e->mRowCount;
        e->mElementRadiusSpacing = e->mRadius / e->mRowElementCount;
        r = GetMapObjectRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        t = r->mValue >> 32;
        e->mCenterRotationAngle = (t * 0x10000) >> 32;
        for (j = 0; j < e->mRowElementCount; j++) {
            for (k = 0; k < e->mRowCount; k++) {
                r = GetMapObjectRandom();
                r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
                t = r->mValue >> 32;
                e->mElements[k][j].mUnk_0e = (t * 0x10000) >> 32;
            }
        }
    }
}

void UpdateFireball2(void *a, Fireball2 *b) {
    s32 i;
    s32 j;
    s32 n;
    s32 d;
    u16 w;
    Kart *p;
    NNSSndSeqPlayer **h;
    Vec3 v;

    n = b->mRadius;
    b->mCenterPos = b->mMapObject.mPos;
    if (b->mRowElementCount == 1) {
        p = GetKart((u16) gRaceSetup->mEntryIndex);
        if (func_0209df84_inline(p, b, n - 0xf000) != FALSE) {
            VEC_Subtract(&p->mPos, &b->mMapObject.mPos, &v);
            d = Vec3DotUnrounded(&v, &b->mMapObject.mMatrix.mRows[2]);
            if ((b->mEntryKartAxisDistance < 0 && d > 0) || (b->mEntryKartAxisDistance > 0 && d < 0)) {
                StopSndHandleSlots7To11();
                h = GetSndHandleSlot(7);
                if ((data_0217c780 & 1) && data_0217d084.mSeqStartEnabled != 0) {
                    if (h[0] != NULL) {
                        NNS_SndPlayerStopSeq(h, 0);
                    }
                    if (h[0] != NULL) {
                        NNS_SndPlayerStopSeq(h, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(h, 0, 0x1c2);
                }
                b->mEntryKartAxisDistance = 0;
            } else {
                b->mEntryKartAxisDistance = d;
            }
        } else {
            b->mEntryKartAxisDistance = 0;
        }
    }
    if (b->mRowElementCount > 1) {
        b->mCenterRotationAngle = b->mCenterRotationAngle + 0x51e;
    }
    for (i = 0; i < b->mRowElementCount; i++) {
        w = b->mRowAngle;
        for (j = 0; j < b->mRowCount; j++) {
            w = w + b->mRowAngleSpacing;
            b->mElements[j][i].mUnk_0c = w;
            VEC_MultAdd(MUL_FIXED12_NO_ROUND(n, FX_CosIdx(w)), &b->mMapObject.mMatrix.mRows[0], &b->mMapObject.mPos,
                        &b->mElements[j][i].mUnk_00);
            VEC_MultAdd(MUL_FIXED12_NO_ROUND(n, FX_SinIdx(w)), &b->mMapObject.mMatrix.mRows[1],
                        &b->mElements[j][i].mUnk_00, &b->mElements[j][i].mUnk_00);
            b->mElements[j][i].mUnk_0e = b->mElements[j][i].mUnk_0e + 0x51e;
        }
        n = n - b->mElementRadiusSpacing;
    }
    b->mRowAngle = b->mRowAngle - b->mRowAnglePerFrame;
    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        if (b->mKartHitTimers[i] > 0) {
            b->mKartHitTimers[i] = b->mKartHitTimers[i] - 1;
        }
    }
    StartMapObjectSoundWhileRequested(&b->mMapObject, 0x160);
}

void CreateFireball2KindData(void) {
    CreateMapObjectKindDataWithSound(CollideKartWithFireball2, NULL, IsPosNearFireball2, 0, 0, 0x18d);
}

void *CreateFireball2DrawList(void) {
    return CreateMapObjectDrawList2(CreateFireball2, DrawFireball2, SetupDrawFireball2);
}

void *CreateFireball2UpdateList(void) {
    return CreateMapObjectUpdateList(InitFireball2Objects, UpdateFireball2, NULL);
}
