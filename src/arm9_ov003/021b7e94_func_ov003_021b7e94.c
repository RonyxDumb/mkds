/* Decompiled C draft; module arm9_ov003; ROM address 021b7e94. No matching claim. */
#include "types.h"
#include "deps/021b7e94_func_ov003_021b7e94.h"

void func_ov003_021b7e94(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = func_0x02133068(param_2,2);
  func_ov003_021b7d90(param_3,param_1 + iVar1,iVar1);
  func_ov003_021b7d90(param_3 + iVar1,param_1,iVar1);
  func_ov003_021b7d90(param_1,param_3,param_2);
  return;
}

