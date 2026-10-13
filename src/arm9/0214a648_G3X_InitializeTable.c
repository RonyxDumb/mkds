/* Decompiled C draft; module arm9; ROM address 0214a648. No matching claim. */
#include "types.h"
#include "deps/0214a648_G3X_InitializeTable.h"

void G3X_InitializeTable(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(uRam0214a6f0 & 0xfffffffc) >> (uRam0214a6f0 & 3) * 8 |
          *(uint *)(uRam0214a6f0 & 0xfffffffc) << (uRam0214a6f0 & 3) * -8 + 0x20;
  if (uVar2 == 0xffffffff) {
    MIi_CpuClear32(0,(undefined4 *)(uintptr_t)(uRam0214a6f4),0x10);
    MIi_CpuClear32(0,(undefined4 *)(uintptr_t)(uRam0214a6f8),0x60);
  }
  else {
    MI_DmaFill32Async(uVar2,uRam0214a6f4,0,0x10,0,0);
    Mem_DmaFill32(*(uint *)(uRam0214a6f0 & 0xfffffffc) >> (uRam0214a6f0 & 3) * 8 |
                  *(uint *)(uRam0214a6f0 & 0xfffffffc) << (uRam0214a6f0 & 3) * -8 + 0x20,
                  uRam0214a6f8,0,0x60);
  }
  puVar1 = puRam0214a6fc;
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    *puVar1 = 0;
  } while (iVar3 < 0x20);
  return;
}

