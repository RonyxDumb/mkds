/* Decompiled C draft; module arm9_ov001; ROM address 0218f3ac. No matching claim. */
#include "types.h"
#include "deps/0218f3ac_FUN_0218f3ac.h"

undefined4 FUN_0218f3ac(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218f3e4 + 0x62));
  if ((*(uint *)(iVar1 + 0x48) & DAT_0218f3e8) == 0) {
    FUN_02188998(param_1,iVar1 + 0x80);
  }
  FUN_0218f6d8(param_1);
  return 0;
}

