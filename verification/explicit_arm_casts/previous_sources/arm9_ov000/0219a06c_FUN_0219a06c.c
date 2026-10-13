/* Decompiled C draft; module arm9_ov000; ROM address 0219a06c. No matching claim. */
#include "types.h"
#include "deps/0219a06c_FUN_0219a06c.h"

void FUN_0219a06c(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_0218dc44(*(undefined4 *)(param_1 + 0x10));
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    puVar2 = (undefined4 *)FUN_0218dbf8(*(undefined4 *)(param_1 + 0x10),iVar1);
    FUN_0219a220(*puVar2);
  }
  return;
}

