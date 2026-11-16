#pragma once

#include "types.h"
#include "Main/Unknown/code_020b4000.h" // Nscr, Ncgr, Nclr
#include "g2d_NAN_load.h" // Unk02021dc8
#include "g2d_NSC_load.h" // Unk02021f9c

void g2du_getScreenData(Nscr **out, void *file);
void g2du_unpackScreenData(Nscr **out, void *file);
void g2du_unpackAnimBank(Unk02021dc8 **out, void *file);
void g2du_getCellBankData(Unk02021dc8 **out, void *file);
void g2du_unpackCellBankData(Unk02021dc8 **out, void *file);
void g2du_getCharacterDataBG(Ncgr **out, void *file);
void g2du_unpackCharacterDataBG(Ncgr **out, void *file);
void g2du_getCharacterData(Ncgr **out, void *file);
void g2du_unpackCharacterData(Ncgr **out, void *file);
void g2du_getPaletteData(Nclr **out, void *file);
void g2du_unpackPaletteData(Nclr **out, void *file);
BOOL g2du_getTextHSpace(void);
s32 GetLanguageCharSpacing(void);
BOOL RaceStartIsLanguageJa(void);
BOOL r2d_shouldUsePointsPlural(s32 number);
void lmap_rotScaleMtx22(s32 *matrix, s32 scale, s32 angle);
void lmap_rotMtx22FlipX(s32 *matrix, s32 angle);
void lmap_rotMtx22(s32 *matrix, s32 angle);
void lmap_scaleMtx22(s32 *matrix, s32 scale);
u16 GetFollowedKartLastEndedLap(void);
u16 Race_GetPlayerId(void);
