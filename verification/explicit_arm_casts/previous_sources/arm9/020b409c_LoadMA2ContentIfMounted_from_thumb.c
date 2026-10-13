/* Decompiled C draft; module arm9; ROM address 020b409c. No matching claim. */
#include "types.h"
#include "deps/020b409c_LoadMA2ContentIfMounted_from_thumb.h"

void LoadMA2ContentIfMounted_from_thumb(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = IsMountEntryLoaded_from_thumb(1);
  if (iVar2 != 0) {
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b416c);
    NFTR_Load(uRam020b4170,uVar3);
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b4174);
    NFTR_Load(uRam020b4178,uVar3);
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b417c);
    NFTR_Load(uRam020b4180,uVar3);
    puVar1 = puRam020b4184;
    *puRam020b4184 = uRam020b4170;
    puVar1[1] = uRam020b4178;
    puVar1[2] = uRam020b4180;
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b4188);
    Gfx_ReadPalette(uRam020b418c,uVar3);
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b4190);
    Gfx_ReadPalette(uRam020b4194,uVar3);
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b4198);
    Gfx_ReadCharGraphics(uRam020b419c,uVar3);
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b41a0);
    LoadCellBankFrom(uRam020b41a4,uVar3);
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b41a8);
    *puRam020b41ac = uVar3;
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b41b0);
    Gfx_ReadPalette(uRam020b41b4,uVar3);
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b41b8);
    Gfx_ReadPalette(uRam020b41bc,uVar3);
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b41c0);
    Gfx_ReadCharGraphics(uRam020b41c4,uVar3);
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b41c8);
    LoadCellBankFrom(uRam020b41cc,uVar3);
    uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020b41d0);
    puRam020b41ac[1] = uVar3;
  }
  return;
}

