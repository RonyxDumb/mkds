/* Decompiled C draft; module arm9_ov000; ROM address 021a1430. No matching claim. */
#include "types.h"
#include "deps/021a1430_FUN_021a1430.h"

void FUN_021a1430(void)

{
  undefined1 *puVar1;
  
  *DAT_021a1478 = 0;
  if (*DAT_021a147c != 0) {
    FUN_021a3704(4);
    *DAT_021a147c = 0;
  }
  FUN_0219ea88();
  if (*DAT_021a1480 != 0) {
    FUN_021a3704(4,*DAT_021a1480,0);
    *DAT_021a1480 = 0;
  }
  puVar1 = DAT_021a1484;
  *DAT_021a1484 = 0;
  puVar1[1] = 0;
  return;
}

