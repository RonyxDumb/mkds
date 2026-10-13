/* Decompiled C draft; module arm9; ROM address 020e1dc0. No matching claim. */
#include "types.h"
#include "deps/020e1dc0_func_020e1dc0.h"

void func_020e1dc0(uint param_1,undefined4 param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = *(ushort *)(param_1 + 4);
  iVar4 = 0;
  if (uVar2 == 0) {
    return;
  }
  do {
    uVar3 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar4 * 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    iVar4 = iVar4 + 1;
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x140) = param_2;
  } while (iVar4 < (int)(uint)uVar2);
  return;
}

