/* Decompiled C draft; module arm9_ov000; ROM address 0218d238. No matching claim. */
#include "types.h"
#include "deps/0218d238_FUN_0218d238.h"

void FUN_0218d238(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_0218dbf8(*(undefined4 *)(param_1 + 4));
  uVar2 = *puVar1;
  (**(code **)(param_1 + DAT_0218d274))(param_1,2,uVar2,*(undefined4 *)(param_1 + DAT_0218d270));
  FUN_0218da5c(*(undefined4 *)(param_1 + 4),param_2);
  FUN_0218d278(param_1,uVar2);
  return;
}

