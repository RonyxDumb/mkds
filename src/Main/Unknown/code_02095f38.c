#include "Main/Unknown/code_02095f38.h"
#include "Main/Unknown/code_0209756c.h" // Flipper
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bc5c.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_02100000.h"

#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "01/code_0218155c.h"

u32 flip_handleBallHit(u32 a) {
    Flipper *flipper;
    flipper = mobj_getInstanceByIdx(mobj_getLogicPartForObjectId(MAP_OBJECT_KIND_FLIPPER), a);
    flipper->fieldEBC = 0xaa;
    return 1;
}

void poo_init(MapObject *mapObject) {
    mapObject->mFlags |= data_021564c0;
}

u32 poo_onDriverCollide(CoverPooHole *coverPooHole, Kart *kart, u8 *b, u8 *c) {
    s32 state;
    s32 itemEffect;
    u32 v2 = *b;
    Vec3 effectPosition;
    s32 t;
    u8 kartMask = 1 << kart->mIndex;
    Unk0210b7a8 s;
    u8 v3 = *c;
    Unk0210b7a8 s2;
    if (v2 == 3 || v2 == 4) {
        itemEffect = kart->mItemEffect;
        if (itemEffect != 1) {
            if (coverPooHole->mState == 4 || (coverPooHole->mState == 5 && coverPooHole->fieldA0 > 0x7800)) {
                coverPooHole->field0.field10.x = 0;
                coverPooHole->field0.field10.y = 0x3800;
                coverPooHole->field0.field10.z = 0;
                return v3;
            }
        }
        if ((((const CoverPooHole *) coverPooHole)->field108 & kartMask) == 0) {
            state = coverPooHole->mState;
            if (state == 0 || state == 3) {
                coverPooHole->field108 = coverPooHole->field108 | kartMask;
                if (gRaceMultiConfig->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_GHOST) {
                    if ((coverPooHole->field0.mDistanceSquaredAndFlags & 4) == 0) {
                        if (coverPooHole->field0.mFarDistanceSquared == gSfxParams[2].field20) {
                            t = 2;
                        } else if (coverPooHole->field0.mFarDistanceSquared == gSfxParams[3].field20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s.mSoundId = 0x16e;
                        s.mPositionSource = &coverPooHole->field0.mPos;
                        s.field8 = t;
                        s.mDistanceSquared = mobj_calcXZCamDist(&coverPooHole->field0.mPos);
                        sub_210B7A8(&s);
                    }
                }
                coverPooHole->field0.mDistanceSquaredAndFlags =
                    coverPooHole->field0.mDistanceSquaredAndFlags | data_021564bc;
                return 0;
            }
            if (itemEffect == 1 && (state == 4 || (state == 5 && coverPooHole->fieldA0 > 0x7800) || state == 1)) {
                coverPooHole->field108 = coverPooHole->field108 | kartMask;
                if ((coverPooHole->field0.mFlags & 0x800) == 0 || kart->mIndex == gRaceMultiConfig->mEntryIndex) {
                    coverPooHole->field104 = 1;
                    coverPooHole->fieldB4 = coverPooHole->fieldA0;
                    coverPooHole->fieldB8 = coverPooHole->fieldA4;
                    coverPooHole->fieldBC = 0x4000;
                    coverPooHole->fieldC0 = 0x1333;
                    coverPooHole->fieldC4 = 0;
                    coverPooHole->fieldD0 = 0;
                    coverPooHole->fieldD4 = 0x2000;
                    coverPooHole->fieldD8 = -0x40;
                    coverPooHole->fieldDC = 0x200;
                    coverPooHole->fieldE0 = 0;
                    coverPooHole->fieldE4 = 0;
                    coverPooHole->fieldF0 = 0;
                    coverPooHole->fieldF4 = 0x1000;
                    coverPooHole->fieldF8 = -0x30;
                    coverPooHole->fieldFC = 0x800;
                    coverPooHole->field100 = 0x100;
                    mobj_tryDestroyByDriver(&coverPooHole->field0, kart);
                    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                        effectPosition.x = (coverPooHole->field0.mPos.x + kart->mPos.x) >> 1;
                        effectPosition.y = (coverPooHole->field0.mPos.y + kart->mPos.y) >> 1;
                        effectPosition.z = (coverPooHole->field0.mPos.z + kart->mPos.z) >> 1;
                        ptcm_createEmitter(0x442, &effectPosition);
                        ptcm_createEmitter(0x443, &effectPosition);
                        if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                            mrcnt_notifyMObjDamage(coverPooHole->field0.mKind);
                        }
                    }
                }
                if ((coverPooHole->field0.mFlags & 0x800) == 0) {
                    if (coverPooHole->mState == 1) {
                        coverPooHole->mState = 6;
                    } else if (coverPooHole->mState == 4) {
                        coverPooHole->mState = 7;
                    }
                }
                coverPooHole->field0.field10.x = 0;
                coverPooHole->field0.field10.y = 0;
                coverPooHole->field0.field10.z = 0;
                return v3;
            }
            if (state == 1) {
                coverPooHole->field108 = coverPooHole->field108 | kartMask;
                if ((coverPooHole->field0.mFlags & 0x800) == 0 || kart->mIndex == gRaceMultiConfig->mEntryIndex) {
                    coverPooHole->field104 = 1;
                    coverPooHole->fieldB4 = coverPooHole->fieldA0;
                    coverPooHole->fieldB8 = coverPooHole->fieldA4;
                    coverPooHole->fieldBC = 0;
                    coverPooHole->fieldC0 = 0;
                    coverPooHole->fieldC4 = 0;
                    coverPooHole->fieldD0 = 0;
                    coverPooHole->fieldD4 = 0x2000;
                    coverPooHole->fieldD8 = -0x40;
                    coverPooHole->fieldDC = 0x200;
                    coverPooHole->fieldE0 = 0;
                    coverPooHole->fieldE4 = 0;
                    coverPooHole->fieldF0 = 0;
                    coverPooHole->fieldF4 = 0x1000;
                    coverPooHole->fieldF8 = -0x30;
                    coverPooHole->fieldFC = 0x800;
                    coverPooHole->field100 = 0x100;
                    coverPooHole->field0.mDistanceSquaredAndFlags =
                        coverPooHole->field0.mDistanceSquaredAndFlags | data_021564bc;
                    if ((coverPooHole->field0.mDistanceSquaredAndFlags & 4) == 0) {
                        if (coverPooHole->field0.mFarDistanceSquared == gSfxParams[2].field20) {
                            t = 2;
                        } else if (coverPooHole->field0.mFarDistanceSquared == gSfxParams[3].field20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s2.mSoundId = 0x16f;
                        s2.mPositionSource = &coverPooHole->field0.mPos;
                        s2.field8 = t;
                        s2.mDistanceSquared = mobj_calcXZCamDist(&coverPooHole->field0.mPos);
                        sub_210B7A8(&s2);
                    }
                }
                if ((coverPooHole->field0.mFlags & 0x800) == 0) {
                    coverPooHole->mState = 6;
                }
                coverPooHole->field0.field10.x = ((s64) kart->mVelocity.x * -0x4cd) >> 12;
                coverPooHole->field0.field10.y = ((s64) kart->mVelocity.y * -0x4cd) >> 12;
                coverPooHole->field0.field10.z = ((s64) kart->mVelocity.z * -0x4cd) >> 12;
                coverPooHole->field0.field10.y = 0x3800;
                return 12;
            }
        }
    }
    coverPooHole->field0.mDistanceSquaredAndFlags = coverPooHole->field0.mDistanceSquaredAndFlags | data_021564bc;
    coverPooHole->field0.field10.x = 0;
    coverPooHole->field0.field10.y = 0;
    coverPooHole->field0.field10.z = 0;
    return 0;
}

