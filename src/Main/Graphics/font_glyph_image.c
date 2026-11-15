#include "Main/Graphics/font_glyph_image.h"
#include "Main/Graphics/font_glyph_image_stride.h"
#include "code_02022aa8.h"

u8 *GetFontGlyphImage(NNSG2dFont *font, int glyphIndex) {
    u32 glyphStride = GetFontGlyphImageStride(font);
    u8 *glyphTable = font->mPRes->mPGlyph->mGlyphTable;
    return glyphTable + glyphIndex * glyphStride;
}
