#pragma once

#include "types.h"

void menu_ta_updateMainText(void);
s32 menu_ta_modeSelectRender(void);
void menu_ta_buttonsFadeOut(void);
void menu_ta_buttonSelected(void);
void menu_ta_buttonSelecting(void);
void menu_ta_wait(void);
void menu_ta_buttonsBump(void);
void menu_ta_buttonsFadeIn(void);
void menu_ta_destroy(void);
void menu_ta_init(void *a, void *b, s32 c);
void menu_ta_setButtonHighlightInvisible(s32 a);
void menu_ta_setButtonHighlightVisible(s32 a);
void menu_ta_buttonSelectedEnd(void);
void menu_ta_buttonSelectingEnd(void);
void menu_ta_waitEnd(void);
void menu_ta_buttonsBumpEnd(void);
void menu_ta_buttonsFadeInEnd(void);
void menu_ta_initFields(void);
void menu_ta_loadFiles(void);
void LoadTimeAttackTopMenuData(void);
