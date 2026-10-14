/* Decompiled C draft; module arm9; ROM address 020d13f8. No matching claim. */
#include "types.h"
#include "deps/020d13f8_IncrementStaffRollFrameCount.h"

undefined2 IncrementStaffRollFrameCount(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = (int *)(*(uint *)(uRam020d1448 & 0xfffffffc) >> (uRam020d1448 & 3) * 8 |
                  *(uint *)(uRam020d1448 & 0xfffffffc) << (uRam020d1448 & 3) * -8 + 0x20);
  uVar2 = *(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
          *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20;
  if ((int)uVar2 < 0x7fffffff) {
    *piVar3 = uVar2 + 1;
  }
  uVar1 = *(uint *)(uRam020d1448 & 0xfffffffc) >> (uRam020d1448 & 3) * 8 |
          *(uint *)(uRam020d1448 & 0xfffffffc) << (uRam020d1448 & 3) * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 0x30c) {
    RunWhenStaffRollCount();
  }
  return *puRam020d144c;
}

