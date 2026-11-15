#pragma once

#include "types.h"
#include "03/unk_021da000.h"
#include "03/unk_021d6000.h"
#include "03/types_021d299c.h"
#include "03/Menu/jb2_menu.h"

extern const ApObjectPosition gApObjectPositions[6];
extern const Rect gApSelectionRects[7];

// Values of Ap.mCloseKind: how the screen was left; BACK also slides the menu pair objects out.
enum {
    AP_CLOSE_KIND_NONE,
    AP_CLOSE_KIND_SELECTED,
    AP_CLOSE_KIND_BACK,
};

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
extern Bytes4 gApEntryIconPalettes;
extern Bytes4 gApPaletteRows;
extern const u8 gApRects[56];
extern const s8 gApMessageDigitColumns[6];
extern const u8 gApEntryImageIndices[4];
extern u8 gApSelectedIndex;
extern struct Ap *gAp;
