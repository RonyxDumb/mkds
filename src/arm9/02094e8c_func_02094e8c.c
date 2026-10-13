/* Decompiled C draft; module arm9; ROM address 02094e8c. No matching claim. */
#include "types.h"
#include "deps/02094e8c_func_02094e8c.h"

void func_02094e8c(undefined4 param_1,int param_2)

{
  uint uVar1;
  short sVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  int local_30;
  int local_2c;
  int local_28;
  uint uVar12;
  
  uVar12 = param_2 + 0xa0U & 3;
  uVar11 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
  *(uint *)(param_2 + 0xa0) = uVar12 - 1;
  if ((int)uVar12 < 1) {
    *(undefined4 *)(param_2 + 0xa0) = 0xf;
    uVar12 = param_2 + 0x9cU & 3;
    uVar11 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    sVar2 = *(short *)((uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) + 0x28);
    iVar5 = GetDriverEntry((short)*(char *)((*(uint *)(uRam02095164 & 0xfffffffc) >>
                                             (uRam02095164 & 3) * 8 |
                                            *(uint *)(uRam02095164 & 0xfffffffc) <<
                                            (uRam02095164 & 3) * -8 + 0x20) + 0x62));
    uVar12 = iVar5 + 0x88U & 3;
    uVar14 = *(uint *)(iVar5 + 0x88U & 0xfffffffc);
    uVar11 = param_2 + 0xcU & 3;
    uVar13 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uVar1 = iVar5 + 0x80U & 3;
    uVar15 = *(uint *)(iVar5 + 0x80U & 0xfffffffc);
    iVar6 = (uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) -
            (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20);
    uVar12 = param_2 + 4U & 3;
    uVar11 = *(uint *)(param_2 + 4U & 0xfffffffc);
    iVar5 = (int)sVar2 << 0xc;
    iVar7 = (uVar15 >> uVar1 * 8 | uVar15 << uVar1 * -8 + 0x20) -
            (uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20);
    lVar3 = (longlong)iVar7 * (longlong)iVar7 + (longlong)iVar6 * (longlong)iVar6;
    iVar6 = (int)((ulonglong)lVar3 >> 0x20);
    lVar4 = (longlong)iVar5 * (longlong)iVar5;
    iVar5 = (int)((ulonglong)lVar4 >> 0x20);
    bVar16 = (uint)lVar3 < (uint)lVar4;
    if ((int)(iVar6 - (iVar5 + (uint)bVar16)) < 0 ==
        (SBORROW4(iVar6,iVar5) != SBORROW4(iVar6 - iVar5,(uint)bVar16))) {
      *(undefined4 *)(param_2 + 0xa4) = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0xa4) = 1;
    }
  }
  uVar12 = param_2 + 0xacU & 3;
  uVar11 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
  if (uVar12 == 0) {
    iVar5 = func_02061818();
    if (iVar5 == 2) {
      uVar12 = param_2 + 0x9cU & 3;
      uVar11 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
      uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
      iVar5 = 0;
      if (0 < *(short *)(uVar12 + 0x2a)) {
        do {
          iVar6 = (int)*(short *)(uVar12 + 0x28);
          if (iVar6 < 1) {
            uVar10 = FUN_02132440(iVar6 << 0xc);
            uVar10 = func_021329f8(uVar10,0x3f000000);
          }
          else {
            uVar10 = FUN_02132440(iVar6 << 0xc);
            uVar10 = func_02131234(0x3f000000,uVar10);
          }
          uVar12 = param_2 + 0xcU & 3;
          uVar15 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
          uVar11 = param_2 + 8U & 3;
          uVar13 = *(uint *)(param_2 + 8U & 0xfffffffc);
          uVar1 = param_2 + 4U & 3;
          uVar14 = *(uint *)(param_2 + 4U & 0xfffffffc);
          uVar8 = func_0209520c();
          uVar10 = func_021322c8(uVar10);
          uVar10 = func_02091f6c((int *)(uintptr_t)(uVar8),uVar10);
          func_0209520c();
          uVar8 = func_020951b4();
          uVar9 = Maybe_get_15d4b4_4();
          local_30 = func_0209518c(uVar10,uVar9);
          local_30 = (uVar14 >> uVar1 * 8 | uVar14 << uVar1 * -8 + 0x20) + local_30;
          uVar9 = func_0209520c();
          local_2c = func_02091f6c((int *)(uintptr_t)(uVar9),0);
          local_2c = (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) + local_2c;
          uVar8 = Maybe_helper_09516c(uVar8);
          local_28 = func_0209518c(uVar10,uVar8);
          local_28 = (uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20) + local_28;
          func_02094000(&local_30);
          uVar12 = param_2 + 0x9cU & 3;
          uVar11 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
          uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(short *)(uVar12 + 0x2a));
      }
    }
    *(undefined4 *)(param_2 + 0xac) = 1;
  }
  else if (uVar12 != 1) {
    if ((uVar12 == 2) &&
       (uVar12 = param_2 + 0xa8U & 3, uVar11 = *(uint *)(param_2 + 0xa8U & 0xfffffffc),
       uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20,
       *(uint *)(param_2 + 0xa8) = uVar12 - 1, (int)uVar12 < 1)) {
      uVar12 = param_2 + 0xa4U & 3;
      uVar11 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      if (uVar11 >> uVar12 * 8 == 0 && uVar11 << uVar12 * -8 + 0x20 == 0) {
        func_020946b8();
        *(undefined4 *)(param_2 + 0xac) = 1;
      }
      else {
        iVar5 = func_02061818();
        if (iVar5 == 0) {
          func_020952dc(param_2,6,1,10,0x14);
        }
        else {
          func_020952dc(param_2,0x1e,1,500,4);
        }
      }
    }
    goto LAB_02095124;
  }
  iVar5 = func_02061818();
  if ((iVar5 != 2) &&
     (uVar12 = param_2 + 0xa4U & 3, uVar11 = *(uint *)(param_2 + 0xa4U & 0xfffffffc),
     uVar11 >> uVar12 * 8 != 0 || uVar11 << uVar12 * -8 + 0x20 != 0)) {
    iVar5 = func_02061818();
    if (iVar5 == 0) {
      func_020952dc(param_2,6,4,10,0x14);
    }
    else {
      func_020952dc(param_2,0x1e,0x14,500,4);
    }
    *(undefined4 *)(param_2 + 0xac) = 2;
  }
LAB_02095124:
  iVar5 = func_02093ff0();
  if (iVar5 < 1) {
    return;
  }
  uVar10 = GetDriverEntry((short)*(char *)((*(uint *)(uRam02095164 & 0xfffffffc) >>
                                            (uRam02095164 & 3) * 8 |
                                           *(uint *)(uRam02095164 & 0xfffffffc) <<
                                           (uRam02095164 & 3) * -8 + 0x20) + 0x62));
  func_020d26e0(uVar10,uRam02095168);
  return;
}

