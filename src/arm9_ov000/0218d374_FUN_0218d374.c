/* Decompiled C draft; module arm9_ov000; ROM address 0218d374. No matching claim. */
#include "types.h"
#include "deps/0218d374_FUN_0218d374.h"

void FUN_0218d374(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0218d3c8;
  switch(param_4) {
  case 0:
    uVar1 = DAT_0218d3bc;
    break;
  case 1:
    uVar1 = DAT_0218d3c0;
    break;
  case 2:
    uVar1 = DAT_0218d3c4;
    break;
  case 3:
  }
  *(undefined4 *)(param_1 + DAT_0218d3cc) = param_3;
  *(undefined4 *)(param_1 + DAT_0218d3d0) = param_2;
  *DAT_0218d3d4 = param_1;
  FUN_0218da04((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 4)),uVar1);
  return;
}

