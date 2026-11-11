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

u32 SetFlipperState4TimerByIndex(u32 flipperIndex) {
    Flipper *flipper;
    flipper = GetMapObjectFromList(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_FLIPPER), flipperIndex);
    flipper->mState4Timer = 0xaa;
    return 1;
}

void InitCoverPooHole(MapObject *mapObject) {
    mapObject->mFlags |= data_021564c0;
}

u32 CollideKartWithCoverPooHole(CoverPooHole *coverPooHole, Kart *kart, u8 *b, u8 *c) {
    s32 state;
    s32 itemEffect;
    u32 v2 = *b;
    Vec3 effectPosition;
    s32 t;
    u8 kartMask = 1 << kart->mIndex;
    SoundStartParams s;
    u8 v3 = *c;
    SoundStartParams s2;
    if (v2 == 3 || v2 == 4) {
        itemEffect = kart->mItemEffect;
        if (itemEffect != 1) {
            if (coverPooHole->mState == 4 || (coverPooHole->mState == 5 && coverPooHole->mCoverHeight > 0x7800)) {
                coverPooHole->mMapObject.mPosStep.x = 0;
                coverPooHole->mMapObject.mPosStep.y = 0x3800;
                coverPooHole->mMapObject.mPosStep.z = 0;
                return v3;
            }
        }
        if ((((const CoverPooHole *) coverPooHole)->mUnk_108 & kartMask) == 0) {
            state = coverPooHole->mState;
            if (state == 0 || state == 3) {
                coverPooHole->mUnk_108 = coverPooHole->mUnk_108 | kartMask;
                if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_GHOST) {
                    if ((coverPooHole->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
                        if (coverPooHole->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            t = 2;
                        } else if (coverPooHole->mMapObject.mFarDistanceSquared ==
                                   gSoundFalloffs[3].mFarDistanceSquared) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s.mSoundId = 0x16e;
                        s.mPositionSource = &coverPooHole->mMapObject.mPos;
                        s.mFalloffIndex = t;
                        s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&coverPooHole->mMapObject.mPos);
                        StartSoundFromParams(&s);
                    }
                }
                coverPooHole->mMapObject.mDistanceSquaredAndFlags =
                    coverPooHole->mMapObject.mDistanceSquaredAndFlags | data_021564bc;
                return 0;
            }
            if (itemEffect == 1 && (state == 4 || (state == 5 && coverPooHole->mCoverHeight > 0x7800) || state == 1)) {
                coverPooHole->mUnk_108 = coverPooHole->mUnk_108 | kartMask;
                if ((coverPooHole->mMapObject.mFlags & 0x800) == 0 || kart->mIndex == gRaceSetup->mEntryIndex) {
                    coverPooHole->mUnk_104 = 1;
                    coverPooHole->mHitCoverHeight = coverPooHole->mCoverHeight;
                    coverPooHole->mHitPooHeight = coverPooHole->mPooHeight;
                    coverPooHole->mUnk_bc = 0x4000;
                    coverPooHole->mUnk_c0 = 0x1333;
                    coverPooHole->mUnk_c4 = 0;
                    coverPooHole->mUnk_d0 = 0;
                    coverPooHole->mUnk_d4 = 0x2000;
                    coverPooHole->mUnk_d8 = -0x40;
                    coverPooHole->mUnk_dc = 0x200;
                    coverPooHole->mUnk_e0 = 0;
                    coverPooHole->mUnk_e4 = 0;
                    coverPooHole->mUnk_f0 = 0;
                    coverPooHole->mUnk_f4 = 0x1000;
                    coverPooHole->mUnk_f8 = -0x30;
                    coverPooHole->mUnk_fc = 0x800;
                    coverPooHole->mUnk_100 = 0x100;
                    StartSoundIfKartStarOrKiller(&coverPooHole->mMapObject, kart);
                    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                        effectPosition.x = (coverPooHole->mMapObject.mPos.x + kart->mPos.x) >> 1;
                        effectPosition.y = (coverPooHole->mMapObject.mPos.y + kart->mPos.y) >> 1;
                        effectPosition.z = (coverPooHole->mMapObject.mPos.z + kart->mPos.z) >> 1;
                        StartEffect(0x442, &effectPosition);
                        StartEffect(0x443, &effectPosition);
                        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                            func_ov001_0218175c(coverPooHole->mMapObject.mKind);
                        }
                    }
                }
                if ((coverPooHole->mMapObject.mFlags & 0x800) == 0) {
                    if (coverPooHole->mState == 1) {
                        coverPooHole->mState = 6;
                    } else if (coverPooHole->mState == 4) {
                        coverPooHole->mState = 7;
                    }
                }
                coverPooHole->mMapObject.mPosStep.x = 0;
                coverPooHole->mMapObject.mPosStep.y = 0;
                coverPooHole->mMapObject.mPosStep.z = 0;
                return v3;
            }
            if (state == 1) {
                coverPooHole->mUnk_108 = coverPooHole->mUnk_108 | kartMask;
                if ((coverPooHole->mMapObject.mFlags & 0x800) == 0 || kart->mIndex == gRaceSetup->mEntryIndex) {
                    coverPooHole->mUnk_104 = 1;
                    coverPooHole->mHitCoverHeight = coverPooHole->mCoverHeight;
                    coverPooHole->mHitPooHeight = coverPooHole->mPooHeight;
                    coverPooHole->mUnk_bc = 0;
                    coverPooHole->mUnk_c0 = 0;
                    coverPooHole->mUnk_c4 = 0;
                    coverPooHole->mUnk_d0 = 0;
                    coverPooHole->mUnk_d4 = 0x2000;
                    coverPooHole->mUnk_d8 = -0x40;
                    coverPooHole->mUnk_dc = 0x200;
                    coverPooHole->mUnk_e0 = 0;
                    coverPooHole->mUnk_e4 = 0;
                    coverPooHole->mUnk_f0 = 0;
                    coverPooHole->mUnk_f4 = 0x1000;
                    coverPooHole->mUnk_f8 = -0x30;
                    coverPooHole->mUnk_fc = 0x800;
                    coverPooHole->mUnk_100 = 0x100;
                    coverPooHole->mMapObject.mDistanceSquaredAndFlags =
                        coverPooHole->mMapObject.mDistanceSquaredAndFlags | data_021564bc;
                    if ((coverPooHole->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
                        if (coverPooHole->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            t = 2;
                        } else if (coverPooHole->mMapObject.mFarDistanceSquared ==
                                   gSoundFalloffs[3].mFarDistanceSquared) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s2.mSoundId = 0x16f;
                        s2.mPositionSource = &coverPooHole->mMapObject.mPos;
                        s2.mFalloffIndex = t;
                        s2.mDistanceSquared = GetHorizontalCameraDistanceSquared(&coverPooHole->mMapObject.mPos);
                        StartSoundFromParams(&s2);
                    }
                }
                if ((coverPooHole->mMapObject.mFlags & 0x800) == 0) {
                    coverPooHole->mState = 6;
                }
                coverPooHole->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(kart->mVelocity.x, -0x4cd);
                coverPooHole->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(kart->mVelocity.y, -0x4cd);
                coverPooHole->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(kart->mVelocity.z, -0x4cd);
                coverPooHole->mMapObject.mPosStep.y = 0x3800;
                return 12;
            }
        }
    }
    coverPooHole->mMapObject.mDistanceSquaredAndFlags =
        coverPooHole->mMapObject.mDistanceSquaredAndFlags | data_021564bc;
    coverPooHole->mMapObject.mPosStep.x = 0;
    coverPooHole->mMapObject.mPosStep.y = 0;
    coverPooHole->mMapObject.mPosStep.z = 0;
    return 0;
}

