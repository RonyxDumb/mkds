#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b200.h"

#define TROPHY_WOBBLE_AMPLITUDE 0xaab
#define TROPHY_WOBBLE_ANGLE_PER_FRAME 0x36

typedef struct Kart Kart;

s32 GetKartBalloonOrShineHeight(Kart *kart);
void DrawTrophy(void);
void AdvanceTrophy(void);
s32 TrophyFX_MulInline(s32 lhs, s32 rhs);
s16 TrophyFX_SinIdx(s32 angle);
void InitTrophy(s32 modelIndex, u16 rankIndex);
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

extern Vec3 gTrophyCameraPos;
extern Vec3 gTrophyCameraUp;
extern char *gTKinoNsbmdName[9];
extern char *gTKinoNsbtpName[9];
extern char gTrophyTKinoNsbmd[];
extern char gTrophyTFlowNsbmd[];
extern char gTrophyTStarNsbmd[];
extern char gTrophyTSpecNsbmd[];
extern char gTrophyTKoraNsbmd[];
extern char gTrophyTBanaNsbmd[];
extern char gTrophyTKonoNsbmd[];
extern char gTrophyTThunNsbmd[];
extern char gTrophyTrophyNsbmd[];
extern char gTrophyTKinoNsbtp[];
extern char gTrophyTFlowNsbtp[];
extern char gTrophyTStarNsbtp[];
extern char gTrophyTSpecNsbtp[];
extern char gTrophyTKoraNsbtp[];
extern char gTrophyTBanaNsbtp[];
extern char gTrophyTKonoNsbtp[];
extern char gTrophyTThunNsbtp[];
extern char gTrophyTrophyNsbtp[];
