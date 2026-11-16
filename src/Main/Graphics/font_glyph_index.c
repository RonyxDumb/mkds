#include "Main/Graphics/font_glyph_index.h"
#include "font_glyph_layout.h"
#include "cpu_copy_clear_16.h"

void FillHalfwords(void *destination, u16 value, s32 size) {
    volatile u16 valueCopy = value;

    MIi_CpuClear16(valueCopy, destination, size);
}

u32 GetFontGlyphIndex(NNSG2dFont *font, u32 code) {
    u32 glyphIndex;

    glyphIndex = NNS_G2dFontFindGlyphIndex(font, code);
    if (glyphIndex == 0xffff) {
        glyphIndex = font->mPRes->mAlterCharIndex;
    }
    return glyphIndex;
}
