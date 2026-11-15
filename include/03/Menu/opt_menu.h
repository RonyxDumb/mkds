#pragma once

#include "types.h"
#include "03/types_021d299c.h"

typedef struct OamEntry OamEntry;
typedef struct Rect Rect;

// The text of a file path the menu loads, passed to BuildFilePathWithLanguage.
typedef struct YbBgOptionNclName {
    /* 00 */ u8 mText[0x16];
} YbBgOptionNclName;

// The text of a file path the menu loads, passed to BuildFilePathWithLanguage.
typedef struct YbBgOption1NclName {
    /* 00 */ u8 mText[0x17];
} YbBgOption1NclName;

void RequestOptMenuPaletteRowCopy(void);
void MoveOptMenuSelection(s32 direction);
void UpdateOptMenuRelease(void);
void UpdateOptMenuFadeOut(void);
void StartOptMenuClose(void);
void UpdateOptMenuResult(void);
void UpdateOptMenuNop(void);
void UpdateOptMenuInput(void);
void UpdateOptMenu(void);
void UpdateOptMenuButtonsIn(void);
void UpdateOptMenuFadeIn(void);
void StartOptMenuFadeIn(void);
void LoadOptMenuFilesAndSetBgCnt(void);
void SetupOptMenu(void);

extern YbBgOption1NclName gYbBgOption1NclName;
extern YbBgOptionNclName gYbBgOptionNclName;
extern const Rect gOptMenuSelectionRects[3];
extern const Rect gOptMenuRects[3];
extern const u16 gOptMenuOamEntryPosition[2];
extern const u8 gOptMenuPaletteRows[3];
// Values of gOptMenuSelectedIndex when an entry is chosen.
#define OPT_MENU_SELECTED_INFO 0
#define OPT_MENU_SELECTED_MULTI 1
#define OPT_MENU_SELECTED_MESSAGE 2

extern u8 gOptMenuSelectedIndex;
extern u8 gOptMenuEntryChosen[4];
extern OamEntry *gOptMenuOamEntry;
extern void *gYbBgOption1Ncl;
