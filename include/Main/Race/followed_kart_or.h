#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx22
#include "Main/Graphics/font_and_player_character.h" // Nscr, Ncgr, Nclr
#include "g2d_NAN_load.h" // NNSG2dCellDataBank
#include "g2d_NSC_load.h" // NNSG2dBinaryFileHeader

void LocateNscr(Nscr **out, void *file);
void LoadNscrData(Nscr **out, void *file);
void LoadNanrData(AnimBank **out, void *file);
void LocateNcer(NNSG2dCellDataBank **out, void *file);
void LoadNcerData(NNSG2dCellDataBank **out, void *file);
void LocateNcgr(Ncgr **out, void *file);
void LoadNcgrData(Ncgr **out, void *file);
void LocateNcgr2(Ncgr **out, void *file);
void LoadNcgrData2(Ncgr **out, void *file);
void LocateNclr(Nclr **out, void *file);
void LoadNclrData(Nclr **out, void *file);
BOOL IsLanguageJa(void);
s32 GetLanguageCharSpacing(void);
BOOL RaceStartIsLanguageJa(void);
BOOL IsPointsLabelPlural(s32 number);
void Matrix2x2RotationReciprocalScale(MtxFx22 *matrix, s32 scale, s32 angle);
void Matrix2x2ReflectedRotation(MtxFx22 *matrix, s32 angle);
void Matrix2x2Rotation(MtxFx22 *matrix, s32 angle);
void Matrix2x2ReciprocalScale(MtxFx22 *matrix, s32 scale);
u16 GetFollowedKartLastEndedLap(void);
u16 GetFollowedKartOrEntryIndex(void);
