/* Decompiled C draft; module arm9_ov003; ROM address 021c574c. No matching claim. */
#include "types.h"
#include "deps/021c574c_FUN_021c574c.h"

void FUN_021c574c(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *DAT_021c57a8;
  if ((*DAT_021c57ac == *(short *)(iVar2 + 0x40)) || (*(byte *)(iVar2 + 0x51) < 5)) {
    if (*(char *)(iVar2 + 0x59) == '\0') {
      FUN_021cdc10(9);
      *(undefined1 *)(*DAT_021c57a8 + 0x59) = 1;
      return;
    }
  }
  else {
    FUN_021cdc10(0x13);
    uVar1 = FUN_021d3544(0,DAT_021c57b0,0,0x78);
    *(undefined4 *)(*DAT_021c57a8 + 0x38) = uVar1;
  }
  return;
}

