/* Decompiled C draft; module arm9; ROM address 02047a28. No matching claim. */
#include "types.h"
#include "deps/02047a28_FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb.h"

void FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(*piRam02047ae8 + iRam02047aec) != 0) {
    iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047af0 + 0x44),param_1);
  }
  if ((iVar1 == 0) && (*(int *)(*piRam02047ae8 + iRam02047af4) != 0)) {
    iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047af0 + 0x40),param_1);
  }
  if ((iVar1 == 0) && (*(int *)(*piRam02047ae8 + iRam02047af8) != 0)) {
    iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047af0 + 0x3c),param_1);
  }
  if ((iVar1 == 0) && (*(int *)(*piRam02047ae8 + iRam02047afc) != 0)) {
    iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047af0 + 0x38),param_1);
  }
  if ((iVar1 == 0) && (*(int *)(*piRam02047ae8 + iRam02047b00) != 0)) {
    iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047af0 + 0x4c),param_1);
  }
  if ((iVar1 == 0) && (*(int *)(*piRam02047ae8 + iRam02047b04) != 0)) {
    iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047af0 + 8),param_1);
  }
  if ((iVar1 == 0) && (*(int *)(*piRam02047ae8 + 0xd8) != 0)) {
    FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047af0 + 4),param_1);
  }
  return;
}

