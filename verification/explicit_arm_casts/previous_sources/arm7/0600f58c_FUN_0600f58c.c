/* Decompiled C draft; module arm7; ROM address 0600f58c. No matching claim. */
#include "types.h"
#include "deps/0600f58c_FUN_0600f58c.h"

undefined4 FUN_0600f58c(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar4 = *(uint *)(DAT_0600f6b4 & 0xfffffffc) >> (DAT_0600f6b4 & 3) * 8 |
          *(uint *)(DAT_0600f6b4 & 0xfffffffc) << (DAT_0600f6b4 & 3) * -8 + 0x20;
  iVar2 = FUN_06009138(uVar4 + 0x188,*(ushort *)(uVar4 + 0x3e4) + 0x3e);
  if (iVar2 == 0) {
    FUN_06009360(1);
    uVar3 = 0;
  }
  else {
    *(undefined2 *)(iVar2 + 0xc) = 0x8d;
    sVar1 = thunk_FUN_03806b2c(*(ushort *)(uVar4 + 0x3e4) + 1,2);
    *(short *)(iVar2 + 0xe) = sVar1 + 0x16;
    FUN_060096e4(iVar2 + 0x1f,*(ushort *)(param_1 + 0x12) & 0xff);
    FUN_060096e4(iVar2 + 0x1e,*(ushort *)(param_1 + 0xe) & 0xff);
    FUN_0600a954(iVar2 + 0x2e,param_1 + 0x1e);
    *(undefined2 *)(iVar2 + 0x16) = *(undefined2 *)(uVar4 + 0x3e4);
    if (*(ushort *)(iVar2 + 0x16) != 0) {
      if ((*(ushort *)(uVar4 + 0x3e6) & 1) == 0) {
        uVar6 = uVar4 + 0x3e0 & 3;
        uVar4 = *(uint *)(uVar4 + 0x3e0 & 0xfffffffc);
        thunk_FUN_037fb230(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,iVar2 + 0x3c,
                           *(ushort *)(iVar2 + 0x16) + 1);
      }
      else {
        uVar6 = uVar4 + 0x3e0 & 3;
        uVar4 = *(uint *)(uVar4 + 0x3e0 & 0xfffffffc);
        uVar4 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
        iVar5 = iVar2 + 0x3c;
        for (uVar6 = 0; uVar4 = uVar4 + 1, uVar6 < *(ushort *)(iVar2 + 0x16); uVar6 = uVar6 + 1) {
          uVar3 = FUN_060096c4(uVar4);
          FUN_060096e4(iVar5,uVar3);
          iVar5 = iVar5 + 1;
        }
      }
    }
    FUN_0600f19c((*(uint *)(DAT_0600f6b4 & 0xfffffffc) >> (DAT_0600f6b4 & 3) * 8 |
                 *(uint *)(DAT_0600f6b4 & 0xfffffffc) << (DAT_0600f6b4 & 3) * -8 + 0x20) + 0x188,
                 iVar2);
    uVar3 = 1;
  }
  return uVar3;
}

