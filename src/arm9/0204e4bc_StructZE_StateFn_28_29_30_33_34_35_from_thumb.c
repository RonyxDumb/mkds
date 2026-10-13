/* Decompiled C draft; module arm9; ROM address 0204e4bc. No matching claim. */
#include "types.h"
#include "deps/0204e4bc_StructZE_StateFn_28_29_30_33_34_35_from_thumb.h"

void StructZE_StateFn_28_29_30_33_34_35_from_thumb(void)

{
  int *piVar1;
  
  piVar1 = piRam0204e4d0;
  *(undefined4 *)(*piRam0204e4d0 + 0xc) = 0x1f;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
                    /* WARNING: Could not recover jumptable at 0x0204e4cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0204e4d4)();
  return;
}

