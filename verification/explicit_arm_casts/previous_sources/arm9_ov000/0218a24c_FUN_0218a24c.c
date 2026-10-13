/* Decompiled C draft; module arm9_ov000; ROM address 0218a24c. No matching claim. */
#include "types.h"
#include "deps/0218a24c_FUN_0218a24c.h"

undefined4 FUN_0218a24c(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = FUN_02188584(1);
  uVar2 = FUN_02188584(4);
  FUN_0218a064(uVar1,param_1,uVar2);
  *DAT_0218a290 = 4;
  iVar3 = FUN_021a8c94(uVar2);
  if (iVar3 != 0) {
    FUN_02188508(2);
    return 0x11;
  }
  return 0xc;
}