u32 CollideItemObjectWithCoverPooHole(CoverPooHole *coverPooHole, ItemObject *a, u8 *b, u8 *c) {
    u8 v1 = *b;
    u8 v2 = *c;
    if (coverPooHole->mState != 4) {
        return 0;
    }
    if (v1 == 2) {
        coverPooHole->mUnk_104 = 1;
        coverPooHole->mHitCoverHeight = coverPooHole->mCoverHeight;
        coverPooHole->mHitPooHeight = coverPooHole->mPooHeight;
        coverPooHole->mUnk_bc = 0x4000;
        coverPooHole->mUnk_c0 = 0x1333;
        coverPooHole->mMapObject.mPosStep.x = 0;
        coverPooHole->mMapObject.mPosStep.y = 0;
        coverPooHole->mMapObject.mPosStep.z = 0;
        coverPooHole->mUnk_c4 = 0;
        coverPooHole->mUnk_d0 = 0;
        coverPooHole->mUnk_d4 = 0x2000;
        coverPooHole->mUnk_d8 = -0x40;
        coverPooHole->mUnk_dc = 0x200;
        coverPooHole->mUnk_e0 = 0;
        coverPooHole->mUnk_e4 = 0;
        coverPooHole->mUnk_f0 = 0;
        coverPooHole->mUnk_f4 = 0x1000;
        coverPooHole->mUnk_f8 = -0x30;
        coverPooHole->mUnk_fc = 0x800;
        coverPooHole->mUnk_100 = 0x100;
        coverPooHole->mMapObject.mDistanceSquaredAndFlags =
            coverPooHole->mMapObject.mDistanceSquaredAndFlags | data_021564b8;
        if ((coverPooHole->mMapObject.mFlags & 0x800) == 0) {
            coverPooHole->mState = 7;
        }
    }
    return v2;
}

