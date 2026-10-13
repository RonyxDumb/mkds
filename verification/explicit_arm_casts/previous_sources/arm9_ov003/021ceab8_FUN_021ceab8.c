/* Decompiled C draft; module arm9_ov003; ROM address 021ceab8. No matching claim. */
#include "types.h"
#include "deps/021ceab8_FUN_021ceab8.h"

void FUN_021ceab8(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = DAT_021ceaec;
  *(char *)(*DAT_021ceaec + 0x1a) = *(char *)(*DAT_021ceaec + 0x1a) + '\x01';
  func_0x0214a348(DAT_021ceaf0,(int)*(char *)(*piVar1 + 0x1a));
  if (-1 < *(char *)(*DAT_021ceaec + 0x1a)) {
    FUN_021d34e0(param_1,DAT_021ceaf4);
  }
  return;
}

