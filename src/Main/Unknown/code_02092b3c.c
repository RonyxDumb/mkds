#include "Main/Unknown/code_02092b3c.h"
#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_020ac000.h"

#include "Main/Course/Basabasa.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Course/ShineBalloon.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_021000d0.h"

void baspw_init(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = value0;
    value0 = MAP_OBJECT_KIND_BASABASA;
    value1 = 8u;
    mobj_createSubObjects(value0, value1, (void *) value2);
}

static inline u32 func_02092b5c_inline(u32 n) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = mobj_getRng1();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return ((mapObjectRandom->mValue >> 32) * n) >> 32;
}

static inline u16 func_02092b5c_inline_2(u32 n) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = mobj_getRng1();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return (u32) (((mapObjectRandom->mValue >> 32) * n) >> 32);
}

void baspw_globalInitLogic(MapObjectList *mapObjectList) {
    s32 i;
    Unk020919e8 *p;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (p = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (p->field0.mFlags & 0x800) {
            p->fieldA4 = (u16) (func_02092b5c_inline_2(25) + 200);
        }
    }
}

static inline s64 func_02092b5c_inline_4(const Vec3 *a, const Vec3 *b) {
    s32 v1;
    s32 v2;

    v1 = a->x - b->x;
    v2 = a->z - b->z;
    return (s64) v1 * v1 + (s64) v2 * v2;
}

static inline BOOL func_02092b5c_inline_3(Unk020919e8 *p, s32 k) {
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
        if (func_02092b5c_inline_4(&kart->mPos, &p->field0.mPos) >= 0x15f900000000LL) {
            continue;
        }
        d = FX_Atan2Idx(kart->mPos.x - p->field0.mPos.x, kart->mPos.z - p->field0.mPos.z) - k;
        if (d < -0x1f40) {
            continue;
        }
        if (d <= 0x1f40) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline void func_02092b5c_inline_5(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x - 0x5000 + func_02092b5c_inline(0xa000);
    v->y = y - 0x5000 + func_02092b5c_inline(0xa000);
    v->z = z - 0x28000 + func_02092b5c_inline(0x50000);
}

s16 baspw_FX_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

s32 baspw_FX_TRUNC_MUL(s32 a, s32 b) {
    return ((s64) a * b) >> 12;
}

s16 baspw_FX_CosIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2 + 1];
}

void baspw_update(void *a, Unk020919e8 *p) {
    s32 i;
    s32 horizontalSpeed;
    u16 k;
    s32 n;
    Vec3 basabasaPos;
    Vec3 basabasaVelocity;

    switch (p->fieldAC) {
        case 0:
            if (race_getCameraField250() == 2) {
                p->fieldAC = 1;
                return;
            }
            if (p->field0.mFlags & 0x800) {
                if (p->fieldA4-- <= 0) {
                    p->fieldA4 = 4;
                    p->fieldAC = 1;
                }
                return;
            }
            if (func_02092b5c_inline_3(p, p->field0.mAngle) != FALSE) {
                p->fieldA4 = 4;
                p->fieldAC = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (p->fieldA0 == 0x14) {
        for (i = 0; i < 2; i++) {
            func_02092b5c_inline_5(&basabasaPos, p->field0.mPos.x, p->field0.mPos.y + 0x23000, p->field0.mPos.z);
            k = p->field0.mAngle;
            horizontalSpeed = kan64_mobj_getRandom32(mobj_getRng1(), 0x1000) + 0x2000;
            k = k - 0xbb8 + sub_2046524(mobj_getRng1(), 0x1770);
            basabasaVelocity.x = baspw_FX_TRUNC_MUL(horizontalSpeed, baspw_FX_SinIdx(k));
            basabasaVelocity.y = kan64_mobj_getRandom32(mobj_getRng1(), 0x400) - 0xa00;
            basabasaVelocity.z = baspw_FX_TRUNC_MUL(horizontalSpeed, baspw_FX_CosIdx(k));
            if (i == 0 && p->fieldA8 == 0) {
                basa_spawn(0x8c, &basabasaPos, &basabasaVelocity, 0xf, 1, i == 0 ? 2 : 0);
            } else {
                basa_spawn(0x8c, &basabasaPos, &basabasaVelocity, 0xf, 0, i == 0 ? 2 : 0);
            }
        }
        p->fieldA8 += 1;
        if (p->fieldA8 >= 3) {
            p->fieldA8 = 0;
        }
    }
    n = p->fieldA0 + 1;
    if (n >= 0x32) {
        n = 0;
    }
    p->fieldA0 = n;
    if (p->fieldA0 != 0) {
        return;
    }
    if (p->fieldA4-- > 0) {
        return;
    }
    p->fieldA8 = 0;
    p->fieldAC = 0;
    if (p->field0.mFlags & 0x800) {
        p->fieldA4 = (u16) (func_02092b5c_inline_2(25) + 200);
    }
}

void baspw_setupLogicPart(void) {
    mobj_createLogicPart(baspw_globalInitLogic, baspw_update, NULL);
}
