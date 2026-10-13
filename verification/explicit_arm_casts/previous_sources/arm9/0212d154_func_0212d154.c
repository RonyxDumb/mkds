/* Decompiled C draft; module arm9; ROM address 0212d154. No matching claim. */
#include "types.h"
#include "deps/0212d154_func_0212d154.h"

undefined4 func_0212d154(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  func_0212d10c();
  if (*(uint *)(uRam0212d210 & 0xfffffffc) >> (uRam0212d210 & 3) * 8 == 0 &&
      *(uint *)(uRam0212d210 & 0xfffffffc) << (uRam0212d210 & 3) * -8 + 0x20 == 0) {
    MIi_CpuClear32(0,param_1,param_2);
    Arm_FlushRange(param_1,param_2);
    uVar1 = func_0212ccd4(1,param_1,param_1 + (param_2 >> 1),param_2 >> 1);
    return uVar1;
  }
  return 0;
}

