#include "Main/MapObjects/empty_kind_data.h"

#include "Main/MapObjects/map_object_model_frame.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "ITCM/model_draw_and_irq_handler.h"

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
void *g_BankEgg1MapObject;
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
    kindData->mSoundId = MINI_DOKAN_SOUND_ID;
    return kindData;
}

void LoadBeachTree1MapObject(void *mapObjectList) {
    gBeachTree1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "BeachTree1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gBeachTree1, 0x3f);
}

void SetupDrawBeachTree1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gBeachTree1);
}

void DrawBeachTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gBeachTree1, mapObject);
}

MapObjectList *CreateBeachTree1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadBeachTree1MapObject, DrawBeachTree1, SetupDrawBeachTree1);
}

void LoadOpaTree1MapObject(void *mapObjectList) {
    gOpaTree1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "opa_tree1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gOpaTree1, 0x3f);
}

void SetupDrawOpaTree1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gOpaTree1);
}

void DrawOpaTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOpaTree1, mapObject);
}

MapObjectList *CreateOpaTree1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadOpaTree1MapObject, DrawOpaTree1, SetupDrawOpaTree1);
}

void LoadOlgMush1MapObject(void *mapObjectList) {
    gOlgMush1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "OlgMush1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gOlgMush1, 0x3f);
}

void SetupDrawOlgMush1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gOlgMush1);
}

void DrawOlgMush1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOlgMush1, mapObject);
}

MapObjectList *CreateOlgMush1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadOlgMush1MapObject, DrawOlgMush1, SetupDrawOlgMush1);
}

void LoadOlgPipe1MapObject(void *mapObjectList) {
    gOlgPipe1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "OlgPipe1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gOlgPipe1, 0x3f);
}

void SetupDrawOlgPipe1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gOlgPipe1);
}

void DrawOlgPipe1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOlgPipe1, mapObject);
}

MapObjectList *CreateOlgPipe1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadOlgPipe1MapObject, DrawOlgPipe1, SetupDrawOlgPipe1);
}

void LoadOf6Yoshi1MapObject(void *mapObjectList) {
    gOf6yoshi1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "of6yoshi1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gOf6yoshi1, 0x3f);
}

void SetupDrawOf6yoshi1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gOf6yoshi1);
}

void DrawOf6yoshi1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOf6yoshi1, mapObject);
}

MapObjectList *CreateOf6yoshi1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadOf6Yoshi1MapObject, DrawOf6yoshi1, SetupDrawOf6yoshi1);
}

void LoadNsCannon1MapObject(void *mapObjectList) {
    gNsCannon1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "NsCannon1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gNsCannon1, 0x3f);
}

void SetupDrawNsCannon1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gNsCannon1);
}

void DrawNsCannon1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gNsCannon1, mapObject);
}

MapObjectList *CreateNsCannon1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadNsCannon1MapObject, DrawNsCannon1, SetupDrawNsCannon1);
}

void LoadCrossTree1MapObject(void *mapObjectList) {
    gCrossTree1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "CrossTree1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gCrossTree1, 0x3f);
}

void SetupDrawCrossTree1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gCrossTree1);
}

void DrawCrossTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gCrossTree1, mapObject);
}

MapObjectList *CreateCrossTree1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadCrossTree1MapObject, DrawCrossTree1, SetupDrawCrossTree1);
}

void LoadBankTree1MapObject(void *mapObjectList) {
    gBankTree1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "Bank_Tree1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gBankTree1, 0x3f);
}

void SetupDrawBankTree1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gBankTree1);
}

void DrawBankTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gBankTree1, mapObject);
}

MapObjectList *CreateBankTree1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadBankTree1MapObject, DrawBankTree1, SetupDrawBankTree1);
}

void LoadGardenTree1MapObject(void *mapObjectList) {
    gGardenTree1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "GardenTree1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gGardenTree1, 0x3f);
}

void SetupDrawGardenTree1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gGardenTree1);
}

void DrawGardenTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gGardenTree1, mapObject);
}

MapObjectList *CreateGardenTree1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadGardenTree1MapObject, DrawGardenTree1, SetupDrawGardenTree1);
}

void LoadTownTree1MapObject(void *mapObjectList) {
    gTownTree1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "TownTree1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gTownTree1, 0x3f);
}

void SetupDrawTownTree1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gTownTree1);
}

void DrawTownTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gTownTree1, mapObject);
}

MapObjectList *CreateTownTree1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadTownTree1MapObject, DrawTownTree1, SetupDrawTownTree1);
}

void LoadMarioTree3MapObject(void *mapObjectList) {
    gMarioTree3 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "MarioTree3.nsbmd");
    StructMapObject_MaybeSetPolygonId(gMarioTree3, 0x3f);
}

void SetupDrawMarioTree3(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gMarioTree3);
}

void DrawMarioTree3(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gMarioTree3, mapObject);
}

MapObjectList *CreateMarioTree3DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadMarioTree3MapObject, DrawMarioTree3, SetupDrawMarioTree3);
}

void LoadSnowTree1MapObject(void *mapObjectList) {
    gSnowTree1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "Snow_Tree1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gSnowTree1, 0x3f);
}

void SetupDrawSnowTree1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gSnowTree1);
}

void DrawSnowTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gSnowTree1, mapObject);
}

MapObjectList *CreateSnowTree1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadSnowTree1MapObject, DrawSnowTree1, SetupDrawSnowTree1);
}

void LoadDeTree1MapObject(void *mapObjectList) {
    gDeTree1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "DeTree1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gDeTree1, 0x3f);
}

