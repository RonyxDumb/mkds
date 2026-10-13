/* Decompiled C draft; module arm9_ov000; ROM address 021abc4c. No matching claim. */
#include "types.h"
#include "deps/021abc4c_FUN_021abc4c.h"

void FUN_021abc4c(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  FUN_021ac37c(param_2,param_1 + 0x14,8);
  uVar1 = *(uint *)(param_1 + 0x18) >> 3 & 0x3f;
  if (uVar1 < 0x38) {
    iVar2 = 0x38 - uVar1;
  }
  else {
    iVar2 = 0x78 - uVar1;
  }
  FUN_021abca0(param_1,DAT_021abc9c,iVar2);
  FUN_021abca0(param_1,param_2,8);
  FUN_021ac37c(param_2,param_1,0x14);
  return;
}

