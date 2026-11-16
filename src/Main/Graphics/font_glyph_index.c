#include "Main/Graphics/font_glyph_index.h"
#include "font_glyph_layout.h"
#include "cpu_copy_clear_16.h"

void DoFill16(void *destination, u16 value, s32 size) {
    volatile u16 valueCopy = value;

    Mem_CpuFill16(valueCopy, destination, size);
}

u32 NFTR_SomeFn(NNSG2dFont *font, u32 code) {
    u32 glyphIndex;

    glyphIndex = NFTR_GetTileIndexForCharacter(font, code);
    if (glyphIndex == 0xffff) {
        glyphIndex = font->mPRes->mAlterCharIndex;
    }
    return glyphIndex;
}
