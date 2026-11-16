#include "Main/Unknown/code_020fcf10.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"

void SteerItemKouraWToAnglePoint(ItemKouraW *item, s32 maxStep, s32 angle, s32 radius, s32 gain, s32 oldWeight,
                                 s32 shift) {
    Vec3 t;
    Vec3 *toTarget;
    Vec3 *pos;
    Vec3 *velocity;
    Kart *kart;
    s32 s;

    kart = item->mKartItems->mKart;
    item->field22C = kart->mSignedTurnedForward;
    pos = &item->field0.mPos;
    velocity = &item->field0.mVelocity;
    toTarget = &item->field238;
    if (kart->field44 & 0x100) {
        item->field22C.x = -item->field22C.x;
        item->field22C.y = -item->field22C.y;
        item->field22C.z = -item->field22C.z;
    }
    vec_crossProduct(&item->field22C, &kart->mGroundNormal, &t);
    s = ((s64) radius * FX_SinCosTable_[(angle >> 4) * 2 + 1]) >> 12;
    item->field250.x = ((s64) t.x * s) >> 12;
    item->field250.y = ((s64) t.y * s) >> 12;
    item->field250.z = ((s64) t.z * s) >> 12;
    s = ((s64) radius * FX_SinCosTable_[(angle >> 4) * 2]) >> 12;
    VEC_MultAdd(s, &item->field22C, &item->field250, &item->field250);
    VEC_MultAdd(0x1e000, &item->field22C, &item->field250, &t);
    if (StructMQRacerEntry_SomeFn_64(kart) == FALSE) {
        item->field244 = kart->mDrawMatrixPos;
    }
    VEC_Add(&t, &item->field244, &t);
    VEC_Subtract(&t, pos, toTarget);
    t.x = ((s64) toTarget->x * gain) >> 12;
    t.y = ((s64) toTarget->y * gain) >> 12;
    t.z = ((s64) toTarget->z * gain) >> 12;
    if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= (s64) maxStep * maxStep) {
        if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
            vec_normalize(&t, &t);
        }
        t.x = ((s64) t.x * maxStep) >> 12;
        t.y = ((s64) t.y * maxStep) >> 12;
        t.z = ((s64) t.z * maxStep) >> 12;
    }
    velocity->x = (velocity->x * (s32) oldWeight + t.x) >> shift;
    velocity->y = (velocity->y * (s32) oldWeight + t.y) >> shift;
    velocity->z = (velocity->z * oldWeight + t.z) >> shift;
    VEC_Add(velocity, pos, pos);
    if (col_collide(pos, &item->field0.mPrevPos, 0, item->field0.fieldDC, 4, item->field0.mCollisionSlotIndex,
                      &t, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    if ((kart->field48 & 1) == 0) {
        pos->y += t.y;
        return;
    }
    VEC_Add(pos, &t, pos);
}
