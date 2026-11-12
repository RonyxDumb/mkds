#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Unknown/code_020e6b58.h"
#include "code_02146d78.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Unknown/unk_0217a000.h" // Camera

void UpdateMapObjectViewTests(void);
void RefreshMapObjectViewTests(void);
void UpdateMapObjects(void);
void DrawMapObjects(Camera *view);
void DrawKoopaBlocksKind203AndBridges(Camera *view);
s32 FindMapObjectsTouchingKart(Kart *kart, Vec3 *position, Vec3 *hitOffset);
s32 FindMapObjectsOfKindInRadius(Vec3 *position, s32 radius, s32 kind);
