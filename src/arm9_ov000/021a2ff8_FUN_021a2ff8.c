/* Decompiled C draft; module arm9_ov000; ROM address 021a2ff8. No matching claim. */
#include "types.h"
#include "deps/021a2ff8_FUN_021a2ff8.h"

void FUN_021a2ff8(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_021a302c;
  if (*DAT_021a302c != 0) {
    param_1 = param_1 * 0x30;
    *(undefined4 *)(*DAT_021a302c + param_1 + 0xc) = 0;
    *(undefined4 *)(*piVar1 + param_1 + 0x10) = 0;
    *(undefined4 *)(*piVar1 + param_1 + 0x14) = 0;
    *(undefined4 *)(*piVar1 + param_1 + 0x18) = 0;
    *(undefined1 *)(*piVar1 + param_1 + 0x1c) = 0;
    *(undefined2 *)(*piVar1 + param_1 + 0x22) = 0;
  }
  return;
}

