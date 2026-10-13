/* Decompiled C draft; module arm9_ov003; ROM address 021d2ecc. No matching claim. */
#include "types.h"
#include "deps/021d2ecc_FUN_021d2ecc.h"

void FUN_021d2ecc(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_021d285c(0x10,4);
  *puVar1 = 0;
  puVar1[1] = puVar1 + 2;
  puVar1[2] = puVar1;
  puVar1[3] = 0;
  return;
}

