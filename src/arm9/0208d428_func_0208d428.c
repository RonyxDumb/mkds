/* Decompiled C draft; module arm9; ROM address 0208d428. No matching claim. */
#include "types.h"
#include "deps/0208d428_func_0208d428.h"

void func_0208d428(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar3 = uRam0208d468;
  uVar6 = 0;
  do {
    uVar2 = param_1 + 0x50U & 3;
    uVar4 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
    uVar5 = func_0208b7bc(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20,uVar3);
    iVar1 = uVar6 * 4;
    uVar6 = uVar6 + 1 & 0xffff;
    *(undefined4 *)(param_1 + iVar1 + 0x10) = uVar5;
  } while (uVar6 < 2);
  return;
}

