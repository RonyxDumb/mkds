#pragma once

#include "types.h"
#include "model_material_set.h" // MtxFx22
#include "Main/Graphics/font_and_player_character.h" // Nscr, Ncgr, Nclr
#include "animation_data_unpack.h" // NNSG2dCellDataBank
#include "screen_data_unpack.h" // NNSG2dBinaryFileHeader

void MaybeReadScreenBlock(Nscr **out, void *file);
void MaybeReadScreenBlock_0(Nscr **out, void *file);
void LoadNanrData(AnimBank **out, void *file);
void LocateNcer(NNSG2dCellDataBank **out, void *file);
void LoadCellBankFrom(NNSG2dCellDataBank **out, void *file);
void MaybeReadCharBlock_1(Ncgr **out, void *file);
void Gfx_ReadCharGraphicsV2(Ncgr **out, void *file);
void Gfx_ReadCharGraphicsRelative(Ncgr **out, void *file);
void Gfx_ReadCharGraphics(Ncgr **out, void *file);
void Gfx_ReadPaletteRelative(Nclr **out, void *file);
void Gfx_ReadPalette(Nclr **out, void *file);
BOOL ComputeSomeInterCharacterWidth(void);
s32 GetSomeInterCharacterWidth2(void);
BOOL GetSomeInterCharacterWidth(void);
BOOL SomeCheckLangFrench(s32 number);
void Matrix2x2RotationReciprocalScale(MtxFx22 *matrix, s32 scale, u16 angle);
void Matrix2x2ReflectedRotation(MtxFx22 *matrix, u16 angle);
void MaybeCreateRotationMatrix(MtxFx22 *matrix, u16 angle);
void Matrix2x2ReciprocalScale(MtxFx22 *matrix, s32 scale);
u16 GetSomeLapCount(void);
u16 GetCurrentPlayerRacerId(void);
