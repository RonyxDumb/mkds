#include "Main/MapObjects/empty_kind_data.h"

#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/data_0217b000.h"
#include "ITCM/code_01ff8000.h"

const u16 gPakkunSpitDisabledFlag = 1;
const u32 gPakkunSpitSkipSoundFlag = 0x40000000;

void *gBeachTree1;
void *gNsCannon1;
void *gKinoMount2;
void *gOsaTree1c;
void *gOm6Tree1;
void *gDeTree1;
void *gKinoHouse1;
void *gOpaTree1;
void *gOlgMush1;
void *gBankEgg1;
void *gMarioTree3;
void *gOlaTree1c;
void *gKinoMount1;
void *gKinoHouse2;
void *gBankTree1;
void *gCrossTree1;
void *gGardenTree1;
void *gTownTree1;
void *gSnowTree1;
void *gOf6Tree1;
void *gMiniDokan;
void *gOf6yoshi1;
void *gOlgPipe1;

MapObjectKindDescriptor gBeachTree1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateBeachTree1DrawList};
MapObjectKindDescriptor gDeTree1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateDeTree1DrawList};
MapObjectKindDescriptor gSnowTree1SecondKindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateSnowTree1DrawList};
MapObjectKindDescriptor gOlgMush1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateOlgMush1DrawList};
MapObjectKindDescriptor gOlgPipe1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateOlgPipe1DrawList};
MapObjectKindDescriptor gSnowTree1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateSnowTree1DrawList};
MapObjectKindDescriptor gNsCannon1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateNsCannon1DrawList};
MapObjectKindDescriptor gCrossTree1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateCrossTree1DrawList};
MapObjectKindDescriptor gBankTree1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateBankTree1DrawList};
MapObjectKindDescriptor gGardenTree1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateGardenTree1DrawList};
MapObjectKindDescriptor gGardenTree1SecondKindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateGardenTree1DrawList};
MapObjectKindDescriptor gTownTree1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateTownTree1DrawList};
MapObjectKindDescriptor gTownTree1SecondKindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateTownTree1DrawList};
MapObjectKindDescriptor gOf6yoshi1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateOf6yoshi1DrawList};
MapObjectKindDescriptor gMarioTree3KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateMarioTree3DrawList};
MapObjectKindDescriptor gOpaTree1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateOpaTree1DrawList};
MapObjectKindDescriptor gBeachTree1SecondKindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateBeachTree1DrawList};
MapObjectKindDescriptor gDeTree1SecondKindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateDeTree1DrawList};
MapObjectKindDescriptor gOlaTree1cKindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateOlaTree1cDrawList};
MapObjectKindDescriptor gOsaTree1cKindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateOsaTree1cDrawList};
MapObjectKindDescriptor gKinoHouse1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateKinoHouse1DrawList};
MapObjectKindDescriptor gOf6Tree1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateOf6Tree1DrawList};
MapObjectKindDescriptor gKinoHouse2KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateKinoHouse2DrawList};
MapObjectKindDescriptor gKinoMount1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateKinoMount1DrawList};
MapObjectKindDescriptor gKinoMount2KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateKinoMount2DrawList};
MapObjectKindDescriptor gOm6Tree1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateOm6Tree1DrawList};
MapObjectKindDescriptor gOf6Tree1SecondKindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateOf6Tree1DrawList};
MapObjectKindDescriptor gBankEgg1KindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateBankEgg1DrawList};
MapObjectKindDescriptor gMiniDokanKindDescriptor = {
    0, {0, 0}, 0xa0, 0, CreateEmptyKindDataWithSound, CreateMiniDokanDrawList};

MapObjectKindData *CreateEmptyKindDataWithSound(void) {
    MapObjectKindData *kindData;

    kindData = CreateEmptyMapObjectKindData();
    kindData->mSoundId = 0x84;
    return kindData;
}

void CreateBeachTree1(void *mapObjectList) {
    gBeachTree1 = CreateMapObjectModelNsbmd(mapObjectList, "BeachTree1.nsbmd");
    SetMapObjectModelPolygonId(gBeachTree1, 0x3f);
}

void SetupDrawBeachTree1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gBeachTree1);
}

void DrawBeachTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gBeachTree1, mapObject);
}

MapObjectList *CreateBeachTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateBeachTree1, DrawBeachTree1, SetupDrawBeachTree1);
}

void CreateOpaTree1(void *mapObjectList) {
    gOpaTree1 = CreateMapObjectModelNsbmd(mapObjectList, "opa_tree1.nsbmd");
    SetMapObjectModelPolygonId(gOpaTree1, 0x3f);
}

void SetupDrawOpaTree1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gOpaTree1);
}

void DrawOpaTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOpaTree1, mapObject);
}

MapObjectList *CreateOpaTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateOpaTree1, DrawOpaTree1, SetupDrawOpaTree1);
}

void CreateOlgMush1(void *mapObjectList) {
    gOlgMush1 = CreateMapObjectModelNsbmd(mapObjectList, "OlgMush1.nsbmd");
    SetMapObjectModelPolygonId(gOlgMush1, 0x3f);
}

void SetupDrawOlgMush1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gOlgMush1);
}

void DrawOlgMush1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOlgMush1, mapObject);
}

MapObjectList *CreateOlgMush1DrawList(void) {
    return CreateMapObjectDrawList2(CreateOlgMush1, DrawOlgMush1, SetupDrawOlgMush1);
}

void CreateOlgPipe1(void *mapObjectList) {
    gOlgPipe1 = CreateMapObjectModelNsbmd(mapObjectList, "OlgPipe1.nsbmd");
    SetMapObjectModelPolygonId(gOlgPipe1, 0x3f);
}

void SetupDrawOlgPipe1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gOlgPipe1);
}

void DrawOlgPipe1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOlgPipe1, mapObject);
}

MapObjectList *CreateOlgPipe1DrawList(void) {
    return CreateMapObjectDrawList2(CreateOlgPipe1, DrawOlgPipe1, SetupDrawOlgPipe1);
}

void CreateOf6yoshi1(void *mapObjectList) {
    gOf6yoshi1 = CreateMapObjectModelNsbmd(mapObjectList, "of6yoshi1.nsbmd");
    SetMapObjectModelPolygonId(gOf6yoshi1, 0x3f);
}

void SetupDrawOf6yoshi1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gOf6yoshi1);
}

void DrawOf6yoshi1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOf6yoshi1, mapObject);
}

MapObjectList *CreateOf6yoshi1DrawList(void) {
    return CreateMapObjectDrawList2(CreateOf6yoshi1, DrawOf6yoshi1, SetupDrawOf6yoshi1);
}

void CreateNsCannon1(void *mapObjectList) {
    gNsCannon1 = CreateMapObjectModelNsbmd(mapObjectList, "NsCannon1.nsbmd");
    SetMapObjectModelPolygonId(gNsCannon1, 0x3f);
}

void SetupDrawNsCannon1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gNsCannon1);
}

void DrawNsCannon1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gNsCannon1, mapObject);
}

MapObjectList *CreateNsCannon1DrawList(void) {
    return CreateMapObjectDrawList2(CreateNsCannon1, DrawNsCannon1, SetupDrawNsCannon1);
}

void CreateCrossTree1(void *mapObjectList) {
    gCrossTree1 = CreateMapObjectModelNsbmd(mapObjectList, "CrossTree1.nsbmd");
    SetMapObjectModelPolygonId(gCrossTree1, 0x3f);
}

void SetupDrawCrossTree1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gCrossTree1);
}

void DrawCrossTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gCrossTree1, mapObject);
}

MapObjectList *CreateCrossTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateCrossTree1, DrawCrossTree1, SetupDrawCrossTree1);
}

void CreateBankTree1(void *mapObjectList) {
    gBankTree1 = CreateMapObjectModelNsbmd(mapObjectList, "Bank_Tree1.nsbmd");
    SetMapObjectModelPolygonId(gBankTree1, 0x3f);
}

void SetupDrawBankTree1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gBankTree1);
}

void DrawBankTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gBankTree1, mapObject);
}

MapObjectList *CreateBankTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateBankTree1, DrawBankTree1, SetupDrawBankTree1);
}

