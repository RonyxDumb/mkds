/* Decompiled C draft; module arm9_ov000; ROM address 021a73d8. No matching claim. */
#include "types.h"
#include "deps/021a73d8_FUN_021a73d8.h"

int FUN_021a73d8(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_021a732c();
  if (iVar1 == 0) {
    return -0x31;
  }
  uVar2 = FUN_021a7064(DAT_021a7408,iVar1,1);
  FUN_021a6f84(iVar1,uVar2);
  return iVar1;
}

