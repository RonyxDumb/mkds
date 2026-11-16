#include "Main/Unknown/code_020992ac.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff8000.h"

void *bbobj_sDeTree1Model;
void *bbobj_sCrossTree1Model;
void *bbobj_sNsCannon1Model;
void *bbobj_sBeachTree1Model;
void *bbobj_sMiniDokanModel;
void *bbobj_sOm6Tree1Model;
void *bbobj_sKinoHouse2Model;
void *bbobj_sOsaTree1cModel;
void *bbobj_sTownTree1Model;
void *bbobj_sOf6Tree1Model;
void *bbobj_sMarioTree3Model;
void *bbobj_sOlgMush1Model;
void *bbobj_sOlaTree1cModel;
void *bbobj_sKinoHouse1Model;
void *bbobj_sBankTree1Model;
void *bbobj_sOlgPipe1Model;
void *bbobj_sOpaTree1Model;
void *bbobj_sGardenTree1Model;
void *bbobj_sKinoMount2Model;
void *bbobj_sSnowTree1Model;
void *bbobj_sBankEgg1Model;
void *bbobj_sKinoMount1Model;
void *bbobj_sOf6yoshi1Model;

MapObjectKindDescriptor gOf6Tree1NoColMObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupOf6Tree1RenderPart};
MapObjectKindDescriptor gOlaTree1cMObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupOlaTree1cRenderPart};
MapObjectKindDescriptor gDeTree1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupDeTree1RenderPart};
MapObjectKindDescriptor gOlgMush1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupOlgMush1RenderPart};
MapObjectKindDescriptor gOlgPipe1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupOlgPipe1RenderPart};
MapObjectKindDescriptor gBeachTree1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupBeachTree1RenderPart};
MapObjectKindDescriptor gNsCannon1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupNsCannon1RenderPart};
MapObjectKindDescriptor gCrossTree1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupCrossTree1RenderPart};
MapObjectKindDescriptor gBankTree1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupBankTree1RenderPart};
MapObjectKindDescriptor gOf6yoshi1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupOf6yoshi1RenderPart};
MapObjectKindDescriptor gGardenTree1NoColMObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupGardenTree1RenderPart};
MapObjectKindDescriptor gGardenTree1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupGardenTree1RenderPart};
MapObjectKindDescriptor gTownTree1NoColMObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupTownTree1RenderPart};
MapObjectKindDescriptor gTownTree1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupTownTree1RenderPart};
MapObjectKindDescriptor gMarioTree3MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupMarioTree3RenderPart};
MapObjectKindDescriptor gSnowTree1NoColMObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupSnowTree1RenderPart};
MapObjectKindDescriptor gOpaTree1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupOpaTree1RenderPart};
MapObjectKindDescriptor gSnowTree1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupSnowTree1RenderPart};
MapObjectKindDescriptor gDeTree1NoColMObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupDeTree1RenderPart};
MapObjectKindDescriptor gOsaTree1cMObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupOsaTree1cRenderPart};
MapObjectKindDescriptor gKinoHouse1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupKinoHouse1RenderPart};
MapObjectKindDescriptor gOf6Tree1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupOf6Tree1RenderPart};
MapObjectKindDescriptor gKinoHouse2MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupKinoHouse2RenderPart};
MapObjectKindDescriptor gKinoMount1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupKinoMount1RenderPart};
MapObjectKindDescriptor gKinoMount2MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupKinoMount2RenderPart};
MapObjectKindDescriptor gOm6Tree1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupOm6Tree1RenderPart};
MapObjectKindDescriptor gBeachTree1NoColMObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupBeachTree1RenderPart};
MapObjectKindDescriptor gBankEgg1MObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupBankEgg1RenderPart};
MapObjectKindDescriptor gMiniDokanMObjDef = {0, {0, 0}, 0xa0, 0, bbobj_setupConfig, bbobj_setupMiniDokanRenderPart};

MapObjectKindData *bbobj_setupConfig(void) {
    MapObjectKindData *kindData;

    kindData = (MapObjectKindData *) mobj_createDummyConfig();
    kindData->field24 = 0x84;
    return kindData;
}

