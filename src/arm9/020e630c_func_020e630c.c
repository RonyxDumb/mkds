/* Decompiled C draft; module arm9; ROM address 020e630c. No matching claim. */
#include "types.h"
#include "deps/020e630c_func_020e630c.h"

void func_020e630c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = uRam020e6378;
  uVar1 = param_2 + 0xbcU & 3;
  uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xc0U & 3;
  uVar3 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xc4U & 3;
  uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  func_020ea8a8(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_2 + 0x28,param_2 + 0x1c);
  func_020ea868(*(uint *)(uRam020e637c & 0xfffffffc) >> (uRam020e637c & 3) * 8 |
                *(uint *)(uRam020e637c & 0xfffffffc) << (uRam020e637c & 3) * -8 + 0x20,param_2 + 200
                ,param_2 + 0x1c,param_4);
  return;
}

