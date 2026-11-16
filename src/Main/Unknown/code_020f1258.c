#include "Main/Unknown/code_020f1258.h"

#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02061654.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020f1d70.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

BOOL func_020f14a0(ItemKouraR *item, s32 speed, s32 gain, s32 d) {
    Vec3 t;
    Vec3 firstNormal;
    Vec3 secondNormal;
    s32 n;
    BOOL sameNormal;
    Vec3 *pos;
    Vec3 *velocity;
    Kart *kart;
    BOOL result;

    result = FALSE;
    pos = &item->field0.field0.field0.mPos;
    velocity = &item->field0.field0.field0.mVelocity;
    if ((item->field0.field0.field0.field48 & 1) == race_getIsOddFrame()) {
        kart = item->mKartItems->mKart;
        if (!(item->field0.field0.field0.mFlags & 0x20000)) {
            if (func_0206c0e0(kart) != FALSE) {
                speed >>= 1;
            }
            VEC_Subtract(&kart->mDrawMatrixPos, pos, &t);
            t.y = vec_dotProduct(&item->field0.field0.field0.mNormal, &t) >> 12;
            if (t.y * t.y > 0xbd1) {
                if ((s64) t.x * t.x + (s64) t.z * t.z < (s64) 0xe1000000u) {
                    result = TRUE;
                }
            }
            n = 0;
            t.y = 0;
            if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
                n = vec_normalize(&t, &t);
            }
            t.x = ((s64) t.x * speed) >> 12;
            t.y = ((s64) t.y * speed) >> 12;
            t.z = ((s64) t.z * speed) >> 12;
            if (item->field0.field0.field0.mFlags & 0x8000000) {
                if (n < (s32) (((s64) kart->mPhysicalParam->mRadius * kart->mScale.z + 0x800) >> 12)) {
                    item->field238 = item->field238 + 1;
                    if (item->field238 > 0x5a) {
                        func_020f7070(item, 1);
                        return FALSE;
                    }
                    t.x = 0;
                    t.y = 0;
                    t.z = 0;
                }
            }
            VEC_Subtract(&t, &item->field22C, &t);
            if (0x64000 - n > 0) {
                gain += (s32) (((s64) (0x64000 - n) * 16) >> 12);
            }
            t.x = ((s64) t.x * gain) >> 12;
            t.y = ((s64) t.y * gain) >> 12;
            t.z = ((s64) t.z * gain) >> 12;
            VEC_Add(&item->field22C, &t, &item->field22C);
            VEC_Subtract(&item->mKartItems->mKart->mVelocity, velocity, &t);
            t.y = 0;
            t.x = ((s64) t.x * gain) >> 12;
            t.y = ((s64) t.y * gain) >> 12;
            t.z = ((s64) t.z * gain) >> 12;
            VEC_Add(velocity, &t, velocity);
        }
    }
    item->mKartItems->field208 = TRUE;
    VEC_Add(&item->field22C, pos, pos);
    VEC_Add(velocity, pos, pos);
    if (col_collide(&pos->x, (u32 *) &item->field0.field0.field0.mPrevPos, 0,
                      item->field0.field0.field0.fieldDC, 4, item->field0.field0.field0.mCollisionSlotIndex,
                      &t, &firstNormal, (s32 *) &secondNormal, &item->field0.field0.field0.mCollisionBits, NULL,
                      NULL, NULL, NULL) != 0) {
        VEC_Add(&t, pos, pos);
        if (item->field0.field0.field0.mCollisionBits & 0x1e34ef) {
            n = VEC_DotProduct(&firstNormal, velocity);
            velocity->x = velocity->x - (s32) (((s64) firstNormal.x * n) >> 12);
            velocity->y = velocity->y - (s32) (((s64) firstNormal.y * n) >> 12);
            velocity->z = velocity->z - (s32) (((s64) firstNormal.z * n) >> 12);
            sameNormal = (firstNormal.x == item->field0.field0.field0.mNormal.x &&
                          firstNormal.y == item->field0.field0.field0.mNormal.y &&
                          firstNormal.z == item->field0.field0.field0.mNormal.z);
            if (sameNormal == FALSE) {
                item->field0.field0.field0.mNormal = firstNormal;
                item->field0.field0.field0.mFlags |= 0x100;
            }
        }
        if (item->field0.field0.field0.mCollisionBits & 0x214300) {
            if (item->field0.field0.field158 == 0 && d != 0) {
                n = VEC_DotProduct(&secondNormal, velocity);
                t.x = ((s64) secondNormal.x * n) >> 12;
                t.y = ((s64) secondNormal.y * n) >> 12;
                t.z = ((s64) secondNormal.z * n) >> 12;
                velocity->x = velocity->x - t.x;
                velocity->y = velocity->y - t.y;
                velocity->z = velocity->z - t.z;
                VEC_Subtract(velocity, &t, velocity);
                velocity->x = ((s64) velocity->x * 0x23d) >> 12;
                velocity->y = ((s64) velocity->y * 0x23d) >> 12;
                velocity->z = ((s64) velocity->z * 0x23d) >> 12;
                func_020f6fc4(item, 1);
                return FALSE;
            }
        }
        if (item->field0.field0.field0.mCollisionBits & 0x8000) {
            func_020f7070(item, 1);
            return FALSE;
        }
    }
    func_020f2028(&item->field0.field0.field0);
    return result;
}

