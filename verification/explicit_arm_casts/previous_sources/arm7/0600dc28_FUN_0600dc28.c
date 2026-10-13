/* Decompiled C draft; module arm7; ROM address 0600dc28. No matching claim. */
#include "types.h"
#include "deps/0600dc28_FUN_0600dc28.h"

void FUN_0600dc28(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  int iVar11;
  int iVar12;
  int local_30;
  
  uVar3 = DAT_0600dfc8;
  uVar7 = *(uint *)(DAT_0600dfc8 & 0xfffffffc) >> (DAT_0600dfc8 & 3) * 8 |
          *(uint *)(DAT_0600dfc8 & 0xfffffffc) << (DAT_0600dfc8 & 3) * -8 + 0x20;
  iVar11 = uVar7 + DAT_0600dfcc;
  local_30 = 0;
  do {
    while( true ) {
      while( true ) {
        uVar8 = (uint)*DAT_0600dfd0;
        if (uVar8 == *(ushort *)(iVar11 + 4)) {
          return;
        }
        puVar10 = (ushort *)(DAT_0600dfd4 + uVar8 * 2);
        puVar4 = (ushort *)FUN_0600c580(puVar10 + 1);
        uVar2 = *puVar4;
        if (*(ushort *)(&DAT_04804000 + uVar8 * 2) != DAT_0600dfd8) break;
        *DAT_0600dfd0 = uVar2;
      }
      puVar5 = (undefined2 *)FUN_0600c580(puVar10 + 4);
      iVar6 = FUN_0600da04(puVar10,*puVar5);
      *DAT_0600dfd0 = uVar2;
      if (iVar6 != 0) break;
      if ((*puVar10 & 0xf) == 0xc) {
        FUN_06009360(0x10);
      }
      else {
        FUN_06009360(8);
      }
    }
    if (((*(ushort *)
           ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x690) & 8) != 0) &&
       ((*(ushort *)(iVar6 + 0x14) & 0x4000) != 0)) {
      *(undefined2 *)(iVar11 + 2) = 0;
    }
    iVar12 = 1;
    if ((*(ushort *)(iVar6 + 8) & 0x200) != 0) {
      if (((int)((uint)*(ushort *)(iVar6 + 0x14) << 0x15) < 0) ||
         ((*(ushort *)(iVar6 + 0x2a) & 0xf) != 0)) {
        FUN_06009040(uVar7 + 0x188,uVar7 + 0x1e8,iVar6 + -0x10);
        FUN_06008a8c(2,9);
        iVar12 = 0;
      }
      goto switchD_0600ddbc_default;
    }
    switch(*(ushort *)(iVar6 + 8) & 0xf) {
    case 0:
      if ((*(ushort *)(iVar6 + 0x14) & 0xf) == 0) {
        FUN_06009040(uVar7 + 0x188,uVar7 + 0x1dc,iVar6 + -0x10);
        FUN_06008a8c(1,7);
        iVar12 = 0;
      }
      break;
    case 1:
      if (*(short *)(iVar6 + 0x14) == 0x80) {
        FUN_060176c0(iVar6);
      }
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      if ((DAT_0600dfdc & *(ushort *)(iVar6 + 0x14)) == 0xa4) {
        FUN_06009040(uVar7 + 0x188,uVar7 + 0x1dc,iVar6 + -0x10);
        FUN_06008a8c(1,7);
        iVar12 = local_30;
      }
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      if ((*(ushort *)(iVar6 + 0x14) & 0xf) == 8) {
        FUN_06009040(uVar7 + 0x188,uVar7 + 0x1c4,iVar6 + -0x10);
        FUN_06008a8c(2,6);
        iVar12 = 0;
      }
      break;
    case 9:
      break;
    case 10:
      break;
    case 0xb:
      break;
    case 0xc:
      if ((DAT_0600dfdc & *(ushort *)(iVar6 + 0x14)) == 0x228) {
        if (*(short *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                       *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x354) == 0) {
          *DAT_0600dfe4 = 1;
        }
        uVar9 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
        uVar8 = uVar9 + 0x5ac;
        uVar1 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)(uVar9 + 0x5ac) = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) + 1;
        iVar12 = FUN_06018064(iVar6);
      }
      break;
    case 0xd:
      if ((DAT_0600dfdc & *(ushort *)(iVar6 + 0x14)) == 0x218) {
        uVar9 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
        uVar8 = uVar9 + 0x5b0;
        uVar1 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)(uVar9 + 0x5b0) = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) + 1;
        iVar12 = FUN_06017d88(iVar6);
      }
      break;
    case 0xe:
      goto LAB_0600deb8;
    case 0xf:
LAB_0600deb8:
      if ((DAT_0600dfe0 & *(ushort *)(iVar6 + 0x14)) == 0x118) {
        FUN_06017e6c(iVar6);
      }
    }
switchD_0600ddbc_default:
    if (iVar12 != 0) {
      FUN_060090b4(uVar7 + 0x188,iVar6 + -0x10);
    }
    uVar8 = 0;
    if ((*(ushort *)
          ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
           *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x690) & 1) != 0) {
      do {
        puVar4 = puVar10;
        if (DAT_0600dfe8 <= puVar10) {
          puVar4 = (ushort *)
                   ((int)puVar10 -
                   (uint)*(ushort *)
                          ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                           *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x3de));
        }
        puVar10 = puVar4 + 1;
        *puVar4 = (ushort)DAT_0600dfd8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 7);
    }
  } while( true );
}

