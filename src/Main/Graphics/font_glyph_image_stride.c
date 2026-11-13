#include "Main/Graphics/font_glyph_image_stride.h"
#include "code_02022aa8.h"

u32 GetFontGlyphImageStride(NNSG2dFont *font) {
    return font->mPRes->mPGlyph->mCellSize;
}
