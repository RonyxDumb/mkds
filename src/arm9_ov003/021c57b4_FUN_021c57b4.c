/* Decompiled C draft; module arm9_ov003; ROM address 021c57b4. No matching claim. */
#include "types.h"
#include "deps/021c57b4_FUN_021c57b4.h"

void FUN_021c57b4(void)

{
  undefined4 uVar1;
  
  if (*DAT_021c5800 == 0) {
    if (*(char *)(*DAT_021c5804 + 0x59) == '\0') {
      FUN_021cdc10(9);
      *(undefined1 *)(*DAT_021c5804 + 0x59) = 1;
      return;
    }
  }
  else {
    FUN_021cdc10(0x13);
    uVar1 = FUN_021d3544(0,DAT_021c5808,0,0x78);
    *(undefined4 *)(*DAT_021c5804 + 0x38) = uVar1;
  }
  return;
}

