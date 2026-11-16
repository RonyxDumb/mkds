#include "Main/Graphics/font_glyph.h"
#include "Main/Graphics/font_glyph_image.h"
#include "font_glyph_layout.h"

void GetFontGlyph(NNSG2dGlyph *glyph, NNSG2dFont *font, u32 glyphIndex) {
    glyph->mPWidths = NFTR_GetCharacterWidthTileEntry(font, glyphIndex);
    glyph->mImage = NFTR_SomeFn_2(font, glyphIndex);
}
