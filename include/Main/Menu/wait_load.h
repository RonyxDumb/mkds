#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

void ClearWaitPointer(void);

typedef struct LayoutEntryTable LayoutEntryTable;

typedef struct NNSG2dCellDataBank NNSG2dCellDataBank;

void CreateWait(void *heap, NNSG2dCellDataBank *destinationNcer, LayoutEntryTable *destinationBncl,
                u32 destinationBnclIndex, u16 paletteIndex, u32 queueSelector);
void LoadWaitData(void);

extern struct Wait *gWait;

extern char *gWaitNcgrName;
extern char *gWaitNclrName;
extern char *gWaitNcerName;
extern char *gWaitBnclName;
