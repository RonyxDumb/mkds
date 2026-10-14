/* Decompiled C draft; module arm7; ROM address 06012cf8. No matching claim. */
#include "types.h"
#include "deps/06012cf8_FUN_06012cf8.h"

undefined4 FUN_06012cf8(int param_1)

{
  uint uVar1;
  short sVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar4 = *(uint *)(DAT_06012ed4 & 0xfffffffc) >> (DAT_06012ed4 & 3) * 8 |
          *(uint *)(DAT_06012ed4 & 0xfffffffc) << (DAT_06012ed4 & 3) * -8 + 0x20;
  if (DAT_06012ed8 < *(ushort *)(param_1 + 0x16)) {
    uVar5 = 5;
  }
  else {
    if (*(short *)(uVar4 + 0x32e) == 1) {
      uVar6 = FUN_0600ef30((ushort *)(uintptr_t)(param_1 + 0x28));
      if ((uVar6 == 0xff) || (iVar7 = FUN_0600e918(), iVar7 != 0x40)) {
        return 10;
      }
    }
    else {
      uVar6 = (uint)*(ushort *)(uVar4 + 0x3cc);
    }
    *(short *)(param_1 + 0x12) = (short)uVar6;
    uVar8 = (*(uint *)(DAT_06012ed4 & 0xfffffffc) >> (DAT_06012ed4 & 3) * 8 |
            *(uint *)(DAT_06012ed4 & 0xfffffffc) << (DAT_06012ed4 & 3) * -8 + 0x20) + 0x3ec;
    uVar1 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(ushort *)(param_1 + 0x14) =
         (ushort)(uVar8 >> uVar1 * 8) | (ushort)(uVar8 << uVar1 * -8 + 0x20);
    if ((*(ushort *)(param_1 + 0x1e) & 0xff) == 0) {
      uVar3 = FUN_0600e85c(uVar6);
      *(undefined2 *)(param_1 + 0x20) = uVar3;
    }
    else {
      *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x1e);
      *(undefined2 *)(param_1 + 0x1e) = 0;
    }
    if (*(short *)(param_1 + 0x16) == 0) {
      *(ushort *)(param_1 + 0x24) = *(ushort *)(uVar4 + 0x3ce) & 0xbfff | 0x40;
      *(undefined2 *)(param_1 + 0x22) = 0x1c;
    }
    else {
      *(undefined2 *)(param_1 + 0x24) = *(undefined2 *)(uVar4 + 0x3ce);
      if (*(short *)(uVar4 + 0x334) == 0) {
        *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x16) + 0x1c;
      }
      else {
        *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x16) + 0x24;
      }
    }
    sVar2 = *(short *)(uVar4 + 0x32e);
    if (sVar2 == 1) {
      FUN_0600a954((undefined2 *)(uintptr_t)(param_1 + 0x34),(undefined2 *)(uintptr_t)(param_1 + 0x2e));
      FUN_0600a954((undefined2 *)(uintptr_t)(param_1 + 0x2e),(undefined2 *)(uintptr_t)(uVar4 + 0x3a8));
      if (uVar6 == 0) {
        FUN_0600ed84(uVar4 + 0x200,param_1);
        uVar4 = *(uint *)(DAT_06012ed4 & 0xfffffffc) >> (DAT_06012ed4 & 3) * 8 |
                *(uint *)(DAT_06012ed4 & 0xfffffffc) << (DAT_06012ed4 & 3) * -8 + 0x20;
        if ((*(ushort *)(uVar4 + 0x52e) & ~*(ushort *)(uVar4 + 0x532)) == 0) {
          FUN_0601536c(2);
        }
      }
      else {
        FUN_0600ecf4(param_1 + 0x10);
        FUN_06009040(uVar4 + 0x200,uVar4 + 0x194,param_1);
        FUN_0601536c(0);
      }
    }
    else if ((sVar2 == 2) || (sVar2 == 3)) {
      FUN_0600a954((undefined2 *)(uintptr_t)(param_1 + 0x34),(undefined2 *)(uintptr_t)(param_1 + 0x28));
      FUN_0600a954((undefined2 *)(uintptr_t)(param_1 + 0x28),(undefined2 *)(uintptr_t)(uVar4 + 0x3a8));
      FUN_0600ecf4(param_1 + 0x10);
      FUN_06009040(uVar4 + 0x200,uVar4 + 0x194,param_1);
      FUN_0601536c(0);
    }
    uVar5 = 0x81;
  }
  return uVar5;
}