void CreateGardenTree1(void *mapObjectList) {
    gGardenTree1 = CreateMapObjectModelNsbmd(mapObjectList, "GardenTree1.nsbmd");
    SetMapObjectModelPolygonId(gGardenTree1, 0x3f);
}

void SetupDrawGardenTree1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gGardenTree1);
}

void DrawGardenTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gGardenTree1, mapObject);
}

MapObjectList *CreateGardenTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateGardenTree1, DrawGardenTree1, SetupDrawGardenTree1);
}

void CreateTownTree1(void *mapObjectList) {
    gTownTree1 = CreateMapObjectModelNsbmd(mapObjectList, "TownTree1.nsbmd");
    SetMapObjectModelPolygonId(gTownTree1, 0x3f);
}

void SetupDrawTownTree1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gTownTree1);
}

void DrawTownTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gTownTree1, mapObject);
}

MapObjectList *CreateTownTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateTownTree1, DrawTownTree1, SetupDrawTownTree1);
}

void CreateMarioTree3(void *mapObjectList) {
    gMarioTree3 = CreateMapObjectModelNsbmd(mapObjectList, "MarioTree3.nsbmd");
    SetMapObjectModelPolygonId(gMarioTree3, 0x3f);
}

void SetupDrawMarioTree3(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gMarioTree3);
}

void DrawMarioTree3(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gMarioTree3, mapObject);
}

MapObjectList *CreateMarioTree3DrawList(void) {
    return CreateMapObjectDrawList2(CreateMarioTree3, DrawMarioTree3, SetupDrawMarioTree3);
}

void CreateSnowTree1(void *mapObjectList) {
    gSnowTree1 = CreateMapObjectModelNsbmd(mapObjectList, "Snow_Tree1.nsbmd");
    SetMapObjectModelPolygonId(gSnowTree1, 0x3f);
}

void SetupDrawSnowTree1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gSnowTree1);
}

void DrawSnowTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gSnowTree1, mapObject);
}

MapObjectList *CreateSnowTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateSnowTree1, DrawSnowTree1, SetupDrawSnowTree1);
}

void CreateDeTree1(void *mapObjectList) {
    gDeTree1 = CreateMapObjectModelNsbmd(mapObjectList, "DeTree1.nsbmd");
    SetMapObjectModelPolygonId(gDeTree1, 0x3f);
}

void SetupDrawDeTree1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gDeTree1);
}

void DrawDeTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gDeTree1, mapObject);
}

MapObjectList *CreateDeTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateDeTree1, DrawDeTree1, SetupDrawDeTree1);
}

void CreateOlaTree1c(void *mapObjectList) {
    gOlaTree1c = CreateMapObjectModelNsbmd(mapObjectList, "olaTree1c.nsbmd");
    SetMapObjectModelPolygonId(gOlaTree1c, 0x3f);
}

void SetupDrawOlaTree1c(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gOlaTree1c);
}

void DrawOlaTree1c(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOlaTree1c, mapObject);
}

MapObjectList *CreateOlaTree1cDrawList(void) {
    return CreateMapObjectDrawList2(CreateOlaTree1c, DrawOlaTree1c, SetupDrawOlaTree1c);
}

void CreateOsaTree1c(void *mapObjectList) {
    gOsaTree1c = CreateMapObjectModelNsbmd(mapObjectList, "osaTree1c.nsbmd");
    SetMapObjectModelPolygonId(gOsaTree1c, 0x3f);
}

void SetupDrawOsaTree1c(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gOsaTree1c);
}

void DrawOsaTree1c(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOsaTree1c, mapObject);
}

MapObjectList *CreateOsaTree1cDrawList(void) {
    return CreateMapObjectDrawList2(CreateOsaTree1c, DrawOsaTree1c, SetupDrawOsaTree1c);
}

void CreateKinoHouse1(void *mapObjectList) {
    gKinoHouse1 = CreateMapObjectModelNsbmd(mapObjectList, "KinoHouse1.nsbmd");
    SetMapObjectModelPolygonId(gKinoHouse1, 0x3f);
}

void SetupDrawKinoHouse1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gKinoHouse1);
}

void DrawKinoHouse1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gKinoHouse1, mapObject);
}

