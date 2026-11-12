#pragma once

#include "types.h"
#include "03/types_021d299c.h"
#include "00/Lib/DWC/code_02188720.h"
#include "00/Lib/DWC/code_0218a064.h"

typedef struct Rect Rect;

// Seven bytes moved as one value.
typedef struct Bytes7 {
    /* 0 */ u8 mBytes[7];
} Bytes7;

// Entry of gApObjectPositions, two halfwords.
typedef struct ApObjectPosition {
    /* 0 */ u16 mX;
    /* 2 */ u16 mY;
} ApObjectPosition;

// Four bytes moved as one value.
typedef struct Bytes4 {
    /* 0 */ u8 mBytes[4];
} Bytes4;

// 0x44 bytes moved as one value.
typedef struct Bytes68 {
    /* 00 */ u32 mUnk_00[0x11];
} Bytes68;

extern const u8 gApScanEmptyBssid[];
extern u8 *gKind2ItemBuffer;
extern const Rect gTouchScreenRect;
extern u16 gEditKeyboardPage0KeyTexts[50];
extern u16 gEditKeyboardPage1KeyTexts[50];
extern u16 gEditKeyboardPage2KeyTexts[50];
extern u16 *gEditKeyboardPageKeyTexts[3];
