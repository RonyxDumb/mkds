/* Decompiled C draft; module arm9_ov000; ROM address 0218e80c. No matching claim. */
#include "types.h"
#include "deps/0218e80c_FUN_0218e80c.h"

undefined4 FUN_0218e80c(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_021a8dd8(param_1,3,0);
  if (param_2 == 0) {
    uVar1 = uVar1 | 4;
  }
  else {
    uVar1 = uVar1 & 0xfffffffb;
  }
  iVar2 = FUN_021a8dd8(param_1,4,uVar1);
  if (iVar2 == 0) {
    return 1;
  }
  return 0;
}

