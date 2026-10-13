/* Decompiled C draft; module arm9; ROM address 02094c24. No matching claim. */
#include "types.h"
#include "deps/02094c24_func_02094c24.h"

void func_02094c24(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return;
  }
  iVar3 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar3) {
      return;
    }
    uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar3 * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    if (uVar2 == 0) break;
    *(ushort *)(uVar2 + 0xae) = (ushort)iVar3 & 1;
    *(ushort *)(uVar2 + 0xb0) = (ushort)(iVar3 / 2) & 1;
    iVar3 = iVar3 + 1;
  }
  return;
}

