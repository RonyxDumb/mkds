/* Decompiled C draft; module arm9_ov000; ROM address 0218eb44. No matching claim. */
#include "types.h"
#include "deps/0218eb44_FUN_0218eb44.h"

int FUN_0218eb44(int *param_1)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (iVar1 = *param_1, iVar1 == 0)) {
    return 2;
  }
  if (*(int *)(iVar1 + DAT_0218eb90) != 0) {
    return 0;
  }
  if (*(int *)(iVar1 + DAT_0218eb94) == 4) {
    FUN_02196590(param_1,DAT_0218eb98);
    return 2;
  }
  iVar1 = FUN_0218f960();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}

