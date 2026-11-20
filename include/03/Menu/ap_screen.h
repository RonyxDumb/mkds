#pragma once

#include "types.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/wifi_menu_tables.h"
#include "03/System/touch_key_input.h"
#include "03/Menu/jb2_menu.h"

extern const ApObjectPosition gApObjectPositions[6];
extern const Rect gApSelectionRects[7];

// Values of gApSelectedIndex: the three entries, the multi button, and the reset button of each entry.
#define AP_SELECTED_FIRST_ENTRY 0
#define AP_SELECTED_SECOND_ENTRY 1
#define AP_SELECTED_THIRD_ENTRY 2
#define AP_SELECTED_MULTI 3
#define AP_SELECTED_FIRST_RESET 4
#define AP_SELECTED_SECOND_RESET 5
#define AP_SELECTED_THIRD_RESET 6

// Values of Ap.mCloseKind: how the screen was left; BACK also slides the menu pair objects out.
enum {
    AP_CLOSE_KIND_NONE,
    AP_CLOSE_KIND_SELECTED,
    AP_CLOSE_KIND_BACK,
};

// Palette rows of the selected button, by selected index (the three entries, then the multi button).
typedef struct ApPaletteRows {
    /* 0 */ u8 mRowIndices[4];
} ApPaletteRows;

// Palette of the entry icon, by the entry's set type (a type above 2 uses the last one).
typedef struct ApEntryIconPalettes {
    /* 0 */ u8 mPaletteIndices[4];
} ApEntryIconPalettes;

// The screen of the three stored access point entries: the remembered entry, the icon and reset button objects and the
// close kind.
typedef struct Ap {
    /* 00 */ void *mYbBgStep11Ncl;
    /* 04 */ OamRange *mEntryIconObjects[3];
    /* 10 */ OamRange *mResetButtonObjects[3];
    /* 1c */ u8 mRememberedEntryIndex;
    /* 1d */ u8 mCloseKind;
} Ap;

void RequestApSelectionPalette(void);
void UpdateApMessageClose(void);
void UpdateApMessageResult(void);
void SetApSelectedButtonImage(void);
void MoveApSelection(int direction);
void PlaceApSelection(void);
void UpdateApRelease(void);
void UpdateApFadeOut(void);
void StartApClose(void);
void UpdateApResult(void);
void UpdateApNop(void);
void UpdateApInput(void);
void UpdateAp(void);
void UpdateApButtonsIn(void);
void UpdateApFadeIn(void);
void StartApFadeIn(void);

extern YbBgStep11NclName gYbBgStep11NclName2;
extern ApEntryIconPalettes gApEntryIconPalettes;
extern ApPaletteRows gApPaletteRows;
extern const u8 gApRects[56];
extern const s8 gApMessageDigitColumns[6];
extern const u8 gApEntryImageIndices[4];
extern u8 gApSelectedIndex;
extern struct Ap *gAp;
