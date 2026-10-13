/* Decompiled C draft; module arm9; ROM address 02044940. No matching claim. */
#include "types.h"
#include "deps/02044940_PrepareRace.h"

void PrepareRace(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  undefined4 *puVar19;
  
  uVar8 = DAT_02044bec;
  uVar18 = 0;
  uVar13 = *(uint *)(DAT_02044bec & 0xfffffffc) >> (DAT_02044bec & 3) * 8 |
           *(uint *)(DAT_02044bec & 0xfffffffc) << (DAT_02044bec & 3) * -8 + 0x20;
  uVar7 = uVar13 + 0x1f0 & 3;
  uVar6 = *(uint *)(uVar13 + 0x1f0 & 0xfffffffc);
  switch(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) {
  case 0:
    goto LAB_0204497c;
  case 1:
    uVar18 = 1;
    uVar7 = (*(uint *)(DAT_02044bf0 & 0xfffffffc) >> (DAT_02044bf0 & 3) * 8 |
            *(uint *)(DAT_02044bf0 & 0xfffffffc) << (DAT_02044bf0 & 3) * -8 + 0x20) + 0x14;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar7 = uVar6 + 8 & 3;
    uVar11 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    if ((int)((uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) << 0x1f) < 0) {
      *(undefined1 *)(uVar13 + 0x3e6) = 1;
      uVar7 = uVar6 + 8 & 3;
      uVar13 = *(uint *)(uVar6 + 8 & 0xfffffffc);
      *(byte *)((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x3e4) =
           (byte)(((uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) << 0x11) >> 0x19);
      uVar7 = uVar6 + 8 & 3;
      uVar13 = *(uint *)(uVar6 + 8 & 0xfffffffc);
      *(byte *)((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x3e5) =
           (byte)(((uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) << 10) >> 0x19);
      uVar7 = uVar6 + 8 & 3;
      uVar6 = *(uint *)(uVar6 + 8 & 0xfffffffc);
      *(ushort *)
       ((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
        *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x3e2) =
           (ushort)((ushort)((uVar6 >> uVar7 * 8) >> 0x10) |
                   (ushort)((uVar6 << uVar7 * -8 + 0x20) >> 0x10)) >> 6;
    }
    else {
      *(undefined1 *)(uVar13 + 0x3e6) = 0;
      *(undefined1 *)
       ((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
        *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x3e4) = 0;
      *(undefined1 *)
       ((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
        *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x3e5) = 0;
      *(undefined2 *)
       ((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
        *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x3e2) = 0;
    }
    uVar6 = *(uint *)(DAT_02044bec & 0xfffffffc) >> (DAT_02044bec & 3) * 8 |
            *(uint *)(DAT_02044bec & 0xfffffffc) << (DAT_02044bec & 3) * -8 + 0x20;
    uVar7 = uVar6 + 0x20c & 3;
    uVar8 = *(uint *)(uVar6 + 0x20c & 0xfffffffc);
    switch(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) {
    case 0:
      uVar7 = uVar6 + 0x1e8 & 3;
      uVar8 = *(uint *)(uVar6 + 0x1e8 & 0xfffffffc);
      iVar15 = MaybeLoadPersonalGhost(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,1);
      if (iVar15 != 0) {
        uVar18 = 2;
      }
      break;
    case 1:
      uVar7 = uVar6 + 0x1e8 & 3;
      uVar8 = *(uint *)(uVar6 + 0x1e8 & 0xfffffffc);
      iVar15 = MaybeLoadDownloadGhost(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,1);
      if (iVar15 != 0) {
        uVar18 = 2;
      }
      break;
    case 2:
      uVar7 = uVar6 + 0x1e8 & 3;
      uVar8 = *(uint *)(uVar6 + 0x1e8 & 0xfffffffc);
      iVar15 = MaybeLoadStaffGhost(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,1);
      if (iVar15 != 0) {
        uVar18 = 2;
      }
      break;
    case 3:
    }
    break;
  case 2:
    goto LAB_0204497c;
  case 3:
LAB_0204497c:
    uVar18 = 8;
    break;
  case 4:
    uVar18 = 2;
    break;
  case 5:
    uVar18 = 4;
  }
  uVar8 = DAT_02044bec;
  uVar6 = *(uint *)(DAT_02044bec & 0xfffffffc) >> (DAT_02044bec & 3) * 8 |
          *(uint *)(DAT_02044bec & 0xfffffffc) << (DAT_02044bec & 3) * -8 + 0x20;
  uVar7 = uVar6 + 500 & 3;
  uVar13 = *(uint *)(uVar6 + 500 & 0xfffffffc);
  switch(uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    goto LAB_02044ad8;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
LAB_02044ad8:
    *(undefined1 *)(uVar6 + 0x24a) = *(undefined1 *)(uVar6 + 0x24b);
    goto switchD_02044ab4_default;
  case 6:
    uVar18 = 8;
    *(undefined1 *)(uVar6 + 0x24a) = *(undefined1 *)(uVar6 + 0x24b);
  default:
    goto switchD_02044ab4_default;
  }
  uVar7 = 0;
  uVar13 = 0;
  do {
    uVar11 = uVar13 * 0x30 + uVar6 + 600;
    uVar1 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    bVar2 = uVar11 >> uVar1 * 8 != 0;
    bVar3 = uVar11 << uVar1 * -8 + 0x20 != 0;
    if (!bVar2 && !bVar3) {
      uVar7 = uVar13;
    }
    uVar9 = (undefined1)uVar7;
  } while ((bVar2 || bVar3) && (uVar13 = uVar13 + 1 & 0xff, uVar13 < 8));
  bVar2 = false;
  uVar7 = *(uint *)(DAT_02044bf4 & 0xfffffffc) >> (DAT_02044bf4 & 3) * 8 |
          *(uint *)(DAT_02044bf4 & 0xfffffffc) << (DAT_02044bf4 & 3) * -8 + 0x20;
  if (uVar7 == 0) {
    uVar13 = 0;
  }
  else {
    uVar13 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
             *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  }
  if ((uVar13 != 0) &&
     (uVar13 = uVar7 + 4 & 3, uVar11 = *(uint *)(uVar7 + 4 & 0xfffffffc),
     (uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) != 0xd)) {
    bVar2 = true;
  }
  if (bVar2) {
    if ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
        *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) == 2) {
      uVar13 = (uint)*(ushort *)(uVar7 + 0x432);
    }
    else {
      uVar13 = 0;
    }
    uVar9 = (undefined1)*(undefined2 *)(uVar7 + ((uVar13 << 0x10) >> 0xd) + 0x1e52);
  }
  *(undefined1 *)(uVar6 + 0x24a) = uVar9;
  uVar7 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  *(undefined1 *)((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) + 0x24b) = uVar9;
switchD_02044ab4_default:
  iVar15 = 0x1e;
  puVar16 = (undefined4 *)
            (*(uint *)(DAT_02044bec & 0xfffffffc) >> (DAT_02044bec & 3) * 8 |
            *(uint *)(DAT_02044bec & 0xfffffffc) << (DAT_02044bec & 3) * -8 + 0x20);
  puVar4 = puVar16 + 0x7a;
  do {
    puVar19 = puVar4;
    puVar17 = puVar16;
    uVar10 = puVar19[1];
    uVar12 = puVar19[2];
    uVar14 = puVar19[3];
    *puVar17 = *puVar19;
    puVar17[1] = uVar10;
    puVar17[2] = uVar12;
    puVar17[3] = uVar14;
    iVar15 = iVar15 + -1;
    puVar16 = puVar17 + 4;
    puVar4 = puVar19 + 4;
  } while (iVar15 != 0);
  uVar10 = puVar19[5];
  puVar17[4] = puVar19[4];
  puVar17[5] = uVar10;
  MaybeSetRacerCount(uVar18);
  func_02044fc0();
  uVar5 = 0;
  do {
    PrepareCurrentRaceRacer(uVar5);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 8);
  return;
}

