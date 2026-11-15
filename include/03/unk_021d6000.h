#pragma once

#include "types.h"
#include "03/types_021d299c.h"
#include "00/Lib/DWC/code_02188720.h"
#include "00/Lib/DWC/code_0218a064.h"

typedef struct Rect Rect;

// Entry of gApObjectPositions, two halfwords.
typedef struct ApObjectPosition {
    /* 0 */ u16 mX;
    /* 2 */ u16 mY;
} ApObjectPosition;

extern const u8 gApScanEmptyBssid[];
extern u8 *gFirstReplyItemBuffer;
extern const Rect gTouchScreenRect;
extern u16 gEditKeyboardPage0KeyTexts[50];
extern u16 gEditKeyboardPage1KeyTexts[50];
extern u16 gEditKeyboardPage2KeyTexts[50];
extern u16 *gEditKeyboardPageKeyTexts[3];
