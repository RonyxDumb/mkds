#pragma once

#include "types.h"

void WriteTimeAttackTopMenuBg0Offset(void);
s32 AdvanceTimeAttackTopMenu(void);
void AdvanceTimeAttackTopMenuState5(void);
void AdvanceTimeAttackTopMenuState4(void);
void AdvanceTimeAttackTopMenuState3(void);
void AdvanceTimeAttackTopMenuState2(void);
void AdvanceTimeAttackTopMenuState1(void);
void AdvanceTimeAttackTopMenuState0(void);
void ReleaseTimeAttackTopMenu(void);
void InitTimeAttackTopMenu(void *parentHeap, void *mainOam, s32 subOam);
void HideTimeAttackTopMenuHighlight(s32 a);
void ShowTimeAttackTopMenuHighlight(s32 a);
void RequestTimeAttackTopMenuState5(void);
void RequestTimeAttackTopMenuState4(void);
void RequestTimeAttackTopMenuState3(void);
void RequestTimeAttackTopMenuState2(void);
void RequestTimeAttackTopMenuState1(void);
void RequestTimeAttackTopMenuState0(void);
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
