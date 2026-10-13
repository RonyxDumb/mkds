/* Decompiled C draft; module arm7; ROM address 06004a9c. No matching claim. */
#include "types.h"
#include "deps/06004a9c_FUN_06004a9c.h"

undefined4 FUN_06004a9c(int param_1,int param_2,undefined2 *param_3)

{
  uint uVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar7;
  undefined2 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  short *psVar11;
  undefined2 uVar12;
  uint uVar13;
  uint uVar14;
  bool bVar16;
  int local_254;
  undefined1 auStack_230 [6];
  undefined1 auStack_22a [6];
  undefined1 auStack_224 [512];
  uint uVar6;
  uint uVar15;
  
  iVar5 = FUN_06000680();
  uVar1 = iVar5 + 0x154cU & 3;
  uVar14 = *(uint *)(iVar5 + 0x154cU & 0xfffffffc);
  uVar15 = uVar14 >> uVar1 * 8 | uVar14 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 4U & 3;
  uVar14 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar14 = uVar14 >> uVar1 * 8 | uVar14 << uVar1 * -8 + 0x20;
  uVar1 = uVar14 & 0xffff;
  if (param_2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar13 = param_1 + 8U & 3;
    uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar4 = (ushort)(uVar6 >> uVar13 * 8) | (ushort)(uVar6 << uVar13 * -8 + 0x20);
  }
  uVar13 = 0;
  bVar16 = false;
  psVar11 = (short *)(*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
                     *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20);
  sVar2 = *psVar11;
  if ((sVar2 == 9) || (sVar2 == 7)) {
    psVar11 = psVar11 + 6;
    uVar14 = (uint)psVar11 & 3;
    uVar6 = *(uint *)((uint)psVar11 & 0xfffffffc);
    bVar16 = (uVar6 >> uVar14 * 8 | uVar6 << uVar14 * -8 + 0x20) == 1;
  }
  else {
    if ((sVar2 != 10) && (sVar2 != 8)) {
      if (param_2 == 0) {
        puVar8 = (undefined2 *)thunk_FUN_03807424();
        *puVar8 = 0xd;
        puVar8[1] = 3;
        puVar8[2] = 0;
        puVar8[3] = 0;
        puVar8[4] = (short)uVar14;
        puVar8[5] = 0;
        thunk_FUN_038074cc();
      }
      return 0;
    }
    uVar10 = thunk_FUN_037faf70();
    uVar9 = *(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
            *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20;
    uVar14 = uVar9 + 0xc;
    uVar6 = uVar14 & 3;
    uVar14 = *(uint *)(uVar14 & 0xfffffffc);
    if ((uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) == 1) {
      *(undefined4 *)(uVar9 + 0xc) = 0;
      bVar16 = true;
      thunk_FUN_037fabc0(uVar15 + 0xd0);
      FUN_06000154();
      psVar11 = (short *)(*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
                         *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20);
      if (*psVar11 == 10) {
        *psVar11 = 8;
      }
    }
    *(undefined2 *)
     ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
      *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x17e) = 0;
    *(undefined2 *)
     ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
      *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x86) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
      *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x14) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
      *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x10) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
      *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x1c) = 0;
    thunk_FUN_037faf84(uVar10);
  }
  psVar11 = (short *)(*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
                     *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20);
  sVar2 = *psVar11;
  if ((sVar2 == 10) || (sVar2 == 8)) {
    thunk_FUN_037fb390((int)psVar11 + DAT_06005058,auStack_230,6);
    for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
      iVar7 = FUN_060029f8(auStack_224,auStack_230,3);
      uVar3 = *(ushort *)(iVar7 + 4);
      if (uVar3 < 8) {
        if (uVar3 < 7) {
          if ((1 < uVar3) || ((uVar3 != 0 && (uVar3 != 1)))) {
LAB_06004c70:
            if (param_2 == 0) {
              FUN_06004a50(5,uVar3,uVar1,0);
            }
            else {
              FUN_06004a04(5,uVar3,uVar1,0);
            }
            if (bVar16) {
              FUN_06006d24(1);
            }
            return 0;
          }
          break;
        }
      }
      else if (uVar3 != 0xc) goto LAB_06004c70;
    }
    uVar12 = 1;
    *(undefined2 *)
     ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
      *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0xbe) = 0;
    *(undefined2 *)
     (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
     *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) = 3;
    iVar5 = FUN_06002ca4(auStack_224,1);
    sVar2 = *(short *)(iVar5 + 4);
    if (sVar2 != 0) {
      if (param_2 == 0) {
        FUN_06004a50(0,sVar2,uVar1,1);
      }
      else {
        FUN_06004a04(0,sVar2,uVar1,1);
      }
      if (bVar16) {
        FUN_06006d24(1);
      }
      return 0;
    }
    iVar5 = FUN_0600210c(auStack_224);
    sVar2 = *(short *)(iVar5 + 4);
    if (sVar2 != 0) {
      if (param_2 == 0) {
        FUN_06004a50(DAT_0600505c,sVar2,uVar1,1);
      }
      else {
        FUN_06004a04(DAT_0600505c,sVar2,uVar1,1);
      }
      if (bVar16) {
        FUN_06006d24(1);
      }
      return 0;
    }
    *(undefined2 *)
     (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
     *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) = 2;
    if (param_2 == 1) {
      puVar8 = (undefined2 *)thunk_FUN_03807424();
      *puVar8 = 0xc;
      puVar8[1] = 0;
      puVar8[4] = 9;
      puVar8[6] = uVar4;
      puVar8[5] = *(undefined2 *)
                   ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
                    *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x184);
      *(undefined2 *)
       ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
        *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x18e) = 0;
      *(undefined2 *)
       ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
        *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 400) = 0;
      thunk_FUN_038074cc();
    }
    if (bVar16) {
      FUN_06006d24(1);
    }
  }
  else {
    for (uVar14 = 1; uVar12 = (undefined2)uVar13, (int)uVar14 < 0x10; uVar14 = uVar14 + 1) {
      uVar9 = *(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
              *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20;
      uVar6 = 1 << (uVar14 & 0xff);
      if ((uVar6 & *(ushort *)(uVar9 + 0x17e) & uVar1) != 0) {
        thunk_FUN_037fb390((uVar14 - 1) * 6 + uVar9 + 0x124,auStack_22a,6);
        for (local_254 = 0; local_254 < 2; local_254 = local_254 + 1) {
          iVar5 = FUN_060029f8(auStack_224,auStack_22a,3);
          sVar2 = *(short *)(iVar5 + 4);
          if (sVar2 == 0) break;
          if ((sVar2 != 7) && (sVar2 != 0xc)) {
            if (param_2 == 0) {
              FUN_06004a50(5,sVar2,uVar1,uVar13);
            }
            else {
              FUN_06004a04(5,sVar2,uVar1,uVar13);
            }
            if (bVar16) {
              FUN_06006d24(1);
            }
            return 0;
          }
        }
        uVar10 = thunk_FUN_037faf70();
        uVar9 = *(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
                *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20;
        uVar3 = *(ushort *)(uVar9 + 0x17e);
        if ((uVar3 & uVar6) != 0) {
          uVar13 = uVar13 | 1 << (uVar14 & 0xff) & 0xffffU;
          *(ushort *)(uVar9 + 0x17e) = uVar3 & ~(ushort)uVar6;
          uVar9 = *(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
                  *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20;
          *(ushort *)(uVar9 + 0x86) = *(ushort *)(uVar9 + 0x86) & ~(ushort)uVar6;
          iVar5 = (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
                  *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) +
                  (uVar14 & 0xffff) * 8;
          *(undefined4 *)(iVar5 + 0x734) = 0;
          *(undefined4 *)(iVar5 + 0x738) = 0;
          iVar5 = uVar14 * 6;
          *(undefined1 *)
           ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
            *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + iVar5 + 0x11e) = 0;
          *(undefined1 *)
           ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
            *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + iVar5 + 0x11f) = 0;
          *(undefined1 *)
           ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
            *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + iVar5 + 0x120) = 0;
          *(undefined1 *)
           ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
            *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + iVar5 + 0x121) = 0;
          *(undefined1 *)
           ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
            *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + iVar5 + 0x122) = 0;
          *(undefined1 *)
           ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
            *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + iVar5 + 0x123) = 0;
          if (param_2 == 1) {
            puVar8 = (undefined2 *)thunk_FUN_03807424();
            *puVar8 = 8;
            puVar8[1] = 0;
            puVar8[4] = 9;
            puVar8[9] = uVar4;
            puVar8[8] = (short)uVar14;
            thunk_FUN_037fb390(auStack_22a,puVar8 + 5,6);
            thunk_FUN_038074cc(puVar8);
          }
          if (bVar16) {
            FUN_06006d24(uVar6 & 0xffff);
          }
        }
        thunk_FUN_037faf84(uVar10);
      }
    }
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = uVar12;
  }
  return 1;
}

