/* Decompiled C draft; module arm9_ov000; ROM address 0218efa8. No matching claim. */
#include "types.h"
#include "deps/0218efa8_FUN_0218efa8.h"

undefined4 FUN_0218efa8(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (iVar2 = *param_1, iVar2 == 0)) {
    return 2;
  }
  if (*(int *)(iVar2 + DAT_0218efec) != 0) {
    return 0;
  }
  if (*(int *)(iVar2 + DAT_0218eff0) == 4) {
    FUN_02196590(param_1,DAT_0218eff4);
    return 2;
  }
  uVar1 = FUN_021923b4();
  return uVar1;
}