// FALSE when the position is out of reach, else TRUE with the vector c that pushes it out (zero in most states).
BOOL TryGetCoverPooHolePushOut(CoverPooHole *coverPooHole, const Vec3 *position, s32 radius, Vec3 *pushOut) {
    Vec3 offset;
    s32 d;
    VEC_Subtract(position, &coverPooHole->mMapObject.mPos, &offset);
    if (offset.y >= coverPooHole->mCoverHeight + radius) {
        return FALSE;
    }
    d = VEC_Mag(&offset);
    if (d >= coverPooHole->mMapObject.mExtent.x + radius) {
        return FALSE;
    }
    if (coverPooHole->mState == 1) {
        pushOut->x = 0;
        pushOut->y = 0;
        pushOut->z = 0;
        return TRUE;
    }
    if (coverPooHole->mState == 4 || (coverPooHole->mState == 5 && coverPooHole->mCoverHeight > 0x7800)) {
        if (LENGTH_SQUARED(offset) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
        }
        d = coverPooHole->mMapObject.mExtent.x + radius - d;
        pushOut->x = MUL_FIXED12_NO_ROUND(offset.x, d);
        pushOut->y = MUL_FIXED12_NO_ROUND(offset.y, d);
        pushOut->z = MUL_FIXED12_NO_ROUND(offset.z, d);
        return TRUE;
    }
    pushOut->x = 0;
    pushOut->y = 0;
    pushOut->z = 0;
    return TRUE;
}

void CreateCoverPooHole(void *a) {
    gCover = CreateMapObjectModelNsbmd(a, "cover.nsbmd");
    gPoo = CreateMapObjectModelNsbmdNsbtp(a, "poo.nsbmd", "poo.nsbtp");
    gHole = CreateMapObjectModelNsbmd(a, "hole.nsbmd");
    SetMapObjectModelPolygonId(gPoo, 0x3f);
    SetMapObjectModelPolygonId(gHole, 0x3f);
}

