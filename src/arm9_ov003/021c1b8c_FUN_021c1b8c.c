/* Decompiled C draft; module arm9_ov003; ROM address 021c1b8c. No matching claim. */
#include "types.h"
#include "deps/021c1b8c_FUN_021c1b8c.h"

void FUN_021c1b8c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(uint **)(*DAT_021c1be4 + 0x1c) & 0xff) - 0xc;
  uVar2 = (uint)*(ushort *)(DAT_021c1bec + 0xe);
  if ((int)uVar2 < iVar1) {
    FUN_021c1364(1);
    return;
  }
  FUN_021c1364(1,uVar2,uVar2,param_4,(**(uint **)(*DAT_021c1be4 + 0x1c) & DAT_021c1be8) >> 0x10,
               iVar1);
  FUN_021c1364(2,0xc0);
  FUN_021d34e0(param_1,DAT_021c1bf0);
  return;
}

