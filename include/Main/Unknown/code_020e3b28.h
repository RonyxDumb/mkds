#pragma once

#include "types.h"
#include "Main/Unknown/code_020f9c6c.h"

typedef struct Unk020e1e98_154 Unk020e1e98_154;
typedef struct Unk020e1d10 Unk020e1d10;
typedef struct Rotary Rotary;
typedef struct BridgeDrawList BridgeDrawList;
typedef struct Bridge Bridge;

extern const BridgeDrawList data_02158ce8;

void UpdateRotaryState3(Rotary *object);
void DrawAllKind203MapObjects(void *viewMatrix);
BOOL IsRotaryKind(s32 kind);
void CreateRotary(BridgeDrawList *list);
void InitRotaryObjects(BridgeDrawList *list);
void InitRotary(Rotary *object, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo);
void *CreateBridgeKindData(void);
void *CreateBridgeDrawList(void);
void *CreateBridgeUpdateList(void);
void UpdateBridge(s32 unused, Bridge *bridge); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawBridge(Unk020e1d10 *object, void *viewMatrix, u32 alpha);
void DrawAllBridges(void *viewMatrix);
