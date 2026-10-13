/* Decompiled C draft; module arm7; ROM address 0600e69c. No matching claim. */
#include "types.h"
#include "deps/0600e69c_FUN_0600e69c.h"

void FUN_0600e69c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = FUN_0600e918();
  if (iVar1 == 0x40) {
    iVar1 = (uint)*(ushort *)
                   ((*(uint *)(DAT_0600e740 & 0xfffffffc) >> (DAT_0600e740 & 3) * 8 |
                    *(uint *)(DAT_0600e740 & 0xfffffffc) << (DAT_0600e740 & 3) * -8 + 0x20) + 0x3d8)
            + DAT_0600e744;
    uVar2 = thunk_FUN_037f8850(0x1000000);
    if (param_1 == 0) {
      uVar3 = FUN_060096c4(iVar1 + 4);
      FUN_060096e4(iVar1 + 4,uVar3 & 0xfe);
    }
    else {
      uVar3 = FUN_0600e840(param_1);
      iVar1 = iVar1 + 5 + (uVar3 >> 3);
      uVar4 = FUN_060096c4(iVar1);
      FUN_060096e4(iVar1,~(1 << (uVar3 & 7)) & uVar4 & 0xff);
    }
    thunk_FUN_037f888c(uVar2);
  }
  return;
}

