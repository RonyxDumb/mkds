#pragma once

#include "types.h"
#include "Main/Unknown/code_020a7000.h"
#include "Main/Unknown/code_020f36d8.h"

void CreateSanboHAndSanboB(void *a);
u8 CollideItemObjectWithSanbo(Sanbo *sanbo, ItemObject *itemObject, u8 *b, u8 *c);
u8 CollideKartWithSanbo(Sanbo *sanbo, Kart *kart, u8 *b, u8 *c);
