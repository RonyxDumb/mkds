#include "Main/Kart/kart_matrix.h"
#include "Main/Kart/kart_drift.h"

// Copies row 0 of the kart's matrix at 0x120 to the given vector.
u32 GetKartMatrixRow0(Kart *kart, Vec3 *out) {
    Vec3 *row;
    s32 value0;
    s32 rowX = kart->mRotationRow0.x;
    row = &kart->mRotationRow0;
    out->x = rowX;
    value0 = row->y;
    out->y = value0;
    value0 = row->z;
    out->z = value0;
    return value0;
}
