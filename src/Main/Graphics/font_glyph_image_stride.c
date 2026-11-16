#include "Main/Graphics/font_glyph_image_stride.h"
#include "font_glyph_layout.h"

u32 GetFontGlyphImageStride(NNSG2dFont *font) {
    return font->mPRes->mPGlyph->mCellSize;
}
