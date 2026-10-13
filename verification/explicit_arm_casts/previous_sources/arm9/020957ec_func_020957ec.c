/* Decompiled C draft; module arm9; ROM address 020957ec. No matching claim. */
#include "types.h"
#include "deps/020957ec_func_020957ec.h"

void func_020957ec(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return;
  }
  iVar4 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar4) {
      return;
    }
    uVar3 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar4 * 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    if (uVar3 == 0) break;
    uVar1 = uVar3 + 0x9c & 3;
    uVar2 = *(uint *)(uVar3 + 0x9c & 0xfffffffc);
    VecFx32_AddScale1(0x320000,uVar3 + 0x40,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,
                      uVar3 + 0xa4);
    iVar4 = iVar4 + 1;
  }
  return;
}

