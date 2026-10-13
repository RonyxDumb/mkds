/* Decompiled C draft; module arm9_ov000; ROM address 0219b8a8. No matching claim. */
#include "types.h"
#include "deps/0219b8a8_FUN_0219b8a8.h"

void FUN_0219b8a8(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = DAT_0219b8b8;
  *(undefined4 *)(*DAT_0219b8b8 + 0x28) = *(undefined4 *)(*DAT_0219b8b8 + 0x24);
  *(undefined4 *)(*piVar1 + 0x24) = param_1;
  return;
}

