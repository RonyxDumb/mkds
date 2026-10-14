/* Decompiled C draft; module arm9; ROM address 0210ef68. No matching claim. */
#include "types.h"
#include "deps/0210ef68_func_0210ef68.h"

void func_0210ef68(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_1 + 0x40U & 3;
  uVar1 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  iVar3 = 0;
  if ((int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) < 1) {
    return;
  }
  do {
    uVar2 = param_1 + iVar3 * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    Sound_SetFileFatDynamicOffsetField(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
    uVar2 = param_1 + 0x40U & 3;
    uVar1 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    iVar3 = iVar3 + 1;
  } while (iVar3 < (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20));
  return;
}

