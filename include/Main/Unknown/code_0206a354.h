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

void AdvanceKartThunderShrink(Kart *kart);
void StartKartThunderShrink(Kart *kart);
void AdvanceKartState5(Kart *kart);
s32 StartKartState5(Kart *kart, const Vec3 *pushDirection, s32 record);
void AdvanceKartState4(Kart *kart);
void StartKartState4(Kart *kart, const Vec3 *pushDirection, s32 record);
BOOL TryStartKartState4(Kart *kart, MapObject *mapObject);
void AdvanceKartState3(Kart *kart);
void StartKartState3(Kart *kart);
BOOL TryStartKartState3(Kart *kart);
void AdvanceKartState6(Kart *kart);
void StartKartState6(Kart *kart);
BOOL TryStartKartState6(Kart *kart);
void AdvanceKartState1And2(Kart *kart);
void StartKartState2(Kart *kart, int spinCount, int skipSound);
