/* Decompiled C draft; module arm9; ROM address 0209df84. No matching claim. */
#include "types.h"
#include "deps/0209df84_func_0209df84.h"

void func_0209df84(undefined4 param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  bool bVar13;
  int local_48;
  uint local_44;
  int local_34;
  undefined1 auStack_30 [12];
  uint uVar12;
  
  uVar12 = param_2 + 0xacU & 3;
  uVar11 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
  *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_2 + 0xb8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_2 + 0xbc) = *(undefined4 *)(param_2 + 0xc);
  if (*(short *)(param_2 + 0xa2) == 1) {
    iVar2 = GetDriverEntry((short)*(char *)((*(uint *)(uRam0209e2f8 & 0xfffffffc) >>
                                             (uRam0209e2f8 & 3) * 8 |
                                            *(uint *)(uRam0209e2f8 & 0xfffffffc) <<
                                            (uRam0209e2f8 & 3) * -8 + 0x20) + 0x62));
    iVar7 = uVar12 - 0xf000;
    uVar11 = iVar2 + 0x88U & 3;
    uVar8 = *(uint *)(iVar2 + 0x88U & 0xfffffffc);
    uVar6 = param_2 + 0xcU & 3;
    uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    iVar3 = -iVar7;
    iVar5 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) -
            (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    if ((iVar7 < iVar5) || (iVar5 + iVar7 < 0 != SBORROW4(iVar5,iVar3))) {
      bVar13 = false;
    }
    else {
      uVar11 = iVar2 + 0x80U & 3;
      uVar8 = *(uint *)(iVar2 + 0x80U & 0xfffffffc);
      uVar6 = param_2 + 4U & 3;
      uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
      iVar9 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) -
              (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
      if ((iVar7 < iVar9) || (iVar9 + iVar7 < 0 != SBORROW4(iVar9,iVar3))) {
        bVar13 = false;
      }
      else {
        uVar11 = iVar2 + 0x84U & 3;
        uVar8 = *(uint *)(iVar2 + 0x84U & 0xfffffffc);
        uVar6 = param_2 + 8U & 3;
        uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
        iVar10 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) -
                 (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
        if ((iVar7 < iVar10) || (iVar10 + iVar7 < 0 != SBORROW4(iVar10,iVar3))) {
          bVar13 = false;
        }
        else {
          lVar1 = (longlong)iVar5 * (longlong)iVar5 +
                  (longlong)iVar9 * (longlong)iVar9 + (longlong)iVar10 * (longlong)iVar10;
          iVar5 = (int)((ulonglong)lVar1 >> 0x20);
          iVar3 = (int)((ulonglong)((longlong)iVar7 * (longlong)iVar7) >> 0x20);
          bVar13 = (uint)lVar1 < (uint)((longlong)iVar7 * (longlong)iVar7);
          if ((int)(iVar5 - (iVar3 + (uint)bVar13)) < 0 ==
              (SBORROW4(iVar5,iVar3) != SBORROW4(iVar5 - iVar3,(uint)bVar13))) {
            bVar13 = false;
          }
          else {
            bVar13 = true;
          }
        }
      }
    }
    if (bVar13) {
      VecFx32_Subtract(iVar2 + 0x80,param_2 + 4,auStack_30);
      iVar3 = VecFx32_CrossProduct_0(auStack_30,param_2 + 0x40);
      uVar11 = param_2 + 0x19e4U & 3;
      uVar6 = *(uint *)(param_2 + 0x19e4U & 0xfffffffc);
      uVar11 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
      if ((((int)uVar11 < 0) && (0 < iVar3)) || ((0 < (int)uVar11 && (iVar3 < 0)))) {
        func_02108e38();
        uVar11 = func_02108e6c(7);
        if ((((*(uint *)(uRam0209e2fc & 0xfffffffc) >> (uRam0209e2fc & 3) * 8 |
              *(uint *)(uRam0209e2fc & 0xfffffffc) << (uRam0209e2fc & 3) * -8 + 0x20) & 1) != 0) &&
           (uVar6 = iRam0209e300 + 0xcU & 3, uVar4 = *(uint *)(iRam0209e300 + 0xcU & 0xfffffffc),
           uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0)) {
          if (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 != 0 ||
              *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20 != 0) {
            func_0212c6f0(uVar11,0);
          }
          if (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 != 0 ||
              *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20 != 0) {
            func_0212c6f0(uVar11,0);
          }
          NNSi_MaybeSndPlayerStartSeq(uVar11,0,uRam0209e304);
        }
        *(undefined4 *)(param_2 + 0x19e4) = 0;
      }
      else {
        *(int *)(param_2 + 0x19e4) = iVar3;
      }
    }
    else {
      *(undefined4 *)(param_2 + 0x19e4) = 0;
    }
  }
  if (1 < *(ushort *)(param_2 + 0xa2)) {
    *(short *)(param_2 + 0xc2) = *(short *)(param_2 + 0xc2) + (short)uRam0209e308;
  }
  local_48 = 0;
  if (*(short *)(param_2 + 0xa2) != 0) {
    iVar3 = 0;
    local_34 = 0;
    do {
      local_44 = (uint)*(ushort *)(param_2 + 0xb2);
      if (*(short *)(param_2 + 0xa0) != 0) {
        iVar5 = param_2 + 0xc4;
        iVar7 = param_2 + local_48 * 0x10;
        iVar2 = local_34;
        do {
          iVar9 = iVar5 + iVar3;
          uVar11 = local_44 + *(ushort *)(param_2 + 0xa4);
          local_44 = uVar11 & 0xffff;
          *(short *)(iVar7 + 0xd0) = (short)(uVar11 * 0x10000 >> 0x10);
          uVar11 = (uint)*(short *)(iRam0209e30c + (((int)local_44 >> 4) * 2 + 1) * 2);
          VecFx32_AddScale1((uint)((ulonglong)uVar11 * (ulonglong)uVar12) >> 0xc |
                            (((int)uVar12 >> 0x1f) * uVar11 +
                            uVar12 * ((int)uVar11 >> 0x1f) +
                            (int)((ulonglong)uVar11 * (ulonglong)uVar12 >> 0x20)) * 0x100000,
                            param_2 + 0x28,param_2 + 4,iVar9);
          uVar11 = (uint)*(short *)(iRam0209e30c + ((int)local_44 >> 4) * 4);
          VecFx32_AddScale1((uint)((ulonglong)uVar11 * (ulonglong)uVar12) >> 0xc |
                            (((int)uVar12 >> 0x1f) * uVar11 +
                            uVar12 * ((int)uVar11 >> 0x1f) +
                            (int)((ulonglong)uVar11 * (ulonglong)uVar12 >> 0x20)) * 0x100000,
                            param_2 + 0x34,iVar9,iVar9);
          iVar2 = iVar2 + 1;
          *(short *)(iVar7 + 0xd2) = *(short *)(iVar7 + 0xd2) + (short)uRam0209e308;
          iVar5 = iVar5 + 0x140;
          iVar7 = iVar7 + 0x140;
        } while (iVar2 < (int)(uint)*(ushort *)(param_2 + 0xa0));
      }
      uVar11 = param_2 + 0xa8U & 3;
      uVar6 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      local_48 = local_48 + 1;
      uVar12 = uVar12 - (uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20);
      iVar3 = iVar3 + 0x10;
    } while (local_48 < (int)(uint)*(ushort *)(param_2 + 0xa2));
  }
  uVar12 = uRam0209e2f8;
  iVar3 = 0;
  *(short *)(param_2 + 0xb2) = *(short *)(param_2 + 0xb2) - *(short *)(param_2 + 0xb0);
  if (*(char *)((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x3d0) != '\0') {
    do {
      iVar2 = param_2 + iVar3 * 4;
      uVar11 = iVar2 + 0x19c4;
      uVar6 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar11 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
      iVar3 = iVar3 + 1;
      if (0 < (int)uVar11) {
        *(uint *)(iVar2 + 0x19c4) = uVar11 - 1;
      }
    } while (iVar3 < (int)(uint)*(byte *)((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                                          *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20
                                          ) + 0x3d0));
  }
  func_020d275c(param_2,0x160);
  return;
}

