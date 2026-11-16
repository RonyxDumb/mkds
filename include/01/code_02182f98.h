#pragma once

#include "types.h"

typedef struct Coin Coin;

void coin_renderShadow(void *f, Coin *coin, void *h, u32 l);
void coin_globalPreRenderShadow(void);
void coin_globalInitShadow(void);
