/* Decompiled C draft; module arm9; ROM address 0214bea4. No matching claim. */
#include "types.h"
#include "deps/0214bea4_TEQSub_Fn35Impl.h"

void TEQSub_Fn35Impl(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam0214bf00 & 0xfffffffc) >> (uRam0214bf00 & 3) * 8 |
          *(uint *)(uRam0214bf00 & 0xfffffffc) << (uRam0214bf00 & 3) * -8 + 0x20;
  if ((uVar1 != 0xffffffff) && (0x30 < param_3)) {
    MI_DmaCopy32(uVar1,param_1,param_2 + 0x6600000);
    return;
  }
  Mem_CpuCopy32(param_1,param_2 + 0x6600000,param_3);
  return;
}

