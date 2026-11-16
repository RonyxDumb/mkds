#include "Main/Unknown/code_020918a8.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Course/Basabasa.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_02077bc0.h"

static inline u32 func_020919e8_inline(u32 n) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = mobj_getRng1();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return ((mapObjectRandom->mValue >> 32) * n) >> 32;
}

static inline u16 func_020919e8_inline_2(u32 n) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = mobj_getRng1();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return (u32) (((mapObjectRandom->mValue >> 32) * n) >> 32);
}

static inline void func_020919e8_inline_3(Unk020919e8 *p, s32 n) {
    Unk0210b7a8 s;
    s32 v;

    if (p->mUnk_00.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (p->mUnk_00.mFarDistanceSquared == gSfxParams[2].mUnk_20) {
        v = 2;
    } else if (p->mUnk_00.mFarDistanceSquared == gSfxParams[3].mUnk_20) {
        v = 3;
    } else {
        v = 4;
    }
    s.mSoundId = n;
    s.mPositionSource = &p->mUnk_00.mPos;
    s.mUnk_08 = v;
    s.mDistanceSquared = mobj_calcXZCamDist(&p->mUnk_00.mPos);
    func_0210b7a8(&s);
}

void kan64_loadModel(void *a) {
    kan64_sModel = mobj_loadModel(a, aKanoke_64_nsbm);
    mobj_loadNsbcaAnim(kan64_sModel, aKanoke_64_nsbc);
}

void kan64_render(void *a, Unk020919e8 *p) {
    s32 w;

    mobj_setModelNsbcaFrame(kan64_sModel, p->mUnk_a0);
    w = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &w, 1);
    p->mUnk_00.mMatrix.mUnk_00[3].x = p->mUnk_00.mPos.x >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].y = p->mUnk_00.mPos.y >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].z = p->mUnk_00.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &p->mUnk_00.mMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &p->mUnk_00.mScale, 3);
    mobj_renderModel(a, kan64_sModel, p);
}

void kan64_globalInitLogic(MapObjectList *mapObjectList) {
    s32 i;
    Unk020919e8 *p;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (p = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (p->mUnk_00.mFlags & 0x800) {
            p->mUnk_a4 = (u16) (func_020919e8_inline_2(25) + 200);
        }
    }
}

// Returns a random value below b (0 when b is 0), advancing the generator a.
u32 kan64_mobj_getRandom32(RandomState64 *randomState64, u32 limit) {
    if (limit == 0) {
        return 0;
    }
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    if (limit == 0) {
        return randomState64->mValue >> 32;
    }
    return ((randomState64->mValue >> 32) * limit) >> 32;
}

s16 kan64_FX_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

s32 kan64_FX_TRUNC_MUL(s32 a, s32 b) {
    return ((s64) a * b) >> 12;
}

static inline s64 func_020919e8_inline_5(const Vec3 *a, const Vec3 *b) {
    s32 v1;
    s32 v2;

    v1 = a->x - b->x;
    v2 = a->z - b->z;
    return (s64) v1 * v1 + (s64) v2 * v2;
}

