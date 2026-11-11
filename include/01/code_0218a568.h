#pragma once

#include "types.h"

typedef struct Unk02188950 Unk02188950;

int SwitchToBounceEffectsOnCollision(Unk02188950 *mapObject);
int StartBombKingBounceEffects(Unk02188950 *mapObject);
void StartBombKingWalkState(Unk02188950 *mapObject);
void StartBombKingRandomState(Unk02188950 *mapObject);
void StartBombKingWalkToBombState(Unk02188950 *mapObject);
void func_ov001_0218a828(Unk02188950 *mapObject);
void StartItemBombThrow(Unk02188950 *mapObject);
void StartBombKingChaseState(Unk02188950 *mapObject);
void StoreNewItemBombAndStartThrow(Unk02188950 *mapObject);
void StartBombKingThrowBombsState(Unk02188950 *mapObject);
void StartBombKingJumpCycle(Unk02188950 *mapObject);
void func_ov001_0218aba0(Unk02188950 *mapObject);
