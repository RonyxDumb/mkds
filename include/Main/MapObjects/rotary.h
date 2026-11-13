#pragma once

#include "types.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Graphics/model_animation.h"

typedef struct RotaryKindInfo RotaryKindInfo;
typedef struct CollisionMapObject CollisionMapObject;
typedef struct Rotary Rotary;
typedef struct BridgeDrawList BridgeDrawList;
typedef struct Bridge Bridge;

void UpdateRotaryState3(Rotary *object);
void DrawAllKind203MapObjects(void *viewMatrix);
BOOL IsRotaryKind(s32 kind);
void CreateRotary(BridgeDrawList *list);
void InitRotaryObjects(BridgeDrawList *list);
void InitRotary(Rotary *object, struct CourseMapRow *courseRow, RotaryKindInfo *kindInfo);
MapObjectKindData *CreateBridgeKindData(void);
MapObjectList *CreateBridgeDrawList(void);
MapObjectList *CreateBridgeUpdateList(void);
void UpdateBridge(s32 unused, Bridge *bridge); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawBridge(CollisionMapObject *object, void *viewMatrix, u32 alpha);
void DrawAllBridges(void *viewMatrix);

extern StateCallbacks gRotaryStateTable[4];

