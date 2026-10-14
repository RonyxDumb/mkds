/* Decompiled C draft; module arm9; ROM address 0214c418. No matching claim. */
#include "types.h"
#include "deps/0214c418_SomeDmaCopy_0.h"

void SomeDmaCopy_0(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam0214c488 & 0xfffffffc) >> (uRam0214c488 & 3) * 8 |
          *(uint *)(uRam0214c488 & 0xfffffffc) << (uRam0214c488 & 3) * -8 + 0x20;
  param_2 = (*(uint *)(uRam0214c484 & 0xfffffffc) >> (uRam0214c484 & 3) * 8 |
            *(uint *)(uRam0214c484 & 0xfffffffc) << (uRam0214c484 & 3) * -8 + 0x20) + param_2;
  if (uVar1 != 0xffffffff) {
    func_0214c990(uVar1,param_1,param_2,param_3,0,0);
    return;
  }
  Mem_CpuCopy32(param_1,param_2,param_3,param_3);
  return;
}

