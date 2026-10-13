/* Decompiled C draft; module arm9_ov000; ROM address 021aa004. No matching claim. */
#include "types.h"
#include "deps/021aa004_FUN_021aa004.h"

undefined4 FUN_021aa004(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint local_18;
  
  do {
    uVar1 = FUN_021adfc8(&local_18,param_3);
    if (local_18 == 0) {
      return 0xffffffff;
    }
    if (param_2 < local_18) {
      local_18 = param_2;
    }
    func_0x0214d1fc((ushort *)(uintptr_t)(uVar1),(uint *)(uintptr_t)(param_1),local_18);
    FUN_021adf30(local_18,param_3);
    param_1 = param_1 + local_18;
    param_2 = param_2 - local_18;
  } while (0 < (int)param_2);
  return 0;
}

