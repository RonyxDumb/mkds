#include "Main/Unknown/code_020f9c6c.h"
#include "code_02012b30.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020fe450.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020fe000.h"
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
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1a24.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Item/ItemGesso.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020fcbb8.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01fff000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020fc000.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01fff434.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fcb9c.h"
#include "Main/Unknown/code_020fcedc.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f2000.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020fd254.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Kart/KartTimes.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"

void itkraw_activate(ItemKouraW *item) {
    item->field170 = 1;
}

void itkraw_initInstance(ItemKouraW *item) {
    sm_init(&item->field2E8, (UnkFunc *const *) itkraw_sStates, 8, item);
    MTX_Identity43_((MtxFx43 *) item->field2B4);
    item->mRank = 1;
    item->mRankKartIndex = gRaceStatus->mKartAtRank[0];
    item->field278 = 0;
    item->mPosStrip = NULL;
    item->mSoundId = 0xdc;
    item->mKartMask = 0;
    item->mHitSpinsKart = 0;
}

void itkraw_20FC94C(ItemKouraW *item) {
    sfx_210B850(&item->field300);
    item->field0.mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) func_0210a67c;
    item->field160 = 0;
    item->field0.mDrawPos = item->field0.mPos;
    FreeItemObjectCollisionSlot((s32) item);
    item->field0.mFlags |= 0x200000;
    ClearItemKouraWKartItemsAndAngle(item);
    if (gRaceStatus->mRaceDone != 0) {
        item->mRank = 1;
        item->mRankKartIndex = gRaceStatus->mKartAtRank[(item->mRank & 0xff) - 1];
    } else {
        item->mRankKartIndex = gRaceStatus->mKartAtRank[(item->mRank & 0xff) - 1];
        while (rstat_hasDriverFinished(item->mRankKartIndex) != 0 && item->mRank < (u32) gRaceMultiConfig->mKartCount) {
            item->mRank++;
            item->mRankKartIndex = gRaceStatus->mKartAtRank[(item->mRank & 0xff) - 1];
        }
    }
    item->field260 = 0x32000;
    item->field264 = 0xf000;
    item->mDrawOffsetAngle = 0;
    item->field27C = 0x1a000;
    item->field298.x = 0;
    item->field298.y = 0;
    item->field298.z = 0;
    VEC_Subtract(&item->field0.mVelocity, &item->field298, &item->field28C);
    item->field0.fieldD0 = &item->field0.mDrawPos;
    light_init(&item->field0.mColorBlend, 1);
}

void SetItemKouraWKartItemsAndStateIfNone(ItemKouraW *item, s32 kartIndex) {
    Kart *kart;

    if (item->mKartItems != NULL) {
        return;
    }
    SetItemKouraWKartItems(item, kartIndex);
    kart = item->mKartItems->mKart;
    item->mNextState = ((item->field0.mFlags & 0x40000000) || (kart->field48 & 1)) ? 2 : 3;
    item->mNextStateRequested = 1;
}

s32 itkraw_20FC79C(ItemInUse *itemInUse, ItemKouraW *item) {
    Kart *kart;

    sub_20F9114(item);
    if (itemInUse->mKartItems->field1F0.mLink != NULL) {
        InitLinkFollowingItemFromInUse((LinkFollowingItemObject *) item, itemInUse, 0x14, 0xcc, 1, 1, 0, 0x6000,
                                       item->mRankKartIndex, 1);
        sm_gotoState(item->field2E8, 1);
    } else {
        SetItemKouraWKartItems(item, (u16) gRaceStatus->mKartAtRank[0]);
        kart = item->mKartItems->mKart;
        item->mNextState = ((item->field0.mFlags & 0x40000000) || (kart->field48 & 1)) ? 2 : 3;
        item->mNextStateRequested = 1;
        if (item->field0.mFlags & 0x8000000) {
            sub_20FE71C(5, item->mKartItems->mKartIndex, item->field0.mId);
        }
    }
    itkraw_20FC94C(item);
    // one 36-byte copy of the three vectors (three Vec3 assignments give 0x160 bytes against 0x150)
    *(MtxFx33 *) &item->field0.field94 = *(MtxFx33 *) &itemInUse->mKartOrientation.field0;
    if (item->field0.mFlags & 0x8000000) {
        item->mNextState = 0;
        item->mNextStateRequested = 1;
    }
    return 1;
}

void itkraw_20FC654(ItemKouraW *item) {
    Vec3 buf;
    s16 v;
    s32 a;

    a = item->field260;
    if (item->field0.mFlags & 0x40000000) {
        item->mDrawOffsetAngle += 0x5dc;
        v = FX_SinCosTable_[(item->mDrawOffsetAngle >> 4) * 2];
        VEC_MultAdd(a + (s32) (((s64) item->field264 * v) >> 12), &item->field0.mNormal, &item->field0.mPos, &buf);
        VEC_Subtract(&buf, &item->field0.mDrawPos, &buf);
        VEC_MultAdd(0x333, &buf, &item->field0.mDrawPos, &item->field0.mDrawPos);
    } else {
        item->field0.mDrawPos.y += item->field0.mVelocity.y >> 1;
        item->mDrawOffsetAngle += 0x5dc;
        v = FX_SinCosTable_[(item->mDrawOffsetAngle >> 4) * 2];
        a += (s32) (((s64) item->field264 * v) >> 12);
        a = a + item->field0.mPos.y - item->field0.mDrawPos.y;
        item->field0.mDrawPos.y += (s32) (((s64) a * 0x19a) >> 12);
        item->field0.mDrawPos.x = item->field0.mPos.x;
        item->field0.mDrawPos.z = item->field0.mPos.z;
    }
}

