#include "Main/Unknown/code_020a0028.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_0209b000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146cbc.h"

void aship_loadModel(void *a) {
    aship_sModel = mobj_loadModel(a, aAirship_nsbmd);
    mobj_setModelPolygonIdAll(aship_sModel, 0x3f);
}

void aship_render(void *a, Airship *airship) {
    s32 v;
    s32 rotationMatrix[9];
    Vec3 w;

    v = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v, 1);
    w.y = (airship->fieldA0 + airship->mWobbleOffset) >> 4;
    w.x = 0;
    w.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &w, 3);
    airship->field0.mMatrix.field0[3].x = airship->field0.mPos.x >> 4;
    airship->field0.mMatrix.field0[3].y = airship->field0.mPos.y >> 4;
    airship->field0.mMatrix.field0[3].z = airship->field0.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &airship->field0.mMatrix, 0xc);
    if (airship->field0.mAngle != 0) {
        MTX_RotY33_(rotationMatrix, FX_SinCosTable_[((airship->field0.mAngle >> 4) << 1)],
                    FX_SinCosTable_[((airship->field0.mAngle >> 4) << 1) + 1]);
        NNS_G3dGeBufferOP_N(0x1a, rotationMatrix, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &airship->field0.mScale, 3);
    mobj_renderModel(a, aship_sModel, airship);
}

void aship_globalLogicInit(AirshipObjectList *list) {
    s32 i;
    Airship *airship;
    BOOL z;
    s32 v;

    if (list == NULL) {
        return;
    }
    z = FALSE;
    for (i = 0; i < list->field4 && (airship = list->field0[i]) != NULL; i++) {
        pw_initFromObject(&airship->fieldC8, airship->field0.mCourseMapRow, z);
        airship->fieldA4 = (airship->field0.mCourseMapRow->field28 * 0x5000L) / 100;
        v = airship->fieldA4;
        airship->fieldC8.mSpeed = v;
        airship->fieldC8.mProgressStep =
            ((s64) v * airship->fieldC8.mPath->mSegments[airship->fieldC8.mSegmentIndex].mInverseProgressLength) >> 12;
        airship->fieldA0 = airship->field0.mPos.y;
        pw_20D8BF8_XYZ(&airship->fieldC8, &airship->field0.mPos, &airship->field0.field10);
        airship->fieldA0 = airship->fieldA0 - airship->field0.mPos.y;
        airship->mWobbleAngle = 0;
        airship->mWobbleMid = 0;
        airship->mWobbleAmplitude = 0x50000;
        airship->mWobbleAmplitudePerFrame = 0;
        airship->mWobbleAnglePerFrame = 0xb6;
        airship->fieldC4 = 0;
        if (airship->field0.mCourseMapRow->field2A != 0) {
            airship->mState = 0;
        } else {
            airship->mState = 2;
        }
    }
}

s32 aship_FX_CosIdx(s32 angle) {
    return FX_SinCosTable_[((angle >> 4) << 1) + 1];
}

s32 aship_FX_MulInline(s32 multiplicand, s32 multiplier) {
    return ((s64) multiplicand * multiplier + 0x800) >> 12;
}
