/* Decompiled C draft; module arm9_ov001; ROM address 0218f244. No matching claim. */
#include "types.h"
#include "deps/0218f244_FUN_0218f244.h"

undefined4 FUN_0218f244(int param_1)

{
  int iVar1;
  undefined1 auStack_18 [16];
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218f2a0 + 0x62));
  if ((*(uint *)(iVar1 + 0x48) & DAT_0218f2a4) == 0) {
    func_0x02147fd8(-*(int *)(*(int *)(param_1 + 0xa0) + 0xe8),iVar1 + 0x68,iVar1 + 0x80,auStack_18)
    ;
    FUN_02188998(param_1,auStack_18);
    FUN_02188d8c(param_1,auStack_18);
  }
  FUN_0218f6d8(param_1);
  return 0;
}

