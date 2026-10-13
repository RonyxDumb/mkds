/* Decompiled C draft; module arm7; ROM address 06007394. No matching claim. */
#include "types.h"
#include "deps/06007394_FUN_06007394.h"

/* WARNING: Removing unreachable block (ram,0x06007458) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4
FUN_06007394(uint param_1,uint param_2,uint param_3,ushort *param_4,uint *param_5,int *param_6)

{
  uint uVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  short *psVar9;
  int iVar10;
  uint uVar11;
  short *psVar12;
  int iVar13;
  uint uVar14;
  undefined2 *puVar15;
  ushort uVar16;
  int iVar17;
  ushort *puVar18;
  ushort *puVar19;
  ushort *puVar20;
  ushort *puVar21;
  uint uVar22;
  undefined2 *puVar23;
  ushort *puVar24;
  bool bVar25;
  uint uStack_7c;
  uint uStack_70;
  uint uStack_68;
  uint uStack_60;
  short *psStack_5c;
  ushort *puStack_58;
  undefined2 *puStack_54;
  int iStack_3c;
  int iStack_34;
  
  iVar7 = FUN_06000680();
  uVar1 = iVar7 + 0x154cU & 3;
  uVar8 = *(uint *)(iVar7 + 0x154cU & 0xfffffffc);
  uVar8 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  psVar9 = (short *)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
  uVar22 = (uint)(ushort)psVar9[199];
  uVar1 = (uint)(psVar9 + 0x28) & 3;
  uVar8 = *(uint *)((uint)(psVar9 + 0x28) & 0xfffffffc);
  puVar19 = (ushort *)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
  if (0xf < (ushort)psVar9[0xc2]) {
    return 1;
  }
  if (*psVar9 == 9) {
    bVar4 = true;
  }
  else {
    if (*psVar9 != 10) {
      return 1;
    }
    bVar4 = false;
  }
  uStack_70 = 0;
  *param_4 = 0;
  *param_5 = 0;
  iVar7 = 0;
  *param_6 = 0;
  uStack_68 = param_3;
  if (bVar4) {
    if (psVar9[0x49] != 0) {
      uStack_68 = param_2;
    }
    bVar3 = psVar9[0x49] == 0;
  }
  else {
    bVar3 = false;
  }
  uStack_7c = 0;
  bVar5 = true;
  thunk_FUN_037f9a0c((int)psVar9 + DAT_060078a8);
  uVar1 = (uint)(psVar9 + 0x398) & 3;
  uVar8 = *(uint *)((uint)(psVar9 + 0x398) & 0xfffffffc);
  if ((uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) == 1) {
    thunk_FUN_037f999c((int)psVar9 + DAT_060078a8);
    return 1;
  }
  psVar9[0x398] = 1;
  psVar9[0x399] = 0;
  uStack_60 = 0;
  puVar24 = (ushort *)((int)psVar9 + DAT_060078ac);
  psStack_5c = (short *)((int)psVar9 + DAT_060078b0);
  iStack_3c = 2;
  iStack_34 = 0;
  while ((uStack_60 < 4 && (2 < (int)uVar22))) {
    puStack_54 = DAT_060078b4;
    puVar23 = (undefined2 *)(uint)*puVar24;
    puStack_58 = puVar24;
    while ((puVar23 != DAT_060078b4 && (2 < (int)uVar22))) {
      puVar18 = (ushort *)(psVar9 + (int)puVar23 * 0x10 + 0x17a);
      uVar1 = 1 << (puVar18[1] & 0xff);
      puVar15 = puVar23;
      if ((uStack_7c & uVar1) == 0) {
        uStack_7c = uStack_7c | uVar1;
        uVar8 = uStack_68 & puVar18[3];
        if ((!bVar3) || ((~(param_3 & param_1) & uVar8) == 0)) {
          bVar25 = (puVar18[1] & 8) != 0;
          if ((bVar4) && ((undefined2 *)(uVar8 | 1) != DAT_060078b4)) {
            bVar6 = true;
          }
          else {
            bVar6 = false;
          }
          if ((puVar18[7] & 1) == 1) {
            puVar18[7] = puVar18[7] + 1;
          }
          iVar10 = iStack_3c;
          if (!bVar25) {
            iVar10 = 0;
          }
          iVar17 = iStack_34;
          if (!bVar5) {
            iVar17 = 2;
          }
          iVar13 = iStack_3c;
          if (!bVar6) {
            iVar13 = 0;
          }
          if ((int)(iVar13 + (uint)puVar18[7] + iVar17 + iVar10) <= (int)uVar22) {
            puVar20 = puVar19;
            if (!bVar5) {
              puVar20 = puVar19 + 1;
              *puVar19 = 0;
              iVar7 = iVar7 + 2;
              uVar22 = uVar22 - 2;
              param_4 = puVar19;
            }
            *param_4 = *param_4 | (puVar18[1] & 0xf) << 8 | puVar18[7] >> 1 & 0xff;
            uVar14 = (uint)(puVar18 + 10) & 3;
            uVar11 = *(uint *)((uint)(puVar18 + 10) & 0xfffffffc);
            thunk_FUN_037fb230(uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20,puVar20);
            uVar14 = (uint)puVar18[7];
            puVar20 = (ushort *)((int)puVar20 + (uVar14 & 0xfffffffe));
            iVar7 = iVar7 + uVar14;
            uVar22 = uVar22 - uVar14;
            puVar21 = puVar20;
            if (bVar25) {
              if ((puVar18[8] & 1) == 0) {
                uVar16 = (ushort)((int)(uint)puVar18[8] >> 1);
              }
              else {
                uVar16 = psVar9[(uint)(ushort)psVar9[0xc2] * 8 + (puVar18[1] & 7) + 0xfa];
                psVar9[(uint)(ushort)psVar9[0xc2] * 8 + (puVar18[1] & 7) + 0xfa] = uVar16 + 1;
                puVar18[8] = uVar16 << 1;
              }
              puVar21 = puVar20 + 1;
              *puVar20 = (ushort)DAT_060078b8 & uVar16;
              iVar7 = iVar7 + 2;
              uVar22 = uVar22 - 2;
            }
            puVar19 = puVar21;
            if (bVar6) {
              *param_4 = *param_4 | 0x1000;
              puVar19 = puVar21 + 1;
              *puVar21 = (ushort)uVar8;
              iVar7 = iVar7 + 2;
              uVar22 = uVar22 - 2;
            }
            if (bVar5) {
              bVar5 = false;
            }
            if ((undefined2 *)(uint)puVar24[1] == puVar23) {
              puVar24[1] = (ushort)puStack_54;
            }
            *puStack_58 = *puVar18;
            *puVar18 = (ushort)DAT_060078b4;
            puVar15 = (undefined2 *)(uint)(ushort)psStack_5c[1];
            psVar12 = DAT_060078b4;
            if (puVar15 == DAT_060078b4) {
              psVar12 = psStack_5c;
            }
            sVar2 = (short)puVar23;
            if (puVar15 == DAT_060078b4) {
              *psVar12 = sVar2;
            }
            else {
              psVar9[(int)puVar15 * 0x10 + 0x17a] = sVar2;
            }
            psStack_5c[1] = sVar2;
            puVar18[5] = (ushort)uVar8;
            uStack_7c = uStack_7c & ~uVar1;
            uStack_70 = uStack_70 | puVar18[2];
            puVar15 = puStack_54;
            if (psVar9[0x4a] == 1) goto LAB_06007874;
          }
        }
      }
      puStack_54 = puVar15;
      if (puVar15 == DAT_060078b4) {
        puVar23 = (undefined2 *)(uint)*puVar24;
        puStack_58 = puVar24;
      }
      else {
        puVar23 = (undefined2 *)(uint)(ushort)psVar9[(int)puVar15 * 0x10 + 0x17a];
        puStack_58 = (ushort *)(psVar9 + (int)puVar15 * 0x10 + 0x17a);
      }
    }
    puVar24 = puVar24 + 2;
    psStack_5c = psStack_5c + 2;
    uStack_60 = uStack_60 + 1;
  }
LAB_06007874:
  *param_5 = uStack_70;
  *param_6 = iVar7;
  thunk_FUN_037f999c((int)psVar9 + DAT_060078a8);
  return 0;
}

