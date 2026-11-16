#include "Main/Graphics/font_glyph_image.h"
#include "Main/Graphics/font_glyph_image_stride.h"
#include "font_glyph_layout.h"

u8 *NFTR_SomeFn_2(NNSG2dFont *font, int glyphIndex) {
    u32 glyphStride = NFTR_SomeFn_3(font);
    u8 *glyphTable = font->mPRes->mPGlyph->mGlyphTable;
    return glyphTable + glyphIndex * glyphStride;
}
