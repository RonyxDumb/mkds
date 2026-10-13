/* Decompiled C draft; module arm9; ROM address 02013e18. No matching claim. */
#include "types.h"
#include "deps/02013e18_func_02013e18.h"

void func_02013e18(int *param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  uVar8 = param_4 + 0xcU & 3;
  uVar4 = *(uint *)(param_4 + 0xcU & 0xfffffffc);
  uVar1 = param_4 + 0x10U & 3;
  uVar10 = *(uint *)(param_4 + 0x10U & 0xfffffffc);
  uVar6 = param_3 + 4 & 3;
  uVar7 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar13 = (int)param_2 >> 0xc;
  iVar5 = param_4 + (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20);
  iVar3 = param_4 + (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20);
  iVar11 = param_4 + (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
  uVar8 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  if (uVar13 == *(ushort *)(param_4 + 4) - 1) {
    if ((uVar8 & 0xc0000000) != 0) {
      if ((uVar8 & 0x40000000) == 0) {
        uVar13 = (uVar13 & 3) + (uVar13 >> 2);
      }
      else {
        uVar13 = (uVar13 & 1) + (uVar13 >> 1);
      }
    }
    uVar8 = param_4 + 8U & 3;
    uVar1 = *(uint *)(param_4 + 8U & 0xfffffffc);
    if (((uVar1 >> uVar8 * 8 | uVar1 << uVar8 * -8 + 0x20) & 2) == 0) {
      iVar3 = func_02013c78(param_1,iVar5,iVar3,*(undefined2 *)(iVar11 + uVar13 * 2));
      if (iVar3 != 0) {
        uVar13 = (uint)(param_1 + 5) & 3;
        uVar8 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
        uVar7 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
        uVar13 = (uint)(param_1 + 1) & 3;
        uVar8 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
        uVar6 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
        uVar13 = (uint)(param_1 + 4) & 3;
        uVar8 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
        uVar1 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
        uVar13 = (uint)(param_1 + 2) & 3;
        uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
        uVar8 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
        uVar13 = (uint)(param_1 + 3) & 3;
        uVar4 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
        uVar13 = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
        uVar4 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
        param_1[6] = (int)(uVar6 * uVar7 - uVar8 * uVar1) >> 0xc;
        param_1[7] = (int)(uVar8 * uVar13 - uVar4 * uVar7) >> 0xc;
        param_1[8] = (int)(uVar4 * uVar1 - uVar6 * uVar13) >> 0xc;
        return;
      }
      return;
    }
    iVar9 = 0;
  }
  else if ((uVar8 & 0xc0000000) == 0) {
    iVar9 = uVar13 + 1;
  }
  else {
    uVar1 = (uVar8 & uRam02014154) >> 0x10;
    if ((uVar8 & 0x40000000) == 0) {
      if (uVar13 < uVar1) {
        uVar13 = uVar13 >> 2;
        iVar9 = uVar13 + 1;
        param_2 = param_2 & uRam0201415c;
        iVar12 = 4;
        goto LAB_02013f88;
      }
      uVar13 = (uVar13 & 3) + (uVar13 >> 2);
      iVar9 = uVar13 + 1;
    }
    else {
      if (uVar13 < uVar1) {
        uVar13 = uVar13 >> 1;
        iVar9 = uVar13 + 1;
        param_2 = param_2 & uRam02014158;
        iVar12 = 2;
        goto LAB_02013f88;
      }
      uVar13 = (uVar8 & uRam02014154) >> 0x11;
      iVar9 = uVar13 + 1;
    }
  }
  iVar12 = 1;
  param_2 = param_2 & uRam02014160;
LAB_02013f88:
  iVar2 = func_02013c78(&local_68,iVar5,iVar3,*(undefined2 *)(iVar11 + uVar13 * 2));
  iVar3 = func_02013c78(&local_44,iVar5,iVar3,*(undefined2 *)(iVar11 + iVar9 * 2));
  *param_1 = local_68 * iVar12 + ((int)(param_2 * (local_44 - local_68)) >> 0xc);
  param_1[1] = local_64 * iVar12 + ((int)(param_2 * (local_40 - local_64)) >> 0xc);
  param_1[2] = local_60 * iVar12 + ((int)(param_2 * (local_3c - local_60)) >> 0xc);
  param_1[3] = local_5c * iVar12 + ((int)(param_2 * (local_38 - local_5c)) >> 0xc);
  param_1[4] = local_58 * iVar12 + ((int)(param_2 * (local_34 - local_58)) >> 0xc);
  param_1[5] = local_54 * iVar12 + ((int)(param_2 * (local_30 - local_54)) >> 0xc);
  VecFx32_Normalize(param_1,param_1);
  VecFx32_Normalize(param_1 + 3,param_1 + 3);
  if (iVar2 != 0 || iVar3 != 0) {
    uVar13 = (uint)(param_1 + 5) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
    uVar10 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
    uVar13 = (uint)(param_1 + 1) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    uVar6 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
    uVar7 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    uVar13 = (uint)(param_1 + 4) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    uVar1 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
    uVar13 = (uint)(param_1 + 2) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar8 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
    uVar13 = (uint)(param_1 + 3) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    uVar13 = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
    param_1[6] = (int)(uVar6 * uVar10 - uVar8 * uVar1) >> 0xc;
    param_1[7] = (int)(uVar8 * uVar13 - uVar7 * uVar10) >> 0xc;
    param_1[8] = (int)(uVar7 * uVar1 - uVar6 * uVar13) >> 0xc;
    return;
  }
  param_1[6] = local_50 * iVar12 + ((int)(param_2 * (local_2c - local_50)) >> 0xc);
  param_1[7] = local_4c * iVar12 + ((int)(param_2 * (local_28 - local_4c)) >> 0xc);
  param_1[8] = local_48 * iVar12 + ((int)(param_2 * (local_24 - local_48)) >> 0xc);
  VecFx32_Normalize(param_1 + 6,param_1 + 6);
  return;
}

