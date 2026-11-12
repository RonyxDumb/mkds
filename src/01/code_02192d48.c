#include "01/code_02192d48.h"

#include "01/code_02192000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "fx_mtx33.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/MapObjects/bound.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Item/item_koura_w.h"
#include "ITCM/code_01ff8000.h"
#include "code_02147cd8.h"

MapObjectModel *gStopSign;

void InitStopSign(MissionRunMapObject *mapObject) {
    MtxFx33 rotationMatrix;
    RefreshMapObjectMatrixFromHitNormal(&mapObject->mUnk_000);
    mapObject->mUnk_000.mAngle = DEG_TO_ANGLE(mapObject->mUnk_000.mCourseMapRow->mRotationDegrees.y);
    MTX_RotY33_(&rotationMatrix, FX_SinIdx(mapObject->mUnk_000.mAngle), FX_CosIdx(mapObject->mUnk_000.mAngle));
    MTX_Concat33(&rotationMatrix, &mapObject->mUnk_000.mMatrix.mAxes, &mapObject->mUnk_000.mMatrix.mAxes);
}

void LoadStopSign(MapObjectList *mapObjectList) {
    gStopSign = LoadMapObjectModelAnimated(mapObjectList, "StopSign.nsbmd");
    SetMapObjectModelPolygonId(gStopSign, 0x3f);
    SetMapObjectModelLightEnableFlag(gStopSign, 2);
    SetNsbmdEmiAll(gStopSign->mAnimatedModel, 0x294a);
}

void DrawStopSign(void *mapObjectList, StopSignObject *mapObject) {
    s32 commandValue = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandValue, 1);
    mapObject->mMatrixPosX = mapObject->mPosX >> 4;
    mapObject->mMatrixPosY = mapObject->mPosY >> 4;
    mapObject->mMatrixPosZ = mapObject->mPosZ >> 4;
    NNS_G3dGeBufferOP_N(0x19, mapObject->mMatrixAxes, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, mapObject->mScale, 3);
    DrawMapObjectModel(mapObjectList, gStopSign, mapObject);
}

void CreateStopSignKindData(void) {
    CreateMapObjectKindData(NULL, NULL, NULL, 0, 1);
}

void *CreateStopSignDrawList(void) {
    return CreateMapObjectDrawList1(LoadStopSign, DrawStopSign, NULL);
}
