#include "Main/Graphics/font_glyph.h"
#include "Main/Graphics/font_glyph_image.h"
#include "code_02022aa8.h"

void GetFontGlyph(NNSG2dGlyph *glyph, Unk02022aa8 *font, u32 glyphIndex) {
    glyph->mPWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
    glyph->mImage = GetFontGlyphImage(font, glyphIndex);
}