void DrawCoverPooHole(void *a, CoverPooHole *coverPooHole) {
    s32 w0;
    s32 w1;
    s32 w2;
    MtxFx33 m;
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
    f0[1] = coverPooHole->mUnk_a8 >> 4;
    f0[0] = 0;
    f0[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, f0, 3);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&coverPooHole->mMapObject.mPos), 12);
    QueueMapObjectModelMaterial(a, gHole);
    DrawMapObjectModel(a, gHole, coverPooHole);
    w1 = 1;
    NNS_G3dGeBufferOP_N(0x12, &w1, 1);
    switch (coverPooHole->mState) {
        case 1:
        case 2:
        case 6:
            SetMapObjectModelNsbtpFrameIndex(gPoo, 0);
            break;
        case 4:
        case 5:
        case 7:
            SetMapObjectModelNsbtpFrameIndex(gPoo, 1);
            break;
    }
    if (coverPooHole->mState != 0) {
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        if (coverPooHole->mUnk_104 != 0) {
            t = coverPooHole->mHitPooHeight >> 4;
            f1[0] = 0;
            f1[1] = t;
            f1[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, f1, 3);
        } else {
            t = coverPooHole->mPooHeight >> 4;
            f2[0] = 0;
            f2[1] = t;
            f2[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, f2, 3);
        }
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&coverPooHole->mMapObject.mPos), 12);
        QueueMapObjectModelMaterial(a, gPoo);
        DrawMapObjectModel(a, gPoo, coverPooHole);
        w2 = 1;
        NNS_G3dGeBufferOP_N(0x12, &w2, 1);
    }
    if (coverPooHole->mUnk_104 == 1) {
        goto L;
    }
    if (coverPooHole->mUnk_104 == 2) {
    L:
        e = coverPooHole->mUnk_c8;
        k = ((u16) coverPooHole->mUnk_e8 >> 4) * 2;
        v1 = FX_SinCosTable_[k];
        r = MUL_FIXED12_NO_ROUND(v1, 0x7000);
        if (r <= 0) {
            r = -r;
        }
        t = coverPooHole->mHitCoverHeight + r;
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&coverPooHole->mMapObject.mPos), 12);
        f3[1] = t >> 4;
        f3[0] = 0;
        f3[2] = 0;
        NNS_G3dGeBufferOP_N(0x1c, f3, 3);
        j = (e >> 4) * 2;
        MTX_RotY33_(&m, FX_SinCosTable_[j], FX_SinCosTable_[j + 1]);
        NNS_G3dGeBufferOP_N(0x1a, &m, 9);
        MTX_RotZ33_(&m, v1, FX_SinCosTable_[k + 1]);
        NNS_G3dGeBufferOP_N(0x1a, &m, 9);
    } else {
        t = coverPooHole->mCoverHeight >> 4;
        f4[0] = 0;
        f4[1] = t;
        f4[2] = 0;
        NNS_G3dGeBufferOP_N(0x1c, f4, 3);
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&coverPooHole->mMapObject.mPos), 12);
    }
    QueueMapObjectModelMaterial(a, gCover);
    DrawMapObjectModel(a, gCover, coverPooHole);
}

void InitCoverPooHoleObjects(MapObjectList *mapObjectList) {
    s32 i;
    CoverPooHole *coverPooHole;
    RandomState64 *mapObjectRandom;
    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (coverPooHole = mapObjectList->mMapObjects[i]) != NULL; i++) {
        coverPooHole->mUnk_a8 = 0x1000;
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue =
            (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        coverPooHole->mTimer = (u16) (coverPooHole->mMapObject.mCourseMapRow->mUnk_28 +
                                      (u16) (((u64) (u32) (mapObjectRandom->mValue >> 32) * 60) >> 32) - 30);
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            coverPooHole->mState = 3;
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
        } else {
            coverPooHole->mState = 0;
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
        }
    }
}

s32 CoverPooHoleFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 CoverPooHoleFX_MulInline(s32 a, s32 b) {
    return MUL_FIXED12_ROUNDED(a, b);
}

static inline u16 CoverPooHoleMapObjectRandomBelowU16(u32 limit) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return (u32) (((mapObjectRandom->mValue >> 32) * limit) >> 32);
}

static inline void StartCoverPooHoleSound(CoverPooHole *coverPooHole, s32 soundId) {
    SoundStartParams startParams;
    s32 falloffIndex;

    if (coverPooHole->mMapObject.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (coverPooHole->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
        falloffIndex = 2;
    } else if (coverPooHole->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
        falloffIndex = 3;
    } else {
        falloffIndex = 4;
    }
    startParams.mSoundId = soundId;
    startParams.mPositionSource = &coverPooHole->mMapObject.mPos;
    startParams.mFalloffIndex = falloffIndex;
    startParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&coverPooHole->mMapObject.mPos);
    StartSoundFromParams(&startParams);
}

