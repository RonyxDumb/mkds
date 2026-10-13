/* Decompiled C draft; module arm9; ROM address 02079c0c. No matching claim. */
#include "types.h"
#include "deps/02079c0c_CharacterKartContext_SomeFn_1_1.h"

void CharacterKartContext_SomeFn_1_1(int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined2 *puVar8;
  
  uVar6 = param_1 + 0x10U & 3;
  uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar7 = (*(uint *)(uRam02079cdc & 0xfffffffc) >> (uRam02079cdc & 3) * 8 |
          *(uint *)(uRam02079cdc & 0xfffffffc) << (uRam02079cdc & 3) * -8 + 0x20) + 4;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  puVar8 = (undefined2 *)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
  uVar7 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar2 = *puVar8;
  uVar3 = puVar8[3];
  uVar4 = puVar8[1];
  ModelBlock_SomeMatFn_0(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar2);
  uVar7 = param_1 + 0x14U & 3;
  uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  ModelBlock_SomeMatFn_0(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar2);
  uVar7 = param_1 + 0x10U & 3;
  uVar6 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  ModelBlock_SetEmi(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar3);
  uVar7 = param_1 + 0x14U & 3;
  uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  ModelBlock_SetEmi(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar3);
  uVar7 = param_1 + 0x10U & 3;
  uVar6 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  ModelBlock_SomeMatFn_1(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar4);
  uVar7 = param_1 + 0x14U & 3;
  uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  ModelBlock_SomeMatFn_1(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar4);
  uVar7 = param_1 + 0x18U & 3;
  uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (uVar7 != 0) {
    uVar7 = uVar7 + 4;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    ModelBlock_SomeMatFn_0(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar2);
    uVar7 = param_1 + 0x18U & 3;
    uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    ModelBlock_SetEmi(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar3);
    uVar7 = param_1 + 0x18U & 3;
    uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    ModelBlock_SomeMatFn_1(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar4);
    return;
  }
  return;
}

