/* Decompiled C draft; module arm9_ov003; ROM address 021bb408. No matching claim. */
#include "types.h"
#include "deps/021bb408_FUN_021bb408.h"

void FUN_021bb408(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    do {
      *(char *)(param_1 + uVar1) = (char)*param_2;
      *(char *)(param_1 + uVar1 + 1) = (char)((uint)*param_2 >> 8);
      *(char *)(param_1 + uVar1 + 2) = (char)((uint)*param_2 >> 0x10);
      *(char *)(param_1 + uVar1 + 3) = (char)((uint)*param_2 >> 0x18);
      param_2 = param_2 + 1;
      uVar1 = uVar1 + 4;
    } while (uVar1 < param_3);
  }
  return;
}

