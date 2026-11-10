#pragma once

#include "types.h"

typedef struct Kart Kart;

typedef struct MapObject MapObject;

extern const s16 data_usa_02154a54[];
extern const s16 data_usa_021654c4;
extern const s32 data_usa_021654d0;
extern const s32 data_usa_021654d4;
extern const s32 data_usa_021654e0;
extern const s32 data_usa_021654e4;
extern const s32 data_usa_021654e8;
extern const s32 data_usa_021654f0;
extern const s32 data_usa_02165508;
extern const s32 data_usa_0216550c;
extern const Vec4 data_usa_0216556c;

void AdvanceKartThunderShrink(Kart *p);
void StartKartThunderShrink(Kart *p);
void AdvanceKartState5(Kart *p);
s32 StartKartState5(Kart *p, const Vec3 *a, s32 b);
void AdvanceKartState4(Kart *p);
void StartKartState4(Kart *p, const Vec3 *a, s32 b);
BOOL TryStartKartState4(Kart *p, MapObject *a);
void AdvanceKartState3(Kart *p);
void StartKartState3(Kart *p);
BOOL TryStartKartState3(Kart *p);
void AdvanceKartState6(Kart *p);
void StartKartState6(Kart *p);
BOOL TryStartKartState6(Kart *p);
void AdvanceKartState1And2(Kart *p);
void StartKartState2(Kart *p, int a, int b);