void bbobj_loadBeachTree1Model(void *a) {
    bbobj_sBeachTree1Model = mobj_loadBillboardModel(a, "BeachTree1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sBeachTree1Model, 0x3f);
}

void bbobj_applyBeachTree1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sBeachTree1Model);
}

void bbobj_renderBeachTree1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sBeachTree1Model, mapObject);
}

MapObjectList *bbobj_setupBeachTree1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadBeachTree1Model, bbobj_renderBeachTree1, bbobj_applyBeachTree1Material);
}

void bbobj_loadOpaTree1Model(void *a) {
    bbobj_sOpaTree1Model = mobj_loadBillboardModel(a, "opa_tree1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sOpaTree1Model, 0x3f);
}

void bbobj_applyOpaTree1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sOpaTree1Model);
}

void bbobj_renderOpaTree1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sOpaTree1Model, mapObject);
}

MapObjectList *bbobj_setupOpaTree1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadOpaTree1Model, bbobj_renderOpaTree1, bbobj_applyOpaTree1Material);
}

void bbobj_loadOlgMush1Model(void *a) {
    bbobj_sOlgMush1Model = mobj_loadBillboardModel(a, "OlgMush1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sOlgMush1Model, 0x3f);
}

void bbobj_applyOlgMush1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sOlgMush1Model);
}

void bbobj_renderOlgMush1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sOlgMush1Model, mapObject);
}

MapObjectList *bbobj_setupOlgMush1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadOlgMush1Model, bbobj_renderOlgMush1, bbobj_applyOlgMush1Material);
}

void bbobj_loadOlgPipe1Model(void *a) {
    bbobj_sOlgPipe1Model = mobj_loadBillboardModel(a, "OlgPipe1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sOlgPipe1Model, 0x3f);
}

void bbobj_applyOlgPipe1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sOlgPipe1Model);
}

void bbobj_renderOlgPipe1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sOlgPipe1Model, mapObject);
}

MapObjectList *bbobj_setupOlgPipe1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadOlgPipe1Model, bbobj_renderOlgPipe1, bbobj_applyOlgPipe1Material);
}

void bbobj_loadOf6yoshi1Model(void *a) {
    bbobj_sOf6yoshi1Model = mobj_loadBillboardModel(a, "of6yoshi1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sOf6yoshi1Model, 0x3f);
}

void bbobj_applyOf6yoshi1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sOf6yoshi1Model);
}

void bbobj_renderOf6yoshi1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sOf6yoshi1Model, mapObject);
}

MapObjectList *bbobj_setupOf6yoshi1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadOf6yoshi1Model, bbobj_renderOf6yoshi1, bbobj_applyOf6yoshi1Material);
}

void bbobj_loadNsCannon1Model(void *a) {
    bbobj_sNsCannon1Model = mobj_loadBillboardModel(a, "NsCannon1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sNsCannon1Model, 0x3f);
}

void bbobj_applyNsCannon1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sNsCannon1Model);
}

void bbobj_renderNsCannon1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sNsCannon1Model, mapObject);
}

MapObjectList *bbobj_setupNsCannon1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadNsCannon1Model, bbobj_renderNsCannon1, bbobj_applyNsCannon1Material);
}

void bbobj_loadCrossTree1Model(void *a) {
    bbobj_sCrossTree1Model = mobj_loadBillboardModel(a, "CrossTree1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sCrossTree1Model, 0x3f);
}

void bbobj_applyCrossTree1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sCrossTree1Model);
}

void bbobj_renderCrossTree1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sCrossTree1Model, mapObject);
}

MapObjectList *bbobj_setupCrossTree1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadCrossTree1Model, bbobj_renderCrossTree1, bbobj_applyCrossTree1Material);
}

void bbobj_loadBankTree1Model(void *a) {
    bbobj_sBankTree1Model = mobj_loadBillboardModel(a, "Bank_Tree1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sBankTree1Model, 0x3f);
}

void bbobj_applyBankTree1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sBankTree1Model);
}

void bbobj_renderBankTree1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sBankTree1Model, mapObject);
}

MapObjectList *bbobj_setupBankTree1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadBankTree1Model, bbobj_renderBankTree1, bbobj_applyBankTree1Material);
}

