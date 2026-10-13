/* Decompiled C draft; module arm9_ov000; ROM address 0218e644. No matching claim. */
#include "types.h"
#include "deps/0218e644_FUN_0218e644.h"

undefined4 FUN_0218e644(undefined4 param_1)

{
  int iVar1;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  iVar1 = FUN_0218e68c(param_1,0,local_8,0);
  if (iVar1 == 1) {
    return local_8[0];
  }
  return 0;
}

