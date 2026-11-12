#include "Main/Graphics/font_glyph_image_stride.h"
#include "code_02022aa8.h"

u32 GetFontGlyphImageStride(Unk02022aa8 *font) {
    return font->mPRes->mPGlyph->mCellSize;
}
