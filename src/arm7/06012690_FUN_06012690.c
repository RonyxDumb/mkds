/* Decompiled C draft; module arm7; ROM address 06012690. No matching claim. */
#include "types.h"
#include "deps/06012690_FUN_06012690.h"

undefined4 FUN_06012690(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  bool bVar3;
  short sVar4;
  short sVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined2 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar12;
  ushort uVar13;
  int iVar14;
  uint uVar15;
  bool bVar16;
  undefined2 *puVar11;
  
  uVar9 = *(uint *)(DAT_06012b34 & 0xfffffffc) >> (DAT_06012b34 & 3) * 8 |
          *(uint *)(DAT_06012b34 & 0xfffffffc) << (DAT_06012b34 & 3) * -8 + 0x20;
  iVar14 = uVar9 + DAT_06012b38;
  uVar1 = *(ushort *)(uVar9 + 0x690);
  bVar3 = true;
  *(undefined2 *)(param_2 + 2) = 1;
  if (*(short *)(uVar9 + 0x32e) == 1) {
    if (*(short *)(iVar14 + 0x3c) == 0) {
      uVar7 = iVar14 + 0x44U & 3;
      uVar10 = *(uint *)(iVar14 + 0x44U & 0xfffffffc);
      puVar11 = (undefined2 *)(uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20);
      if ((*(ushort *)(param_1 + 0x10) & 0x8000) != 0) {
        if ((*(ushort *)(param_1 + 0x10) & 2) == 0) {
          *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(iVar14 + 0x94);
        }
        if ((*(ushort *)(param_1 + 0x10) & 4) == 0) {
          *(undefined2 *)(param_1 + 0x16) = *(undefined2 *)(iVar14 + 0xa0);
        }
        if ((*(ushort *)(param_1 + 0x10) & 8) == 0) {
          *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(iVar14 + 0x96);
        }
        if ((*(ushort *)(param_1 + 0x10) & 0x10) == 0) {
          *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(iVar14 + 0x9c);
          bVar3 = false;
        }
      }
      if (*(ushort *)(param_1 + 0x1c) < 0x205) {
        iVar12 = 0;
        for (uVar7 = 2; uVar7 != 0; uVar7 = (uVar7 << 0x11) >> 0x10) {
          if ((*(ushort *)(param_1 + 0x16) & uVar7) != 0) {
            iVar12 = iVar12 + 1;
          }
        }
        *(undefined2 *)(iVar14 + 0x94) = *(undefined2 *)(param_1 + 0x14);
        uVar13 = *(ushort *)(param_1 + 0x14);
        if ((uVar13 & 0x8000) == 0) {
          bVar16 = (uVar1 & 2) != 0;
          if (bVar16) {
            sVar5 = 2;
            sVar4 = 6;
          }
          else {
            sVar5 = 0;
            sVar4 = sVar5;
          }
          uVar10 = (uint)bVar16;
          uVar7 = uVar13 + uVar10;
          if (uVar10 + DAT_06012b40 < uVar7) {
            return 5;
          }
          *(short *)(param_1 + 0x14) = sVar5 + (short)uVar7 * 4 + 0xd0;
          puVar11[7] = sVar4 + 0xea;
        }
        else {
          *(ushort *)(param_1 + 0x14) = uVar13 & (ushort)DAT_06012b3c;
          uVar7 = *(ushort *)(param_1 + 0x14) - 0xd0 >> 2;
          puVar11[7] = 0xea;
          if (0x10000 < uVar7) {
            return 5;
          }
        }
        uVar15 = uVar7 + 9 & 0xfffffffe;
        uVar6 = FUN_06009138(uVar9 + 0x188,uVar15 * iVar12 + 0x1a);
        *(undefined4 *)(iVar14 + 0x90) = uVar6;
        uVar7 = iVar14 + 0x90U & 3;
        uVar10 = *(uint *)(iVar14 + 0x90U & 0xfffffffc);
        if (uVar10 >> uVar7 * 8 == 0 && uVar10 << uVar7 * -8 + 0x20 == 0) {
          uVar6 = 8;
        }
        else {
          *(undefined2 *)(iVar14 + 0x3c) = 1;
          *(short *)(iVar14 + 0x3e) = *(short *)(iVar14 + 0x3e) + 1;
          *(undefined2 *)(iVar14 + 0x96) = *(undefined2 *)(param_1 + 0x18);
          *(undefined2 *)(iVar14 + 0x98) = *(undefined2 *)(param_1 + 0x16);
          *(undefined2 *)(iVar14 + 0x9a) = 0;
          *(undefined2 *)(iVar14 + 0x9c) = *(undefined2 *)(param_1 + 0x1c);
          *(undefined2 *)(iVar14 + 0x9e) = *(undefined2 *)(param_1 + 0x12);
          *puVar11 = 0;
          puVar11[1] = *(undefined2 *)(param_1 + 0x16);
          puVar11[2] = 0;
          puVar11[4] = 0x14;
          puVar11[5] = *(short *)(param_1 + 0x1c) + 0x22;
          puVar11[6] = 0x228;
          puVar11[7] = (*(short *)(param_1 + 0x14) + 10) * (short)iVar12 + puVar11[7];
          FUN_0600a8d4(puVar11 + 8,(undefined2 *)(uintptr_t)(DAT_06012b44),(undefined2 *)(uintptr_t)(uVar9 + 0x3a8),(undefined2 *)(uintptr_t)(uVar9 + 0x324));
          if (((*(ushort *)(param_1 + 0x10) & 0x8000) == 0) ||
             ((ushort)puVar11[0x11] == DAT_06012b48)) {
            uVar13 = 0;
            puVar11[0x11] = (short)DAT_06012b48;
          }
          else {
            uVar13 = 0x4000;
          }
          puVar11[0x12] = *(undefined2 *)(param_1 + 0x14);
          puVar11[0x13] = *(undefined2 *)(param_1 + 0x16);
          puVar11[0x14] = *(undefined2 *)(param_1 + 0x1e);
          if ((bVar3) && (*(short *)(param_1 + 0x1c) != 0)) {
            uVar7 = param_1 + 0x20U & 3;
            uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
            FUN_06009788(puVar11 + 0x15,uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20);
          }
          if ((uVar1 & 4) != 0) {
            puVar8 = (undefined2 *)((int)puVar11 + *(ushort *)(param_1 + 0x1c) + 0x2d & 0xfffffffc);
            *puVar8 = (short)DAT_06012b4c;
            puVar8[1] = (short)DAT_06012b50;
          }
          uVar7 = iVar14 + 0x90U & 3;
          uVar10 = *(uint *)(iVar14 + 0x90U & 0xfffffffc);
          *(undefined2 *)((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0xc) = 0x184;
          uVar7 = iVar14 + 0x90U & 3;
          uVar10 = *(uint *)(iVar14 + 0x90U & 0xfffffffc);
          *(short *)((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0xe) =
               (short)(uVar15 * iVar12 + 0xb >> 1);
          uVar7 = iVar14 + 0x90U & 3;
          uVar10 = *(uint *)(iVar14 + 0x90U & 0xfffffffc);
          *(undefined2 *)((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0x10) =
               *(undefined2 *)(param_1 + 0x16);
          uVar7 = iVar14 + 0x90U & 3;
          uVar10 = *(uint *)(iVar14 + 0x90U & 0xfffffffc);
          *(short *)((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0x14) = (short)iVar12;
          uVar7 = iVar14 + 0x90U & 3;
          uVar10 = *(uint *)(iVar14 + 0x90U & 0xfffffffc);
          *(short *)((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0x16) = (short)uVar15;
          uVar7 = iVar14 + 0x90U & 3;
          uVar10 = *(uint *)(iVar14 + 0x90U & 0xfffffffc);
          *(undefined2 *)((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0x18) = 0;
          uVar7 = iVar14 + 0x90U & 3;
          uVar10 = *(uint *)(iVar14 + 0x90U & 0xfffffffc);
          puVar8 = (undefined2 *)((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0x1a);
          sVar5 = 1;
          uVar2 = (undefined2)DAT_06012b48;
          for (uVar7 = 2; uVar7 != 0; uVar7 = (uVar7 << 0x11) >> 0x10) {
            if ((*(ushort *)(param_1 + 0x16) & uVar7) != 0) {
              *puVar8 = uVar2;
              puVar8[1] = 0;
              puVar8[3] = 0;
              puVar8[2] = sVar5;
              puVar8 = (undefined2 *)((int)puVar8 + uVar15);
            }
            sVar5 = sVar5 + 1;
          }
          *DAT_06012b54 = *(undefined2 *)(param_1 + 0x14);
          *DAT_06012b58 = puVar11[7];
          uVar1 = *(ushort *)(param_1 + 0x1a);
          if (*(short *)(param_1 + 0x18) == 0) {
            sVar5 = thunk_FUN_03806d38((*(ushort *)(param_1 + 0x1c) + 0x22) * 4 +
                                       (uint)*(ushort *)(param_1 + 0x14) * iVar12 + 0x41a,10);
            thunk_FUN_037faf70();
            *DAT_06012b5c = sVar5;
            *DAT_06012b64 = (ushort)(((uint)puVar11 & DAT_06012b60) >> 1) | 0x8000 | uVar13;
            thunk_FUN_037faf84();
          }
          else {
            uVar6 = thunk_FUN_037faf70();
            iVar12 = thunk_FUN_03806d38((0x10000 - (uint)uVar1) + (uint)*DAT_06012b68 & DAT_06012b48
                                        ,10);
            if ((uint)*(ushort *)(param_1 + 0x18) <= iVar12 + 3U) {
              thunk_FUN_037faf84(uVar6);
              uVar7 = iVar14 + 0x90U & 3;
              uVar10 = *(uint *)(iVar14 + 0x90U & 0xfffffffc);
              FUN_060090b4(uVar9 + 0x188,uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20);
              *(undefined2 *)(iVar14 + 0x3c) = 0;
              *(short *)(iVar14 + 0x3e) = *(short *)(iVar14 + 0x3e) + -1;
              return 5;
            }
            *DAT_06012b5c = (*(ushort *)(param_1 + 0x18) - (short)iVar12) + -1;
            *DAT_06012b64 = (ushort)(((uint)puVar11 & DAT_06012b60) >> 1) | 0x8000 | uVar13;
            thunk_FUN_037faf84(uVar6);
          }
          uVar6 = 0;
        }
      }
      else {
        uVar6 = 5;
      }
    }
    else {
      uVar6 = 8;
    }
  }
  else {
    uVar6 = 0xb;
  }
  return uVar6;
}

