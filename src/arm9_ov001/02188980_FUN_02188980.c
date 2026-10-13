/* Decompiled C draft; module arm9_ov001; ROM address 02188980. No matching claim. */
#include "types.h"
#include "deps/02188980_FUN_02188980.h"

void FUN_02188980(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)(param_1 + DAT_02188994);
    uVar1 = param_2[1];
    *puVar2 = *param_2;
    puVar2[1] = uVar1;
    puVar2[2] = param_2[2];
  }
  return;
}

