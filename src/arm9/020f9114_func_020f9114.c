/* Decompiled C draft; module arm9; ROM address 020f9114. No matching claim. */
#include "types.h"
#include "deps/020f9114_func_020f9114.h"

void func_020f9114(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f915c & 0xfffffffc) >> (uRam020f915c & 3) * 8 |
          *(uint *)(uRam020f915c & 0xfffffffc) << (uRam020f915c & 3) * -8 + 0x20) + 0xa0;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  func_02109038(param_1,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,param_1 + 0x50);
  func_0210cf9c(param_1,1);
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x400000;
  return;
}

