/* Decompiled C draft; module arm9; ROM address 02151830. No matching claim. */
#include "types.h"
#include "deps/02151830_StructDC_SomeFn_3_from_thumb.h"

undefined4 StructDC_SomeFn_3_from_thumb(ushort *param_1)

{
  int iVar1;
  
  iVar1 = func_0215122c(0x20,0x20,(undefined4)(uintptr_t)(param_1));
  if (iVar1 == 0) {
    return 0;
  }
  *piRam02151864 = (uint)*param_1 * 8 - iRam02151860;
  return 1;
}

