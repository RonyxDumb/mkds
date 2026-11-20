#pragma once

#include "types.h"
#include "03/Menu/jb2_menu.h"

// Palette row of the selected way, by way index: mRowIndices.
typedef struct WayPaletteRows {
    /* 0 */ u8 mRowIndices[4];
} WayPaletteRows;

// Message index of the connect message box, by the second secondary menu pair value: mMessageIndices.
typedef struct ConnectMessageIds {
    /* 00 */ u32 mMessageIndices[3];
} ConnectMessageIds;

extern char gWhStateStopName[26];
extern char gWhStateIdleName[26];
extern char gWhStateBusyName[26];
extern char gWhStateErrorName[27];
extern char gWhStateScanningName[30];
extern char gWhStateConnectedName[31];
extern char gWhStateKeySharingName[32];
extern char gWhStateDataSharingName[33];
extern char gWhStateConnectFailName[34];
extern char gWhStateMeasureChannelName[36];
extern char *gWhStateNames[10];
extern char gWhIndicateStateFormat[30];
extern char gWhEndParentFailedText[37];
extern char gWhStartKeySharingFailedText[47];