void itkraw_20FC2E8(ItemKouraW *item, Vec3 *direction, s32 followDelta, Vec3 *normal) {
    Vec3 buf;
    Vec3 v3;
    Vec3 *previousDirection = &item->field28C;
    Vec3 *smoothedDelta = &item->field298;
    s32 ok;

    if (normal != NULL) {
        if ((s64) direction->x * direction->x + (s64) direction->y * direction->y + (s64) direction->z * direction->z >=
            0x10) {
            vec_normalize(direction, &item->field0.field94.field0[2]);
        }
        smoothedDelta->x = ((s64) smoothedDelta->x * 0xccd) >> 12;
        smoothedDelta->y = ((s64) smoothedDelta->y * 0xccd) >> 12;
        smoothedDelta->z = ((s64) smoothedDelta->z * 0xccd) >> 12;
        VEC_MultAdd(0x3000, smoothedDelta, normal, &buf);
        vec_crossProduct(&buf, &item->field0.field94.field0[2], &buf);
        if ((s64) buf.x * buf.x + (s64) buf.y * buf.y + (s64) buf.z * buf.z >= 0x10) {
            vec_normalize(&buf, &item->field0.field94.field0[0]);
        }
    } else {
        if ((s64) direction->x * direction->x + (s64) direction->y * direction->y + (s64) direction->z * direction->z >=
            0x10) {
            vec_normalize(direction, &buf);
        }
        if (buf.x * buf.x + buf.z * buf.z < 0x112510) {
            return;
        }
        item->field0.field94.field0[2] = buf;
        if (followDelta != 0) {
            smoothedDelta->x += (s32) (((s64) (direction->x - previousDirection->x - smoothedDelta->x) * 0x148) >> 12);
            smoothedDelta->z += (s32) (((s64) (direction->z - previousDirection->z - smoothedDelta->z) * 0x148) >> 12);
        } else {
            smoothedDelta->x = ((s64) smoothedDelta->x * 0xc00) >> 12;
            smoothedDelta->z = ((s64) smoothedDelta->z * 0xc00) >> 12;
        }
        v3 = data_0216c6a8;
        v3.x = ((s64) smoothedDelta->x * 0x3000) >> 12;
        v3.z = ((s64) smoothedDelta->z * 0x3000) >> 12;
        buf = v3;
        vec_crossProduct(&buf, &item->field0.field94.field0[2], &item->field0.field94.field0[0]);
        if ((s64) item->field0.field94.field0[0].x * item->field0.field94.field0[0].x +
                (s64) item->field0.field94.field0[0].y * item->field0.field94.field0[0].y +
                (s64) item->field0.field94.field0[0].z * item->field0.field94.field0[0].z >=
            0x10) {
            ok = vec_normalize(&item->field0.field94.field0[0],
                                                    &item->field0.field94.field0[0]);
        } else {
            ok = 0;
        }
        if (ok == 0) {
            Vec3 t = {0, 0, 0};
            t.x = item->field0.field94.field0[0].z;
            t.z = -item->field0.field94.field0[0].x;
            item->field0.field94.field0[0] = t;
        }
    }
    vec_crossProduct(&item->field0.field94.field0[2], &item->field0.field94.field0[0],
                       &item->field0.field94.field0[1]);
    *previousDirection = *direction;
}

void itkraw_20FC2C0(ItemKouraW *item) {
    sm_execute(item->field2E8);
    func_020f9320(&item->field0, 0x3c000400u);
}

#pragma thumb off

void itkraw_20FC268(ItemKouraW *item) {
    AdvanceItemObjectMotion((DirectedItemObject *) item, 0xd000);
    if (item->field0.mFlags & 1) {
        return;
    }
    AdvanceSoundDistanceSquaredChange(&item->field300, item->field0.mDistanceSquaredAndFlags & ~0xc000001f);
    if (item->mSoundId == 1) {
        return;
    }
    StartSoundWhileRequested(&item->field0.mSoundSource, item->mSoundId, 0x7f, 0);
}

static inline Vec3 *func_020fbd98_inline(ItemKouraW *item) {
    if (item->mState >= 3) {
        if (item->mKartItems->mKart->field48 & 1) {
            return &item->mKartItems->mKart->mGroundNormal;
        }
    } else if (item->field0.mFlags & 0x40000000) {
        return &item->field0.mNormal;
    }
    return NULL;
}

void itkraw_20FBD98(ItemKouraW *item) {
    u32 i;
    s32 r;
    s32 v;
    void *normal;
    Kart *kart;

    if (item->mStateFrames == 8) {
        item->mPosStrip = trl_createTrail(item->field0.fieldD0);
    }
    AdvanceLinkFollowingItem((LinkFollowingItemObject *) item, item->field27C, 0x21, item->mRankKartIndex, 1);
    if (!(item->field0.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(&item->field300, item->field0.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->field0.mSoundSource, item->mSoundId, 0x7f, 0);
        }
    }
    item->field0.mVelocity.y -= (s32) (((s64) * (s32 *) item->field12C * 0x66) >> 12);
    if (item->field0.mFlags & 1) {
        return;
    }
    itkraw_20FC654(item);
    normal = func_020fbd98_inline(item);
    itkraw_20FC2E8(item, &item->field0.mVelocity, 1, normal);
    if (item->field278 == 0) {
        if (gRaceStatus->mRaceDone != 0) {
            item->mRank = 1;
            item->mRankKartIndex = gRaceStatus->mKartAtRank[(u8) item->mRank - 1];
        } else {
            item->mRankKartIndex = gRaceStatus->mKartAtRank[(u8) item->mRank - 1];
            while (rstat_hasDriverFinished(item->mRankKartIndex) != 0 && (u32) item->mRank < gRaceMultiConfig->mKartCount) {
                (item->mRank)++;
                item->mRankKartIndex = gRaceStatus->mKartAtRank[(u8) item->mRank - 1];
            }
        }
        if (item->mRankKartIndex ==
                (u16) (!(item->field0.field78 & 0x8000) ? (u16) (item->field0.field78 & ~0xff00) : 8) ||
            StructMQRacerEntry_HasFlags0x60(driver_getById(item->mRankKartIndex)) != 0) {
            item->field278 = 1;
        } else {
            item->mKartMask |= 1 << item->mRankKartIndex;
        }
    }
    if (item->field278 != 0) {
        u32 kartCount;
        kartCount = (u8) gRaceMultiConfig->mKartCount;
        for (i = 1; i <= kartCount; i = (u16) (i + 1)) {
            item->mRankKartIndex = gRaceStatus->mKartAtRank[(u8) i - 1];
            if (StructMQRacerEntry_HasFlags0x60(driver_getById(item->mRankKartIndex)) == 0) {
                break;
            }
        }
        item->mKartMask |= 1 << item->mRankKartIndex;
    }
    if (TrySetItemKouraWKartItems(item, item->mRankKartIndex) != 0) {
        kart = item->mKartItems->mKart;
        r = ((item->field0.mFlags & 0x40000000) || (kart->field48 & 1)) ? 2 : 3;
        item->mNextState = r;
        item->mNextStateRequested = 1;
        if (item->field0.mFlags & 0x8000000) {
            sub_20FE71C(5, item->mKartItems->mKartIndex, item->field0.mId);
        }
        return;
    }
    r = (u16) race_getFrameCounterModulo8();
    if ((item->mKartMask & (1 << r)) != 0 && item->mRankKartIndex != r && rstat_hasDriverFinished(r) != 0 &&
        TrySetItemKouraWKartItems(item, r) != 0) {
        kart = item->mKartItems->mKart;
        v = ((item->field0.mFlags & 0x40000000) || (kart->field48 & 1)) ? 2 : 3;
        item->mNextState = v;
        item->mNextStateRequested = 1;
        if (item->field0.mFlags & 0x8000000) {
            sub_20FE71C(5, item->mKartItems->mKartIndex, item->field0.mId);
        }
        return;
    }
    if (item->mStateFrames <= 0xa8c) {
        return;
    }
    v = (u16) gRaceStatus->mKartAtRank[0];
    if (item->mKartItems != NULL) {
        return;
    }
    if ((u32) v >= 8) {
        v = 0;
    }
    SetItemKouraWKartItems(item, (u16) v);
    kart = item->mKartItems->mKart;
    r = ((item->field0.mFlags & 0x40000000) || (kart->field48 & 1)) ? 2 : 3;
    item->mNextState = r;
    item->mNextStateRequested = 1;
}