u32 poo_onItemCollide(CoverPooHole *coverPooHole, ItemObject *a, u8 *b, u8 *c) {
    u8 v1 = *b;
    u8 v2 = *c;
    if (coverPooHole->mState != 4) {
        return 0;
    }
    if (v1 == 2) {
        coverPooHole->field104 = 1;
        coverPooHole->fieldB4 = coverPooHole->fieldA0;
        coverPooHole->fieldB8 = coverPooHole->fieldA4;
        coverPooHole->fieldBC = 0x4000;
        coverPooHole->fieldC0 = 0x1333;
        coverPooHole->field0.field10.x = 0;
        coverPooHole->field0.field10.y = 0;
        coverPooHole->field0.field10.z = 0;
        coverPooHole->fieldC4 = 0;
        coverPooHole->fieldD0 = 0;
        coverPooHole->fieldD4 = 0x2000;
        coverPooHole->fieldD8 = -0x40;
        coverPooHole->fieldDC = 0x200;
        coverPooHole->fieldE0 = 0;
        coverPooHole->fieldE4 = 0;
        coverPooHole->fieldF0 = 0;
        coverPooHole->fieldF4 = 0x1000;
        coverPooHole->fieldF8 = -0x30;
        coverPooHole->fieldFC = 0x800;
        coverPooHole->field100 = 0x100;
        coverPooHole->field0.mDistanceSquaredAndFlags = coverPooHole->field0.mDistanceSquaredAndFlags | data_021564b8;
        if ((coverPooHole->field0.mFlags & 0x800) == 0) {
            coverPooHole->mState = 7;
        }
    }
    return v2;
}

