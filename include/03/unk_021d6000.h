#pragma once

#include "types.h"
#include "03/types_021d299c.h"
#include "00/Lib/DWC/code_02188720.h"

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

extern u8 gApScanEmptyBssid[];
extern u32 gThreadStackSize;
extern s32 gTimeoutAtMs;
extern s32 gStartEntryCount;
extern u8 *gKind2ItemBuffer;
extern u32 gFormatAddressesFlag;
extern char gSixAsterisksString[];
extern Bytes7 gKind2Item3Bytes;
extern Bytes4 gWarpString;
extern u8 gExchangeSocketConfig[];
extern Rect gTouchScreenRect;
extern u16 *gEditKeyboardPageKeyTexts[3];
