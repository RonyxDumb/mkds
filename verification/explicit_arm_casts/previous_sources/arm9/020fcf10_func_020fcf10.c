/* Decompiled C draft; module arm9; ROM address 020fcf10. No matching claim. */
#include "types.h"
#include "deps/020fcf10_func_020fcf10.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020fcf10(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
                  uint param_7)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint uVar8;
  
  uVar7 = param_1 + 0x228U & 3;
  uVar2 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  uVar7 = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + 0x1fc;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  uVar4 = *(undefined4 *)(uVar8 + 0x60);
  uVar6 = *(undefined4 *)(uVar8 + 100);
  *(undefined4 *)(param_1 + 0x22c) = *(undefined4 *)(uVar8 + 0x5c);
  *(undefined4 *)(param_1 + 0x230) = uVar4;
  *(undefined4 *)(param_1 + 0x234) = uVar6;
  uVar7 = uVar8 + 0x44 & 3;
  uVar2 = *(uint *)(uVar8 + 0x44 & 0xfffffffc);
  iVar10 = param_1 + 0x50;
  piVar9 = (int *)(param_1 + 0x5c);
  uVar11 = param_1 + 0x238;
  if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x100) != 0) {
    uVar7 = param_1 + 0x22cU & 3;
    uVar2 = *(uint *)(param_1 + 0x22cU & 0xfffffffc);
    *(uint *)(param_1 + 0x22c) = -(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
    uVar7 = param_1 + 0x230U & 3;
    uVar2 = *(uint *)(param_1 + 0x230U & 0xfffffffc);
    *(uint *)(param_1 + 0x230) = -(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
    uVar7 = param_1 + 0x234U & 3;
    uVar2 = *(uint *)(param_1 + 0x234U & 0xfffffffc);
    *(uint *)(param_1 + 0x234) = -(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
  }
  Vector3_Cross(param_1 + 0x22c,uVar8 + 0x244,&local_34);
  iVar3 = iRam020fd250;
  lVar1 = (longlong)param_4 * (longlong)(int)*(short *)(iRam020fd250 + ((param_3 >> 4) * 2 + 1) * 2)
  ;
  uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  *(uint *)(param_1 + 0x250) =
       (uint)((longlong)(int)local_34 * (longlong)(int)uVar7) >> 0xc |
       (int)((ulonglong)((longlong)(int)local_34 * (longlong)(int)uVar7) >> 0x20) << 0x14;
  *(uint *)(param_1 + 0x254) =
       (uint)((longlong)(int)local_30 * (longlong)(int)uVar7) >> 0xc |
       (int)((ulonglong)((longlong)(int)local_30 * (longlong)(int)uVar7) >> 0x20) << 0x14;
  *(uint *)(param_1 + 600) =
       (uint)((longlong)(int)local_2c * (longlong)(int)uVar7) >> 0xc |
       (int)((ulonglong)((longlong)(int)local_2c * (longlong)(int)uVar7) >> 0x20) << 0x14;
  lVar1 = (longlong)param_4 * (longlong)(int)*(short *)(iVar3 + (param_3 >> 4) * 4);
  VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14,param_1 + 0x22c,
                    param_1 + 0x250,param_1 + 0x250);
  VecFx32_AddScale1(0x1e000,param_1 + 0x22c);
  iVar3 = StructMQRacerEntry_SomeFn_64(uVar8);
  if (iVar3 == 0) {
    uVar4 = *(undefined4 *)(uVar8 + 0x9c);
    uVar6 = *(undefined4 *)(uVar8 + 0xa0);
    *(undefined4 *)(param_1 + 0x244) = *(undefined4 *)(uVar8 + 0x98);
    *(undefined4 *)(param_1 + 0x248) = uVar4;
    *(undefined4 *)(param_1 + 0x24c) = uVar6;
  }
  VecFx32_Add(&local_34,param_1 + 0x244,&local_34);
  VecFx32_Subtract(&local_34,iVar10,uVar11);
  iVar12 = (int)((ulonglong)((longlong)(int)param_2 * (longlong)(int)param_2) >> 0x20);
  lVar1 = (longlong)
          (int)(*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
               *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) * (longlong)param_5;
  local_34 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar7 = param_1 + 0x23cU & 3;
  uVar2 = *(uint *)(param_1 + 0x23cU & 0xfffffffc);
  iVar3 = (int)param_2 >> 0x1f;
  lVar1 = (longlong)(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) * (longlong)param_5;
  local_30 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar7 = param_1 + 0x240U & 3;
  uVar2 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) * (longlong)param_5;
  local_2c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  lVar1 = (longlong)(int)local_2c * (longlong)(int)local_2c +
          (longlong)(int)local_34 * (longlong)(int)local_34 +
          (longlong)(int)local_30 * (longlong)(int)local_30;
  uVar7 = (uint)lVar1;
  iVar5 = (int)((ulonglong)lVar1 >> 0x20);
  bVar13 = uVar7 < (uint)((longlong)(int)param_2 * (longlong)(int)param_2);
  if ((int)(iVar5 - (iVar12 + (uint)bVar13)) < 0 ==
      (SBORROW4(iVar5,iVar12) != SBORROW4(iVar5 - iVar12,(uint)bVar13))) {
    if ((int)(uint)(uVar7 < 0x10) <= iVar5) {
      Vector3_MaybeNormalize(&local_34,&local_34);
    }
    local_34 = (uint)((ulonglong)param_2 * (ulonglong)local_34) >> 0xc |
               (((int)local_34 >> 0x1f) * param_2 +
               local_34 * iVar3 + (int)((ulonglong)param_2 * (ulonglong)local_34 >> 0x20)) *
               0x100000;
    local_2c = (uint)((ulonglong)param_2 * (ulonglong)local_2c) >> 0xc |
               (((int)local_2c >> 0x1f) * param_2 +
               local_2c * iVar3 + (int)((ulonglong)param_2 * (ulonglong)local_2c >> 0x20)) *
               0x100000;
    local_30 = (uint)((ulonglong)param_2 * (ulonglong)local_30) >> 0xc |
               (((int)local_30 >> 0x1f) * param_2 +
               local_30 * iVar3 + (int)((ulonglong)param_2 * (ulonglong)local_30 >> 0x20)) *
               0x100000;
  }
  *piVar9 = (int)((*(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                  *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20) * param_6
                 + local_34) >> (param_7 & 0xff);
  uVar7 = param_1 + 0x60U & 3;
  uVar2 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  *(int *)(param_1 + 0x60) =
       (int)((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) * param_6 + local_30) >>
       (param_7 & 0xff);
  uVar7 = param_1 + 100U & 3;
  uVar2 = *(uint *)(param_1 + 100U & 0xfffffffc);
  *(int *)(param_1 + 100) =
       (int)((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) * param_6 + local_2c) >>
       (param_7 & 0xff);
  VecFx32_Add(piVar9,iVar10,iVar10);
  uVar7 = param_1 + 0xdcU & 3;
  uVar2 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  iVar3 = func_01ffdee4(iVar10,param_1 + 0xe4,0,uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20,4,
                        (int)*(short *)(param_1 + 0xda),&local_34,0,0,0,0,0,0,0);
  if (iVar3 != 0) {
    uVar7 = uVar8 + 0x48 & 3;
    uVar2 = *(uint *)(uVar8 + 0x48 & 0xfffffffc);
    if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 1) != 0) {
      VecFx32_Add(iVar10,&local_34,iVar10);
      return;
    }
    uVar7 = param_1 + 0x54U & 3;
    uVar2 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
    *(uint *)(param_1 + 0x54) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + local_30;
    return;
  }
  return;
}

