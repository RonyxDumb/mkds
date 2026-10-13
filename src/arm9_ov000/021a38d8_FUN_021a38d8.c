/* Decompiled C draft; module arm9_ov000; ROM address 021a38d8. No matching claim. */
#include "types.h"
#include "deps/021a38d8_FUN_021a38d8.h"

undefined4 FUN_021a38d8(void)

{
  int *piVar1;
  
  piVar1 = (int *)*DAT_021a390c;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  if (*piVar1 != 0) {
    *(undefined2 *)(piVar1 + 1) = 3;
    FUN_021a3810();
    return 1;
  }
  return 0;
}

