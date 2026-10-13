/* Decompiled C draft; module arm9; ROM address 02058fb4. No matching claim. */
#include "types.h"
#include "deps/02058fb4_StructZE_E7Fn_18_2_from_thumb.h"

void StructZE_E7Fn_18_2_from_thumb(void)

{
  int iVar1;
  
  iVar1 = func_0205905c();
  if (iVar1 == 1) {
    iVar1 = *piRam02058fd8 + iRam02058fdc;
    *(undefined2 *)(iVar1 + 0x10) = 0x13;
    *(undefined2 *)(iVar1 + 0x12) = 1;
  }
  return;
}

