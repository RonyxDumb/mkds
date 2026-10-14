/* Decompiled C draft; module arm9; ROM address 0207f9cc. No matching claim. */
#include "types.h"
#include "deps/0207f9cc_func_0207f9cc.h"

void func_0207f9cc(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar3;
  
  uVar2 = param_1 + 8U & 3;
  uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x18;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  puVar3 = (undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar4 = puVar3[1];
  uVar5 = puVar3[2];
  *(undefined4 *)(param_1 + 0x44) = *puVar3;
  *(undefined4 *)(param_1 + 0x48) = uVar4;
  *(undefined4 *)(param_1 + 0x4c) = uVar5;
  uVar4 = puRam0207fa70[1];
  uVar5 = puRam0207fa70[2];
  *(undefined4 *)(param_1 + 0x60) = *puRam0207fa70;
  *(undefined4 *)(param_1 + 100) = uVar4;
  *(undefined4 *)(param_1 + 0x68) = uVar5;
  *(undefined2 *)(param_1 + 0x6c) = 0;
  *(undefined2 *)(param_1 + 0x6e) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)(param_1 + 0x7a) = 0;
  *(undefined2 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x84) = param_2;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined2 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0xfffff000;
  *(undefined2 *)(param_1 + 0xc0) = 0;
  *(undefined2 *)(param_1 + 0xc2) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  func_0207e7f0(param_1);
  return;
}

