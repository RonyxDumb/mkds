/* Decompiled C draft; module arm9_ov003; ROM address 021c0b30. No matching claim. */
#include "types.h"
#include "deps/021c0b30_FUN_021c0b30.h"

void FUN_021c0b30(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *DAT_021c0b9c;
  uVar2 = (**(uint **)(iVar1 + 0x90) & DAT_021c0ba0) >> 0x10;
  iVar3 = (**(uint **)(iVar1 + 0x90) & 0xff) - 0xc;
  uVar4 = (uint)*(ushort *)(DAT_021c0ba4 + 0x22);
  if ((int)uVar4 < iVar3) {
    FUN_021c0154(*(undefined1 *)(iVar1 + DAT_021c0ba8),2,iVar3,uVar4,uVar2,iVar3);
    return;
  }
  FUN_021c0154(*(undefined1 *)(iVar1 + DAT_021c0ba8),2,uVar4,uVar4,uVar2,iVar3);
  FUN_021c0154(*(undefined1 *)(*DAT_021c0b9c + DAT_021c0ba8),3,0xc0);
  FUN_021d34e0(param_1,DAT_021c0bac);
  return;
}

