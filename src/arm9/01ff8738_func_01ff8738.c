/* Decompiled C draft; module arm9; ROM address 01ff8738. No matching claim. */
#include "types.h"
#include "deps/01ff8738_func_01ff8738.h"

void func_01ff8738(int param_1,int param_2,int param_3,uint param_4)

{
  undefined2 *puVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  uint local_34;
  uint local_30;
  uint local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  
  *(char *)(param_1 + 0xad) = (char)param_4;
  uVar6 = param_1 + 8U & 3;
  uVar9 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar10 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20 | 8;
  *(uint *)(param_1 + 8) = uVar10;
  *(int *)(param_1 + 0xb0) = param_1 + 0xf4;
  uVar6 = param_1 + 0x1cU & 3;
  uVar9 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  bVar15 = uVar9 >> uVar6 * 8 != 0;
  bVar3 = uVar9 << uVar6 * -8 + 0x20 != 0;
  uVar6 = param_1 + 4U & 3;
  uVar9 = *(uint *)(param_1 + 4U & 0xfffffffc);
  if (bVar15 || bVar3) {
    uVar10 = (uint)*(byte *)(param_1 + 0x90);
  }
  uVar6 = (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) + 0x38;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20;
  if (!bVar15 && !bVar3) {
    uVar10 = 0;
  }
  if ((uVar6 == 0) ||
     (uVar9 = param_1 + 8U & 3, uVar8 = *(uint *)(param_1 + 8U & 0xfffffffc),
     ((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) & 0x80) != 0)) {
    if (((param_2 == 0x20) || (param_2 == 0x40)) &&
       (uVar9 = param_1 + (param_4 >> 5) * 4 + 0xbc, uVar8 = uVar9 & 3,
       uVar9 = *(uint *)(uVar9 & 0xfffffffc),
       (1 << (param_4 & 0x1f) & (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20)) != 0)) {
      if (uVar6 == 0) {
        puVar11 = (uint *)(param_4 * 0x38 + iRam01ff8af4);
      }
      else {
        puVar11 = (uint *)(param_4 * 0x38 + uVar6);
      }
    }
    else {
      if (uVar6 == 0) {
        if (param_2 == 0x40) {
          uVar6 = param_1 + 0xbc + (param_4 >> 5) * 4;
          uVar9 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          puVar11 = (uint *)(param_4 * 0x38 + iRam01ff8af4);
          *(uint *)(param_1 + 0xbc + (param_4 >> 5) * 4) =
               uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20 | 1 << (param_4 & 0x1f);
        }
        else {
          puVar11 = (uint *)(param_1 + 0xf4);
        }
      }
      else {
        uVar6 = param_1 + 0xbc + (param_4 >> 5) * 4;
        uVar9 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        *(uint *)(param_1 + 0xbc + (param_4 >> 5) * 4) =
             uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20 | 1 << (param_4 & 0x1f);
        uVar6 = param_1 + 4U & 3;
        uVar9 = *(uint *)(param_1 + 4U & 0xfffffffc);
        uVar6 = (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) + 0x38;
        uVar9 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        puVar11 = (uint *)(param_4 * 0x38 + (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20));
      }
      *puVar11 = 0;
      iVar4 = iRam01ff8af8;
      uVar6 = param_1 + 0xd8U & 3;
      uVar9 = *(uint *)(param_1 + 0xd8U & 0xfffffffc);
      uVar8 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      uVar6 = *(ushort *)(uVar8 + 4 + (uint)*(ushort *)(uVar8 + 10)) * param_4 +
              uVar8 + 4 + (uint)*(ushort *)(uVar8 + 10) + 4;
      uVar9 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      if ((*(ushort *)(uVar8 + (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) + 0x1e) & 0x20) !=
          0) {
        *puVar11 = *(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
                   *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20 | 0x20;
      }
      iVar5 = iRam01ff8afc;
      uVar9 = iVar4 + 0x94U & 3;
      uVar14 = *(uint *)(iVar4 + 0x94U & 0xfffffffc);
      uVar6 = iRam01ff8afc + ((int)(uint)*(ushort *)(param_3 + 0x1e) >> 6 & 7U) * 4;
      uVar8 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar12 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
      uVar6 = param_3 + 4U & 3;
      uVar8 = *(uint *)(param_3 + 4U & 0xfffffffc);
      puVar11[1] = (uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20) & ~uVar12 |
                   (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) & uVar12;
      uVar9 = iVar4 + 0x98U & 3;
      uVar13 = *(uint *)(iVar4 + 0x98U & 0xfffffffc);
      uVar8 = param_3 + 8U & 3;
      uVar14 = *(uint *)(param_3 + 8U & 0xfffffffc);
      uVar6 = iVar5 + ((int)(uint)*(ushort *)(param_3 + 0x1e) >> 9 & 7U) * 4;
      uVar12 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20;
      puVar11[2] = (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) & ~uVar6 |
                   (uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20) & uVar6;
      uVar6 = param_3 + 0x10U & 3;
      uVar9 = *(uint *)(param_3 + 0x10U & 0xfffffffc);
      uVar14 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      uVar6 = param_3 + 0xcU & 3;
      uVar8 = *(uint *)(param_3 + 0xcU & 0xfffffffc);
      uVar9 = iVar4 + 0x9cU & 3;
      uVar12 = *(uint *)(iVar4 + 0x9cU & 0xfffffffc);
      puVar11[3] = (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) & ~uVar14 |
                   (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) & uVar14;
      uVar6 = param_3 + 0x14U & 3;
      uVar9 = *(uint *)(param_3 + 0x14U & 0xfffffffc);
      puVar11[4] = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      puVar11[5] = (uint)*(ushort *)(param_3 + 0x1c);
      uVar2 = *(ushort *)(param_3 + 0x1e);
      if ((uVar2 & 1) != 0) {
        uVar6 = uVar2 & 2;
        bVar15 = (uVar2 & 2) != 0;
        if (bVar15) {
          uVar6 = *(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
                  *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20;
        }
        puVar7 = (undefined2 *)(param_3 + 0x2c);
        if (bVar15) {
          *puVar11 = uVar6 | 1;
        }
        else {
          puVar11[6] = *(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                       *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20;
          uVar6 = param_3 + 0x30U & 3;
          uVar9 = *(uint *)(param_3 + 0x30U & 0xfffffffc);
          puVar7 = (undefined2 *)(param_3 + 0x34);
          puVar11[7] = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
        }
        if ((*(ushort *)(param_3 + 0x1e) & 4) == 0) {
          *(undefined2 *)(puVar11 + 8) = *puVar7;
          puVar1 = puVar7 + 1;
          puVar7 = puVar7 + 2;
          *(undefined2 *)((int)puVar11 + 0x22) = *puVar1;
        }
        else {
          *puVar11 = *(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
                     *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20 | 2;
        }
        if ((*(ushort *)(param_3 + 0x1e) & 8) == 0) {
          puVar11[9] = *(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                       *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20;
          uVar6 = (uint)(puVar7 + 2) & 3;
          uVar9 = *(uint *)((uint)(puVar7 + 2) & 0xfffffffc);
          puVar11[10] = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
        }
        else {
          *puVar11 = *(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
                     *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20 | 4;
        }
        *puVar11 = *(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
                   *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20 | 8;
      }
      uVar6 = param_1 + 4U & 3;
      uVar9 = *(uint *)(param_1 + 4U & 0xfffffffc);
      uVar9 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      uVar6 = uVar9 + 8 & 3;
      uVar8 = *(uint *)(uVar9 + 8 & 0xfffffffc);
      uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
      if ((uVar6 != 0) &&
         (uVar8 = uVar9 + (param_4 >> 5) * 4 + 0x3c, uVar12 = uVar8 & 3,
         uVar8 = *(uint *)(uVar8 & 0xfffffffc),
         (1 << (param_4 & 0x1f) & (uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20)) != 0)) {
        uVar8 = uVar9 + 0xc & 3;
        uVar9 = *(uint *)(uVar9 + 0xc & 0xfffffffc);
        (*(code *)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20))(puVar11,uVar6,param_4);
      }
      if (((*(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
           *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20) & 0x18) != 0) {
        *(undefined2 *)(puVar11 + 0xb) = *(undefined2 *)(param_3 + 0x20);
        *(undefined2 *)((int)puVar11 + 0x2e) = *(undefined2 *)(param_3 + 0x22);
        uVar6 = param_3 + 0x24U & 3;
        uVar9 = *(uint *)(param_3 + 0x24U & 0xfffffffc);
        puVar11[0xc] = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
        uVar6 = param_3 + 0x28U & 3;
        uVar9 = *(uint *)(param_3 + 0x28U & 0xfffffffc);
        puVar11[0xd] = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      }
    }
  }
  else {
    puVar11 = (uint *)(param_4 * 0x38 + uVar6);
  }
  *(uint **)(param_1 + 0xb0) = puVar11;
  uVar6 = param_1 + 0xb0U & 3;
  uVar9 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  uVar8 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
  uVar6 = uVar8 + 0xc & 3;
  uVar9 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
  uVar6 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
  if ((uVar6 & 0x1f0000) == 0) {
    uVar6 = param_1 + 8U & 3;
    uVar9 = *(uint *)(param_1 + 8U & 0xfffffffc);
    *(uint *)(param_1 + 8) = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20 | 2;
  }
  else {
    if (((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
         *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) & 0x20) != 0) {
      *(uint *)(uVar8 + 0xc) = uVar6 & 0xffe0ffff;
    }
    uVar6 = param_1 + 8U & 3;
    uVar9 = *(uint *)(param_1 + 8U & 0xfffffffc);
    *(uint *)(param_1 + 8) = (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) & 0xfffffffd;
    uVar6 = param_1 + 8U & 3;
    uVar9 = *(uint *)(param_1 + 8U & 0xfffffffc);
    if (((uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) & 0x100) == 0) {
      uVar6 = uVar8 + 4 & 3;
      uVar9 = *(uint *)(uVar8 + 4 & 0xfffffffc);
      local_34 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      uVar6 = uVar8 + 8 & 3;
      uVar9 = *(uint *)(uVar8 + 8 & 0xfffffffc);
      local_30 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      uVar6 = uVar8 + 0xc & 3;
      uVar9 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
      local_2c = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      local_28 = uRam01ff8b04;
      uVar6 = uVar8 + 0x10 & 3;
      uVar9 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
      local_24 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      uVar6 = uVar8 + 0x14 & 3;
      uVar9 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
      local_20 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      func_01ff9048(uRam01ff8b00,&local_34,6,local_20,uRam01ff8b00);
      if (((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
           *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) & 0x18) != 0) {
        uVar6 = param_1 + 0xf0U & 3;
        uVar9 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
        (*(code *)(uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20))(uVar8);
      }
    }
  }
  if (uVar10 != 3) {
    return;
  }
  uVar6 = param_1 + 8U & 3;
  uVar9 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *(uint *)(param_1 + 8) = (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) & 0xffffffbf;
  uVar6 = param_1 + 0x1cU & 3;
  uVar9 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  (*(code *)(uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20))(param_1);
  return;
}

