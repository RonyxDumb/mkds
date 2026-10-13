/* Decompiled C draft; module arm9; ROM address 02016cd8. No matching claim. */
#include "types.h"
#include "deps/02016cd8_func_02016cd8.h"

void func_02016cd8(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = 0;
  iVar3 = param_1;
  if (param_2 != 1) {
    do {
      uVar4 = uVar1 + 1;
      iVar2 = param_1 + uVar4 * 0x10;
      *(int *)(param_1 + uVar1 * 0x10 + 0xc) = iVar2;
      *(int *)(iVar2 + 8) = iVar3;
      uVar1 = uVar4;
      iVar3 = iVar3 + 0x10;
    } while (uVar4 < param_2 - 1U);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + param_2 * 0x10 + -4) = 0;
  return;
}

