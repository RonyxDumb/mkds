#pragma once

#include "types.h"
#include "03/types_021d299c.h"

typedef struct Rect Rect;

typedef struct Jb2MenuPaletteRows {
    /* 0 */ u8 mRowIndices[2];
} Jb2MenuPaletteRows;

typedef struct YbBgStep11NclName {
    /* 00 */ u8 mText[0x16];
} YbBgStep11NclName;

extern Rect gJb2MenuRects[];
extern u16 gJb2MenuSelectionLeft[];
extern u16 gJb2MenuSelectionTop[];
extern u16 gJb2MenuSelectionRight[];
extern u16 gJb2MenuSelectionBottom[];
extern Jb2MenuPaletteRows gJb2MenuPaletteRows;
extern YbBgStep11NclName gYbBgStep11NclName;
extern u8 gJbBgStep1NcgName2[];
extern u8 gJbBgStep1NclName2[];
extern u8 gJb2MenuNscName[];
extern u8 gJb2MenuSelectedIndex;
extern void *gYbBgStep11Ncl;

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
