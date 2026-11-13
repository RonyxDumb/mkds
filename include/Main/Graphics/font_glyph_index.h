#pragma once

#include "types.h"

typedef struct NNSG2dFont NNSG2dFont;

u32 GetFontGlyphIndex(NNSG2dFont *font, u32 code);
void FillHalfwords(void *destination, u16 value, s32 size);
