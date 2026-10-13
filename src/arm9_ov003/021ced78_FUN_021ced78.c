/* Decompiled C draft; module arm9_ov003; ROM address 021ced78. No matching claim. */
#include "types.h"
#include "deps/021ced78_FUN_021ced78.h"

void FUN_021ced78(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_021cedb4;
  *(undefined1 *)(*DAT_021cedb4 + 0x1b) = 0xff;
  iVar3 = *piVar1;
  *(short *)(iVar3 + 0x18) = *(short *)(iVar3 + 0x18) + 1;
  if (0x77 < *(ushort *)(*piVar1 + 0x18)) {
    FUN_021d34c8(0,param_1);
    uVar2 = FUN_021d3544(1,DAT_021cedb8,0,0x78);
    *(undefined4 *)(*DAT_021cedb4 + 0x14) = uVar2;
  }
  return;
}