void SetupDrawDeTree1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gDeTree1);
}

void DrawDeTree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gDeTree1, mapObject);
}

MapObjectList *CreateDeTree1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadDeTree1MapObject, DrawDeTree1, SetupDrawDeTree1);
}

void LoadOlaTree1cMapObject(void *mapObjectList) {
    gOlaTree1c = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "olaTree1c.nsbmd");
    StructMapObject_MaybeSetPolygonId(gOlaTree1c, 0x3f);
}

void SetupDrawOlaTree1c(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gOlaTree1c);
}

void DrawOlaTree1c(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOlaTree1c, mapObject);
}

MapObjectList *CreateOlaTree1cDrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadOlaTree1cMapObject, DrawOlaTree1c, SetupDrawOlaTree1c);
}

void LoadOsaTree1cMapObject(void *mapObjectList) {
    gOsaTree1c = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "osaTree1c.nsbmd");
    StructMapObject_MaybeSetPolygonId(gOsaTree1c, 0x3f);
}

void SetupDrawOsaTree1c(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gOsaTree1c);
}

void DrawOsaTree1c(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOsaTree1c, mapObject);
}

MapObjectList *CreateOsaTree1cDrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadOsaTree1cMapObject, DrawOsaTree1c, SetupDrawOsaTree1c);
}

void LoadKinoHouse1MapObject(void *mapObjectList) {
    gKinoHouse1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "KinoHouse1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gKinoHouse1, 0x3f);
}

void SetupDrawKinoHouse1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gKinoHouse1);
}

void DrawKinoHouse1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gKinoHouse1, mapObject);
}

MapObjectList *CreateKinoHouse1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadKinoHouse1MapObject, DrawKinoHouse1, SetupDrawKinoHouse1);
}

void LoadKinoHouse2MapObject(void *mapObjectList) {
    gKinoHouse2 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "KinoHouse2.nsbmd");
    StructMapObject_MaybeSetPolygonId(gKinoHouse2, 0x3f);
}

void SetupDrawKinoHouse2(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gKinoHouse2);
}

void DrawKinoHouse2(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gKinoHouse2, mapObject);
}

MapObjectList *CreateKinoHouse2DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadKinoHouse2MapObject, DrawKinoHouse2, SetupDrawKinoHouse2);
}

void LoadKinoMount1MapObject(void *mapObjectList) {
    gKinoMount1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "KinoMount1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gKinoMount1, 0x3f);
}

void SetupDrawKinoMount1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gKinoMount1);
}

void DrawKinoMount1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gKinoMount1, mapObject);
}

MapObjectList *CreateKinoMount1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadKinoMount1MapObject, DrawKinoMount1, SetupDrawKinoMount1);
}

void LoadKinoMount2MapObject(void *mapObjectList) {
    gKinoMount2 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "KinoMount2.nsbmd");
    StructMapObject_MaybeSetPolygonId(gKinoMount2, 0x3f);
}

void SetupDrawKinoMount2(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gKinoMount2);
}

void DrawKinoMount2(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gKinoMount2, mapObject);
}

MapObjectList *CreateKinoMount2DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadKinoMount2MapObject, DrawKinoMount2, SetupDrawKinoMount2);
}

void LoadOm6Tree1MapObject(void *mapObjectList) {
    gOm6Tree1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "om6Tree1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gOm6Tree1, 0x3f);
}

void SetupDrawOm6Tree1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gOm6Tree1);
}

void DrawOm6Tree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOm6Tree1, mapObject);
}

MapObjectList *CreateOm6Tree1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadOm6Tree1MapObject, DrawOm6Tree1, SetupDrawOm6Tree1);
}

void LoadOf6Tree1MapObject(void *mapObjectList) {
    gOf6Tree1 = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "Of6Tree1.nsbmd");
    StructMapObject_MaybeSetPolygonId(gOf6Tree1, 0x3f);
}

void SetupDrawOf6Tree1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gOf6Tree1);
}

void DrawOf6Tree1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gOf6Tree1, mapObject);
}

MapObjectList *CreateOf6Tree1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadOf6Tree1MapObject, DrawOf6Tree1, SetupDrawOf6Tree1);
}

void LoadBankEgg1MapObject(void *mapObjectList) {
    g_BankEgg1MapObject = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "BankEgg1.nsbmd");
    StructMapObject_MaybeSetPolygonId(g_BankEgg1MapObject, 0x3f);
}

void SetupDrawBankEgg1(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, g_BankEgg1MapObject);
}

void DrawBankEgg1(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, g_BankEgg1MapObject, mapObject);
}

MapObjectList *CreateBankEgg1DrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadBankEgg1MapObject, DrawBankEgg1, SetupDrawBankEgg1);
}

void LoadMiniDokanMapObject(void *mapObjectList) {
    gMiniDokan = CreateMapObjectFromModel_2_from_thumb(mapObjectList, "mini_dokan.nsbmd");
    StructMapObject_MaybeSetPolygonId(gMiniDokan, 0x3f);
}

void SetupDrawMiniDokan(void *mapObjectList) {
    StructMapObject_SomeFn_9(mapObjectList, gMiniDokan);
}

void DrawMiniDokan(u32 mapObjectList, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 commandParam;
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    matrix = MaybeGetBBMtxAtPosition(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    DrawMapObjectModelWithPos(mapObjectList, gMiniDokan, mapObject);
}

MapObjectList *CreateMiniDokanDrawList(void) {
    return CreateAllocateMapObject_from_thumb(LoadMiniDokanMapObject, DrawMiniDokan, SetupDrawMiniDokan);
}
