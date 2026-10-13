/* Decompiled C draft; module arm9; ROM address 0212afac. No matching claim. */
#include "types.h"
#include "deps/0212afac_GetMultiplayerErrorString_from_thumb.h"

undefined4 GetMultiplayerErrorString_from_thumb(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (*psRam0212b058 != 2) {
    uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0212b05c);
  }
  iVar2 = *(int *)*puRam0212b060;
  if (iVar2 == 4) {
    uVar1 = Bmg_GetRawStringPointer_from_thumb(uVar1,0x86);
    return uVar1;
  }
  if (iVar2 == 5) {
    uVar1 = Bmg_GetRawStringPointer_from_thumb(uVar1,0x87);
    return uVar1;
  }
  if (iVar2 == 6) {
    uVar1 = Bmg_GetRawStringPointer_from_thumb(uVar1,0x88);
    return uVar1;
  }
  if (iVar2 == 1) {
    uVar1 = Bmg_GetRawStringPointer_from_thumb(uVar1,0x83);
    return uVar1;
  }
  if (iVar2 == 2) {
    uVar1 = Bmg_GetRawStringPointer_from_thumb(uVar1,0x84);
    return uVar1;
  }
  if (iVar2 == 3) {
    uVar1 = Bmg_GetRawStringPointer_from_thumb(uVar1,0x85);
    return uVar1;
  }
  if (iVar2 == 0) {
    if (*psRam0212b058 == 2) {
      iVar2 = GetGlobal2DObject();
      uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar2 + 0x20),0);
      return uVar1;
    }
    uVar1 = Bmg_GetRawStringPointer_from_thumb(uVar1,0x82);
    return uVar1;
  }
  return 0;
}

