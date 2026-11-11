#pragma once

#include "types.h"

typedef struct Hash20Context Hash20Context;

void CPSi_sha1_block(Hash20Context *context, const u8 *block);
void long_from_char(u32 *words, const u8 *bytes, u32 byteCount);