void UpdateCoverPooHole(void *a, CoverPooHole *coverPooHole) {
    s32 v;

    coverPooHole->mMapObject.mPosStep.y = 0;
    switch (coverPooHole->mUnk_104) {
        case 0:
            break;
        case 1:
            coverPooHole->mHitPooHeight += coverPooHole->mUnk_c0;
            coverPooHole->mUnk_c0 -= 0x800;
            if (coverPooHole->mHitCoverHeight >= 0x2000) {
                coverPooHole->mHitCoverHeight += coverPooHole->mUnk_bc;
                coverPooHole->mUnk_bc -= 0x19a;
            } else {
                coverPooHole->mHitCoverHeight = 0x2000;
                coverPooHole->mUnk_104 = 2;
                StartCoverPooHoleSound(coverPooHole, 0x16c);
            }
            break;
        case 2:
            if (coverPooHole->mHitPooHeight >= 0x2000) {
                coverPooHole->mHitPooHeight += coverPooHole->mUnk_c0;
                coverPooHole->mUnk_c0 -= 0x800;
            }
            coverPooHole->mUnk_c4 += coverPooHole->mUnk_dc;
            coverPooHole->mUnk_cc =
                coverPooHole->mUnk_d0 +
                CoverPooHoleFX_MulInline(coverPooHole->mUnk_d4, CoverPooHoleFX_SinIdx(coverPooHole->mUnk_c4)) -
                coverPooHole->mUnk_c8;
            coverPooHole->mUnk_c8 += coverPooHole->mUnk_cc;
            if (coverPooHole->mUnk_d4 > 0) {
                v = coverPooHole->mUnk_d4 + coverPooHole->mUnk_d8;
                if (v <= 0) {
                    v = 0;
                }
                coverPooHole->mUnk_d4 = v;
            } else if (coverPooHole->mUnk_d4 < 0) {
                v = coverPooHole->mUnk_d4 + coverPooHole->mUnk_d8;
                if (v >= 0) {
                    v = 0;
                }
                coverPooHole->mUnk_d4 = v;
            }
            if (coverPooHole->mUnk_dc > 0) {
                v = coverPooHole->mUnk_dc + coverPooHole->mUnk_e0;
                if (v <= 0) {
                    v = 0;
                }
                coverPooHole->mUnk_dc = v;
            } else if (coverPooHole->mUnk_dc < 0) {
                v = coverPooHole->mUnk_dc + coverPooHole->mUnk_e0;
                if (v >= 0) {
                    v = 0;
                }
                coverPooHole->mUnk_dc = v;
            }
            coverPooHole->mUnk_e4 += coverPooHole->mUnk_fc;
            coverPooHole->mUnk_ec =
                coverPooHole->mUnk_f0 +
                CoverPooHoleFX_MulInline(coverPooHole->mUnk_f4, CoverPooHoleFX_SinIdx(coverPooHole->mUnk_e4)) -
                coverPooHole->mUnk_e8;
            coverPooHole->mUnk_e8 += coverPooHole->mUnk_ec;
            if (coverPooHole->mUnk_f4 > 0) {
                v = coverPooHole->mUnk_f4 + coverPooHole->mUnk_f8;
                if (v <= 0) {
                    v = 0;
                }
                coverPooHole->mUnk_f4 = v;
            } else if (coverPooHole->mUnk_f4 < 0) {
                v = coverPooHole->mUnk_f4 + coverPooHole->mUnk_f8;
                if (v >= 0) {
                    v = 0;
                }
                coverPooHole->mUnk_f4 = v;
            }
            if (coverPooHole->mUnk_fc > 0) {
                v = coverPooHole->mUnk_fc + coverPooHole->mUnk_100;
                if (v <= 0) {
                    v = 0;
                }
                coverPooHole->mUnk_fc = v;
            } else if (coverPooHole->mUnk_fc < 0) {
                v = coverPooHole->mUnk_fc + coverPooHole->mUnk_100;
                if (v >= 0) {
                    v = 0;
                }
                coverPooHole->mUnk_fc = v;
            }
            if (coverPooHole->mUnk_f4 == 0 && coverPooHole->mState != 2 && coverPooHole->mState != 5) {
                coverPooHole->mUnk_104 = 0;
            }
            break;
    }
    if ((coverPooHole->mState == 6 || coverPooHole->mState == 7) && coverPooHole->mUnk_104 == 0) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            coverPooHole->mState = 3;
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
        } else {
            coverPooHole->mState = 0;
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
        }
    }
    switch (coverPooHole->mState) {
        case 0:
            if (coverPooHole->mTimer-- > 0) {
                return;
            }
            coverPooHole->mTimer = (u16) (CoverPooHoleMapObjectRandomBelowU16(30) + 30);
            coverPooHole->mState = 1;
            coverPooHole->mUnk_104 = 0;
            coverPooHole->mUnk_108 = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d3);
            break;
        case 1:
            if (coverPooHole->mCoverHeight < 0x7800) {
                coverPooHole->mCoverHeight += 0x400;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - 0xf000;
                return;
            }
            if (coverPooHole->mTimer-- > 0) {
                coverPooHole->mCoverHeight = 0x7800;
                coverPooHole->mPooHeight = -0x7800;
                return;
            }
            coverPooHole->mCoverHeight = 0x7800;
            coverPooHole->mPooHeight = -0x7800;
            coverPooHole->mState = 2;
            break;
        case 2:
            if (coverPooHole->mCoverHeight > 0x2000) {
                coverPooHole->mCoverHeight -= 0x400;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - 0xf000;
                return;
            }
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
            coverPooHole->mTimer = (u16) (CoverPooHoleMapObjectRandomBelowU16(15) + 15);
            coverPooHole->mState = 3;
            coverPooHole->mUnk_108 = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d4);
            break;
        case 3:
            if (coverPooHole->mTimer-- > 0) {
                return;
            }
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
            coverPooHole->mTimer = (u16) (CoverPooHoleMapObjectRandomBelowU16(90) + 90);
            coverPooHole->mState = 4;
            coverPooHole->mUnk_104 = 0;
            coverPooHole->mUnk_108 = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d3);
            break;
        case 4:
            if (coverPooHole->mCoverHeight < 0x124cd) {
                coverPooHole->mCoverHeight += 0xc00;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - 0xf000;
                return;
            }
            if (coverPooHole->mTimer-- > 0) {
                coverPooHole->mCoverHeight = 0x124cd;
                coverPooHole->mPooHeight = 0x34cd;
                return;
            }
            coverPooHole->mCoverHeight = 0x124cd;
            coverPooHole->mPooHeight = 0x34cd;
            coverPooHole->mState = 5;
            break;
        case 5:
            if (coverPooHole->mCoverHeight > 0x2000) {
                coverPooHole->mCoverHeight -= 0xc00;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - 0xf000;
                return;
            }
            coverPooHole->mTimer =
                (u16) (coverPooHole->mMapObject.mCourseMapRow->mUnk_28 + CoverPooHoleMapObjectRandomBelowU16(60) - 30);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                coverPooHole->mState = 3;
                coverPooHole->mCoverHeight = 0x2000;
                coverPooHole->mPooHeight = -0xd000;
            } else {
                coverPooHole->mState = 0;
                coverPooHole->mCoverHeight = 0x2000;
                coverPooHole->mPooHeight = -0xd000;
            }
            coverPooHole->mUnk_108 = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d4);
            break;
    }
}

void CreateCoverPooHoleKindData(void) {
    MapObjectKindData *o;
    o = CreateMapObjectKindDataWithSound(CollideKartWithCoverPooHole, CollideItemObjectWithCoverPooHole,
                                         TryGetCoverPooHolePushOut, 0, 1, 0x16d);
    o->mCollideItemObjectSoundId = 0x1b0;
}

void *CreateCoverPooHoleDrawList(void) {
    return CreateMapObjectDrawList2(CreateCoverPooHole, DrawCoverPooHole, NULL);
}

void *CreateCoverPooHoleUpdateList(void) {
    return CreateMapObjectUpdateList(InitCoverPooHoleObjects, UpdateCoverPooHole, NULL);
}

BOOL IsCoverPooHoleState1Or4(CoverPooHole *coverPooHole) {
    if (coverPooHole->mState == 1 || coverPooHole->mState == 4) {
        return TRUE;
    }
    return FALSE;
}
