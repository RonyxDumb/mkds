#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

u8 obpak_onItemCollide(Unk020e43a8 *obPakkunSf, void *itemObject, u8 *b, u8 *c);
u8 obpak_onDriverCollide(Unk020e43a8 *obPakkunSf, void *kart, u8 *b, u8 *c);
void obpak_update(u32 a, Unk020e43a8 *obPakkunSf);
