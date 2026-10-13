/* Decompiled C draft; module arm7; ROM address 0600cb28. No matching claim. */
#include "types.h"
#include "deps/0600cb28_FUN_0600cb28.h"

void FUN_0600cb28(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ushort *puVar14;
  ushort *puVar15;
  ushort uVar16;
  
  uVar9 = *(uint *)(DAT_0600cf20 & 0xfffffffc) >> (DAT_0600cf20 & 3) * 8 |
          *(uint *)(DAT_0600cf20 & 0xfffffffc) << (DAT_0600cf20 & 3) * -8 + 0x20;
  puVar15 = (ushort *)(uVar9 + DAT_0600cf24);
  uVar1 = *(ushort *)(uVar9 + 0x690);
  *DAT_0600cf28 = 1;
  do {
    uVar13 = (uint)puVar15[2];
    uVar2 = *DAT_0600cf2c;
    uVar12 = (uint)uVar2;
    if (uVar13 == uVar12) {
LAB_0600cebc:
      if ((uVar1 & 1) != 0) {
        uVar1 = *DAT_0600cf2c;
        iVar8 = FUN_0600c4c8();
        if ((iVar8 != 0) && (uVar1 == *DAT_0600cf2c)) {
          FUN_06009360(0x20);
        }
      }
      if (*DAT_0600cf68 != *DAT_0600cf2c) {
        FUN_06008a8c(0,0xf);
      }
      return;
    }
    if (*DAT_0600cf30 < *DAT_0600cf30) {
      uVar16 = *DAT_0600cf30 >> 4 | *DAT_0600cf34 << 0xc;
    }
    else {
      uVar16 = *DAT_0600cf30 >> 4 | *DAT_0600cf34 << 0xc;
    }
    puVar14 = (ushort *)(DAT_0600cf38 + uVar13 * 2);
    puVar3 = (ushort *)FUN_0600c580(puVar14 + 1);
    puVar4 = (ushort *)FUN_0600c580(puVar3 + 1);
    puVar5 = (ushort *)FUN_0600c580(puVar4 + 2);
    puVar6 = (ushort *)FUN_0600c580(puVar14 + 7);
    *(ushort *)(&DAT_04804000 + uVar13 * 2) =
         *(ushort *)(&DAT_04804000 + uVar13 * 2) | (ushort)((*puVar3 & 0x200) << 1);
    *puVar4 = uVar16;
    uVar11 = (uint)*puVar5;
    uVar13 = (uVar11 + uVar13 * 2 + 0xf >> 2) * 2;
    if (0xfaf < uVar13) {
      uVar13 = uVar13 - (*(ushort *)(uVar9 + 0x3de) >> 1);
    }
    if (DAT_0600cf3c < uVar11) {
      *puVar14 = (ushort)DAT_0600cf40;
      *(short *)(uVar9 + 0x3f8) = *(short *)(uVar9 + 0x3f8) + 1;
      uVar13 = uVar12;
    }
    else if (((uVar1 & 1) != 0) && (uVar13 != uVar12)) {
      uVar12 = DAT_0600cf38 + uVar13 * 2;
      if (uVar12 < DAT_0600cf44) {
        uVar16 = *(ushort *)(uVar12 + 6) & 0xff;
      }
      else {
        uVar16 = *(ushort *)((uVar12 - *(ushort *)(uVar9 + 0x3de)) + 6);
      }
      if (((*(ushort *)(&DAT_04804000 + uVar13 * 2) & 0x7c00) != 0) ||
         (((uVar16 != 10 && (uVar16 != 0x14)) || (DAT_0600cf48 < uVar11)))) {
        *(short *)(uVar9 + 0x3f8) = *(short *)(uVar9 + 0x3f8) + 1;
        *puVar14 = (ushort)DAT_0600cf40;
        puVar15[2] = uVar2;
        *puVar3 = uVar2;
        goto LAB_0600cebc;
      }
    }
    if ((*puVar14 & 0xf) == 0xc) {
      puVar4 = (ushort *)FUN_0600c580(puVar14 + 6);
      uVar2 = *puVar4;
      puVar4 = (ushort *)FUN_0600c580(puVar14 + 0x11);
      uVar16 = *puVar4;
      if ((*puVar15 == uVar16) && ((uVar2 & 0x800) != 0)) {
        uVar10 = *(uint *)(DAT_0600cf20 & 0xfffffffc) >> (DAT_0600cf20 & 3) * 8 |
                 *(uint *)(DAT_0600cf20 & 0xfffffffc) << (DAT_0600cf20 & 3) * -8 + 0x20;
        uVar12 = uVar10 + 0x57c;
        uVar11 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        *(uint *)(uVar10 + 0x57c) = (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) + 1;
        *puVar14 = (ushort)DAT_0600cf40;
      }
      else {
        uVar12 = *(uint *)(DAT_0600cf20 & 0xfffffffc) >> (DAT_0600cf20 & 3) * 8 |
                 *(uint *)(DAT_0600cf20 & 0xfffffffc) << (DAT_0600cf20 & 3) * -8 + 0x20;
        if ((-1 < (int)((uint)*(ushort *)(uVar12 + 0x33a) << 0x18)) &&
           (*(short *)(uVar12 + 0x34c) == 0x40)) {
          if ((*DAT_0600cf4c == 0) || ((*DAT_0600cf50 & 0x8000) == 0)) {
            uVar16 = (ushort)DAT_0600cf40;
            *DAT_0600cf5c = uVar16;
            *DAT_0600cf60 = uVar16;
            *DAT_0600cf64 = uVar16;
            *puVar14 = uVar16;
          }
          else {
            thunk_FUN_037fa564(uVar12 + 0x660);
            uVar7 = thunk_FUN_03806b2c((uint)*puVar6 * DAT_0600cf54,0x40);
            iVar8 = thunk_FUN_03806b2c(uVar7,1000);
            thunk_FUN_037fa670((*(uint *)(DAT_0600cf20 & 0xfffffffc) >> (DAT_0600cf20 & 3) * 8 |
                               *(uint *)(DAT_0600cf20 & 0xfffffffc) <<
                               (DAT_0600cf20 & 3) * -8 + 0x20) + 0x660,iVar8,iVar8 >> 0x1f,
                               DAT_0600cf58,0);
          }
        }
      }
      *puVar15 = uVar16;
      iVar8 = FUN_0600c4c8();
      if (iVar8 == 0) {
        uVar10 = *(uint *)(DAT_0600cf20 & 0xfffffffc) >> (DAT_0600cf20 & 3) * 8 |
                 *(uint *)(DAT_0600cf20 & 0xfffffffc) << (DAT_0600cf20 & 3) * -8 + 0x20;
        uVar12 = uVar10 + 0x5a8;
        uVar11 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        *(uint *)(uVar10 + 0x5a8) = (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) + 1;
      }
    }
    else if ((((*puVar14 & 0xf) == 0xd) &&
             (uVar12 = *(uint *)(DAT_0600cf20 & 0xfffffffc) >> (DAT_0600cf20 & 3) * 8 |
                       *(uint *)(DAT_0600cf20 & 0xfffffffc) << (DAT_0600cf20 & 3) * -8 + 0x20,
             -1 < (int)((uint)*(ushort *)(uVar12 + 0x33a) << 0x18))) &&
            ((*(short *)(uVar12 + 0x34c) == 0x40 &&
             ((*DAT_0600cf4c == 0 || ((*DAT_0600cf50 & 0x8000) == 0)))))) {
      *puVar14 = (ushort)DAT_0600cf40;
    }
    puVar15[2] = (ushort)uVar13;
    *puVar3 = (ushort)uVar13;
  } while( true );
}