// FALSE when the position is out of reach, else TRUE with the vector c that pushes it out (zero in most states).
BOOL poo_collide(CoverPooHole *coverPooHole, const Vec3 *position, s32 radius, Vec3 *pushOut) {
    Vec3 offset;
    s32 d;
    VEC_Subtract(position, &coverPooHole->field0.mPos, &offset);
    if (offset.y >= coverPooHole->fieldA0 + radius) {
        return FALSE;
    }
    d = VEC_Mag(&offset);
    if (d >= coverPooHole->field0.mExtent.x + radius) {
        return FALSE;
    }
    if (coverPooHole->mState == 1) {
        pushOut->x = 0;
        pushOut->y = 0;
        pushOut->z = 0;
        return TRUE;
    }
    if (coverPooHole->mState == 4 || (coverPooHole->mState == 5 && coverPooHole->fieldA0 > 0x7800)) {
        if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z >= 0x10) {
            vec_normalize(&offset, &offset);
        }
        d = coverPooHole->field0.mExtent.x + radius - d;
        pushOut->x = ((s64) offset.x * d) >> 12;
        pushOut->y = ((s64) offset.y * d) >> 12;
        pushOut->z = ((s64) offset.z * d) >> 12;
        return TRUE;
    }
    pushOut->x = 0;
    pushOut->y = 0;
    pushOut->z = 0;
    return TRUE;
}

void poo_loadModels(void *a) {
    poo_sCoverModel = mobj_loadBillboardModel(a, "cover.nsbmd");
    poo_sPooModel = mobj_loadTexAnimBillboardModel(a, "poo.nsbmd", "poo.nsbtp");
    poo_sHoleModel = mobj_loadBillboardModel(a, "hole.nsbmd");
    mobj_setModelPolygonIdAll(poo_sPooModel, 0x3f);
    mobj_setModelPolygonIdAll(poo_sHoleModel, 0x3f);
}

