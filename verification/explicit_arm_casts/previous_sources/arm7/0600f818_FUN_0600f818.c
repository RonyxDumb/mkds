/* Decompiled C draft; module arm7; ROM address 0600f818. No matching claim. */
#include "types.h"
#include "deps/0600f818_FUN_0600f818.h"

undefined4 FUN_0600f818(undefined4 param_1,undefined2 param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = FUN_06009138((*(uint *)(DAT_0600f904 & 0xfffffffc) >> (DAT_0600f904 & 3) * 8 |
                       *(uint *)(DAT_0600f904 & 0xfffffffc) << (DAT_0600f904 & 3) * -8 + 0x20) +
                       0x188,0x3a);
  if (iVar2 == 0) {
    FUN_06009360(1);
    uVar3 = 0;
  }
  else {
    *(undefined2 *)(iVar2 + 0xc) = 0x87;
    *(undefined2 *)(iVar2 + 0xe) = 0x15;
    FUN_0600a954(iVar2 + 0x10,param_1);
    *(undefined2 *)(iVar2 + 0x16) = param_2;
    uVar1 = FUN_060096c4(param_3 + 1);
    *(undefined2 *)(iVar2 + 0x18) = uVar1;
    for (uVar4 = 0; (uVar4 < *(ushort *)(iVar2 + 0x18) && (uVar4 < 0x20)); uVar4 = uVar4 + 1) {
      uVar3 = FUN_060096c4(param_3 + 2 + uVar4);
      FUN_060096e4(iVar2 + 0x1a + uVar4,uVar3);
    }
    for (; uVar4 < 0x20; uVar4 = uVar4 + 1) {
      FUN_060096e4(iVar2 + 0x1a + uVar4,0);
    }
    FUN_0600f19c((*(uint *)(DAT_0600f904 & 0xfffffffc) >> (DAT_0600f904 & 3) * 8 |
                 *(uint *)(DAT_0600f904 & 0xfffffffc) << (DAT_0600f904 & 3) * -8 + 0x20) + 0x188,
                 iVar2);
    uVar3 = 1;
  }
  return uVar3;
}

