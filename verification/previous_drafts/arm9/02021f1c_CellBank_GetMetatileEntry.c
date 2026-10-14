/* Decompiled C draft; module arm9; ROM address 02021f1c. No matching claim. */
#include "types.h"
#include "deps/02021f1c_CellBank_GetMetatileEntry.h"

int CellBank_GetMetatileEntry(ushort *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 < *param_1) {
    if ((param_1[1] & 1) == 0) {
      uVar1 = (uint)(param_1 + 2) & 3;
      uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_2 * 8;
    }
    else {
      uVar1 = (uint)(param_1 + 2) & 3;
      uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_2 * 0x10;
    }
    return iVar3;
  }
  return 0;
}

