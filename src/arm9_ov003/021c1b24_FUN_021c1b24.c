/* Decompiled C draft; module arm9_ov003; ROM address 021c1b24. No matching claim. */
#include "types.h"
#include "deps/021c1b24_FUN_021c1b24.h"

void FUN_021c1b24(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(uint **)(*DAT_021c1b7c + 0x28) & 0xff) - 0xc;
  uVar2 = (uint)*(ushort *)(DAT_021c1b84 + 0x1a);
  if ((int)uVar2 < iVar1) {
    FUN_021c1364(2);
    return;
  }
  FUN_021c1364(2,uVar2,uVar2,param_4,(**(uint **)(*DAT_021c1b7c + 0x28) & DAT_021c1b80) >> 0x10,
               iVar1);
  FUN_021c1364(3,0xc0);
  FUN_021d34e0(param_1,DAT_021c1b88);
  return;
}

