/* Decompiled C draft; module arm9_ov000; ROM address 0219d734. No matching claim. */
#include "types.h"
#include "deps/0219d734_FUN_0219d734.h"

void FUN_0219d734(int param_1)

{
  int *piVar1;
  
  if ((*DAT_0219d76c != 0) && (param_1 != 0)) {
    FUN_0219c384();
    piVar1 = (int *)*DAT_0219d76c;
    if ((*piVar1 != 0) && (*piVar1 != 2)) {
      (*(code *)piVar1[0xb])(param_1,*(undefined1 *)((int)piVar1 + 0x1d),piVar1[0xc]);
    }
    FUN_0219d478();
  }
  return;
}

