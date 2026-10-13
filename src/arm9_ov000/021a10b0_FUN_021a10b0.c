/* Decompiled C draft; module arm9_ov000; ROM address 021a10b0. No matching claim. */
#include "types.h"
#include "deps/021a10b0_FUN_021a10b0.h"

void FUN_021a10b0(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  FUN_021a1140(0);
  piVar1 = DAT_021a1118;
  *(undefined1 *)(*DAT_021a1118 + 0x15) = param_1;
  *(undefined1 *)(*piVar1 + 0x16) = param_2;
  *(undefined4 *)(*piVar1 + DAT_021a111c) = param_3;
  *(undefined4 *)(*piVar1 + DAT_021a1120) = param_4;
  *(undefined1 *)(*piVar1 + DAT_021a1124) = 0;
  *(undefined1 *)(*piVar1 + DAT_021a1128) = 0;
  FUN_021a4b84(0x32,DAT_021a112c);
  FUN_021a4b84(0x33,DAT_021a1130);
  FUN_021a4b84(0x34,DAT_021a1134);
  FUN_021a4b84(0x35,DAT_021a1138);
  FUN_021a4b84(0x36,DAT_021a113c);
  return;
}

