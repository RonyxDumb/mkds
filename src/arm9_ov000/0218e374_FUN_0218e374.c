/* Decompiled C draft; module arm9_ov000; ROM address 0218e374. No matching claim. */
#include "types.h"
#include "deps/0218e374_FUN_0218e374.h"

undefined4 FUN_0218e374(undefined4 param_1)

{
  int iVar1;
  undefined4 local_8 [2];
  
  iVar1 = FUN_021a8c1c(param_1,local_8);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  return local_8[0];
}

