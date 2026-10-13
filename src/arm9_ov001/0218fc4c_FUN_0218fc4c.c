/* Decompiled C draft; module arm9_ov001; ROM address 0218fc4c. No matching claim. */
#include "types.h"
#include "deps/0218fc4c_FUN_0218fc4c.h"

/* WARNING: Removing unreachable block (ram,0x0218fc8a) */

void FUN_0218fc4c(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (*(int *)(*DAT_0218fcc0 + 8) == 4) {
    iVar2 = func_0x020a126c();
  }
  else {
    iVar2 = 0;
  }
  if ((iVar2 == 0) && (iVar2 = FUN_021871f8(param_2,1), iVar2 != 0)) {
    if (*(int *)(*DAT_0218fcc0 + 8) == 4) {
      sVar1 = FUN_02181b54();
      uVar3 = FUN_02181b68(sVar1 + 2);
    }
    else {
      uVar3 = 0;
    }
    uVar4 = FUN_02188220(uVar3);
    if (uVar4 < 2) {
      FUN_02190468(param_2);
    }
    else {
      FUN_0219081c(param_2);
    }
  }
  FUN_021864ac(param_1,param_2);
  return;
}

