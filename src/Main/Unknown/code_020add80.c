#include "Main/Unknown/code_020add80.h"
#include "code_02022aa8.h"

u32 GetFontGlyphImageStride(Unk02022aa8 *font) {
    return font->mPRes->mPGlyph->mCellSize;
}
