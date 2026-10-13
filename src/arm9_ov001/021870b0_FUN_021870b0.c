/* Decompiled C draft; module arm9_ov001; ROM address 021870b0. No matching claim. */
#include "types.h"
#include "deps/021870b0_FUN_021870b0.h"

void FUN_021870b0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_1 != 0) && (param_3 != 0)) {
    uVar1 = FUN_0219b418(param_1,param_3);
    puVar2 = (undefined4 *)(param_2 + DAT_021870dc);
    *puVar2 = uVar1;
    func_0x0209b940(*puVar2,0x3f);
    *DAT_021870e0 = 0;
  }
  return;
}

