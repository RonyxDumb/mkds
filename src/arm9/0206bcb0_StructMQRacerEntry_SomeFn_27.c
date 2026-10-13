/* Decompiled C draft; module arm9; ROM address 0206bcb0. No matching claim. */
#include "types.h"
#include "deps/0206bcb0_StructMQRacerEntry_SomeFn_27.h"

undefined4 StructMQRacerEntry_SomeFn_27(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = param_1 + 0x180U & 3;
  uVar6 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if ((uVar7 == 1) || (uVar7 == 2)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if ((!bVar3) &&
     ((uVar6 = param_1 + 0x368U & 3, uVar4 = *(uint *)(param_1 + 0x368U & 0xfffffffc),
      iRam0206be4c <
      (int)((uint)*(ushort *)(param_1 + 0x366) * iRam0206be4c -
           (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20)) ||
      (uVar6 = param_1 + 0x7cU & 3, uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
      ((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0x200) != 0)))) {
    return 0;
  }
  uVar6 = param_1 + 0x4cU & 3;
  uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  if ((uVar6 & 0x400000) == 0) {
    uVar4 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x200) == 0) {
      bVar2 = true;
      if (((uVar6 & uRam0206be50) == 0) &&
         (uVar6 = param_1 + 0x48U & 3, uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
         ((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0x1800) == 0)) {
        uVar6 = param_1 + 0x180U & 3;
        uVar4 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
        bVar1 = false;
        if ((uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0) &&
           ((uVar7 != 1 && (uVar7 != 2)))) {
          bVar1 = true;
        }
        if (!bVar1) {
          bVar2 = false;
        }
      }
      if (bVar2) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
    }
    else {
      uVar7 = param_1 + 0x180U & 3;
      uVar4 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
      if (((uVar4 >> uVar7 * 8 == 0 && uVar4 << uVar7 * -8 + 0x20 == 0) &&
          (uVar7 = param_1 + 0x48U & 3, uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
          ((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) & 0x1800) == 0)) &&
         ((uVar6 & uRam0206be50) == 0)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return 0;
  }
  if (bVar3) {
    StructMQRacerEntry_SomeFn_0(param_1,param_2,param_3);
    if (param_3 == 0) {
      if (param_2 == 1) {
        uVar7 = param_1 + 0x7cU & 3;
        uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x200) != 0) {
          uVar7 = param_1 + 0x514U & 3;
          uVar6 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
          uVar4 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
          uVar7 = uVar4 + 0x2c;
          uVar6 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          *(uint *)(uVar4 + 0x2c) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) ^ 4;
        }
      }
      else if ((param_2 == 2) &&
              (uVar7 = param_1 + 0x7cU & 3, uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
              ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x200) != 0)) {
        uVar7 = param_1 + 0x514U & 3;
        uVar6 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
        uVar4 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
        uVar7 = uVar4 + 0x2c;
        uVar6 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(uint *)(uVar4 + 0x2c) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) ^ 8;
      }
    }
  }
  else {
    *(short *)(param_1 + 0x366) = *(short *)(param_1 + 0x366) + 1;
  }
  return 1;
}

