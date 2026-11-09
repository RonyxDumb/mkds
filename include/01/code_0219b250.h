#pragma once

#include "types.h"
#include "Main/Unknown/code_0209bc74.h" // MapObjectModel

// First argument of LoadMapObjectModelAnimated and LoadMapObjectModelShadow.
typedef struct Unk0219b478 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} Unk0219b478;

void func_ov001_0219b250(MapObjectModel *p0);
void func_ov001_0219b25c(MapObjectModel *p0, void *p1);
void func_ov001_0219b28c(MapObjectModel *p0, void *p1);
void LoadMapObjectModelNsbtpAnimation(MapObjectModel *p0, const char *p1);
void LoadMapObjectModelNsbtaAnimation(MapObjectModel *p0, const char *p1);
void LoadMapObjectModelNsbmaAnimation(MapObjectModel *p0, const char *p1);
void LoadMapObjectModelNsbcaAnimation(MapObjectModel *p0, const char *p1);
MapObjectModel *LoadMapObjectModelShadow(Unk0219b478 *p0, const char *p1);
MapObjectModel *LoadMapObjectModelAnimated(Unk0219b478 *p0, const char *p1);
void *LoadMissionRunFile(const char *p0);
void *func_ov001_0219b510(void *p0, void *p1, void *p2, u32 p3, u16 p4, u16 p5, u16 p6);
