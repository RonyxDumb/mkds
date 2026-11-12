#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"

void ClearWaitPointer(void);

typedef struct LayoutEntryTable LayoutEntryTable;

typedef struct Unk02021dc8 Unk02021dc8;

void CreateWait(void *heap, Unk02021dc8 *destinationNcer, LayoutEntryTable *destinationBncl, u32 destinationBnclIndex,
                u16 paletteIndex, u32 queueSelector);
void LoadWaitData(void);

extern struct Wait *gWait;

extern char *gWaitNcgrName;
extern char *gWaitNclrName;
extern char *gWaitNcerName;
extern char *gWaitBnclName;
