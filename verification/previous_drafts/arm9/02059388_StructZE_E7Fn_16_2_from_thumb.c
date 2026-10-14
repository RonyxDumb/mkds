/* Decompiled C draft; module arm9; ROM address 02059388. No matching claim. */
#include "types.h"
#include "deps/02059388_StructZE_E7Fn_16_2_from_thumb.h"

void StructZE_E7Fn_16_2_from_thumb(void)

{
  int iVar1;
  
  iVar1 = func_020593dc();
  if (iVar1 == 1) {
    iVar1 = *piRam020593ac + iRam020593b0;
    *(undefined2 *)(iVar1 + 0x10) = 0x11;
    *(undefined2 *)(iVar1 + 0x12) = 1;
  }
  return;
}