void itkraw_20FBD4C(ItemKouraW *item) {
    item->field27C = VEC_Mag(&item->field0.mVelocity);
    item->field284 = 0x1e000;
    if (item->mKartItems->mKartIndex == gRaceMultiConfig->mEntryIndex) {
        item->mSoundId = 0xdd;
    }
}

void itkraw_20FBC18(ItemKouraW *item) {
    s32 r;
    void *normal;
    Kart *kart;

    kart = item->mKartItems->mKart;
    r = 0x800;
    if ((item->field0.mFlags & 0x10000000) && (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        r += 0x19a;
    }
    if (item->field27C > 0xd000) {
        item->field27C -= 0xccd;
    } else {
        item->field27C += 0xccd;
    }
    SteerItemKouraWAtAngleZero(item, r, item->field27C, item->field284);
    if (!(item->field0.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(&item->field300, item->field0.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->field0.mSoundSource, item->mSoundId, 0x7f, 0);
        }
    }
    if ((s64) item->field238.x * item->field238.x + (s64) item->field238.z * item->field238.z < 0x1900000000LL) {
        item->mNextState = 4;
        item->mNextStateRequested = 1;
    }
    itkraw_20FC654(item);
    normal = func_020fbd98_inline(item);
    itkraw_20FC2E8(item, &item->field0.mVelocity, 1, normal);
}

void itkraw_20FBAE0(ItemKouraW *item) {
    s32 i;
    void *normal;
    ItemPointLink *link;

    if (item->field27C > 0xd000) {
        item->field27C -= 0xccd;
    } else {
        item->field27C += 0xccd;
    }
    AdvanceLinkFollowingItem((LinkFollowingItemObject *) item, item->field27C, 0x21, item->mRankKartIndex, 1);
    if (!(item->field0.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(&item->field300, item->field0.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->field0.mSoundSource, item->mSoundId, 0x7f, 0);
        }
    }
    if (item->field0.mFlags & 1) {
        return;
    }
    itkraw_20FC654(item);
    normal = func_020fbd98_inline(item);
    itkraw_20FC2E8(item, &item->field0.mVelocity, 1, normal);
    link = item->mKartItems->field1F0.mLink;
    for (i = 0; i < 4; i++) {
        if (link == item->mTargetLink) {
            item->mNextState = 3;
            item->mNextStateRequested = 1;
        }
        link = link->mNextLinks[0];
    }
}

void itkraw_20FBA6C(ItemKouraW *item) {
    item->field264 = 0x5000;
    item->field288 = 0x3e8;
    VEC_Subtract(&item->field238, &item->field298, &item->field28C);
    if (item->mPosStrip != NULL) {
        trl_killTrail(item->mPosStrip);
        item->mPosStrip = NULL;
    }
    if (item->field0.mFlags & 0x8000000) {
        sub_20FE71C(5, item->mKartItems->mKartIndex, item->field0.mId);
    }
}

void itkraw_20FB7F8(ItemKouraW *item) {
    Vec3 direction;
    void *normal;

    if (item->field27C > 0xd000) {
        item->field27C -= 0xccd;
    } else {
        item->field27C += 0xccd;
    }
    item->field260 -= 0xccd;
    item->field288 += 0x2d;
    if ((u32) item->mAngle < 0x8000) {
        item->field284 -= 0x666;
    } else {
        item->field284 -= 0xccd;
    }
    SteerItemKouraWToNextAnglePoint(item, 0x4cd, item->field27C, item->field284, item->field288);
    if (!(item->field0.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(&item->field300, item->field0.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->field0.mSoundSource, item->mSoundId, 0x7f, 0);
        }
    }
    itkraw_20FC654(item);
    if ((u32) item->mAngle < 0x11f40) {
        normal = func_020fbd98_inline(item);
        if (normal != NULL) {
            direction.x = item->field250.x * 2;
            direction.y = item->field250.y * 2;
            direction.z = item->field250.z * 2;
            vec_crossProduct(normal, &direction, &direction);
            VEC_MultAdd(((s64) (item->mAngle - 0x10000) * 0xccd) >> 12, normal, &direction, &direction);
        } else {
            direction.x = ((s64) item->field250.z * 0x2000) >> 12;
            direction.y = ((s64) (item->mAngle - 0x10000) * 0xccd) >> 12;
            direction.z = -(s32) (((s64) item->field250.x * 0x2000) >> 12);
        }
        if (item->mStateFrames == 0) {
            VEC_Subtract(&direction, &item->field298, &item->field28C);
        }
        itkraw_20FC2E8(item, &direction, 1, normal);
        return;
    }
    item->mNextState = 5;
    item->mNextStateRequested = 1;
}

void itkraw_20FB770(ItemKouraW *item) {
    enum { K0 } kind;

    if (item->field0.fieldD0 == &item->field0.mDrawPos) {
        item->field0.mPos = item->field0.mDrawPos;
        item->field0.fieldD0 = &item->field0.mPos;
    }
    item->field260 = 0x28000;
    item->field264 = 0x333;
    kind = item->field0.mKind;
    item->field0.field100 = it_sItemParams[kind].field74;
    item->field0.mFlags |= 0x800000;
    item->field2A4 = item->field28C;
    item->field27C = 0x3000;
    item->field284 = 0x59a;
}

void itkraw_20FB61C(ItemKouraW *item) {
    Vec3 v;
    Vec3 *normal;
    s32 x;
    s32 y;
    s32 z;

    item->field260 += 0x4cd;
    SteerItemKouraWToKartForward(item, item->field264, item->field260);
    if (item->field264 < 0xb33) {
        item->field264 += 0x52;
    }
    if (item->field260 > 0x2d000) {
        item->mNextState = 6;
        item->mNextStateRequested = 1;
    }
    item->field27C -= 0xa14;
    item->field284 -= 0x102;
    if (item->field284 < 0x7b) {
        item->field284 = 0x7b;
    }
    normal = func_020fbd98_inline(item);
    if (normal != NULL) {
        VEC_MultAdd(item->field27C, normal, &item->field22C, &v);
    } else {
        z = item->field22C.z;
        y = item->field27C;
        x = item->field22C.x;
        v.x = x;
        v.y = y;
        v.z = z;
    }
    VEC_Subtract(&v, &item->field2A4, &v);
    VEC_MultAdd(item->field284, &v, &item->field2A4, &item->field2A4);
    itkraw_20FC2E8(item, &item->field2A4, 0, normal);
}

void itkraw_20FB5DC(ItemKouraW *item) {
    enum { K0 } kind;

    item->field260 = 0x28000;
    kind = item->field0.mKind;
    item->field0.field100 = it_sItemParams[kind].field74;
    item->field0.field100 += 0x800;
    func_020f9c6c(&item->field0);
}

void itkraw_20FB46C(ItemKouraW *item) {
    s32 grew;
    Vec3 hitOffset;

    item->field260 -= 0x7000;
    SteerItemKouraWToKartForward(item, 0xb33, item->field260);
    if (item->field260 < -0x32000) {
        sub_20F7104(&item->field0, 0);
        if (item->field0.mFlags & 0x8000000) {
            sub_20FE71C(5, item->mKartItems->mKartIndex, item->field0.mId);
        }
    } else {
        Vec3 *position;

        position = &item->field0.mPos;
        if (col_collide(position, &item->field0.mPrevPos, 0, item->field0.fieldDC, 4,
                          item->field0.mCollisionSlotIndex, &hitOffset, NULL, NULL, &item->field0.mCollisionBits,
                          NULL, NULL, NULL, NULL) != 0) {
            VEC_Add(&hitOffset, position, position);
            sub_20F7104(&item->field0, 0);
            if (item->field0.mFlags & 0x8000000) {
                sub_20FE71C(5, item->mKartItems->mKartIndex, item->field0.mId);
            }
        }
    }
    grew =
        GrowItemObjectScale(item, it_sItemParams[item->field0.mKind].field74, it_sItemParams[item->field0.mKind].field78);
    if (sub_20F9CE8(&item->field0) != 0) {
        return;
    }
    if (grew) {
        RefreshItemObjectScale(&item->field0);
    }
}

void itkraw_20FB35C(ItemKouraW *param_1) {
    NNSSndSeqPlayer **sndHandle;
    struct ModelEffect *effect;
    s32 *effectScale;

    param_1->field0.mFlags |= 0x800000;
    param_1->field0.field100 = 0;
    param_1->field0.mScale = data_02159d84;
    param_1->mModelEffect =
        expl_spawnEffect(1, &param_1->field0.mPos, sub_20F9160(&param_1->field0) == 0 ? 1 : 0);
    effect = param_1->mModelEffect;
    if (effect != NULL) {
        effectScale = effect->mScale;
        effectScale[0] = 0x1000;
        effectScale[1] = 0x1000;
        effectScale[2] = 0x1000;
    }
    it_20F91FC(param_1, 0xdf);
    if (data_0217c780 & 1) {
        sndHandle = sp_acquireElement(sound_getPoolById(0));
        if (SoundHandle_217D084.fieldC != 0) {
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(sndHandle, 0, 0xe0);
        }
    }
    cam_tryImpactShakePlayerCamera(param_1->field0.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
}

void itkraw_20FB2B4(ItemKouraW *item) {
    u32 stateFrames;

    stateFrames = item->mStateFrames;
    if (GrowItemObjectScale(item, gKouraWState7ScaleLimit, gKouraWState7ScaleStep)) {
        sub_20F9FA8(&item->field0);
    }
    if (stateFrames < 0x16) {
        return;
    }
    if (stateFrames == 0x16) {
        item->mHitSpinsKart = 1;
    } else if (stateFrames == 0x2a) {
        FreeItemObjectCollisionSlot((s32) item);
    }
    if (stateFrames <= 0x55) {
        return;
    }
    it_itemsetDestroyItem(&it_sItemsets[item->field0.mKind], &item->field0);
}

void *itkraw_20FB208(void *param_1, ItemKouraW *item, void *param_3) {
    void *r;
    void *t;

    if (item != NULL && param_3 != NULL) {
        func_020ff1b8(vec_dotProduct(&item->field0.mVelocity, (Vec3 *) &item->mDirection) < 0 ? 1 : 0,
                      &item->field0.mVelocity.y);
    }
    t = CopyItemObjectData(param_1, item, param_3);
    r = CopyItemPointLinkIndex(t, item != NULL ? (void *) &item->mPreviousLink : 0, param_3);
    if (item != NULL && param_3 == NULL) {
        func_020ff1a0(item->field0.mVelocity.y, &item->field2FC);
    }
    if (item != NULL && param_3 != NULL) {
        return sub_20FE8AC(item->field0.mKind);
    }
    return r;
}

void itkraw_20FB038(ItemKouraW *item) {
    s32 kartIndex;
    DirectionQuaternion directionQuaternion;
    Kart *kart;
    s32 nextState;

    sub_20F8E78(item);
    if (item->mPreviousLink != 0) {
        InitLinkFollowingItem((LinkFollowingItemObject *) item, 0x14, 0xcc, 1, 0, item->field2FC,
                              gRaceStatus->mKartAtRank[0], 1);
        sm_gotoState(&item->field2E8, 1);
    } else if (item->field0.mFlags & 0x8000000) {
        kartIndex = (u16) gRaceStatus->mKartAtRank[0];
        if (item->mKartItems == NULL) {
            SetItemKouraWKartItems(item, kartIndex);
            kart = item->mKartItems->mKart;
            nextState = ((item->field0.mFlags & 0x40000000) || (kart->field48 & 1)) ? 2 : 3;
            item->mNextState = nextState;
            item->mNextStateRequested = 1;
        }
    } else {
        kartIndex = (u16) gRaceStatus->mKartAtRank[0];
        SetItemKouraWKartItems(item, kartIndex);
        kart = item->mKartItems->mKart;
        nextState = ((item->field0.mFlags & 0x40000000) || (kart->field48 & 1)) ? 2 : 3;
        item->mNextState = nextState;
        item->mNextStateRequested = 1;
        if (item->field0.mFlags & 0x8000000) {
            sub_20FE71C(5, item->mKartItems->mKartIndex, item->field0.mId);
        }
    }
    itkraw_20FC94C(item);
    if ((s64) item->field0.mVelocity.x * item->field0.mVelocity.x +
            (s64) item->field0.mVelocity.y * item->field0.mVelocity.y +
            (s64) item->field0.mVelocity.z * item->field0.mVelocity.z >=
        0x10) {
        vec_normalize(&item->field0.mVelocity, &directionQuaternion.mDirection);
    }
    qrtn_fromForwardVec(&directionQuaternion.mDirection, &directionQuaternion.mQuaternion);
    qtrn_toMtx33(&item->field0.field94, &directionQuaternion.mQuaternion);
}

void itkraw_20FAED0(ItemKouraW *item, s32 param_2, s32 param_3) {
    u32 alpha;
    Vec3 scale;
    void *matrix;

    if (item->field0.mFlags & 0x2000) {
        if (IsItemObjectFartherFromCameraThan(&item->field0, 0x6a4) != 0) {
            return;
        }
    }
    scale.x = scale.z = item->field0.mScale.x;
    scale.y = item->field0.mScale.y;
    if (item->field0.mAlpha != 0x1f) {
        u32 i;
        NNSG3dResMdl *o;

        o = gKouraW->mResMdl;
        alpha = (u16) item->field0.mAlpha;
        for (i = 0; i < o->mInfo.mNumMat; i++) {
            NNS_G3dMdlSetMdlAlpha(o, i, alpha);
        }
    }
    if (item->field0.mFlags & 0x80000) {
        matrix = BuildItemObjectMatrix(&item->field0, (Vec3 *) param_2);
    } else {
        Vec3 *position;

        position = item->field0.fieldD0;
        item->field0.field94.field0[3].x = position->x >> 4;
        item->field0.field94.field0[3].y = position->y >> 4;
        item->field0.field94.field0[3].z = position->z >> 4;
        matrix = &item->field0.field94;
    }
    model2_renderModel(gKouraW, matrix, &scale, 0x1f);
    if (item->field0.mAlpha == 0x1f) {
        return;
    }
    {
        u32 i;
        NNSG3dResMdl *o;

        o = gKouraW->mResMdl;
        for (i = 0; i < o->mInfo.mNumMat; i++) {
            NNS_G3dMdlSetMdlAlpha(o, i, 0x1f);
        }
    }
}

void itkraw_20FAE74(ItemKouraW *item, s32 param_2, s32 param_3) {
    ModelEffect *effect;

    if (item->mState != 7) {
        itkraw_20FAED0(item, param_2, param_3);
        return;
    }
    effect = item->mModelEffect;
    if (effect == NULL) {
        return;
    }
    effect->mVisible = (item->field0.mFlags & 0x10000) == 0;
}

// Asks for state 7 unless the object is already in it; returns 1.
s32 itkraw_20FADE4(ItemKouraW *item) {
    if (item->mState != 7) {
        sm_init(&item->field2E8, (UnkFunc *const *) itkraw_sStates, 8, item);
        item->mNextState = 7;
        item->mNextStateRequested = 1;
        if ((item->field0.mFlags & 0x180000) == 0) {
            item->field0.mAdvance = (void (*)(struct ItemObject *)) itkraw_20FC2C0;
        }
        item->field0.mFlags &= ~0x8000;
        item->field0.mFlags |= 0x80000;
        func_020f9c6c(&item->field0);
        item->field0.field78 &= ~0x4000;
    }
    return 1;
}

BOOL IsItemKouraWState7(ItemKouraW *item) {
    return item->mState == 7;
}

Vec3 *GetItemKouraWState7Info(ItemKouraW *item, s32 *stateFrames, s32 *scaleRatio) {
    *stateFrames = item->mStateFrames;
    *scaleRatio = ((s64) item->field0.mScale.z * gKouraWState7InverseLimit) >> 12;
    return &item->field0.mPos;
}

#pragma thumb on

void itkraw_load(void) {
    s32 scaleLimit;
    s32 radiusRatio;
    s32 v;

    gKouraWState7ScaleLimit = 0x1e000;
    gKouraWState7InverseLimit = FX_Div(0x1000, gKouraWState7ScaleLimit);
    gKouraWState7ScaleStep = 0x299a;
    scaleLimit = gKouraWState7ScaleLimit;
    radiusRatio = it_sItemParams[5].field6C;
    v = ((s64) scaleLimit * radiusRatio) >> 12;
    data_0217bd34 = v;
    v >>= 12;
    data_0217bd34 = v;
    data_0217bd34 = v * v;
    gKouraW = it_loadItemModel(aKoura_w_nsbmd, aKoura_w_nsbtx);
    if (gRaceMultiConfig->mCourseId == COURSE_ID_RAINBOW) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(gKouraW->mResMdl, 0);
    }
}

#pragma thumb off

BOOL IsItemInfoObjectCountFree(s32 itemInfoIndex) {
    if (itemInfoIndex != 0x13) {
        return it_sItemsets[it_sItemConfigs[itemInfoIndex].mObjectKind].fieldC -
                   it_sItemsets[it_sItemConfigs[itemInfoIndex].mObjectKind].mReservedCount >=
               it_sItemConfigs[itemInfoIndex].mObjectCount;
    }
    return FALSE;
}

static inline BOOL func_020fab34_inline(s32 itemInfoIndex) {
    if (itemInfoIndex != 0x13) {
        return it_sItemsets[it_sItemConfigs[itemInfoIndex].mObjectKind].fieldC -
                   it_sItemsets[it_sItemConfigs[itemInfoIndex].mObjectKind].mReservedCount >=
               it_sItemConfigs[itemInfoIndex].mObjectCount;
    }
    return FALSE;
}

// Replaces the rolled item by the fallback item when nothing was rolled or no objects are free for it; returns TRUE
// when it did.
BOOL ReplaceUnavailableItem(s32 *itemInfoIndexPointer) {
    s32 itemInfoIndex;
    s32 v;
    ItemInfo *itemInfo;
    s32 objectCount;

    itemInfoIndex = *itemInfoIndexPointer;
    if (itemInfoIndex == 0x13) {
        goto done;
    }
    if (gRaceMultiConfig->mMode == 5) {
        itemInfo = &it_sItemConfigs[itemInfoIndex];
        objectCount = itemInfo->mObjectCount;
        v = objectCount * func_020fa0e8(itemInfo->mObjectKind, 0);
        if (func_020fab34_inline(itemInfoIndex) != FALSE && gStruct217AA14->field724 >= v) {
            return FALSE;
        }
    } else {
        if (func_020fab34_inline(itemInfoIndex) != FALSE) {
            return FALSE;
        }
    }
done:
    *itemInfoIndexPointer = gRaceMultiConfig->mMode == 5 ? 4 : 2;
    return TRUE;
}

BOOL TryReleaseItemObjectsForItemInfo(s32 itemInfoIndex) {
    ItemInfo *itemInfo;
    s32 objectCount;
    ItemPool *pool;
    enum { K0 } kind;

    itemInfo = &it_sItemConfigs[itemInfoIndex];
    kind = itemInfo->mObjectKind;
    pool = &it_sItemsets[kind];
    objectCount = itemInfo->mObjectCount;
    while (pool->fieldC - pool->mReservedCount < objectCount) {
        if (it_sItemParams[kind].mLimit == 1) {
            return FALSE;
        }
        if (TryReleaseFirstItemObject(pool) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void sub_20FA9E4(void) {
    enum { K0 } poolIndex;
    u16 kartIndex;

    for (poolIndex = 0; poolIndex < 0xe; poolIndex++) {
        TryReleaseFirstItemObject(&it_sItemsets[poolIndex]);
    }
    for (kartIndex = 0; kartIndex < it_sDriverCount; kartIndex++) {
        ReleaseKartItems(&it_sDriverItemStatus[kartIndex]);
    }
}

void it_updateAll(void) {
    enum { K0 } poolIndex;
    u16 kartIndex;

    if (gRaceMultiConfig->mMode == 5) {
        sub_20FEC30();
        sub_20FEB44();
    }
    for (poolIndex = 0; poolIndex < 0xe; poolIndex++) {
        if (it_sItemsets[poolIndex].mActiveCount != 0) {
            UpdateItemPool(&it_sItemsets[poolIndex]);
        }
    }
    for (kartIndex = 0; kartIndex < it_sDriverCount; kartIndex++) {
        it_driverUpdateItemStatus(&it_sDriverItemStatus[kartIndex]);
    }
    sub_20F8258();
    cspl_update();
    UpdateBouncingItemBoxTimers();
}

void it_renderAll(void *a) {
    enum { K0 } poolIndex;
    void *viewAxis;

    viewAxis = &((Unk020e6b38 *) bbm_getBillboardMtx())->field18;
    bbm_restoreCameraMtx();
    for (poolIndex = 0; poolIndex < 0xe; poolIndex++) {
        if (it_sItemsets[poolIndex].mTakenCount > 0 && it_sItemsets[poolIndex].field40 == 0) {
            it_renderItemset(&it_sItemsets[poolIndex], viewAxis);
        }
    }
}

void StartItemSlotForKart(s32 kartIndex, s32 param_2, s32 param_3) {
    s32 playerKind;
    BOOL isHumanGhostOrPeer;

    if (it_sDriverItemStatus[kartIndex].mHeldItem.mItemInfoIndex != 0x13) {
        return;
    }
    playerKind = gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mKind;
    if (playerKind == PLAYER_KIND_PEER) {
        return;
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        isHumanGhostOrPeer = FALSE;
        if ((u32) playerKind > 3) {
        } else if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
        StartItemSlot(&it_sDriverItemStatus[kartIndex], param_2, mgcnt_20A1CD8(kartIndex), isHumanGhostOrPeer ? 1 : 0,
                      param_3);
    } else {
        isHumanGhostOrPeer = FALSE;
        if ((u32) playerKind > 3) {
        } else if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
        StartItemSlot(&it_sDriverItemStatus[kartIndex], param_2, rstat_getPlace(kartIndex), isHumanGhostOrPeer ? 1 : 0, param_3);
    }
}

static inline s32 func_020fa4c8_inline(ItemObject *item, Kart *kart) {
    Vec3 previousDelta;
    Vec3 delta;
    s32 previousDistanceSquared;
    s32 distanceSquared;
    s32 radius;
    s32 x;
    s64 fullDistanceSquared;

    if (!(item->mFlags & 0x8000)) {
        return 1;
    }
    if (kart->mIndex != (u16) (!(item->field78 & 0x8000) ? (u16) (item->field78 & ~0xff00) : 8)) {
        return 1;
    }
    if (item->mVelocity.x != 0 || item->mVelocity.y != 0 || item->mVelocity.z != 0 || kart->mForwardSpeed != 0) {
        VEC_Subtract(&item->mPrevPos, &kart->mPrevPointAlongUp, &previousDelta);
        previousDelta.y = 0;
        VEC_Subtract(&item->mPos, &kart->mPointAlongUp, &delta);
        delta.y = 0;
        previousDistanceSquared = vec_dotProduct(&previousDelta, &previousDelta);
        distanceSquared = vec_dotProduct(&delta, &delta);
        if (previousDistanceSquared - 0x1000 > distanceSquared) {
            return 1;
        }
    }
    radius = item->mRadius;
    x = item->mPos.x - kart->mPointAlongUp.x;
    fullDistanceSquared =
        (s64) (item->mPos.z - kart->mPointAlongUp.z) * (item->mPos.z - kart->mPointAlongUp.z) +
        ((s64) x * x + (s64) (item->mPos.y - kart->mPointAlongUp.y) * (item->mPos.y - kart->mPointAlongUp.y));
    return fullDistanceSquared < (s64) radius * radius ? 1 : 0;
}

// Returns how many item objects hit the kart; GetCollidedItemObject reads them.
s32 it_20FA4C8(Kart *kart) {
    s32 i;
    s32 hitCount;
    BOOL fl;
    s32 v;
    s32 lim;
    ItemObject *item;
    enum { K0 } kind;

    hitCount = 0;
    fl = (kart->field48 & 0x8000000) != 0;
    lim = 0xf;
    for (i = 0; i < gColQueryResultCount; i++) {
        if (!(gColQueryResultFlags[i] & 0x4000)) {
            continue;
        }
        item = gColQueryResultObjects[i];
        if (fl && !(item->mFlags & 0x200000)) {
            continue;
        }
        if (!it_20F97E0(item, kart)) {
            continue;
        }
        v = func_020fa4c8_inline(item, kart);
        if (v == 0) {
            continue;
        }
        if ((kart->field7C & 0x2000) && sub_20F9880(item) != 0) {
            continue;
        }
        gCollidedItemObjects[hitCount++] = item;
        if (item->mFlags & 0x1000) {
            RemoveItemInUseObject(&it_sDriverItemStatus[(u16) (item->field78 & ~0xff00)].mItemInUse, item);
        }
        kind = item->mKind;
        if (it_sItemParams[kind].field88 != 0) {
            if (sub_20F9880(item) != 0) {
                sub_20F6BE8(item, &kart->mCollisionCenter, &kart->mVelocity, &kart->mSignedTurnedForward);
                sub_20F6F10(item, 1, (u16) kart->mIndex);
            } else {
                sub_20F7430(item, 1);
            }
        }
        if (hitCount >= 0x10) {
            hitCount = lim;
        }
    }
    return hitCount;
}

#pragma thumb on

#pragma thumb off

struct ItemObject *GetCollidedItemObject(u32 index) {
    return gCollidedItemObjects[index];
}

#pragma thumb off

void *it_spawnItem(s32 kind, u16 param_2, void *param_3, void *param_4) {
    ItemObject *item;
    ItemPool *pool;

    item = 0;
    if (it_sItemsets[kind].mLimit - it_sItemsets[kind].mReservedCount <= 0) {
        return 0;
    }
    it_itemsetAcquireItems(&it_sItemsets[kind], 1, &item, param_2, param_3);
    pool = &it_sItemsets[kind];
    pool->mReservedCount++;
    it_itemsetAddItem(&it_sItemsets[item->mKind], item);
    it_20F98A0(item, param_3, param_4, 0, 0);
    if (param_2 == 8) {
        item->field78 |= data_02159cbc;
    }
    return item;
}

#pragma thumb on

static inline ItemObject *func_020fa3d0_inline(s32 kind, u16 param_2, void *param_3, void *param_4) {
    ItemObject *item;
    ItemPool *pool;

    item = 0;
    if (it_sItemsets[kind].mLimit - it_sItemsets[kind].mReservedCount <= 0) {
        return 0;
    }
    it_itemsetAcquireItems(&it_sItemsets[kind], 1, &item, param_2, param_3);
    pool = &it_sItemsets[kind];
    pool->mReservedCount++;
    it_itemsetAddItem(&it_sItemsets[item->mKind], item);
    it_20F98A0(item, param_3, param_4, 0, 0);
    if (param_2 == 8) {
        item->field78 |= data_02159cbc;
    }
    return item;
}

// Starts an item object at every course map row of object kind 0x6d and rests it on the floor.
void StartCourseMapItemObjects(void) {
    u32 i;
    u32 rowCount;
    u32 v;
    ItemObject *item;
    Vec3 m;
    enum { K0 } kind;
    CourseMapRow *row;

    rowCount = gMapData->mRowCount;
    for (i = 0; i < rowCount; i++) {
        row = &gMapData->mRows[i];
        if (row->mKind == 0x6d) {
            kind = row->field28;
            if (col_collide(row, 0, 0, 0xa000, 8, -2, 0, &m, 0, 0, 0, 0, 0, &v) == 0) {
                m = data_02159cb0;
            }
            item = func_020fa3d0_inline(kind, 8, row, &m);
            if (item != 0) {
                void (*advance)(ItemObject *);

                kind = item->mKind;
                advance = it_sItemParams[kind].mAdvance;
                if ((item->mFlags & 0x180000) == 0) {
                    item->mAdvance = advance;
                }
                StartRestingItemObject(item, &v);
            }
        }
    }
}

void InitializeItems(void) {
    void *heap;
    s32 a;
    s32 i;
    enum { K0 } kind;
    HeldItem *heldItem;
    u8 kartCount;

    heap = proc_getHeap(proc_getCurrent());
    a = 0;
    LoadItemSlotList();
    sub_20F82E8(1);
    sub_20F82C4(1);
    sub_20F82A4(1);
    it_initItemConfig();
    items_20F1A24();
    CreateItemPushVector();
    InitItemPointLinkDirections();
    kartCount = gRaceMultiConfig->mKartCount;
    it_sDriverCount = kartCount;
    it_sDriverItemStatus = heap_alloc(heap, kartCount * 0x210);
    for (i = 0; i < it_sDriverCount; i++) {
        InitKartItems(&it_sDriverItemStatus[i], (u16) i);
    }
    it_sItemsets = heap_alloc(heap, 0x3b8);
    for (kind = 0; kind < 0xe; kind++) {
        it_initItemset(&it_sItemsets[kind], kind, &a);
    }
    it_loadAllModels();
    if (gRaceMultiConfig->mMode == 5) {
        func_020fe46c();
        func_020fe450();
    }
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
        for (i = 0; i < it_sDriverCount; i++) {
            heldItem = &it_sDriverItemStatus[i].mHeldItem;
            SetHeldItem(heldItem, 5);
            switch (chkrt_getKartABC((u16) i)) {
                case 0:
                    it_takeSlotItems(heldItem, 1);
                    break;
                case 1:
                    it_takeSlotItems(heldItem, 2);
                    break;
            }
        }
    }
    gCollidedItemObjects = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    StartCourseMapItemObjects();
    CreateItemTeresaFrameScaleTable();
    cspl_init();
    InitBouncingItemBoxTimers();
}

s32 func_020fa0e8(s32 kind, s32 param_2) {
    switch (param_2) {
        case 0:
            return (u8) ((u8) it_sItemParams[kind].mDataSize + 1);
        case 1:
            return 0x12;
        case 2:
            return 3;
        case 3:
            return (u8) ((kind == 0xb ? 3 : 2) + 1);
    }
    return 0;
}

#pragma thumb off

s32 GrowItemObjectScale(void *objectParam, s32 limit, s32 step) {
    ItemObject *item = objectParam;

    if (item->mScale.z < limit) {
        item->mScale.z += step;
        if (item->mScale.z > limit) {
            item->mScale.z = limit;
        }
        return 1;
    }
    return 0;
}

void RefreshItemObjectScale(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    kind = item->mKind;
    item->mFlags |= 0x40;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &it_sItemParams[kind];
    radiusRatio = kindInfo->field6C;
    item->fieldDC = ((s64) item->mScale.y * kindInfo->field64) >> 12;
    item->mRadius = ((s64) item->mScale.y * radiusRatio) >> 12;
    col_setBoundingSphereRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
}

void sub_20F9FA8(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    kind = item->mKind;
    item->mFlags |= 0x40;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &it_sItemParams[kind];
    radiusRatio = kindInfo->field6C;
    item->fieldDC = ((s64) item->mScale.y * kindInfo->field64) >> 12;
    item->mRadius = ((s64) item->mScale.y * radiusRatio) >> 12;
    col_setBoundingSphereRadius(item->mCollisionSlotIndex, item->mRadius);
}

void SetItemObjectScaleByRatios(ItemObject *objectParam, s32 xRatio, s32 yRatio) {
    ItemObject *item = objectParam;
    enum { K0 } kind;
    s32 m;

    kind = item->mKind;
    m = it_sItemParams[kind].field68;
    item->mScale.x = ((s64) item->mScale.z * xRatio) >> 12;
    item->mScale.y = ((s64) item->mScale.z * yRatio) >> 12;
    item->fieldDC = ((s64) item->mScale.y * it_sItemParams[kind].field64) >> 12;
    item->mRadius = ((s64) item->mScale.y * m) >> 12;
    col_setBoundingSphereRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
}

s32 func_020f9dc8(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    if (item->field100 <= -0x29 || item->field100 >= 0x29 || item->mScale.x - item->mScale.y <= -0x29 ||
        item->mScale.x - item->mScale.y >= 0x29) {
        kind = item->mKind;
        item->mFlags |= 0x40;
        item->mScale.y += item->field100;
        item->field100 += (s32) (((s64) (item->mScale.z - item->mScale.y) * 0x333) >> 12);
        item->field100 = ((s64) item->field100 * 0xc00) >> 12;
        item->mScale.x = item->mScale.z * 2 - item->mScale.y;
        kindInfo = &it_sItemParams[kind];
        radiusRatio = kindInfo->field6C;
        item->fieldDC = ((s64) item->mScale.y * kindInfo->field64) >> 12;
        item->mRadius = ((s64) item->mScale.y * radiusRatio) >> 12;
        col_setBoundingSphereRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
        return 1;
    }
    item->field100 = 0;
    return 0;
}

s32 sub_20F9CE8(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    if (item->field100 != 0) {
        kind = item->mKind;
        item->mFlags |= 0x40;
        item->mScale.y += (s32) (((s64) (item->field100 - item->mScale.y) * 0x333) >> 12);
        item->mScale.x = item->mScale.z * 2 - item->mScale.y;
        kindInfo = &it_sItemParams[kind];
        radiusRatio = kindInfo->field6C;
        item->fieldDC = ((s64) item->mScale.y * kindInfo->field64) >> 12;
        item->mRadius = ((s64) item->mScale.y * radiusRatio) >> 12;
        col_setBoundingSphereRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
        return 1;
    }
    return 0;
}

void CreateItemObjectCollisionSlot(void *objectParam) {
    ItemObject *item = objectParam;

    if (item->mCollisionSlotIndex != -1) {
        return;
    }
    item->mCollisionSlotIndex = col_createColEntry(&item->mPos, item->mRadius + 0xa000, 0x4000, item);
}

void func_020f9c6c(ItemObject *item) {
    if (item->mCollisionSlotIndex != -1) {
        return;
    }
    item->mCollisionSlotIndex = col_createColEntry(&item->mPos, item->mRadius, 0x4000, item);
}

#pragma thumb on
