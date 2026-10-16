/* Decompiled C draft; module arm9; ROM address 02025f90. No matching claim. */
#include "types.h"
#include "deps/02025f90_VerifySelectCharacterFiles_from_thumb.h"

void VerifySelectCharacterFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8 [2];
  
  local_10 = 0;
  local_c = 0;
  local_8[0] = 0;
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02026030);
  Gfx_ReadCharGraphics(&local_10,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02026034);
  LoadCellBankFrom(local_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02026038);
  Gfx_ReadPalette(&local_c,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202603c);
  Gfx_ReadCharGraphics(&local_10,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02026040);
  LoadCellBankFrom(local_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02026044);
  Gfx_ReadPalette(&local_c,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02026048);
  Gfx_ReadCharGraphics(&local_10,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202604c);
  LoadCellBankFrom(local_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02026050);
  Gfx_ReadCharGraphics(&local_10,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02026054);
  LoadCellBankFrom(local_8,uVar1);
  return;
}

