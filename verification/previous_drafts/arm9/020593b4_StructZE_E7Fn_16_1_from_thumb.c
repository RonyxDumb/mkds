/* Decompiled C draft; module arm9; ROM address 020593b4. No matching claim. */
#include "types.h"
#include "deps/020593b4_StructZE_E7Fn_16_1_from_thumb.h"

void StructZE_E7Fn_16_1_from_thumb(void)

{
  int iVar1;
  
  if ((int *)*piRam020593d8 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)*piRam020593d8;
  }
  if (iVar1 == 1) {
    func_020518c8(0);
  }
  return;
}

