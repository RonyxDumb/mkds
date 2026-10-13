/* Decompiled C draft; module arm9; ROM address 02047b08. No matching claim. */
#include "types.h"
#include "deps/02047b08_FindFileBuffer_MAR_EFT_from_thumb.h"

void FindFileBuffer_MAR_EFT_from_thumb(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FormatGetPathMountBuffer_from_thumb(*puRam02047b2c,(char *)(uintptr_t)(param_1));
  if (iVar1 == 0) {
    FormatGetPathMountBuffer_from_thumb(puRam02047b2c[0x12],(char *)(uintptr_t)(param_1));
  }
  return;
}

