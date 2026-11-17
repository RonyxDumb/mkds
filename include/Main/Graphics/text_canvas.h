#pragma once
#include "types.h"

// The character canvas, font, character spacing and line spacing that InitTextCanvas stores and DrawTextOnCanvas draws
// with.
typedef struct TextCanvas {
    /* 00 */ void *mCharCanvas;
    /* 04 */ void *mFont;
    /* 08 */ s32 mCharSpacing;
    /* 0c */ s32 mLineSpacing;
} TextCanvas;
