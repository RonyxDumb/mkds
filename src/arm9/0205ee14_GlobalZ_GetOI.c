/* Decompiled C draft; module arm9; ROM address 0205ee14. No matching claim. */
#include "types.h"
#include "deps/0205ee14_GlobalZ_GetOI.h"

bool GlobalZ_GetOI(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    uVar2 = (*(uint *)(uRam0205ee70 & 0xfffffffc) >> (uRam0205ee70 & 3) * 8 |
            *(uint *)(uRam0205ee70 & 0xfffffffc) << (uRam0205ee70 & 3) * -8 + 0x20) + 0x20;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    Mem_CpuCopy8(param_1 * 0x24 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 4);
  }
  uVar2 = (*(uint *)(uRam0205ee70 & 0xfffffffc) >> (uRam0205ee70 & 3) * 8 |
          *(uint *)(uRam0205ee70 & 0xfffffffc) << (uRam0205ee70 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (int)((uint)*(byte *)(param_1 * 0x24 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) +
                              0x26) << 0x1f) < 0;
}

