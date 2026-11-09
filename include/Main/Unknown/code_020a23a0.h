#pragma once

#include "types.h"

typedef struct Kart Kart;

s32 GetKartBalloonOrShineHeight(Kart *kart);
void DrawTrophy(void);
void AdvanceTrophy(void);
s32 TrophyMulFixed12Rounded(s32 a, s32 b);
s16 TrophyGetAnglePairFirst(s32 angle);
void InitTrophy(s32 modelIndex, u32 rankIndex);
void SetupTrophy(void);
