/* Decompiled C draft; module arm9_ov000; ROM address 021a8830. No matching claim. */
#include "types.h"
#include "deps/021a8830_FUN_021a8830.h"

int FUN_021a8830(void)

{
  int iVar1;
  
  if (*DAT_021a886c == 0) {
    if (((*DAT_021a8870 & 3) == 1) && (iVar1 = func_0x0200fcf8(), iVar1 != 0x12)) {
      func_0x0200dc3c(10);
    }
  }
  else if (*DAT_021a8874 == 0) {
    *DAT_021a8874 = *DAT_021a886c;
  }
  return *DAT_021a886c;
}

