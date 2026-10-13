/* Decompiled C draft; module arm9_ov003; ROM address 021c0ab0. No matching claim. */
#include "types.h"
#include "deps/021c0ab0_FUN_021c0ab0.h"

void FUN_021c0ab0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *DAT_021c0b1c;
  uVar2 = (**(uint **)(iVar1 + 0xc0) & DAT_021c0b20) >> 0x10;
  iVar3 = (**(uint **)(iVar1 + 0xc0) & 0xff) - 0xc;
  uVar4 = (uint)*(ushort *)(DAT_021c0b24 + 0x12);
  if ((int)uVar4 < iVar3) {
    FUN_021c0154(*(undefined1 *)(iVar1 + DAT_021c0b28),3,iVar3,uVar4,uVar2,iVar3);
    return;
  }
  FUN_021c0154(*(undefined1 *)(iVar1 + DAT_021c0b28),3,uVar4,uVar4,uVar2,iVar3);
  FUN_021c0154(*(undefined1 *)(*DAT_021c0b1c + DAT_021c0b28),4,0xc0);
  FUN_021d34e0(param_1,DAT_021c0b2c);
  return;
}

