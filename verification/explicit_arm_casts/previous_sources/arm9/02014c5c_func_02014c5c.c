/* Decompiled C draft; module arm9; ROM address 02014c5c. No matching claim. */
#include "types.h"
#include "deps/02014c5c_func_02014c5c.h"

void func_02014c5c(int param_1,int param_2,uint param_3,uint *param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  uVar2 = (uint)*(ushort *)(param_1 + param_2 * 2 + 0x14);
  uVar9 = param_1 + uVar2;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar9 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
  iVar4 = param_1 + uVar2;
  if ((uVar9 & 1) == 0) {
    uVar8 = iVar4 + 4;
    if (((param_3 & uRam0201503c) == 0) ||
       (uVar2 = param_1 + 8U & 3, uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc),
       ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 1) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    *param_4 = 0;
    if ((uVar9 & 6) == 0) {
      if ((uVar9 & 8) == 0) {
        if (bVar1) {
          func_02014954(param_4 + 0x13,param_3,uVar8,param_1);
        }
        else {
          func_02014ad0(param_4 + 0x13,param_3,uVar8,param_1);
        }
        uVar2 = iVar4 + 0xc;
      }
      else {
        uVar2 = iVar4 + 8;
        param_4[0x13] =
             *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
             *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
      }
      if ((uVar9 & 0x10) == 0) {
        if (bVar1) {
          func_02014954(param_4 + 0x14,param_3,uVar2,param_1);
        }
        else {
          func_02014ad0(param_4 + 0x14,param_3,uVar2,param_1);
        }
        uVar3 = uVar2 + 8;
      }
      else {
        uVar3 = uVar2 + 4;
        param_4[0x14] =
             *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
             *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      }
      if ((uVar9 & 0x20) == 0) {
        if (bVar1) {
          func_02014954(param_4 + 0x15,param_3,uVar3,param_1);
        }
        else {
          func_02014ad0(param_4 + 0x15,param_3,uVar3,param_1);
        }
        uVar8 = uVar3 + 8;
      }
      else {
        uVar8 = uVar3 + 4;
        param_4[0x15] =
             *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
             *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      }
    }
    else if ((uVar9 & 2) == 0) {
      func_0201520c(param_4);
    }
    else {
      *param_4 = *(uint *)((uint)param_4 & 0xfffffffc) >> ((uint)param_4 & 3) * 8 |
                 *(uint *)((uint)param_4 & 0xfffffffc) << ((uint)param_4 & 3) * -8 + 0x20 | 4;
    }
    if ((uVar9 & 0xc0) == 0) {
      if ((uVar9 & 0x100) == 0) {
        if (bVar1) {
          func_02013e18(param_4 + 10,param_3,uVar8,param_1);
        }
        else {
          func_02014164(param_4 + 10,param_3,uVar8,param_1);
        }
        uVar8 = uVar8 + 8;
      }
      else {
        uVar2 = param_1 + 0xcU & 3;
        uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
        uVar3 = param_1 + 0x10U & 3;
        uVar6 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
        iVar4 = func_02013c78(param_4 + 10,
                              param_1 + (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20),
                              param_1 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20),
                              *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                              *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20);
        if (iVar4 != 0) {
          uVar2 = (uint)(param_4 + 0xf) & 3;
          uVar3 = *(uint *)((uint)(param_4 + 0xf) & 0xfffffffc);
          uVar11 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
          uVar2 = (uint)(param_4 + 0xb) & 3;
          uVar3 = *(uint *)((uint)(param_4 + 0xb) & 0xfffffffc);
          uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
          uVar2 = (uint)(param_4 + 10) & 3;
          uVar5 = *(uint *)((uint)(param_4 + 10) & 0xfffffffc);
          uVar7 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
          uVar2 = (uint)(param_4 + 0xe) & 3;
          uVar5 = *(uint *)((uint)(param_4 + 0xe) & 0xfffffffc);
          uVar10 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
          uVar2 = (uint)(param_4 + 0xc) & 3;
          uVar5 = *(uint *)((uint)(param_4 + 0xc) & 0xfffffffc);
          uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
          uVar2 = (uint)(param_4 + 0xd) & 3;
          uVar6 = *(uint *)((uint)(param_4 + 0xd) & 0xfffffffc);
          uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
          param_4[0x10] = (int)(uVar3 * uVar11 - uVar5 * uVar10) >> 0xc;
          param_4[0x11] = (int)(uVar5 * uVar2 - uVar7 * uVar11) >> 0xc;
          param_4[0x12] = (int)(uVar7 * uVar10 - uVar3 * uVar2) >> 0xc;
        }
        uVar8 = uVar8 + 4;
      }
    }
    else if ((uVar9 & 0x40) == 0) {
      func_02015044(param_4);
    }
    else {
      *param_4 = *(uint *)((uint)param_4 & 0xfffffffc) >> ((uint)param_4 & 3) * 8 |
                 *(uint *)((uint)param_4 & 0xfffffffc) << ((uint)param_4 & 3) * -8 + 0x20 | 2;
    }
    if ((uVar9 & 0x600) == 0) {
      if ((uVar9 & 0x800) == 0) {
        if (bVar1) {
          func_0201456c(&local_58,param_3,uVar8,param_1);
        }
        else {
          func_02014724(&local_58,param_3,uVar8,param_1);
        }
        local_40 = local_58;
        local_34 = local_54;
      }
      else {
        local_40 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                   *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
        uVar2 = uVar8 + 4 & 3;
        uVar3 = *(uint *)(uVar8 + 4 & 0xfffffffc);
        local_34 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      }
      if ((uVar9 & 0x1000) == 0) {
        if (bVar1) {
          func_0201456c(&local_50,param_3,uVar8 + 8,param_1);
        }
        else {
          func_02014724(&local_50,param_3,uVar8 + 8,param_1);
        }
        local_3c = local_50;
        local_30 = local_4c;
      }
      else {
        uVar2 = uVar8 + 8 & 3;
        uVar3 = *(uint *)(uVar8 + 8 & 0xfffffffc);
        local_3c = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
        uVar2 = uVar8 + 0xc & 3;
        uVar3 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
        local_30 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      }
      if ((uVar9 & 0x2000) == 0) {
        if (bVar1) {
          func_0201456c(&local_48,param_3,uVar8 + 0x10,param_1);
        }
        else {
          func_02014724(&local_48,param_3,uVar8 + 0x10,param_1);
        }
        local_38 = local_48;
        local_2c = local_44;
      }
      else {
        uVar9 = uVar8 + 0x10 & 3;
        uVar2 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
        local_38 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
        uVar9 = uVar8 + 0x14 & 3;
        uVar8 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
        local_2c = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      }
    }
    else {
      if ((uVar9 & 0x200) == 0) {
        func_020151a4(param_4);
        return;
      }
      *param_4 = *(uint *)((uint)param_4 & 0xfffffffc) >> ((uint)param_4 & 3) * 8 |
                 *(uint *)((uint)param_4 & 0xfffffffc) << ((uint)param_4 & 3) * -8 + 0x20 | 1;
    }
  }
  else {
    *param_4 = 7;
  }
  uVar8 = *(uint *)(uRam02015040 & 0xfffffffc) >> (uRam02015040 & 3) * 8 |
          *(uint *)(uRam02015040 & 0xfffffffc) << (uRam02015040 & 3) * -8 + 0x20;
  uVar9 = uVar8 + 0xe8 & 3;
  uVar2 = *(uint *)(uVar8 + 0xe8 & 0xfffffffc);
  (*(code *)(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20))
            (param_4,&local_40,
             *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
             *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20);
  return;
}

