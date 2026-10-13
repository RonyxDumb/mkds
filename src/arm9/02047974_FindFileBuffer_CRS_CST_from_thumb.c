/* Decompiled C draft; module arm9; ROM address 02047974. No matching claim. */
#include "types.h"
#include "deps/02047974_FindFileBuffer_CRS_CST_from_thumb.h"

void FindFileBuffer_CRS_CST_from_thumb(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047998 + 0xc),(char *)(uintptr_t)(param_1));
  if (iVar1 == 0) {
    FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047998 + 0x34),(char *)(uintptr_t)(param_1));
  }
  return;
}

