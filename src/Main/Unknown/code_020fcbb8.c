#include "Main/Unknown/code_020fcbb8.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020fcf10.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02077bc0.h"

void SteerItemKouraWToNextAnglePoint(ItemKouraW *item, s32 gain, s32 maxStep, s32 radius, u16 angleStep) {
    item->mAngle += angleStep;
    SteerItemKouraWToAnglePoint(item, maxStep, (u16) item->mAngle, radius, gain, 1, 1);
}

void SteerItemKouraWToKartForward(ItemKouraW *item, s32 gain, s32 lift) {
    Vec3 v;
    s32 flagBit0;
    Vec3 *pos;
    Vec3 *velocity;
    Kart *kart;

    kart = item->mKartItems->mKart;
    flagBit0 = (kart->field48 & 1) ? 1 : 0;
    item->field22C = kart->mSignedTurnedForward;
    pos = &item->field0.mPos;
    velocity = &item->field0.mVelocity;
    if (kart->field44 & 0x100) {
        item->field22C.x = -item->field22C.x;
        item->field22C.y = -item->field22C.y;
        item->field22C.z = -item->field22C.z;
    }
    if (func_0206c0b0(kart) == FALSE) {
        item->field244 = kart->mDrawMatrixPos;
    }
    VEC_MultAdd(0x14ffa, &item->field22C, &item->field244, &v);
    if (flagBit0 == 0) {
        v.y += lift;
    } else {
        VEC_MultAdd(lift, &kart->mGroundNormal, &v, &v);
    }
    VEC_Subtract(&v, pos, &v);
    velocity->x = ((s64) v.x * gain) >> 12;
    velocity->y = ((s64) v.y * gain) >> 12;
    velocity->z = ((s64) v.z * gain) >> 12;
    VEC_Add(velocity, pos, pos);
    if (flagBit0 == 0) {
        return;
    }
    if (col_collide(pos, &item->field0.mPrevPos, 0, item->field0.fieldDC, 4, item->field0.mCollisionSlotIndex,
                      &v, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    VEC_Add(pos, &v, pos);
}

BOOL TrySetItemKouraWKartItems(ItemKouraW *item, s32 kartIndex) {
    Kart *kart;
    KartItems *kartItems;
    Vec3 v;
    Vec3 *kartPos;
    s32 shortRange;
    s32 normalDistance;
    s32 offsetX;
    s32 offsetZ;

    kart = driver_getById(kartIndex);
    if (func_0206c0b0(kart) != FALSE) {
        return FALSE;
    }
    kartItems = &(it_sDriverItemStatus)[kartIndex];
    kartPos = &kart->mDrawMatrixPos;
    if (kartItems->field1F0.mLink != item->mTargetLink) {
        shortRange = ((item->field0.mFlags & 0x40000000) || (kart->field48 & 1)) ? 1 : 0;
        VEC_Subtract(kartPos, &item->field0.mPos, &v);
        offsetX = v.x >> 12;
        offsetZ = v.z >> 12;
        if (offsetX * offsetX + offsetZ * offsetZ > (shortRange ? 0x9c40 : 0x27100)) {
            return FALSE;
        }
        normalDistance = vec_dotProduct(&item->field0.mNormal, &v) >> 12;
        if (normalDistance * normalDistance > 0x9c4) {
            return FALSE;
        }
    }
    if (item->field0.mFlags & 0x10000000) {
        return FALSE;
    }
    item->mKartItems = kartItems;
    item->field244 = *kartPos;
    return TRUE;
}
