/* Decompiled C draft; module arm9_ov003; ROM address 021c0c2c. No matching claim. */
#include "types.h"
#include "deps/021c0c2c_FUN_021c0c2c.h"

void FUN_021c0c2c(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *DAT_021c0c94;
  uVar2 = (**(uint **)(iVar1 + 0x30) & DAT_021c0c98) >> 0x10;
  iVar3 = (**(uint **)(iVar1 + 0x30) & 0xff) - 0xc;
  uVar4 = (uint)*(ushort *)(DAT_021c0c9c + 2);
  if ((int)uVar4 < iVar3) {
    FUN_021c0154(*(undefined1 *)(iVar1 + DAT_021c0ca0),0,iVar3,uVar4,uVar2,iVar3);
    return;
  }
  FUN_021c0154(*(undefined1 *)(iVar1 + DAT_021c0ca0),0,uVar4,uVar4,uVar2,iVar3);
  FUN_021c0154(*(undefined1 *)(*DAT_021c0c94 + DAT_021c0ca0),1,0xc0);
  FUN_021d34e0(param_1,DAT_021c0ca4);
  return;
}

