/* Decompiled C draft; module arm9_ov001; ROM address 0219ebfc. No matching claim. */
#include "types.h"
#include "deps/0219ebfc_FUN_0219ebfc.h"

void FUN_0219ebfc(void)

{
  int *piVar1;
  
  *(int *)(*DAT_0219ec34 + 0x24) = *(int *)(*DAT_0219ec34 + 0x24) + 1;
  func_0x021059e0();
  if (4 < *(int *)(*DAT_0219ec34 + 0x24)) {
    FUN_0219f198();
    piVar1 = DAT_0219ec34;
    *(undefined2 *)(*DAT_0219ec34 + 0x48) = 0xff00;
    *(undefined4 *)(*piVar1 + 0x58) = 1;
  }
  return;
}

