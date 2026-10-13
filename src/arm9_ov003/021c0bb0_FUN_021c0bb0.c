/* Decompiled C draft; module arm9_ov003; ROM address 021c0bb0. No matching claim. */
#include "types.h"
#include "deps/021c0bb0_FUN_021c0bb0.h"

void FUN_021c0bb0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *DAT_021c0c18;
  uVar2 = (**(uint **)(iVar1 + 0x60) & DAT_021c0c1c) >> 0x10;
  iVar3 = (**(uint **)(iVar1 + 0x60) & 0xff) - 0xc;
  uVar4 = (uint)*(ushort *)(DAT_021c0c20 + 0x32);
  if ((int)uVar4 < iVar3) {
    FUN_021c0154(*(undefined1 *)(iVar1 + DAT_021c0c24),1,iVar3,uVar4,uVar2,iVar3);
    return;
  }
  FUN_021c0154(*(undefined1 *)(iVar1 + DAT_021c0c24),1,uVar4,uVar4,uVar2,iVar3);
  FUN_021c0154(*(undefined1 *)(*DAT_021c0c18 + DAT_021c0c24),2,0xc0);
  FUN_021d34e0(param_1,DAT_021c0c28);
  return;
}

