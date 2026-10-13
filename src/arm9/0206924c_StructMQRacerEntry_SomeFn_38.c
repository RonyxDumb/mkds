/* Decompiled C draft; module arm9; ROM address 0206924c. No matching claim. */
#include "types.h"
#include "deps/0206924c_StructMQRacerEntry_SomeFn_38.h"

void StructMQRacerEntry_SomeFn_38(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0x400) != 0) {
    return;
  }
  iVar2 = IsRacerFinishedRace(*(undefined2 *)(param_1 + 0x74));
  if (iVar2 != 0) {
    return;
  }
  uVar4 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar4 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  if ((uVar4 & 0x60) != 0) {
    return;
  }
  uVar1 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam02069384) == 0) {
    if ((uVar4 & 0x2000) == 0) {
      *(undefined2 *)(param_1 + 0x554) = 0;
      uVar4 = param_1 + 0x4cU & 3;
      uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20 | 0x8000000;
      uVar4 = param_1 + 0x4cU & 3;
      uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0xfffdffff;
      uVar4 = param_1 + 0x4cU & 3;
      uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0x2000) != 0) {
        StructMQRacerEntry_SomeFn_2(param_1);
      }
      uVar4 = param_1 + 0x590U & 3;
      uVar1 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
      CharacterKartContext_SomeFn_1_0
                (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20,0,uRam02069388,0);
      uVar4 = param_1 + 0x7cU & 3;
      uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0x10) != 0) {
        StructMQRacerEntry_SomeFn_7(param_1,1,0);
        uVar4 = param_1 + 0x590U & 3;
        uVar1 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
        CharacterKartContext_SetNsbtpAnimationProgress
                  (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20,1);
      }
      uVar4 = param_1 + 0x48U & 3;
      uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0x840) == 0) {
        uVar4 = param_1 + 0x3ccU & 3;
        uVar1 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
        StructMQRacerEntry_SomeFn_5(param_1,uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20,0);
      }
      func_021038f0(*(undefined2 *)(param_1 + 0x74),param_2);
      uVar4 = param_1 + 0x7cU & 3;
      uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0x200) != 0) {
        uVar4 = param_1 + 0x514U & 3;
        uVar1 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
        uVar3 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
        uVar4 = uVar3 + 0x2c;
        uVar1 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        *(uint *)(uVar3 + 0x2c) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) ^ 0x80000;
      }
      return;
    }
    return;
  }
  return;
}

