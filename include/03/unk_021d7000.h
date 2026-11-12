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

// Objects whose layout isn't known yet.
extern Bytes6 gMessageBoxWindowExtraBitFlags;
extern Bytes21 gYbBgStep2NclName;
extern Bytes22 gYbBgStep21NclName;
extern Bytes23 gJb3ListBackNscName;
extern char gYbObjKbNclName3[];
extern char gJbBgStep2NcgName[];
extern char gJbBgStep21NcgName[];
extern char gJb3ListNscName[];
extern u16 gDotSeparatedBytesFormat[];
extern char gYbObjMainNclName4[];
extern Bytes4 gApPaletteRows;
extern Bytes4 gApEntryIconPalettes;
extern YbBgStep11NclName gYbBgStep11NclName2;
extern char gYbObjMainNclName5[];
extern char gYbObjWayNclName[];
extern char gJbBgStep1NcgName3[];
extern char gJbBgStep1NclName3[];
extern char gJb2ApNscName[];
extern WayPaletteRows gWayPaletteRows;
extern Bytes22 gYbBgStep21NclName2;
extern char gJbBgStep2NcgName2[];
extern char gYbBgStep2NclName2[];
extern char gJb3WayNscName[];
extern u8 *gWhStateNames[];
extern u8 gWhAlreadyIdleText[];
extern u8 gWhFinalizeStateFormat[];
extern u8 gWhNoChildText[];
extern u8 gWhNoDataSetText[];
extern u8 gWhRecvBufferSizeFormat[];
extern u8 gWhSendBufferSizeFormat[];
extern u8 gWhConnectModeFormat[];
extern u8 gWhDecidedChannelFormat[];
extern void *gTextCanvasNftrNames[];
extern u8 gWhChannelBusyRatioFormat[];
extern u8 gWhIndicateStateFormat[];
extern u8 gWhEndParentFailedText[];
extern u8 gWhStartKeySharingFailedText[];
extern u8 gWhChildConnectedFormat[];
extern u8 gWhChildDisconnectedFormat[];
extern u8 gWhStateFromFormat[];
extern u8 gWhStateToFormat[];
extern u8 gCrcTable[];