MapObjectList *CreateKinoHouse1DrawList(void) {
    return CreateMapObjectDrawList2(CreateKinoHouse1, DrawKinoHouse1, SetupDrawKinoHouse1);
}

void CreateKinoHouse2(void *mapObjectList) {
    gKinoHouse2 = CreateMapObjectModelNsbmd(mapObjectList, "KinoHouse2.nsbmd");
    SetMapObjectModelPolygonId(gKinoHouse2, 0x3f);
}

void SetupDrawKinoHouse2(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gKinoHouse2);
}

void DrawKinoHouse2(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gKinoHouse2, mapObject);
}

MapObjectList *CreateKinoHouse2DrawList(void) {
    return CreateMapObjectDrawList2(CreateKinoHouse2, DrawKinoHouse2, SetupDrawKinoHouse2);
}

void CreateKinoMount1(void *mapObjectList) {
    gKinoMount1 = CreateMapObjectModelNsbmd(mapObjectList, "KinoMount1.nsbmd");
    SetMapObjectModelPolygonId(gKinoMount1, 0x3f);
}

void SetupDrawKinoMount1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gKinoMount1);
}

void DrawKinoMount1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gKinoMount1, mapObject);
}

MapObjectList *CreateKinoMount1DrawList(void) {
    return CreateMapObjectDrawList2(CreateKinoMount1, DrawKinoMount1, SetupDrawKinoMount1);
}

void CreateKinoMount2(void *mapObjectList) {
    gKinoMount2 = CreateMapObjectModelNsbmd(mapObjectList, "KinoMount2.nsbmd");
    SetMapObjectModelPolygonId(gKinoMount2, 0x3f);
}

void SetupDrawKinoMount2(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gKinoMount2);
}

void DrawKinoMount2(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gKinoMount2, mapObject);
}

MapObjectList *CreateKinoMount2DrawList(void) {
    return CreateMapObjectDrawList2(CreateKinoMount2, DrawKinoMount2, SetupDrawKinoMount2);
}

void CreateOm6Tree1(void *mapObjectList) {
    gOm6Tree1 = CreateMapObjectModelNsbmd(mapObjectList, "om6Tree1.nsbmd");
    SetMapObjectModelPolygonId(gOm6Tree1, 0x3f);
}

void SetupDrawOm6Tree1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gOm6Tree1);
}

void DrawOm6Tree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOm6Tree1, mapObject);
}

MapObjectList *CreateOm6Tree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateOm6Tree1, DrawOm6Tree1, SetupDrawOm6Tree1);
}

void CreateOf6Tree1(void *mapObjectList) {
    gOf6Tree1 = CreateMapObjectModelNsbmd(mapObjectList, "Of6Tree1.nsbmd");
    SetMapObjectModelPolygonId(gOf6Tree1, 0x3f);
}

void SetupDrawOf6Tree1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gOf6Tree1);
}

void DrawOf6Tree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOf6Tree1, mapObject);
}

MapObjectList *CreateOf6Tree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateOf6Tree1, DrawOf6Tree1, SetupDrawOf6Tree1);
}

void CreateBankEgg1(void *mapObjectList) {
    gBankEgg1 = CreateMapObjectModelNsbmd(mapObjectList, "BankEgg1.nsbmd");
    SetMapObjectModelPolygonId(gBankEgg1, 0x3f);
}

void SetupDrawBankEgg1(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gBankEgg1);
}

void DrawBankEgg1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gBankEgg1, mapObject);
}

MapObjectList *CreateBankEgg1DrawList(void) {
    return CreateMapObjectDrawList2(CreateBankEgg1, DrawBankEgg1, SetupDrawBankEgg1);
}

void CreateMiniDokan(void *mapObjectList) {
    gMiniDokan = CreateMapObjectModelNsbmd(mapObjectList, "mini_dokan.nsbmd");
    SetMapObjectModelPolygonId(gMiniDokan, 0x3f);
}

void SetupDrawMiniDokan(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gMiniDokan);
}

void DrawMiniDokan(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = SetViewRotatedMatrixPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gMiniDokan, mapObject);
}

MapObjectList *CreateMiniDokanDrawList(void) {
    return CreateMapObjectDrawList2(CreateMiniDokan, DrawMiniDokan, SetupDrawMiniDokan);
}
