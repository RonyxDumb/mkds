/* Decompiled C draft; module arm9; ROM address 020e5634. No matching claim. */
#include "types.h"
#include "deps/020e5634_func_020e5634.h"

void func_020e5634(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = iRam020e5664;
  *(int *)(param_1 + 0x24) =
       (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 4;
  uVar1 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  *(int *)(param_1 + 0x28) = (int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + iVar2) >> 4;
  uVar1 = param_2 + 8 & 3;
  uVar3 = *(uint *)(param_2 + 8 & 0xfffffffc);
  *(int *)(param_1 + 0x2c) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  return;
}

