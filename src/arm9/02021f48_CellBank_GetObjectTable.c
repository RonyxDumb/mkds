/* Decompiled C draft; module arm9; ROM address 02021f48. No matching claim. */
#include "types.h"
#include "deps/02021f48_CellBank_GetObjectTable.h"

int CellBank_GetObjectTable(ushort *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_1[1] & 1) == 0) {
    uVar1 = (uint)(param_1 + 2) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + (uint)*param_1 * 8;
  }
  else {
    uVar1 = (uint)(param_1 + 2) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + (uint)*param_1 * 0x10;
  }
  return iVar3;
}

