#pragma once

#include "types.h"
#include "Main/Unknown/code_020f9c6c.h"

typedef struct Unk020e1e98_154 Unk020e1e98_154;
typedef struct Unk020e3ef4 Unk020e3ef4;
typedef struct BridgeDrawList BridgeDrawList;
typedef struct Bridge Bridge;

extern const BridgeDrawList data_02158ce8;

void func_020e4380(Unk020e3ef4 *object);
void func_020e435c(void *viewMatrix);
BOOL func_020e4320(s32 kind);
void func_020e4184(BridgeDrawList *list);
void func_020e410c(BridgeDrawList *list);
void func_020e3ef4(Unk020e3ef4 *object, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo);
void *CreateBridgeKindData(void);
void *CreateBridgeDrawList(void);
void *CreateBridgeUpdateList(void);
void UpdateBridge(s32 a, Bridge *bridge); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawBridge(Unk020e3ef4 *object, void *viewMatrix, u32 alpha);
void DrawAllBridges(void *viewMatrix);
