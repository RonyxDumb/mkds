/* Decompiled C draft; module arm9; ROM address 02069134. No matching claim. */
#include "types.h"
#include "deps/02069134_StructMQRacerEntry_SomeFn_40.h"

void StructMQRacerEntry_SomeFn_40(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar7;
  uint uVar6;
  
  uVar6 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  iVar7 = param_1 + iRam0206923c;
  if ((uVar6 & 0x40) == 0) {
    if (((*(short *)(iVar7 + 0x1c) == 400) && ((uVar6 & 0x20000) == 0)) &&
       ((uVar6 & 0x8000000) != 0)) {
      *(undefined2 *)(iVar7 + 0x1c) = 400;
      uVar6 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20 | 0x20000;
      uVar2 = func_0207a134();
      uVar3 = func_0207a11c();
      uVar4 = func_0207a104();
      uVar6 = param_1 + 0x590U & 3;
      uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
      CharacterKartContext_SomeFn_1_0
                (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,uVar2,uVar3,uVar4);
    }
    uVar6 = param_1 + 0x4cU & 3;
    uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    uVar2 = uRam02069240;
    if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x20000) != 0) {
      uVar2 = 0x52;
    }
    uVar6 = param_1 + 0x590U & 3;
    uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    func_02079ce0(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,uVar2);
  }
  iVar1 = iRam02069244;
  *(short *)(iVar7 + 0x1c) = *(short *)(iVar7 + 0x1c) + 1;
  if (iVar1 < *(short *)(iVar7 + 0x1c)) {
    uVar6 = param_1 + 0x4cU & 3;
    uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x8000000) != 0) {
      uVar6 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & uRam02069248;
      uVar6 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x2000) != 0) {
        StructMQRacerEntry_SomeFn_36(param_1);
      }
      uVar6 = param_1 + 0x590U & 3;
      uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
      CharacterKartContext_SomeFn_1_1(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
      return;
    }
    return;
  }
  return;
}

