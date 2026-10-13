/* Decompiled C draft; module arm9; ROM address 0201dc24. No matching claim. */
#include "types.h"
#include "deps/0201dc24_func_0201dc24.h"

void func_0201dc24(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar4;
  uint uVar3;
  
  uVar3 = param_2 + 0x10U & 3;
  uVar2 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  iVar1 = 0;
  if (*(byte *)(uVar3 + 8) == 0) {
    return;
  }
  iVar4 = iVar1;
  do {
    if (param_3 < (int)(iVar4 + (uint)*(byte *)(uVar3 + 9))) {
      *(undefined1 *)(param_1 + 0x2c) = *(undefined1 *)(uVar3 + iVar1);
      return;
    }
    iVar1 = iVar1 + 1;
    iVar4 = iVar4 + (uint)*(byte *)(uVar3 + 9);
  } while (iVar1 < (int)(uint)*(byte *)(uVar3 + 8));
  return;
}

