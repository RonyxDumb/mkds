#include "01/code_02192d48.h"

#include "01/code_02192000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "ITCM/code_01ff8000.h"

Unk0219b250 *gStopSign;

void stsig_init(Unk02188950 *a) {
    s32 m[9];
    mobj_setDirectionFromFloor(a);
    a->field0.mAngle = (a->field0.mCourseMapRow->fieldC.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44;
    MTX_RotY33_(m, FX_SinCosTable_[(a->field0.mAngle >> 4) * 2], FX_SinCosTable_[(a->field0.mAngle >> 4) * 2 + 1]);
    MTX_Concat33(m, &a->field0.mMatrix.field0[0].x, &a->field0.mMatrix.field0[0].x);
}

void LoadStopSign(Unk0219b478 *a) {
    gStopSign = LoadMapObjectModelAnimated(a, "StopSign.nsbmd");
    mobj_setModelPolygonIdAll(gStopSign, 0x3f);
    mobj_setModelLightMask(gStopSign, 2);
    model_setEmi(gStopSign->mAnimatedModel, 0x294a);
}

void DrawStopSign(void *a, StopSignObject *b) {
    s32 v = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v, 1);
    b->field4C = b->field4 >> 4;
    b->field50 = b->field8 >> 4;
    b->field54 = b->fieldC >> 4;
    NNS_G3dGeBufferOP_N(0x19, b->field28, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, b->field1C, 3);
    mobj_renderModel(a, gStopSign, b);
}

void stsig_setupCollision(void) {
    mobj_createConfig(NULL, NULL, NULL, 0, 1);
}

void *stsig_setupRenderPart(void) {
    return mobj_createRenderPart3d(LoadStopSign, DrawStopSign, NULL);
}
