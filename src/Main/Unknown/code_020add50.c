#include "Main/Unknown/code_020add50.h"
#include "Main/Unknown/code_020add80.h"
#include "code_02022aa8.h"

int GetFontGlyphImage(Unk02022aa8 *font, int glyphIndex) {
    u32 value0 = GetFontGlyphImageStride(font);
    u32 value1 = (u32) font->mUnk_00->mUnk_08->mUnk_08;
    return glyphIndex * value0 + value1;
}
