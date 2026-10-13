/* Decompiled C draft; module arm9_ov000; ROM address 021ab6d4. No matching claim. */
#include "types.h"
#include "deps/021ab6d4_FUN_021ab6d4.h"

void FUN_021ab6d4(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  FUN_021abc14(param_2,param_1 + 0x10,8);
  uVar1 = *(uint *)(param_1 + 0x10) >> 3 & 0x3f;
  if (uVar1 < 0x38) {
    iVar2 = 0x38 - uVar1;
  }
  else {
    iVar2 = 0x78 - uVar1;
  }
  FUN_021ab728(param_1,DAT_021ab724,iVar2);
  FUN_021ab728(param_1,param_2,8);
  FUN_021abc14(param_2,param_1,0x10);
  return;
}

