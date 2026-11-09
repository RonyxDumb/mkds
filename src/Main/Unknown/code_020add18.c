#include "Main/Unknown/code_020add18.h"
#include "Main/Unknown/code_020add50.h"
#include "code_02022aa8.h"

void GetFontGlyph(NNSG2dGlyph *glyph, Unk02022aa8 *font, u32 glyphIndex) {
    glyph->mPWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
    glyph->mImage = GetFontGlyphImage(font, glyphIndex);
}
