/* Decompiled C draft; module arm9_ov001; ROM address 021968bc. No matching claim. */
#include "types.h"
#include "deps/021968bc_FUN_021968bc.h"

void FUN_021968bc(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_02196900;
  *(int *)(*DAT_02196900 + 0x58) = *(int *)(*DAT_02196900 + 0x58) + 1;
  uVar2 = func_0x020ae4c0(1,0xffffff40,0,*(undefined4 *)(*piVar1 + 0x58),10);
  piVar1 = DAT_02196900;
  *(undefined4 *)(*DAT_02196900 + 0x5c) = uVar2;
  *(undefined4 *)(*piVar1 + 100) = uVar2;
  *(short *)(*(int *)(*piVar1 + 0x38) + 6) = (short)uVar2;
  if (9 < *(int *)(*piVar1 + 0x58)) {
    FUN_0219703c();
  }
  return;
}

