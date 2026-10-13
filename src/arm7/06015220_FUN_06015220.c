/* Decompiled C draft; module arm7; ROM address 06015220. No matching claim. */
#include "types.h"
#include "deps/06015220_FUN_06015220.h"

void FUN_06015220(int param_1,int param_2)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  if ((*(ushort *)(param_2 + 0x24) & 0x4000) == 0) {
    if (*(ushort *)(param_2 + 0xc) == DAT_06015358) {
      FUN_06009788(param_1,param_2 + 0x18,*(ushort *)(param_2 + 0x16) + 0x24);
    }
    else {
      uVar1 = param_2 + 0x3cU & 3;
      uVar3 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
      FUN_0600974c(param_1,param_2 + 0x18,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                   *(undefined2 *)(param_2 + 0x16));
    }
  }
  else {
    if (*(ushort *)(param_2 + 0xc) == DAT_06015358) {
      FUN_06009710(param_1,param_2 + 0x18,param_2 + 0x3c,*(undefined2 *)(param_2 + 0x16));
    }
    else {
      uVar1 = param_2 + 0x3cU & 3;
      uVar3 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
      FUN_06009710(param_1,param_2 + 0x18,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                   *(undefined2 *)(param_2 + 0x16));
    }
    puVar2 = DAT_0601535c;
    *(ushort *)(param_1 + 0x24) = *DAT_0601535c + *DAT_0601535c * 0x100;
    uVar3 = DAT_06015360;
    *(ushort *)(param_1 + 0x26) =
         *puVar2 & 0xff |
         *(short *)((*(uint *)(DAT_06015360 & 0xfffffffc) >> (DAT_06015360 & 3) * 8 |
                    *(uint *)(DAT_06015360 & 0xfffffffc) << (DAT_06015360 & 3) * -8 + 0x20) + 0x336)
         << 0xe;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((*(ushort *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x690) & 8) != 0) {
      puVar4 = (undefined2 *)(param_1 + (uint)*(ushort *)(param_2 + 0x22) + 5 & 0xfffffffe);
      *puVar4 = 0;
      puVar4[1] = 0;
    }
  }
  if ((*(ushort *)
        ((*(uint *)(DAT_06015360 & 0xfffffffc) >> (DAT_06015360 & 3) * 8 |
         *(uint *)(DAT_06015360 & 0xfffffffc) << (DAT_06015360 & 3) * -8 + 0x20) + 0x690) & 4) != 0)
  {
    puVar4 = (undefined2 *)(param_1 + (uint)*(ushort *)(param_2 + 0x22) + 0xb & 0xfffffffc);
    *puVar4 = (short)DAT_06015364;
    puVar4[1] = (short)DAT_06015368;
  }
  return;
}