static inline BOOL func_020919e8_inline_4(Unk020919e8 *p, s32 k) {
    s32 i;
    BOOL f;
    s32 d;
    Kart *kart;

    for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
        f = FALSE;
        if (gRaceMultiConfig->mCurrentEntries[(u16) i].mPlayer.mKind <= 3 &&
            ((1 << gRaceMultiConfig->mCurrentEntries[(u16) i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            f = TRUE;
        }
        if (f == FALSE && i != gRaceMultiConfig->mEntryIndex) {
            continue;
        }
        kart = driver_getById((u16) i);
        if (func_020919e8_inline_5(&kart->mPos, &p->mUnk_00.mPos) >= 0x225510000000LL) {
            continue;
        }
        d = FX_Atan2Idx(kart->mPos.x - p->mUnk_00.mPos.x, kart->mPos.z - p->mUnk_00.mPos.z) - k;
        if (d < -0x1f40) {
            continue;
        }
        if (d <= 0x1f40) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline void func_020919e8_inline_6(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x - 0x5000 + func_020919e8_inline(0xa000);
    mobj_getRng1();
    v->y = y;
    v->z = z - 0x28000 + func_020919e8_inline(0x50000);
}

s16 kan64_FX_CosIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2 + 1];
}

void kan64_update(void *a, Unk020919e8 *p) {
    s32 i;
    s32 horizontalSpeed;
    u16 k;
    s32 nextFrameIndex;
    Vec3 basabasaPos;
    Vec3 basabasaVelocity;

    switch (p->mUnk_ac) {
        case 0:
            if (race_getCameraField250() == 2) {
                p->mUnk_ac = 1;
                return;
            }
            if (p->mUnk_00.mFlags & 0x800) {
                if (p->mUnk_a4-- <= 0) {
                    p->mUnk_a4 = 8;
                    p->mUnk_ac = 1;
                }
                return;
            }
            if (func_020919e8_inline_4(p, p->mUnk_00.mAngle) != FALSE) {
                p->mUnk_a4 = 8;
                p->mUnk_ac = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (p->mUnk_a0 == 10) {
        for (i = 0; i < 3; i++) {
            func_020919e8_inline_6(&basabasaPos, p->mUnk_00.mPos.x, p->mUnk_00.mPos.y + 0x19000, p->mUnk_00.mPos.z);
            k = p->mUnk_00.mAngle;
            horizontalSpeed = kan64_mobj_getRandom32(mobj_getRng1(), 0x1000) + 0x800;
            k = k - 0x3e8 + func_02046524(mobj_getRng1(), 0x7d0);
            basabasaVelocity.x = kan64_FX_TRUNC_MUL(horizontalSpeed, kan64_FX_SinIdx(k));
            basabasaVelocity.y = kan64_mobj_getRandom32(mobj_getRng1(), 0x400) + 0x2200;
            basabasaVelocity.z = kan64_FX_TRUNC_MUL(horizontalSpeed, kan64_FX_CosIdx(k));
            if (i == 0 && p->mUnk_a8 == 0) {
                basa_spawn(0x50, &basabasaPos, &basabasaVelocity, 0x28, 1, i == 0 ? 3 : 0);
            } else {
                basa_spawn(0x50, &basabasaPos, &basabasaVelocity, 0x28, 0, i == 0 ? 3 : 0);
            }
        }
        p->mUnk_a8 += 1;
        if (p->mUnk_a8 >= 3) {
            p->mUnk_a8 = 0;
        }
    }
    nextFrameIndex = p->mUnk_a0 + 1;
    if (nextFrameIndex >= mobj_getModelNsbcaFrameCount(kan64_sModel)) {
        nextFrameIndex = 0;
    }
    p->mUnk_a0 = nextFrameIndex;
    if (p->mUnk_a0 == 0) {
        if (p->mUnk_a4-- <= 0) {
            p->mUnk_a8 = 0;
            p->mUnk_ac = 0;
            if (p->mUnk_00.mFlags & 0x800) {
                p->mUnk_a4 = (u16) (func_020919e8_inline_2(25) + 200);
            }
        }
    }
    if (p->mUnk_a0 != 0) {
        return;
    }
    func_020919e8_inline_3(p, 0x188);
}

void kan64_setupRenderPart(void) {
    mobj_createRenderPart3d(kan64_loadModel, kan64_render, NULL);
}

void kan64_setupLogicPart(void) {
    mobj_createLogicPart(kan64_globalInitLogic, kan64_update, NULL);
}

void cow_loadModel(void *a) {
    cow_sModel = mobj_loadTexAnimBillboardModel(a, aCow_nsbmd, aCow_nsbtp);
    mobj_setModelPolygonIdAll(cow_sModel, 0x3f);
}

void cow_globalPreRender(void *a) {
    mobj_bbModelApplyMaterial(a, cow_sModel);
}

void cow_render(void *a, Unk020919e8 *b) {
    s32 w;

    w = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &w, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&b->mUnk_00.mPos), 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &b->mUnk_00.mScale, 3);
    mobj_setModelNsbtpFrame(cow_sModel, b->mUnk_00.mCourseMapRow->mUnk_28);
    mobj_renderModel(a, cow_sModel, b);
}

void cow_setupRenderPart(void) {
    mobj_createRenderPart2d(cow_loadModel, cow_render, cow_globalPreRender);
}
