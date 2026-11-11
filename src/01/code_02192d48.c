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
#include "code_02147cd8.h"

MapObjectModel *gStopSign;

void InitStopSign(Unk02188950 *mapObject) {
    MtxFx33 rotationMatrix;
    RefreshMapObjectMatrixFromHitNormal(&mapObject->mUnk_000);
    mapObject->mUnk_000.mAngle =
        (mapObject->mUnk_000.mCourseMapRow->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44;
    MTX_RotY33_(&rotationMatrix, FX_SinIdx(mapObject->mUnk_000.mAngle), FX_CosIdx(mapObject->mUnk_000.mAngle));
    MTX_Concat33(&rotationMatrix, &mapObject->mUnk_000.mMatrix.mAxes, &mapObject->mUnk_000.mMatrix.mAxes);
}

void LoadStopSign(Unk0219b478 *mapObjectList) {
    gStopSign = LoadMapObjectModelAnimated(mapObjectList, "StopSign.nsbmd");
    SetMapObjectModelPolygonId(gStopSign, 0x3f);
    SetMapObjectModelLightEnableFlag(gStopSign, 2);
    SetNsbmdEmiAll(gStopSign->mAnimatedModel, 0x294a);
}

void DrawStopSign(void *mapObjectList, StopSignObject *mapObject) {
    s32 commandValue = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandValue, 1);
    mapObject->mUnk_4c = mapObject->mUnk_04 >> 4;
    mapObject->mUnk_50 = mapObject->mUnk_08 >> 4;
    mapObject->mUnk_54 = mapObject->mUnk_0c >> 4;
    NNS_G3dGeBufferOP_N(0x19, mapObject->mUnk_28, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, mapObject->mUnk_1c, 3);
    DrawMapObjectModel(mapObjectList, gStopSign, mapObject);
}

void CreateStopSignKindData(void) {
    CreateMapObjectKindData(NULL, NULL, NULL, 0, 1);
}

void *CreateStopSignDrawList(void) {
    return CreateMapObjectDrawList1(LoadStopSign, DrawStopSign, NULL);
}
