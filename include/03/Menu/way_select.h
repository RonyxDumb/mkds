#pragma once

#include "types.h"
#include "03/System/touch_key_input.h"
#include "03/Menu/wifi_menu_strings.h"

// Values of gWaySelectedIndex and gWaySavedIndex, the highlighted way; UpdateWayRelease opens the screen of the chosen
// one.
#define WAY_SELECTED_AP_SCAN 0
#define WAY_SELECTED_VALUE_RECORDS 1
#define WAY_SELECTED_EXCHANGE_SEARCH 2
#define WAY_SELECTED_JB3_LIST 3

extern const Rect gWaySelectionRects[2][4];

void UpdateWayFadeOut(void);
void StartWayClose(void);
void UpdateWayResult(void);
void UpdateWayNop(void);
void UpdateWayInput(void);
void UpdateWay(void);
void UpdateWayButtonsIn(void);
void UpdateWayFadeIn(void);
void StartWayFadeIn(void);
void LoadWayFilesAndSetBgCnt(void);
void SetupWay(void);

// The text of a file path of the way screen palette, passed to BuildFilePathWithLanguage.
typedef struct WayPaletteFileName {
    /* 00 */ u8 mText[0x16];
} WayPaletteFileName;

extern const Rect gWayRects[2][4];
extern WayPaletteFileName gYbBgStep21NclName2;
extern WayPaletteRows gWayPaletteRows;
extern const s8 gWayMoveTargets[2][4][4];
extern const s8 gWayMessageDigitColumns[6];
extern u8 *gYbBgStep21Ncl;
extern u8 gWayChosen;
extern s8 gWaySelectedIndex;
extern s8 gWaySavedIndex;
