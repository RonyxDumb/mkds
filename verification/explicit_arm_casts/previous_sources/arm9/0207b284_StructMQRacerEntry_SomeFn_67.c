/* Decompiled C draft; module arm9; ROM address 0207b284. No matching claim. */
#include "types.h"
#include "deps/0207b284_StructMQRacerEntry_SomeFn_67.h"

void StructMQRacerEntry_SomeFn_67(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar4;
  
  uVar5 = param_1 + 0x590U & 3;
  uVar3 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 + 0x10 & 3;
  uVar3 = *(uint *)(uVar4 + 0x10 & 0xfffffffc);
  uVar6 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 + 0xc & 3;
  uVar3 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = uVar6 + 4;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  ModelBlock_SomeMatFn_4(uVar5,2);
  ModelBlock_SomeTexPltFn_9(uVar5);
  if ((uVar3 != 0) &&
     (uVar2 = uVar4 + 0xac & 3, uVar1 = *(uint *)(uVar4 + 0xac & 0xfffffffc),
     uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0)) {
    uVar3 = uVar3 + 0x1c;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    StructML_SomeFn_2(uVar6,uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    *(undefined4 *)(uVar4 + 0xac) = 1;
  }
  ModelBlock_SomeMatFn(uVar5,2);
  uVar5 = uVar4 + 0x14 & 3;
  uVar3 = *(uint *)(uVar4 + 0x14 & 0xfffffffc);
  uVar5 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 4;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  ModelBlock_SomeMatFn_4(uVar5,2);
  ModelBlock_SomeTexPltFn_9(uVar5);
  ModelBlock_SomeMatFn(uVar5,2);
  uVar5 = uVar4 + 0x18 & 3;
  uVar3 = *(uint *)(uVar4 + 0x18 & 0xfffffffc);
  uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  if (uVar5 != 0) {
    uVar5 = uVar5 + 4;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    ModelBlock_SomeMatFn_4(uVar5,2);
    ModelBlock_SomeTexPltFn_9(uVar5);
    ModelBlock_SomeMatFn(uVar5,2);
  }
  *(undefined4 *)(uVar4 + 100) = 1;
  return;
}

