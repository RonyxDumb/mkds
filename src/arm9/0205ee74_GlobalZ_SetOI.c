/* Decompiled C draft; module arm9; ROM address 0205ee74. No matching claim. */
#include "types.h"
#include "deps/0205ee74_GlobalZ_SetOI.h"

void GlobalZ_SetOI(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0205eeac & 0xfffffffc) >> (uRam0205eeac & 3) * 8 |
          *(uint *)(uRam0205eeac & 0xfffffffc) << (uRam0205eeac & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  Mem_CpuCopy8(param_2,param_1 * 0x24 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 4);
  return;
}

