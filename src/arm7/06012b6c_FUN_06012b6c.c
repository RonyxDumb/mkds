/* Decompiled C draft; module arm7; ROM address 06012b6c. No matching claim. */
#include "types.h"
#include "deps/06012b6c_FUN_06012b6c.h"

undefined4 FUN_06012b6c(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar9;
  undefined2 *puVar8;
  
  uVar5 = *(uint *)(DAT_06012cdc & 0xfffffffc) >> (DAT_06012cdc & 3) * 8 |
          *(uint *)(DAT_06012cdc & 0xfffffffc) << (DAT_06012cdc & 3) * -8 + 0x20;
  iVar9 = uVar5 + DAT_06012ce0;
  uVar1 = *(ushort *)(uVar5 + 0x690);
  *(undefined2 *)(param_2 + 2) = 1;
  if (*(short *)(uVar5 + 0x32e) == 2) {
    if (*(ushort *)(param_1 + 0x10) < 0x205) {
      iVar6 = (uint)(*(short *)(iVar9 + 0x50) != 0) * 0x14;
      if (*(short *)(iVar9 + 0x50 + iVar6) == 0) {
        if ((*DAT_06012ce4 & 0x8000) == 0) {
          uVar7 = iVar9 + iVar6 + 0x58;
          uVar3 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          puVar8 = (undefined2 *)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
          *puVar8 = 0;
          puVar8[2] = 0;
          puVar8[4] = 0x14;
          puVar8[5] = *(short *)(param_1 + 0x10) + 0x1e;
          puVar8[6] = 0x118;
          FUN_0600a8d4(puVar8 + 8,(undefined2 *)(uintptr_t)(uVar5 + 0x3a8),(undefined2 *)(uintptr_t)(uVar5 + 0x324),(undefined2 *)(uintptr_t)(DAT_06012ce8));
          puVar8[0x12] = *(undefined2 *)(param_1 + 0x12);
          if (*(short *)(param_1 + 0x10) != 0) {
            uVar7 = param_1 + 0x14U & 3;
            uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
            FUN_06009788(puVar8 + 0x13,uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
          }
          if ((uVar1 & 4) != 0) {
            puVar4 = (undefined2 *)((int)puVar8 + *(ushort *)(param_1 + 0x10) + 0x29 & 0xfffffffc);
            *puVar4 = (short)DAT_06012cec;
            puVar4[1] = (short)DAT_06012cf0;
          }
          *(undefined2 *)(iVar9 + 0x50 + iVar6) = 1;
          *(short *)(iVar9 + 0x52 + iVar6) = *(short *)(iVar9 + 0x52 + iVar6) + 1;
          *DAT_06012ce4 = (ushort)(((uint)puVar8 & DAT_06012cf4) >> 1) | 0x8000;
          if (-1 < (int)((uint)*(ushort *)(uVar5 + 0x33a) << 0x18)) {
            FUN_0600aa30();
          }
          uVar2 = 0;
        }
        else {
          uVar2 = 8;
        }
      }
      else {
        uVar2 = 8;
      }
    }
    else {
      uVar2 = 5;
    }
  }
  else {
    uVar2 = 0xb;
  }
  return uVar2;
}

