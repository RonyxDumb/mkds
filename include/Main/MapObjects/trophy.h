#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b200.h"

typedef struct Kart Kart;

s32 GetKartBalloonOrShineHeight(Kart *kart);
void DrawTrophy(void);
void AdvanceTrophy(void);
s32 TrophyFX_MulInline(s32 lhs, s32 rhs);
s16 TrophyFX_SinIdx(s32 angle);
void InitTrophy(s32 modelIndex, u32 rankIndex);
void SetupTrophy(void);

extern const s32 gTrophyModelEffectOffsetY[9];
extern const s16 gTrophyModelLight0Y[10];
extern const s32 gTrophyModelEffectRadius[9];
extern const s16 gTrophyModelLight1X[10];
extern const s16 gTrophyModelLight0Z[10];
extern const s16 gTrophyModelLight0X[10];
extern const s16 gTrophyModelLight1Y[10];
extern const s16 gTrophyModelLight1Z[10];
extern struct Trophy *gTrophy;
