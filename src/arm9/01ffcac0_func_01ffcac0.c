/* Decompiled C draft; module arm9; ROM address 01ffcac0. No matching claim. */
#include "types.h"
#include "deps/01ffcac0_func_01ffcac0.h"

void func_01ffcac0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined2 *)(param_1 + 0x2b0) = 0;
  uVar2 = uRam01ffcb54;
  uVar1 = param_1 + 0x44U & 3;
  uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam01ffcb50;
  uVar1 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uVar2;
  *(undefined2 *)(param_1 + 0x2b4) = *(undefined2 *)(param_1 + 0x2b2);
  *(undefined2 *)(param_1 + 0x2b2) = 0;
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x1e4) = *(undefined4 *)(param_1 + 0x1d8);
  *(undefined4 *)(param_1 + 0x1e8) = *(undefined4 *)(param_1 + 0x1dc);
  *(undefined4 *)(param_1 + 0x1ec) = *(undefined4 *)(param_1 + 0x1e0);
  *(undefined4 *)(param_1 + 0x2f0) = *(undefined4 *)(param_1 + 0x2e4);
  *(undefined4 *)(param_1 + 0x2f4) = *(undefined4 *)(param_1 + 0x2e8);
  *(undefined4 *)(param_1 + 0x2f8) = *(undefined4 *)(param_1 + 0x2ec);
  *(undefined4 *)(param_1 + 0x2e4) = *(undefined4 *)(param_1 + 0x2d8);
  *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_1 + 0x2dc);
  *(undefined4 *)(param_1 + 0x2ec) = *(undefined4 *)(param_1 + 0x2e0);
  uVar1 = param_1 + 0x220U & 3;
  uVar2 = *(uint *)(param_1 + 0x220U & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))(param_1);
  return;
}

