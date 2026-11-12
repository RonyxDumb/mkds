#pragma once

#include "types.h"
#include "03/Menu/jb2_menu.h"

typedef struct Bytes4 Bytes4;

// Bytes moved as one value.
typedef struct Bytes21 {
    /* 00 */ u8 mUnk_00[0x15];
} Bytes21;

typedef struct Bytes22 {
    /* 00 */ u8 mUnk_00[0x16];
} Bytes22;

typedef struct Bytes23 {
    /* 00 */ u8 mUnk_00[0x17];
} Bytes23;

// Six bytes moved as one value.
typedef struct Bytes6 {
    /* 0 */ u8 mBytes[6];
} Bytes6;

// Four bytes moved as one value.
typedef struct WayPaletteRows {
    /* 0 */ u8 mRowIndices[4];
} WayPaletteRows;

// Three words moved as one value.
typedef struct ConnectMessageIds {
    /* 00 */ u32 mMessageIndices[3];
} ConnectMessageIds;

extern char *gWhStateNames[];
extern u8 gWhAlreadyIdleText[];
extern u8 gWhFinalizeStateFormat[];
extern u8 gWhNoChildText[];
extern u8 gWhNoDataSetText[];
extern u8 gWhRecvBufferSizeFormat[];
extern u8 gWhSendBufferSizeFormat[];
extern u8 gWhConnectModeFormat[];
extern u8 gWhDecidedChannelFormat[];
extern u8 gWhChannelBusyRatioFormat[];
extern u8 gWhIndicateStateFormat[];
extern u8 gWhEndParentFailedText[];
extern u8 gWhStartKeySharingFailedText[];
extern u8 gWhChildConnectedFormat[];
extern u8 gWhChildDisconnectedFormat[];
extern u8 gWhStateFromFormat[];
extern u8 gWhStateToFormat[];
extern u8 gCrcTable[];
