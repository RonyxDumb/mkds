/* Decompiled C draft; module arm9; ROM address 02125c2c. No matching claim. */
#include "types.h"
#include "deps/02125c2c_PrepareNavigationContextFiles_from_thumb.h"

void PrepareNavigationContextFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined1 auStack_8 [8];
  
  if (*psRam02125d50 == 2) {
    uVar1 = find_buf_fn_from_thumb(uRam02125d54);
    Gfx_ReadCharGraphicsV2(auStack_8,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam02125d58);
    MaybeReadScreenBlock_0(auStack_8,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam02125d5c);
    Gfx_ReadPalette(auStack_8,uVar1);
    return;
  }
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d60);
  Gfx_ReadCharGraphicsV2(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d64);
  Gfx_ReadCharGraphicsV2(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d68);
  MaybeReadScreenBlock_0(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d6c);
  MaybeReadScreenBlock_0(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d70);
  MaybeReadScreenBlock_0(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d74);
  MaybeReadScreenBlock_0(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d78);
  MaybeReadScreenBlock_0(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d7c);
  MaybeReadScreenBlock_0(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d80);
  MaybeReadScreenBlock_0(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d84);
  Gfx_ReadPalette(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d88);
  Gfx_ReadCharGraphicsV2(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d8c);
  MaybeReadScreenBlock_0(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d90);
  Gfx_ReadPalette(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d94);
  Gfx_ReadCharGraphicsV2(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d98);
  MaybeReadScreenBlock_0(auStack_8,uVar1);
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02125d9c);
  Gfx_ReadPalette(auStack_8,uVar1);
  return;
}

