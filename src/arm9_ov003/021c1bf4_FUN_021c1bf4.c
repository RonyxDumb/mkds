/* Decompiled C draft; module arm9_ov003; ROM address 021c1bf4. No matching claim. */
#include "types.h"
#include "deps/021c1bf4_FUN_021c1bf4.h"

void FUN_021c1bf4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(uint **)(*DAT_021c1c4c + 0x10) & 0xff) - 0xc;
  uVar2 = (uint)*(ushort *)(DAT_021c1c54 + 2);
  if ((int)uVar2 < iVar1) {
    FUN_021c1364(0);
    return;
  }
  FUN_021c1364(0,uVar2,uVar2,param_4,(**(uint **)(*DAT_021c1c4c + 0x10) & DAT_021c1c50) >> 0x10,
               iVar1);
  FUN_021c1364(1,0xc0);
  FUN_021d34e0(param_1,DAT_021c1c58);
  return;
}

