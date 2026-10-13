/* Decompiled C draft; module arm9; ROM address 0205928c. No matching claim. */
#include "types.h"
#include "deps/0205928c_StructZE_E7Fn_20_2_from_thumb.h"

void StructZE_E7Fn_20_2_from_thumb(void)

{
  int iVar1;
  
  if (*(int *)(*piRam020592a4 + 0x10) == 0) {
    iVar1 = *piRam020592a4 + iRam020592a8;
    *(undefined2 *)(iVar1 + 0x10) = 0xf;
    *(undefined2 *)(iVar1 + 0x12) = 1;
  }
  return;
}

