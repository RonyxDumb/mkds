/* Decompiled C draft; module arm9; ROM address 0202b8d8. No matching claim. */
#include "types.h"
#include "deps/0202b8d8_VerifySelectMenuFiles_from_thumb.h"

void VerifySelectMenuFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [12];
  
  if (*psRam0202b9d0 == 2) {
    uVar1 = find_buf_fn_from_thumb(uRam0202b9d4);
    Gfx_ReadCharGraphicsV2(auStack_18,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam0202b9d8);
    Gfx_ReadCharGraphics(auStack_18,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam0202b9dc);
    LoadCellBankFrom(auStack_10,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam0202b9e0);
    Gfx_ReadPalette(auStack_14,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam0202b9e4);
    Gfx_ReadPalette(auStack_14,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam0202b9e8);
    MaybeReadScreenBlock_0(auStack_c,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam0202b9ec);
    MaybeReadScreenBlock_0(auStack_c,uVar1);
    return;
  }
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202b9f0);
  Gfx_ReadCharGraphicsV2(auStack_18,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202b9f4);
  Gfx_ReadCharGraphics(auStack_18,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202b9f8);
  Gfx_ReadCharGraphics(auStack_18,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202b9fc);
  LoadCellBankFrom(auStack_10,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202ba00);
  LoadCellBankFrom(auStack_10,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202ba04);
  Gfx_ReadPalette(auStack_14,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202ba08);
  Gfx_ReadPalette(auStack_14,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202ba0c);
  MaybeReadScreenBlock_0(auStack_c,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202ba10);
  MaybeReadScreenBlock_0(auStack_c,uVar1);
  return;
}

