/* Decompiled C draft; module arm9_ov000; ROM address 0218e77c. No matching claim. */
#include "types.h"
#include "deps/0218e77c_FUN_0218e77c.h"

undefined4 FUN_0218e77c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  undefined4 local_8 [2];
  
  local_8[0] = 4;
  iVar1 = FUN_0218e3c4(param_1,DAT_0218e7a4,DAT_0218e7a8,&local_c,local_8);
  uVar2 = 0xffffffff;
  if (iVar1 != -1) {
    uVar2 = local_c;
  }
  return uVar2;
}

