/* Decompiled C draft; module arm9; ROM address 02068a64. No matching claim. */
#include "types.h"
#include "deps/02068a64_DriverContext_UpdateCharacterAnimation.h"

void DriverContext_UpdateCharacterAnimation(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  uint uVar5;
  
  uVar5 = param_1 + 0x7cU & 3;
  uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((uVar5 & 0x10) == 0) {
    uVar3 = 0;
    if ((param_2 == 1) || ((uVar5 & 0x20000) != 0)) {
      uVar3 = 1;
    }
    uVar5 = param_1 + 0x590U & 3;
    uVar4 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    CharacterKartContext_SetNsbtpAnimationProgress
              (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,uVar3);
    return;
  }
  uVar5 = param_1 + 0x590U & 3;
  uVar4 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar7 = 0;
  uVar5 = uVar4 + 8 & 3;
  uVar1 = *(uint *)(uVar4 + 8 & 0xfffffffc);
  uVar1 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 + 0x38 & 3;
  uVar2 = *(uint *)(uVar4 + 0x38 & 0xfffffffc);
  uVar6 = (uint)*(ushort *)(uVar1 + 0x1a);
  bVar8 = true;
  if (uVar2 >> uVar5 * 8 != 0 || uVar2 << uVar5 * -8 + 0x20 != 0) {
    if (uVar6 != 0) {
      Animation_SetLoop(uVar1,uVar6,1);
    }
    *(undefined4 *)(uVar4 + 0x38) = 0;
  }
  if (param_2 == 1) {
    uVar7 = 1;
    param_2 = uVar7;
  }
  else {
    uVar5 = param_1 + 0x7cU & 3;
    uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    if ((uVar5 & 0x10000) == 0) {
      if ((uVar5 & 0x20000) != 0) {
        bVar8 = uVar6 != param_2;
        param_2 = 3;
        uVar7 = 1;
      }
    }
    else {
      bVar8 = uVar6 != param_2;
      param_2 = 2;
    }
  }
  if (bVar8) {
    uVar5 = param_1 + 0x590U & 3;
    uVar4 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    CharacterKartContext_SetNsbcaAnimAt
              (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,param_2,param_3);
  }
  uVar5 = param_1 + 0x590U & 3;
  uVar4 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  CharacterKartContext_SetNsbtpAnimationProgress
            (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,uVar7);
  return;
}

