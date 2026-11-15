#pragma once

#include "types.h"

void WriteTimeAttackTopMenuBg0Offset(void);
s32 AdvanceTimeAttackTopMenu(void);
void AdvanceTimeAttackTopMenuSlideOut(void);
void AdvanceTimeAttackTopMenuPress(void);
void AdvanceTimeAttackTopMenuInput(void);
void AdvanceTimeAttackTopMenuWaitSelectReturn(void);
void AdvanceTimeAttackTopMenuSettle(void);
void AdvanceTimeAttackTopMenuSlideIn(void);
void ReleaseTimeAttackTopMenu(void);
void InitTimeAttackTopMenu(void *parentHeap, void *mainOam, void *subOam);
void HideTimeAttackTopMenuHighlight(s32 index);
void ShowTimeAttackTopMenuHighlight(s32 index);
void RequestTimeAttackTopMenuSlideOut(void);
void RequestTimeAttackTopMenuPress(void);
void RequestTimeAttackTopMenuInput(void);
void RequestTimeAttackTopMenuWaitSelectReturn(void);
void RequestTimeAttackTopMenuSettle(void);
void RequestTimeAttackTopMenuSlideIn(void);
void LocateAndQueueTimeAttackTopMenu(void);
void LoadTimeAttackTopMenuData(void);

extern char *gTimeAttackTopMenuSNcgrName;
extern char *gTimeAttackTopMenuSNcerName;
extern const u16 gTimeAttackTopMenuPaletteCellIndices[3];
extern char *gTimeAttackTopMenuMNscrName;
extern char *gTimeAttackTopMenuSBnblName;
extern const u16 gTimeAttackTopMenuOffsetIndices[3];
extern char *gTimeAttackTopMenuMBNcgrName;
extern char *gTimeAttackTopMenuMBNclrName;
extern const u16 gTimeAttackTopMenuVisibleTableIndices[3];
extern char *gTimeAttackTopMenuSONclrName;
extern char *gTimeAttackTopMenuSBnclName;
extern const u16 gTimeAttackTopMenuXluCellIndices[3];
