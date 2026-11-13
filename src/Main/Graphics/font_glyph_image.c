#include "Main/Graphics/font_glyph_image.h"
#include "Main/Graphics/font_glyph_image_stride.h"
#include "code_02022aa8.h"

u8 *GetFontGlyphImage(NNSG2dFont *font, int glyphIndex) {
    u32 value0 = GetFontGlyphImageStride(font);
    u8 *value1 = font->mPRes->mPGlyph->mGlyphTable;
    return value1 + glyphIndex * value0;
}
