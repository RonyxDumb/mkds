#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/data_0217a000.h" // Camera
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/data_0217b000.h"

typedef struct MapObject MapObject;

void SetMapObjectMaskAndFlagFromNumber(s32 number, MapObject *mapObject);

u16 AllocPolygonIdWrapping(void);
u16 AllocPolygonId(void);
u16 CountMapObjectsOfKind(u32 kind);
void ParkFlaggedMapObjects(void);
void UnparkFlaggedMapObjects(void);

void SetMapObjectsRunUpdateLists(void);

s32 GetHeightAboveWaterOrEfct(s32 height);
s32 IsFarBelowWaterEfct(s32 height);
void RunMapObjectListCallbacks(void);
s32 GetMapObjectHitResponse(MapObject *mapObject, s32 itemKind, Vec3 *hitOffset);

u32 IsWaterHeightUsed(void);

BOOL IsSphereHittingMapObject(Vec3 *position, s32 radius, MapObject *mapObject, Vec3 *overlapOffset);
BOOL IsWaterPresent(void);
s32 GetHeightAboveWater(s32 height);
s32 GetWaterHeightFactor(void);
u32 GetWaterHeightAngle(void);

Vec3 *GetFoundMapObjectVector(int index);

MapObject *GetFoundMapObject(u32 index);

void UpdateMapObjectViewTests(void);
void RefreshMapObjectViewTests(void);
void UpdateMapObjects(void);
void DrawMapObjects(Camera *view);
void DrawKoopaBlocksKind203AndBridges(Camera *view);
s32 FindMapObjectsTouchingKart(Kart *kart, Vec3 *position, Vec3 *hitOffset);
s32 FindMapObjectsOfKindInRadius(Vec3 *position, s32 radius, s32 kind);

typedef struct Water Water;

// Publishes the WaterEfct object as gCourseWaterEfct.
void SetCourseWaterEfct(void *waterEfct);
// Publishes the Water object as gCourseWater.
void SetCourseWater(Water *water);

typedef struct MapObjectList MapObjectList;

void InitMapObjectDrawOrder(MapObjectList *list);

void SetDrawListSlot(void *listSlot);

u32 AddMapObjectToDrawList(MapObjectList *list, MapObject *mapObject);
u32 InitMapObjectDrawList(MapObjectList *list);

void DrawListAddToMapObjectListCount(MapObjectList *list, s32 count);

void ClearMapObjectList(MapObjectList *list);

void RefreshViewFrustumFromProjection(s32 top, s32 bottom, s32 left, s32 right, s32 nearDistance, s32 farDistance);

void InitMapObjectViewState(void);

void UpdateViewFrustum(MtxFx43 *viewMatrix);
u32 ComputeDistanceViewTest(Vec3 *position, s32 unusedArg1, s32 unusedArg2, s32 distanceLimitSquared);
s32 GetHorizontalCameraDistanceSquared(Vec3 *position);
void SetItemObjectSoundByViewRange(ItemObject *itemObject, Vec3 *position, u32 distanceAndFlags);
BOOL IsMapObjectOutOfRange(MapObject *mapObject);
BOOL IsMapObjectOutOfRangeOrMaskedAtDistance(MapObject *mapObject, s32 distanceSquared);
void SetupMapObjectView(MtxFx43 *viewMatrix);
void DrawMapObjectList(MapObjectList *list, MtxFx43 *viewMatrix);

u32 GetViewTestRefreshPending(void);

void RequestViewTestRefresh(void);

typedef struct ViewFrustum ViewFrustum;

ViewFrustum *GetViewFrustum(void);

extern const u16 gViewTestPassedFlag;
extern const u16 gMapObjectNumberOverflowFlag;
extern const u32 gViewTestResultFlag;
extern const u32 gViewTestDistanceLimitFlag;
extern ViewFrustum gViewFrustumBeforeRotation;
extern ViewFrustum gViewFrustum;
extern s32 gItemSoundCameraHeightLimit;
