/* Decompiled C draft; module arm7; ROM address 0601858c. No matching claim. */
#include "types.h"
#include "deps/0601858c_FUN_0601858c.h"

void FUN_0601858c(undefined2 param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  short *psVar10;
  
  psVar10 = (short *)((*(uint *)(DAT_060186e4 & 0xfffffffc) >> (DAT_060186e4 & 3) * 8 |
                      *(uint *)(DAT_060186e4 & 0xfffffffc) << (DAT_060186e4 & 3) * -8 + 0x20) +
                     0x23c);
  uVar2 = FUN_060096c4(param_3 + 1);
  if (uVar2 < 0x21) {
    uVar2 = 4;
    uVar4 = 0x400;
    uVar7 = 4;
    for (uVar9 = 0; uVar9 < 4; uVar9 = uVar9 + 1) {
      uVar6 = uVar9;
      if (*psVar10 != 0) {
        iVar5 = FUN_0600a578(psVar10 + 3,param_2 + 0x24);
        if (iVar5 != 0) goto LAB_06018638;
        uVar6 = uVar7;
        if ((ushort)psVar10[0x18] < uVar4) {
          uVar2 = uVar9;
          uVar4 = psVar10[0x18];
        }
      }
      psVar10 = psVar10 + 0x19;
      uVar7 = uVar6;
    }
    uVar9 = uVar7;
    if ((uVar7 != 4) || (uVar9 = uVar2, uVar2 != 4)) {
LAB_06018638:
      iVar5 = (*(uint *)(DAT_060186e4 & 0xfffffffc) >> (DAT_060186e4 & 3) * 8 |
              *(uint *)(DAT_060186e4 & 0xfffffffc) << (DAT_060186e4 & 3) * -8 + 0x20) + 0x23c;
      iVar8 = iVar5 + uVar9 * 0x32;
      thunk_FUN_037fb218(0,iVar8);
      *(undefined2 *)(iVar8 + 0x30) = 0x400;
      *(ushort *)(iVar5 + uVar9 * 0x32) = *(ushort *)(param_2 + 0x12) & 0xff;
      *(undefined2 *)(iVar8 + 2) = param_1;
      FUN_0600a954(iVar8 + 6,param_2 + 0x24);
      uVar1 = FUN_060096c4(param_3 + 1);
      *(undefined2 *)(iVar8 + 0xc) = uVar1;
      for (uVar2 = 0; uVar2 < *(ushort *)(iVar8 + 0xc); uVar2 = uVar2 + 1) {
        uVar3 = FUN_060096c4(param_3 + 2 + uVar2);
        FUN_060096e4(iVar8 + 0xe + uVar2,uVar3);
      }
      *(undefined2 *)(iVar8 + 0x2e) = *(undefined2 *)(param_2 + 0x34);
      *(undefined2 *)(iVar8 + 4) = *(undefined2 *)(param_2 + 0x36);
    }
  }
  return;
}

