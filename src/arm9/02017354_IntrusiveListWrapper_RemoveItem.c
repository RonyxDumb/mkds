/* Decompiled C draft; module arm9; ROM address 02017354. No matching claim. */
#include "types.h"
#include "deps/02017354_IntrusiveListWrapper_RemoveItem.h"

void IntrusiveListWrapper_RemoveItem(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar3;
  
  uVar4 = (uint)*(ushort *)((int)param_1 + 10);
  uVar3 = param_2 + uVar4 & 3;
  uVar2 = *(uint *)(param_2 + uVar4 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  puVar5 = (undefined4 *)(param_2 + uVar4);
  if (uVar3 == 0) {
    uVar3 = (uint)(puVar5 + 1) & 3;
    uVar2 = *(uint *)((uint)(puVar5 + 1) & 0xfffffffc);
    *param_1 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  }
  else {
    uVar2 = (uint)(puVar5 + 1) & 3;
    uVar1 = *(uint *)((uint)(puVar5 + 1) & 0xfffffffc);
    *(uint *)(uVar3 + uVar4 + 4) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  uVar3 = (uint)(puVar5 + 1) & 3;
  uVar2 = *(uint *)((uint)(puVar5 + 1) & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    param_1[1] = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                 *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
  }
  else {
    *(uint *)(uVar3 + *(ushort *)((int)param_1 + 10)) =
         *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
         *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
  }
  *puVar5 = 0;
  puVar5[1] = 0;
  *(short *)(param_1 + 2) = (short)param_1[2] + -1;
  return;
}

