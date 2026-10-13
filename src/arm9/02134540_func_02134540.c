/* Decompiled C draft; module arm9; ROM address 02134540. No matching claim. */
#include "types.h"
#include "deps/02134540_func_02134540.h"

undefined4 func_02134540(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  uint local_28;
  
  iVar2 = func_0213c94c(param_4,0);
  if (iVar2 == 0) {
    func_0213c94c(param_4,0xffffffff);
  }
  uVar12 = param_2 * param_3;
  if (((uVar12 == 0) ||
      (uVar4 = param_4 + 0xdU & 3, uVar3 = *(uint *)(param_4 + 0xdU & 0xfffffffc),
      ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xff) != 0)) ||
     (uVar4 = param_4 + 4U & 3, uVar3 = *(uint *)(param_4 + 4U & 0xfffffffc),
     uVar4 = ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) << 0x16) >> 0x1d, uVar4 == 0)) {
    return 0;
  }
  if (uVar4 == 2) {
    func_02135010();
  }
  uVar4 = param_4 + 4U & 3;
  uVar3 = *(uint *)(param_4 + 4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  bVar1 = true;
  if ((((int)(uVar4 << 0x13) < 0) && (uVar4 = (uVar4 << 0x19) >> 0x1e, uVar4 != 2)) && (uVar4 != 1))
  {
    bVar1 = false;
  }
  uVar4 = param_4 + 8U & 3;
  uVar3 = *(uint *)(param_4 + 8U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (((uVar4 & 7) == 0) &&
     (uVar3 = param_4 + 4U & 3, uVar5 = *(uint *)(param_4 + 4U & 0xfffffffc),
     (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) << 0x1b) >> 0x1d & 2) != 0)) {
    *(uint *)(param_4 + 8) = uVar4 & 0xfffffff8 | 1;
    func_02134508(param_4);
  }
  uVar4 = param_4 + 8U & 3;
  uVar3 = *(uint *)(param_4 + 8U & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 7) != 1) {
    puVar9 = (uint *)(param_4 + 0xd);
    uVar4 = (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
            *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffff00 | 1
    ;
    uVar12 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
    *puVar9 = uVar4 >> uVar12 | uVar4 << 0x20 - uVar12;
    *(undefined4 *)(param_4 + 0x28) = 0;
    return 0;
  }
  iVar2 = 0;
  if (uVar12 != 0) {
    uVar4 = param_4 + 0x1cU & 3;
    uVar3 = *(uint *)(param_4 + 0x1cU & 0xfffffffc);
    uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = param_4 + 0x24U & 3;
    uVar3 = *(uint *)(param_4 + 0x24U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if ((uVar4 != uVar5) || (bVar1)) {
      uVar3 = param_4 + 0x20U & 3;
      uVar8 = *(uint *)(param_4 + 0x20U & 0xfffffffc);
      *(uint *)(param_4 + 0x28) =
           (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) - (uVar4 - uVar5);
      piVar10 = (int *)(param_4 + 0x24);
      while( true ) {
        uVar4 = param_4 + 0x28U & 3;
        uVar3 = *(uint *)(param_4 + 0x28U & 0xfffffffc);
        local_28 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        iVar11 = 0;
        if (uVar12 < local_28) {
          local_28 = uVar12;
        }
        uVar4 = param_4 + 4U & 3;
        uVar3 = *(uint *)(param_4 + 4U & 0xfffffffc);
        if (((((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) << 0x19) >> 0x1e == 1) &&
            (local_28 != 0)) && (iVar11 = func_02134d80(param_1,10), iVar11 != 0)) {
          local_28 = (iVar11 + 1) - param_1;
        }
        if (local_28 != 0) {
          uVar4 = param_4 + 0x24U & 3;
          uVar3 = *(uint *)(param_4 + 0x24U & 0xfffffffc);
          func_02134eb8(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,param_1);
          param_1 = param_1 + local_28;
          *piVar10 = (*(uint *)((uint)piVar10 & 0xfffffffc) >> ((uint)piVar10 & 3) * 8 |
                     *(uint *)((uint)piVar10 & 0xfffffffc) << ((uint)piVar10 & 3) * -8 + 0x20) +
                     local_28;
          uVar4 = param_4 + 0x28U & 3;
          uVar3 = *(uint *)(param_4 + 0x28U & 0xfffffffc);
          uVar12 = uVar12 - local_28;
          *(uint *)(param_4 + 0x28) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) - local_28;
        }
        uVar4 = param_4 + 0x28U & 3;
        uVar3 = *(uint *)(param_4 + 0x28U & 0xfffffffc);
        if ((((uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) || (iVar11 != 0)) ||
            (uVar4 = param_4 + 4U & 3, uVar3 = *(uint *)(param_4 + 4U & 0xfffffffc),
            ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) << 0x19) >> 0x1e == 0)) &&
           (iVar11 = func_0213446c(param_4,0), iVar11 != 0)) break;
        iVar2 = iVar2 + local_28;
        if ((uVar12 == 0) || (!bVar1)) goto LAB_021347d0;
      }
      puVar9 = (uint *)(param_4 + 0xd);
      uVar4 = (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
              *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffff00 |
              1;
      uVar12 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
      *puVar9 = uVar4 >> uVar12 | uVar4 << 0x20 - uVar12;
      uVar12 = 0;
      *(undefined4 *)(param_4 + 0x28) = 0;
    }
  }
LAB_021347d0:
  if ((uVar12 != 0) && (!bVar1)) {
    uVar4 = param_4 + 0x1cU & 3;
    uVar8 = *(uint *)(param_4 + 0x1cU & 0xfffffffc);
    uVar3 = param_4 + 0x20U & 3;
    uVar5 = *(uint *)(param_4 + 0x20U & 0xfffffffc);
    *(int *)(param_4 + 0x1c) = param_1;
    *(uint *)(param_4 + 0x20) = uVar12;
    *(uint *)(param_4 + 0x24) = param_1 + uVar12;
    iVar11 = func_0213446c(param_4,&local_28);
    if (iVar11 == 0) {
      iVar2 = iVar2 + local_28;
    }
    else {
      puVar9 = (uint *)(param_4 + 0xd);
      uVar6 = (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
              *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffff00 |
              1;
      uVar12 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
      *puVar9 = uVar6 >> uVar12 | uVar6 << 0x20 - uVar12;
      *(undefined4 *)(param_4 + 0x28) = 0;
    }
    *(uint *)(param_4 + 0x1c) = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
    *(uint *)(param_4 + 0x20) = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    func_02134508(param_4);
    *(undefined4 *)(param_4 + 0x28) = 0;
  }
  uVar12 = param_4 + 4U & 3;
  uVar4 = *(uint *)(param_4 + 4U & 0xfffffffc);
  if (((uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20) << 0x19) >> 0x1e != 2) {
    *(undefined4 *)(param_4 + 0x28) = 0;
  }
  uVar7 = MaybeBoundsCheck(iVar2,param_2);
  return uVar7;
}

