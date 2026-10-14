/* Decompiled C draft; module arm9; ROM address 020592ac. No matching claim. */
#include "types.h"
#include "deps/020592ac_StructZE_E7Fn_20_1_from_thumb.h"

void StructZE_E7Fn_20_1_from_thumb(void)

{
  int iVar1;
  
  if ((int *)*piRam020592d0 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)*piRam020592d0;
  }
  if (iVar1 == 1) {
    func_020518c8(1);
  }
  return;
}

