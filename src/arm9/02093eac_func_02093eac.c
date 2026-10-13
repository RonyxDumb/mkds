/* Decompiled C draft; module arm9; ROM address 02093eac. No matching claim. */
#include "types.h"
#include "deps/02093eac_func_02093eac.h"

void func_02093eac(uint param_1)

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
    *(undefined4 *)(uVar2 + 0xa0) = 0;
    iVar3 = iVar3 + 1;
  }
  return;
}