int TrySetItemKouraRKartItems(ItemKouraR *item, int kartIndex, s32 maxDistanceSquared, u32 checkRank) {
    u16 ownerIndex;
    Kart *kart;
    u32 kartRank;
    s32 ownerRank;
    Vec3 offset;
    s32 distanceSquared;
    s32 dot;
    s32 offsetSquared;
    s32 velocitySquared;
    s64 dotSquared;
    s64 lengthProduct;

    kart = driver_getById(kartIndex);
    ownerIndex = !(item->field0.field0.field0.field78 & 0x8000)
                     ? (u16) (item->field0.field0.field0.field78 & ~0xff00)
                     : 8;
    kartRank = rstat_getPlace(kartIndex);
    if (ownerIndex < 8 && checkRank != 0) {
        ownerRank = rstat_getPlace(ownerIndex);
        if (ownerRank <= kartRank) {
            if (ownerRank != 1) {
                return 0;
            }
            if (kartRank > 3) {
                return 0;
            }
        }
    }
    if ((kart->field7C & 0x402020) || (kart->field4C & 0x800) || (kartRank != 1 && kart->mState != KART_STATE_NORMAL)) {
        return 0;
    }
    driver_getPosition(&offset, kartIndex);
    VEC_Subtract(&offset, &item->field0.field0.field0.mPos, &offset);
    distanceSquared = (offset.x >> 12) * (offset.x >> 12);
    distanceSquared += (offset.z >> 12) * (offset.z >> 12);
    if (distanceSquared > 0x27100 || (maxDistanceSquared != 0 && distanceSquared > maxDistanceSquared)) {
        return 0;
    }
    dot = vec_dotProduct(&item->field0.field0.field0.mVelocity, &offset);
    if (dot < 0) {
        return 0;
    }
    offsetSquared = vec_dotProduct(&offset, &offset) >> 12;
    velocitySquared =
        vec_dotProduct(&item->field0.field0.field0.mVelocity, &item->field0.field0.field0.mVelocity);
    lengthProduct = (s64) velocitySquared * offsetSquared;
    dotSquared = (s64) dot * (dot >> 12);
    if ((s32) (dotSquared >> 12) < (s32) (((s64) (s32) (lengthProduct >> 12) * 0x400) >> 12)) {
        return 0;
    }
    dot = vec_dotProduct(&item->field0.field0.field0.mNormal, &offset);
    if ((dot >> 12) * (dot >> 12) > 0x9c4) {
        return 0;
    }
    if (item->field0.field0.field0.mFlags & 0x10000000) {
        return 0;
    }
    item->mKartItems = &it_sDriverItemStatus[kartIndex];
    item->field22C.x = 0;
    item->field22C.y = 0;
    item->field22C.z = 0;
    item->field238 = 0;
    return distanceSquared;
}
