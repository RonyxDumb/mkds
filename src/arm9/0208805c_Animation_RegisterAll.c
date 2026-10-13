/* Decompiled C draft; module arm9; ROM address 0208805c. No matching claim. */
#include "types.h"
#include "deps/0208805c_Animation_RegisterAll.h"

void Animation_RegisterAll(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  
  puVar1 = DAT_020881ac;
  uVar9 = 0;
  uVar8 = 0;
  if (*(short *)(param_1 + 0x18) == 0) {
    return;
  }
  do {
    uVar4 = param_1 + 0x28U & 3;
    uVar2 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    switch(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) {
    case 0:
      uVar9 = Anim_NSBCA_LoadGetJNT0Block(param_2);
      uVar9 = JNT0_LoadJointByIdx(uVar9,uVar8);
      break;
    case 1:
      uVar9 = MaybeLoadBTA0Format(param_2);
      uVar9 = BTA0_LoadRawData(uVar9,uVar8);
      break;
    case 2:
      uVar9 = MaybeLoadBTP0Format(param_2);
      uVar9 = BTP0_LoadRawData(uVar9,uVar8);
      break;
    case 3:
      uVar9 = MaybeLoadBVA0Format(param_2);
      uVar9 = BVA0_LoadRawData(uVar9,uVar8);
      break;
    case 4:
      uVar9 = MaybeLoadBMA0Format(param_2);
      uVar9 = BMA0_LoadRawData(uVar9,uVar8);
    }
    if (param_3 == 0) {
      uVar4 = param_1 + 0x1cU & 3;
      uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      uVar2 = param_1 + 0x20U & 3;
      uVar6 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
      uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + uVar8 * 4;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
      *(undefined4 *)((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) + uVar8 * 4) = 0;
    }
    else {
      uVar4 = param_1 + 0x14U & 3;
      uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
      uVar4 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 4;
      uVar2 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar5 = Anim_GetNeededBlockSize((char *)(uintptr_t)(uVar9),uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
      *puVar1 = uVar5;
      uVar4 = Mem_AllocateHeap(param_3);
      uVar2 = param_1 + 0x1cU & 3;
      uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      *(uint *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + uVar8 * 4) = uVar4;
      uVar2 = param_1 + 0x20U & 3;
      uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
      *(undefined4 *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + uVar8 * 4) = 0;
    }
    uVar2 = param_1 + 0x14U & 3;
    uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar2 = uVar3 + 4;
    uVar6 = uVar2 & 3;
    uVar7 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = uVar3 + 0x68;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    MaybeCreateAnimationBlock
              ((undefined4 *)(uintptr_t)(uVar4),(char *)(uintptr_t)(uVar9),uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,
               uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < *(ushort *)(param_1 + 0x18));
  return;
}

