/* Decompiled C draft; module arm9; ROM address 0208d358. No matching claim. */
#include "types.h"
#include "deps/0208d358_func_0208d358.h"

void func_0208d358(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  uint uVar3;
  
  uVar5 = 0;
  do {
    iVar4 = param_1 + uVar5 * 4;
    uVar2 = iVar4 + 0x10;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar2 = uVar3 + 0x24;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar3 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffd;
    uVar2 = iVar4 + 0x18;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar5 = uVar5 + 1 & 0xffff;
    uVar2 = uVar3 + 0x24;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar3 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffd;
  } while (uVar5 < 2);
  return;
}

