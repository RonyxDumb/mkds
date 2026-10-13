/* Decompiled C draft; module arm7; ROM address 06010730. No matching claim. */
#include "types.h"
#include "deps/06010730_FUN_06010730.h"

undefined4 FUN_06010730(int param_1,int param_2)

{
  uint uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar7;
  uint uVar6;
  
  uVar5 = DAT_0601083c;
  puVar7 = (undefined2 *)
           ((*(uint *)(DAT_0601083c & 0xfffffffc) >> (DAT_0601083c & 3) * 8 |
            *(uint *)(DAT_0601083c & 0xfffffffc) << (DAT_0601083c & 3) * -8 + 0x20) + DAT_06010840);
  *(undefined2 *)(param_2 + 2) = 1;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  sVar2 = *(short *)(uVar6 + 0x32e);
  if (sVar2 == 0) {
    uVar3 = 0xb;
  }
  else if ((sVar2 == 1) || ((*(ushort *)(param_1 + 0x10) & 1) == 0)) {
    if (*(short *)(uVar6 + 0x34c) == 0x40) {
      iVar4 = FUN_06013d2c(param_1 + 0x10,*(undefined2 *)(param_1 + 0x16));
      if (iVar4 == 0) {
        uVar3 = 8;
      }
      else {
        *(int *)(puVar7 + 0xc) = param_1;
        *(int *)(puVar7 + 0xe) = param_2;
        *puVar7 = 0x71;
        uVar6 = DAT_0601083c;
        if ((*(ushort *)(param_1 + 0x10) & 1) == 0) {
          FUN_06014554(param_1 + 0x10);
          FUN_060143ac(iVar4);
        }
        else {
          uVar5 = (*(uint *)(DAT_0601083c & 0xfffffffc) >> (DAT_0601083c & 3) * 8 |
                  *(uint *)(DAT_0601083c & 0xfffffffc) << (DAT_0601083c & 3) * -8 + 0x20) + 0x3ec;
          uVar1 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          *(ushort *)(iVar4 + 4) =
               (ushort)(uVar5 >> uVar1 * 8) | (ushort)(uVar5 << uVar1 * -8 + 0x20);
          uVar5 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          FUN_0600ed84((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x188,iVar4 + -0x10);
          uVar6 = *(uint *)(DAT_0601083c & 0xfffffffc) >> (DAT_0601083c & 3) * 8 |
                  *(uint *)(DAT_0601083c & 0xfffffffc) << (DAT_0601083c & 3) * -8 + 0x20;
          if ((*(ushort *)(uVar6 + 0x52e) & ~*(ushort *)(uVar6 + 0x532)) == 0) {
            FUN_0601536c(2);
          }
        }
        uVar3 = 0x80;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 5;
  }
  return uVar3;
}

