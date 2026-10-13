/* Decompiled C draft; module arm9; ROM address 020592d4. No matching claim. */
#include "types.h"
#include "deps/020592d4_StructZE_E7Fn_17_2_from_thumb.h"

void StructZE_E7Fn_17_2_from_thumb(void)

{
  int iVar1;
  
  iVar1 = func_02058dc0(uRam020592f8);
  if (iVar1 == 1) {
    iVar1 = *piRam020592fc + iRam02059300;
    *(undefined2 *)(iVar1 + 0x10) = 0x14;
    *(undefined2 *)(iVar1 + 0x12) = 1;
  }
  return;
}

