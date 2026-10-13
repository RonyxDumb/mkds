/* Decompiled C draft; module arm9; ROM address 020f9054. No matching claim. */
#include "types.h"
#include "deps/020f9054_func_020f9054.h"

void func_020f9054(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  
  pcVar3 = pcRam020f90b8;
  if (param_4 == 0) {
    uVar2 = param_2 * 0xa8 +
            (*(uint *)(uRam020f90b4 & 0xfffffffc) >> (uRam020f90b4 & 3) * 8 |
            *(uint *)(uRam020f90b4 & 0xfffffffc) << (uRam020f90b4 & 3) * -8 + 0x20) + 0x48;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  }
  func_020f9a14(param_1);
  (*pcVar3)(param_3,param_1,0);
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffbfffff;
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x10000000;
  return;
}

