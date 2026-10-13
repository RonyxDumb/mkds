/* Decompiled C draft; module arm9; ROM address 0206d18c. No matching claim. */
#include "types.h"
#include "deps/0206d18c_func_0206d18c.h"

void func_0206d18c(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  
  uVar2 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & DAT_0206d568) != 0) {
    return;
  }
  iVar1 = func_020fa4c8();
  if (iVar1 == 0) {
    return;
  }
  uVar2 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & DAT_0206d56c) != 0) {
    return;
  }
  uVar2 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0x800) != 0) {
    return;
  }
  iVar1 = func_020fa4b4(0);
  uVar2 = iVar1 + 0x44U & 3;
  uVar5 = *(uint *)(iVar1 + 0x44U & 0xfffffffc);
  iVar8 = 0;
  switch(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) {
  case 0:
    goto LAB_0206d224;
  case 1:
    goto LAB_0206d224;
  case 2:
    iVar8 = StructMQRacerEntry_SomeFn_27(param_1,1,0);
    if ((iVar8 != 0) &&
       (uVar2 = param_1 + 0x590U & 3, uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc),
       uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0x58, uVar5 = uVar2 & 3,
       uVar2 = *(uint *)(uVar2 & 0xfffffffc),
       uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0)) {
      func_0208b7bc(0xc,param_1 + 0x80);
      func_0208b7bc(0xd,param_1 + 0x80);
      func_0208b7bc(0xe,param_1 + 0x80);
    }
    break;
  case 3:
    DriverContext_MaybeApplyBoost(param_1,0,0x5a);
    uVar2 = param_1 + 0x48U & 3;
    uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20 | 0x100000;
    uVar5 = DAT_0206d570;
    *(undefined2 *)(param_1 + 0x538) = 0x5a;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 8;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) == 2) {
      func_020a1ddc(*(undefined2 *)(param_1 + 0x74));
    }
    break;
  case 4:
    StructMQRacerEntry_SomeFn_55(param_1);
    break;
  case 5:
    uVar2 = iVar1 + 0x2e4U & 3;
    uVar5 = *(uint *)(iVar1 + 0x2e4U & 0xfffffffc);
    if (uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0) {
      iVar8 = func_0206bab8(param_1);
    }
    else {
      iVar8 = StructMQRacerEntry_SomeFn_27(param_1,2,0);
    }
    break;
  case 6:
    uVar7 = 0;
    func_02061874();
    func_02082e4c(*(undefined2 *)(param_1 + 0x74));
    uVar5 = DAT_0206d570;
    uVar2 = param_1 + 0x7cU & 3;
    uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    uVar2 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 0x200;
    if (uVar2 == 0) {
      if (*(char *)((*(uint *)(DAT_0206d570 & 0xfffffffc) >> (DAT_0206d570 & 3) * 8 |
                    *(uint *)(DAT_0206d570 & 0xfffffffc) << (DAT_0206d570 & 3) * -8 + 0x20) + 0x3d0)
          != '\0') {
        do {
          if (uVar7 != *(ushort *)(param_1 + 0x74)) {
            GetDriverEntry(uVar7);
            DriverContext_ApplyThunderShrink();
          }
          uVar2 = uVar5 & 3;
          uVar4 = *(uint *)(uVar5 & 0xfffffffc);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(byte *)((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x3d0));
      }
    }
    else if (uVar2 != 0) {
      uVar2 = param_1 + 0x514U & 3;
      uVar5 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar4 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      uVar2 = uVar4 + 0x2c;
      uVar5 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar4 + 0x2c) = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) ^ 0x4000;
    }
    break;
  case 7:
