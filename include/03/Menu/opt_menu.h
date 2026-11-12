#pragma once

#include "types.h"

typedef struct OamEntry OamEntry;
typedef struct Rect Rect;

typedef struct YbBgOptionNclName {
    /* 00 */ u8 mText[0x16];
} YbBgOptionNclName;

typedef struct YbBgOption1NclName {
    /* 00 */ u8 mText[0x17];
} YbBgOption1NclName;

extern u8 gOptMenuPaletteRows[];
extern u16 gOptMenuOamEntryPosition[];
extern Rect gOptMenuRects[];
extern u16 gOptMenuSelectionLeft[];
extern u16 gOptMenuSelectionTop[];
extern u16 gOptMenuSelectionRight[];
extern u16 gOptMenuSelectionBottom[];
extern YbBgOptionNclName gYbBgOptionNclName;
extern YbBgOption1NclName gYbBgOption1NclName;
extern u8 gJbBgOptionNcgName[];
extern u8 gJb5OptMenuNscName[];
extern u8 gOptMenuSelectedIndex;
extern void *gYbBgOption1Ncl;
extern OamEntry *gOptMenuOamEntry;

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
