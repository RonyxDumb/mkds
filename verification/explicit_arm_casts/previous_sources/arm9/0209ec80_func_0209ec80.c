/* Decompiled C draft; module arm9; ROM address 0209ec80. No matching claim. */
#include "types.h"
#include "deps/0209ec80_func_0209ec80.h"

void func_0209ec80(undefined4 param_1,int param_2)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar13;
  uint uVar14;
  uint uVar15;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint uVar4;
  uint uVar12;
  
  uVar4 = param_2 + 0xacU & 3;
  uVar3 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 == 1) {
    uVar4 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(uint *)(param_2 + 0xa8) = uVar4 - 1;
    if ((int)uVar4 < 1) {
      *(undefined4 *)(param_2 + 0xac) = 2;
    }
    return;
  }
  if (uVar4 == 2) {
    uVar4 = param_2 + 0xa4U & 3;
    uVar3 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 == 0) {
      iVar13 = *(ushort *)(param_2 + 0xa0) + 1;
      iVar5 = StructMapObject_GetAnimationBCAFrameCount
                        (*(uint *)(uRam0209ef94 & 0xfffffffc) >> (uRam0209ef94 & 3) * 8 |
                         *(uint *)(uRam0209ef94 & 0xfffffffc) << (uRam0209ef94 & 3) * -8 + 0x20);
      if (iVar5 <= iVar13) {
        iVar13 = 0;
      }
      *(short *)(param_2 + 0xa0) = (short)iVar13;
      sVar1 = *(short *)(param_2 + 0xa0);
      if ((((sVar1 == 0) || (sVar1 == 0xf)) || (sVar1 == 0x1f)) ||
         ((sVar1 == 0x37 || (sVar1 == 0x51)))) {
        iVar5 = func_020d4ddc(param_2);
        if (iVar5 == 0) {
          uVar4 = param_2 + 0x70U & 3;
          uVar3 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
          uVar9 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
          uVar4 = iRam0209ef98 + 0x68U & 3;
          uVar3 = *(uint *)(iRam0209ef98 + 0x68U & 0xfffffffc);
          if (uVar9 == (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
            local_48 = 2;
          }
          else {
            uVar4 = iRam0209ef98 + 0x8cU & 3;
            uVar3 = *(uint *)(iRam0209ef98 + 0x8cU & 0xfffffffc);
            if (uVar9 == (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
              local_48 = 3;
            }
            else {
              local_48 = 4;
            }
          }
          local_4c = param_2 + 4;
          local_50 = uRam0209ef9c;
          local_44 = func_020d4ef4();
          func_0210b7a8(&local_50);
        }
      }
      else if (((sVar1 == 8) || (sVar1 == 0x14)) || ((sVar1 == 0x2c || (sVar1 == 0x44)))) {
        iVar5 = func_020d4ddc(param_2);
        if (iVar5 == 0) {
          uVar4 = param_2 + 0x70U & 3;
          uVar3 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
          uVar9 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
          uVar4 = iRam0209ef98 + 0x68U & 3;
          uVar3 = *(uint *)(iRam0209ef98 + 0x68U & 0xfffffffc);
          if (uVar9 == (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
            local_38 = 2;
          }
          else {
            uVar4 = iRam0209ef98 + 0x8cU & 3;
            uVar3 = *(uint *)(iRam0209ef98 + 0x8cU & 0xfffffffc);
            if (uVar9 == (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
              local_38 = 3;
            }
            else {
              local_38 = 4;
            }
          }
          local_3c = param_2 + 4;
          local_40 = uRam0209efa0;
          local_34 = func_020d4ef4();
          func_0210b7a8(&local_40);
        }
      }
      else if ((sVar1 == 0x78) && (iVar5 = func_020d4ddc(param_2), iVar5 == 0)) {
        uVar4 = param_2 + 0x70U & 3;
        uVar3 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
        uVar9 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        uVar4 = iRam0209ef98 + 0x68U & 3;
        uVar3 = *(uint *)(iRam0209ef98 + 0x68U & 0xfffffffc);
        if (uVar9 == (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
          local_28 = 2;
        }
        else {
          uVar4 = iRam0209ef98 + 0x8cU & 3;
          uVar3 = *(uint *)(iRam0209ef98 + 0x8cU & 0xfffffffc);
          if (uVar9 == (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
            local_28 = 3;
          }
          else {
            local_28 = 4;
          }
        }
        local_2c = param_2 + 4;
        local_30 = uRam0209efa4;
        local_24 = func_020d4ef4();
        func_0210b7a8(&local_30);
      }
    }
    else if (uVar4 == 1) {
      iVar13 = *(ushort *)(param_2 + 0xa0) + 1;
      iVar5 = StructMapObject_GetAnimationBCAFrameCount
                        (*(uint *)(uRam0209efa8 & 0xfffffffc) >> (uRam0209efa8 & 3) * 8 |
                         *(uint *)(uRam0209efa8 & 0xfffffffc) << (uRam0209efa8 & 3) * -8 + 0x20);
      if (iVar5 <= iVar13) {
        iVar13 = 0;
      }
      *(short *)(param_2 + 0xa0) = (short)iVar13;
      if ((*(short *)(param_2 + 0xa0) == 0) && (iVar5 = func_020d4ddc(param_2), iVar5 == 0)) {
        uVar4 = param_2 + 0x70U & 3;
        uVar3 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
        uVar9 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        uVar4 = iRam0209ef98 + 0x68U & 3;
        uVar3 = *(uint *)(iRam0209ef98 + 0x68U & 0xfffffffc);
        if (uVar9 == (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
          local_18 = 2;
        }
        else {
          uVar4 = iRam0209ef98 + 0x8cU & 3;
          uVar3 = *(uint *)(iRam0209ef98 + 0x8cU & 0xfffffffc);
          if (uVar9 == (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
            local_18 = 3;
          }
          else {
            local_18 = 4;
          }
        }
        local_1c = param_2 + 4;
        local_20 = 0x118;
        local_14 = func_020d4ef4();
        func_0210b7a8(&local_20);
      }
    }
    if (*(short *)(param_2 + 0xa0) == 0) {
      uVar14 = *(uint *)(uRam0209efac & 0xfffffffc) >> (uRam0209efac & 3) * 8 |
               *(uint *)(uRam0209efac & 0xfffffffc) << (uRam0209efac & 3) * -8 + 0x20;
      iVar5 = uVar14 + iRam0209efb0;
      uVar4 = iVar5 + 8U & 3;
      uVar3 = *(uint *)(iVar5 + 8U & 0xfffffffc);
      uVar10 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar14 + 0x498 & 3;
      uVar3 = *(uint *)(uVar14 + 0x498 & 0xfffffffc);
      uVar8 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = iVar5 + 4U & 3;
      uVar6 = *(uint *)(iVar5 + 4U & 0xfffffffc);
      lVar2 = (ulonglong)uVar8 * (ulonglong)uVar10;
      uVar15 = (uint)lVar2;
      uVar3 = iVar5 + 0xcU & 3;
      uVar7 = *(uint *)(iVar5 + 0xcU & 0xfffffffc);
      uVar9 = iVar5 + 0x10U & 3;
      uVar11 = *(uint *)(iVar5 + 0x10U & 0xfffffffc);
      uVar12 = uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20;
      uVar9 = iVar5 + 0x14U & 3;
      uVar11 = *(uint *)(iVar5 + 0x14U & 0xfffffffc);
      *(uint *)(uVar14 + 0x498) = uVar12 + uVar15;
      *(uint *)(iVar5 + 4) =
           (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) +
           (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) * uVar8 +
           uVar10 * (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar12,uVar15);
      uVar4 = iVar5 + 4U & 3;
      uVar3 = *(uint *)(iVar5 + 4U & 0xfffffffc);
      *(int *)(param_2 + 0xa8) =
           (int)((ulonglong)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 0x78 >> 0x20) + 0x3c
      ;
      *(undefined4 *)(param_2 + 0xac) = 1;
      return;
    }
    return;
  }
  return;
}

