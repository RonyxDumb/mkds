#pragma once

#include "types.h"

typedef struct NNSG2dFont NNSG2dFont;

u8 *GetFontGlyphImage(NNSG2dFont *font, int glyphIndex);
