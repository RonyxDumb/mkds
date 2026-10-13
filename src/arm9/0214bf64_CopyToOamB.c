/* Decompiled C draft; module arm9; ROM address 0214bf64. No matching claim. */
#include "types.h"
#include "deps/0214bf64_CopyToOamB.h"

void CopyToOamB(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam0214bfc4 & 0xfffffffc) >> (uRam0214bfc4 & 3) * 8 |
          *(uint *)(uRam0214bfc4 & 0xfffffffc) << (uRam0214bfc4 & 3) * -8 + 0x20;
  if ((uVar1 != 0xffffffff) && (0x30 < param_3)) {
    MI_DmaCopy32(uVar1,param_1,param_2 + iRam0214bfc8);
    return;
  }
  Mem_CpuCopy32((undefined4 *)(uintptr_t)(param_1),(undefined4 *)(uintptr_t)(param_2 + iRam0214bfc8),param_3);
  return;
}

