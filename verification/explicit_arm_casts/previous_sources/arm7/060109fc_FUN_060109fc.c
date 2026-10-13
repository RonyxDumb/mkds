/* Decompiled C draft; module arm7; ROM address 060109fc. No matching claim. */
#include "types.h"
#include "deps/060109fc_FUN_060109fc.h"

undefined4 FUN_060109fc(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  *(undefined2 *)(param_2 + 2) = 4;
  uVar5 = *(uint *)(DAT_06010b30 & 0xfffffffc) >> (DAT_06010b30 & 3) * 8 |
          *(uint *)(DAT_06010b30 & 0xfffffffc) << (DAT_06010b30 & 3) * -8 + 0x20;
  uVar4 = (uint)*(ushort *)(uVar5 + 0x32e);
  if (((uVar4 == 3) || (uVar4 == 2)) || (uVar4 == 1)) {
    if (*(ushort *)(uVar5 + 0x34c) < 0x30) {
      uVar2 = 1;
    }
    else if (((uVar4 + DAT_06010b34 & 0xffff) < 2) && ((*(ushort *)(param_1 + 0x10) & 1) != 0)) {
      uVar2 = 5;
    }
    else {
      FUN_0600a954(param_2 + 6,param_1 + 0x10);
      iVar3 = FUN_0601364c(param_2 + 6,*(undefined2 *)(param_1 + 0x16));
      uVar4 = DAT_06010b30;
      if (iVar3 == 0) {
        uVar2 = 8;
      }
      else {
        *(int *)((*(uint *)(DAT_06010b30 & 0xfffffffc) >> (DAT_06010b30 & 3) * 8 |
                 *(uint *)(DAT_06010b30 & 0xfffffffc) << (DAT_06010b30 & 3) * -8 + 0x20) + 0x41c) =
             param_1;
        *(int *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                 *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x420) = param_2;
        *(undefined2 *)
         ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x404) = 0x41;
        if ((*(ushort *)(param_1 + 0x10) & 1) == 0) {
          FUN_06014554(param_1 + 0x10);
          FUN_060143ac(iVar3);
        }
        else {
          uVar5 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                  *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x3ec;
          uVar1 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          *(ushort *)(iVar3 + 4) =
               (ushort)(uVar5 >> uVar1 * 8) | (ushort)(uVar5 << uVar1 * -8 + 0x20);
          FUN_0600ed84((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                       *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x188,
                       iVar3 + -0x10);
          uVar4 = *(uint *)(DAT_06010b30 & 0xfffffffc) >> (DAT_06010b30 & 3) * 8 |
                  *(uint *)(DAT_06010b30 & 0xfffffffc) << (DAT_06010b30 & 3) * -8 + 0x20;
          if ((*(ushort *)(uVar4 + 0x52e) & ~*(ushort *)(uVar4 + 0x532)) == 0) {
            FUN_0601536c(2);
          }
        }
        uVar2 = 0x80;
      }
    }
  }
  else {
    uVar2 = 0xb;
  }
  return uVar2;
}

