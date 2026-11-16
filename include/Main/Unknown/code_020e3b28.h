#pragma once

#include "types.h"
#include "Main/Unknown/code_020f9c6c.h"

typedef struct Unk020e1e98_154 Unk020e1e98_154;
typedef struct Unk020e3ef4 Unk020e3ef4;
typedef struct Unk020e1dc0 Unk020e1dc0;
typedef struct Bridge Bridge;

// Block of twelve words.
typedef struct Unk020e3e48 {
    /* 00 */ u32 field0[12];
} Unk020e3e48;

void rotcyl_state3Update(Unk020e3ef4 *object);
void rotcyl_renderAll(void *viewMatrix);
BOOL rotcyl_isRotatingCylinder(s32 kind);
void rotcyl_loadModels(Unk020e1dc0 *list);
void rotcyl_globalLogicInit(Unk020e1dc0 *list);
void rotcyl_init(Unk020e3ef4 *object, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo);
void *bridge_setupConfig(void);
void *bridge_setupRenderPart(void);
void *bridge_setupLogicPart(void);
void bridge_update(s32 a, Bridge *bridge); /* skipped for objects with mFlags & 4 (parked pool objects) */
void bridge_render(Unk020e3ef4 *object, void *viewMatrix, u32 alpha);
void bridge_renderAll(void *viewMatrix);
