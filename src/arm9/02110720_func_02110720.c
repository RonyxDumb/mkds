/* Decompiled C draft; module arm9; ROM address 02110720. No matching claim. */
#include "types.h"
#include "deps/02110720_func_02110720.h"

void func_02110720(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = iRam02110750;
  uVar5 = iRam0211074c + 0x70U & 3;
  uVar4 = *(uint *)(iRam0211074c + 0x70U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  *(undefined4 *)(iRam0211074c + uVar5 * 4) = param_1;
  iVar1 = iRam0211074c;
  iVar3 = uVar5 + 1;
  *(undefined4 *)(iVar2 + uVar5 * 4) = param_2;
  if (iVar3 == 0xe) {
    iVar3 = 0;
  }
  *(int *)(iVar1 + 0x70) = iVar3;
  return;
}

