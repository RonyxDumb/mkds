/* Decompiled C draft; module arm9; ROM address 02059008. No matching claim. */
#include "types.h"
#include "deps/02059008_StructZE_E7Fn_21_2_from_thumb.h"

void StructZE_E7Fn_21_2_from_thumb(void)

{
  int iVar1;
  
  iVar1 = func_0205910c();
  if (iVar1 == 1) {
    iVar1 = *piRam0205902c + iRam02059030;
    *(undefined2 *)(iVar1 + 0x10) = 0x14;
    *(undefined2 *)(iVar1 + 0x12) = 1;
  }
  return;
}

