/* Decompiled C draft; module arm9_ov000; ROM address 0218d1a0. No matching claim. */
#include "types.h"
#include "deps/0218d1a0_FUN_0218d1a0.h"

void FUN_0218d1a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = FUN_0218dc44(*(undefined4 *)(param_1 + 4));
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)FUN_0218dbf8(*(undefined4 *)(param_1 + 4),iVar3);
      FUN_0218d278(param_1,*puVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_0218d8b4(*(undefined4 *)(param_1 + 4));
  FUN_0218d1dc(param_1);
  return;
}

