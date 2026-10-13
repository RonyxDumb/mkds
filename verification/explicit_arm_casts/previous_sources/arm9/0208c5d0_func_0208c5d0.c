/* Decompiled C draft; module arm9; ROM address 0208c5d0. No matching claim. */
#include "types.h"
#include "deps/0208c5d0_func_0208c5d0.h"

void func_0208c5d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x3cU & 3;
  uVar1 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  if (uVar1 >> uVar4 * 8 != 0 || uVar1 << uVar4 * -8 + 0x20 != 0) {
    uVar4 = 0;
    do {
      func_0208b6d0(param_1 + uVar4 * 4);
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < 2);
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  uVar4 = param_1 + 0x38U & 3;
  uVar1 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  if (uVar1 >> uVar4 * 8 != 0 || uVar1 << uVar4 * -8 + 0x20 != 0) {
    uVar4 = param_1 + 0x74U & 3;
    uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    (*(code *)(uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20))(param_1);
  }
  uVar4 = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined2 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined2 *)(param_1 + 0x62) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  uVar1 = param_1 + 0x40U & 3;
  uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    do {
      uVar1 = param_1 + uVar4 * 4 + 0x20;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      func_0208b710(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      uVar1 = param_1 + uVar4 * 4 + 0x28;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      func_0208b710(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      iVar3 = param_1 + uVar4 * 4;
      *(undefined4 *)(iVar3 + 0x20) = 0;
      uVar4 = uVar4 + 1 & 0xffff;
      *(undefined4 *)(iVar3 + 0x28) = 0;
    } while (uVar4 < 2);
  }
  uVar4 = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined2 *)(param_1 + 0x48) = 0;
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    do {
      uVar1 = param_1 + uVar4 * 4 + 8;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      func_0208b710(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      iVar3 = uVar4 * 4;
      uVar4 = uVar4 + 1 & 0xffff;
      *(undefined4 *)(param_1 + iVar3 + 8) = 0;
    } while (uVar4 < 2);
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined2 *)(param_1 + 0x4a) = 0;
  return;
}

