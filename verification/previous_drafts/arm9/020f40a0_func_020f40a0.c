/* Decompiled C draft; module arm9; ROM address 020f40a0. No matching claim. */
#include "types.h"
#include "deps/020f40a0_func_020f40a0.h"

void func_020f40a0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1 * 0x1c +
          (*(uint *)(uRam020f40d4 & 0xfffffffc) >> (uRam020f40d4 & 3) * 8 |
          *(uint *)(uRam020f40d4 & 0xfffffffc) << (uRam020f40d4 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar2 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0x44 +
          (*(uint *)(uRam020f40d8 & 0xfffffffc) >> (uRam020f40d8 & 3) * 8 |
          *(uint *)(uRam020f40d8 & 0xfffffffc) << (uRam020f40d8 & 3) * -8 + 0x20);
  uVar3 = iVar2 + 0x1c;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(iVar2 + 0x1c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - param_2;
  return;
}

