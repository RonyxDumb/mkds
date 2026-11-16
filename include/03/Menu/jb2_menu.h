#pragma once

#include "types.h"
#include "03/System/touch_key_input.h"

typedef struct Rect Rect;

// The palette rows the Jb2 menu copies, one per selection.
typedef struct Jb2MenuPaletteRows {
    /* 0 */ u8 mRowIndices[2];
} Jb2MenuPaletteRows;

// The text of a file path the menu loads, passed to BuildFilePathWithLanguage.
typedef struct YbBgStep11NclName {
    /* 00 */ u8 mText[0x16];
} YbBgStep11NclName;

void RequestJb2MenuPaletteRowCopy(void);
void MoveJb2MenuSelection(s32 direction);
void UpdateJb2MenuRelease(void);
void UpdateJb2MenuFadeOut(void);
void StartJb2MenuClose(void);
void UpdateJb2MenuResult(void);
void UpdateJb2MenuNop(void);
void UpdateJb2MenuInput(void);
void UpdateJb2Menu(void);
void UpdateJb2MenuButtonsIn(void);
void UpdateJb2MenuFadeIn(void);
void StartJb2MenuFadeIn(void);
void LoadJb2MenuFilesAndSetBgCnt(void);
void SetupJb2Menu(void);

extern const Rect gJb2MenuRects[2];
extern const Rect gJb2MenuSelectionRects[2];
extern Jb2MenuPaletteRows gJb2MenuPaletteRows;
extern YbBgStep11NclName gYbBgStep11NclName;
extern u8 gJb2MenuSelectedIndex;
extern void *gYbBgStep11Ncl;
