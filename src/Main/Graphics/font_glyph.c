#include "Main/Graphics/font_glyph.h"
#include "Main/Graphics/font_glyph_image.h"
#include "font_glyph_layout.h"

void GetFontGlyph(NNSG2dGlyph *glyph, NNSG2dFont *font, u32 glyphIndex) {
    glyph->mPWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
    glyph->mImage = GetFontGlyphImage(font, glyphIndex);
}
