/* Decompiled C draft; module arm7; ROM address 06016b4c. No matching claim. */
#include "types.h"
#include "deps/06016b4c_FUN_06016b4c.h"

void FUN_06016b4c(int param_1,int *param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  uint uVar10;
  undefined2 *puVar12;
  ushort *puVar13;
  uint local_60;
  int local_50;
  undefined2 local_4c;
  undefined2 local_4a;
  short local_48;
  undefined2 local_46;
  undefined2 local_44;
  uint uVar11;
  
  uVar6 = *(uint *)(DAT_06016f40 & 0xfffffffc) >> (DAT_06016f40 & 3) * 8 |
          *(uint *)(DAT_06016f40 & 0xfffffffc) << (DAT_06016f40 & 3) * -8 + 0x20;
  puVar12 = (undefined2 *)(uVar6 + DAT_06016f44);
  if (*(short *)(uVar6 + 0x404) == 0x13) {
    uVar6 = (uint)(puVar12 + 0xe) & 3;
    uVar10 = *(uint *)((uint)(puVar12 + 0xe) & 0xfffffffc);
    uVar11 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
    uVar6 = (uint)(puVar12 + 0xc) & 3;
    uVar10 = *(uint *)((uint)(puVar12 + 0xc) & 0xfffffffc);
    iVar8 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) + 0x4e;
    for (uVar6 = 0; uVar10 = (uint)(puVar12 + 0xc) & 3,
        uVar4 = *(uint *)((uint)(puVar12 + 0xc) & 0xfffffffc),
        uVar6 < *(ushort *)((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) + 0x4c);
        uVar6 = uVar6 + 1) {
      iVar3 = FUN_0600a578(iVar8,param_1 + 0x24);
      if (iVar3 != 0) {
        *(ushort *)(uVar11 + 6) = *(ushort *)(uVar11 + 6) | (ushort)(1 << (uVar6 & 0xff));
        return;
      }
      iVar8 = iVar8 + 6;
    }
    puVar9 = (ushort *)(uVar11 + 10);
    for (uVar6 = 0; uVar6 < *(ushort *)(uVar11 + 8); uVar6 = uVar6 + 1) {
      iVar8 = FUN_0600a578(param_1 + 0x24,puVar9 + 2);
      if (iVar8 != 0) {
        return;
      }
      puVar9 = puVar9 + *puVar9;
    }
    thunk_FUN_037fb218(0,puVar9,0x40);
    uVar2 = *(ushort *)(param_1 + 6);
    if (0xc < uVar2) {
      if (param_2 == (int *)0x0) {
        thunk_FUN_037fb24c(0,&local_50,0x2c);
        local_50 = param_1 + 0x38;
        local_48 = uVar2 - 0xc;
        local_46 = 3;
        local_44 = 0x38;
        local_4c = *(undefined2 *)(param_1 + 8);
        local_4a = *(undefined2 *)(param_1 + 0x36);
        FUN_060161b4(&local_50);
        param_2 = &local_50;
      }
      uVar6 = (uint)(param_2 + 10) & 3;
      uVar10 = *(uint *)((uint)(param_2 + 10) & 0xfffffffc);
      uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
      if (uVar6 == 0) {
        *puVar9 = (ushort)(*(ushort *)((int)param_2 + 0x1a) + 0x41 >> 1);
      }
      else {
        sVar1 = FUN_060096c4(uVar6 + 1);
        puVar9[0x1e] = sVar1 - 8;
        *puVar9 = (ushort)(puVar9[0x1e] + 0x41 >> 1);
      }
      if (((*(ushort *)((int)param_2 + 10) & 1) == 1) &&
         (*puVar9 <=
          *(ushort *)
           ((*(uint *)(DAT_06016f40 & 0xfffffffc) >> (DAT_06016f40 & 3) * 8 |
            *(uint *)(DAT_06016f40 & 0xfffffffc) << (DAT_06016f40 & 3) * -8 + 0x20) + 0x408))) {
        puVar9[0x16] = *(ushort *)(param_1 + 0x36);
        FUN_0600a954(puVar9 + 2,param_1 + 0x24);
        puVar9[0x19] = *(ushort *)(param_1 + 0x34);
        puVar9[1] = *(ushort *)(param_1 + 0x12) & 0xff;
        uVar6 = (uint)(param_2 + 10) & 3;
        uVar10 = *(uint *)((uint)(param_2 + 10) & 0xfffffffc);
        if (uVar10 >> uVar6 * 8 == 0 && uVar10 << uVar6 * -8 + 0x20 == 0) {
          puVar9[0x1f] = *(ushort *)(param_2 + 6);
          if ((short)param_2[6] != 0) {
            uVar10 = param_1 + 0x38;
            puVar13 = puVar9 + 0x20;
            uVar6 = 0;
            local_60 = 0;
            while (uVar6 < *(ushort *)(param_2 + 6)) {
              uVar4 = FUN_060096c4(uVar10);
              iVar8 = FUN_060096c4(uVar10 + 1);
              if ((uVar4 < 7) ||
                 (uVar4 = (uint)(param_2 + 10) & 3,
                 uVar7 = *(uint *)((uint)(param_2 + 10) & 0xfffffffc),
                 uVar10 == (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20))) {
                uVar10 = uVar10 + iVar8 + 2;
              }
              else {
                for (uVar4 = local_60; uVar4 < iVar8 + 2U; uVar4 = uVar4 + 1) {
                  uVar5 = FUN_060096c4(uVar10);
                  FUN_060096e4(puVar13,uVar5);
                  puVar13 = (ushort *)((int)puVar13 + 1);
                  uVar10 = uVar10 + 1;
                }
                uVar6 = uVar6 + 1;
              }
            }
          }
        }
        else {
          for (uVar6 = 0; uVar6 < puVar9[0x1e]; uVar6 = uVar6 + 1) {
            uVar10 = (uint)(param_2 + 10) & 3;
            uVar4 = *(uint *)((uint)(param_2 + 10) & 0xfffffffc);
            uVar5 = FUN_060096c4((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) + 10 + uVar6);
            FUN_060096e4((int)puVar9 + uVar6 + 0x40,uVar5);
          }
        }
        uVar6 = (uint)(param_2 + 7) & 3;
        uVar10 = *(uint *)((uint)(param_2 + 7) & 0xfffffffc);
        uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
        if (uVar6 == 0) {
          uVar6 = 0;
          puVar9[5] = 0;
          do {
            FUN_060096e4((int)puVar9 + uVar6 + 0xc,0);
            uVar6 = uVar6 + 1;
          } while (uVar6 < 0x20);
        }
        else {
          uVar2 = FUN_060096c4(uVar6 + 1);
          puVar9[5] = uVar2;
          for (uVar6 = 0; uVar6 < puVar9[5]; uVar6 = uVar6 + 1) {
            uVar10 = (uint)(param_2 + 7) & 3;
            uVar4 = *(uint *)((uint)(param_2 + 7) & 0xfffffffc);
            uVar5 = FUN_060096c4((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) + 2 + uVar6);
            FUN_060096e4((int)puVar9 + uVar6 + 0xc,uVar5);
          }
        }
        puVar9[0x17] = *(ushort *)(param_2 + 5);
        puVar9[0x18] = *(ushort *)((int)param_2 + 0x16);
        puVar9[0x1b] = *(ushort *)((int)param_2 + 0x12);
        uVar6 = (uint)(param_2 + 8) & 3;
        uVar10 = *(uint *)((uint)(param_2 + 8) & 0xfffffffc);
        uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
        if (uVar6 != 0) {
          uVar2 = FUN_060096c4(uVar6 + 3);
          puVar9[0x1c] = uVar2;
        }
        uVar6 = (uint)(param_2 + 9) & 3;
        uVar10 = *(uint *)((uint)(param_2 + 9) & 0xfffffffc);
        uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
        if (uVar6 != 0) {
          uVar2 = FUN_060096c4(uVar6 + 3);
          puVar9[0x1a] = uVar2;
        }
        *(ushort *)(uVar11 + 2) = *(short *)(uVar11 + 2) + *puVar9;
        *(short *)(uVar11 + 8) = *(short *)(uVar11 + 8) + 1;
        puVar12[2] = puVar12[2] - *puVar9;
        if ((ushort)puVar12[2] < 0x20) {
          FUN_0600983c();
          *puVar12 = 0x15;
          FUN_06008a8c(2,0);
        }
      }
      else {
        FUN_0600a954(puVar9 + 2,DAT_06016f48);
      }
    }
  }
  return;
}

