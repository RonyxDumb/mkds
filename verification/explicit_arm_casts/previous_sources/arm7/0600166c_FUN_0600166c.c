/* Decompiled C draft; module arm7; ROM address 0600166c. No matching claim. */
#include "types.h"
#include "deps/0600166c_FUN_0600166c.h"

void FUN_0600166c(int param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ushort *puVar12;
  uint uVar13;
  uint uVar15;
  bool bVar16;
  undefined8 uVar17;
  int local_38;
  short *psVar14;
  
  iVar3 = FUN_06000680();
  uVar13 = iVar3 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
  uVar4 = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
  uVar13 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar15 = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
  uVar13 = uVar15 + 0xc & 3;
  uVar4 = *(uint *)(uVar15 + 0xc & 0xfffffffc);
  if (uVar4 >> uVar13 * 8 != 0 || uVar4 << uVar13 * -8 + 0x20 != 0) {
    if ((*(short *)(param_1 + 0x12) == 0) &&
       ((*(short *)(uVar15 + 0x3a) != 1 || (*(short *)(param_1 + 0x10) == 0)))) {
      if (*(short *)(uVar15 + 0x3a) != 0) {
        *(undefined2 *)(uVar15 + 0x3a) = 0;
      }
      uVar13 = uVar15 + (uint)*(ushort *)(uVar15 + 0x44) * 4 + 0x48;
      uVar4 = uVar13 & 3;
      uVar13 = *(uint *)(uVar13 & 0xfffffffc);
      psVar14 = (short *)(uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20);
      uVar13 = (uint)*(ushort *)(param_1 + 0x16) * (uint)*(ushort *)(param_1 + 0x14) + 10;
      if (*(ushort *)(uVar15 + 0x46) < uVar13) {
        uVar13 = (uint)*(ushort *)(uVar15 + 0x46);
      }
      thunk_FUN_037fb390(param_1 + 0x10,psVar14,uVar13);
      FUN_060015d4(param_1,*psVar14,*(undefined2 *)(uVar15 + 0x92));
      uVar17 = thunk_FUN_037fa278();
      iVar3 = (int)((ulonglong)uVar17 >> 0x20);
      uVar13 = (uint)uVar17 | 1;
      puVar12 = (ushort *)(psVar14 + 5);
      local_38 = 0;
      for (uVar2 = 0; uVar2 < (ushort)psVar14[2]; uVar2 = uVar2 + 1) {
        uVar4 = (uint)puVar12[2];
        if ((uVar4 != 0) && (uVar4 < 0x10)) {
          uVar8 = (uint)*puVar12;
          if ((uVar8 < 2) || (uVar8 == DAT_06001a74)) {
            if (uVar8 == 0) {
              iVar7 = uVar15 + uVar4 * 8;
              uVar4 = iVar7 + 0x734;
              uVar8 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar9 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
              uVar4 = iVar7 + 0x738;
              uVar8 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar11 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
              uVar4 = uVar15 + 0x7b4 & 3;
              uVar8 = *(uint *)(uVar15 + 0x7b4 & 0xfffffffc);
              uVar10 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
              uVar4 = uVar15 + 0x7b8 & 3;
              uVar8 = *(uint *)(uVar15 + 0x7b8 & 0xfffffffc);
              uVar4 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
              if ((uVar4 != 0 || uVar10 != 0) && (uVar11 != 0 || uVar9 != 0)) {
                uVar8 = iVar3 - (uVar11 + (uVar13 < uVar9));
                bVar16 = uVar4 <= uVar8;
                if (uVar8 == uVar4) {
                  bVar16 = uVar10 <= uVar13 - uVar9;
                }
                if (bVar16 && (uVar8 != uVar4 || uVar13 - uVar9 != uVar10)) {
                  puVar5 = (undefined4 *)FUN_06000000();
                  iVar7 = uVar15 + (uint)puVar12[2] * 8;
                  *(undefined4 *)(iVar7 + 0x734) = 0;
                  *(undefined4 *)(iVar7 + 0x738) = 0;
                  iVar7 = local_38;
                  if (puVar5 != (undefined4 *)0x0) {
                    *puVar5 = 0x25;
                    puVar5[1] = 1 << (puVar12[2] & 0xff);
                    puVar5[2] = DAT_06001a78;
                    iVar7 = FUN_06000680();
                    iVar7 = thunk_FUN_037f9854(iVar7 + 0x88,puVar5,0);
                  }
                  if (iVar7 == 0) {
                    puVar6 = (undefined2 *)thunk_FUN_03807424();
                    *puVar6 = 0x80;
                    puVar6[1] = 8;
                    puVar6[2] = 0x16;
                    puVar6[3] = 0x25;
                    thunk_FUN_038074cc();
                  }
                }
              }
            }
          }
          else {
            *puVar12 = *puVar12 - 2;
            *(ushort *)(uVar15 + 0x86) =
                 *(ushort *)(uVar15 + 0x86) | (ushort)(1 << (puVar12[2] & 0xff));
            iVar7 = uVar15 + (uint)puVar12[2] * 8;
            *(uint *)(iVar7 + 0x734) = uVar13;
            *(int *)(iVar7 + 0x738) = iVar3;
            if (*puVar12 != 0) {
              FUN_06006ab0(puVar12[2],puVar12[4],puVar12 + 5,*puVar12,psVar14);
            }
          }
        }
        puVar12 = (ushort *)((int)puVar12 + (uint)(ushort)psVar14[3]);
      }
      FUN_06006f18(0,*psVar14);
      sVar1 = *psVar14;
      puVar6 = (undefined2 *)thunk_FUN_03807424();
      *puVar6 = 0xe;
      puVar6[1] = 0;
      puVar6[2] = 0xb;
      *(short **)(puVar6 + 4) = psVar14;
      thunk_FUN_038074cc();
      thunk_FUN_03807480();
      *(ushort *)(uVar15 + 0x44) = *(ushort *)(uVar15 + 0x44) ^ 1;
      thunk_FUN_037faf70();
      if (sVar1 == 0) {
        *(short *)(uVar15 + 0x36) = *(short *)(uVar15 + 0x36) + -1;
      }
      if (0 < *(short *)(uVar15 + 0x38)) {
        *(short *)(uVar15 + 0x38) = *(short *)(uVar15 + 0x38) + -1;
      }
      if ((*(short *)(uVar15 + 0x36) < 1) || (*(short *)(uVar15 + 0x38) < 1)) {
        bVar16 = false;
      }
      else {
        bVar16 = true;
      }
      thunk_FUN_037faf84();
      if (bVar16) {
        uVar13 = DAT_06001a74;
        if (sVar1 != 0) {
          uVar13 = (uint)*(ushort *)(param_1 + 0x10);
        }
        puVar5 = (undefined4 *)FUN_06000000();
        iVar3 = FUN_06000680();
        if (puVar5 == (undefined4 *)0x0) {
          iVar7 = 0;
        }
        else {
          *puVar5 = 0x29;
          puVar5[1] = uVar13;
          iVar7 = thunk_FUN_037f9854(iVar3 + 0x88,puVar5,0);
        }
        if ((iVar7 == 0) &&
           (uVar13 = iVar3 + 0x154cU & 3, uVar4 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc),
           uVar4 >> uVar13 * 8 != 0 || uVar4 << uVar13 * -8 + 0x20 != 0)) {
          puVar6 = (undefined2 *)thunk_FUN_03807424();
          *puVar6 = 0x80;
          puVar6[1] = 8;
          puVar6[2] = 0x16;
          puVar6[3] = 0x29;
          thunk_FUN_038074cc();
        }
      }
    }
    else {
      puVar5 = (undefined4 *)FUN_06000000();
      if (puVar5 == (undefined4 *)0x0) {
        iVar3 = 0;
      }
      else {
        *puVar5 = 0x2b;
        puVar5[1] = (uint)*(ushort *)(uVar15 + 0x3c);
        iVar3 = FUN_06000680();
        iVar3 = thunk_FUN_037f9854(iVar3 + 0x88,puVar5,0);
      }
      if (iVar3 == 0) {
        puVar6 = (undefined2 *)thunk_FUN_03807424();
        *puVar6 = 0x80;
        puVar6[1] = 8;
        puVar6[2] = 0x16;
        puVar6[3] = 0x2b;
        thunk_FUN_038074cc();
      }
      else {
        *(undefined2 *)(uVar15 + 0x3a) = 1;
      }
    }
  }
  return;
}

