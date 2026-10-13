/* Decompiled C draft; module arm9_ov003; ROM address 021bffb0. No matching claim. */
#include "types.h"
#include "deps/021bffb0_FUN_021bffb0.h"

void FUN_021bffb0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  switch(*(undefined1 *)(*DAT_021c003c + DAT_021c0040)) {
  case 0x2f:
    uVar3 = 0x42;
    break;
  case 0x30:
    uVar3 = 0x41;
    break;
  case 0x31:
    uVar3 = 0x43;
    break;
  case 0x32:
    uVar3 = 0x41;
    break;
  case 0x33:
  case 0x34:
    uVar3 = 0x45;
    break;
  default:
    uVar3 = 0x40;
  }
  uVar1 = FUN_021d1974(*(undefined4 *)(*DAT_021c003c + DAT_021c0044),0);
  FUN_021d1c3c(0,uVar3,uVar1);
  FUN_021d1790(*(undefined4 *)(*DAT_021c003c + DAT_021c0044),0xffffffff,2);
  iVar2 = *(char *)(*DAT_021c003c + DAT_021c0040) * 4;
  FUN_021d17d4(*(undefined4 *)(*DAT_021c003c + DAT_021c0044),0xffffffff,
               *(undefined2 *)(DAT_021c0048 + iVar2),*(undefined2 *)(DAT_021c004c + iVar2));
  return;
}

