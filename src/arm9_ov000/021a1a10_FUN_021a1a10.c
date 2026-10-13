/* Decompiled C draft; module arm9_ov000; ROM address 021a1a10. No matching claim. */
#include "types.h"
#include "deps/021a1a10_FUN_021a1a10.h"

void FUN_021a1a10(void)

{
  int *piVar1;
  
  piVar1 = DAT_021a1a34;
  if (*(char *)(*DAT_021a1a34 + 0x15) != '\x02') {
    *(undefined1 *)(*DAT_021a1a34 + 0x14) = 0;
    *(undefined1 *)(*piVar1 + 0x16) = 0;
    FUN_021a4818(*(undefined4 *)(*piVar1 + 0x10));
  }
  return;
}