void bbobj_loadGardenTree1Model(void *a) {
    bbobj_sGardenTree1Model = mobj_loadBillboardModel(a, "GardenTree1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sGardenTree1Model, 0x3f);
}

void bbobj_applyGardenTree1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sGardenTree1Model);
}

void bbobj_renderGardenTree1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sGardenTree1Model, mapObject);
}

MapObjectList *bbobj_setupGardenTree1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadGardenTree1Model, bbobj_renderGardenTree1, bbobj_applyGardenTree1Material);
}

void bbobj_loadTownTree1Model(void *a) {
    bbobj_sTownTree1Model = mobj_loadBillboardModel(a, "TownTree1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sTownTree1Model, 0x3f);
}

void bbobj_applyTownTree1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sTownTree1Model);
}

void bbobj_renderTownTree1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sTownTree1Model, mapObject);
}

MapObjectList *bbobj_setupTownTree1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadTownTree1Model, bbobj_renderTownTree1, bbobj_applyTownTree1Material);
}

void bbobj_loadMarioTree3Model(void *a) {
    bbobj_sMarioTree3Model = mobj_loadBillboardModel(a, "MarioTree3.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sMarioTree3Model, 0x3f);
}

void bbobj_applyMarioTree3Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sMarioTree3Model);
}

void bbobj_renderMarioTree3(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sMarioTree3Model, mapObject);
}

MapObjectList *bbobj_setupMarioTree3RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadMarioTree3Model, bbobj_renderMarioTree3, bbobj_applyMarioTree3Material);
}

void bbobj_loadSnowTree1Model(void *a) {
    bbobj_sSnowTree1Model = mobj_loadBillboardModel(a, "Snow_Tree1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sSnowTree1Model, 0x3f);
}

void bbobj_applySnowTree1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sSnowTree1Model);
}

void bbobj_renderSnowTree1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sSnowTree1Model, mapObject);
}

MapObjectList *bbobj_setupSnowTree1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadSnowTree1Model, bbobj_renderSnowTree1, bbobj_applySnowTree1Material);
}

void bbobj_loadDeTree1Model(void *a) {
    bbobj_sDeTree1Model = mobj_loadBillboardModel(a, "DeTree1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sDeTree1Model, 0x3f);
}

void bbobj_applyDeTree1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sDeTree1Model);
}

void bbobj_renderDeTree1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sDeTree1Model, mapObject);
}

MapObjectList *bbobj_setupDeTree1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadDeTree1Model, bbobj_renderDeTree1, bbobj_applyDeTree1Material);
}

void bbobj_loadOlaTree1cModel(void *a) {
    bbobj_sOlaTree1cModel = mobj_loadBillboardModel(a, "olaTree1c.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sOlaTree1cModel, 0x3f);
}

void bbobj_applyOlaTree1cMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sOlaTree1cModel);
}

void bbobj_renderOlaTree1c(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sOlaTree1cModel, mapObject);
}

MapObjectList *bbobj_setupOlaTree1cRenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadOlaTree1cModel, bbobj_renderOlaTree1c, bbobj_applyOlaTree1cMaterial);
}

void bbobj_loadOsaTree1cModel(void *a) {
    bbobj_sOsaTree1cModel = mobj_loadBillboardModel(a, "osaTree1c.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sOsaTree1cModel, 0x3f);
}

void bbobj_applyOsaTree1cMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sOsaTree1cModel);
}

void bbobj_renderOsaTree1c(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sOsaTree1cModel, mapObject);
}

MapObjectList *bbobj_setupOsaTree1cRenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadOsaTree1cModel, bbobj_renderOsaTree1c, bbobj_applyOsaTree1cMaterial);
}

void bbobj_loadKinoHouse1Model(void *a) {
    bbobj_sKinoHouse1Model = mobj_loadBillboardModel(a, "KinoHouse1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sKinoHouse1Model, 0x3f);
}

void bbobj_applyKinoHouse1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sKinoHouse1Model);
}

void bbobj_renderKinoHouse1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sKinoHouse1Model, mapObject);
}

MapObjectList *bbobj_setupKinoHouse1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadKinoHouse1Model, bbobj_renderKinoHouse1, bbobj_applyKinoHouse1Material);
}