void poo_render(void *a, CoverPooHole *coverPooHole) {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 m[9];
    s32 f0[3];
    s32 f1[3];
    s32 f2[3];
    s32 f3[3];
    s32 f4[3];
    u16 e;
    s32 k;
    s32 v1;
    s32 j;
    s32 r;
    s32 t;
    w0 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &w0, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    f0[1] = coverPooHole->fieldA8 >> 4;
    f0[0] = 0;
    f0[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, f0, 3);
    NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&coverPooHole->field0.mPos), 12);
    mobj_bbModelApplyMaterial(a, poo_sHoleModel);
    mobj_renderModel(a, poo_sHoleModel, coverPooHole);
    w1 = 1;
    NNS_G3dGeBufferOP_N(0x12, &w1, 1);
    switch (coverPooHole->mState) {
        case 1:
        case 2:
        case 6:
            mobj_setModelNsbtpFrame(poo_sPooModel, 0);
            break;
        case 4:
        case 5:
        case 7:
            mobj_setModelNsbtpFrame(poo_sPooModel, 1);
            break;
    }
    if (coverPooHole->mState != 0) {
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        if (coverPooHole->field104 != 0) {
            t = coverPooHole->fieldB8 >> 4;
            f1[0] = 0;
            f1[1] = t;
            f1[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, f1, 3);
        } else {
            t = coverPooHole->fieldA4 >> 4;
            f2[0] = 0;
            f2[1] = t;
            f2[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, f2, 3);
        }
        NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&coverPooHole->field0.mPos), 12);
        mobj_bbModelApplyMaterial(a, poo_sPooModel);
        mobj_renderModel(a, poo_sPooModel, coverPooHole);
        w2 = 1;
        NNS_G3dGeBufferOP_N(0x12, &w2, 1);
    }
    if (coverPooHole->field104 == 1) {
        goto L;
    }
    if (coverPooHole->field104 == 2) {
    L:
        e = coverPooHole->fieldC8;
        k = ((u16) coverPooHole->fieldE8 >> 4) * 2;
        v1 = FX_SinCosTable_[k];
        r = ((s64) v1 * 0x7000) >> 12;
        if (r <= 0) {
            r = -r;
        }
        t = coverPooHole->fieldB4 + r;
        NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&coverPooHole->field0.mPos), 12);
        f3[1] = t >> 4;
        f3[0] = 0;
        f3[2] = 0;
        NNS_G3dGeBufferOP_N(0x1c, f3, 3);
        j = (e >> 4) * 2;
        MTX_RotY33_(m, FX_SinCosTable_[j], FX_SinCosTable_[j + 1]);
        NNS_G3dGeBufferOP_N(0x1a, m, 9);
        MTX_RotZ33_(m, v1, FX_SinCosTable_[k + 1]);
        NNS_G3dGeBufferOP_N(0x1a, m, 9);
    } else {
        t = coverPooHole->fieldA0 >> 4;
        f4[0] = 0;
        f4[1] = t;
        f4[2] = 0;
        NNS_G3dGeBufferOP_N(0x1c, f4, 3);
        NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&coverPooHole->field0.mPos), 12);
    }
    mobj_bbModelApplyMaterial(a, poo_sCoverModel);
    mobj_renderModel(a, poo_sCoverModel, coverPooHole);
}

void poo_globalLogicInit(MapObjectList *mapObjectList) {
    s32 i;
    CoverPooHole *coverPooHole;
    RandomState64 *mapObjectRandom;
    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (coverPooHole = mapObjectList->mMapObjects[i]) != NULL; i++) {
        coverPooHole->fieldA8 = 0x1000;
        mapObjectRandom = mobj_getRng1();
        mapObjectRandom->mValue =
            (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        coverPooHole->mTimer = (u16) (coverPooHole->field0.mCourseMapRow->field28 +
                                      (u16) (((u64) (u32) (mapObjectRandom->mValue >> 32) * 60) >> 32) - 30);
        if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
            coverPooHole->mState = 3;
            coverPooHole->fieldA0 = 0x2000;
            coverPooHole->fieldA4 = -0xd000;
        } else {
            coverPooHole->mState = 0;
            coverPooHole->fieldA0 = 0x2000;
            coverPooHole->fieldA4 = -0xd000;
        }
    }
}

s32 poo_FX_SinIdx(s32 a) {
    return FX_SinCosTable_[(a >> 4) * 2];
}

s32 poo_FX_MulInline(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

static inline u16 func_02095fec_inline(u32 n) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = mobj_getRng1();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return (u32) (((mapObjectRandom->mValue >> 32) * n) >> 32);
}

