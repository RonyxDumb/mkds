/* Decompiled C draft; module arm9_ov000; ROM address 021ae2d8. No matching claim. */
#include "types.h"
#include "deps/021ae2d8_FUN_021ae2d8.h"

void FUN_021ae2d8(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_021ae2f0 + 4) + 0xa4);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 8) = 10;
    *(undefined4 *)(iVar1 + 0x44) = 0;
  }
  return;
}