void bbobj_loadKinoHouse2Model(void *a) {
    bbobj_sKinoHouse2Model = mobj_loadBillboardModel(a, "KinoHouse2.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sKinoHouse2Model, 0x3f);
}

void bbobj_applyKinoHouse2Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sKinoHouse2Model);
}

void bbobj_renderKinoHouse2(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sKinoHouse2Model, mapObject);
}

MapObjectList *bbobj_setupKinoHouse2RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadKinoHouse2Model, bbobj_renderKinoHouse2, bbobj_applyKinoHouse2Material);
}

void bbobj_loadKinoMount1Model(void *a) {
    bbobj_sKinoMount1Model = mobj_loadBillboardModel(a, "KinoMount1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sKinoMount1Model, 0x3f);
}

void bbobj_applyKinoMount1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sKinoMount1Model);
}

void bbobj_renderKinoMount1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sKinoMount1Model, mapObject);
}

MapObjectList *bbobj_setupKinoMount1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadKinoMount1Model, bbobj_renderKinoMount1, bbobj_applyKinoMount1Material);
}

void bbobj_loadKinoMount2Model(void *a) {
    bbobj_sKinoMount2Model = mobj_loadBillboardModel(a, "KinoMount2.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sKinoMount2Model, 0x3f);
}

void bbobj_applyKinoMount2Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sKinoMount2Model);
}

void bbobj_renderKinoMount2(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sKinoMount2Model, mapObject);
}

MapObjectList *bbobj_setupKinoMount2RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadKinoMount2Model, bbobj_renderKinoMount2, bbobj_applyKinoMount2Material);
}

void bbobj_loadOm6Tree1Model(void *a) {
    bbobj_sOm6Tree1Model = mobj_loadBillboardModel(a, "om6Tree1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sOm6Tree1Model, 0x3f);
}

void bbobj_applyOm6Tree1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sOm6Tree1Model);
}

void bbobj_renderOm6Tree1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sOm6Tree1Model, mapObject);
}

MapObjectList *bbobj_setupOm6Tree1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadOm6Tree1Model, bbobj_renderOm6Tree1, bbobj_applyOm6Tree1Material);
}

void bbobj_loadOf6Tree1Model(void *a) {
    bbobj_sOf6Tree1Model = mobj_loadBillboardModel(a, "Of6Tree1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sOf6Tree1Model, 0x3f);
}

void bbobj_applyOf6Tree1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sOf6Tree1Model);
}

void bbobj_renderOf6Tree1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sOf6Tree1Model, mapObject);
}

MapObjectList *bbobj_setupOf6Tree1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadOf6Tree1Model, bbobj_renderOf6Tree1, bbobj_applyOf6Tree1Material);
}

void bbobj_loadBankEgg1Model(void *a) {
    bbobj_sBankEgg1Model = mobj_loadBillboardModel(a, "BankEgg1.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sBankEgg1Model, 0x3f);
}

void bbobj_applyBankEgg1Material(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sBankEgg1Model);
}

void bbobj_renderBankEgg1(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sBankEgg1Model, mapObject);
}

MapObjectList *bbobj_setupBankEgg1RenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadBankEgg1Model, bbobj_renderBankEgg1, bbobj_applyBankEgg1Material);
}

void bbobj_loadMiniDokanModel(void *a) {
    bbobj_sMiniDokanModel = mobj_loadBillboardModel(a, "mini_dokan.nsbmd");
    mobj_setModelPolygonIdAll(bbobj_sMiniDokanModel, 0x3f);
}

void bbobj_applyMiniDokanMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, bbobj_sMiniDokanModel);
}

void bbobj_renderMiniDokan(u32 a, MapObject *mapObject) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    matrix = bbm_getYBillboardAtPos(&mapObject->mPos);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    mobj_renderModelInPlace(a, bbobj_sMiniDokanModel, mapObject);
}

MapObjectList *bbobj_setupMiniDokanRenderPart(void) {
    return mobj_createRenderPart2d(bbobj_loadMiniDokanModel, bbobj_renderMiniDokan, bbobj_applyMiniDokanMaterial);
}
