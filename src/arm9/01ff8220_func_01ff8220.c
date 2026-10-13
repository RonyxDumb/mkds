/* Decompiled C draft; module arm9; ROM address 01ff8220. No matching claim. */
#include "types.h"
#include "deps/01ff8220_func_01ff8220.h"

void func_01ff8220(int *param_1,int param_2)

{
  ushort *puVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ushort *puVar12;
  ushort *puVar13;
  uint *puVar14;
  int iVar15;
  bool bVar16;
  uint local_38;
  uint local_30;
  uint uStack_2c;
  uint local_28;
  
  bVar2 = *(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 1);
  uVar11 = (uint)bVar2;
  iVar15 = 4;
  *(byte *)((int)param_1 + 0xae) = bVar2;
  uVar9 = (uint)(param_1 + 2) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  param_1[2] = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20 | 0x10;
  uVar9 = (uint)(param_1 + 2) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar9 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
  if ((uVar9 & 0x400) != 0) {
    if ((param_2 == 0x40) || (param_2 == 0x60)) {
      iVar15 = 5;
    }
    if (((param_2 == 0x20) || (param_2 == 0x60)) && (iVar15 = iVar15 + 1, (uVar9 & 0x100) == 0)) {
      local_30 = (uint)*(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                                 *(uint *)((uint)param_1 & 0xfffffffc) <<
                                 ((uint)param_1 & 3) * -8 + 0x20) + 4);
      func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_30),1);
    }
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + iVar15;
    return;
  }
  if ((param_2 == 0x40) || (param_2 == 0x60)) {
    uVar9 = 0;
    if (param_2 == 0x40) {
      uVar9 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
              *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    }
    iVar15 = 5;
    if (param_2 == 0x40) {
      bVar2 = *(byte *)(uVar9 + 4);
    }
    else {
      bVar2 = *(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                       5);
    }
    uStack_2c = (uint)bVar2;
    uVar9 = (uint)(param_1 + 2) & 3;
    uVar7 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    if (((uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) & 0x100) == 0) {
      func_01ff9048(0x14,(undefined4)(uintptr_t)(&uStack_2c),1);
    }
  }
  param_1[0x2d] = (int)(param_1 + 0x4b);
  uVar9 = (uint)(param_1 + 9) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
  if (uVar7 >> uVar9 * 8 == 0 && uVar7 << uVar9 * -8 + 0x20 == 0) {
    cVar3 = '\0';
  }
  else {
    cVar3 = *(char *)((int)param_1 + 0x92);
  }
  uVar9 = (uint)(param_1 + 1) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar9 = (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) + 0x34;
  uVar7 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar9 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
  if (uVar9 == 0) {
    puVar14 = (uint *)(param_1 + 0x4b);
    bVar16 = false;
  }
  else {
    puVar14 = (uint *)(uVar11 * 0x58 + uVar9);
    uVar9 = (uint)(param_1 + 2) & 3;
    uVar7 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    bVar16 = ((uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) & 0x80) == 0;
  }
  if (!bVar16) {
    *puVar14 = 0;
    uVar9 = (uint)(param_1 + 1) & 3;
    uVar7 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    uVar7 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
    uVar9 = uVar7 + 0x10;
    uVar10 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
    if ((uVar9 == 0) ||
       (uVar7 = uVar7 + 0x14, uVar10 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
       iVar8 = (*(code *)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20))(puVar14,uVar9,uVar11),
       iVar8 == 0)) {
      uVar9 = (uint)(param_1 + 0x35) & 3;
      uVar7 = *(uint *)((uint)(param_1 + 0x35) & 0xfffffffc);
      uVar10 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
      uVar9 = *(ushort *)(uVar10 + *(ushort *)(uVar10 + 6)) * uVar11 +
              uVar10 + *(ushort *)(uVar10 + 6) + 4;
      uVar7 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar9 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
      puVar12 = (ushort *)(uVar10 + uVar9);
      puVar13 = puVar12 + 2;
      if ((*(ushort *)(uVar10 + uVar9) & 1) == 0) {
        puVar14[0x13] =
             *(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
             *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20;
        uVar9 = (uint)(puVar12 + 4) & 3;
        uVar7 = *(uint *)((uint)(puVar12 + 4) & 0xfffffffc);
        puVar14[0x14] = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
        uVar9 = (uint)(puVar12 + 6) & 3;
        uVar7 = *(uint *)((uint)(puVar12 + 6) & 0xfffffffc);
        puVar13 = puVar12 + 8;
        puVar14[0x15] = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
      }
      else {
        *puVar14 = *(uint *)((uint)puVar14 & 0xfffffffc) >> ((uint)puVar14 & 3) * 8 |
                   *(uint *)((uint)puVar14 & 0xfffffffc) << ((uint)puVar14 & 3) * -8 + 0x20 | 4;
      }
      uVar4 = *puVar12;
      if ((uVar4 & 2) == 0) {
        if ((uVar4 & 8) == 0) {
          puVar14[10] = (int)(short)puVar12[1];
          puVar14[0xb] = (int)(short)*puVar13;
          puVar14[0xc] = (int)(short)puVar13[1];
          puVar14[0xd] = (int)(short)puVar13[2];
          puVar14[0xe] = (int)(short)puVar13[3];
          puVar14[0xf] = (int)(short)puVar13[4];
          puVar14[0x10] = (int)(short)puVar13[5];
          puVar14[0x11] = (int)(short)puVar13[6];
          puVar1 = puVar13 + 7;
          puVar13 = puVar13 + 8;
          puVar14[0x12] = (int)(short)*puVar1;
        }
        else {
          iVar8 = (int)(uVar4 & 0xf0) >> 4;
          local_38 = (uint)(short)puVar13[1];
          uVar9 = (uint)(short)*puVar13;
          func_0214d32c(puVar14 + 10);
          iVar5 = iRam01ff85c0;
          puVar13 = puVar13 + 2;
          if ((*puVar12 & 0x100) == 0) {
            uVar7 = 0x1000;
          }
          else {
            uVar7 = 0xfffff000;
          }
          puVar14[iVar8 + 10] = uVar7;
          iVar6 = iRam01ff85c4;
          puVar14[*(byte *)(iVar5 + iVar8 * 4) + 10] = uVar9;
          puVar14[*(byte *)(iVar6 + iVar8 * 4) + 10] = local_38;
          if ((*puVar12 & 0x200) != 0) {
            local_38 = -local_38;
          }
          puVar14[*(byte *)(iRam01ff85c8 + iVar8 * 4) + 10] = local_38;
          if ((*puVar12 & 0x400) != 0) {
            uVar9 = -uVar9;
          }
          puVar14[*(byte *)(iRam01ff85cc + iVar8 * 4) + 10] = uVar9;
        }
      }
      else {
        *puVar14 = *(uint *)((uint)puVar14 & 0xfffffffc) >> ((uint)puVar14 & 3) * 8 |
                   *(uint *)((uint)puVar14 & 0xfffffffc) << ((uint)puVar14 & 3) * -8 + 0x20 | 2;
      }
      uVar9 = (uint)(param_1 + 0x3a) & 3;
      uVar7 = *(uint *)((uint)(param_1 + 0x3a) & 0xfffffffc);
      (*(code *)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20))
                (puVar14,puVar13,
                 *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20,*puVar12);
    }
  }
  param_1[0x2d] = (int)puVar14;
  uVar9 = (uint)(param_1 + 2) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  if (((uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) & 0x100) == 0) {
    uVar9 = (uint)(param_1 + 0x2d) & 3;
    uVar11 = *(uint *)((uint)(param_1 + 0x2d) & 0xfffffffc);
    uVar7 = (uint)(param_1 + 0x3b) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 0x3b) & 0xfffffffc);
    (*(code *)(uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20))
              (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20);
  }
  uVar9 = 0;
  param_1[0x2d] = 0;
  if (cVar3 == '\x03') {
    uVar9 = (uint)(param_1 + 2) & 3;
    uVar7 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    param_1[2] = (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) & 0xffffffbf;
    uVar9 = (uint)(param_1 + 9) & 3;
    uVar7 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
    (*(code *)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20))(param_1);
    uVar9 = (uint)(param_1 + 2) & 3;
    uVar7 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar9 = (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) & 0x40;
  }
  if ((((param_2 == 0x20) || (param_2 == 0x60)) && (iVar15 = iVar15 + 1, uVar9 == 0)) &&
     (uVar9 = (uint)(param_1 + 2) & 3, uVar7 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc),
     ((uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) & 0x100) == 0)) {
    local_28 = (uint)*(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                               *(uint *)((uint)param_1 & 0xfffffffc) <<
                               ((uint)param_1 & 3) * -8 + 0x20) + 4);
    func_01ff9048(0x13,(undefined4)(uintptr_t)(&local_28),1);
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + iVar15;
  return;
}

