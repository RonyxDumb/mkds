/* Decompiled C draft; module arm9_ov003; ROM address 021d1be4. No matching claim. */
#include "types.h"
#include "deps/021d1be4_FUN_021d1be4.h"

undefined4 FUN_021d1be4(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_021d19e0(param_1,*(undefined2 *)(*(int *)(DAT_021d1c14 + param_1 * 4) + param_2 * 8));
  uVar2 = FUN_021d1974(uVar1,0);
  FUN_021d1c3c(param_1,param_2,uVar2);
  return uVar1;
}

