/* Decompiled C draft; module arm9; ROM address 02027df8. No matching claim. */
#include "types.h"
#include "deps/02027df8_VerifySelectKartFiles_from_thumb.h"

void VerifySelectKartFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c [3];
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c[0] = 0;
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02027e60);
  Gfx_ReadCharGraphicsV2(&local_18,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02027e64);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02027e68);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02027e6c);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02027e70);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02027e74);
  MaybeReadScreenBlock_0(local_c,uVar1);
  return;
}

