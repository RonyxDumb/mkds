/* Decompiled C draft; module arm9; ROM address 02021e8c. No matching claim. */
#include "types.h"
#include "deps/02021e8c_CellBank_InitializeLoad.h"

void CellBank_InitializeLoad(ushort *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  
  uVar3 = (uint)(param_1 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  *(uint *)(param_1 + 2) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + (int)param_1;
  iVar1 = CellBank_GetObjectTable();
  uVar6 = 0;
  if (*param_1 != 0) {
    do {
      iVar2 = CellBank_GetMetatileEntry(param_1,uVar6);
      uVar3 = iVar2 + 4U & 3;
      uVar4 = *(uint *)(iVar2 + 4U & 0xfffffffc);
      uVar6 = uVar6 + 1;
      *(uint *)(iVar2 + 4) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + iVar1;
    } while (uVar6 < *param_1);
  }
  uVar3 = (uint)(param_1 + 6) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    *(uint *)(param_1 + 6) = uVar3 + (int)param_1;
    uVar3 = (uint)(param_1 + 6) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    uVar3 = uVar5 + 4 & 3;
    uVar4 = *(uint *)(uVar5 + 4 & 0xfffffffc);
    *(uint *)(uVar5 + 4) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + uVar5;
    *(uint *)(param_1 + 6) = uVar5;
    return;
  }
  return;
}

