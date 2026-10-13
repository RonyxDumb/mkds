/* Decompiled C draft; module arm9; ROM address 0207b13c. No matching claim. */
#include "types.h"
#include "deps/0207b13c_StructMQRacerEntry_SomeFn_36.h"

void StructMQRacerEntry_SomeFn_36(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0x590U & 3;
  uVar2 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 + 100 & 3;
  uVar2 = *(uint *)(uVar3 + 100 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = uVar3 + 0x10 & 3;
    uVar2 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
    uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 4;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    ModelBlock_SomeMatFn_4(uVar1,2);
    ModelBlock_SomeMatFn(uVar1,3);
    uVar1 = uVar3 + 0x14 & 3;
    uVar2 = *(uint *)(uVar3 + 0x14 & 0xfffffffc);
    uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 4;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    ModelBlock_SomeMatFn_4(uVar1,2);
    ModelBlock_SomeMatFn(uVar1,3);
    return;
  }
  return;
}

