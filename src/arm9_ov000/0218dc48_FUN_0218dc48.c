/* Decompiled C draft; module arm9_ov000; ROM address 0218dc48. No matching claim. */
#include "types.h"
#include "deps/0218dc48_FUN_0218dc48.h"

void FUN_0218dc48(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    func_0x0213442c(DAT_0218dc8c,DAT_0218dc90,0,0x69);
  }
  iVar1 = 0;
  if (0 < *param_1) {
    do {
      FUN_0218dd74(param_1,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *param_1);
  }
  FUN_021a3668(param_1[5]);
  FUN_021a3668((undefined4)(uintptr_t)(param_1));
  return;
}