LAB_0206d224:
    iVar8 = StructMQRacerEntry_SomeFn_65(param_1);
    break;
  case 8:
    func_02104ee0(iVar1,param_1);
    break;
  case 9:
    uVar2 = iVar1 + 0x16cU & 3;
    uVar5 = *(uint *)(iVar1 + 0x16cU & 0xfffffffc);
    if (uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0) {
      iVar8 = func_0206bab8(param_1);
    }
    else {
      iVar8 = StructMQRacerEntry_SomeFn_27(param_1,2,0);
    }
  }
  if ((iVar8 != 0) &&
     (uVar2 = (*(uint *)(DAT_0206d570 & 0xfffffffc) >> (DAT_0206d570 & 3) * 8 |
              *(uint *)(DAT_0206d570 & 0xfffffffc) << (DAT_0206d570 & 3) * -8 + 0x20) + 8,
     uVar5 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
     (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) == 4)) {
    func_0207a70c(*(undefined2 *)(param_1 + 0x74));
  }
  uVar2 = (*(uint *)(DAT_0206d570 & 0xfffffffc) >> (DAT_0206d570 & 3) * 8 |
          *(uint *)(DAT_0206d570 & 0xfffffffc) << (DAT_0206d570 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) == 2) {
    func_020a1e40(*(undefined2 *)(param_1 + 0x74),iVar1);
  }
  iVar3 = func_020f9880(iVar1);
  if (iVar3 == 0) {
    return;
  }
  uVar2 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & DAT_0206d574) != 0) {
    uVar2 = 1 << (*(ushort *)(param_1 + 0x74) & 0xff);
    if (((uint)*(byte *)(iVar1 + 0x128) & uVar2 & 0xff) == 0) {
      *(byte *)(iVar1 + 0x128) = *(byte *)(iVar1 + 0x128) | (byte)uVar2;
      DriverContext_MaybeQueuePlaySfx(param_1,0xe9,0x7f,0);
      return;
    }
    return;
  }
  if ((*(ushort *)(iVar1 + 0x78) & 0x8000) == 0) {
    uVar2 = *(ushort *)(iVar1 + 0x78) & 0xffff00ff;
  }
  else {
    uVar2 = 8;
  }
  if (uVar2 < *(byte *)((*(uint *)(DAT_0206d570 & 0xfffffffc) >> (DAT_0206d570 & 3) * 8 |
                        *(uint *)(DAT_0206d570 & 0xfffffffc) << (DAT_0206d570 & 3) * -8 + 0x20) +
                       0x3d0)) {
    iVar1 = GetDriverEntry(uVar2);
    if ((*(short *)(iVar1 + 0x74) != *(short *)(param_1 + 0x74)) && (iVar8 != 0)) {
      uVar5 = (*(uint *)(DAT_0206d570 & 0xfffffffc) >> (DAT_0206d570 & 3) * 8 |
              *(uint *)(DAT_0206d570 & 0xfffffffc) << (DAT_0206d570 & 3) * -8 + 0x20) + 8;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) != 4) {
        func_0207a70c(uVar2);
      }
      uVar5 = iVar1 + 0x48U & 3;
      uVar4 = *(uint *)(iVar1 + 0x48U & 0xfffffffc);
      if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x840) == 0) {
        uVar5 = iVar1 + 0x3ccU & 3;
        uVar4 = *(uint *)(iVar1 + 0x3ccU & 0xfffffffc);
        StructMQRacerEntry_SomeFn_5(iVar1,uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,8);
      }
      uVar5 = iVar1 + 0x7cU & 3;
      uVar4 = *(uint *)(iVar1 + 0x7cU & 0xfffffffc);
      uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      if (((uVar5 & 0x10) != 0) && ((uVar5 & 0x30000) == 0)) {
        StructMQRacerEntry_SomeFn_7(iVar1,2,0);
      }
    }
    uVar5 = param_1 + 0x7cU & 3;
    uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x200) != 0) {
      uVar5 = param_1 + 0x514U & 3;
      uVar4 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar6 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      uVar5 = uVar6 + 0x2c;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(uint *)(uVar6 + 0x2c) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x9fffffff;
      uVar5 = param_1 + 0x514U & 3;
      uVar4 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar6 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      uVar5 = uVar6 + 0x2c;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(uint *)(uVar6 + 0x2c) =
           uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20 | (uVar2 & 3) << 0x1d;
      return;
    }
    return;
  }
  return;
}

