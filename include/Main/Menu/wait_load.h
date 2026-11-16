#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

void ClearWaitPointer(void);

typedef struct LayoutEntryTable LayoutEntryTable;

typedef struct NNSG2dCellDataBank NNSG2dCellDataBank;

void CreateWait(void *heap, NNSG2dCellDataBank *destinationNcer, LayoutEntryTable *destinationBncl,
                u32 destinationBnclIndex, u16 paletteIndex, u32 queueSelector);
void VerifyCommonWaitFiles_from_thumb(void);

extern struct Wait *gWait;

extern char *g_str_common_wait_nce_ncgr;
extern char *g_str_common_wait_nclr;
extern char *g_str_common_wait_nce_ncer;
extern char *gWaitBnclName;
