#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"

void WriteSelectCupMBgOffsets(void);
s32 AdvanceSelectCupM(void);
void AdvanceSelectCupMScrollUp(void);
void AdvanceSelectCupMScrollDown(void);
void ReleaseSelectCupM(void);
void InitSelectCupM(void *parentHeap, void *mainOamList, void *subOamList);
void StartSelectCupMScrollUp(void);
void StartSelectCupMScrollDown(void);
void InitSelectCupMCellsAndRequestCupPicture(void);
void LocateAndQueueSelectCupM(void);

extern const u32 gSelectCupMCourseIds[8][4];
extern char *gSelectCupMBNclrName3;
extern const u16 gSelectCupMLabelWidths[4];
extern char *gSelectCupMNcgrName3;
extern const u16 gSelectCupMTrophyCells[4];
extern const u16 gSelectCupMCourseCells[4];
extern const u16 gSelectCupMCourseLabels[4];
extern const u32 gSelectCupMCupIndices[8];
extern const u16 gSelectCupMCupMessageIndices[8][4];
extern char *gSelectCupMBNcgrName3;
extern char *gSelectCupMBnclName3;
extern char *gSelectCupMNcerName3;
extern char *gSelectCupMNscrName3;
extern const u16 gSelectCupMCellSlots[8];
extern const u16 gSelectCupMLabelHeights[4];
extern char *gSelectCupMBnllName3;
extern char *gSelectCupMONclrName3;
extern struct SelectCupM *gSelectCupM;
