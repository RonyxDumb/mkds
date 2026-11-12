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
extern u8 gYbObjKbNclName3[];
extern u8 gJbBgStep2NcgName[];
extern u8 gJbBgStep21NcgName[];
extern u8 gJb3ListNscName[];
extern u16 gDotSeparatedBytesFormat[];
extern u8 gYbObjMainNclName4[];
extern Bytes4 gApPaletteRows;
extern Bytes4 gApEntryIconPalettes;
extern u8 gYb5MultiNscName[];
extern u8 gYb5MultiNscName2[];
extern u8 gJb5InfoNscName[];
extern u8 data_ov003_021d7158[];
extern u8 data_ov003_021d716c[];
extern u8 data_ov003_021d7180[];
extern u8 data_ov003_021d7194[];
extern u8 gJb5MoveNscName[];
extern u8 data_ov003_021d71bc[];
extern u8 data_ov003_021d7214[];
extern u8 gYbObjMainNclName2[];
extern u8 gYbObjKbNclName[];
extern u8 gJbBgStep3NcgName2[];
extern u8 gYbBgStep3NclName2[];
extern u8 gXb4EditNscName[];
extern u8 gYbObjMainNclName3[];
extern u8 gYbObjKbNclName2[];
extern u8 gJbBgStep3NcgName3[];
extern u8 gYbBgStep3NclName3[];
extern u8 gXb4EditAddrNscName[];
extern u8 gJb4ErrorNscName[];
extern u8 gJbBgStep3NcgName4[];
extern u8 gYbBgStep3NclName4[];
extern u8 gXb4NoneNscName[];
extern u8 gXb4MultiNscName3[];
extern u8 gXb4MultiNscName4[];
extern u8 gXb4MultiNscName5[];
extern u8 gJbBgStep3NcgName5[];
extern u8 gYbBgStep3NclName5[];
extern u8 gXb4MultiNscName6[];
extern u8 gJbBgStep3NcgName6[];
extern u8 gYbBgStep3NclName6[];
extern u8 gXb4MultiNscName7[];
extern YbBgStep11NclName gYbBgStep11NclName2;
extern u8 gYbObjMainNclName5[];
extern u8 gYbObjWayNclName[];
extern u8 gJbBgStep1NcgName3[];
extern u8 gJbBgStep1NclName3[];
extern u8 gJb2ApNscName[];
extern WayPaletteRows gWayPaletteRows;
extern Bytes22 gYbBgStep21NclName2;
extern u8 gJbBgStep2NcgName2[];
extern u8 gYbBgStep2NclName2[];
extern u8 gJb3WayNscName[];
extern u8 gJbBgStep3NcgName7[];
extern u8 gYbBgStep3NclName7[];
extern u8 gXb4MultiNscName8[];
extern u8 gXb4MultiNscName9[];
extern ConnectMessageIds gConnectMessageIds;
extern u8 gXb4NoneNscName2[];
extern u8 gXb4MultiNscName10[];
extern u8 gJbBgStep2NcgName3[];
extern u8 gYbBgStep2NclName3[];
extern u8 gXb3MultiNscName[];
extern u8 gJbBgStep3NcgName8[];
extern u8 gYbBgStep3NclName8[];
extern u8 gJb4UsbNscName[];
extern const char gAddressTextFormat[];
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
