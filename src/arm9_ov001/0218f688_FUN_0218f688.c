/* Decompiled C draft; module arm9_ov001; ROM address 0218f688. No matching claim. */
#include "types.h"
#include "deps/0218f688_FUN_0218f688.h"

undefined4 FUN_0218f688(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218f6d0 + 0x62));
  if ((*(uint *)(iVar1 + 0x48) & DAT_0218f6d4) == 0) {
    FUN_02188998(param_1,(undefined4 *)(uintptr_t)(iVar1 + 0x80));
    FUN_02188d8c(param_1,(undefined4 *)(uintptr_t)(iVar1 + 0x80));
  }
  FUN_0218f6d8(param_1);
  return 0;
}

