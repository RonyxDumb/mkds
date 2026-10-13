/* Decompiled C draft; module arm9_ov001; ROM address 0218f3ec. No matching claim. */
#include "types.h"
#include "deps/0218f3ec_FUN_0218f3ec.h"

undefined4 FUN_0218f3ec(int param_1)

{
  int iVar1;
  undefined1 auStack_18 [16];
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218f448 + 0x62));
  if ((*(uint *)(iVar1 + 0x48) & DAT_0218f44c) == 0) {
    func_0x02147fd8(*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f450),iVar1 + 0x68,
                    iVar1 + 0x80,auStack_18);
    FUN_02188998(param_1,auStack_18);
    FUN_02188d8c(param_1,auStack_18);
  }
  FUN_0218f6d8(param_1);
  func_0x02061860();
  return 0;
}

