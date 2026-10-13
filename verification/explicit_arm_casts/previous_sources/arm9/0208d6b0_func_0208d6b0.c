/* Decompiled C draft; module arm9; ROM address 0208d6b0. No matching claim. */
#include "types.h"
#include "deps/0208d6b0_func_0208d6b0.h"

void func_0208d6b0(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar6 = param_1 + 0x3cU & 3;
  uVar3 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  if (uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0) {
    uVar6 = 0;
    do {
      func_0208b6d0(param_1 + uVar6 * 4);
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 2);
  }
  uVar6 = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  uVar2 = uRam0208d750;
  uVar1 = (undefined2)uRam0208d754;
  do {
    uVar3 = param_1 + 0x4cU & 3;
    uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    uVar5 = func_0208b7bc(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,uVar2);
    *(undefined4 *)(param_1 + uVar6 * 4) = uVar5;
    uVar3 = param_1 + uVar6 * 4;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x72) = uVar1;
    uVar3 = param_1 + uVar6 * 4;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(undefined1 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x81) = 0x1c;
    uVar3 = param_1 + uVar6 * 4;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar6 = uVar6 + 1 & 0xffff;
    *(undefined4 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x6c) = 0x1000;
  } while (uVar6 < 2);
  *(undefined4 *)(param_1 + 0x3c) = 1;
  return;
}

