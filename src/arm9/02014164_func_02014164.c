/* Decompiled C draft; module arm9; ROM address 02014164. No matching claim. */
#include "types.h"
#include "deps/02014164_func_02014164.h"

void func_02014164(int *param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
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
  
  uVar3 = param_4 + 0xcU & 3;
  uVar8 = *(uint *)(param_4 + 0xcU & 0xfffffffc);
  uVar7 = param_4 + 0x10U & 3;
  uVar5 = *(uint *)(param_4 + 0x10U & 0xfffffffc);
  uVar11 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
           *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  uVar10 = param_3 + 4 & 3;
  uVar4 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar1 = param_2 >> 0xc;
  iVar9 = param_4 + (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20);
  iVar6 = param_4 + (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
  param_4 = param_4 + (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20);
  if ((uVar11 & 0xc0000000) != 0) {
    uVar3 = uVar11 & uRam02014568;
    if ((uVar11 & 0x40000000) == 0) {
      if ((uVar1 & 3) == 0) {
        uVar1 = uVar1 >> 2;
      }
      else {
        if (uVar1 <= uVar3 >> 0x10) {
          if ((uVar1 & 1) != 0) {
            if ((uVar1 & 2) == 0) {
              uVar3 = uVar1 >> 2;
              uVar1 = uVar3 + 1;
            }
            else {
              uVar1 = uVar1 >> 2;
              uVar3 = uVar1 + 1;
            }
            iVar2 = func_02013c78(param_1,iVar9,iVar6,*(undefined2 *)(param_4 + uVar3 * 2));
            iVar6 = func_02013c78(&local_68,iVar9,iVar6,*(undefined2 *)(param_4 + uVar1 * 2));
            *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) * 3
                       + local_68;
            uVar1 = (uint)(param_1 + 1) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
            param_1[1] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 3 + local_64;
            uVar1 = (uint)(param_1 + 2) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
            param_1[2] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 3 + local_60;
            uVar1 = (uint)(param_1 + 3) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
            param_1[3] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 3 + local_5c;
            uVar1 = (uint)(param_1 + 4) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
            param_1[4] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 3 + local_58;
            uVar1 = (uint)(param_1 + 5) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
            param_1[5] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 3 + local_54;
            VecFx32_Normalize((uint)(uintptr_t)(param_1),param_1);
            VecFx32_Normalize((uint)(uintptr_t)(param_1 + 3),param_1 + 3);
            if (iVar2 != 0 || iVar6 != 0) {
              uVar1 = (uint)(param_1 + 5) & 3;
              uVar3 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
              uVar5 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
              uVar1 = (uint)(param_1 + 1) & 3;
              uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
              uVar10 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
              uVar1 = (uint)(param_1 + 4) & 3;
              uVar3 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
              uVar7 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
              uVar1 = (uint)(param_1 + 2) & 3;
              uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
              uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
              uVar1 = (uint)(param_1 + 3) & 3;
              uVar4 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
              uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
              uVar4 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
              param_1[6] = (int)(uVar10 * uVar5 - uVar3 * uVar7) >> 0xc;
              param_1[7] = (int)(uVar3 * uVar1 - uVar4 * uVar5) >> 0xc;
              param_1[8] = (int)(uVar4 * uVar7 - uVar10 * uVar1) >> 0xc;
              return;
            }
            uVar1 = (uint)(param_1 + 6) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
            param_1[6] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 3 + local_50;
            uVar1 = (uint)(param_1 + 7) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
            param_1[7] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 3 + local_4c;
            uVar1 = (uint)(param_1 + 8) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
            param_1[8] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 3 + local_48;
            VecFx32_Normalize((uint)(uintptr_t)(param_1 + 6),param_1 + 6);
            return;
          }
          uVar1 = uVar1 >> 2;
          goto LAB_02014380;
        }
        uVar1 = (uVar1 & 3) + (uVar3 >> 0x12);
      }
    }
    else if ((uVar1 & 1) == 0) {
      uVar1 = uVar1 >> 1;
    }
    else {
      if (uVar1 <= uVar3 >> 0x10) {
        uVar1 = uVar1 >> 1;
LAB_02014380:
        iVar2 = func_02013c78(param_1,iVar9,iVar6,*(undefined2 *)(param_4 + uVar1 * 2));
        iVar6 = func_02013c78(&local_44,iVar9,iVar6,*(undefined2 *)(param_4 + uVar1 * 2 + 2));
        *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                   *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                   local_44;
        uVar1 = (uint)(param_1 + 1) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
        param_1[1] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + local_40;
        uVar1 = (uint)(param_1 + 2) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
        param_1[2] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + local_3c;
        uVar1 = (uint)(param_1 + 3) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
        param_1[3] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + local_38;
        uVar1 = (uint)(param_1 + 4) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
        param_1[4] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + local_34;
        uVar1 = (uint)(param_1 + 5) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
        param_1[5] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + local_30;
        VecFx32_Normalize((uint)(uintptr_t)(param_1),param_1);
        VecFx32_Normalize((uint)(uintptr_t)(param_1 + 3),param_1 + 3);
        if (iVar2 != 0 || iVar6 != 0) {
          uVar1 = (uint)(param_1 + 5) & 3;
          uVar3 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
          uVar5 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
          uVar1 = (uint)(param_1 + 1) & 3;
          uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
          uVar10 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
          uVar1 = (uint)(param_1 + 4) & 3;
          uVar3 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
          uVar7 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
          uVar1 = (uint)(param_1 + 2) & 3;
          uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
          uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
          uVar1 = (uint)(param_1 + 3) & 3;
          uVar4 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
          uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
          uVar4 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                  *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
          param_1[6] = (int)(uVar10 * uVar5 - uVar3 * uVar7) >> 0xc;
          param_1[7] = (int)(uVar3 * uVar1 - uVar4 * uVar5) >> 0xc;
          param_1[8] = (int)(uVar4 * uVar7 - uVar10 * uVar1) >> 0xc;
          return;
        }
        uVar1 = (uint)(param_1 + 6) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
        param_1[6] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + local_2c;
        uVar1 = (uint)(param_1 + 7) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
        param_1[7] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + local_28;
        uVar1 = (uint)(param_1 + 8) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
        param_1[8] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + local_24;
        VecFx32_Normalize((uint)(uintptr_t)(param_1 + 6),param_1 + 6);
        return;
      }
      uVar1 = (uVar3 >> 0x11) + 1;
    }
  }
  iVar6 = func_02013c78(param_1,iVar9,iVar6,*(undefined2 *)(param_4 + uVar1 * 2));
  if (iVar6 != 0) {
    uVar1 = (uint)(param_1 + 5) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
    uVar8 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    uVar10 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    uVar1 = (uint)(param_1 + 4) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    uVar7 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = (uint)(param_1 + 3) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    param_1[6] = (int)(uVar10 * uVar8 - uVar3 * uVar7) >> 0xc;
    param_1[7] = (int)(uVar3 * uVar1 - uVar5 * uVar8) >> 0xc;
    param_1[8] = (int)(uVar5 * uVar7 - uVar10 * uVar1) >> 0xc;
    return;
  }
  return;
}

