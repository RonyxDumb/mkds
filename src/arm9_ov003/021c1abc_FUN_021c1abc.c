/* Decompiled C draft; module arm9_ov003; ROM address 021c1abc. No matching claim. */
#include "types.h"
#include "deps/021c1abc_FUN_021c1abc.h"

void FUN_021c1abc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(uint **)(*DAT_021c1b14 + 0x34) & 0xff) - 0xc;
  uVar2 = (uint)*(ushort *)(DAT_021c1b1c + 0x26);
  if ((int)uVar2 < iVar1) {
    FUN_021c1364(3);
    return;
  }
  FUN_021c1364(3,uVar2,uVar2,param_4,(**(uint **)(*DAT_021c1b14 + 0x34) & DAT_021c1b18) >> 0x10,
               iVar1);
  FUN_021c1364(4,0xc0);
  FUN_021d34e0(param_1,DAT_021c1b20);
  return;
}

