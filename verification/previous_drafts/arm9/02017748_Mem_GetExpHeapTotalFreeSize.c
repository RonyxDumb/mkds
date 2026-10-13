/* Decompiled C draft; module arm9; ROM address 02017748. No matching claim. */
#include "types.h"
#include "deps/02017748_Mem_GetExpHeapTotalFreeSize.h"

int Mem_GetExpHeapTotalFreeSize(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 + 0x24U & 3;
  uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar2 = 0;
  if (uVar5 == 0) {
    return iVar2;
  }
  do {
    uVar4 = uVar5 + 4 & 3;
    uVar3 = *(uint *)(uVar5 + 4 & 0xfffffffc);
    uVar1 = uVar5 + 0xc & 3;
    uVar5 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
    uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    iVar2 = iVar2 + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  } while (uVar5 != 0);
  return iVar2;
}

