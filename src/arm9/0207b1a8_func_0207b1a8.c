/* Decompiled C draft; module arm9; ROM address 0207b1a8. No matching claim. */
#include "types.h"
#include "deps/0207b1a8_func_0207b1a8.h"

void func_0207b1a8(int param_1)

{
  uint uVar1;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar2;
  uint uVar4;
  
  uVar5 = param_1 + 0x590U & 3;
  uVar1 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar2 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
  uVar5 = uVar2 + 0x10 & 3;
  uVar1 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
  uVar6 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
  uVar5 = uVar2 + 0xc & 3;
  uVar1 = *(uint *)(uVar2 + 0xc & 0xfffffffc);
  uVar5 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
  uVar1 = uVar6 + 4 & 3;
  uVar3 = *(uint *)(uVar6 + 4 & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  ModelBlock_SomeMatFn_4(uVar4,0);
  uVar1 = uVar6 + 0x68 & 3;
  uVar3 = *(uint *)(uVar6 + 0x68 & 0xfffffffc);
  ModelBlock_SomeTexPltFn_10(uVar4,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if ((uVar5 != 0) &&
     (uVar1 = uVar2 + 0xac & 3, uVar3 = *(uint *)(uVar2 + 0xac & 0xfffffffc),
     uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0)) {
    uVar5 = uVar5 + 0x1c;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar1 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    uVar5 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    StructML_SomeFn_3(uVar6,uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20);
    *(undefined4 *)(uVar2 + 0xac) = 0;
  }
  ModelBlock_SomeMatFn(uVar4,0);
  uVar5 = uVar2 + 0x14 & 3;
  uVar1 = *(uint *)(uVar2 + 0x14 & 0xfffffffc);
  uVar1 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
  uVar5 = uVar1 + 4;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  ModelBlock_SomeMatFn_4(uVar3,0);
  uVar1 = uVar1 + 0x68;
  uVar5 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  ModelBlock_SomeTexPltFn_10(uVar3,uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20);
  ModelBlock_SomeMatFn(uVar3,0);
  uVar5 = uVar2 + 0x18 & 3;
  uVar1 = *(uint *)(uVar2 + 0x18 & 0xfffffffc);
  uVar5 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
  if (uVar5 != 0) {
    uVar1 = uVar5 + 4 & 3;
    uVar3 = *(uint *)(uVar5 + 4 & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    ModelBlock_SomeMatFn_4(uVar3,0);
    uVar1 = uVar5 + 0x68 & 3;
    uVar5 = *(uint *)(uVar5 + 0x68 & 0xfffffffc);
    ModelBlock_SomeTexPltFn_10(uVar3,uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
    ModelBlock_SomeMatFn(uVar3,0);
  }
  *(undefined4 *)(uVar2 + 100) = 0;
  return;
}

