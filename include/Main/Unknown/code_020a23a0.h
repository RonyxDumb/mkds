#pragma once

#include "types.h"

typedef struct Kart Kart;

s32 GetKartBalloonOrShineHeight(Kart *kart);
void DrawTrophy(void);
void AdvanceTrophy(void);
s32 TrophyFX_MulInline(s32 lhs, s32 rhs);
s16 TrophyFX_SinIdx(s32 angle);
void InitTrophy(s32 modelIndex, u32 rankIndex);
void SetupTrophy(void);
