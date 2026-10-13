/* Decompiled C draft; module arm9; ROM address 020952dc. No matching claim. */
#include "types.h"
#include "deps/020952dc_func_020952dc.h"

void func_020952dc(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  undefined4 unaff_r10;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  uint uVar13;
  
  iVar3 = func_02093ff0();
  if (iVar3 < param_2) {
    iVar3 = 0;
    if (0 < param_3) {
      uVar4 = FUN_02132440(param_4 << 0xc);
      uVar4 = func_02131234(0x3f000000,uVar4);
      uVar5 = FUN_02132440(param_4 << 0xc);
      uVar5 = func_021329f8(uVar5,0x3f000000);
      do {
        if (0 < param_4) {
          unaff_r10 = uVar4;
        }
        uVar15 = param_1 + 8U & 3;
        uVar14 = *(uint *)(param_1 + 8U & 0xfffffffc);
        if (param_4 < 1) {
          unaff_r10 = uVar5;
        }
        uVar6 = func_0209520c();
        uVar7 = func_021322c8(unaff_r10);
        unaff_r10 = func_02091f6c((int *)(uintptr_t)(uVar6),uVar7);
        func_0209520c();
        uVar6 = func_020951b4();
        uVar7 = Maybe_get_15d4b4_4();
        uStack_30 = func_0209518c(unaff_r10,uVar7);
        uVar7 = func_0209520c();
        iStack_2c = func_02091f6c((int *)(uintptr_t)(uVar7),0);
        iStack_2c = (uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20) + iStack_2c;
        uVar6 = Maybe_helper_09516c(uVar6);
        uStack_28 = func_0209518c(unaff_r10,uVar6);
        func_02094000(&uStack_30);
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_3);
    }
    param_5 = param_5 & 0xffff;
    if (param_5 == 0x10000) {
      uVar17 = *(uint *)(uRam020954dc & 0xfffffffc) >> (uRam020954dc & 3) * 8 |
               *(uint *)(uRam020954dc & 0xfffffffc) << (uRam020954dc & 3) * -8 + 0x20;
      uVar15 = uVar17 + 0x498 & 3;
      uVar14 = *(uint *)(uVar17 + 0x498 & 0xfffffffc);
      uVar10 = uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20;
      iVar3 = uVar17 + iRam020954e0;
      uVar15 = iVar3 + 8U & 3;
      uVar14 = *(uint *)(iVar3 + 8U & 0xfffffffc);
      uVar11 = uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20;
      uVar15 = iVar3 + 4U & 3;
      uVar8 = *(uint *)(iVar3 + 4U & 0xfffffffc);
      lVar2 = (ulonglong)uVar10 * (ulonglong)uVar11;
      uVar16 = (uint)lVar2;
      uVar14 = iVar3 + 0xcU & 3;
      uVar9 = *(uint *)(iVar3 + 0xcU & 0xfffffffc);
      uVar1 = iVar3 + 0x10U & 3;
      uVar12 = *(uint *)(iVar3 + 0x10U & 0xfffffffc);
      uVar13 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
      uVar1 = iVar3 + 0x14U & 3;
      uVar12 = *(uint *)(iVar3 + 0x14U & 0xfffffffc);
      *(uint *)(uVar17 + 0x498) = uVar13 + uVar16;
      *(uint *)(iVar3 + 4) =
           (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) +
           (uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) * uVar10 +
           uVar11 * (uVar8 >> uVar15 * 8 | uVar8 << uVar15 * -8 + 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar13,uVar16);
      uVar15 = iVar3 + 4U & 3;
      uVar14 = *(uint *)(iVar3 + 4U & 0xfffffffc);
      uVar15 = (uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20) >> 0x10;
    }
    else {
      piVar18 = (int *)((*(uint *)(uRam020954dc & 0xfffffffc) >> (uRam020954dc & 3) * 8 |
                        *(uint *)(uRam020954dc & 0xfffffffc) << (uRam020954dc & 3) * -8 + 0x20) +
                       iRam020954e0);
      if (param_5 == 0) {
        uVar15 = 0;
      }
      else {
        uVar15 = (uint)(piVar18 + 2) & 3;
        uVar14 = *(uint *)((uint)(piVar18 + 2) & 0xfffffffc);
        uVar11 = uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20;
        uVar10 = *(uint *)((uint)piVar18 & 0xfffffffc) >> ((uint)piVar18 & 3) * 8 |
                 *(uint *)((uint)piVar18 & 0xfffffffc) << ((uint)piVar18 & 3) * -8 + 0x20;
        uVar15 = (uint)(piVar18 + 1) & 3;
        uVar8 = *(uint *)((uint)(piVar18 + 1) & 0xfffffffc);
        lVar2 = (ulonglong)uVar10 * (ulonglong)uVar11;
        uVar16 = (uint)lVar2;
        uVar14 = (uint)(piVar18 + 3) & 3;
        uVar9 = *(uint *)((uint)(piVar18 + 3) & 0xfffffffc);
        uVar1 = (uint)(piVar18 + 4) & 3;
        uVar12 = *(uint *)((uint)(piVar18 + 4) & 0xfffffffc);
        uVar13 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
        uVar1 = (uint)(piVar18 + 5) & 3;
        uVar12 = *(uint *)((uint)(piVar18 + 5) & 0xfffffffc);
        *piVar18 = uVar13 + uVar16;
        piVar18[1] = (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) +
                     (uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) * uVar10 +
                     uVar11 * (uVar8 >> uVar15 * 8 | uVar8 << uVar15 * -8 + 0x20) +
                     (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar13,uVar16);
        if (param_5 == 0) {
          uVar15 = (uint)(piVar18 + 1) & 3;
          uVar14 = *(uint *)((uint)(piVar18 + 1) & 0xfffffffc);
          uVar15 = uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20;
        }
        else {
          uVar15 = (uint)(piVar18 + 1) & 3;
          uVar14 = *(uint *)((uint)(piVar18 + 1) & 0xfffffffc);
          uVar15 = (uint)((ulonglong)param_5 *
                          (ulonglong)(uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20) >> 0x20);
        }
      }
      uVar15 = uVar15 & 0xffff;
    }
    *(uint *)(param_1 + 0xa8) = uVar15;
    return;
  }
  return;
}

