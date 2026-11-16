#pragma once

#include "types.h"
#include "Main/Menu/kart_icon_row.h"
#include "Main/Menu/menu_screens_work.h"

typedef struct NNSG2dCellDataBank NNSG2dCellDataBank;

typedef struct LayoutEntryTable LayoutEntryTable;

void QueueKartIcon(s32 iconIndex, NNSG2dCellDataBank *destinationNcer, LayoutEntryTable *destinationBncl,
                   u32 destinationBnclIndex, u16 paletteIndex, s32 queueSelector);

void ClearKartIconPointer(void);

void CreateCommonKartIcon(void *heap);

void CreateKartIcon(void *heap);

void VerifyKartIconFiles_from_thumb(void);
void LoadKartIconData(void);

extern const char *gKartIconNcgrName;
extern const char *gKartIconNcerName;
extern const char *gKartIconNclrNames[3];
extern const char *gKartIconBnclName;
extern const char *gCommonKartIconNcgrName;
extern const char *gCommonKartIconNcerName;
extern const char *gCommonKartIconNclrNames[3];
extern const char *gCommonKartIconBnclName;
extern const KartIconRow gKartIconRows[37];
extern struct KartIcon *gKartIcon;
