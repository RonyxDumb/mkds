#include "01/MapObjects/stop_sign.h"

#include "Main/MapObjects/map_object_model_frame.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/Item/item_koura_w.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "vector_math.h"

MapObjectKindDescriptor gStopSignKindDescriptor = {
    0,    {0, 0}, 0xa0, InitStopSign, CreateStopSignKindData,  CreateStopSignDrawList,
    NULL, NULL,   NULL, NULL,         {NULL, NULL, NULL, NULL}};
MapObjectModel *gStopSign;

void InitStopSign(MissionRunMapObject *mapObject) {
    MtxFx33 rotationMatrix;
    RefreshMapObjectMatrixFromHitNormal(&mapObject->mMapObject);
    mapObject->mMapObject.mAngle = DEG_TO_ANGLE(mapObject->mMapObject.mCourseMapRow->mRotationDegrees.y);
    MTX_RotY33_(&rotationMatrix, FX_SinIdx(mapObject->mMapObject.mAngle), FX_CosIdx(mapObject->mMapObject.mAngle));
    MTX_Concat33(&rotationMatrix, &mapObject->mMapObject.mMatrix.mAxes, &mapObject->mMapObject.mMatrix.mAxes);
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

MapObjectKindData *CreateStopSignKindData(void) {
    return CreateMapObjectKindData(NULL, NULL, NULL, 0, 1);
}

MapObjectList *CreateStopSignDrawList(void) {
    return CreateMapObjectDrawList1(LoadStopSign, DrawStopSign, NULL);
}
