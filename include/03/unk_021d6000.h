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

// Objects whose layout isn't known yet.
extern s8 gJb3ListDigitColumns[];
extern Rect gJb3ListCellRect;
extern Rect gJb3ListLeftButtonRect;
extern Rect gJb3ListRightButtonRect;
extern u8 gJb3ListIdByEntryIndex[];
extern const u8 gJb3ListCellImageIds[][3];
extern u8 gJb3ListEntryIndexById[];
extern u16 gJb3ListBackNscOffsets[];
extern u8 gApEntryImageIndices[];
extern s8 gApMessageDigitColumns[];
extern ApObjectPosition gApObjectPositions[];
extern u8 gApRects[];
extern Rect gApSelectionRects[];
extern s8 gWayMessageDigitColumns[];
extern s8 gWayMoveTargets[][4][4];
extern Rect gWayRects[][4];
extern Rect gWaySelectionRects[][4];
extern u8 gApScanEmptyBssid[];
extern u8 gUsbScanEmptyBssid[];
extern u8 gMessageBoxButtonCounts[];
extern u16 gMessageBoxTextOffset[2];
extern u8 gMessageBoxImageIds[];
extern u8 gMessageBoxWindowRect[];
extern s8 gMessageBoxKeyResults[][2];
extern u8 gMessageBoxButtonSlots[][2];
extern u8 gMessageBoxButtonImageIds[][2];
extern u16 gMessageBoxButtonSizes[][2];
extern u16 gMessageBoxTextSizes[][2];
extern u16 gMessageBoxPositions[][2];
extern u16 gMessageBoxSizes[][2];
extern u16 gMessageBoxButtonPositions[][2][2];
extern u32 gThreadStackSize;
extern s32 gTimeoutAtMs;
extern s32 gStartEntryCount;
extern u8 *gKind2ItemBuffer;
extern u32 gFormatAddressesFlag;
extern char gSixAsterisksString[];
extern Bytes7 gKind2Item3Bytes;
extern Bytes4 gWarpString;
extern u8 gExchangeSocketConfig[];
extern u8 gTaskListCapacities[];
extern u8 gEditAddrKeyboardRow4HighlightValues[];
extern u8 gEditAddrKeyboardExtraKeyImages[];
extern u8 gEditAddrKeyboardRow4KeyImages[];
extern u8 gEditAddrKeyboardKeyPalettes[];
extern u8 gEditAddrKeyboardRow4KeyInputs[];
extern u8 gEditAddrKeyboardExtraKeyInputs[];
extern u16 gEditAddrKeyboardDigitKeySize[];
extern const u16 gEditAddrKeyboardRowTextAreaSize[];
extern u16 gEditAddrKeyboardExtraKeySize[];
extern u16 gEditAddrKeyboardRow4KeySize[];
extern u16 gEditAddrKeyboardExtraKeyPositions[][2];
extern u16 gEditAddrKeyboardRow4KeyPositions[][2];
extern u8 gEditAddrKeyboardDigitInputs[];
extern u16 gEditAddrKeyboardKeyTexts[];
extern u16 gEditAddrKeyboardDigitKeyPositions[][2];
extern u16 gEditAddrKeyboardCursorX[];
extern u16 gEditAddrKeyboardCursorY[];
extern s8 gEditAddrKeyboardCursorMoves[];
extern Rect gTouchScreenRect;
extern u16 *gEditKeyboardPageKeyTexts[3];
extern u8 gEditAddrKeyboardRow4KeyCounts[];
extern u8 gEditAddrKeyboardDigitKeyCounts[];
extern u8 gEditAddrKeyboardExtraKeyCounts[];
extern u16 gEditAddrKeyboardTextRectStart[];
