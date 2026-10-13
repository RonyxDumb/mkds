/* Decompiled C draft; module arm9_ov000; ROM address 021a37dc. No matching claim. */
#include "types.h"
#include "deps/021a37dc_FUN_021a37dc.h"

void FUN_021a37dc(void)

{
  int iVar1;
  
  if (*DAT_021a380c != 0) {
    iVar1 = FUN_02188720();
    while (iVar1 == 0) {
      func_0x0200dc3c(10);
      iVar1 = FUN_02188720();
    }
    *DAT_021a380c = 0;
  }
  return;
}