static inline void func_02095fec_inline_2(CoverPooHole *coverPooHole, s32 soundId) {
    Unk0210b7a8 s;
    s32 v;

    if (coverPooHole->field0.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (coverPooHole->field0.mFarDistanceSquared == gSfxParams[2].field20) {
        v = 2;
    } else if (coverPooHole->field0.mFarDistanceSquared == gSfxParams[3].field20) {
        v = 3;
    } else {
        v = 4;
    }
    s.mSoundId = soundId;
    s.mPositionSource = &coverPooHole->field0.mPos;
    s.field8 = v;
    s.mDistanceSquared = mobj_calcXZCamDist(&coverPooHole->field0.mPos);
    sub_210B7A8(&s);
}

void poo_update(void *a, CoverPooHole *coverPooHole) {
    s32 v;

    coverPooHole->field0.field10.y = 0;
    switch (coverPooHole->field104) {
        case 0:
            break;
        case 1:
            coverPooHole->fieldB8 += coverPooHole->fieldC0;
            coverPooHole->fieldC0 -= 0x800;
            if (coverPooHole->fieldB4 >= 0x2000) {
                coverPooHole->fieldB4 += coverPooHole->fieldBC;
                coverPooHole->fieldBC -= 0x19a;
            } else {
                coverPooHole->fieldB4 = 0x2000;
                coverPooHole->field104 = 2;
                func_02095fec_inline_2(coverPooHole, 0x16c);
            }
            break;
        case 2:
            if (coverPooHole->fieldB8 >= 0x2000) {
                coverPooHole->fieldB8 += coverPooHole->fieldC0;
                coverPooHole->fieldC0 -= 0x800;
            }
            coverPooHole->fieldC4 += coverPooHole->fieldDC;
            coverPooHole->fieldCC = coverPooHole->fieldD0 +
                                    poo_FX_MulInline(coverPooHole->fieldD4, poo_FX_SinIdx(coverPooHole->fieldC4)) -
                                    coverPooHole->fieldC8;
            coverPooHole->fieldC8 += coverPooHole->fieldCC;
            if (coverPooHole->fieldD4 > 0) {
                v = coverPooHole->fieldD4 + coverPooHole->fieldD8;
                if (v <= 0) {
                    v = 0;
                }
                coverPooHole->fieldD4 = v;
            } else if (coverPooHole->fieldD4 < 0) {
                v = coverPooHole->fieldD4 + coverPooHole->fieldD8;
                if (v >= 0) {
                    v = 0;
                }
                coverPooHole->fieldD4 = v;
            }
            if (coverPooHole->fieldDC > 0) {
                v = coverPooHole->fieldDC + coverPooHole->fieldE0;
                if (v <= 0) {
                    v = 0;
                }
                coverPooHole->fieldDC = v;
            } else if (coverPooHole->fieldDC < 0) {
                v = coverPooHole->fieldDC + coverPooHole->fieldE0;
                if (v >= 0) {
                    v = 0;
                }
                coverPooHole->fieldDC = v;
            }
            coverPooHole->fieldE4 += coverPooHole->fieldFC;
            coverPooHole->fieldEC = coverPooHole->fieldF0 +
                                    poo_FX_MulInline(coverPooHole->fieldF4, poo_FX_SinIdx(coverPooHole->fieldE4)) -
                                    coverPooHole->fieldE8;
            coverPooHole->fieldE8 += coverPooHole->fieldEC;
            if (coverPooHole->fieldF4 > 0) {
                v = coverPooHole->fieldF4 + coverPooHole->fieldF8;
                if (v <= 0) {
                    v = 0;
                }
                coverPooHole->fieldF4 = v;
            } else if (coverPooHole->fieldF4 < 0) {
                v = coverPooHole->fieldF4 + coverPooHole->fieldF8;
                if (v >= 0) {
                    v = 0;
                }
                coverPooHole->fieldF4 = v;
            }
            if (coverPooHole->fieldFC > 0) {
                v = coverPooHole->fieldFC + coverPooHole->field100;
                if (v <= 0) {
                    v = 0;
                }
                coverPooHole->fieldFC = v;
            } else if (coverPooHole->fieldFC < 0) {
                v = coverPooHole->fieldFC + coverPooHole->field100;
                if (v >= 0) {
                    v = 0;
                }
                coverPooHole->fieldFC = v;
            }
            if (coverPooHole->fieldF4 == 0 && coverPooHole->mState != 2 && coverPooHole->mState != 5) {
                coverPooHole->field104 = 0;
            }
            break;
    }
    if ((coverPooHole->mState == 6 || coverPooHole->mState == 7) && coverPooHole->field104 == 0) {
        if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
            coverPooHole->mState = 3;
            coverPooHole->fieldA0 = 0x2000;
            coverPooHole->fieldA4 = -0xd000;
        } else {
            coverPooHole->mState = 0;
            coverPooHole->fieldA0 = 0x2000;
            coverPooHole->fieldA4 = -0xd000;
        }
    }
    switch (coverPooHole->mState) {
        case 0:
            if (coverPooHole->mTimer-- > 0) {
                return;
            }
            coverPooHole->mTimer = (u16) (func_02095fec_inline(30) + 30);
            coverPooHole->mState = 1;
            coverPooHole->field104 = 0;
            coverPooHole->field108 = 0;
            func_02095fec_inline_2(coverPooHole, 0x1d3);
            break;
        case 1:
            if (coverPooHole->fieldA0 < 0x7800) {
                coverPooHole->fieldA0 += 0x400;
                coverPooHole->fieldA4 = coverPooHole->fieldA0 - 0xf000;
                return;
            }
            if (coverPooHole->mTimer-- > 0) {
                coverPooHole->fieldA0 = 0x7800;
                coverPooHole->fieldA4 = -0x7800;
                return;
            }
            coverPooHole->fieldA0 = 0x7800;
            coverPooHole->fieldA4 = -0x7800;
            coverPooHole->mState = 2;
            break;
        case 2:
            if (coverPooHole->fieldA0 > 0x2000) {
                coverPooHole->fieldA0 -= 0x400;
                coverPooHole->fieldA4 = coverPooHole->fieldA0 - 0xf000;
                return;
            }
            coverPooHole->fieldA0 = 0x2000;
            coverPooHole->fieldA4 = -0xd000;
            coverPooHole->mTimer = (u16) (func_02095fec_inline(15) + 15);
            coverPooHole->mState = 3;
            coverPooHole->field108 = 0;
            func_02095fec_inline_2(coverPooHole, 0x1d4);
            break;
        case 3:
            if (coverPooHole->mTimer-- > 0) {
                return;
            }
            coverPooHole->fieldA0 = 0x2000;
            coverPooHole->fieldA4 = -0xd000;
            coverPooHole->mTimer = (u16) (func_02095fec_inline(90) + 90);
            coverPooHole->mState = 4;
            coverPooHole->field104 = 0;
            coverPooHole->field108 = 0;
            func_02095fec_inline_2(coverPooHole, 0x1d3);
            break;
        case 4:
            if (coverPooHole->fieldA0 < 0x124cd) {
                coverPooHole->fieldA0 += 0xc00;
                coverPooHole->fieldA4 = coverPooHole->fieldA0 - 0xf000;
                return;
            }
            if (coverPooHole->mTimer-- > 0) {
                coverPooHole->fieldA0 = 0x124cd;
                coverPooHole->fieldA4 = 0x34cd;
                return;
            }
            coverPooHole->fieldA0 = 0x124cd;
            coverPooHole->fieldA4 = 0x34cd;
            coverPooHole->mState = 5;
            break;
        case 5:
            if (coverPooHole->fieldA0 > 0x2000) {
                coverPooHole->fieldA0 -= 0xc00;
                coverPooHole->fieldA4 = coverPooHole->fieldA0 - 0xf000;
                return;
            }
            coverPooHole->mTimer = (u16) (coverPooHole->field0.mCourseMapRow->field28 + func_02095fec_inline(60) - 30);
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                coverPooHole->mState = 3;
                coverPooHole->fieldA0 = 0x2000;
                coverPooHole->fieldA4 = -0xd000;
            } else {
                coverPooHole->mState = 0;
                coverPooHole->fieldA0 = 0x2000;
                coverPooHole->fieldA4 = -0xd000;
            }
            coverPooHole->field108 = 0;
            func_02095fec_inline_2(coverPooHole, 0x1d4);
            break;
    }
}

void poo_setupConfig(void) {
    MapObjectKindData *o;
    o = mobj_createConfigEx(poo_onDriverCollide, poo_onItemCollide, poo_collide, 0, 1,
                      0x16d);
    o->field28 = 0x1b0;
}

void *poo_setupRenderPart(void) {
    return mobj_createRenderPart2d(poo_loadModels, poo_render, NULL);
}

void *poo_setupLogicPart(void) {
    return mobj_createLogicPart(poo_globalLogicInit, poo_update, NULL);
}

BOOL poo_2095F38(Unk0217b498_00 *a) {
    if (a->fieldB0 == 1 || a->fieldB0 == 4) {
        return TRUE;
    }
    return FALSE;
}
