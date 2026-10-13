/* Decompiled C draft; module arm7; ROM address 060157b8. No matching claim. */
#include "types.h"
#include "deps/060157b8_FUN_060157b8.h"

void FUN_060157b8(ushort *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint uVar6;
  int iVar7;
  uint unaff_r5;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint unaff_r11;
  int local_30;
  
  uVar4 = *(uint *)(DAT_060159ec & 0xfffffffc) >> (DAT_060159ec & 3) * 8 |
          *(uint *)(DAT_060159ec & 0xfffffffc) << (DAT_060159ec & 3) * -8 + 0x20;
  iVar9 = uVar4 + DAT_060159f0;
  param_1[4] = param_1[4] - 0x18;
  uVar8 = 0;
  do {
    if (2 < uVar8) {
LAB_06015898:
      if (uVar8 != 3) {
        iVar7 = uVar8 * 0x18;
        uVar8 = iVar9 + iVar7 + 0x14;
        uVar10 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        uVar8 = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20;
        uVar10 = *(ushort *)(uVar8 + 0x20) + unaff_r5;
        if (DAT_060159f4 < uVar10) {
          FUN_060090b4(uVar4 + 0x188,uVar8);
          *(undefined2 *)(iVar9 + iVar7) = 0;
        }
        else {
          thunk_FUN_037fb230((int)param_1 + local_30 + 0x24,
                             uVar8 + 0x3c + (uint)*(ushort *)(uVar8 + 0x20),unaff_r5 + 1);
          *(short *)(uVar8 + 0x20) = (short)uVar10;
          iVar3 = thunk_FUN_03806b2c(*param_1 & 0xf0,0x10);
          puVar5 = (undefined2 *)(iVar9 + iVar7);
          puVar5[8] = puVar5[8] & 0xfff0 |
                      (ushort)(((iVar3 - unaff_r11) + ((ushort)puVar5[8] & 0xf)) * 0x10000 >> 0x10)
                      & 0xf;
          uVar6 = *(uint *)(DAT_060159ec & 0xfffffffc) >> (DAT_060159ec & 3) * 8 |
                  *(uint *)(DAT_060159ec & 0xfffffffc) << (DAT_060159ec & 3) * -8 + 0x20;
          uVar10 = uVar6 + 0x560;
          uVar1 = uVar10 & 3;
          uVar10 = *(uint *)(uVar10 & 0xfffffffc);
          *(uint *)(uVar6 + 0x560) = (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) + iVar3;
          if ((*param_1 & 0x100) == 0) {
            *puVar5 = 0;
            *(ushort *)(uVar8 + 0x18) = (*(ushort *)(uVar8 + 0x18) & 0xff0f) + 0x10;
            *(short *)(uVar8 + 0x20) = *(short *)(uVar8 + 0x20) + 0x18;
            if ((*(ushort *)(uVar8 + 0x18) & 0xf) == 0) {
              FUN_06009040(uVar4 + 0x188,uVar4 + 0x1dc,uVar8);
              FUN_06008a8c(1,7);
            }
            else if ((*(ushort *)(uVar8 + 0x18) & 0xf) == 8) {
              FUN_06009040(uVar4 + 0x188,uVar4 + 0x1c4,uVar8);
              FUN_06008a8c(2,6);
            }
            else {
              FUN_060090b4(uVar4 + 0x188,uVar8);
            }
          }
        }
      }
      return;
    }
    iVar7 = uVar8 * 0x18;
    iVar3 = iVar9 + iVar7;
    if ((((*(short *)(iVar9 + iVar7) != 0) && (iVar2 = FUN_0600a578(iVar3 + 4,param_2), iVar2 != 0))
        && (iVar2 = FUN_0600a578(iVar3 + 10,param_2 + 6), iVar2 != 0)) &&
       (((uint)*(ushort *)(param_2 + 0xc) << 0x10) >> 0x14 ==
        ((uint)*(ushort *)(iVar3 + 0x10) << 0x10) >> 0x14)) {
      unaff_r11 = (uint)*(ushort *)(iVar9 + iVar7 + 0x10) - (uint)*(ushort *)(param_2 + 0xc);
      if ((unaff_r11 & 0x80000000) != 0) {
        return;
      }
      local_30 = unaff_r11 * *(ushort *)(iVar9 + iVar7 + 2);
      unaff_r5 = (uint)param_1[4] - local_30;
      if (unaff_r5 == 0) {
        return;
      }
      if ((unaff_r5 & 0x80000000) != 0) {
        return;
      }
      goto LAB_06015898;
    }
    uVar8 = uVar8 + 1;
  } while( true );
}

