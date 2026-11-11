#pragma once

#include "types.h"

typedef struct Coin Coin;

void DrawCoinShadow(void *mapObjectList, Coin *coin, void *viewMatrix, u32 mapObjectAlpha);
void AdvanceCoinShadowRotationIndex(void);
void ResetCoinShadowRotationIndex(void);
