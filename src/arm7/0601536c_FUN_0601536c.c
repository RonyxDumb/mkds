/* Decompiled C draft; module arm7; ROM address 0601536c. No matching claim. */
#include "types.h"
#include "deps/0601536c_FUN_0601536c.h"

void FUN_0601536c(int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  int iVar12;
  uint uVar13;
  uint local_34;
  
  uVar8 = *(uint *)(DAT_060155ac & 0xfffffffc) >> (DAT_060155ac & 3) * 8 |
          *(uint *)(DAT_060155ac & 0xfffffffc) << (DAT_060155ac & 3) * -8 + 0x20;
  iVar12 = uVar8 + DAT_060155b0;
  psVar11 = (short *)(param_1 * 0x14 + iVar12);
  uVar13 = param_1 * 0xc + uVar8 + 0x194;
  if (*(short *)(uVar13 + 8) != 0) {
    uVar4 = thunk_FUN_037f8850(0x1000000);
    if (*psVar11 == 0) {
      uVar5 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
              *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
      while (local_34 = uVar5, local_34 != 0xffffffff) {
        uVar5 = FUN_06008e48();
        iVar10 = local_34 + 0x10;
        uVar2 = *(undefined2 *)(local_34 + 0x12);
        uVar1 = uVar8 + 0x3ec & 3;
        uVar9 = *(uint *)(uVar8 + 0x3ec & 0xfffffffc);
        uVar1 = (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) -
                (uint)*(ushort *)(local_34 + 0x14) & 0xffff;
        if (((*(ushort *)(uVar8 + 0x3d0) < uVar1) &&
            (((uint)*(ushort *)(local_34 + 0x24) << 0x1c) >> 0x1e != 0)) ||
           ((uint)*(ushort *)(uVar8 + 0x3d0) * 8 < uVar1)) {
          *(short *)(iVar12 + 0xae) = *(short *)(iVar12 + 0xae) + 1;
          *(undefined2 *)(local_34 + 0x18) = 2;
          psVar11[2] = psVar11[2] + 1;
          uVar1 = (uint)(psVar11 + 8) & 3;
          uVar9 = *(uint *)((uint)(psVar11 + 8) & 0xfffffffc);
          (*(code *)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20))(iVar10,0);
        }
        else {
          if ((param_1 != 0) && ((param_1 != 1 || (iVar6 = FUN_0600e918(uVar2), iVar6 != 0x40))))
          goto LAB_060154dc;
          iVar6 = FUN_0600e8f8(uVar2);
          if (iVar6 != 0) {
            iVar6 = FUN_0600e918(uVar2);
            if (iVar6 == 0x40) {
LAB_060154dc:
              *psVar11 = 1;
              psVar11[1] = psVar11[1] + 1;
              *(int *)(psVar11 + 6) = iVar10;
              uVar13 = (uint)(psVar11 + 4) & 3;
              uVar5 = *(uint *)((uint)(psVar11 + 4) & 0xfffffffc);
              uVar13 = uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20;
              if (*(short *)(uVar8 + 0x354) == 0) {
                FUN_0600ae00(2);
              }
              FUN_06015220(uVar13,local_34);
              if ((*(short *)(uVar8 + 0x350) == 1) && (uVar8 = FUN_0600e824(uVar2), 1 < uVar8)) {
                *(ushort *)(uVar13 + 0xc) = *(ushort *)(uVar13 + 0xc) | 0x2000;
              }
              puVar7 = (ushort *)(DAT_060155b4 + param_1 * 4);
              uVar3 = (ushort)((uVar13 & DAT_060155b8) >> 1);
              if ((*(ushort *)(local_34 + 0x24) & 0xc) == 4) {
                *puVar7 = uVar3 | 0xa000;
              }
              else if ((*(ushort *)(local_34 + 0x24) & 0xfc) == 0x50) {
                *puVar7 = uVar3 | 0x9000;
              }
              else {
                *puVar7 = uVar3 | 0x8000;
              }
              thunk_FUN_037f888c(uVar4);
              return;
            }
            *(undefined2 *)(local_34 + 0x18) = 2;
            FUN_060125a8(uVar13,local_34);
            FUN_0600ec88(iVar10);
          }
        }
      }
      thunk_FUN_037f888c(uVar4);
    }
    else {
      thunk_FUN_037f888c();
    }
  }
  return;
}

