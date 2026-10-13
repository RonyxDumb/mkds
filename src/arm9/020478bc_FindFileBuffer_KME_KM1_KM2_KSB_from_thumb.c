/* Decompiled C draft; module arm9; ROM address 020478bc. No matching claim. */
#include "types.h"
#include "deps/020478bc_FindFileBuffer_KME_KM1_KM2_KSB_from_thumb.h"

int FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = GetCurrentSceneId();
  if (((iVar1 == 1) || (iVar1 == 3)) || (iVar1 == 0xc)) {
    iVar2 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam0204793c + 0x28),(char *)(uintptr_t)(param_1));
  }
  else {
    if (*(int *)(*piRam02047940 + iRam02047944) != 0) {
      iVar2 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam0204793c + 0x18),(char *)(uintptr_t)(param_1));
    }
    if ((iVar2 == 0) && (*(int *)(*piRam02047940 + iRam02047948) != 0)) {
      iVar2 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam0204793c + 0x1c),(char *)(uintptr_t)(param_1));
    }
    if ((iVar2 == 0) && (*(int *)(*piRam02047940 + iRam0204794c) != 0)) {
      iVar2 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam0204793c + 0x20),(char *)(uintptr_t)(param_1));
    }
  }
  return iVar2;
}

