/* Decompiled C draft; module arm9_ov000; ROM address 02194840. No matching claim. */
#include "types.h"
#include "deps/02194840_FUN_02194840.h"

undefined4 FUN_02194840(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_1;
  local_c = param_2;
  local_8 = param_3;
  iVar1 = FUN_0218dd8c((int *)(uintptr_t)(*(undefined4 *)(*param_1 + DAT_0219486c)),DAT_02194870,(undefined4)(uintptr_t)(&local_10));
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}

