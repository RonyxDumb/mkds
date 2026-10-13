/* Decompiled C draft; module arm9_ov000; ROM address 02198914. No matching claim. */
#include "types.h"
#include "deps/02198914_FUN_02198914.h"

void FUN_02198914(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  if (*(int *)(param_1 + 0xc) == 5) {
    local_c = param_2;
    local_8 = param_3;
    uStack_4 = param_4;
    FUN_0219a61c(&local_c,&local_8);
    iVar1 = FUN_0218dc44(*(undefined4 *)(param_1 + 0x98));
    if (iVar1 != 0) {
      FUN_02198098(param_1,0,local_c,local_8,param_4);
      return;
    }
    FUN_02198ad8(param_1,local_c,local_8,param_4);
  }
  return;
}

