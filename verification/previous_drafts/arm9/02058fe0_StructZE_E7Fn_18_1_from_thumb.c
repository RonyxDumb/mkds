/* Decompiled C draft; module arm9; ROM address 02058fe0. No matching claim. */
#include "types.h"
#include "deps/02058fe0_StructZE_E7Fn_18_1_from_thumb.h"

void StructZE_E7Fn_18_1_from_thumb(void)

{
  int iVar1;
  
  if ((int *)*piRam02059004 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)*piRam02059004;
  }
  if (iVar1 == 1) {
    func_020518c8(0);
  }
  return;
}

