/* Decompiled C draft; module arm9; ROM address 0200850c. No matching claim. */
#include "types.h"
#include "deps/0200850c_func_0200850c.h"

void func_0200850c(uint *param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  if (param_2 < uRam02008568) {
    param_2 = uRam02008568;
  }
  if (uRam0200856c < param_3) {
    param_3 = uRam0200856c;
  }
  uVar1 = *param_1;
  if (param_2 < uVar1) {
    param_2 = uVar1;
  }
  if (uVar1 + param_1[3] < param_3) {
    param_3 = uVar1 + param_1[3];
  }
  if (param_2 < param_3) {
    if (param_4 != 0) {
      Mem_CpuFill8((uint *)(uintptr_t)(param_1[2] + param_2),0,param_3 - param_2);
      return;
    }
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_1[1] + param_2),(uint *)(uintptr_t)(param_1[2] + param_2),param_3 - param_2);
  }
  return;
}

