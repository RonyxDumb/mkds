/* Decompiled C draft; module arm9_ov003; ROM address 021bb3bc. No matching claim. */
#include "types.h"
#include "deps/021bb3bc_FUN_021bb3bc.h"

void FUN_021bb3bc(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    do {
      *(undefined1 *)(param_1 + uVar1) = *(undefined1 *)(param_2 + uVar1);
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_3);
  }
  return;
}

