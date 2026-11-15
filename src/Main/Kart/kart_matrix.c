#include "Main/Kart/kart_matrix.h"
#include "Main/Kart/kart_drift.h"

// Copies row 0 of the kart's matrix at 0x120 to the given vector.
u32 GetKartMatrixRow0(Kart *kart, Vec3 *out) {
    Vec3 *row;
    s32 rowComponent;
    s32 rowX = kart->mRotationRow0.x;
    row = &kart->mRotationRow0;
    out->x = rowX;
    rowComponent = row->y;
    out->y = rowComponent;
    rowComponent = row->z;
    out->z = rowComponent;
    return rowComponent;
}
