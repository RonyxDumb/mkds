#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

typedef struct LayoutEntryTable LayoutEntryTable;

typedef struct NNSG2dCellDataBank NNSG2dCellDataBank;

void QueueSelectCupNameM(u32 nameIndex, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout, u32 destIndex,
                         u32 queueSelector);
void CreateSelectCupNameM(void *heap);
void LoadSelectCupNameMData(void);
void QueueCupMark(u32 cupMarkIndex, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout, u32 destIndex,
                  u16 paletteSlot, s32 queueSelector);
void ClearCupMarkPointer(void);

void ClearSelectCupNameMPointer(void);

void CreateCommonCupMark(void *heap);
void CreateCupMark(void *heap);
void LoadCommonCupMarkData(void);
void LoadCupMarkData(void);

extern char *gCommonCupMarkNcerName;
// Objects whose layout isn't known yet.
extern const u16 gCupMarkBnclIndices[8];
extern char *gCommonCupMarkBnclName;
extern char *gCupMarkNcgrName;
extern char *gCupMarkNclrName;
extern char *gCommonCupMarkNcgrName;
extern char *gCupMarkNcerName;
extern const u16 gSelectCupNameMBnclIndices[8];
extern char *gCommonCupMarkNclrName;
extern char *gCupMarkBnclName;
extern struct SelectCupNameM *gSelectCupNameM;
extern struct CupMark *gCupMark;
