/* Decompiled C draft; module arm9_ov000; ROM address 021adb80. No matching claim. */
#include "types.h"
#include "deps/021adb80_FUN_021adb80.h"

void FUN_021adb80(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_021adba8 + 4) + 0xa4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) {
    FUN_021adc64(*(undefined4 *)(iVar1 + 0x5c),*(int *)(iVar1 + 0x60),0,0);
    *(undefined4 *)(iVar1 + 0x60) = 0;
  }
  return;
}

